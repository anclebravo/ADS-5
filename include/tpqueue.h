#pragma once

struct SYM
{
    char ch;
    int  prior;
};

template<typename T>
class TPQueue
{
    struct ITEM
    {
        T data;
        ITEM* next;
        ITEM* pred;
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
void TPQueue<T>::push(const T& dat)
{
    if (head == nullptr)
    {
        head = create(dat);
        tail = head;
    }
    else if (tail->data.prior >= dat.prior)
    {
        if (tail->data.ch == dat.ch)
            tail->data = dat;
        else
        {
            tail->next = create(dat);
            tail->next->pred = tail;
            tail = tail->next;
        }
    }
    else if (head == tail)
    {
        tail->pred = create(dat);
        head = tail->pred;
        head->next = tail;
    }
    else
    {
        ITEM* tmp = tail;
        while (tmp != head && tmp->data.prior < dat.prior)
        {
            tmp = tmp->pred;
        }
        if (tmp->data.prior == dat.prior)
        {
            ITEM* cell = new ITEM;
            cell->next = tmp->next;
            cell->pred = tmp;
            cell->data = dat;
            tmp->next->pred = cell;
            tmp->next = cell;
        }
        if (tmp == head && tmp->data.prior < dat.prior)
        {
            head->pred = create(dat);
            head = head->pred;
            head->next = tmp;
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
    else
    {
        return SYM{'\0', 0};
    }
}

template<typename T>
void TPQueue<T>::print() const
{
    ITEM* temp = head;
    while (temp)
    {
        std::cout << temp->data.ch << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

