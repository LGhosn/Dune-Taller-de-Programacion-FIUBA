#ifndef COLA_NO_BLOQUEANTE_H
#define COLA_NO_BLOQUEANTE_H

#include <queue>
#include <memory>
#include <mutex>

template<typename T>
class ColaNoBloqueante {
	std::queue<std::unique_ptr<T>> cola;
	std::mutex mutex;

public:
	ColaNoBloqueante() = default;

	std::unique_ptr<T> pop();
	std::queue<std::unique_ptr<T>> popAll(); 

	void push(T* elem);
};

#endif
