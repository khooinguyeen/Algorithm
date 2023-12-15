#include <iostream>
using namespace std;

int binary_search(int s[], int key, int low, int high)
{
    int middle;

    if (low > high)
        return (-1);
    middle = (low + high) / 2;
    if (s[middle] == key)
        return (middle);
    if (s[middle] > key) 
        return (binary_search(s, key, low, middle - 1));
    else
        return (binary_search(s, key, middle + 1, high));
}

int main(void)
{
    int arr[] = {1, 3, 2, -4, 42, 5, 6, 7, 1};
    cout << binary_search(arr, 42, 0, 9) << endl;
}