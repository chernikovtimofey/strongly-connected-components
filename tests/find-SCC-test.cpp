#include <iostream>
#include <sstream>
#include <fstream>
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

        std::vector<int> SCC;
        find_SCC(SCC, graph);
        std::cout << "test " << i << ":\n" << "SCC as function: " << vector_string(SCC) << "\n\n" << "SCC as set:" << "\n" << graph_string(SCC_function_to_sets(SCC)) << "\n\n";
    }
}