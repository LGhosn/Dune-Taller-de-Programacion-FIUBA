#include "sdl_side_menu.h"

SideMenuSDL::SideMenuSDL(SDL2pp::Renderer& renderer, uint8_t casa, TexturasSDL& texturas,
                            uint8_t id_jugador, YAML::Node& constantes, ColorSDL& color) :
                            constantes(constantes),
                            renderer(renderer),
                            color(color),
                            casa(casa),
                            tienda(renderer, casa, texturas, id_jugador, constantes, color),
                            especia(renderer, texturas, constantes, color),
                            energia(renderer, texturas, constantes, color),
                            logo_casa(texturas.obtenerLogoCasa(casa)) {
    uint32_t ancho_menu = constantes["WorldView"]["SideMenu"]["Ancho"].as<uint32_t>();
    uint32_t ancho_ventana = constantes["WorldView"]["Ventana"]["Ancho"].as<uint32_t>();
    uint32_t largo_ventana = constantes["WorldView"]["Ventana"]["Alto"].as<uint32_t>();
    uint32_t padding_tienda = constantes["WorldView"]["SideMenu"]["Tienda"]["Padding"].as<uint32_t>();

    origen_logo_casa = SDL2pp::Rect(0,0,logo_casa.GetWidth(),logo_casa.GetWidth());
    destino_logo_casa = SDL2pp::Rect(ancho_ventana - ancho_menu + padding_tienda,
                                    padding_tienda,
                                    ancho_menu - 2 * padding_tienda,
                                    ancho_menu - 2 * padding_tienda);
    side_menu_rect = SDL2pp::Rect(ancho_ventana - ancho_menu,
                                    0,
                                    ancho_menu,
                                    largo_ventana);
}

SolicitudCliente* SideMenuSDL::clickEnMenu(int pos_x, int pos_y) {
    SolicitudCliente* solicitud = tienda.click(pos_x, pos_y);
    return solicitud;
}

SolicitudCliente* SideMenuSDL::clickEnMapa(Coordenadas& coords) {
    return tienda.clickEnMapa(coords);
}

void SideMenuSDL::modificarEspecia(uint16_t cantidad_especia) {
    especia.modificarEspecia(cantidad_especia);
}

void SideMenuSDL::modificarEnergia(int16_t cantidad_energia) {
    energia.modificarEnergia(cantidad_energia);
}

void SideMenuSDL::empezarConstruccionEdificio(uint8_t tipo, uint16_t tiempo_construccion) {
    tienda.empezarConstruccionEdificio(tipo, tiempo_construccion);
}

void SideMenuSDL::empezarEntrenamientoInfanteria(uint8_t tipo, uint16_t tiempo_construccion, Coordenadas& coords_spawn) {
    tienda.empezarEntrenamientoInfanteria(tipo, tiempo_construccion, coords_spawn);
}

void SideMenuSDL::empezarEntrenamientoVehiculo(uint8_t tipo, uint16_t tiempo_construccion, Coordenadas& coords_spawn) {
    tienda.empezarEntrenamientoVehiculo(tipo, tiempo_construccion, coords_spawn);
}



void SideMenuSDL::actualizarTiendaEdificios(const std::vector<bool>& edificios_comprables) {
    tienda.actualizarEdificios(edificios_comprables);
}

void SideMenuSDL::edificioCreado(uint8_t tipo) {
    tienda.edificioCreado(tipo);
}

void SideMenuSDL::update(long frames_transcurridos) {
    tienda.update(frames_transcurridos);
}

void SideMenuSDL::render() {
    renderer.SetDrawColor(color.obtenerSecundario());
    renderer.FillRect(side_menu_rect);
    renderer.Copy(logo_casa, origen_logo_casa, destino_logo_casa);
    tienda.render();
    especia.render();
    energia.render();
}
