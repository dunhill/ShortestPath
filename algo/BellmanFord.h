#pragma once

#include "../common/Graph.h"

#include <vector>
#include <utility>

class BellmanFord
{
public:
    BellmanFord(Graph graph):m_graph(graph){}
    std::pair<int, std::vector< Vertex >> shortest_path(Vertex from, Vertex to) const;
private:
    Graph m_graph;
};
