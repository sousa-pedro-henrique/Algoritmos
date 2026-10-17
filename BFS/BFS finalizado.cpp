#include <bits/stdc++.h>
using namespace std;

map<int, int> id; // indices de cada u em V
map<int, set<int>>  Adj; 	//vizinhos , Adjacentes de cada vertice
vector<int> v2;

void BFS(set<int> V, int s){
	
	char cor[V.size()];		// flag de visita de cada vertice
	int d[V.size()]; 			// distancia de cada u ate a origem da bsuca 
	int* Pai[V.size()];			// vertice pai de cada vertice u
	queue<int> Q;				// fila Q
	
	for(int u=0; u<V.size(); u++){
		cor[u] = 'B'; 
		d[u] = 9999;
		Pai[u] = nullptr;
	}
	
	cor[id[s]] = 'C'; // cor de s eh cinza
	d[id[s]] =0 ;	
	Q.push(s);
	
	while(Q.size()>0){			// enquanto Q != vazio
		int u = Q.front();
		Q.pop(); // dequeue Q
	
		for(auto v : Adj[u]){
			
			if(cor[id[v]] == 'B'){
				
				cor[id[v]] = 'C'; 	// cor de v eh cinza
				
				d[id[v]] = d[id[u]]+1; // distancia de v ate s eh u ate s +1
				
				Pai[id[v]] = &v2[id[u]]; // Pai de v eh u

				Q.push(v);	// v entra na fila
				
			}
		}
		cor[id[u]] = 'P'; 	// cor de u eh preto
		
	}// fim da BFS
	
	cout << "\nV: ";
	for(auto i : V){ // imprime todas os vertices
		cout << i << " ";
	}
	cout << "\n\nC: ";
	for(auto i : cor){ // imprime todas as cores
		cout << i << " ";
	}
cout << "\nD: ";
	for(auto i : d){	// imprime todas as distancias
		cout << i << " ";
	}
cout << "\nP: ";
	for(auto i : Pai){ // imprime todos os pais
	
		if(i == nullptr){	// evita imprimir conteudo de nullptr
			cout << "N ";
			continue;
		}
		cout << *i << " ";
	}
}

int main(){

set<int> V; 				// vertices


int s;		  			    // origem da busca


	int n; 				    // numero de arestas
	cin >> n;
	
	while(n--){ 	// construcao do grafo
		
		int u, v; 	// par de vertices de cada aresta
		cin >> u >> v;
		Adj[u].insert(v);
		Adj[v].insert(u);
		V.insert(u);
		V.insert(v);
	}
	cout << "\n";

cin >> s;

int i=0;
for(auto u : V){
	id[u] = i;
	i++;
	v2.push_back(u);
}

	BFS(V, s);

	return 0;
}