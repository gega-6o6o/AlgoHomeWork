#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int>& memo)
{
    if (n <= 1)
    {
        return n;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main()
{
    int n;
    cout << "Введите номер числа Фибоначчи: ";
    cin >> n;
    
    vector<int> memo(n + 1, -1);
    
    cout << "F(" << n << ") = " << fibonacci(n, memo) << endl;
    return 0;
}
