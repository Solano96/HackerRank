#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <cmath>
#include <time.h>
using namespace std;

int divide(vector<vector<int> > &array, int start, int end){
    int pivot = array[start][0];
    int right = end;
    int left = start;
    vector<int> temp;

    while(left < right){
        while(array[right][0] > pivot)
            right--;
        while(left < right && array[left][0] <= pivot)
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

void quicksort(vector<vector<int> > &array, int start, int end){
    if(start < end){
       int pivot = divide(array, start, end);
       quicksort(array, start, pivot-1);
       quicksort(array, pivot+1, end);   
    }    
}

int divide2(vector<vector<int> > &array, int start, int end){
    int pivot = array[start][1];
    int right = end;
    int left = start;
    vector<int> temp;

    while(left < right){
        while(array[right][1] > pivot)
            right--;
        while(left < right && array[left][1] <= pivot)
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

void quicksort2(vector<vector<int> > &array, int start, int end){
    if(start < end){
       int pivot = divide2(array, start, end);
       quicksort2(array, start, pivot-1);
       quicksort2(array, pivot+1, end);   
    }    
}

int max(vector < vector<int> > track, int init, int fin){
    int max = 0;
    
    for(int i = init; i <= fin; i++){
        if(max < track[i][2])
            max = track[i][2];
    }
    
    return max;
}

void func_aux(long long int &number, int &sup, int &inf, int &init2, int j, vector < vector<int> > track){
    sup = max(track, init2, j);
                        
    if(track[j][1] > inf)
        inf = track[j][1];
    
    int inc =  sup-inf;
    
    if(inc >= 0)
        number -= 1+inc;
        
    init2=j+1;
    inf = sup+1;
}

long long int gridlandMetro(long long int n, long long int m, int k, vector < vector<int> > track) {
    // Complete this function
    quicksort(track, 0, track.size()-1);
    long long int number = m*n;
    int init = 0;
    int init2 = 0;
    int sup = 0;
    int inf = 0;
    
    for(int i = 0; i < track.size()-1; i++){
        if(track[i][0] < track[i+1][0]){
            quicksort2(track, init, i);
            for(int j = init; j <= i; j++){
                if(j != i){
                    if(track[j][1] < track[j+1][1]){
                        func_aux(number, sup, inf, init2, j, track);
                    }
                }
                else{
                    func_aux(number, sup, inf, init2, j, track);
                }
            }
            init2 = init = i+1;            
            sup = 0;
            inf = 0;
        }
    }
    
    quicksort2(track, init, track.size()-1);
    for(int j = init; j <= track.size()-1; j++){
        if(j != track.size()-1){
            if(track[j][1] < track[j+1][1]){
                func_aux(number, sup, inf, init2, j, track);
            }
        }
        else{
            func_aux(number, sup, inf, init2, j, track);
        }
    }
        
    return number;
}

int main() {
    long long int n;
    long long int m;
    int k;
    cin >> n >> m >> k;
    vector< vector<int> > track(k,vector<int>(3));
    for(int track_i = 0;track_i < k;track_i++){
       for(int track_j = 0;track_j < 3;track_j++){
          cin >> track[track_i][track_j];
       }
    }
    long long int result = m*n;
    
    if(k != 0)
        result = gridlandMetro(n, m, k, track);;
    cout << result << endl;
}
