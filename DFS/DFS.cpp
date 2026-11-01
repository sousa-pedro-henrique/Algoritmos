#include <bits/stdc++.h>

using namespace std;
set<char> V;
map<char, set<char>> Adj;
int tempo=0;

    static map<char, char> Pred;
    static map<char, string> Cor;
    static map<char, int> Abre;
    static map<char, int> Fecha;

/*
ENTRADA DO GRAFO DA LISTA:
6
AB
B
D
D
F
A
C
C
E
E
F

 */

void DFSvisit(char u);
void DFS();

int main() {

    int a;
    cin >> a;

    while (a--) {
        char u, v;
        cin >> u >> v;
        V.insert(u);
        V.insert(v);
        Adj[u].insert(v);
    }

    DFS();
    return 0;
}

void DFSvisit(char u) {
    Cor[u] = "Cinza";
    tempo++;
    Abre[u] = tempo;

    for (char v : Adj[u]) {
        if (Cor[v] == "Branco") {
            Pred[v] = u;
            DFSvisit(v);
        }
    }
    Cor[u] = "Preto";
    tempo++;
    Fecha[u] = tempo;
}

void DFS() {

    for (char i : V) {
        Pred[i] = '#';
        Cor[i] = "Branco";
        Abre[i] = 0;
        Fecha[i] = 0;
    }

    for (char u : V) {
        if (Cor[u] == "Branco") {
            DFSvisit(u);
        }
    }
    cout << setw(10) << right << "Vertice | "<< setw(7) << right << "Pred | "<< setw(6) << right << "  Abre | "<< setw(7) << right << "  Fecha |" << "\n";
    for (char u : V) {
        cout << setw(4) << right << u << "  |" << setw(7) << right << Pred[u] << "  |" << setw(6) << right << Abre[u] << "  |"<< setw(7) << right << Fecha[u] << "  |" << "\n";

    }
    cout << "\n";
}