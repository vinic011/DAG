#include "graph.hpp"

graph::graph(std::size_t n) : nvertices_{n},adj_matrix{}
{
    adj_matrix.resize(n*n, false);
}

std::size_t graph::map(std::size_t u,std::size_t v) const
{   
    return u*nvertices_ + v;
}

void graph::add_edge(std::size_t u,std::size_t v)
{
    if(u >= nvertices_ || v >= nvertices_ || u == v)
        return;
    else adj_matrix[map(u,v)] = true;
}

std::istream &operator>>(std::istream& is, graph& g)
{
    int a,b;
    while(is >> a){
        is >> b;
        g.add_edge(a,b);
    }
    return is;
}

bool graph::dag_test()
{
    std::vector<color> mark_visit;
    mark_visit.resize(nvertices_,white);
    for(std::size_t i = 0; i < nvertices_; i++){
        if(mark_visit[i] == white){
            if(!dag_test_r(i,mark_visit))
                return false;
        }
    }
    return true;
}

bool graph::dag_test_r(std::size_t& i, std::vector<color>& mark_visit)
{
    mark_visit[i] = grey;
    for(std::size_t j = 0; j < nvertices_; j++){
        if(adj_matrix[map(i,j)] && mark_visit[j] == white && i != j)
            dag_test_r(j,mark_visit);
        if(adj_matrix[map(i,j)] && mark_visit[j] == grey && i != j)
            return false;
    }
    mark_visit[i] = black;
    return true;
}

void graph::topological_sort()
{
    std::vector<color> mark_visit;
    std::stack<std::size_t> stack_black;
    mark_visit.resize(nvertices_,white);
    for(std::size_t i = 0; i < nvertices_; i++){
        if(mark_visit[i] == white)
            topological_sort_r(i,mark_visit,stack_black);
    }
    while(!stack_black.empty()){
            std::cout << stack_black.top() << " ";
            stack_black.pop();
    }
}

void graph::topological_sort_r(std::size_t &i, std::vector<color>& mark_visit,std::stack<std::size_t> & stack_black)
{
    mark_visit[i] = grey;
    for(std::size_t j = 0; j < nvertices_; j++){
        if(adj_matrix[map(i,j)] && mark_visit[j] == white && i != j)
            topological_sort_r(j,mark_visit,stack_black);
    }
    stack_black.push(i);
}


