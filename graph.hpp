#include<vector>
#include<stack>
#include<iostream>

enum color{
    white,
    grey,
    black,
};

class graph{
public:
    explicit graph(std::size_t nvertices);
    friend std::istream &operator>>(std::istream &is,graph& g);
    void add_edge(std::size_t u,std::size_t v);

    bool dag_test();
    bool dag_test_r(std::size_t&,std::vector<color>&);

    void topological_sort();
    void topological_sort_r(std::size_t&,std::vector<color>&,std::stack<std::size_t>&);
   
private:
    std::size_t nvertices_;
    std::size_t map(std::size_t u,std::size_t v) const;
    std::vector<bool> adj_matrix;
};
