#include <iostream>
#include <string>

using namespace std;

int simple_string_hash(const string& s)
{
    int hash = 0;
    for (char c : s)
    {
        hash += static_cast<int>(c);
    }
    return hash;
}

int main()
{
    string input;
    
    do
    {
        cout << "Введите строку: ";
        getline(cin, input);
        
        if (input != "exit")
        {
            int hash = simple_string_hash(input);
            cout << "Наивный хэш строки " << input << " = " << hash << endl;
        }
    } while (input != "exit");
    
    int exit_hash = simple_string_hash("exit");
    cout << "Наивный хэш строки exit = " << exit_hash << endl;
    
    return 0;
}
