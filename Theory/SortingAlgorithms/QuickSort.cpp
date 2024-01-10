#include <iostream>
using namespace std;

// low = first index
// high = last index

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            for (int i = 0; i < 6; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    swap(arr[i + 1], arr[high]);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    cout << low << " " << high << endl;
    if (low < high)
    {
        int pi = partition(arr, low, high);
        cout << pi << endl;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {-4, 6, 2, 5, 1, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted Array\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}