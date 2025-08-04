#include <iostream>
#include <vector>

using namespace std;

void count_sort(int* arr, int size)
{
    const int MIN_VAL = 10;
    const int MAX_VAL = 24;
    const int RANGE = MAX_VAL - MIN_VAL + 1;
    
    vector<int> count(RANGE, 0);
    
    for (int i = 0; i < size; ++i)
    {
        count[arr[i] - MIN_VAL]++;
    }
    
    int index = 0;
    for (int val = 0; val < RANGE; ++val)
    {
        while (count[val] > 0)
        {
            arr[index++] = val + MIN_VAL;
            count[val]--;
        }
    }
}

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[] = {21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    cout << "Исходный массив: ";
    print_array(arr1, size1);
    count_sort(arr1, size1);
    cout << "Отсортированный массив: ";
    print_array(arr1, size1);
    cout << endl;

    cout << "Исходный массив: ";
    print_array(arr2, size2);
    count_sort(arr2, size2);
    cout << "Отсортированный массив: ";
    print_array(arr2, size2);
    cout << endl;

    cout << "Исходный массив: ";
    print_array(arr3, size3);
    count_sort(arr3, size3);
    cout << "Отсортированный массив: ";
    print_array(arr3, size3);

    return 0;
}
