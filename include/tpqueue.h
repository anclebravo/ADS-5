#include <cassert>
#include <stdio.h>
#include <iostream>
template<typename T>
class TPQueue
{
	struct INFO
	{
		T data;
		INFO* next;
	};
public:
	TPQueue() :head(nullptr), cur(nullptr) {}
	~TPQueue();
	void push(const T&);
	T pop();
	void print() const;
private:
	TPQueue::INFO* create(const T&);
	INFO* head;
	INFO* tmp;
	INFO* cur;
};

template<typename T>
typename TPQueue<T>::INFO* TPQueue<T>::create(const T& data)
{
	INFO* info = new INFO;
	info->data = data;
	info->next = nullptr;
	return info;
}	

template<typename T>
TPQueue<T>::~TPQueue()
{
	while (head)
		pop();
}

template<typename T>
void TPQueue<T>::push(const T& inf)
{
	if (head == nullptr)
	{
		head = create(inf);
		cur = head;
	}
	else if (cur->data.prior == inf.prior)
	{
		while (cur->next != nullptr && cur->next->data.prior == inf.prior)
			cur = cur->next;
		tmp = new INFO;
		tmp->data = inf;
		tmp->next = cur->next;
		cur->next = tmp;
	}
	else if (cur->data.prior < inf.prior)
	{
		tmp = create(inf);
		tmp->next = head;
		head = tmp;
	}
	else if (cur->data.prior > inf.prior)
	{
		while (cur->next != nullptr && cur->next->data.prior > inf.prior)
			cur = cur->next;
		tmp = new INFO;
		tmp->next = cur->next;
		cur->next = tmp;
	}
}

template<typename T>
T TPQueue<T>::pop()
{
	if (head)
	{
		INFO* temp = head->next;
		T data = head->data;
		delete head;
		head = temp;
		return data;
	}
}


struct SYM
{
	char ch;
	int  prior;
};
