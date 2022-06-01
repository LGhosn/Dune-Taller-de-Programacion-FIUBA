#ifndef COLA_NO_BLOQUEANTE_H
#define COLA_NO_BLOQUEANTE_H

#include <queue>
#include <mutex>

template<class T>
class ColaNoBloqueante {
	std::queue<T> cola;
	std::mutex mutex;

public:
	ColaNoBloqueante() = default;

	T pop();

	void push(T& elem);
};

#endif
