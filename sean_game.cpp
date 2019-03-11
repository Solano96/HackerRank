#include <iostream>

using namespace std;

int main(){
    int number_cases, n;
    int **matriz;
    
    cin >> number_cases;
    
    for(int w = 0; w < number_cases; w++){
        cin >> n;
        
        matriz = new int*[2*n];
        
        for(int i = 0; i < 2*n; i++)
            matriz[i] = new int[2*n];
        
        for(int i = 0; i < 2*n; i++)
            for(int j = 0; j < 2*n; j++)
                cin >> matriz[i][j];
                
        int sum_total = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int max = matriz[i][j];                
                if(matriz[i][2*n-1-j]>max) max = matriz[i][2*n-1-j];
                if(matriz[2*n-1-i][j]>max) max = matriz[2*n-i-1][j];
                if(matriz[2*n-1-i][2*n-1-j]>max) max = matriz[2*n-1-i][2*n-1-j];
                sum_total+=max;
            }      
        }        
        
        for(int i = 0; i < 2*n; i++)
            delete[] matriz[i];
        delete[] matriz;    
        
        cout << sum_total << endl;
    } 
    //system("pause");
}
