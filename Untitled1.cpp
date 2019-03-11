#include <iostream>

using namespace std;

int CalculateN(int n, int m){
    if(n%m != 0)
        return (n-(n%m))/m;
    else
        return (n-m)/m;
}

int SumN(int N){
    return ((N+1)*N)/2;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        
        int N1,N2,N3;

        N1 = CalculateN(n,3);
        N2 = CalculateN(n,5);
        N3 = CalculateN(n,15);        
        
        int sum = 3*SumN(N1)+5*SumN(N2)-15*SumN(N3);
        
        cout << sum << endl;        
    }
    return 0;
}









