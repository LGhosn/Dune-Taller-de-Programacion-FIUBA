#include "FormCreacion.h"
#include "../src_cliente/client_solicitudes/sol_crear_partida.h"

FormCreacion::FormCreacion(Client& cliente, QWidget* parent) :
                            QWidget(parent),
                            cliente(cliente),
                            ui(new Ui_FromCrear) {
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    connect(ui->CrearButton, &QPushButton::clicked, this, &FormCreacion::solicitudDeCreacion);
    connect(ui->AtreidesButton, &QPushButton::clicked, this, &FormCreacion::elegirCasaAtreides);
    connect(ui->HarkonnenButton, &QPushButton::clicked, this, &FormCreacion::elegirCasaHarkonnen);
    connect(ui->OrdosButton, &QPushButton::clicked, this, &FormCreacion::elegirCasaOrdos);
}

void FormCreacion::solicitudDeCreacion() {
    try {
        // Tomamos de cada campo rellenado por el usuario.
        std::string nombre_partida = ui->NombreLine->text().toStdString();
        std::string mapa = ui->MapaLine->text().toStdString();
        std::string casa = ui->CasaLine->text().toStdString();
        uint8_t jugadores_requeridos = ui->CantLine->text().toInt();

        // Validamos que el nombre de la partida y mapa no sean un string vacío,
        // la casa y el número de jugadores requeridos en caso de no serlo se
        // notifica que el campo no es válido y no se crea la solicitud hasta
        // que dicho campo sea válido.
        if (algunParametroNoEsValido(nombre_partida, mapa, casa, jugadores_requeridos)) {
            QMessageBox::information(this, "Error en los campos rellenados",
                                     "Recuerda rellenar el campo de nombre de partida, mapa, elegir una casa de las tres disponibles y una cantidad de jugadores requeridos para comenzar la partida.");
        } else {
            SolicitudDeCreacion solicitud(nombre_partida, mapa, casa, jugadores_requeridos);
            ProtocoloCliente& protocolo = cliente.protocoloAsociado();
            protocolo.enviarSolicitudDeCreacion(solicitud);
            Status status_recibido = protocolo.recibirStatus();
            crearNotificacion(status_recibido);
            //protocolo.esperarAComienzoDePartida();
        }
    } catch (const std::exception &e) {
        syslog(LOG_CRIT, "Error detectado: %s", e.what());
    } catch (...) {
        syslog(LOG_CRIT, "Error desconocido.\n");
    }
}

void FormCreacion::crearNotificacion(Status& status) {
    if (status.conexionEstablecida()) {
        QMessageBox::information(this, "Creacion Existosa", "Esperando jugadores restantes...");
    } else {
        QMessageBox::information(this, "Creacion Fallida", "Existe otra partida con ese mismo nombre, por favor elegir otro.");
        this->close();
    }
}

bool FormCreacion::algunParametroNoEsValido(std::string &nombre_partida,
                                            std::string &mapa,
                                            std::string &casa,
                                            uint8_t& jugadores_requeridos) {
    return elNombreDePartidaNoEsValido(nombre_partida) || elMapaNoEsValido(mapa) || laCasaNoEsValida(casa);
}

bool FormCreacion::elNombreDePartidaNoEsValido(std::string& nombre_partida) {
    return nombre_partida.empty();
}

bool FormCreacion::elMapaNoEsValido(std::string& mapa) {
    return mapa.empty();
}

bool FormCreacion::laCasaNoEsValida(std::string &casa) {
    auto itr = casas_elegibles.find(casa);
    return itr == casas_elegibles.end();
}

void FormCreacion::elegirCasaAtreides() {
    ui->CasaLine->setText("Atreides");
}

void FormCreacion::elegirCasaHarkonnen() {
    ui->CasaLine->setText("Harkonnen");
}

void FormCreacion::elegirCasaOrdos() {
    ui->CasaLine->setText("Ordos");
}

FormCreacion::~FormCreacion() {
    delete ui;
}
