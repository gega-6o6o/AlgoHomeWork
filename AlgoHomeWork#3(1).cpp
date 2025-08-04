#include <iostream>
#include <vector>

using namespace std;

void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        } else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_helper(int* arr, int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort_helper(arr, left, mid);
    merge_sort_helper(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void merge_sort(int* arr, int size)
{
    merge_sort_helper(arr, 0, size - 1);
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
    merge_sort(arr1, size1);
    cout << "Отсортированный массив: ";
    print_array(arr1, size1);
    cout << endl;

    cout << "Исходный массив: ";
    print_array(arr2, size2);
    merge_sort(arr2, size2);
    cout << "Отсортированный массив: ";
    print_array(arr2, size2);
    cout << endl;

    cout << "Исходный массив: ";
    print_array(arr3, size3);
    merge_sort(arr3, size3);
    cout << "Отсортированный массив: ";
    print_array(arr3, size3);

    return 0;
}
