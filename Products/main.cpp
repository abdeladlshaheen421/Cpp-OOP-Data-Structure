#include <iostream>

using namespace std;

int main()
{
    cout<<"\n\n\t\t\t\t\t**********************************\n";
    cout<<"\t\t\t\t\t*    Programming Assignment 1    *\n";
    cout<<"\t\t\t\t\t*     Computer Programming 1     *\n";
    cout<<"\t\t\t\t\t*    Author: Enter Your Name     *\n";
    cout<<"\t\t\t\t\t*  Due Date: Monday, Feb 7,2022  *\n";
    cout<<"\t\t\t\t\t**********************************\n";
    double originalPrice,markUpPercentage,salesTaxRate;

    cout<<"\n\t\t\t\t\t Enter Value of original Price :  ";
    cin>>originalPrice;

    cout<<"\n\t\t\t\t\t Enter Value of  markUp Percentage  :  ";
    cin>>markUpPercentage;
    markUpPercentage/=100;

    cout<<"\n\t\t\t\t\t Enter Value of sales  Tax :   ";
    cin>>salesTaxRate;
    salesTaxRate/=100;

    cout<<"\n\t\t\t\t\t-------------------------------------------------\n\n";
    cout<<"\t\t\t\t\tThe original price of item is :  "<<originalPrice<<endl;

    cout<<"\t\t\t\t\tThe percentage of markUp  is :  "<<markUpPercentage <<endl;


    double sellingPrice=originalPrice*(1+markUpPercentage);
    cout<<"\t\t\t\t\tThe Store selling price of item is :  "<<sellingPrice<<endl;

    cout<<"\t\t\t\t\tThe Sales tax rate :  "<<salesTaxRate<<endl;

    double salesTax=salesTaxRate*sellingPrice;
    cout<<"\t\t\t\t\tThe Sales tax  :  "<<salesTax<<endl;

    cout<<"\t\t\t\t\tThe final price of item  :  "<<sellingPrice+salesTax<<endl;
    return 0;
}
