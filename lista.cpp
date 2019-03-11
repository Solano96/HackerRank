#include <iostream>
#include <list>

using namespace std;

int main(){
    list<int> lista;
    int k;
    
    int n = 0;
    
    cout << "Introducir valor de k: "; 
    cin >> k;
    cout << endl << endl;
    
    cout << "Introducir números (-1 para acabar): ";
    
    do{
         cin >> n;
         lista.push_back(n);
         cout << "  ";
    }while(n != -1);    
    
    list<int>::iterator it;
    
    for(it = lista.begin(); it != lista.end(); it++)
           cout << *it << "  ";
           
    cout << endl << endl;
        int i = 0;
    for(it = lista.begin(); it != lista.end(); it++){
           if(*it > k){
               lista.push_back(*it);
               it = lista.erase(it);      
               it--;    
           }       
           cout << *it << "  ";
    }
    
    for(it = lista.begin(); it != lista.end(); it++)
           cout << *it << "  ";
}

