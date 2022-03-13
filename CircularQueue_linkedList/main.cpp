#include <iostream>

using namespace std;
struct Node{
int id;
Node* next;
};
class Queue{
Node* head;
Node* tail;
public:
    Queue()
    {
        head=tail=NULL;
    }
    void enQueue(int value)
    {
        Node* temp=new Node;
        temp->id=value;
        temp->next=NULL;
        if(head==NULL)
            head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    int deQueue()
    {
        if(head==NULL)
        {
            cout<<"this queue is empty";
            return NULL;
        }
        int id=head->id;
        Node* temp=head->next;
        delete[] head;
        head=temp;
        if(head==NULL)
            tail==NULL;
        return id;
    }
};
int main()
{
    Queue circq;
    circq.enQueue(10);
    circq.enQueue(20);
    circq.enQueue(30);

    cout<<circq.deQueue()<<endl;
    cout<<circq.deQueue()<<endl;
    cout<<circq.deQueue()<<endl;
    circq.enQueue(40);
    cout<<circq.deQueue()<<endl;
    cout<<circq.deQueue()<<endl;
    return 0;
}
