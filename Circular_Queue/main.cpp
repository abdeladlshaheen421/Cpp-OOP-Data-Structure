#include <iostream>

using namespace std;
class CircularQueue{
    int rear;
    int front;
    int* arr;
    int size;
public:
    CircularQueue(int s=5)
    {
       front = rear = -1;
       size = s;
       arr = new int[s];
    }

    void enQueue(int value)
    {
        if ((front == 0 && rear == size-1))
        {
            cout<<"\nQueue is Full\n";

        }
        //first element
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = value;
        }

        else if (rear == size-1)
        {
            rear = 0;
            arr[rear] = value;
        }

        else
        {
            rear++;
            arr[rear] = value;
        }
    }
    int deQueue()
    {
        if (front == -1 &&rear==-1)
    {
        cout<<"\nQueue is Empty\n";
        return 0;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    return data;
    }
    ~CircularQueue()
    {
        delete[] arr;
    }
};
int main()
{

    CircularQueue s;
    s.deQueue();
    s.enQueue(10);
    s.enQueue(20);
    s.enQueue(60);
    s.enQueue(80);
    s.enQueue(70);
    s.enQueue(100);
    cout<<s.deQueue()<<endl;
    s.enQueue(50);
    cout<<s.deQueue()<<endl;
    return 0;
}
