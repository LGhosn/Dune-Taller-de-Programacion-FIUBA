#include "DuneEditorDeMapas.h"

/* *****************************************************************
 *           CONSTRUCTOR UTILIZADO AL CREAR UN MAPA NUEVO
 * *****************************************************************/

DuneEditorDeMapas::DuneEditorDeMapas(QWidget* parent,
                                     int cant_filas,
                                     int cant_columnas,
                                     int cant_jugadores) :
                                     ui(new Ui_DuneEditorDeMapas),
                                     grilla_terrenos(new std::vector(cant_filas, std::vector<int>(cant_columnas, TIPO_TERRENO_DEFAULT))),
                                     grilla_texturas(new std::vector(cant_filas, std::vector<int>(cant_columnas, TIPO_TEXTURA_DEFAULT))) {
    ui->setupUi(this);
    ui->scrollArea->setStyleSheet("background-color: rgb(114, 159, 207);");
    ui->MostradorTexturaLabel->setPixmap(QPixmap(RESOURCE_PATH"/terrenos/arena/mostrador/arena9.bmp"));  // Textura default utilizada a la hora de crear un mapa desde cero.
    establecerDatosDeCreacionDeMapa(cant_jugadores, cant_filas, cant_columnas);
    establecerGrillaEstandar();
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    connect(ui->SaveButton, &QPushButton::clicked, this, &DuneEditorDeMapas::guardarMapa);
    connect(ui->TerrainTypeComboBox, &QComboBox::currentTextChanged, this, &DuneEditorDeMapas::ofrecerTexturasSegunTipoDeTerreno);
    connect(ui->TerrainTextureComboBox, &QComboBox::currentTextChanged, this, &DuneEditorDeMapas::mostrarTexturaSegunTipoDeTerreno);
    cargarMapaDefault();
}

/* *****************************************************************
 *        CONSTRUCTOR UTILIZADO AL EDITAR UN MAPA EXISTENTE
 * *****************************************************************/

DuneEditorDeMapas::DuneEditorDeMapas(QWidget* parent,
                                     std::string &path_mapa) :
                                     ui(new Ui_DuneEditorDeMapas) {
    ui->setupUi(this);
    ui->scrollArea->setStyleSheet("background-color: rgb(114, 159, 207);");
    establecerGrillaEstandar();
    establecerDatosDeEdicionDeMapa((std::string &) path_mapa);
    move(QGuiApplication::screens().at(0)->geometry().center() - frameGeometry().center());
    connect(ui->SaveButton, &QPushButton::clicked, this, &DuneEditorDeMapas::guardarMapa);
    connect(ui->TerrainTypeComboBox, &QComboBox::currentTextChanged, this, &DuneEditorDeMapas::ofrecerTexturasSegunTipoDeTerreno);
    connect(ui->TerrainTextureComboBox, &QComboBox::currentTextChanged, this, &DuneEditorDeMapas::mostrarTexturaSegunTipoDeTerreno);
}

/* *****************************************************************
 *                      METODOS AUXILIARES
 * *****************************************************************/

void DuneEditorDeMapas::establecerDatosDeCreacionDeMapa(int cant_jugadores, int cant_filas, int cant_columnas) {
    modo_de_edicion = "Creando un nuevo mapa";
    cantidad_jugadores = cant_jugadores;
    cantidad_filas_mapa = cant_filas;
    cantidad_columnas_mapa = cant_columnas;
    ui->EditonModeLabel->setText(modo_de_edicion);
    ui->CantJugadoresLabel->setNum(cant_jugadores);
    ui->CantFilasLabel->setNum(cant_filas);
    ui->CantColumnasLabel->setNum(cant_columnas);
}

void DuneEditorDeMapas::establecerDatosDeEdicionDeMapa(std::string &path_mapa) {
    modo_de_edicion = "Editando un nuevo mapa";

    YAML::Node config = YAML::LoadFile(path_mapa);
    cantidad_jugadores = config["Jugadores"].as<int>();
    cantidad_columnas_mapa = config["Ancho"].as<int>();
    cantidad_filas_mapa = config["Alto"].as<int>();
    ui->EditonModeLabel->setText(modo_de_edicion);
    ui->CantJugadoresLabel->setNum(cantidad_jugadores);
    ui->CantColumnasLabel->setNum(cantidad_columnas_mapa);
    ui->CantFilasLabel->setNum(cantidad_filas_mapa);

    // Establecemos las matrices internas que contienen info sobre las texturas y los terrenos.
    grilla_terrenos = new std::vector<std::vector<int>>;
    grilla_texturas = new std::vector<std::vector<int>>;
    for (int i = 0; i < cantidad_filas_mapa; i++) {
        (*grilla_terrenos).emplace_back(config["TiposTerrenos"][i].as<std::vector<int>>());
        (*grilla_texturas).emplace_back(config["TiposTexturas"][i].as<std::vector<int>>());
    }

    // Establecemos las ClickableLabels que muestran las texturas establecidas.
    for (int i = 0; i < cantidad_filas_mapa; i++) {
        for (int j = 0; j < cantidad_columnas_mapa; j++){
            int terreno_editado = (*grilla_terrenos)[i][j];
            int textura_editada = (*grilla_texturas)[i][j];
            std::string path_textura_editada = obtenerPathSegunInfo(terreno_editado, textura_editada);
            ClickableLabel* label = new ClickableLabel(reinterpret_cast<std::vector<std::vector<int>> *>(grilla_terrenos),
                                                       reinterpret_cast<std::vector<std::vector<int>> *>(grilla_texturas),
                                                       centros_ubicados,
                                                       cantidad_jugadores,
                                                       cantidad_filas_mapa,
                                                       cantidad_columnas_mapa,
                                                       &terreno_editado,
                                                       &textura_editada,
                                                       reinterpret_cast<QString*>(&path_textura_editada));
            connect(label, &ClickableLabel::clicked, label, &ClickableLabel::establecerTextura);
            grilla->addWidget(label, i, j);
        }
    }
}

std::string DuneEditorDeMapas::obtenerPathSegunInfo(uint8_t terreno_editado, uint8_t textura_editada) {
    std::stringstream path_resultante;
    path_resultante << RESOURCE_PATH << "/terrenos/";
    if (terreno_editado == 0) {
        path_resultante << "arena/mostrador/arena" << (int) textura_editada << ".bmp";
    }  else if (terreno_editado == 2) {
        path_resultante << "duna/mostrador/duna" << (int) textura_editada << ".bmp";
    } else if (terreno_editado == 5) {
        path_resultante << "roca/mostrador/roca" << (int) textura_editada << ".bmp";
    } else if (terreno_editado == 1) {
        path_resultante << "cimas/mostrador/cima" << (int) textura_editada << ".bmp";
    } else if (terreno_editado == 4) {
        path_resultante << "precipicio/mostrador/precipicio" << (int) textura_editada << ".bmp";
    } else if (terreno_editado == 3) {
        path_resultante << "especia/mostrador/especia"  << (int) textura_editada << ".bmp";
    }
    return path_resultante.str();
}

void DuneEditorDeMapas::establecerGrillaEstandar() {
    grilla = new QGridLayout(ui->scrollAreaWidgetContents);
    grilla->setContentsMargins(0, 0, 0, 0);
    grilla->setHorizontalSpacing(0);
    grilla->setVerticalSpacing(0);
}

void DuneEditorDeMapas::cargarMapaDefault() {
    for (int i = 0; i < cantidad_filas_mapa; i++) {
        for (int j = 0; j < cantidad_columnas_mapa; j++) {
            ClickableLabel* label = new ClickableLabel(reinterpret_cast<std::vector<std::vector<int>> *>(grilla_terrenos),
                                                       reinterpret_cast<std::vector<std::vector<int>> *>(grilla_texturas),
                                                       centros_ubicados,
                                                       cantidad_jugadores,
                                                       cantidad_filas_mapa,
                                                       cantidad_columnas_mapa,
                                                       &terreno_seleccionado,
                                                       &textura_seleccionada,
                                                       reinterpret_cast<QString*>(&path_textura_seleccionada));
            connect(label, &ClickableLabel::clicked, label, &ClickableLabel::establecerTextura);
            grilla->addWidget(label, i, j);
        }
    }
}

/* *****************************************************************
 *        METODOS REFERIDOS A OFRECER TEXTURAS AL USUARIO
 * *****************************************************************/

void DuneEditorDeMapas::agregarTexturas(std::string &path) {
    ui->TerrainTextureComboBox->clear();
    std::vector<std::string> texturas_encontradas;
    for (auto &file: std::filesystem::directory_iterator(path)) {
        std::string textura_path = file.path();
        std::string textura = textura_path.substr(textura_path.find_last_of('/') + 1);
        texturas_encontradas.push_back(textura);
    }
    std::sort(texturas_encontradas.begin(), texturas_encontradas.end());
    for (auto &textura_encontrada: texturas_encontradas) {
        ui->TerrainTextureComboBox->addItem(QString::fromStdString(textura_encontrada));
    }
}

void DuneEditorDeMapas::ofrecerTexturasSegunTipoDeTerreno() {
    QString terreno = ui->TerrainTypeComboBox->currentText();
    if (terreno == "-") {
        ui->TerrainTextureComboBox->clear();
    } else if (terreno == "Arena") {
        ofrecerTexturasDeArena();
    } else if (terreno == "Duna") {
        ofrecerTexturasDeDuna();
    } else if (terreno == "Roca") {
        ofrecerTexturasDeRoca();
    } else if (terreno == "Cima") {
        ofrecerTexturasDeCima();
    } else if (terreno == "Precipicio") {
        ofrecerTexturasDePrecipicio();
    } else if (terreno == "Especia") {
        ofrecerTexturasDeEspecia();
    }  else if (terreno == "Centro") {
        mostrarCentroDeConstruccionSeleccionado();
    }
}

void DuneEditorDeMapas::ofrecerTexturasDeEspecia() {
    std::string path = RESOURCE_PATH"/terrenos/especia/mostrador";
    agregarTexturas(path);
}

void DuneEditorDeMapas::ofrecerTexturasDePrecipicio() {
    std::string path = RESOURCE_PATH"/terrenos/precipicio/mostrador";
    agregarTexturas(path);
}

void DuneEditorDeMapas::ofrecerTexturasDeCima() {
    std::string path = RESOURCE_PATH"/terrenos/cimas/mostrador";
    agregarTexturas(path);
}

void DuneEditorDeMapas::ofrecerTexturasDeRoca() {
    std::string path = RESOURCE_PATH"/terrenos/roca/mostrador";
    agregarTexturas(path);
}

void DuneEditorDeMapas::ofrecerTexturasDeDuna() {
    std::string path = RESOURCE_PATH"/terrenos/dunas/mostrador";
    agregarTexturas(path);
}

void DuneEditorDeMapas::ofrecerTexturasDeArena() {
    std::string path = RESOURCE_PATH"/terrenos/arena/mostrador";
    agregarTexturas(path);
}

/* *****************************************************************
 *        METODOS REFERIDOS A MOSTRAR TEXTURAS AL USUARIO
 * *****************************************************************/

void DuneEditorDeMapas::seleccionarTextura(const char* path, const char &tipo_terreno, const uint8_t &tipo_textura) {
    QString path_textura = QString::fromUtf8(path);
    ui->MostradorTexturaLabel->setPixmap(QPixmap(path));
    path_textura_seleccionada = path_textura;
    terreno_seleccionado = tipo_terreno;
    textura_seleccionada = tipo_textura;
}

void DuneEditorDeMapas::mostrarTexturaSegunTipoDeTerreno() {
    QString terreno = ui->TerrainTypeComboBox->currentText();
    if (terreno == "-") {
        ui->TerrainTextureComboBox->clear();
    } else if (terreno == "Arena") {
        mostrarArenaSeleccionada();
    } else if (terreno == "Duna") {
        mostrarDunaSeleccionada();
    } else if (terreno == "Roca") {
        mostrarRocaSeleccionada();
    } else if (terreno == "Cima") {
        mostrarCimaSeleccionada();
    } else if (terreno == "Precipicio") {
        mostrarPrecipicioSeleccionada();
    } else if (terreno == "Especia") {
        mostrarEspeciaSeleccionada();
    }
}

void DuneEditorDeMapas::mostrarCentroDeConstruccionSeleccionado() {
    ui->TerrainTextureComboBox->clear();
    path_textura_seleccionada = RESOURCE_PATH"/terrenos/cuartel.png";
    ui->MostradorTexturaLabel->setPixmap(QPixmap(path_textura_seleccionada));
    terreno_seleccionado = 6;
}

void DuneEditorDeMapas::mostrarArenaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "arena0.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena0.bmp", 0, 0);
    } else if (textura == "arena1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena1.bmp", 0, 1);
    } else if (textura == "arena2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena2.bmp", 0, 2);
    } else if (textura == "arena3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena3.bmp", 0, 3);
    } else if (textura == "arena4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena4.bmp", 0, 4);
    } else if (textura == "arena5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena5.bmp", 0, 5);
    } else if (textura == "arena6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena6.bmp", 0, 6);
    } else if (textura == "arena7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena7.bmp", 0, 7);
    } else if (textura == "arena8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena8.bmp", 0, 8);
    } else if (textura == "arena9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena9.bmp", 0, 9);
    } else if (textura == "arena10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena10.bmp", 0, 10);
    } else if (textura == "arena11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena11.bmp", 0, 11);
    } else if (textura == "arena12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena12.bmp", 0, 12);
    }
}

void DuneEditorDeMapas::mostrarDunaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "duna0.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna0.bmp", 2, 0);
    } else if (textura == "duna1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna1.bmp", 2, 1);
    } else if (textura == "duna2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna2.bmp", 2, 2);
    } else if (textura == "duna3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna3.bmp", 2, 3);
    } else if (textura == "duna4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna4.bmp", 2, 4);
    } else if (textura == "duna5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna5.bmp", 2, 5);
    } else if (textura == "duna6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna6.bmp", 2, 6);
    }
}

void DuneEditorDeMapas::mostrarRocaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "roca1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca1.bmp", 5, 1);
    } else if (textura == "roca2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca2.bmp", 5, 2);
    } else if (textura == "roca3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca3.bmp", 5, 3);
    } else if (textura == "roca4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca4.bmp", 5, 4);
    } else if (textura == "roca5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca5.bmp", 5, 5);
    } else if (textura == "roca6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca6.bmp", 5, 6);
    } else if (textura == "roca7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca7.bmp", 5, 7);
    } else if (textura == "roca8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca8.bmp", 5, 8);
    } else if (textura == "roca9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca9.bmp", 5, 9);
    } else if (textura == "roca10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca10.bmp", 5, 10);
    } else if (textura == "roca11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca11.bmp", 5, 11);
    } else if (textura == "roca12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca12.bmp", 5, 12);
    } else if (textura == "roca13.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca13.bmp", 5, 13);
    } else if (textura == "roca14.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca14.bmp", 5, 14);
    } else if (textura == "roca15.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca15.bmp", 5, 15);
    } else if (textura == "roca16.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca16.bmp", 5, 16);
    }
}

void DuneEditorDeMapas::mostrarCimaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "cima0.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima0.bmp", 1, 0);
    } else if (textura == "cima1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima1.bmp", 1, 1);
    } else if (textura == "cima2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima2.bmp", 1, 2);
    } else if (textura == "cima3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima3.bmp", 1, 3);
    } else if (textura == "cima4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima4.bmp", 1, 4);
    } else if (textura == "cima5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima5.bmp", 1, 5);
    } else if (textura == "cima6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima6.bmp", 1, 6);
    } else if (textura == "cima7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima7.bmp", 1, 7);
    } else if (textura == "cima8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima8.bmp", 1, 8);
    } else if (textura == "cima9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima9.bmp", 1, 9);
    } else if (textura == "cima10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima10.bmp", 1, 10);
    } else if (textura == "cima11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima11.bmp", 1, 11);
    } else if (textura == "cima12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima12.bmp", 1, 12);
    } else if (textura == "cima13.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima13.bmp", 1, 13);
    } else if (textura == "cima14.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima14.bmp", 1, 14);
    } else if (textura == "cima15.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima15.bmp", 1, 15);
    } else if (textura == "cima16.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima16.bmp", 1, 16);
    } else if (textura == "cima17.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima17.bmp", 1, 17);
    }
}

void DuneEditorDeMapas::mostrarPrecipicioSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "Precipicio1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio1.bmp", 4, 1);
    } else if (textura == "Precipicio2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio2.bmp", 4, 2);
    } else if (textura == "Precipicio3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio3.bmp", 4, 3);
    } else if (textura == "Precipicio4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio4.bmp", 4, 4);
    } else if (textura == "Precipicio5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio5.bmp", 4, 5);
    } else if (textura == "Precipicio6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio6.bmp", 4, 6);
    } else if (textura == "Precipicio7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio7.bmp", 4, 7);
    } else if (textura == "Precipicio8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio8.bmp", 4, 8);
    } else if (textura == "Precipicio9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio9.bmp", 4, 9);
    } else if (textura == "Precipicio10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio10.bmp", 4, 10);
    } else if (textura == "Precipicio11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio11.bmp", 4, 11);
    } else if (textura == "Precipicio12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio12.bmp", 4, 12);
    } else if (textura == "Precipicio13.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio13.bmp", 4, 13);
    }  else if (textura == "Precipicio14.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio14.bmp", 4, 14);
    } else if (textura == "Precipicio15.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio15.bmp", 4, 15);
    } else if (textura == "Precipicio16.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio16.bmp", 4, 16);
    } else if (textura == "Precipicio17.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio17.bmp", 4, 17);
    } else if (textura == "Precipicio18.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio18.bmp", 4, 18);
    } else if (textura == "Precipicio19.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio19.bmp", 4, 19);
    } else if (textura == "Precipicio20.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio20.bmp", 4, 20);
    } else if (textura == "Precipicio21.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio21.bmp", 4, 21);
    } else if (textura == "Precipicio22.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio22.bmp", 4, 22);
    } else if (textura == "Precipicio23.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio23.bmp", 4, 23);
    }
}

void DuneEditorDeMapas::mostrarEspeciaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "especia_abundante0.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abundante0.bmp", 3, 1);
    } else if (textura == "especia_abundante1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abundante1.bmp", 3, 2);
    } else if (textura == "especia_abundante2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abundante2.bmp", 3, 3);
    } else if (textura == "especia_abundante3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abundante3.bmp", 3, 4);
    } else if (textura == "especia_abundante4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abundante4.bmp", 3, 5);
    } else if (textura == "especia_escasa1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa1.bmp", 3, 6);
    } else if (textura == "especia_escasa2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa2.bmp", 3, 7);
    } else if (textura == "especia_escasa3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa3.bmp", 3, 8);
    } else if (textura == "especia_escasa4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa4.bmp", 3, 9);
    } else if (textura == "especia_escasa5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa5.bmp", 3, 10);
    } else if (textura == "especia_escasa6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa6.bmp", 3, 11);
    } else if (textura == "especia_escasa7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa7.bmp", 3, 12);
    } else if (textura == "especia_escasa8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa8.bmp", 3, 13);
    }  else if (textura == "especia_escasa9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa9.bmp", 3, 14);
    } else if (textura == "especia_escasa10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa10.bmp", 3, 15);
    } else if (textura == "especia_escasa11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa11.bmp", 3, 16);
    } else if (textura == "especia_escasa12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa12.bmp", 3, 17);
    } else if (textura == "especia_escasa13.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa13.bmp", 3, 18);
    }
}

/* *****************************************************************
 *             METODOS REFERIDOS AL GUARDADO DE MAPAS
 * *****************************************************************/

void DuneEditorDeMapas::guardarMapa() {
    if (faltanEstablecerCentros()) {
        std::string info = "Se establecieron " +
                           std::to_string(obtenerCantidadDeCentrosUbicados())
                           + " centros de los " +
                           std::to_string(obtenerCantidadDeCentrosNecesarios()) +
                           " necesarios.";
        QMessageBox::information(this, "Error al guardar", QString::fromStdString(info));
    } else {
        pedirNombreDelMapaAlUsuario(this);
    }
}

void DuneEditorDeMapas::pedirNombreDelMapaAlUsuario(QWidget* parent) {
    bool ok;
    QString map_name = QInputDialog::getText(parent, tr("Ingresar nombre del mapa"),
                                         tr("Nombre del Mapa:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && map_name.isEmpty()) {
        QMessageBox::information(parent, "Error al guardar", "Recuerda elegir un nombre para el mapa creado.");
    } else if (ok && !map_name.isEmpty()) {
        if (std::filesystem::exists(RESOURCE_PATH"/maps/" + map_name.toStdString() + ".yaml")) {
            QMessageBox::information(parent, "Error al guardar", "Ya existe un archivo con ese nombre, por favor, elegir otro.");
        } else {
            establecerRocaBajoCuarteles();
            escribirArchivoMapa(map_name);
            std::string informacion_sobre_guardado = "El mapa fue guardado con éxito en la carpeta:\n assets/maps/" + map_name.toStdString() + ".yaml";
            QMessageBox::information(parent, "Éxito al guardar", QString::fromStdString(informacion_sobre_guardado));
        }
    }
}

void DuneEditorDeMapas::establecerRocaBajoCuarteles() {
    for (auto &centro : centros_ubicados) {
        int coord_centro_x = std::get<0>(centro);
        int coord_centro_y = std::get<1>(centro);
        for (int i = coord_centro_y; i < coord_centro_y + 3 ; i++) {
            for (int j = coord_centro_x; j < coord_centro_x + 3;  j++) {
                (*grilla_terrenos)[i][j] = TERRENO_ROCA;
                (*grilla_texturas)[i][j] = TIPO_TEXTURA_DEFAULT;
            }
        }
    }
}

bool DuneEditorDeMapas::faltanEstablecerCentros() {
    return (int)centros_ubicados.size() < cantidad_jugadores;
}

int DuneEditorDeMapas::obtenerCantidadDeCentrosUbicados() {
    return (int)centros_ubicados.size();
}

int DuneEditorDeMapas::obtenerCantidadDeCentrosNecesarios() {
    return cantidad_jugadores;
}


void DuneEditorDeMapas::escribirArchivoMapa(QString &nombre_archivo) {
    YAML::Emitter out;
    escribirDatosDeMapa(out);
    escribirTiposDeTerreno(out);
    escribirTiposDeTexturas(out);
    escribirCentrosDeConstruccion(out);
    guardarArchivoMapa(nombre_archivo, out);
}

void DuneEditorDeMapas::guardarArchivoMapa(const QString &nombre_archivo, const YAML::Emitter &out) {
    std::ofstream archivo;
    std::string archivo_definitivo = nombre_archivo.toStdString() + ".yaml";
    archivo.open(archivo_definitivo);
    archivo << out.c_str();
    archivo.close();
    std::filesystem::copy(RESOURCE_PATH"/../build/" + archivo_definitivo, RESOURCE_PATH"/maps");
    std::filesystem::remove(RESOURCE_PATH"/../build/"+ archivo_definitivo);
}

void DuneEditorDeMapas::escribirCentrosDeConstruccion(YAML::Emitter &out) {
    out << YAML::Key << "CentrosDeConstruccion";
    out << YAML::BeginSeq;
    for (auto &centros : centros_ubicados) {
        std::map<char, uint16_t> coordenada_actual;
        coordenada_actual['x'] = std::get<0>(centros);
        coordenada_actual['y'] = std::get<1>(centros);
        out << coordenada_actual;
    }
    out << YAML::EndSeq;
    out << YAML::EndMap;
}

void DuneEditorDeMapas::escribirTiposDeTexturas(YAML::Emitter &out) {
    out << YAML::Key << "TiposTexturas";
    out << YAML::BeginSeq;
    for (int i = 0; i < cantidad_filas_mapa; i++) {
        std::vector<int> texturas;
        for (int j = 0; j < cantidad_columnas_mapa; j++) {
            texturas.push_back((int)(*grilla_texturas)[i][j]);
        }
        out << YAML::Value << YAML::Flow << texturas;
    }
    out << YAML::EndSeq;
}

void DuneEditorDeMapas::escribirTiposDeTerreno(YAML::Emitter &out) {
    out << YAML::Key << "TiposTerrenos";
    out << YAML::BeginSeq;
    for (int i = 0; i < cantidad_filas_mapa; i++) {
        std::vector<int> terrenos;
        for (int j = 0; j < cantidad_columnas_mapa; j++) {
            terrenos.push_back((int)(*grilla_terrenos)[i][j]);
        }
        out << YAML::Value << YAML::Flow << terrenos;
    }
    out << YAML::EndSeq;
}

void DuneEditorDeMapas::escribirDatosDeMapa(YAML::Emitter &out) {
    out << YAML::BeginMap;
    out << YAML::Key << "Jugadores";
    out << YAML::Value << cantidad_jugadores;
    out << YAML::Key << "Ancho";
    out << YAML::Value << cantidad_columnas_mapa;
    out << YAML::Key << "Alto";
    out << YAML::Value << cantidad_filas_mapa;
}
