#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Mixer.hh>
#include <SDL2pp/Chunk.hh>
#include <SDL2pp/Music.hh>

using namespace SDL2pp;

int main() {

    SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDLTTF sdl_ttf;
    Window window("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                    640, 480, SDL_WINDOW_RESIZABLE);
    Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
    Texture textura1(renderer, SDL_PIXELFORMAT_ARGB8888,
                            SDL_TEXTUREACCESS_STATIC, 16, 16);
    Texture textura2(renderer, RESOURCE_PATH "/AtreidesIcon.png");

    Font font(RESOURCE_PATH "/fonts/Dune2k.ttf", 20);

    Texture text(renderer, font.RenderText_Solid("Hello, world!",
                        SDL_Color{255, 255, 255, 255}));

    Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

    Music musica(RESOURCE_PATH "/musica/harkonnen_battle.mp3");
    Chunk sonido(RESOURCE_PATH "/sonidos/atreides/mensajes_de_voz/ataque_gusano.mp3");

    renderer.Copy(textura1, NullOpt, NullOpt);
    renderer.Copy(text, NullOpt, Rect(Point(0, 0), text.GetSize()));
    renderer.Copy(textura2, NullOpt, NullOpt, 45.0);
    renderer.Present();

    mixer.PlayChannel(-1, sonido);
    mixer.PlayMusic(musica);

    SDL_Delay(5000);

    return 0;
}
