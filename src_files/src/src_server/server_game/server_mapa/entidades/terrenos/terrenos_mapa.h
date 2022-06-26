#ifndef TERRENOS_H
#define TERRENOS_H

#include "../entidades_mapa.h"

class Terrenos : public Entidades {
public:
    Terrenos() = default;
    virtual char obtenerTipo();
    virtual ~Terrenos();
};

class Arena : public Terrenos {
public:
    Arena() = default;
    virtual ~Arena();
};

class Duna : public Terrenos {
public:
    Duna() = default;
    virtual ~Duna();
};

class Roca : public Terrenos {
public:
    Roca() = default;
    virtual ~Roca();
};

class Cima : public Terrenos {
public:
    Cima() = default;
    virtual ~Cima();
};

class Precipicio : public Terrenos {
public:
    Precipicio() = default;
    virtual ~Precipicio();
};


#endif // TERRENOS_H
