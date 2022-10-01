#include "AOGLE.hpp"

int main(int argc, char* argv[])
{
    AOGLE::Renderer renderer;
    AOGLE::Window window;
    AOGLE::Mesh mesh;
    AOGLE::Shader shader;
    AOGLE::Camera camera;
    AOGLE::Debug debug;
    AOGLE::Input input;

    renderer.create();
    window.create(renderer, 800, 600, "Test window");
    mesh.import_from_file(renderer, "test.fbx");
    shader.load(renderer, "unlit.vs", "unlit.fs");

    bool quit = false;
    while(!quit)
    {
        window.process_events(quit, input);
        window.clear(renderer);

        debug.print_debug();
        debug.debug_logic(input);
        camera.pos = debug.camera_pos;

        camera.calculate_MVP(renderer);

        shader.use(renderer);
        mesh.draw(renderer);

        window.present_frame(renderer);
    }

    return 0;
}