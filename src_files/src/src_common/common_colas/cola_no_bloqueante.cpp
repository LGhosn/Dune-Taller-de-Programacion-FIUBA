#include "cola_no_bloqueante.h"
#include "../common_comandos/comando.h"
#include "../common_comandos/common_solicitud.h"
#include <utility>

template<class T>
std::unique_ptr<T> ColaNoBloqueante<T>::pop() {
	std::unique_lock<std::mutex> lock(this->mutex);
	if (this->cola.empty())
		return NULL;
	std::unique_ptr<T> elem = std::move(this->cola.front());
	this->cola.pop();
	return elem;
}

template<class T>
std::queue<std::unique_ptr<T>> ColaNoBloqueante<T>::popAll() {
	std::unique_lock<std::mutex> lock(this->mutex);
	std::queue<std::unique_ptr<T>> cola_copia = std::move(this->cola);
	this->cola = std::queue<std::unique_ptr<T>>();
	return cola_copia;
}

template<class T>
void ColaNoBloqueante<T>::push(T* elem) {
	std::unique_lock<std::mutex> lock(this->mutex);
	this->cola.emplace(elem);
}

template class ColaNoBloqueante<Comando>;
template class ColaNoBloqueante<Solicitud>;
