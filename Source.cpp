#include <iostream>
#include <vector>
#include <fstream>
#include "Graph.hpp"

int main() {
	Graph G("test.txt");
	G.GetNomFileDot();
	G.SetNomFileTxt("test.txt");
	G.ReadGraph();
	G.WriteGraph();
}

