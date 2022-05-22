#include <cerrno>
#include <cstdarg>
#include <cstring>
#include <cstdio>
#include <iostream>
#include "server_camino_no_encontrado_exception.h"

CaminoNoEncontradoException::CaminoNoEncontradoException(const char *fmt, ...) noexcept {
	va_list args;
	va_start(args, fmt);
	vsnprintf(this->mensaje, BUFFER_LEN, fmt, args);
	va_end(args);
	this->mensaje[BUFFER_LEN - 1] = 0;
}

const char* CaminoNoEncontradoException::what() const noexcept {
	return this->mensaje;
}
