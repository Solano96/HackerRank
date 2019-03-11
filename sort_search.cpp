#include <cmath>
#include <cstdio>
#include <vector>
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

struct p{
    int l, r;
};

int main() {
    
    LARGE_INTEGER t_ini, t_fin;
    double secs_ejecucion;
        
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q, k, l, r;
    bool seguir = true;
    int hasta = 0;
    
    cin >> n >> q >> k;
    
    vector<long long int> A(n);
    vector<p> query(q);
    vector<int> valores(n);
    
    for(int i = 0; i < n; i++)
        cin >> A[i];
    
    for(int i = 0; i < q; i++){
        cin >> query[i].l >> query[i].r;        
    }
    
    QueryPerformanceCounter(&t_ini);
    
    for(int i = 0; i < n; i++)
        valores[i] = 0;

    for(int i = q-1; i >= 0 && seguir; i--){
        if(query[i].l <= k && k <= query[i].r){
            seguir = false;
            hasta = i;
        }
    }
    
    for(int i = 0; i <= hasta; i++){
        for(int j = query[i].l; j <= query[i].r; j++){
            valores[j]++;    
        }    
    }
    
    vector<bool> ordenar(hasta+1);
    
    for(int i = 0; i <= hasta; i++){
        if(query[i].l > k || k > query[i].r){
            if(valores[query[i].l]==1 && valores[query[i].r]==1)
               ordenar[i] = false;
            else
               ordenar[i] = true;    
        }    
        else
            ordenar[i] = true;
    }
    
    QueryPerformanceCounter(&t_ini);
    for(int i = 0; i <= hasta; i++)
        if(ordenar[i])
            sort(A.begin()+query[i].l, A.begin()+query[i].r+1);
    
    QueryPerformanceCounter(&t_fin);   
    secs_ejecucion = performancecounter_diff(&t_fin, &t_ini);
    cout << "Tiempo de ejecución: " << secs_ejecucion << " segundos." << endl;
    
    cout << A[k];
    
    system("pause");
}
