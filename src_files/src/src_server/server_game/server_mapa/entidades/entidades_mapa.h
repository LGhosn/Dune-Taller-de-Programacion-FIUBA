#ifndef ENTIDADES_H
#define ENTIDADES_H

class Entidades {
protected:
    char tipo;
    
public:
    Entidades() = default;
    virtual char obtenerTipo() = 0;
    virtual ~Entidades() = default;
};

#endif // ENTIDADES_H
