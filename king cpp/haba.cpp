#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

struct Edge {
    Edge(){}
    Edge(float weight, std::pair<char, char> vertex)
    {
        this->weight = weight;
        this->vertex = vertex;
    }
    float weight = 0;
    std::pair<char, char> vertex = {0, 0};
};

/*
Let's override operator '<<' so we can print our vertexes.
*/
std::ostream& operator<<(std::ostream& stream, const Edge& edge)
{
  stream << '(' << edge.weight << ", {" << edge.vertex.first << ", " << edge.vertex.second << " })";
  return stream;
}

/*
This function takes a list of a vector of vertexes and an edge.
The vector of edges is the subgraph. The list holds all our current subgraphs.
The funcion returns the subgraps connected to the given edge, and return a
pair of iterator to the connected subgraps.
*/
auto find_conected_graps(std::list<std::vector<Edge>>& subgraphs, const Edge& edge)
{
    auto result = std::pair(subgraphs.end(), subgraphs.end());
    std::cout << "\nLooking for vertexes connected to " << edge << '\n';

    for(auto it = subgraphs.begin(); it != subgraphs.end(); it++)
    {
        for(auto& e: *it)
        {
            if(edge.vertex.first == e.vertex.first || edge.vertex.first == e.vertex.second)
            {
                std::cout << e << '\n';
                result.first = it;
            }
            if(edge.vertex.second == e.vertex.first || edge.vertex.second == e.vertex.second)
            {
                std::cout <<  e << '\n';
                result.second = it;
            }
        }
    }
    return result;
}

/*
And finally we can call our function.
*/
auto kruskal(std::vector<Edge> edges)
{
    std::list<std::vector<Edge>> subgraphs;

    if(edges.empty())
    {
        return std::vector<Edge>();
    }

    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){
        return (a.weight > b.weight)? true: false;
    });


    for(int i = 0; i < edges.size(); i++)
    {
        //get the subgraphs connected to the current edge
        auto temp = find_conected_graps(subgraphs, edges[i]);
        if(temp.first == temp.second)
        {
            //if boths sides* of the edges are connected to the same
            //subgraph we discard it. 
            if(temp.first != subgraphs.end())
            {
                std::cout << "Cycle found! Discarding.\n";
                continue;
            }
            //If the connected subgraphs are not in our subgraps list
            //we create a new subgraph and push the current edge to it.
            std::cout << "No connections found. Pushing it in a new subgraph.\n";
            auto temp_graph = subgraphs.emplace(subgraphs.end());
            temp_graph->push_back(edges[i]);
        }
        else
        {
            if(temp.first == subgraphs.end())
            {
                temp.second->push_back(edges[i]);
            }
            else if(temp.second == subgraphs.end())
            {
                temp.first->push_back(edges[i]);
            }
            else
            {
                //Here our vertex is connected to two subgraps. We merge them
                //and delete one of it.
                temp.first->push_back(edges[i]);
                std::copy(temp.second->begin(), temp.second->end(), std::back_inserter(*temp.first));
                subgraphs.erase(temp.second);
                std::cout << "Subgraphs merged.\n";
            }

        }
    }
    //At the end we should have just one subgraph
    return *subgraphs.begin();
}


int main()
{
    std::vector<Edge> edges;
    
    edges = {Edge(5 , {'A', 'B'}), Edge(17, {'A', 'E'}),
             Edge(13, {'B', 'C'}), Edge(20, {'B', 'D'}), Edge(5 , {'B', 'E'}), Edge(7, {'B', 'G'}),
             Edge(12, {'C', 'D'}), Edge(11, {'C', 'G'}), Edge(6, {'C', 'H'}),
             Edge(10, {'E', 'F'}), Edge(8, {'E', 'G'}),
             Edge(4, {'F', 'G'})};
    

    auto result = kruskal(edges);
    auto t = 0.f;
    for(auto& edge: result)
    {
        std::cout << edge << '\n';
        t += edge.weight;
    }
    std::cout << "max: " << t << '\n';
}