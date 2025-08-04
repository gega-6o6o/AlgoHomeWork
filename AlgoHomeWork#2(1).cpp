#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Введите номер числа Фибоначчи: ";
    cin >> n;
    cout << "F(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
// Сложность по времени - O(2ⁿ), Сложность по памяти - O(n)
