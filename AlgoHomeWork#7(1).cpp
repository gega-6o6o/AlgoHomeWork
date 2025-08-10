#include <iostream>
#include <fstream>
#include <vector>

void dfs(const std::vector<std::vector<int>>& graph,
         std::size_t current,
         std::vector<bool>& visited,
         std::vector<std::size_t>& traversal)
{
    visited[current] = true;
    traversal.push_back(current);

    for (std::size_t neighbor = 1; neighbor < graph.size(); ++neighbor)
    {
        if (graph[current][neighbor] == 1 && !visited[neighbor])
        {
            dfs(graph, neighbor, visited, traversal);
        }
    }
}

int main()
{
    std::ifstream input("input.txt");
    std::size_t N;
    input >> N;

    std::vector<std::vector<int>> graph(N+1, std::vector<int>(N+1));
    for (std::size_t i = 1; i <= N; ++i) {
        for (std::size_t j = 1; j <= N; ++j)
        {
            input >> graph[i][j];
        }
    }

    std::vector<bool> visited(N+1, false);
    std::vector<std::size_t> traversal;

    dfs(graph, 1, visited, traversal);

    std::cout << "Порядок обхода вершин:";
    for (auto v : traversal)
    {
        std::cout << " " << v;
    }
    std::cout << std::endl;

    return 0;
}
