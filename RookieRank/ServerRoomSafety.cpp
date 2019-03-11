#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string checkAll(int n, vector <int> height, vector <int> position) {
    // Complete this function
    bool right = true;
    bool left = true;
    
    for(int i = n-1; i > 0 && left; i--){
        bool caido = false;
        int j = i-1;
        
        while(!caido && j >= 0){
            if(position[j]+height[j] >= position[i])
                caido = true;
            j--;
        }
                
        if(!caido)
            left = false;
    }
    
    for(int i = 0; i < n-1 && right; i++){
        bool caido = false;
        int j = i+1;
        
        while(!caido && j < n){
            if(position[j]-height[j] <= position[i])
                caido = true;
            j++;
        }
        
        if(!caido)
            right = false;
    }
    
    if(right && left) return "BOTH";
    else if(right)    return "RIGHT";
    else if(left)     return "LEFT";
    else              return "NONE";
}

int main() {
    int n;
    cin >> n;
    vector<int> position(n);
    for(int position_i = 0; position_i < n; position_i++){
       cin >> position[position_i];
    }
    vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
    }
    string ret = checkAll(n, height, position);
    cout << ret << endl;
    return 0;
}
