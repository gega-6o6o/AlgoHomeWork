#include <iostream>
#include <string>

using namespace std;

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    cout << "Динамический массив: ";
    for (int i = 0; i < actual_size; ++i)
    {
        if (i < logical_size)
        {
            cout << arr[i];
        }
        else
        {
            cout << "_";
        }
        if (i != actual_size - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size)
{
    if (logical_size <= 0)
    {
        return arr;
    }

    logical_size--;

    if (logical_size <= actual_size / 3 && actual_size / 3 > 0)
    {
        int new_actual_size = actual_size / 3;
        int* new_arr = new int[new_actual_size];

        for (int i = 0; i < logical_size; ++i)
        {
            new_arr[i] = arr[i + 1];
        }

        actual_size = new_actual_size;
        delete[] arr;
        return new_arr;
    }
    else
    {
        for (int i = 0; i < logical_size; ++i)
        {
            arr[i] = arr[i + 1];
        }
        return arr;
    }
}

int main()
{
    int actual_size, logical_size;
    
    cout << "Введите фактический размер массива: ";
    cin >> actual_size;
    cout << "Введите логический размер массива: ";
    cin >> logical_size;
    
    if (logical_size > actual_size)
    {
        cout << "Ошибка! Логический размер массива не может превышать фактический!" << endl;
        return 1;
    }
    
    int* arr = new int[actual_size];
    
    for (int i = 0; i < logical_size; ++i)
    {
        cout << "Введите arr[" << i << "]: ";
        cin >> arr[i];
    }
    
    print_dynamic_array(arr, logical_size, actual_size);
    
    string answer;
    while (true)
    {
        cout << "Удалить первый элемент? (да/нет): ";
        cin >> answer;
        
        if (answer == "нет")
        {
            cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        else if (answer == "да")
        {
            if (logical_size == 0)
            {
                cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << endl;
                break;
            }
            
            arr = remove_dynamic_array_head(arr, logical_size, actual_size);
            print_dynamic_array(arr, logical_size, actual_size);
        }
        else
        {
            cout << "Пожалуйста, введите 'да' или 'нет'." << endl;
        }
    }
    
    delete[] arr;
    
    return 0;
}
