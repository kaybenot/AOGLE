#include "AOGLE.hpp"

int main(int argc, char* argv[])
{
    AOGLE_Renderer renderer;
    AOGLE_Window window;
    AOGLE_Mesh mesh;
    AOGLE_Shader shader;
    AOGLE_Camera camera;

    renderer.create();
    window.create(renderer, 800, 600, "Test window");
    mesh.import_from_file(renderer, "test.fbx");
    shader.load(renderer, "unlit.vs", "unlit.fs");

    camera.pos = {10, 5, 0};

    bool quit = false;
    while(!quit)
    {
        window.process_events(quit);
        window.clear(renderer);

        camera.calculate_MVP(renderer);

        shader.use(renderer);
        mesh.draw(renderer);

        window.present_frame(renderer);
    }

    return 0;
}