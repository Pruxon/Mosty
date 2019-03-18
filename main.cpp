#include <iostream>
#include <fstream>
#include "Graph.h"


int main(int Argc, char* Argv[]) {
    if(Argc == 0)
        return -1;
    char *File = Argv[1];
/*int main(){
    char *File = "graf4.txt";
*/
    Graph *My_Graph = new Graph(File);

    std::vector<std::pair<int, int> > Bridges;
/*
    Bridges = My_Graph->getEdges();
    if (Bridges.size() == 0)
        std::cout<<"No extensive bridges" << std::endl;
    else
    {
        std::cout<<"Bridges:"<<std::endl;
        for (unsigned i = 0; i < Bridges.size(); i++)
        {
            std::cout<<Bridges[i].first<<" "<<Bridges[i].second<<std::endl;
        }
    }
*/
    Bridges = My_Graph->FindBridges();

    if (Bridges.size() == 0)
        std::cout<<"No extensive bridges" << std::endl;
    else
    {
        std::cout<<"Extensive Bridges:"<<std::endl;
        for (unsigned i = 0; i < Bridges.size(); i++)
        {
            std::cout<<Bridges[i].first<<" "<<Bridges[i].second<<std::endl;
        }
    }

    return 0;
}
