#ifndef COLA_NO_BLOQUEANTE_H
#define COLA_NO_BLOQUEANTE_H

#include <queue>
#include <memory>
#include <mutex>
#include <iostream>

template<typename T>
class ColaNoBloqueante {
	std::queue<std::unique_ptr<T>> cola;
	std::mutex mutex;

public:
	ColaNoBloqueante<T>() = default;

	std::unique_ptr<T> pop() {
		std::unique_lock<std::mutex> lock(this->mutex);
		if (this->cola.empty())
			return NULL;
		std::unique_ptr<T> elem = std::move(this->cola.front());
		this->cola.pop();
		return elem;
	}
	std::queue<std::unique_ptr<T>> popAll() {
		std::unique_lock<std::mutex> lock(this->mutex);
		std::queue<std::unique_ptr<T>> cola_copia = std::move(this->cola);
		this->cola = std::queue<std::unique_ptr<T>>();
		return cola_copia;
	}

	void push(T* elem) {
		std::unique_lock<std::mutex> lock(this->mutex);
		this->cola.emplace(elem);
	}

	~ColaNoBloqueante<T>() = default;

	ColaNoBloqueante<T>& operator=(const ColaNoBloqueante<T>&) = delete;
	ColaNoBloqueante<T>(const ColaNoBloqueante<T>&) = delete;

	ColaNoBloqueante<T>& operator=(ColaNoBloqueante<T>&& otra) {
		if (this == &otra)
			return *this;
		this->cola = std::move(otra.cola);
		return *this;
	}

	ColaNoBloqueante<T>(ColaNoBloqueante<T>&& otra) : cola(std::move(otra.cola)) {}

};

#endif
