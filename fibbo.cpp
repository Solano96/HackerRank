#include <iostream>
#include <cmath>
using namespace std;

int modulo = 1000000007;

void CopiarMatriz2x2(int matriz[][2], int matriz_copia[][2]){
     for(int i = 0; i < 2; i++)
          for(int j = 0; j < 2; j++)
              matriz_copia[i][j] = matriz[i][j];
}

void MultiplicarMatrices2x2(int matriz_1[][2], int matriz_2[][2], int matriz_resultado[][2]){
     for(int i = 0; i < 2; i++)
         for(int j = 0; j < 2; j++){
             matriz_resultado[i][j] = 0;
             
             for(int k = 0; k < 2; k++){
                 matriz_resultado[i][j] += (matriz_1[i][k])*(matriz_2[k][j]);
             }
             matriz_resultado[i][j]%modulo;
         }  
}

void PotenciasMatriz(int matriz[][2], int n){
     
     if(n == 1){
     }    
     else if(n == 2){
          int matriz_1[2][2];
          int matriz_2[2][2];
          
          CopiarMatriz2x2(matriz, matriz_1);
          CopiarMatriz2x2(matriz, matriz_2);
          
          MultiplicarMatrices2x2(matriz_1, matriz_2, matriz);
     }     
     else if(n%2 == 0){
          PotenciasMatriz(matriz, n/2); 
          PotenciasMatriz(matriz, 2);              
     }
     else{
          int matriz_1[2][2];
          int matriz_2[2][2];
          
          CopiarMatriz2x2(matriz, matriz_1);
          CopiarMatriz2x2(matriz, matriz_2);
                  
          PotenciasMatriz(matriz_1, n-1);
          
          MultiplicarMatrices2x2(matriz_1, matriz_2, matriz);
     }
}

int main(){    
    int number_cases;
    int a, b, n;
    // Introducir número de casos
    cin >> number_cases;
    
    // Introducir los valores de cada caso
    for(int i = 0; i < number_cases; i++){
        cin >> a >> b >> n;
        
        if(n == 0) 
             cout << a << endl;
        else if(n == 1)
             cout << b << endl;
        else if(n == 2)
             cout << a+b << endl;
        else{
             int matriz_fibo[2][2] = {0,1,1,1};
             int matriz[2][2] = {a,b,b,a+b}; 
             int matriz_resultado[2][2];
             PotenciasMatriz(matriz_fibo, n-2);
             MultiplicarMatrices2x2(matriz, matriz_fibo ,matriz_resultado);
             cout << matriz_resultado[1][1] << endl;
        }        
    }        
    
    system("pause");
}
