#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int divide(vector<string> &array, int start, int end){
    int pivot = array[start].size();
    int right = end;
    int left = start;
    string temp;

    while(left < right){
        while(array[right].size() > pivot)
            right--;
        while(left < right && array[left].size() <= pivot)
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

void quicksort(vector<string > &array, int start, int end){
    if(start < end){
       int pivot = divide(array, start, end);
       quicksort(array, start, pivot-1);
       quicksort(array, pivot+1, end);   
    }    
}

vector <string> bigSorting(vector <string> arr) {
    // Complete this function
    quicksort(arr, 0, arr.size()-1);
    int init = 0;
    
    for(int i = 0; i < arr.size(); i++){
        if(i != arr.size()-1){
            if(arr[i].size() < arr[i+1].size()){
                sort(arr.begin()+init, arr.begin()+i+1);
                init = i+1;
            }
        }
        else{
            sort(arr.begin()+init, arr.begin()+i);
        }
    }
    
    return arr;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    vector <string> result = bigSorting(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
