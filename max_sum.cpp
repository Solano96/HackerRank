#include <iostream>

using namespace std;

struct Nodo{
    long long int dato;
    Nodo * izq;
    Nodo * dech;    
    
    Nodo(long long int dat){
        dato = dat;
        izq = NULL;
        dech = NULL;
    }
};

class Arbol{
    private: 
        Nodo *raiz, *actual;       
    public:
        
        Arbol(){raiz = NULL; actual = NULL;}
        
        void insertar(long long int d){  
            actual = raiz;
            Nodo *padre = NULL;
            
            while(actual != NULL){
                padre = actual;;                
                if(actual->dato >= d)
                    actual = actual->izq;
                else
                    actual = actual->dech;  
            }
            
            if(padre == NULL)
                raiz = new Nodo(d);   
            else{
                if(padre->dato >= d)
                    padre->izq = new Nodo(d);
                else
                    padre->dech = new Nodo(d);    
            }            
        }    
        
        void borrar(long long int d){
            actual = raiz;
            Nodo *padre = NULL;
            Nodo *nodo;
            long long int aux;            
            
            while(actual != NULL){
                if(actual->dato == d){
                       if(actual->izq == NULL && actual->dech == NULL){
                            if(padre)
                                if(padre->izq == actual)
                                    padre->izq = NULL;
                                else if(padre->dech == actual)
                                    padre->dech = NULL;  
                            delete actual;  
                            actual = NULL; 
                            return;                                       
                       }    
                       else{
                           padre = actual;
                           if(actual->izq != NULL){
                              nodo = actual->izq;                                                    
                              while(nodo->dech != NULL){
                                    padre = nodo;
                                    nodo = nodo->dech;
                              }                                
                           }
                           else{
                              nodo = actual->dech;
                              while(nodo->izq != NULL){
                                    padre = nodo;
                                    nodo = nodo->izq;
                              }
                           }                            
                           aux = nodo->dato;
                           nodo->dato = actual->dato;
                           actual->dato = aux;
                           actual = nodo;
                       }
                }
                else{
                    padre = actual;
                    if(actual->dato > d)
                        actual = actual->izq;
                    else
                        actual = actual->dech;       
                }             
            }           
        }
        
        long long int inmediatoSuperior(long long int d){
            long long int min = -1;
            actual = raiz;
            bool seguir = true;
            
            while(seguir){
                if(actual->dato > d && actual->dato < min)
                    min = actual->dato;
                
                if(min == -1 && actual->dato > d)
                    min = actual->dato;
                    
                if(actual->dato > d){
                    if(actual->izq != NULL)
                        actual = actual->izq;
                    else 
                        seguir = false;    
                }
                else{
                    if(actual->dech != NULL)
                        actual = actual->dech;
                    else
                        seguir = false;    
                }                       
            }            
            return min;    
        }
        
        void InOrden(Nodo *nodo=NULL, bool r=true){
           if(r) nodo = raiz;
           if(nodo->izq) InOrden(nodo->izq, false);
           cout << nodo->dato << ", ";
           if(nodo->dech) InOrden(nodo->dech, false);
        }
        
        void Insertar(long long int *vect, int begin, int end){
            
            if(begin == end){
                insertar(vect[begin]);    
            }
            else if(end-begin == 1){
                insertar(vect[begin]);
                insertar(vect[end]);
            }
            else{
                int mitad = (begin+end)/2;
                insertar(vect[mitad]);                
                Insertar(vect, begin, mitad-1);
                Insertar(vect, mitad+1, end);
            }           
        }
        
};

int main(){
    long long int q, n, m;
    
    
    cin >> q;
    
    for(long long int k = 0; k < q; k++){
        Arbol sum_ordenadas;
        cin >> n >> m;
        
        long long int array[n];
        long long int sum_parcial[n];
        long long int max_sum;
        
        cin >> array[0];
        sum_parcial[0] = (m + array[0])%m;
        max_sum = sum_parcial[0];
        
        for(int i = 1; i < n; i++){
            cin >> array[i];
            sum_parcial[i] = (m + array[i]%m + sum_parcial[i-1]%m)%m;
            
            if(sum_parcial[i] > max_sum)
                max_sum = sum_parcial[i];
        }
        
        sum_ordenadas.Insertar(sum_parcial, 0, n-1);
                
        for(int i = n-1; i > 0; i--){
            long long int s1 = sum_parcial[i];
            sum_ordenadas.borrar(s1);        
            long long int s2 = sum_ordenadas.inmediatoSuperior(s1);
            if(s2 != -1){
                long long int sum = (m + s1 - s2)%m;
                
                if(sum > max_sum)
                   max_sum = sum;  
            }
            
        }        
        
        cout << max_sum << endl;            
    }
    cin >> m;
}
