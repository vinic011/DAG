#include "graph.hpp"

int main()
{
    std::size_t n;
    std::cin >> n;
    auto g = graph(n);
    std::cin >> g;
    if (g.dag_test() == true) {
        g.topological_sort();
    }
    else std::cout << " ";
    std::cout << "\n";
}