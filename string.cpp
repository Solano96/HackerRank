#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string cad;
    cin >> cad;
    bool change = true;
    int tam = cad.size();
    while(change){
        change = false;
        for(int i = 0; i < tam; i++){
            if(cad[i] == cad[i+1]){
               cad.erase(i, 2);
               change = true;
               tam = cad.size();
               i++;               
            }
        }
    }
    
    if(cad.empty())
        cout << "Empty String";
    else
        cout << cad;
    return 0;
}
