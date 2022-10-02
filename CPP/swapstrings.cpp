#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char strOne[50], strTwo[50], strTmp[50];
    int i=0;
    cout<<"Enter the First String: ";
    gets(strOne);
    cout<<"Enter the Second String: ";
    gets(strTwo);
    cout<<"\nString before Swap:\n";
    cout<<"First String = "<<strOne<<"\tSecond String = "<<strTwo;
    while(strOne[i]!='\0')
    {
        strTmp[i] = strOne[i];
        i++;
    }
    strTmp[i] = '\0';
    i=0;
    while(strTwo[i]!='\0')
    {
        strOne[i] = strTwo[i];
        i++;
    }
    strOne[i] = '\0';
    i=0;
    while(strTmp[i]!='\0')
    {
        strTwo[i] = strTmp[i];
        i++;
    }
    strTwo[i] = '\0';
    cout<<"\n\nString after Swap:\n";
    cout<<"First String = "<<strOne<<"\tSecond String = "<<strTwo;
    cout<<endl;
    return 0;
}
