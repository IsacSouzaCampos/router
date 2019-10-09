#include <iostream>
#include "grafo.h"



Grafo::Grafo() = default;

void Grafo::inserirVertice(int data) {
    int index = ultimo;
    // Vertice v = Vertice(data, index);
    listaVertices.push_back(Vertice(data, index));
    vertices++;
    ultimo++;
}


bool Grafo::inserirAresta(int v1, int v2) {
    for(auto& vi : listaVertices) {
        if(vi.getIndex() == v1) {
            for(auto& vj : listaVertices) {
                if(vj.getIndex() == v2) {
                    vi.listaVizinhos.push_back(vj);
                    vj.listaVizinhos.push_back(vi);
                    arestas++;
                    return true;
                }
            }
        }
    }
    return false;
}

bool Grafo::deletarVertice(int index) {
    for(auto& v : listaVertices){
         if(v.getIndex() == index) {
            listaVertices.remove(v);
            vertices--;
            return true;;
         }
    }
    return false;
}

bool Grafo::deletarAresta(int v1, int v2) {
    for(auto& vi : listaVertices) {
        if(vi.getIndex() == v1) {
            for(auto& vj : vi.listaVizinhos) {
                if(vj.getIndex() == v2) {
                    vi.listaVizinhos.remove(vj);
                    vj.listaVizinhos.remove(vi);
                    arestas--;
                    return true;
                }
            }
        }
    }
    return false;
}

void Grafo::imprimirListaAdjacentes() {
    if(listaVertices.empty())
        throw out_of_range("lista vazia!");
    for(auto& vi : listaVertices) {
        cout << "[v" << vi.getIndex() << "]: " << flush;
        for(auto& vj : vi.listaVizinhos) {
            cout << "[v" << vj.getIndex() << "] / " << flush;
        }
        cout << endl;
    }
}

void Grafo::imprimirVertices() {
    for(auto& v : listaVertices)
        cout << v.getData() << endl;
}

void Grafo::DFS() {
    stack<Vertice> stack;
    for(auto& v : listaVertices) {
        v.setColor(color::BRANCO);
    }

    auto& raiz = *(listaVertices.begin());
    stack.push(raiz);

    while(!stack.empty()) {
        auto current = stack.top();
        current.setColor(color::CINZA);
        stack.pop();

        bool branco = false;
        for(auto& v : current.listaVizinhos) {
            if(v.getColor() == color::BRANCO) {
                branco = true;
                continue;
            }
        }
        if(!branco) {
            current.setColor(color::PRETO);
            cout << current.getData() << endl;
            continue;
        }
        
        for(auto& v : current.listaVizinhos) {
            if(v.getColor() == color::BRANCO) {
                v.setColor(color::CINZA);
                stack.push(v);
            }
        }
    }
}

void Grafo::BFS() {
    queue<Vertice> queue;
    for(auto& v : listaVertices) {
        v.setColor(color::BRANCO);
    }

    auto& raiz = *(listaVertices.begin());
    queue.push(raiz);

    while(!queue.empty()) {
        auto current = queue.front();
        current.setColor(color::CINZA);
        queue.pop();

        bool branco = false;
        for(auto& v : current.listaVizinhos) {
            if(v.getColor() == color::BRANCO)
                branco = true;
                continue;
        }
        if(!branco) {
            current.setColor(color::PRETO);
            cout << current.getData() << endl;
            continue;
        }
        
        for(auto& v : current.listaVizinhos) {
            if(v.getColor() == color::BRANCO) {
                v.setColor(color::CINZA);
                queue.push(v);
            }
        }
    }
}