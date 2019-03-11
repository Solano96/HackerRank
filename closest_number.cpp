#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int number_cases;
    double a, b, x;
    // Introducir número de casos
    cin >> number_cases;
    
    // Introducir los valores de cada caso
    for(int i = 0; i < number_cases; i++){
        cin >> a >> b >> x;
        
        int resto = (int)pow(a,b)%(int)x;
        
        if(resto <= x/2)
           cout << (int)(pow(a,b)-resto) << endl;
        else
           cout << (int)(pow(a,b)+(x-resto)) << endl;
    }
    
    system("pause");
}
