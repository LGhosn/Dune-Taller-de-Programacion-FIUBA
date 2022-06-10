#ifndef SERVER_COMANDO_H
#define SERVER_COMANDO_H

class ComandoServer {
public:
    virtual void enviarComando() const = 0;

    virtual ~ComandoServer() = default;
};

#endif
