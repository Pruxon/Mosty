#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <fstream>
#include <vector>
#include <iostream>
#include <queue>




class Graph
{
private:
    int Size = 0;
    std::vector<std::vector<int> > AdjacencyList;
    std::vector<std::pair <int , int> > Edges;
public:
    /*Graph (int number): Size(number)
    {
        AdjacencyList.resize(number);
    };*/


    Graph (const char *File)
    {
        std::fstream file;
        unsigned size_ = 0;

        file.open(File, std::ios::in);
        file>>size_;

        AdjacencyList.resize(size_);
        //Edges.resize(size_);
        Size = size_;

        unsigned a, b;
        while (file >> a >> b)
        {
            AddEdge(a, b);
        }

        file.close();
    }

    void AddEdge(int node1, int node2)
    {
        if (isCorrect(node1) && isCorrect(node2))
        {
            AdjacencyList[node1].push_back(node2);
            AdjacencyList[node2].push_back(node1);
            Edges.push_back({node1, node2});
        }
        else
            throw std::runtime_error("Invalid node number!");
    };

    bool isCorrect (int i) const
    {
        if (i >= Size || i < 0)
            return false;

        return true;
    };

    bool isExtensiveBridge(int node1, int node2)
    {
        if (Size <= 3)
            return false;

        std::queue<int> BFSqueue;
        std::vector<int> visited (Size);
        int VisitedCounter = 0;

        int start = 0;
        if (start == node1 || start == node2)
        {
            start++;
        }
        if (start == node1 || start == node2)
        {
            start++;
        }

        BFSqueue.push(start);
        visited[start] = 1;
        visited[node1] = 1;
        visited[node2] = 1;

        VisitedCounter++;

        while (!BFSqueue.empty())
        {
            int v = BFSqueue.front();
            BFSqueue.pop();
            for (int i = 0; i < AdjacencyList[v].size(); i++)
            {
                int neighbour = AdjacencyList[v][i];
                if (visited[neighbour] == 0)
                {
                    BFSqueue.push(neighbour);
                    visited[neighbour] = 1;
                    VisitedCounter++;
                }
            }
        }
        if (VisitedCounter == Size - 2)
            return false;

        return true;

    }

    std::vector<std::pair<int, int> > getEdges() const
    {
        return Edges;
    }
    std::vector<std::pair<int, int> > FindBridges()
    {
        std::vector<std::pair<int, int> > Bridges;
        if (Size <= 3)
            return Bridges;
        for (int i = 0; i < Edges.size(); i++) //(auto edge : Edges)
        {
            if (isExtensiveBridge(Edges[i].first, Edges[i].second) == true)
            {
                Bridges.push_back(Edges[i]);
            }
        }
        return Bridges;
    }

};

#endif //GRAPH_H_INCLUDED