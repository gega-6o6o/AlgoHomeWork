#include <iostream>
using namespace std;

int countGreater(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return size - left;
}

int main() {
    int arr[] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target;
    cout << "Введите точку отсчёта: ";
    cin >> target;
    
    int count = countGreater(arr, size, target);
    cout << "Количество элементов в массиве больших, чем " << target << ": " << count << endl;
    
    return 0;
}
