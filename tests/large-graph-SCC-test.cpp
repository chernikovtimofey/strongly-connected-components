#include <iostream>
#include <forward_list>
#include <fstream>
#include <chrono>
#include "../SCC-finder.h"
#include "../tests/object-string.h"

int main() {
    std::vector<std::forward_list<int>> graph;
    std::ifstream file;
    file.open("../tests/test-matrices/problem8.10.txt");
    make_adjacency_list(graph, file);
    file.close();

    std::vector<int> SCC;

    int number_experements = 5;
    std::vector<double> durations = std::vector<double>(number_experements);
    for (int i = 0; i < number_experements; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        find_SCC(SCC, graph);
        auto stop = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> ms_double = stop - start;
        durations[i] = ms_double.count();
        std::cout << "experiment " << i << ": " << durations[i] << "\n";
    }

    double avg = 0;
    for (int i = 0; i < number_experements; ++i) {
        avg += durations[i] / number_experements;
    }
    std::cout << "avg of experiments: " << avg << "\n";
}