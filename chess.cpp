#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Pieza{
    char pieza;
    int x, y;
    
    Pieza(char p, char _x, int y){
        pieza = p;
        x = _x-'A';
        y = _y;
    }
}

bool PuedeGanar(Pieza blancas[], int pb, Pieza negras[], int pn, int m, int turno){
     bool puede_ganar = false;
     Pieza queen_negra;
     
     for(int i = 0; i < pn; i++)
         if(negras[i].pieza == 'Q')
            queen_negra = negras[i];
     
     if(turno == 0){
          
     }
      
}

int main() {
    int g, w, b, m;
    
    cin >> g;
    
    for(int k = 0; k < g; k++){
        cin >> w >> b >> m;
        
        Pieza blancas[w], negras[b];
        
        for(int l = 0; l < w; l++){
            char t, c;
            int r;
            cin >> t >> c >> r;
            blancas[l] = Pieza(t,c,r);
        }
        
        for(int l = 0; l < b; l++){            
            char t, c;
            int r;
            cin >> t >> c >> r;
            negras[l] = Pieza(t,c,r);
        }
        
        
        
    }
    
    return 0;
}









