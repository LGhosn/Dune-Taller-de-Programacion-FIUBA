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
		std::cout << "Push" << std::endl;
		this->cola.emplace(elem);
	}

	~ColaNoBloqueante<T>() = default;
};

#endif
