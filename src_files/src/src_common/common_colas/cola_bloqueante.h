#ifndef COLA_BLOQUEANTE_H
#define COLA_BLOQUEANTE_H

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>

template<typename T>
class ColaBloqueante {
	std::queue<std::unique_ptr<T>> cola;
	std::mutex mutex;
	std::condition_variable cv;

public:
	ColaBloqueante();

	std::unique_ptr<T> wait_and_pop();

	void push(T* elem);
};

#endif
