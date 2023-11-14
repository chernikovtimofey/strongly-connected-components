#include <iostream>
#include <fstream>
#include <sstream>
#include "../SCC-finder.h"
#include "object-string.h"

int main() {
    for (int i = 1; i <= 5; ++i) {
        std::stringstream path;
        path << "../tests/test-matrices/problem8.10test" << i << ".txt";
        std::ifstream file;
        file.open(path.str());
        std::vector<std::forward_list<int>> graph;
        make_adjacency_list(graph, file);
        file.close();
        std::cout << "test " << i << ":\n" << graph_string(graph) << "\n\n";
    }
}