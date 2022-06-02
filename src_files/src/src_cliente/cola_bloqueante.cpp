#include "cola_bloqueante.h"

ColaBloqueante::ColaBloqueante() {}

T ColaBloqueante::wait_and_pop() {
	std::unique_lock<std::mutex> lock(this->mutex);
	while (this->cola.empty()) {
		this->cv.wait(lock);
	}
	T elem = this->cola.front();
	this->cola.pop();
	return elem;
}

void push(T& elem) {
	std::unique_lock<std::mutex> lock(this->mutex);
	this->cola.push(elem);
	this->cv.notify_all();
}
