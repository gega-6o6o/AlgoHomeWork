#include <iostream>
#include <algorithm>

using namespace std;

int median_of_three(int* arr, int low, int high)
{
    int mid = low + (high - low) / 2;
    
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    
    return mid;
}

int partition(int* arr, int low, int high)
{
    int pivot_index = median_of_three(arr, low, high);
    swap(arr[pivot_index], arr[high]);
    
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort_helper(int* arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quick_sort_helper(arr, low, pi - 1);
        quick_sort_helper(arr, pi + 1, high);
    }
}

void quick_sort(int* arr, int size)
{
    quick_sort_helper(arr, 0, size - 1);
}

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "Исходный массив: ";
    print_array(arr1, size1);
    quick_sort(arr1, size1);
    cout << "Отсортированный массив: ";
    print_array(arr1, size1);
    cout << endl;

    cout << "Исходный массив: ";
    print_array(arr2, size2);
    quick_sort(arr2, size2);
    cout << "Отсортированный массив: ";
    print_array(arr2, size2);
    cout << endl;

    cout << "Исходный массив: ";
    print_array(arr3, size3);
    quick_sort(arr3, size3);
    cout << "Отсортированный массив: ";
    print_array(arr3, size3);

    return 0;
}
