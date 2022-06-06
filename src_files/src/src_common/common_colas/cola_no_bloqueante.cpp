#include "cola_no_bloqueante.h"
#include "comandos/comando.h"
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
void ColaNoBloqueante<T>::push(T* elem) {
	std::unique_lock<std::mutex> lock(this->mutex);
	this->cola.emplace(elem);
}

template class ColaNoBloqueante<Comando>;
