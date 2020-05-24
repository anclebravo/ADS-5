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

	TPQueue(): head(nullptr), tail(nullptr) {}
	~TPQueue();
	void push(const T&);
	T pop();
	void print() const;

private:
	TPQueue::ITEM* create(const T&);
	ITEM* head;
	ITEM* tail;
	ITEM* a;
};

template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& data)
{
	ITEM* item = new ITEM;
	item->data = data;
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
void TPQueue<T>::push(const T& data)
{
	if (head == nullptr)
	{
		head = create(data);
		a = head;
		tail = head;
	}
	else if (tail->data.prior >= data.prior)
	{
		if (tail->data.prior == data.prior && tail->data.ch == data.ch)
		{
			tail->data = data;

		}

		else
		{
			if (tail->data.prior >= data.prior && tail->data.ch != data.ch)
			{
				tail->next = create(data);
				tail = tail->next;
			}
		}
	}

	else
	{

		if (tail->data.prior < data.prior)
		{
			if (data.prior > head->data.prior)
			{
				ITEM* temp = nullptr;
				temp = create(data);
				temp->next = head;
				head = temp;
			}

			else

				if (data.prior == head->data.prior)

					if (data.ch == head->data.ch)
						head->data = data;
					else
					{
						ITEM* b = nullptr;
						b = create(data);
						b->next = head->next;
						head->next = b;

					}

				else
				{
					if (data.prior < head->data.prior)
					{
						ITEM* b = nullptr;
						b = create(data);
						b->next = head->next;
						head->next = b;
					}
				}

		}
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

}

template<typename T>
void TPQueue<T>::print() const
{
	ITEM* temp = head;
	while (temp)
	{
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
	}
	std::cout << std::endl;	   
}

struct SYM
{
	char ch;
	int  prior;
};
