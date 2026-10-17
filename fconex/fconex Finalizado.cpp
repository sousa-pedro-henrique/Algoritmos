#include <bits/stdc++.h>

using namespace std;
set<int> V;
map<int, set<int>> ida;
map<int, set<int>> volta;

set<int> uniao(set<int> A, set<int> B){ // recebe conjuntos A e B

	for(auto b: B){
		A.insert(b); // insere todos componentes de B em A
	}
	return A; // retorna (A U B)
}

set<int> intersecao(set<int> A, set<int> B){ // recebe A e B
	
	for(auto i = A.begin(); i != A.end();){ // algoritmo de intersecao, claude ajudou um pouco, admito :((
    if(B.find(*i) == B.end()){
        i = A.erase(i);
    } else {
        i++;
    }
}
	
	return A; // retorna A intersecao B
}

set<int> menos(set<int> A, set<int> B){ // recebe dois conjuntos e subtrai B de A

for(auto b : B){
	A.erase(b);
}
	return A; // retorna A - B	
}

set<int> Tp (set<int> rp){ // funcao Gamma+, recebe R+ e seus destinos

set<int> X; // guarda os valores

	for(auto i : rp){ // percorre R+ 
	X.insert(i); // guarda tudo de R+
	for(auto j : ida[i]){ // busca destinos dos componentes de R+
	X.insert(j);
	}
}
	return X; // T+[R+] tem R+ e seus destinos
}

set<int> Tl (set<int> rl){ // funcao Gamma-, recebe R- e suas origens

set<int> X; // guarda os valores

	for(auto i : rl){ // percorre R-
	X.insert(i); // guarda tudo de R-
	for(auto j : volta[i]){ // busca origens dos componentes de R-
	X.insert(j);
	}
}
	return X; // T-[R-] tem R- e suas origens
}

void fconex(int x){ // x recebe S0
	
	set<int> Y; // Y recebe vazio
	set<int> Rp; // R+
	set<int> Rl; // R-
	
	Rp.insert(x); // R+ = R- = x 
	Rl.insert(x);
	
	while(menos(Tp(Rp), Rp).size() > 0){ // Gamma+ - R+ != vazio
		Y = Tp(Rp); // Y recebe T+[R+]
		
		Rp = uniao(Rp, Y); // R+ recebe R+ unido a Y
	}
	while(menos(Tl(Rl), Rl).size() > 0){ //Gamma- - R- != vazio
		Y = Tl(Rl); // Y recebe T-[R-]
		
		Rl = uniao(Rl, Y); // R- recebe R- U Y
		}
	
	Y = intersecao(Rp, Rl); // Y recebe R+ intersecao R-, a CFC pronta
		
	V = menos(V, Y); // V recebe V - Y
	
	cout << "\n{";
	int j=1; // puramente estetico, ignora
	for(auto i : Y){
		cout << i;
		if(j < Y.size()) cout << ", ";
		j++;
	}
		cout << "}\n\n";
		
	if(V.size() > 0) fconex(*V.begin()); // if V != vazio
}

int main(){

int n;
cin >> n;
for(int i=0; i<n; i++){
	int u, v;
	cin >> u >> v;
	V.insert(u);
	V.insert(v);
	ida[u].insert(v);
	volta[v].insert(u);
}
cout << "\nV: ";
int k=1; // puramente estetico
for (auto i : V){
	cout << i;
	if(k< V.size()) cout << ", ";
	k++;
}

cout << "\n\n";

for(auto i : V){
	int k=1; // puramente estetico
	cout << "Gamma+ (" << i << "): ";
	for(auto j : ida[i]){
		cout << j;
		if(k < ida[i].size())cout << ", ";
		k++;
	}
	k=1;
	cout << "\n";
	cout << "Gamma- (" << i << "): ";
	for(auto j : volta[i]){
		cout << j;
		if(k < volta[i].size())cout << ", ";
		k++;
	}
	cout << "\n\n";
}
	cout << "componentes fortemente conexas de V:\n";
		fconex(*V.begin());

	return 0;
}