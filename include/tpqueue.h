#include <cassert>
 
template<typename T>
class TPQueue
{
  struct ITEM
    {
        T data;
        ITEM * next;
    };
public:
    TPQueue():head(nullptr),tail(nullptr){}
    ~TPQueue();
    void push(const T&);
    T pop();
    void print() const;
private:
    TPQueue::ITEM* create(const T&);
    ITEM *head;
    ITEM *tail;
};

template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& data)
{
   ITEM *item=new ITEM;
   item->data.ch=data.ch;
   item->data.prior=data.prior;
   item->next=nullptr;
   return item;
}

template<typename T>
TPQueue<T>::~TPQueue()
{
    while(head)
      pop();
}

template<typename T>
void TPQueue<T>::push(const T& data)
{
    if (data.prior>10 || data.prior<1) 
        return ;
        
    if(tail && head)
    {
        ITEM *step=head, *prev = head;
        
        while (step->data.prior >= data.prior) {
            if (step==tail) {
                break;
            }
            prev=step;
            step=step->next;
        }
        
        if (step==head && step->data.prior != data.prior) {
            step=create(data);
            step->next=head;
            head=step;
        }
        else if (tail->data.prior >= data.prior) {
            tail->next=create(data);
            tail=tail->next;
            return ;
        }
        else {
            ITEM *tmp=prev->next;
            step=create(data);
            prev->next=step;
            step->next=tmp;
        }
    }
    else
    {
        head=create(data);
        tail=head;
    }
}

template<typename T>
T TPQueue<T>::pop()
{
    if(head)
    {
        ITEM *temp=head->next;
        T data=head->data;
        delete head;
        head=temp;
        return data;
    }
    
}

template<typename T>
void TPQueue<T>::print() const
{
    ITEM *temp=head;
    while(temp)
    {
        std::cout<< temp->data.ch <<" "<< temp->data.prior <<std::endl;
        temp=temp->next;
    }
}

struct SYM
{
	char ch;
	int  prior;
};
