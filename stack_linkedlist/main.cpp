#include <iostream>
#include <string.h>
/*#include <bits/stdc++.h>*/
using namespace std;
struct Node{
int id;
Node* previousnode;
};
class Stack{
    Node* tail;
public:
    Stack()
    {
        tail=NULL;
    }
    void push(int value)
    {
        Node* temp=new Node;
        temp->id=value;
        temp->previousnode=NULL;
        if(tail==NULL)
        {
            tail=temp;
        }
        else{
            temp->previousnode=tail;
            tail=temp;
        }
    }
    int isEmpty(){
        if(tail==NULL)
            return 1;
        else
            return 0;
    }
    int top()
    {
        return tail->id;
    }
    int pop()
    {
        if(tail==NULL){
            cout<<"\nstack is Empty\n";
            return NULL;
        }
        int deletedData=tail->id;
        Node* lastNode=tail;
        tail=tail->previousnode;
        delete[] lastNode;
        return deletedData;
    }
};
struct charNode{
char id;
charNode* previousnode;
};
class charStack{
    charNode* tail;
public:
    charStack()
    {
        tail=NULL;
    }
    void push(char value)
    {
        charNode* temp=new charNode;
        temp->id=value;
        temp->previousnode=NULL;
        if(tail==NULL)
        {
            tail=temp;
        }
        else{
            temp->previousnode=tail;
            tail=temp;
        }
    }
    int isEmpty(){
        if(tail==NULL)
            return 1;
        else
            return 0;
    }
    char top()
    {
        return tail->id;
    }
    char pop()
    {
        if(tail==NULL){
            cout<<"\nstack is Empty\n";
            return NULL;
        }
        char deletedData=tail->id;
        charNode* lastNode=tail;
        tail=tail->previousnode;
        delete[] lastNode;
        return deletedData;
    }
};

int precedence(char operation)
{
    if(operation=='+'||operation=='-')
        return 1;
    else if(operation=='*'||operation=='/')
        return 2;
    return 0;
}
int operationResult(int number1,int number2, char operation)
{
    switch(operation)
    {
        case '+': return number1+number2;
        case '-': return number1-number2;
        case '*': return number1*number2;
        case '/': return number1/number2;
    }
}
int finalResult(char equation[])
{
    charStack stOfOperations;
    Stack stOfNumbers;
    for(int i=0;i<strlen(equation);i++)
    {
        //cout<<stOfOperations.top()<<"    "<<stOfNumbers.top()<<endl;
        //to ignore space
        //cout<<i;
        if(equation[i]==' ')
            continue;
        else if(equation[i]=='('){
                    stOfOperations.push(equation[i]);
                }
        else if(isdigit(equation[i])){
        int value=0;
        //to check the next is number or not
        while(i< strlen(equation)&&isdigit(equation[i])){
            value= (value*10) + (equation[i]-'0');//parsing with '0'
            i++;//at end he stop when char
        }
        stOfNumbers.push(value);
        i--;//then to return to char not to ignore

        }
        else if(equation[i]==')')
        {

                while(!stOfOperations.isEmpty()&&stOfOperations.top()!='(')
                {
                    int number2=stOfNumbers.top();
                    stOfNumbers.pop();
                    int number1=stOfNumbers.top();
                    stOfNumbers.pop();
                    char operand=stOfOperations.top();
                    stOfOperations.pop();
                    stOfNumbers.push(operationResult(number1,number2,operand));
                }
                if(!stOfOperations.isEmpty())
                    stOfOperations.pop();
        }
        else{

            while(!stOfOperations.isEmpty()&&precedence(stOfOperations.top())>=precedence(equation[i]))
            {
                    int number2=stOfNumbers.top();
                    stOfNumbers.pop();
                    int number1=stOfNumbers.top();
                    stOfNumbers.pop();
                    char operand=stOfOperations.top();
                    stOfOperations.pop();
                    stOfNumbers.push(operationResult(number1,number2,operand));
            }
            stOfOperations.push(equation[i]);
        }

    }
    while(!stOfOperations.isEmpty())
    {
                    int number2=stOfNumbers.top();
                    stOfNumbers.pop();
                    int number1=stOfNumbers.top();
                    stOfNumbers.pop();
                    char operand=stOfOperations.top();
                    stOfOperations.pop();
                    stOfNumbers.push(operationResult(number1,number2,operand));
    }
    return stOfNumbers.top();
}
int main()
{
    //cout<<finalResult(" 100 * 2 + 12 / (4 + 22) * 10 - 40");
    cout<<finalResult(" 100 +2*(12/3)+(8*5)-100+(100/10-80+20*2)");
    cout<<endl<<100 +2*(12/3)+(8*5)-100+(100/10-80+20*2)<<endl;
    return 0;
}
