#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int n;
    int pos;
    int dist;
    vector<pair<Node *, int>> adj;
    bool visited;
};

class BinaryHeap{
public:
    vector<Node *> elem;
    void addElem(Node * node){
        elem.push_back(node);
        shiftup(elem.size()-1);
    }

    void shiftup(int idx){
        if(idx == 0){
            elem[idx]->pos = 0;
            return;
        }

        int parent = (idx-1)/2;
        if(elem[parent]->dist > elem[idx]->dist){
            elem[parent]->pos = idx;
            swap(elem[parent], elem[idx]);
            shiftup(parent);
        }
        else{
            elem[idx]->pos = idx;
        }
    }

    void shiftdown(int idx){
        if(idx >= elem.size()) return;
        int largest = idx;
        int left = 2*idx + 1;
        int right = 2*idx + 2;

        if(left < elem.size() && elem[left]->dist < elem[largest]->dist) largest = left;
        if(right < elem.size() && elem[right]->dist < elem[largest]->dist) largest = right;
        
        if(largest != idx){
            elem[largest]->pos = idx;
            swap(elem[largest], elem[idx]);
            shiftdown(largest);
        }
        else{
            elem[idx]->pos = idx;
        }
    }
};

class Graph{
public:
    int V;
    vector<Node> nodes;

    Graph(int v){
        V = v;
        for(int i = 0; i < V; ++i){
            nodes.push_back(Node());
        }
    }

    void addEdge(int a, int b, int w){
        nodes[a].adj.push_back(make_pair(&nodes[b], w));
        nodes[b].adj.push_back(make_pair(&nodes[a], w));
    }
};

// the error was due to return type as vector<int> and not returning anything
// don't know why wasn't it a compile time error though
void dijkstra(Graph &g, int src){
    for(int i = 0; i < g.V; ++i) g.nodes[i].dist = numeric_limits<int>::max(); 
    g.nodes[src].dist = 0;

    BinaryHeap b;
    //push all vertices to priority queue
    for(int i = 0; i < g.V; ++i) b.addElem(& g.nodes[i]);

    while(!b.elem.empty()){
        Node *u = b.elem[0];
        u->visited = true;
        b.elem[0] = b.elem[b.elem.size()-1];
        b.elem.pop_back();
        b.shiftdown(0);

        for(auto a: u->adj){
            if(!a.first->visited && u->dist != numeric_limits<int>::max() && 
                   u->dist + a.second < a.first->dist){
                a.first->dist = u->dist + a.second;
                b.shiftup(a.first->pos);
            }

        }

    }

}

int main(){
    Graph graph(9);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 7, 8);
    graph.addEdge(1, 2, 8);
    graph.addEdge(1, 7, 11);
    graph.addEdge(2, 3, 7);
    graph.addEdge(2, 8, 2);
    graph.addEdge(2, 5, 4);
    graph.addEdge(3, 4, 9);
    graph.addEdge(3, 5, 14);
    graph.addEdge(4, 5, 10);
    graph.addEdge(5, 6, 2);
    graph.addEdge(6, 7, 1);
    graph.addEdge(6, 8, 6);
    graph.addEdge(7, 8, 7);
 
    dijkstra(graph, 8);
 
    for(int i = 0; i < graph.V; ++i){
        cout<<i<<": "<<graph.nodes[i].dist<<endl;
    }
    return 0;
}

