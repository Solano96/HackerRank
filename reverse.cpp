#include <iostream>
#include <vector>

using namespace std;

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



int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i];    
    }
    
    reverse(v, 0, n-1);
    
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }        
    char l;
    cin >> l;
}


