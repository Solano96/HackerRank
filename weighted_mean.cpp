#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >> N;
    int X[N], w[N];
    
    for(int i = 0; i < N; i++)
        cin >> X[i];
    
    for(int i = 0; i < N; i++)
        cin >> w[i];
    
    double wm = 0;
    int weight = 0;
    
    for(int i = 0; i < N; i++){
        wm += X[i]*w[i];
        weight += w[i];
    }
    
    wm /= 1.0*weight;
    wm *= 10;
    wm = round(wm);
    wm /= 10; 
    
    cout <<  wm;
    cin >> N;
}
