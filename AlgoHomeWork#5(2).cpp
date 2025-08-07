#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print_pyramid(const vector<int>& arr)
{
    cout << "Пирамида:" << endl;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        int level = 0;
        size_t temp = i + 1;
        while (temp > 1)
        {
            temp >>= 1;
            level++;
        }

        string type;
        if (i == 0)
        {
            type = "root";
        }
        else
        {
            size_t parent_index = (i - 1) / 2;
            type = (i % 2 == 1) ? "left(" + to_string(arr[parent_index]) + ")"
                                : "right(" + to_string(arr[parent_index]) + ")";
        }

        cout << level << " " << type << " " << arr[i] << endl;
    }
}

bool get_parent(size_t current, size_t& parent, const vector<int>& arr)
{
    if (current == 0) return false;
    parent = (current - 1) / 2;
    return true;
}

bool get_left_child(size_t current, size_t& child, const vector<int>& arr)
{
    child = 2 * current + 1;
    return child < arr.size();
}

bool get_right_child(size_t current, size_t& child, const vector<int>& arr)
{
    child = 2 * current + 2;
    return child < arr.size();
}

void print_current_position(size_t index, const vector<int>& arr)
{
    int level = 0;
    size_t temp = index + 1;
    while (temp > 1)
    {
        temp >>= 1;
        level++;
    }

    string type;
    if (index == 0)
    {
        type = "root";
    }
    else
    {
        size_t parent_index = (index - 1) / 2;
        type = (index % 2 == 1) ? "left(" + to_string(arr[parent_index]) + ")"
                               : "right(" + to_string(arr[parent_index]) + ")";
    }

    cout << "Вы находитесь здесь: " << level << " " << type << " " << arr[index] << endl;
}

void navigate_pyramid(const vector<int>& arr)
{
    size_t current = 0;
    string command;

    do
    {
        print_current_position(current, arr);
        cout << "Введите команду: ";
        cin >> command;

        if (command == "up")
        {
            size_t parent;
            if (get_parent(current, parent, arr))
            {
                current = parent;
                cout << "Ок" << endl;
            }
            else
            {
                cout << "Ошибка! Отсутствует родитель" << endl;
            }
        }
        else if (command == "left")
        {
            size_t child;
            if (get_left_child(current, child, arr))
            {
                current = child;
                cout << "Ок" << endl;
            }
            else
            {
                cout << "Ошибка! Отсутствует левый потомок" << endl;
            }
        }
        else if (command == "right")
        {
            size_t child;
            if (get_right_child(current, child, arr))
            {
                current = child;
                cout << "Ок" << endl;
            }
            else
            {
                cout << "Ошибка! Отсутствует правый потомок" << endl;
            }
        }
        else if (command == "exit")
        {
            break;
        }
        else
        {
            cout << "Неизвестная команда. Доступные команды: up, left, right, exit" << endl;
        }
    } while (true);
}

int main()
{
    vector<vector<int>> pyramids =
    {
        {1, 3, 6, 5, 9, 8},
        {94, 67, 18, 44, 55, 12, 6, 42},
        {16, 11, 9, 10, 5, 6, 8, 1, 2, 4}
    };

    for (const auto& pyramid : pyramids)
    {
        cout << "Исходный массив:";
        for (int num : pyramid)
        {
            cout << " " << num;
        }
        cout << endl;

        print_pyramid(pyramid);
        navigate_pyramid(pyramid);
        cout << endl;
    }

    return 0;
}
