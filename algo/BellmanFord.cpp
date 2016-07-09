#include "BellmanFord.h"

std::pair<int, std::vector< Vertex >>
BellmanFord::shortest_path(Vertex from, Vertex to) const
{
    std::map< Vertex, int > distance;
    distance[from] = 0;
    std::map< Vertex, Vertex > predecessors;

    for ( int i = 0; i < m_graph.vertexes().size(); ++i)
    {
        bool updated = false;
        for ( Vertex v : m_graph.vertexes() )
        {
            for ( Edge e : m_graph.get_edges(v, true) )
            {
                auto iter_dist_from = distance.find(e.from());
                if (iter_dist_from == distance.end())
                {
                    continue;
                }
                auto iter_dist_to = distance.find(e.to());
                if ((iter_dist_to == distance.end())
                        || (iter_dist_to->second > iter_dist_from->second + e.weight()))
                {
                    distance[e.to()] = iter_dist_from->second + e.weight();
                    predecessors[e.to()] = e.from();
                    updated = true;
                }
            }
        }
        if (!updated)
        {
            break;
        }
    }

    std::vector< Vertex > path;
    for ( auto v = to; v.id() != from.id(); v = predecessors[v] )
    {
        path.insert(path.begin(), v);
    }
    path.insert(path.begin(), from);
    return std::make_pair( distance[to], path);
}
