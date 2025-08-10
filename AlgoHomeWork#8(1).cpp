#include <iostream>
#include <fstream>
#include <vector>

void printGraph(const std::vector<std::vector<int>>& adjMatrix)
{
    std::cout << "Текстовый вид орграфа:" << std::endl;
    for (int i = 1; i < adjMatrix.size(); ++i)
    {
        std::cout << i << ": ";
        bool hasEdges = false;
        for (int j = 1; j < adjMatrix[i].size(); ++j)
        {
            if (adjMatrix[i][j] == 1)
            {
                if (hasEdges) std::cout << " ";
                std::cout << j;
                hasEdges = true;
            }
        }
        if (!hasEdges)
        {
            std::cout << "нет";
        }
        std::cout << std::endl;
    }
}

int main()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Не удалось открыть файл input.txt" << std::endl;
        return 1;
    }

    int N;
    inputFile >> N;

    std::vector<std::vector<int>> adjMatrix(N + 1, std::vector<int>(N + 1));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            inputFile >> adjMatrix[i][j];
        }
    }

    printGraph(adjMatrix);

    return 0;
}
