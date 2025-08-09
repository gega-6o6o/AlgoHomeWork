#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int find_substring_light_rabin_karp(string source, string substring)
{
    const int prime = 101;
    size_t substring_length = substring.length();
    size_t source_length = source.length();
    
    if (substring_length == 0 || source_length < substring_length)
    {
        return -1;
    }
    
    int substring_hash = 0;
    int window_hash = 0;
    
    for (size_t i = 0; i < substring_length; i++)
    {
        substring_hash = substring_hash * prime + substring[i];
        window_hash = window_hash * prime + source[i];
    }
    
    if (window_hash == substring_hash)
    {
        bool match = true;
        for (size_t i = 0; i < substring_length; i++)
        {
            if (source[i] != substring[i])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            return 0;
        }
    }
    
    int power = 1;
    for (size_t i = 0; i < substring_length - 1; i++)
    {
        power *= prime;
    }
    
    for (size_t i = substring_length; i < source_length; i++)
    {
        window_hash = (window_hash - source[i - substring_length] * power) * prime + source[i];
        
        if (window_hash == substring_hash)
        {
            bool match = true;
            for (size_t j = 0; j < substring_length; j++)
            {
                if (source[i - substring_length + 1 + j] != substring[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return static_cast<int>(i - substring_length + 1);
            }
        }
    }
    
    return -1;
}

int main()
{
    string source, substring;
    
    cout << "Введите строку, в которой будет осуществляться поиск: ";
    getline(cin, source);
    
    while (true)
    {
        cout << "Введите подстроку, которую нужно найти: ";
        getline(cin, substring);
        
        if (substring == "exit")
        {
            break;
        }
        
        int index = find_substring_light_rabin_karp(source, substring);
        if (index != -1)
        {
            cout << "Подстрока " << substring << " найдена по индексу " << index << endl;
        }
        else
        {
            cout << "Подстрока " << substring << " не найдена" << endl;
        }
    }
    
    int index = find_substring_light_rabin_karp(source, "exit");
    if (index != -1)
    {
        cout << "Подстрока exit найдена по индексу " << index << endl;
    }
    else
    {
        cout << "Подстрока exit не найдена" << endl;
    }
    
    return 0;
}
