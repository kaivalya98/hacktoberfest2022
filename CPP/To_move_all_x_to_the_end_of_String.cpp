#include <bits/stdc++.h>
using namespace std;
// to move all X to the end of the String using recursion.
char temp;
int index = 0;
void move_char(string str, char choosedchar, int length, int modifiedLength)
{
    // base condition no 1
    if (index == length - 1)
    {
        cout << "Modified String is :- " << str;
        index = 0;
        return;
    }

    // base condition no 2
    if (index == modifiedLength)
    {
        cout << "Modified String is :- " << str;
        index = 0;
        return;
    }

    if (str[index] == choosedchar)
    {
        if (str[modifiedLength - 1] == choosedchar)
        {
            modifiedLength--;
        }
        else
        {
            temp = str[modifiedLength - 1];
            str[modifiedLength - 1] = str[index];
            str[index] = temp;
        }
    }
    else
    {
        index++;
    }
    move_char(str, choosedchar, length, modifiedLength); // recursion is occuring !!!!!!!!!!
}
int main()
{
    string str;
    char character;
    cout << "Enter the String :- ";
    cin >> str;
    cout << "Enter the character which you want to move to the end of the String :- ";
    cin >> character;
    int length = str.length();
    move_char(str, character, length, length);
    return 0;
}