#include <exception>
#include <SDL2pp/SDL2pp.hh>
#include <SDL2pp/Music.hh>
#include <SDL2pp/Mixer.hh>

int main () {
	SDL2pp::SDL sdl(SDL_INIT_VIDEO);

	SDL2pp::Window window("MapaSDL",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			640, 480,
			SDL_WINDOW_RESIZABLE);

	SDL2pp::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL2pp::Surface surface(RESOURCE_PATH "/terrain/d2k_BLOXBASE.bmp");
	SDL2pp::Texture texture(renderer, surface);

	SDL2pp::Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);

	SDL2pp::Music music(RESOURCE_PATH "/music/Plotting.mp3");

	mixer.FadeInMusic(music, -1, 2000);

	// Clear screen
	renderer.Clear();
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 15; j++) {
			renderer.Copy(texture, SDL2pp::Rect(0, 8, 32, 32), SDL2pp::Rect(i * 32, j * 32, 32, 32));
		}
	}
	SDL2pp::Surface edificio_sup(RESOURCE_PATH "/buildings/141528.png");
	SDL2pp::Texture edificio(renderer, edificio_sup);

	edificio.SetBlendMode(SDL_BLENDMODE_BLEND);
	edificio.SetAlphaMod(180);

	int vcenter = renderer.GetOutputHeight() / 2;
	int hcenter = renderer.GetOutputWidth() / 2;

	renderer.Copy(edificio, SDL2pp::Rect(0, 0, 110, 78), SDL2pp::Rect(hcenter -110/2, vcenter - 78/2, 110, 78));
	renderer.Copy(edificio, SDL2pp::Rect(110, 0, 110, 78), SDL2pp::Rect(hcenter - 45, vcenter - 58, 110, 78));

	renderer.Present();

	SDL_Delay(500000);

	return 0;
}