#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

void BFS(const std::vector<std::vector<int>>& graph,
         int start,
         std::vector<bool>& visited,
         std::vector<int>& order)
{
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        order.push_back(v);

        for (int to = 1; to < graph.size(); ++to)
        {
            if (graph[v][to] == 1 && !visited[to])
            {
                visited[to] = true;
                q.push(to);
            }
        }
    }
}

int main()
{
    std::ifstream input("input.txt");
    if (!input.is_open())
    {
        std::cerr << "Ошибка: файл input.txt не найден!" << std::endl;
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

    int start;
    std::cout << "В графе " << N << " вершин. Введите номер вершины (1-" << N << "): ";
    std::cin >> start;

    if (start < 1 || start > N)
    {
        std::cerr << "Ошибка: номер вершины должен быть от 1 до " << N << std::endl;
        return 1;
    }

    std::vector<bool> visited(N + 1, false);
    std::vector<int> traversalOrder;
    BFS(graph, start, visited, traversalOrder);

    std::cout << "Порядок обхода вершин:";
    for (int v : traversalOrder)
    {
        std::cout << " " << v;
    }
    std::cout << std::endl;

    return 0;
}
