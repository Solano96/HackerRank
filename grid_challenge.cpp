#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int divide(char *array, int start, int end){
    
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

void quicksort(char * array, int start, int end){
    if(start < end){
       int pivot = divide(array, start, end);
       quicksort(array, start, pivot-1);
       quicksort(array, pivot+1, end);   
    }    
}


int main() {
    int T, N;
    
    cin >> T;
    
    for(int k = 0; k < T; k++){
        cin >> N;
        char grid[N][N];
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> grid[i][j];
                
        for(int i = 0; i < N; i++)
            quicksort(grid[i], 0, N-1);
            
        bool posible = true;
        
        for(int j = 0; j < N && posible; j++){
            for(int i = 0; i < N-1 && posible; i++){
                if(grid[i][j] > grid[i+1][j])
                    posible = false;
            }
        }
        
        if(posible)
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
        
    }
    
    return 0;
}
