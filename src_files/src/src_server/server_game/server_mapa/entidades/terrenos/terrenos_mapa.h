#ifndef TERRENOS_H
#define TERRENOS_H

#include "../entidades_mapa.h"

class Terrenos : public Entidades {
public:
    Terrenos() = default;
    virtual char obtenerTipo();
    virtual ~Terrenos() = default;
};

class Arena : public Terrenos {
public:
    Arena();
    virtual ~Arena() = default;
};

class Duna : public Terrenos {
public:
    Duna();
    virtual ~Duna() = default;
};

class Roca : public Terrenos {
public:
    Roca();
    virtual ~Roca() = default;
};

class Cima : public Terrenos {
public:
    Cima();
    virtual ~Cima() = default;
};

class Precipicio : public Terrenos {
public:
    Precipicio();
    virtual ~Precipicio() = default;
};


#endif // TERRENOS_H
