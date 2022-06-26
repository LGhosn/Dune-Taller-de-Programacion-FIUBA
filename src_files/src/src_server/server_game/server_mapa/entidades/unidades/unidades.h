#ifndef UNIDADES_H
#define UNIDADES_H

class Unidades : public Entidades {
public:
    Unidades() = default;
    virtual char obtenerTipo();
    virtual ~Unidades();
};

#endif // UNIDADES_H
