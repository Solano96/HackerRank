#include <map>
#include <set>
#include <list>
#include <ctime>
#include <string>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <cmath>
#include <time.h>

using namespace std;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int function(string s, int left, int right){
    set<string> c;
    int tam = 1+right-left;
    string cad = s.substr(left, tam);
    bool alphabet[26] = {false};
    
    for(int i = 1; i <= tam; i++){
        for(int j = 0; j <= tam-i; j++){
            if(i == 1 && !alphabet[cad[j]-'a']){
                c.insert(cad.substr(j,i));
                alphabet[cad[j]-'a'] = true;
            }
            else if(cad.substr(j,i) != cad.substr(j+1,i))
                c.insert(cad.substr(j,i));
        }
    }
    return c.size();
}

int function2(string s, int left, int right){
    int tam = 1+right-left;
    string cad = s.substr(left, tam);
    int n = 0;
    for(int i = 1; i <= tam; i++){
        set<string> c;
        for(int j = 0; j <= tam-i; j++){
                c.insert(cad.substr(j,i));
        }
        n+=c.size();
    }
    return n;
}

int main(){
    LARGE_INTEGER t_ini, t_fin;
    double secs_ejecucion;
    int n;
    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    QueryPerformanceCounter(&t_ini);

    for(int a0 = 0; a0 < q; a0++){
        int left;
        int right;
        cin >> left >> right;
        // your code goes here
        cout << function2(s, left, right) << endl;
    }
    
    QueryPerformanceCounter(&t_fin);   
    secs_ejecucion = performancecounter_diff(&t_fin, &t_ini);
    cout << "Tiempo de ejecución: " << secs_ejecucion << " segundos." << endl;
    return 0;
}




