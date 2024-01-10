#include <iostream>
using namespace std;

void    heapify(int arr[], int N, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // if left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
    
    // if right child is larger than largest
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // if largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }    
}

// Main function to do heap sort
void    heapSort(int arr[], int N)
{
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // One by one extract element from heap
    for (int i = N - 1; i > 0; i--)
    {
        // Move current root to end;
        swap (arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 9, 42};
    int N = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, N);

    cout << "Sorted array: \n";
    printArray(arr, N);
}