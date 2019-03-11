#include <iostream>
#include <vector>

using namespace std;


int main(){
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> q(n);
        for(int q_i = 0;q_i < n;q_i++){
           cin >> q[q_i];
        }
                
        bool posible = true;
        int sobornos = 0;
        
        // Si alguien esta adelantado más de dos posiciones ha hecho 
        // más de tres sobornos
        for(int i = 0; i < n; i++)
            if(q[i] > i+3)
                posible = false;
                
                
        if(posible){
            for(int i = 0; i < n; i++){
                // Sumamos tantas posiciones como este adelantado (3>pos)
                if(q[i] > i+1)
                    sobornos += q[i]-1-i;
                // Sobornos después de haber sido sobornado
                if(q[i] <= i+1 && i+2 == q[i-1] && i > 0){
                   int hasta = i+2-q[i];
                   bool seguir = true;
                   for(int k = i-1; k > i-hasta && seguir; k--){
                        if(k < 1) 
                            seguir = false;
                        if(q[k]-q[k-1]!=1 && seguir)
                            seguir = false;
                    }
                    if(seguir)
                        sobornos++;
                }
            }    
        }
        
        if(posible) 
            cout << sobornos << endl;
        else
            cout << "Too chaotic" << endl;        
    }
    system("pause");
}








