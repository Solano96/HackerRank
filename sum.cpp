#include <iostream>
#include <cmath>
using namespace std;

int powerSum2(int X, int N, int n) {
    // Complete this function
    if(X == 0){
        return 1;
    }
    else if(X < 0){
        return 0;
    }
    else{
        int total = 0;
        for(int i = n; i <= pow(X,1.0/N)+1; i++){
            long long int p = 1;
            for(int j = 1; j <= N; j++)
                p*=i;            
            total += powerSum2(X-p, N, i+1);
        }  
        return total;
    }    
}

int powerSum(int X, int N){
    return powerSum2(X, N, 1);
}

int main() {
    int X;
    cin >> X;
    int N;
    cin >> N;
    int result = powerSum(X, N);
    cout << result << endl;
    system("pause");
}
