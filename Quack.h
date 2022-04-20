#pragma once
#include <queue>
#include <stack>

//this could be a queue, or this could be a stack
template <typename T>
class Quack {
	std::queue<T> asQueue;
	std::stack<T> asStack;

	bool isQueue;
public:
	Quack(bool beQueue);

	void push(T toAdd);
	T pop();
	bool empty();
};

template <typename T>
Quack<T>::Quack(bool beQueue) {
	isQueue = beQueue;
}

template <typename T>
void Quack<T>::push(T toAdd) {
	if (isQueue) {
		asQueue.push(toAdd);
	}
	else {
		asStack.push(toAdd);
	}
}

template <typename T>
T Quack<T>::pop() {
	T removed;

	if (isQueue) {
		removed = asQueue.front();
		asQueue.pop();
	}
	else {
		removed = asStack.top();
		asStack.pop();
	}

	return removed;
}

template <typename T>
bool Quack<T>::empty() {
	return asQueue.empty() && asStack.empty();
}