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
    int T, N;
    cin >> T;
    
    for(int w = 0; w < T; w++){
        cin >> N;
        int v[N];
        int max = 0;
        
        for(int k = 0; k < N; k++){
            cin >> v[k];
            if(v[k]>max) max = v[k];
        }
         
        bool numeros[max+1];
        
        for(int i = 0; i <= max; i++)
            numeros[i] = false;
            
        vector<int> c;
           
        for(int k = 0; k < N; k++)
            numeros[v[k]] = true;            
        
        for(int k = 0; k <= max; k++)
            if(numeros[k]) 
                c.push_back(k);
                
        int op = 0;
        
        for(int i = 1; i < c.size(); i++){
            int min = 9999999;
            for(int j = 0; j < i; j++){
                int aux = c[i]-c[j];
                int operaciones = 0, num = 0; 
                    
                while(num != aux){
                    if(num+5 <= aux)
                        num +=5;  
                    else if(num+2 <= aux)
                        num+=2;
                    else
                        num++;
                        
                    operaciones++;
                } 
                if(operaciones < min)
                    min = operaciones; 
            }     
            op += min;     
        }    
        cout << op << endl;
    }
}



