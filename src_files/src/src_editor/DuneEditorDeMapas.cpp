#include "DuneEditorDeMapas.h"

/* *****************************************************************
 *           CONSTRUCTOR UTILIZADO AL CREAR UN MAPA NUEVO
 * *****************************************************************/

DuneEditorDeMapas::DuneEditorDeMapas(QWidget* parent,
                                     int cant_filas,
                                     int cant_columnas,
                                     int cant_jugadores) :
                                     ui(new Ui_DuneEditorDeMapas),
                                     grilla_terrenos(new std::vector(cant_filas, std::vector<char>(cant_columnas, TIPO_TERRENO_DEFAULT))),
                                     grilla_texturas(new std::vector(cant_filas, std::vector<uint8_t>(cant_columnas, TIPO_TEXTURA_DEFAULT))) {
    ui->setupUi(this);
    ui->scrollArea->setStyleSheet("background-color: rgb(114, 159, 207);");
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
                                     const char *path_mapa) :
                                     ui(new Ui_DuneEditorDeMapas) {
    ui->setupUi(this);
    ui->scrollArea->setStyleSheet("background-color: rgb(114, 159, 207);");
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
            ClickableLabel* label = new ClickableLabel(reinterpret_cast<std::vector<std::vector<char>> *>(grilla_terrenos),
                                                       reinterpret_cast<std::vector<std::vector<uint8_t>> *>(grilla_texturas),
                                                       &terreno_seleccionado,
                                                       &textura_seleccionada,
                                                       &path_textura_seleccionada);
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
    ui->TerrainTextureComboBox->addItem("-");
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
    } else if (terreno == "CUARTEL") {
        mostrarCuartelSeleccionado();
    }
}

void DuneEditorDeMapas::mostrarCuartelSeleccionado() {
    path_textura_seleccionada = RESOURCE_PATH"/terrenos/cuartel.png";
    terreno_seleccionado = 'B';
}

void DuneEditorDeMapas::mostrarArenaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "-") {
        //ui->MostradorTexturaLabel->setPixmap(QPixmap(QString::fromUtf8(":/")))
    } else if (textura == "arena0.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena0.bmp", 'A', 0);
    } else if (textura == "arena1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena1.bmp", 'A', 1);
    } else if (textura == "arena2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena2.bmp", 'A', 2);
    } else if (textura == "arena3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena3.bmp", 'A', 3);
    } else if (textura == "arena4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena4.bmp", 'A', 4);
    } else if (textura == "arena5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena5.bmp", 'A', 5);
    } else if (textura == "arena6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena6.bmp", 'A', 6);
    } else if (textura == "arena7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena7.bmp", 'A', 7);
    } else if (textura == "arena8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena8.bmp", 'A', 8);
    } else if (textura == "arena9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena9.bmp", 'A', 9);
    } else if (textura == "arena10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena10.bmp", 'A', 10);
    } else if (textura == "arena11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena11.bmp", 'A', 11);
    } else if (textura == "arena12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/arena/mostrador/arena12.bmp", 'A', 12);
    }
}

void DuneEditorDeMapas::mostrarDunaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "-") {
        //ui->MostradorTexturaLabel->setPixmap(QPixmap(QString::fromUtf8(":/")))
    } else if (textura == "duna0.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna0.bmp", 'D', 0);
    } else if (textura == "duna1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna1.bmp", 'D', 1);
    } else if (textura == "duna2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna2.bmp", 'D', 2);
    } else if (textura == "duna3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna3.bmp", 'D', 3);
    } else if (textura == "duna4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna4.bmp", 'D', 4);
    } else if (textura == "duna5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna5.bmp", 'D', 5);
    } else if (textura == "duna6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/dunas/mostrador/duna6.bmp", 'D', 6);
    }
}

void DuneEditorDeMapas::mostrarRocaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "-") {
        //ui->MostradorTexturaLabel->setPixmap(QPixmap(QString::fromUtf8(":/")))
    } else if (textura == "roca1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca1.bmp", 'R', 1);
    } else if (textura == "roca2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca2.bmp", 'R', 2);
    } else if (textura == "roca3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca3.bmp", 'R', 3);
    } else if (textura == "roca4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca4.bmp", 'R', 4);
    } else if (textura == "roca5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca5.bmp", 'R', 5);
    } else if (textura == "roca6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca6.bmp", 'R', 6);
    } else if (textura == "roca7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca7.bmp", 'R', 7);
    } else if (textura == "roca8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca8.bmp", 'R', 8);
    } else if (textura == "roca9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca9.bmp", 'R', 9);
    } else if (textura == "roca10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca10.bmp", 'R', 10);
    } else if (textura == "roca11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca11.bmp", 'R', 11);
    } else if (textura == "roca12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca12.bmp", 'R', 12);
    } else if (textura == "roca13.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca13.bmp", 'R', 13);
    } else if (textura == "roca14.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca14.bmp", 'R', 14);
    } else if (textura == "roca15.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca15.bmp", 'R', 15);
    } else if (textura == "roca16.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/roca/mostrador/roca16.bmp", 'R', 16);
    }
}

void DuneEditorDeMapas::mostrarCimaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "-") {
        //ui->MostradorTexturaLabel->setPixmap(QPixmap(QString::fromUtf8(":/")))
    } else if (textura == "cima0.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima0.jpg", 'C', 0);
    } else if (textura == "cima1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima1.jpg", 'C', 1);
    } else if (textura == "cima2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima2.jpg", 'C', 2);
    } else if (textura == "cima3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima3.jpg", 'C', 3);
    } else if (textura == "cima4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima4.jpg", 'C', 4);
    } else if (textura == "cima5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima5.jpg", 'C', 5);
    } else if (textura == "cima6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima6.jpg", 'C', 6);
    } else if (textura == "cima7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima7.jpg", 'C', 7);
    } else if (textura == "cima8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima8.jpg", 'C', 8);
    } else if (textura == "cima9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima9.jpg", 'C', 9);
    } else if (textura == "cima10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima10.jpg", 'C', 10);
    } else if (textura == "cima11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima11.jpg", 'C', 11);
    } else if (textura == "cima12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima12.jpg", 'C', 12);
    } else if (textura == "cima13.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima13.jpg", 'C', 13);
    } else if (textura == "cima14.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima14.jpg", 'C', 14);
    } else if (textura == "cima15.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima15.jpg", 'C', 15);
    } else if (textura == "cima16.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima16.jpg", 'C', 16);
    } else if (textura == "cima17.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/cimas/mostrador/cima17.jpg", 'C', 17);
    }
}

void DuneEditorDeMapas::mostrarPrecipicioSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "-") {
        //ui->MostradorTexturaLabel->setPixmap(QPixmap(QString::fromUtf8(":/")))
    } else if (textura == "Precipicio1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio1.bmp", 'P', 1);
    } else if (textura == "Precipicio2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio2.bmp", 'P', 2);
    } else if (textura == "Precipicio3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio3.bmp", 'P', 3);
    } else if (textura == "Precipicio4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio4.bmp", 'P', 4);
    } else if (textura == "Precipicio5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio5.bmp", 'P', 5);
    } else if (textura == "Precipicio6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio6.bmp", 'P', 6);
    } else if (textura == "Precipicio7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio7.bmp", 'P', 7);
    } else if (textura == "Precipicio8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio8.bmp", 'P', 8);
    } else if (textura == "Precipicio9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio9.bmp", 'P', 9);
    } else if (textura == "Precipicio10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio10.bmp", 'P', 10);
    } else if (textura == "Precipicio11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio11.bmp", 'P', 11);
    } else if (textura == "Precipicio12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio12.bmp", 'P', 12);
    } else if (textura == "Precipicio13.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio13.bmp", 'P', 13);
    }  else if (textura == "Precipicio14.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio14.bmp", 'P', 14);
    } else if (textura == "Precipicio15.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio15.bmp", 'P', 15);
    } else if (textura == "Precipicio16.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio16.bmp", 'P', 16);
    } else if (textura == "Precipicio17.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio17.bmp", 'P', 17);
    } else if (textura == "Precipicio18.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio18.bmp", 'P', 18);
    } else if (textura == "Precipicio19.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio19.bmp", 'P', 19);
    } else if (textura == "Precipicio20.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio20.bmp", 'P', 20);
    } else if (textura == "Precipicio21.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio21.bmp", 'P', 21);
    } else if (textura == "Precipicio22.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio22.bmp", 'P', 22);
    } else if (textura == "Precipicio23.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/precipicio/mostrador/Precipicio23.bmp", 'P', 23);
    }
}

void DuneEditorDeMapas::mostrarEspeciaSeleccionada() {
    QString textura = ui->TerrainTextureComboBox->currentText();
    if (textura == "-") {
        //ui->MostradorTexturaLabel->setPixmap(QPixmap(QString::fromUtf8(":/")))
    } else if (textura == "especia_abuntante0.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abuntante0.bmp", 'E', 1);
    } else if (textura == "especia_abuntante1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abuntante1.bmp", 'E', 2);
    } else if (textura == "especia_abuntante2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abuntante2.bmp", 'E', 3);
    } else if (textura == "especia_abuntante3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abuntante3.bmp", 'E', 4);
    } else if (textura == "especia_abuntante4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_abuntante4.bmp", 'E', 5);
    } else if (textura == "especia_escasa1.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa1.bmp", 'E', 6);
    } else if (textura == "especia_escasa2.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa2.bmp", 'E', 7);
    } else if (textura == "especia_escasa3.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa3.bmp", 'E', 8);
    } else if (textura == "especia_escasa4.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa4.bmp", 'E', 9);
    } else if (textura == "especia_escasa5.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa5.bmp", 'E', 10);
    } else if (textura == "especia_escasa6.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa6.bmp", 'E', 11);
    } else if (textura == "especia_escasa7.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa7.bmp", 'E', 12);
    } else if (textura == "especia_escasa8.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa8.bmp", 'E', 13);
    }  else if (textura == "especia_escasa9.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa9.bmp", 'E', 14);
    } else if (textura == "especia_escasa10.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa10.bmp", 'E', 15);
    } else if (textura == "especia_escasa11.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa11.bmp", 'E', 16);
    } else if (textura == "especia_escasa12.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa12.bmp", 'E', 17);
    } else if (textura == "especia_escasa13.bmp") {
        seleccionarTextura(RESOURCE_PATH"/terrenos/especia/mostrador/especia_escasa13.bmp", 'E', 18);
    }
}

/* *****************************************************************
 *             METODOS REFERIDOS AL GUARDADO DE MAPAS
 * *****************************************************************/

void DuneEditorDeMapas::guardarMapa() {
    pedirNombreDelMapaAlUsuario(this);
}

void DuneEditorDeMapas::pedirNombreDelMapaAlUsuario(QWidget* parent) {
    bool ok;
    QString map_name = QInputDialog::getText(parent, tr("Ingresar nombre del mapa"),
                                         tr("Nombre del Mapa:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && map_name.isEmpty()) {
        QMessageBox::information(parent, "Error al guardar", "Recuerda elegir un nombre para el mapa creado.");
    } else if (ok && !map_name.isEmpty()) {
        escribirArchivoMapa(map_name);
        std::string informacion_sobre_guardado = "El mapa fue guardado con éxito en la carpeta:\n assets/maps/" + map_name.toStdString() + ".yaml";
        QMessageBox::information(parent, "Éxito al guardar", QString::fromStdString(informacion_sobre_guardado));
    }
}

void DuneEditorDeMapas::escribirArchivoMapa(QString &nombre_archivo) {
    YAML::Emitter out;

    out << YAML::BeginMap;
    out << YAML::Key << "Jugadores";
    out << YAML::Value << cantidad_jugadores;
    out << YAML::Key << "Ancho";
    out << YAML::Value << cantidad_columnas_mapa;
    out << YAML::Key << "Alto";
    out << YAML::Value << cantidad_filas_mapa;
    out << YAML::EndMap;

    out << YAML::BeginMap;
    out << YAML::Key << "TiposTerrenos";
    out << YAML::BeginSeq;
    for (int i = 0; i < cantidad_filas_mapa; i++) {
        std::vector<char> terrenos;
        for (int j = 0; j < cantidad_columnas_mapa; j++) {
            terrenos.push_back((*grilla_terrenos)[j][i]);
        }
        out << YAML::Value << YAML::Flow << terrenos;
    }
    out << YAML::EndSeq;
    out << YAML::EndMap;

    out << YAML::BeginMap;
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
    out << YAML::EndMap;

    std::ofstream archivo;
    std::string archivo_definitivo = nombre_archivo.toStdString() + ".yaml";
    archivo.open(archivo_definitivo);
    archivo << out.c_str();
    archivo.close();
    std::filesystem::copy(RESOURCE_PATH"/../build/" + archivo_definitivo, RESOURCE_PATH"/maps");
}