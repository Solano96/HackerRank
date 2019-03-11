#include <iostream>
#include <vector>

using namespace std;


int main(){
    unsigned long long int t, n, k, b;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        cin >> n >> k >> b;        
        
        unsigned long long int cota_inferior = 0, cota_superior = 0;
        
        for(unsigned long long int j = 1; j <= b; j++){
            cota_inferior+=j;
            cota_superior+=(k+1-j);
        }
        
        if(n >= cota_inferior && n <= cota_superior){
            unsigned long long int avance = (n-cota_inferior)/b;
            unsigned long long int arreglo = (n-cota_inferior)%b;
            
            for(unsigned long long int j = avance+1; j < avance+1+(b-arreglo); j++)
                if(arreglo == 0 && j == avance+b)
                    cout << j << endl;
                else 
                    cout << j << " ";
            
            for(unsigned long long int j = avance+2+(b-arreglo); j < avance+1+b; j++)
                cout << j << " ";
                
            if(arreglo != 0)
                cout << avance+1+b << endl;
        }
        else
            cout << -1 << endl;   
    }    
    system("pause");
}


