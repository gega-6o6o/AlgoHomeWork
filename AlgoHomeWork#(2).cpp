#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void dfsTopSort(const std::vector<std::vector<int>>& graph,
                int vertex,
                std::vector<bool>& visited,
                std::vector<int>& order)
{
    visited[vertex] = true;
    for (int neighbor = 1; neighbor < graph.size(); ++neighbor)
    {
        if (graph[vertex][neighbor] == 1 && !visited[neighbor])
        {
            dfsTopSort(graph, neighbor, visited, order);
        }
    }
    order.push_back(vertex);
}

std::vector<int> topologicalSort(const std::vector<std::vector<int>>& graph)
{
    std::vector<bool> visited(graph.size(), false);
    std::vector<int> order;
    
    for (int vertex = 1; vertex < graph.size(); ++vertex)
    {
        if (!visited[vertex])
        {
            dfsTopSort(graph, vertex, visited, order);
        }
    }
    
    std::reverse(order.begin(), order.end());
    return order;
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
    std::vector<std::vector<int>> graph(N + 1, std::vector<int>(N + 1));
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            inputFile >> graph[i][j];
        }
    }

    std::vector<int> sortedOrder = topologicalSort(graph);
    
    std::cout << "Топологический порядок вершин:";
    for (int vertex : sortedOrder)
    {
        std::cout << " " << vertex;
    }
    std::cout << std::endl;

    return 0;
}
