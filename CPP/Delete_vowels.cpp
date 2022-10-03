//Program to delete all the vowels from a given string and print the resulting string 

#include<iostream>
using namespace std;

int main()
{
        string str;
        cout<<"\n Enter String : ";
        cin>>str;

        for(int i=0; i<str.length(); i++)
        {
                if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I'
|| str[i]=='O' || str[i]=='U')
                {
                        str[i]=' ';
                }
        }
        cout<<"\n String After Deleting Vowels : "<<str;
        cout<<"\n Time complexity: O(n)";
        return 0;
}
