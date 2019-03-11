#include <iostream>

using namespace std;

int main(){
    
    for(int i = 1; i <= 14; i++){
        for(int j = i; j <= 14; j++){
            if((i*j)%14 == 1){
                cout << i << " * " << j << " = " << i*j << endl;    
            }    
        }    
    }    
    cout << endl;
    int k = 3;
    for(int i = 1; i <= 6;i++){
        cout << k%14 << " ";
        k = k*3;
    }
    cout << endl << endl ;
    
    k = 5;
    for(int i = 1; i <= 6;i++){
        cout << k%14 << " ";
        k = k*5;
    }
    cout << endl << endl;
    
    k = 9;
    for(int i = 1; i <= 6;i++){
        cout << k%14 << " ";
        k = k*9;
    }
    cout << endl << endl ;
    
    k = 11;
    for(int i = 1; i <= 6;i++){
        cout << k%14 << " ";
        k = k*11;
    }
    cout << endl << endl ;
    
    k = 13;
    for(int i = 1; i <= 6;i++){
        cout << k%14 << " ";
        k = k*13;
    }
    cout << endl << endl ;
    
    char l;
    cin >> l;
}












