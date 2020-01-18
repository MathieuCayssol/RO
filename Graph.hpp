#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <fstream>

class Graph {
    std::string file_txt;
    std::string file_dot;
    std::vector<std::vector<int> > v;
    int nb_sommet;
    public:
        Graph();
        Graph(std::string);
        Graph(std::string, std::string);
        ~Graph();
        std::string GetNomFileTxt();
        void SetNomFileTxt(std::string);
        std::string GetNomFileDot();
        void SetNomFileDot(std::string);
        void ReadGraph();
        void WriteGraph();
};




#endif