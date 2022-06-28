#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(std::vector<std::vector<char>>* grilla_terrenos,
                               std::vector<std::vector<uint8_t>>* grilla_texturas,
                               std::vector<std::tuple<int, int>>& centros_ubicados,
                               int &cant_jugadores,
                               int &cant_filas_grillas,
                               int &cant_columnas_grillas,
                               char* terreno_seleccionado,
                               uint8_t* textura_seleccionada,
                               QString* path_textura,
                               QWidget* parent,
                               Qt::WindowFlags f) :
                               QLabel(parent),
                               grilla_terrenos(grilla_terrenos),
                               grilla_texturas(grilla_texturas),
                               centros_ubicados(centros_ubicados),
                               cant_jugadores(cant_jugadores),
                               cant_filas_grillas(cant_filas_grillas),
                               cant_columnas_grillas(cant_columnas_grillas),
                               terreno_seleccionado(terreno_seleccionado),
                               textura_seleccionada(textura_seleccionada),
                               path_textura_seleccionada(path_textura) {
    this->setFrameShape(QFrame::Box);
    this->setBaseSize(50, 50);
    this->setMinimumSize(QSize(50, 50));
    this->setMaximumSize(QSize(50, 50));
    this->setPixmap(QPixmap(QString::fromUtf8(RESOURCE_PATH"/terrenos/arena/mostrador/arena9.bmp")));
}

ClickableLabel::~ClickableLabel() = default;

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}

void ClickableLabel::establecerTextura() {
    int coord_x = obtenerCoordenadaX();
    int coord_y = obtenerCoordenadaY();
    std::cout << "Se clickeo la coordenada: " << coord_x << " " << coord_y << std::endl;
    if (seQuiereEstablecerUnCentro()) {
        if (faltanEstablecerCentros()) {
            if (laPosicionParaUnCentroEsValida(coord_x, coord_y)) {
                setPixmap(QPixmap(*path_textura_seleccionada));
                centros_ubicados.emplace_back(std::make_tuple(coord_x, coord_y));
                marcarUbicacionDelCentro(coord_x, coord_y);
            } else {
                if (!lasCoordenadasDelCentroPermanecenEnElMapa(coord_x, coord_y)) {
                    QMessageBox::information(this, "Error al establecer Centro", "Las coordenadas del centro se van de límites, recuerde que el centro es de 3x3.");
                } else {
                    QMessageBox::information(this, "Error al establecer Centro", "El centro se intentó establecer en coordenadas ocupadas por otro centro.");
                }
            }
        } else {
            QMessageBox::information(this, "Error al establecer Centro", "Ya fueron establecidos todos los centros de construcción.");
        }
    } else {
        if (seQuiereEstablecerTexturaSobreUnCentro(coord_x, coord_y)) {
            if (seClickeoSobreElOrigenDelCentro(coord_x, coord_y)) {
                eliminarCentro(coord_x, coord_y);
                establecerTexturaEnLaGrilla(coord_x, coord_y);
            } else {
                QMessageBox::information(this, "Error al establecer Textura", "Para establecer texturas en coordenadas donde hay un centro, primero establecer sobre el icono del mismo.");
            }
        } else {
            establecerTexturaEnLaGrilla(coord_x, coord_y);
        }
    }
}

void ClickableLabel::establecerTexturaEnLaGrilla(int coord_x, int coord_y) {
    (*grilla_terrenos)[coord_y][coord_x] = *terreno_seleccionado;
    (*grilla_texturas)[coord_y][coord_x] = *textura_seleccionada;
    setPixmap(QPixmap(*path_textura_seleccionada));
}

bool ClickableLabel::seQuiereEstablecerTexturaSobreUnCentro(int& coord_x, int& coord_y) {
    if ((*grilla_terrenos)[coord_y][coord_x] == 'X') {
        return true;
    }
    return false;
}

bool ClickableLabel::seClickeoSobreElOrigenDelCentro(int& coord_x, int& coord_y) const {
    for (auto &centro_ubicado : centros_ubicados) {
        int coord_centro_x = std::get<0>(centro_ubicado);
        int coord_centro_y = std::get<1>(centro_ubicado);
        if (coord_centro_x == coord_x && coord_centro_y == coord_y) {
            return true;
        }
    }
    return false;
}

void ClickableLabel::eliminarCentro(int& coord_x, int& coord_y) {
    std::tuple coord_a_eliminar = std::tuple(coord_x, coord_y);
    auto itr = std::find(centros_ubicados.begin(), centros_ubicados.end(), coord_a_eliminar);
    centros_ubicados.erase(itr);
    for (int i = coord_y; i < coord_y + 3; i++) {
        for (int j = coord_x; j < coord_x + 3; j++) {
            (*grilla_terrenos)[i][j] = TIPO_TERRENO_DEFAULT;
            (*grilla_texturas)[i][j] = TIPO_TEXTURA_DEFAULT;
        }
    }
}

void ClickableLabel::marcarUbicacionDelCentro(int& coord_x, int& coord_y) {
    for (int i = coord_y; i < coord_y + 3; i++) {
        for (int j = coord_x; j < coord_x + 3; j++) {
            (*grilla_terrenos)[i][j] = *terreno_seleccionado;
        }
    }
}

int ClickableLabel::obtenerCoordenadaY() {
    return pos().y() / PIXELES_COORDENADA;
}

int ClickableLabel::obtenerCoordenadaX() {
    return pos().x() / PIXELES_COORDENADA;
}

bool ClickableLabel::faltanEstablecerCentros() { return (int) centros_ubicados.size() < cant_jugadores; }

bool ClickableLabel::seQuiereEstablecerUnCentro() { return *terreno_seleccionado == 'X'; }

bool ClickableLabel::laPosicionParaUnCentroEsValida(int& coord_x, int& coord_y) {
    return lasCoordenadasDelCentroPermanecenEnElMapa(coord_x, coord_y) && lasCoordenadasNoCoincidenConLasDeOtroCentro(coord_x, coord_y);
}

bool ClickableLabel::lasCoordenadasNoCoincidenConLasDeOtroCentro(const int &coord_x, const int &coord_y) const {
    for (int i = coord_y; i < coord_y + 3; i++) {
        for (int j = coord_x; j < coord_x + 3; j++) {
            if ((*grilla_terrenos)[i][j] == 'X') {
                return false;
            }
        }
    }
    return true;
}

bool ClickableLabel::lasCoordenadasDelCentroPermanecenEnElMapa(const int &coord_x, const int &coord_y) const {
    if (coord_x + 3 <= cant_columnas_grillas && coord_y + 3 <= cant_filas_grillas) {
        std::cout << coord_x + 3 << " " << coord_y + 3<< std::endl;
        return true;
    } else {
        return false;
    }
}
