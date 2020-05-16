template<typename T>
class TPQueue
{
  // Сюда помещается описание структуры "Очередь с приоритетами"
   struct ITEM
  // Сюда помещается описание структуры "Очередь с приоритетами"	
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
    ITEM* u;
    ITEM* tail;
};

@@ -28,61 +32,76 @@ typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& data)
    ITEM* item = new ITEM;
    item->data = data;
    item->next = nullptr;
    item->pred = nullptr;
	
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
void TPQueue<T>::push(const T& inf)
{
    if (head == nullptr)
    {
        head = create(dat);
        head = create(inf);
        u = head;
        tail = head;
    }
    else if (tail->data.prior >= dat.prior)
    else if (tail->data.prior >= inf.prior)
    {
        if (tail->data.ch == dat.ch)
            tail->data = dat;

        if (tail->data.prior == inf.prior && tail->data.ch == inf.ch)
        {
            tail->data = inf;
        }
        else
        {
            tail->next = create(dat);
            tail->next->pred = tail;
            tail = tail->next;
            if (tail->data.prior >= inf.prior && tail->data.ch != inf.ch)
            {
                tail->next = create(inf);
                tail = tail->next;
            }
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
        if (tail->data.prior < inf.prior)
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
            if (inf.prior > head->data.prior)
            {
                ITEM* tmp = NULL;
                tmp = create(inf);
                tmp->next = head;
                head = tmp;
            }
            else

                if (inf.prior == head->data.prior)

                    if (inf.ch == head->data.ch)
                        head->data = inf;
                    else
                    {
                        ITEM* u = nullptr;
                        u = create(inf);
                        u->next = head->next;
                        head->next = u;
                    }

                else
                {
                    if (inf.prior < head->data.prior)
                    {
                        ITEM* u = nullptr;
                        u = create(inf);
                        u->next = head->next;
                        head->next = u;
                    }
                }
        }
    }
}
@@ -96,25 +115,30 @@ T TPQueue<T>::pop()
        T data = head->data;
        delete head;
        head = temp;

        return data;
    }
}

template<typename T>
void TPQueue<T>::print() const
void TPQueue<T>::print() const	
{
    ITEM* temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
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
    std::cout << std::endl;
}

struct SYM
{
	char ch;
	int  prior;
}; 
	SYM* next;
};
