
#include <iostream>
#include <cassert>
#include<queue>
#include<stack>
#include<vector>
#include<alg.h>
#include<string>
using namespace std;

bool ch = false;
struct AdjacentMatrixGraph {
    int** matrix;
    size_t size;

    AdjacentMatrixGraph(size_t size) {
        this->size = size;
        this->matrix = new int* [size];
        for (size_t i = 0; i < size; i++) {
            this->matrix[i] = new int[size];
            for (size_t j = 0; j < size; j++) {
                this->matrix[i][j] = 0;
            }
        }
    }
    ~AdjacentMatrixGraph() {
        for (size_t i = 0; i < size; i++) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
    }

    void add_edge(size_t start_vertex, size_t end_vertex) {
        assert(start_vertex < size);
        assert(end_vertex < size);
        this->matrix[start_vertex][end_vertex] = 1;
    }
    void remove_edge(std::size_t start_vertex, std::size_t end_vertex) {
        assert(start_vertex < size);
        assert(end_vertex < size);
        this->matrix[start_vertex][end_vertex] = 0;
    }
    void print_matrix() {
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void print_edges() {
        for (size_t i = 0; i < size; i++) {
            bool has_edges = false;
            for (size_t j = 0; j < size; j++) {
                if (matrix[i][j]) {
                    cout << i << "->" << j << " ";
                    has_edges = true;
                }
            }
            if (has_edges) {
                cout << endl;
            }
        }
    }
    void dfs(int vertex, bool* visited) {
        //cout << vertex << " ";
        visited[vertex]++;
        for (int i = 0; i < this->size; i++)
        {
            if (!visited[i] && matrix[vertex][i])
            {
                dfs(i, visited);
            }
        }

    }
    bool connectivity_of_the_graph() {
        bool* visited = new bool[this->size];
        for (int i = 0; i < this->size; i++) {
            visited[i] = false;
        }
        dfs(0, visited);
        for (int i = 0; i < this->size; i++) {
            if (visited[i] == false) {
                return false; cout << "false" << endl;
            }
        }
        return true; cout << "true" << endl;
    }

};

struct GraphNode {
    int weight;
    int vertex;
    GraphNode* next;
    GraphNode(int vertex, int weight = 0, GraphNode* next = nullptr) {
        this->vertex = vertex;
        this->next = next;
        this->weight = weight;
    }
};

struct Graph {
    GraphNode** edges;
    int number_of_vertex;
    Graph(int number_of_vertex) {
        this->number_of_vertex = number_of_vertex;
        this->edges = new GraphNode * [number_of_vertex];
        for (std::size_t i = 0; i < number_of_vertex; i++) {
            this->edges[i] = nullptr;
        }
    }
    ~Graph() {
        for (int i = 0; i < number_of_vertex; i++) {
            GraphNode* current = this->edges[i];
            while (current) {
                GraphNode* to_delete = current;
                current = current->next;
                delete to_delete;
            }
        }
        delete[] this->edges;
    }

    void add_edge(int start_vertex, int end_vertex, int weight = 0) {
        assert(start_vertex < this->number_of_vertex);
        assert(end_vertex < this->number_of_vertex);
        GraphNode* current = this->edges[start_vertex];
        GraphNode* new_current = new GraphNode(end_vertex, weight);
        if (current)
        {
            if (current->vertex > new_current->vertex)
            {
                new_current->next = current;
                this->edges[start_vertex] = new_current;
                return;
            }
            if (current->vertex == new_current->vertex) { delete new_current; return; }

            while (current->next) {
                if (current->next->vertex == new_current->vertex) { delete new_current; return; }
                if (current->next->vertex > new_current->vertex)
                {
                    new_current->next = current->next;
                    current->next = new_current;
                    return;
                }
                current = current->next;
            }
            current->next = new_current;
        }
        else {
            this->edges[start_vertex] = new_current;
        }
    }
    void add_in_end(int start_vertex, int end_vertex) {
        GraphNode* current = this->edges[start_vertex];
        GraphNode* new_current = new GraphNode(end_vertex);

        while (current->next) {
            if (current->vertex == end_vertex)
            {
                return;
            }
            current = current->next;
        }
        if (current->vertex == end_vertex)
        {
            return;
        }
        current->next = new_current;

    }
    void print() {
        for (int i = 0; i < this->number_of_vertex; i++)
        {
            GraphNode* current = this->edges[i];
            cout << "Vertex " << i << " : ";
            while (current) {
                cout << current->vertex << " ";
                current = current->next;
            }
            cout << ";" << endl;
        }
    }

};

int main()
{
    bool f = true;
    while (f) {
        int move;
        cout << "enter move:" <<"  "<<"1 matrix" <<"  "<< "2 list"<<"  "<<"3 leave"<< endl;
        cin >> move;
        if (move == 1) {

            AdjacentMatrixGraph mat(5);
            for (int i = 0; i < 5; i++) {
                int st, en;
                cout << "start" << endl;
                cin >> st;
                cout << "end" << endl;
                cin >> en;
                mat.add_edge(st, en);
            }
            mat.print_matrix();
            cout << "  " << endl;
            mat.print_edges();
            cout << "  " << endl;
            mat.connectivity_of_the_graph();
            cout << "  " << endl;
            int stv;
            int etv=0;
            cout << "Enter START and END of deleted vertex  " << endl;
            cin >> stv, etv;
            cout << "  " << endl;
            mat.remove_edge(stv, etv);
            cout << "  " << endl;
            mat.print_matrix(); break;
        }
        if (move == 2) {
            Graph list(5);
            for (int i = 0; i < 6; i++) {
                int st, en;
                cout << "start" << endl;
                cin >> st;
                cout << "end" << endl;
                cin >> en;
                list.add_edge(st, en);
            }
            list.print();
            cout << "  " << endl;
        }
        if (move == 3) { break; }

    }
}


