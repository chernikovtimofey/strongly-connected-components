#include <vector>
#include <string>
#include <sstream>
#include <forward_list>

std::string graph_string(const std::vector<std::forward_list<int>> &graph) {
    std::stringstream ss;

    if (graph.size() != 0) {
        auto iterator = graph[0].begin();
        ss << "1: ";
        if (iterator != graph[0].end()) {
            ss << *iterator + 1;
            ++iterator;
        }
        for (; iterator != graph[0].end(); ++iterator) {
            ss << " " << *iterator + 1;
        }
    }
    for (int i = 1; i < graph.size(); ++i) {
        ss << "\n" << i + 1 << ": ";
        auto iterator = graph[i].begin();
        if (iterator != graph[i].end()) {
            ss << *iterator + 1;
            ++iterator;
        }
        for (; iterator != graph[i].end(); ++iterator) {
            ss << " " << *iterator + 1;
        }
    }
    return ss.str();
}

std::string vertices_string(const std::forward_list<int> &vertices) {
    std::stringstream ss;

    auto iterator = vertices.begin();
    if (iterator != vertices.end()) {
        ss << *iterator + 1;
        ++iterator;
    }
    for (; iterator != vertices.end(); ++iterator) {
        ss << " " << *iterator + 1;
    }
    return ss.str();
}

std::string vector_string(const std::vector<int> &vector) {
    std::stringstream ss;

    if (vector.size() != 0) {
        ss << vector[0];
    }
    for (int i = 1; i < vector.size(); ++i) {
        ss << " " << vector[i];
    }
    return ss.str();
}