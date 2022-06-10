#include "cmd_zoom.h"

ComandoZoom::ComandoZoom(char sentido) : sentido(sentido) {}

bool ComandoZoom::ejecutar(WorldView& worldView) const {
    if (sentido == ZOOM_IN) {
        worldView.zoomIn();
    } else if (sentido == ZOOM_OUT) {
        worldView.zoomOut();
    }
    return true;
}
