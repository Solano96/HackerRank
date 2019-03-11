#include <iostream>
#include <vector>
#include <string>

using namespace std;

void isSorted(vector <int> arr, string m, int n1, int n2){    
    bool is_sorted = true;
    for(int i = 0; i < arr.size()-1 && is_sorted; i++){
        if(arr[i] > arr[i+1])
            is_sorted = false;   
    }
    
    if(is_sorted){
        cout << "yes" << endl;
        cout << m << " " << n1 << " " << n2 << endl;
    } 
    else{
        cout << "no";
    }
}

void swap(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

void reverse(vector <int> &arr, int from, int to){
    for(int i = from; i <= (to+from)/2; i++){
        swap(arr[i], arr[to+from-i]);
    }
}

void almostSorted(vector <int> arr) {
    // Complete this function    
    // reverse
    bool follow = true;
    for(int i = 0; i < arr.size()-1 && follow; i++)
        if(arr[i] > arr[i+1])
            for(int j = i+1; j < arr.size() && follow; j++){
                if(arr[j] < arr[j+1] || j == arr.size()-1){
                    if(j-i > 1){
                        reverse(arr, i, j);                            
                        isSorted(arr, "reverse", i+1, j+1);  
                        return;    
                    }         
                    else
                        follow = false;       
                }
            }
    
    //swap
    for(int i = 0; i < arr.size()-1; i++)
        if(arr[i] > arr[i+1])
            for(int j = i+1; j < arr.size(); j++)
                if(j == arr.size()-1){                         
                    swap(arr[i], arr[j]);
                    isSorted(arr, "swap", i+1, j+1);
                    return;
                }
                else if(arr[j] > arr[j+1]){                     
                    swap(arr[i], arr[j+1]);
                    isSorted(arr, "swap", i+1, j+2);
                    return;
                }
                else if(j == i+1 && arr[i] > arr[j] && arr[i] < arr[j+1]){                     
                    swap(arr[i], arr[j]);
                    isSorted(arr, "swap", i+1, j+1);
                    return;
                }
    
    cout << "no";
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    almostSorted(arr);
    system("pause");
}

