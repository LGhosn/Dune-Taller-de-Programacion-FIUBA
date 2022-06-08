#include "FormUnion.h"

FormUnion::FormUnion(ProtocoloCliente& protocolo_asociado, QWidget *parent) :
                        protocolo_asociado(protocolo_asociado),
                        QWidget(parent),
                        ui(new Ui_FormUnir) {
    ui->setupUi(this);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    connect(ui->UnirseButton, &QPushButton::clicked, this, &FormUnion::solicitudDeUnion);
    connect(ui->AtreidesButton, &QPushButton::clicked, this, &FormUnion::elegirCasaAtreides);
    connect(ui->HarkonneButton, &QPushButton::clicked, this, &FormUnion::elegirCasaHarkonnen);
    connect(ui->OrdosButton, &QPushButton::clicked, this, &FormUnion::elegirCasaOrdos);
}

void FormUnion::solicitudDeUnion() {
    try {
        // Tomamos de cada campo rellenado por el usuario (el caso del nombre de partida).
        // Y la casa será elegida al clickear el icono correspondiente según el usuario.
        std::string nombre_partida = ui->NombreLine->text().toStdString();
        std::string casa = ui->CasaLine->text().toStdString();

        // Validamos que el nombre de la partida no sea un string vacío,
        // en caso de serlo se notifica que el campo no es válido y no
        // se crea la solicitud hasta que dicho campo sea válido.
        if (algunParametroNoEsValido(casa, nombre_partida)) {
            QMessageBox::information(this, "Error en la casa o el nombre de partida elegidos",
                                     "Recuerda elegir una casa de las tres disponibles y que rellenar el campo de nombre de partida.");
        } else {
            // Armamos la solicitud de union a enviar por el protocolo del cliente.
            SolicitudDeUnion solicitud(nombre_partida, casa);
            protocolo_asociado.enviarSolicitudDeUnion(solicitud);
            StatusDTO status = protocolo_asociado.recibirStatus();
            unirseNotificacion(status);
            protocolo_asociado.esperarComenzarPartida();
        }
    } catch (const std::exception &e) {
        syslog(LOG_CRIT, "Error detectado: %s", e.what());
    } catch (...) {
        syslog(LOG_CRIT, "Error desconocido.\n");
    }
}

void FormUnion::unirseNotificacion(StatusDTO &status) {
    if (status.status == 0) {
        QMessageBox::information(this, "Union Existosa", "Esperando jugadores restantes...");
        this->close();
    } else {
        QMessageBox::information(this, "Union Fallida", "Parece que esa partida no existe o ya que ha comenzado.");
    }
}

void FormUnion::elegirCasaAtreides() {
    ui->CasaLine->setText("Atreides");
}

void FormUnion::elegirCasaHarkonnen() {
    ui->CasaLine->setText("Harkonnen");
}

void FormUnion::elegirCasaOrdos() {
    ui->CasaLine->setText("Ordos");
}

bool FormUnion::algunParametroNoEsValido(std::string& casa, std::string& nombre_partida) {
    return elNombreDePartidaNoEsValido(nombre_partida) || laCasaNoEsValida(casa);
}

bool FormUnion::laCasaNoEsValida(std::string &casa) {
    auto itr = casas_elegibles.find(casa);
    return itr == casas_elegibles.end();
}

bool FormUnion::elNombreDePartidaNoEsValido(std::string& nombre_partida) {
    return nombre_partida.empty();
}

FormUnion::~FormUnion() {
    delete ui;
}
