#include <iostream>
#include <fstream>
#include <vector>

bool isCyclicUtil(const std::vector<std::vector<int>>& graph, int v, std::vector<bool>& visited, int parent)
{
    visited[v] = true;
    for (int i = 1; i < graph.size(); ++i)
    {
        if (graph[v][i])
        {
            if (!visited[i])
            {
                if (isCyclicUtil(graph, i, visited, v)) return true;
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(const std::vector<std::vector<int>>& graph)
{
    std::vector<bool> visited(graph.size(), false);
    for (int v = 1; v < graph.size(); ++v)
    {
        if (!visited[v] && isCyclicUtil(graph, v, visited, -1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    std::ifstream input("input.txt");
    if (!input)
    {
        std::cerr << "Ошибка: файл не найден!" << std::endl;
        return 1;
    }

    int N;
    input >> N;
    std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1));

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            input >> graph[i][j];
        }
    }

    std::cout << (hasCycle(graph) ? "В графе есть цикл!" : "В графе нет циклов") << std::endl;
    return 0;
}
