#include "Graph.hpp"

Graph::Graph(): file_txt("default.txt"), file_dot("default.dot"), v(0), nb_sommet(0){
}

Graph::Graph(std::string file_txt): file_txt(file_txt), file_dot("default.dot"), v(0), nb_sommet(0) {
}

Graph::Graph(std::string file_txt, std::string file_dot): file_txt(file_txt), file_dot(file_dot), v(0), nb_sommet(0) {
}

Graph::~Graph() {

}

// Get and Set .txt

std::string Graph::GetNomFileTxt() {
    std::cout << file_txt << std::endl;
    return file_txt;
}

void Graph::SetNomFileTxt(std::string file_txt) {
    this->file_txt = file_txt;
}

// Get and Set .dot

std::string Graph::GetNomFileDot() {
     std::cout << file_dot << std::endl;
    return file_dot;
}

void Graph::SetNomFileDot(std::string file_dot) {
    this->file_dot = file_dot;
}

// Read Graph from .txt to v

void Graph::ReadGraph() {
    std::ifstream fichier(file_txt.c_str());
    

    while(!fichier.eof()) {
		fichier >> nb_sommet;
		v.resize(nb_sommet);
        int nb_succ;

		for (int i = 0; i < nb_sommet; i++) {
			fichier >> nb_succ;
			v[i].resize(nb_succ);
			for (int j = 0; j < nb_succ; j++) {
				fichier >> v[i][j];
			}
		}
	}
    fichier.close();
}

// Write Graph from v to .dot

void Graph::WriteGraph() {
    std::ofstream fichier(file_dot.c_str());
	fichier << "digraph G { "<< std::endl;

    for (int i = 0; i < nb_sommet; i++)
	{	
		fichier << '"' << i+1 << '"' << "->" << "{";
		int nb_voisins =  v[i].size();
		for (int j=0; j< nb_voisins; j++) {
			fichier << '"' << v[i][j]<<'"';
			if (j!= nb_voisins -1) {
				fichier << ";";
			}
		}
		fichier << "};" << std::endl;
	}
	fichier << "}";
}



