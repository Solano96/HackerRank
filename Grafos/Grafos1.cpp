#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std; // }}}

void CalcularConexos(int i, vector<int> pair[], vector<bool> &marcados, int &c){
    marcados[i] = true;
    for(int k = 0; k < pair[i].size(); k++)
        if(!marcados[pair[i][k]]){
           c++;
           CalcularConexos(pair[i][k], pair, marcados, c);
        }    
}
 
vector<int> CalcularResultado(vector<int> pair[], vector<bool> &marcados, int tam){
    
    vector<int> grupos_conexos;
    
    for(int i = 0; i < tam; i++){
        if(!marcados[i]){
            int conexos = 0;
            conexos++;
            CalcularConexos(i, pair, marcados, conexos);            
            grupos_conexos.push_back(conexos);
        }
    }
     
    return grupos_conexos;
}

int main(){ 
    int N, I;
    cin >> N >> I;
    //vector<vector<int> > pairs(N); ---> con esto va muy lento
    vector<int>pairs[N];
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
    
    long long result = 0;
    
    vector<bool> marcados(N);
    for(int i = 0; i < N; i++)
        marcados[i] = false;
        
    vector<int> grupos_conexos = CalcularResultado(pairs, marcados, N);
    
    int restantes = N;
    for(int i = 0; i < grupos_conexos.size(); i++){
        restantes -= grupos_conexos[i];
        int value = grupos_conexos[i]*restantes;
        result += value;        
    }
    
    cout << result << endl;   
    system("pause");
}





