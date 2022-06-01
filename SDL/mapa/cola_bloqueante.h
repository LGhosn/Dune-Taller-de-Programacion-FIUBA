#ifndef COLA_BLOQUEANTE_H
#define COLA_BLOQUEANTE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template<class T>
class ColaBloqueante{
	std::queue<T> cola;
	std::mutex mutex;
	std::condition_variable cv;

public:
	ColaBloqueante();

	T wait_and_pop();

	void push(T& elem);
};

#endif
