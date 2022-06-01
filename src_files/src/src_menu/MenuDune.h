#ifndef MENU_DUNE_H
#define MENU_DUNE_H

#include "../src_cliente/client_protocolo.h"
#include "../src_form_creacion/FormCreacion.h"
#include "../src_form_union/FormUnion.h"
#include <QWidget>
#include <QScreen>

class Ui_Menu;

class MenuDune : public QWidget {
public:
    explicit MenuDune(ProtocoloCliente& protocolo, QWidget *parent = nullptr);
    void mostrarVentanaDeCreacion();
    void mostrarVentanaDeUnion();
    ~MenuDune() override;

    /*
     * No tiene sentido copiar un cliente y tampoco moverlo (al menos por ahora).
     * */
    MenuDune(const MenuDune&) = delete;
    MenuDune& operator=(const MenuDune&) = delete;
    MenuDune(MenuDune&&) = delete;
    MenuDune& operator=(MenuDune&&) = delete;
private:
    Ui_Menu* ui;
    FormUnion* formulario_union;
    FormCreacion* formulario_creacion;
};
#endif // MENU_DUNE_H
