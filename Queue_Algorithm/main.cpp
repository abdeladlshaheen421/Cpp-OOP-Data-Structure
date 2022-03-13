#include <iostream>

using namespace std;
class Queue{
    int* arr;
    int Size;
    int rear;
public:
    Queue(int _size=5)
    {
        rear=-1;
        Size=_size;
        arr=new int[Size];
    }
    Queue(const Queue& que)
    {
        Size=que.Size;
        rear=que.rear;
        arr=new int[Size];
        for(int i=0;i<=rear;i++)
        {
            arr[i]=que.arr[i];
        }
    }
    int IsFull()
    {
        return rear==Size-1;
    }
    int IsEmpty()
    {
        return rear==-1;
    }
    void EnQueue(int value)
    {
        if(rear<Size-1)
            arr[++rear]=value;
        else
            cout<<"\n queue is Full \n";

    }
    int DeQueue()
    {
        if(!IsEmpty())
        {
            int value=arr[0];
            for(int i=0;i<rear;i++)
            {
                arr[i]=arr[i+1];
            }
            rear--;
            return value;
        }
        else
            cout<<"\nThis Queue is Empty \n";

    }

    ~Queue()
    {
        delete[] arr;
    }

};
int main()
{
    Queue que;
    que.IsEmpty()?cout<<"\nempty\n":cout<<"\nNot Empty\n";//Empty
    que.IsFull()?cout<<"\nFull\n":cout<<"\nNot Full\n";//Not full
    que.EnQueue(10);//10
    que.EnQueue(40);//40
    que.EnQueue(50);//50
    que.EnQueue(20);//20
    que.EnQueue(30);//30
    que.EnQueue(70);//queue is full
    que.IsEmpty()?cout<<"\nempty\n":cout<<"\nNot Empty\n";//Not Empty
    que.IsFull()?cout<<"\nFull\n":cout<<"\nNot Full\n";//Full
    if(!que.IsEmpty())
        cout<<que.DeQueue()<<endl;
    if(!que.IsEmpty())
        cout<<que.DeQueue()<<endl;
    if(!que.IsEmpty())
        cout<<que.DeQueue()<<endl;
    if(!que.IsEmpty())
        cout<<que.DeQueue()<<endl;
    if(!que.IsEmpty())
        cout<<que.DeQueue()<<endl;
    if(!que.IsEmpty())
        que.DeQueue();
    return 0;
}
