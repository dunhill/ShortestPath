#pragma once

#include <map>
#include <vector>
#include <set>
#include <utility>

class Vertex
{
public:
    Vertex(int id = 0):m_id(id){}
public:
    int id() const {return m_id;}
    bool operator<(Vertex other) const
    {
        return id() < other.id();
    }
private:
    int m_id;
};

class Edge
{
public:
    Edge(Vertex from, Vertex to, int weight)
        : m_from(from)
        , m_to(to)
        , m_weight(weight)
    {
    }
public:
    Vertex from() const {return m_from;}
    Vertex to() const {return m_to;}
    int weight() const {return m_weight;}
private:
    Vertex m_from;
    Vertex m_to;
    int m_weight;
};

class Graph
{
public:
    Graph();
    std::set< Vertex > vertexes() const
    {
        return m_vertexes;
    }

    void add_edge(Vertex from, Vertex to, int weight)
    {
        m_vertexes.insert(from);
        m_vertexes.insert(to);

        Edge edge(from, to, weight);
        m_vertex_to_edges.insert(std::make_pair(std::make_pair(from,true), edge));
        m_vertex_to_edges.insert(std::make_pair(std::make_pair(to,false), edge));
    }

    std::vector<Edge> get_edges(Vertex v, bool forward) const
    {
        std::vector< Edge > result;
        auto iter_range = m_vertex_to_edges.equal_range(std::make_pair(v,forward));
        for (auto iter = iter_range.first; iter != iter_range.second; ++iter)
        {
            result.push_back(iter->second);
        }
        return result;
    }
private:
    std::set< Vertex > m_vertexes;
    std::multimap<std::pair<Vertex,bool>,Edge> m_vertex_to_edges;
};
