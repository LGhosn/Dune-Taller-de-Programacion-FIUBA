#ifndef SERVER_FUERA_DE_RANGO_EXCEPTION_H
#define SERVER_FUERA_DE_RANGO_EXCEPTION_H

#include <exception>

#define BUFFER_LEN 256

class FueraDeRangoException : public std::exception {
	private:
	char mensaje[BUFFER_LEN];

	public:
	// Recibe un mensaje que puede tener una cantidad variable de argumentos.
	// Precondicion: el mensaje no debe ocupar mas de 255 caracteres.
	FueraDeRangoException(const char *fmt, ...) noexcept;

	// Devuelve el mensaje de la excepcion.
	virtual const char* what() const noexcept;

	virtual ~FueraDeRangoException() noexcept = default;
};

#endif
