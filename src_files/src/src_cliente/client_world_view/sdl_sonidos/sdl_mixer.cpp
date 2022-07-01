#include "sdl_mixer.h"

MixerSDL::MixerSDL(uint8_t casa, YAML::Node& constantes):
                    mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT,
                            MIX_DEFAULT_CHANNELS, 4096),
					sonidos(casa, constantes),
                    volumen(constantes["WorldView"]["Mixer"]["VolumenInicial"].as<uint8_t>()),
                    volumen_musica(constantes["WorldView"]["Mixer"]["VolumenInicialMusica"].as<uint8_t>()),
                    cantidad_maxima_sonidos(constantes["WorldView"]["Mixer"]["CantidadMaximaSonidos"].as<uint8_t>()) {
    mixer.SetChannelFinishedHandler(mensajeTerminado);
    mixer.SetVolume(-1, volumen);
    mixer.SetMusicVolume(volumen_musica);
    mixer.PlayMusic(sonidos.obtenerMusica(), -1);
}

uint8_t MixerSDL::cantidad_sonidos = 0;

void MixerSDL::mensajeTerminado(int canal) {
    cantidad_sonidos--;
}

void MixerSDL::reproducirMensajeConstruyendo() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeConstruyendo());
    }
	
}

void MixerSDL::reproducirMensajeEdificioConstruido() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeEdificioConstruido());
    }
}

void MixerSDL::reproducirMensajeConstruccionInvalida() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeConstruccionInvalida());
    }
}

void MixerSDL::reproducirMensajeNuevosEdificiosDisponibles() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeNuevosEdificiosDisponibles());
    }
}

void MixerSDL::reproducirMensajeEntrenando() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeEntrenando());
    }
}

void MixerSDL::reproducirMensajeEnergiaBaja() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeEnergiaBaja());
    }
}

void MixerSDL::reproducirMensajeVictoria() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeVictoria());
    }
}

void MixerSDL::reproducirMensajeDerrota() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeDerrota());
    }
}

void MixerSDL::reproducirMensajeAtaqueGusano() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeAtaqueGusano());
    }
}

void MixerSDL::reproducirMensajeCentroAtacado() {
    if (cantidad_sonidos < cantidad_maxima_sonidos) {
        cantidad_sonidos++;
        mixer.PlayChannel(-1, sonidos.obtenerMensajeCentroAtacado());
    }
}
