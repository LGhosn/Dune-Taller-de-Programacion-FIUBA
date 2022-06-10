#ifndef COMMON_CAMINO_NO_ENCONTRADO_EXCEPTION_H
#define COMMON_CAMINO_NO_ENCONTRADO_EXCEPTION_H

#include <exception>

#define BUFFER_LEN 256

class CaminoNoEncontradoException : public std::exception {
	private:
	char mensaje[BUFFER_LEN];

	public:
	// Recibe un mensaje que puede tener una cantidad variable de argumentos.
	// Precondicion: el mensaje no debe ocupar mas de 255 caracteres.
	CaminoNoEncontradoException(const char *fmt, ...) noexcept;

	// Devuelve el mensaje de la excepcion.
	virtual const char* what() const noexcept;

	virtual ~CaminoNoEncontradoException() noexcept = default;
};

#endif
