#include <iostream>
#include <fstream>
#include <vector>

void DFS(const std::vector<std::vector<int>>& graph, int vertex,
         std::vector<int>& components, int componentId)
{
    components[vertex] = componentId;
    for (int neighbor = 1; neighbor < graph.size(); ++neighbor)
    {
        if (graph[vertex][neighbor] && components[neighbor] == 0)
        {
            DFS(graph, neighbor, components, componentId);
        }
    }
}

void findConnectedComponents(const std::vector<std::vector<int>>& graph)
{
    std::vector<int> components(graph.size(), 0);
    int componentCount = 0;
    
    for (int vertex = 1; vertex < graph.size(); ++vertex)
    {
        if (components[vertex] == 0)
        {
            componentCount++;
            DFS(graph, vertex, components, componentCount);
        }
    }
    
    std::cout << "Принадлежность вершин компонентам связности:\n";
    for (int v = 1; v < graph.size(); ++v)
    {
        std::cout << v << " - " << components[v] << "\n";
    }
    std::cout << "Количество компонентов связности в графе: " << componentCount << "\n";
}

int main()
{
    std::ifstream input("input.txt");
    if (!input.is_open())
    {
        std::cerr << "Ошибка: файл input.txt не найден!\n";
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

    findConnectedComponents(graph);
    return 0;
}
