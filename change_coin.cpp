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

using namespace std;

int main(){
    int N, m;
    cin >> N >> m;
    long long int v[m][N+1];  
    int c[m];
    
    for(int i = 0; i < m; i++)
        cin >> c[i];
        
    for(int j = 0; j <= N; j++)
        if(j%c[0] == 0)
            v[0][j] = 1;
        else
            v[0][j] = 0;  
            
// si es menor que el nuevo valor el número de combinaciones el el mismo que el anterior
// si coincide con el nuevo valor el número de combinaciones es uno más que en el anterior
// si es mayor que el nuevo valor condiciono (con el j-c[i]) a que haya un c[i] en la combinación

    for(int i = 1; i < m; i++){
        for(int j = 0; j <= N; j++){            
            if(j < c[i])
               v[i][j] = v[i-1][j];            
            else if(j == c[i])
               v[i][j] = v[i-1][j]+1;            
            else
               v[i][j] = v[i-1][j]+v[i][j-c[i]];     
        }    
    }
    
    cout << v[m-1][N];
    cin >> m;
}


