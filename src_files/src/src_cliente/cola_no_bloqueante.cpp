#include "cola_no_bloqueante.h"

template<typename T>
T ColaNoBloqueante<T>::pop() {
	std::unique_lock<std::mutex> lock(this->mutex);
	if (this->cola.empty())
		return NULL;
	T elem = this->cola.front();
	this->cola.pop();
	return elem;
}

void ColaNoBloqueante<T>::push(T& elem) {
	std::unique_lock<std::mutex> lock(this->mutex);
	this->cola.push(elem);
}
