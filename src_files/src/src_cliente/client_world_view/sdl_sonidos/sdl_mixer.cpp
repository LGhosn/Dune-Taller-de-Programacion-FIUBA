#include "sdl_mixer.h"

MixerSDL::MixerSDL(uint8_t casa, YAML::Node& constantes):
                    mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
                            MIX_DEFAULT_CHANNELS, 4096),
					sonidos(casa, constantes),
                    volumen(constantes["WorldView"]["Mixer"]["VolumenInicial"].as<uint8_t>()),
                    volumen_musica(constantes["WorldView"]["Mixer"]["VolumenInicialMusica"].as<uint8_t>()) {
    mixer.SetVolume(-1, volumen);
    mixer.SetMusicVolume(volumen_musica);
    mixer.PlayMusic(sonidos.obtenerMusica(), -1);
}

SonidosSDL& MixerSDL::obtenerSonidosSDL() {
    return sonidos;
}

void MixerSDL::reproducirMensajeConstruyendo() {
	mixer.PlayChannel(-1, sonidos.obtenerMensajeConstruyendo());
}

void MixerSDL::reproducirMensajeEdificioConstruido() {
    mixer.PlayChannel(-1, sonidos.obtenerMensajeEdificioConstruido());
}

void MixerSDL::reproducirMensajeConstruccionInvalida() {
    mixer.PlayChannel(-1, sonidos.obtenerMensajeConstruccionInvalida());
}

void MixerSDL::reproducirMensajeNuevosEdificiosDisponibles() {
    mixer.PlayChannel(-1, sonidos.obtenerMensajeNuevosEdificiosDisponibles());
}

void MixerSDL::reproducirMensajeEntrenando() {
    mixer.PlayChannel(-1, sonidos.obtenerMensajeEntrenando());
}

void MixerSDL::reproducirMensajeEnergiaBaja() {
    mixer.PlayChannel(-1, sonidos.obtenerMensajeEnergiaBaja());
}
