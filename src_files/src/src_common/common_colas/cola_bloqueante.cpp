#include "cola_bloqueante.h"

template<class T>
ColaBloqueante<T>::ColaBloqueante() {}

template<class T>
std::unique_lock<T> ColaBloqueante<T>::wait_and_pop() {
	std::unique_lock<std::mutex> lock(this->mutex);
	while (this->cola.empty()) {
		this->cv.wait(lock);
	}
	T elem = this->cola.front();
	this->cola.pop();
	return elem;
}

template<class T>
void ColaBloqueante<T>::push(T* elem) {
	std::unique_lock<std::mutex> lock(this->mutex);
	this->cola.push(elem);
	this->cv.notify_all();
}
