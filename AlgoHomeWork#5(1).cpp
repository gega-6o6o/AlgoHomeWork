#include <iostream>
#include <vector>
#include <string>

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
        int parent_value;
        
        if (i == 0)
        {
            type = "root";
        }
        else
        {
            size_t parent_index = (i - 1) / 2;
            parent_value = arr[parent_index];
            
            if (i % 2 == 1)
            {
                type = "left(" + to_string(parent_value) + ")";
            }
            else
            {
                type = "right(" + to_string(parent_value) + ")";
            }
        }
        
        cout << level << " " << type << " " << arr[i] << endl;
    }
}

int main()
{
    vector<vector<int>> test_arrays =
    {
        {1, 3, 6, 5, 9, 8},
        {94, 67, 18, 44, 55, 12, 6, 42},
        {16, 11, 9, 10, 5, 6, 8, 1, 2, 4}
    };
    
    for (const auto& arr : test_arrays)
    {
        cout << "Исходный массив:";
        for (int num : arr)
        {
            cout << " " << num;
        }
        cout << endl;
        
        print_pyramid(arr);
        cout << endl;
    }
    
    return 0;
}
