#ifndef COLA_BLOQUEANTE_H
#define COLA_BLOQUEANTE_H

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>

template<typename T>
class ColaBloqueante {
	std::queue<std::unique_ptr<T>> cola;
	std::mutex mutex;
	std::condition_variable cv;

public:
	ColaBloqueante<T>() = default;

	std::unique_ptr<T> wait_and_pop() {
		std::unique_lock<std::mutex> lock(this->mutex);
		std::cout << "Emtramdp..." << std::endl;
		while (this->cola.empty()) {
			this->cv.wait(lock);
		}
		std::cout << "Desencolando..." << std::endl;
		std::unique_ptr<T> elem = std::move(this->cola.front());
		this->cola.pop();
		return elem;
	}

	void push(T* elem) {
		std::unique_lock<std::mutex> lock(this->mutex);
		std::cout << "Pushing cola bloqueante" << std::endl;
		this->cola.emplace(elem);
		this->cv.notify_all();
	}

	~ColaBloqueante<T>() = default;
};

#endif
