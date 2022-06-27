#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(std::vector<std::vector<char>>* grilla_terrenos,
                               std::vector<std::vector<uint8_t>>* grilla_texturas,
                               char* terreno_seleccionado,
                               uint8_t* textura_seleccionada,
                               QString* path_textura,
                               QWidget* parent,
                               Qt::WindowFlags f) :
                               QLabel(parent),
                               grilla_terrenos(grilla_terrenos),
                               grilla_texturas(grilla_texturas),
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
    int coord_x = pos().x();
    int coord_y = pos().y();
    (*grilla_terrenos)[coord_x][coord_y] = *terreno_seleccionado;
    (*grilla_texturas)[coord_x][coord_y] = *textura_seleccionada;
    setPixmap(QPixmap(*path_textura_seleccionada));
}
