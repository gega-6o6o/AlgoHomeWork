#include <iostream>
#include <string>
#include <cstdint>
#include <cmath>

using namespace std;

uint64_t real_string_hash(const string& s, uint64_t p, uint64_t n)
{
    uint64_t hash = 0;
    uint64_t power = 1;
    
    for (size_t i = 0; i < s.size(); ++i)
    {
        hash = (hash + static_cast<uint64_t>(s[i]) * power) % n;
        power = (power * p) % n;
    }
    
    return hash;
}

int main()
{
    uint64_t p, n;
    
    cout << "Введите p: ";
    cin >> p;
    cout << "Введите n: ";
    cin >> n;
    
    cin.ignore();
    
    string input;
    
    do
    {
        cout << "Введите строку: ";
        getline(cin, input);
        
        if (input != "exit")
        {
            uint64_t hash = real_string_hash(input, p, n);
            cout << "Хэш строки " << input << " = " << hash << endl;
        }
    } while (input != "exit");
    
    uint64_t exit_hash = real_string_hash("exit", p, n);
    cout << "Хэш строки exit = " << exit_hash << endl;
    
    return 0;
}
