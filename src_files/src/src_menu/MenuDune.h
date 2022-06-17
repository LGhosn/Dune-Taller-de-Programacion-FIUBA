#ifndef MENU_DUNE_H
#define MENU_DUNE_H

#include "../src_cliente/client_client.h"
#include "../src_cliente/client_protocolo.h"
#include "../src_form_creacion/FormCreacion.h"
#include "../src_form_union/FormUnion.h"
#include <QWidget>
#include <QScreen>

class Ui_Menu;

class MenuDune : public QWidget {
public:
    explicit MenuDune(Client& cliente, QWidget *parent = nullptr);
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
    FormCreacion* formulario_creacion;
    FormUnion* formulario_union;
    Client& cliente_asociado;
};
#endif // MENU_DUNE_H
