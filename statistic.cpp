#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip> 
#include <algorithm>
using namespace std;

struct repetidos{    
    int numero;
    int apariciones;    
};

int divide(int *array, int start, int end){
    
    int pivot = array[start];
    int right = end;
    int left = start;
    int temp;
    
    while(left < right){
        while(array[right] > pivot)
            right--;
        while(left < right && array[left] <= pivot)
            left++;
            
        if(left < right){
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }             
    }
    
    temp = array[start];
    array[start] = array[right];
    array[right] = temp;
    
    return right;
}

void quicksort(int * array, int start, int end){
    if(start < end){
       int pivot = divide(array, start, end);
       quicksort(array, start, pivot-1);
       quicksort(array, pivot+1, end);   
    }    
}

int main() {
    int N;    
    cin >> N;
    int array[N];
    double media = 0, mediana, moda = -1;
    
    // Introucir array y clacular media
    for(int i = 0; i < N; i++){
        cin >> array[i];
        media += array[i];
    }    
    media /= 1.0*N;
        
    // Ordenamos el array
    quicksort(array, 0, N-1);
    
    // Calculamos la mediana
    if(N%2 == 0)
        mediana = 1.0*(array[N/2]+array[N/2-1])/2;  
    else
        mediana = 1.0*array[N/2];
    
    // Calculamos el número de apariciones de cada número
    vector<repetidos> v;    
    repetidos r;
    r.numero = array[0];
    r.apariciones = 1;
    
    for(int i = 1; i < N; i++){
        if(array[i] != r.numero){
            v.push_back(r);
            r.numero = array[i];
            r.apariciones = 1;    
        }
        else
            r.apariciones++;
    }
    
    v.push_back(r);
    
    int max = v[0].apariciones;
    
    for(int i = 0; i < v.size(); i++)
        if(v[i].apariciones > max)
            max = v[i].apariciones;    
    
    
    for(int i = 0; i < v.size() && moda == -1; i++)
        if(v[i].apariciones == max)
            moda = v[i].numero;
    
    cout << fixed << setprecision(1) << media << endl << mediana << endl << setprecision(0) << moda;
    
    system("pause");
}





