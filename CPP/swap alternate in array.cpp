#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void alternate(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
            swap(arr[i], arr[i + 1]);
    }
}

int main()
{
    int arr[5] = {1, 3, 5, 2, 5};
    int arr2[6] = {1, 3, 5, 2, 5, 7};
    alternate(arr, 5);
    alternate(arr2, 6);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " " << endl;
    }
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << arr2[i] << " " << endl;
    }

    return 0;
}
