#include <iostream>
#include <string.h>
using namespace std;
int binarySearch(int* arr,int Size,int key)
{
    int start = 0 , endp = Size-1 , middle ;
    while(start<=endp)
    {
        middle=(start+endp) / 2;
        if(key>arr[middle])
            start=middle+1;
        else if(key<arr[middle])
            endp=middle-1;
        else if(key==arr[middle])
            return middle;
    }
    return -1;
}
void Swap(int* x ,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int recursionbinarySearch(int* arr,int Size,int start,int endp,int key)
{
    if(start>endp)
        return -1;
    else{
        int middle=(start+endp)/2;
        if(arr[middle]==key)
            return middle;
        else if(arr[middle]<key)
            recursionbinarySearch(arr,Size,middle+1,endp,key);
        else if(arr[middle]>key)
            recursionbinarySearch(arr,Size,start,middle-1,key);
    }
}
void bubbleSort(int* arr , int Size)
{
    for(int i=0;i<Size-1;i++)
    {
        for(int j=0;j<Size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                Swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void selectionSort(int* arr, int Size)
{
    int MinValue;
    for(int i=0;i<Size-1;i++)
    {
        MinValue=i;
        for(int j=i+1;j<Size;j++)
        {
            if(arr[j]<arr[MinValue]){
                MinValue=j;
            }
        }
            Swap(&arr[i],&arr[MinValue]);
    }
}
void selectionSortString(char arr[][10], int Size)
{
    char MinValue[10];
    for(int i=0;i<Size-1;i++)
    {
        int minindex=i;
        strcpy(MinValue,arr[i]);

        for(int j=i+1;j<Size;j++)
        {
            if(strcmp(MinValue,arr[j])>0){
                strcpy(MinValue,arr[j]);
                minindex=j;
            }
        }
        if(minindex!=i){
            char temp[10];
            strcpy(temp,arr[i]);
            strcpy(arr[i],arr[minindex]);
            strcpy(arr[minindex],temp);

        }
    }
}
int main()
{
    int arrayoFint[5]={10,20,30,40,50};
    binarySearch(arrayoFint,5,40)>=0?cout<<"element Found and index is :  "<<binarySearch(arrayoFint,5,40):cout<<"element Not Found";
    cout<<endl;
    binarySearch(arrayoFint,5,0)>=0?cout<<"element Found and index is :  "<<binarySearch(arrayoFint,5,0):cout<<"element Not Found";
    cout<<"\n--------------------------------------------------------------------\n";

    int arrayoFint2[5]={1,2,3,4,5};
    recursionbinarySearch(arrayoFint2,5,0,4,2)>=0?cout<<"element Found and index is :  "<<recursionbinarySearch(arrayoFint2,5,0,4,2):cout<<"element Not Found";
    cout<<endl;
    recursionbinarySearch(arrayoFint2,5,0,4,0)>=0?cout<<"element Found and index is :  "<<recursionbinarySearch(arrayoFint2,5,0,4,0):cout<<"element Not Found";
    cout<<"\n--------------------------------------------------------------------\n";

    int unsortedarr[5]={25,15,10,1,5};
    bubbleSort(unsortedarr,5);
    for(int i=0;i<5;i++)
    {
        cout<<unsortedarr[i]<<" ";
    }

    cout<<"\n--------------------------------------------------------------------\n";

    int unsortedarr2[5]={25,15,10,1,5};
    selectionSort(unsortedarr2,5);
    for(int i=0;i<5;i++)
    {
        cout<<unsortedarr2[i]<<" ";
    }
    cout<<"\n--------------------------------------------------------------------\n";

    char openSourceNames[5][10]={"saleh","mido","abdo","ahmed"};
    selectionSortString(openSourceNames,4);
    for(int i=0;i<5;i++)
    {
        cout<<openSourceNames[i]<<"   ";
    }
    return 0;
}
