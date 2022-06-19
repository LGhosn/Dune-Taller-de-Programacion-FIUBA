#ifndef DUNE_EDITOR_H
#define DUNE_EDITOR_H

#include <cstdlib>
#include <QMainWindow>
#include <QScreen>
#include "DuneMapEditor_ui.h"

class DuneMapEditor: public QMainWindow {
private:
    Ui_DuneMapEditor* ui;
    std::string edition_mode = "-";
    std::string terrain_type = "-";
    uint8_t required_players;
    uint32_t map_rows = 250;
    uint32_t map_columns = 250;

public:
    explicit DuneMapEditor(QWidget *parent = nullptr);
};
#endif