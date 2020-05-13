#include <cassert>

template<typename T>
class TPQueue
{
	struct ITEM
	{
		T data;
		ITEM* next;
	};
public:
	TPQueue() :head(nullptr), tail(nullptr) {}
	~TPQueue();
	void push(const T&);
	T pop();
	void print() const;
private:
	TPQueue::ITEM* create(const T&);
	ITEM* head;
	ITEM* tail;
};

template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& _data)
{
	ITEM* item = new ITEM;
	item->data = _data;
	item->next = nullptr;
	return item;
}

template<typename T>
TPQueue<T>::~TPQueue()
{
	while (head)
		pop();
}

template<typename T>
void TPQueue<T>::push(const T& _data)
{
	if (tail && head)
	{
		ITEM* temp = head;
		while (temp)
		{
			if (temp->data.prior < _data.prior)
			{
				ITEM* item = new ITEM;
				item->data = temp->data;
				item->next = temp->next;
				temp->data = _data;
				temp->next = item;
				return;
			}
			temp = temp->next;
		}	
		tail->next = create(_data);
		tail = tail->next;
	}
	else
	{
		head = create(_data);
		tail = head;
	}
}

template<typename T>
T TPQueue<T>::pop()
{
	if (head)
	{
		ITEM* temp = head->next;
		T data = head->data;
		delete head;
		head = temp;
		return data;
	}
	else
	{
		return T{0};
	}
}

template<typename T>
void TPQueue<T>::print() const
{
	ITEM* temp = head;
	while (temp)
	{
		std::cout << temp->data.prior << " "<<temp->data.ch;
		temp = temp->next;
	}
	std::cout << std::endl;
}

struct SYM
{
	char ch;
	int  prior;
};
