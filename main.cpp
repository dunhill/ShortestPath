#include <iostream>

#include <common/Graph.h>
#include <algo/BellmanFord.h>

int main()
{
    std::cout << "Shortest Path problem solver" << std::endl << std::endl;

    Graph graph;
    graph.add_edge(1, 2, 1);
    graph.add_edge(1, 3, 4);
    graph.add_edge(2, 4, 6);
    graph.add_edge(3, 4, 2);

    BellmanFord algo(graph);
    auto result = algo.shortest_path(1, 4);

    std::cout << "Shotest path has cost " << result.first
              << " and " << result.second.size() << " vertices:" << std::endl;
    for ( const Vertex& vertex : result.second )
    {
        std::cout << vertex.id() << std::endl;
    }

    return 0;
}

