#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <forward_list>
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

        std::forward_list<int> finish_time_q;
        finish_time(finish_time_q, graph);
        std::cout << "test " << i << ":\n" << vertices_string(finish_time_q) << "\n\n";
    }
}