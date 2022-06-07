#include "cola_bloqueante.h"
#include "../common_comandos/comando_a_enviar.h"

template<class T>
ColaBloqueante<T>::ColaBloqueante() {}

template<class T>
std::unique_ptr<T> ColaBloqueante<T>::wait_and_pop() {
	std::unique_lock<std::mutex> lock(this->mutex);
	while (this->cola.empty()) {
		this->cv.wait(lock);
	}
	std::unique_ptr<T> elem = std::move(this->cola.front());
	this->cola.pop();
	return elem;
}

template<class T>
void ColaBloqueante<T>::push(T* elem) {
	std::unique_lock<std::mutex> lock(this->mutex);
	this->cola.emplace(elem);
	this->cv.notify_all();
}
template class ColaBloqueante<ComandoAEnviar>;
