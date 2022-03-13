#include <iostream>
#include <string.h>
using namespace std;
struct student{
int StudentId=-1;
char StudentName[10];
public:
 void display()
{
    if(StudentId!=-1){
        cout<<"student is defined"<<endl;
        cout<<"student name : "<<StudentName<<"  and student id:  "<<StudentId<<endl;
    }
    else
    {
        cout<<"student Not Found !!!"<<endl;
    }
}
};
struct node{
    int id;
    char StudentName[10];
    node* previousNode;
    node* nextNode;
};
class LinkedList{
    node* head;
    node* tail;
    node* getaddressId(int value)
    {
        node* Element=head;
        struct student st;
        while(Element!=NULL)
        {
            if(Element->id==value)
            {
                return Element;
            }
            Element=Element->nextNode;
        }

        return NULL;
    }
    node* getaddressName(char value[])
    {
        node* Element=head;
        struct student st;
        while(Element!=NULL)
        {
            if(!strcmp(Element->StudentName,value))
            {
                return Element;
            }
            Element=Element->nextNode;
        }

        return NULL;
    }
public:
    LinkedList()
    {
        head=tail=NULL;
    }
    void append(int StudentId,char StudentName[])
    {
        node* temp=new node();
        strcpy(temp->StudentName,StudentName);
        temp->id=StudentId;
        temp->previousNode=NULL;
        temp->nextNode=NULL;

        if(head==NULL)
        {
            head=tail=temp;
        }
        else
        {
            temp->previousNode=tail;
            tail->nextNode=temp;
            tail=temp;
        }
    }
    void display()
    {
        node* Element=head;
        while(Element!=NULL)
        {
            cout<<"Student_id : "<<Element->id<<"  Student Name : "<<Element->StudentName<<endl;
            Element=Element->nextNode;
        }
    }
    int length()
    {
        node* Element=head;
        int counter=0;
        while(Element!=NULL)
        {
            Element=Element->nextNode;
            counter++;
        }
        return counter;
    }
    student searching(int value)
    {
        node* Element=getaddressId(value);
        struct student st;
        if(Element!=NULL)
        {
            st.StudentId=Element->id;
            strcpy(st.StudentName,Element->StudentName);
        }

        return st;
    }
    student searching(char value[])
    {
        node* Element=getaddressName(value);
        struct student st;
        if(Element!=NULL)
        {
            st.StudentId=Element->id;
            strcpy(st.StudentName,Element->StudentName);
        }

        return st;
    }
    void Insert(int nid,char name[],int oid){
        node* temp=getaddressId(oid);//get ele  to push after
        if(temp==NULL||temp==tail)//if not found or it's last element
            append(nid,name);
        else
        {
            node* n=new node;
            n->id=nid;
            strcpy(n->StudentName,name);

            n->previousNode=temp;
            n->nextNode=temp->nextNode;

            temp->nextNode=n;
            n->nextNode->previousNode=n;
        }
    }
    void Delete(int id)
    {
        node* temp=getaddressId(id);
        if(head==tail)//if it's only the element in linked or none
        {
            head=tail=NULL;

        }
        else if(temp==head)//if first element
        {
            head=head->nextNode;
            head->previousNode=NULL;

        }
        else if(temp==tail)//if last element
        {
            tail=tail->previousNode;
            tail->nextNode=NULL;

        }
        else
        {
            temp->previousNode->nextNode=temp->nextNode;
            temp->nextNode->previousNode=temp->previousNode;

        }
        delete temp;
    }
    void deleteall(){
        node* temp=head;
        while(temp!=NULL)
        {
            head=head->nextNode;
            delete temp;
            temp=head;
        }
        head=tail=NULL;
    }

};

int main()
{
    LinkedList linked;
    linked.append(10,"abdeladl");
    linked.append(20,"khaled");
    linked.append(30,"Som3a");
    linked.append(40,"shata");

    linked.display();

    cout<<"The Length of LinkedList is : "<<linked.length()<<endl;

    linked.searching("abdeladl").display();
    linked.searching(20).display();

    linked.Insert(70,"ahmed",10);
    //linked.deleteall();
    linked.Delete(20);
    linked.display();

    linked.searching("amosha").display();
    linked.searching(60).display();

    linked.deleteall();
    cout<<"The Length of LinkedList is : "<<linked.length()<<endl;
    return 0;
}
