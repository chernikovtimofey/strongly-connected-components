#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <forward_list>

void make_adjacency_list(std::vector<std::forward_list<int>> &graph, std::istream &istream) {
    int from; istream >> from;
    --from;
    int to; istream >> to;
    --to;
    do {
        if (graph.size() <= from) {
            graph.resize(from + 1);
        }
        graph[from].push_front(to);

        istream >> from;
        --from;
        istream >> to;
        --to;
    } while(!istream.eof());

    graph.shrink_to_fit();

    std::forward_list<int>::iterator iter = graph[0].begin();
    int ok = 2;
}

void finish_time(std::forward_list<int> &finish_time_q, const std::vector<std::forward_list<int>> &graph) {
    auto q_last_element = finish_time_q.before_begin();
    std::stack<std::pair<int, std::forward_list<int>::const_iterator>> stack;
    std::vector<bool> visited = std::vector<bool>(graph.size());

    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            stack.push(std::make_pair(i, graph[i].begin()));

            while(!stack.empty()) {
                int current = stack.top().first;
                visited[current] = true;
                bool all_descendants_visited = true;
                for (auto iterator = stack.top().second; iterator != graph[current].end(); ++iterator) {
                    if (!visited[*iterator]) {
                        ++stack.top().second;
                        stack.push(std::make_pair(*iterator, graph[*iterator].begin()));
                        all_descendants_visited = false;
                        break;
                    }
                }

                if (all_descendants_visited) {
                    stack.pop();
                    finish_time_q.push_front(current);
                }
            }
        }
    }
}

std::vector<std::forward_list<int>> graph_transposition(const std::vector<std::forward_list<int>> &graph) {
    std::vector<std::forward_list<int>> transposed_graph = std::vector<std::forward_list<int>>(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        for (auto iterator = graph[i].begin(); iterator != graph[i].end(); ++iterator) {
            transposed_graph[*iterator].push_front(i);
        }
    }
    return transposed_graph;
}

void find_SCC(std::vector<int> &SCC, std::vector<std::forward_list<int>> &graph) {
    std::forward_list<int> finish_time_q;
    finish_time(finish_time_q, graph);
    graph = graph_transposition(graph);

    SCC = std::vector<int>(graph.size(), -1);
    int SCC_number = 0;
    std::stack<std::pair<int, std::forward_list<int>::const_iterator>> stack;
    std::vector<bool> visited = std::vector<bool>(graph.size());
    for (auto iterator1 = finish_time_q.begin(); iterator1 != finish_time_q.end(); ++iterator1) {
        if (SCC[*iterator1] == -1) {
            stack.push(std::make_pair(*iterator1, graph[*iterator1].begin()));

            while(!stack.empty()) {
                int current = stack.top().first;
                visited[current] = true;
                SCC[current] = SCC_number;
                bool all_descendants_visited = true;
                for (auto iterator2 = stack.top().second; iterator2 != graph[current].end(); ++iterator2) {
                    if (!visited[*iterator2]) {
                        ++stack.top().second;
                        stack.push(std::make_pair(*iterator2, graph[*iterator2].begin()));
                        all_descendants_visited = false;
                        break;
                    }
                }

                if (all_descendants_visited) { stack.pop(); }
            }
            ++SCC_number;
        }
    }
}

std::vector<std::forward_list<int>> SCC_function_to_sets(const std::vector<int> &SCC) {
    std::vector<std::forward_list<int>> sets;
    for (int i = 0; i < SCC.size(); ++i) {
        if (sets.size() <= SCC[i]) {
            sets.resize(SCC[i] + 1);
        }
        sets[SCC[i]].push_front(i);
    }
    return sets;
}