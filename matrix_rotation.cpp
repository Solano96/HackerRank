#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int m, n, r;
    cin >> m >> n >> r;
    
    int matrix_1[m][n];
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> matrix_1[i][j];
        
    bool trasponer = false;
    
    vector<vector<int> > matrix;
    
    if(m <= n){
       for(int i = 0; i < m; i++){
           vector<int> aux;
           for(int j = 0; j < n; j++)
               aux.push_back(matrix_1[i][j]);               
           matrix.push_back(aux);
       }
    }
    else{
        for(int j = 0; j < n; j++){
           vector<int> aux;
           for(int i = 0; i < m; i++)
               aux.push_back(matrix_1[i][j]);               
           matrix.push_back(aux);
        }
        trasponer = true;
        int aux = m;
        m = n;
        n = aux;
    }
    
    vector<int> v[m/2];
    
    for(int k = 0; k < m/2; k++){
        for(int i = k; i < n-k; i++){
            v[k].push_back(matrix[k][i]);
        }
            
        for(int i = k+1; i < m-k-1; i++){
            v[k].push_back(matrix[i][n-k-1]); 
        }
            
         for(int i = n-k-1; i >= k; i--){
            v[k].push_back(matrix[m-k-1][i]);
        }
            
         for(int i = m-k-2; i >= k+1; i--){
            v[k].push_back(matrix[i][k]);
        }
    }
    
    for(int k = 0; k < m/2; k++){
        int rotate = r%v[k].size();
        int v_aux[v[k].size()];
        for(int i = 0; i < v[k].size(); i++){ 
            if(trasponer)               
                v_aux[i] = v[k][(i+v[k].size()-rotate)%v[k].size()];  
            else
                v_aux[i] = v[k][(i+rotate)%v[k].size()];                
        }
        
        for(int i = 0; i < v[k].size(); i++)
            v[k][i] = v_aux[i];
    }
    
    for(int k = 0; k < m/2; k++){
        int j = 0;
        for(int i = k; i < n-k; i++){
            matrix[k][i] = v[k][j];
            j++;
        }
        
            
        for(int i = k+1; i < m-k-1; i++){
            matrix[i][n-k-1] = v[k][j]; 
            j++; 
        } 
            
         for(int i = n-k-1; i >= k; i--){
            matrix[m-k-1][i] = v[k][j];
            j++;
        }
            
         for(int i = m-k-2; i >= k+1; i--){
            matrix[i][k] = v[k][j];
            j++;
        }
    }

    if(!trasponer)
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;      
      }
    else
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cout << matrix[j][i] << " ";
        cout << endl;      
      }
    
    return 0;
}
















