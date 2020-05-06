#include <cassert>
 
struct SYM
{
	char ch;
	int prior;
	SYM* next;
};

template<typename T>
class TPQueue
{
public:
	TPQueue() :head(nullptr), tail(nullptr) {}
	~TPQueue();
	void push(const T&);
	T pop();
	void print() const;
	T* create(const T&);
private:
	T* head;
	T* tail;
};

template<typename T>
typename T* TPQueue<T>::create(const T& data)
{
	T* item = new T;
	item->ch = data.ch;
	item->prior = data.prior;
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
	if (tail && head)
	{
		T* temp = head;
		while (temp)
		{
			if (data.prior > temp->prior)
			{
				bool flag = 0;

				T* newNode = new T{0,0,nullptr};
				newNode->ch = temp->ch;
				newNode->prior = temp->prior;
				newNode->next = temp->next;


				if (head == temp)
					flag = 1;
				if (tail == temp)
					flag = 2;

				temp->ch=data.ch;
				temp->prior = data.prior;
				temp->next = newNode;

				if (flag == 1)
					head = temp;
				if (flag == 2)
					tail = temp;
				return;
			}
			temp = temp->next;
		}
		tail->next = create(data);
		tail = tail->next;
	}
	else
	{
		head = create(data);
		tail = head;
	}
}

template<typename T>
T TPQueue<T>::pop()
{
	if (head)
	{
		T* temp = head->next;
		T data{head->ch,head->prior,nullptr};
		delete head;
		head = temp;
		return data;
	}
	else
	{
		return T{0,0,nullptr};
	}
}

template<typename T>
void TPQueue<T>::print() const
{
	T* temp = head;
	while (temp)
	{
		std::cout << temp->ch << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
