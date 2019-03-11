#include <iostream>
#include <string.h>

using namespace std;

string texto =       "abcdefghijklmnopqrstuvwxyz";
string texto_reves = "zyxwvutsrqponmlkjihgfedcba";

void cifrar(string text, string &cifrado){     
     cifrado = "";     
     for(int i = 0; i < text.size(); i++){
         int n = text[i] - 'a';
         cifrado += texto_reves[n];
     }          
}

void cifrar2(string text, string &cifrado){
     cifrado = "";
     for(int i = 0; i < text.size(); i++){
             int n = text[i]+i;
             n = n%26;
             cifrado += texto[n];        
     }     
}

void descifrar(string text, string &descifrado){     
     descifrado = "";     
     for(int i = 0; i < text.size(); i++){
             int n = text[i]-'a';
             n+=7-i;
             n%=26;
             descifrado += texto[n];        
     }
}

int main(){
    string clave, cifrado, descifrado;
    
    cout << "Introducir clave para cifrar: ";    
    cin >> clave;
    cout << endl << endl;
    
    cifrar2(clave, cifrado);
    
    cout << "Tu clave cifrada es: " << cifrado << endl;
    
    descifrar(cifrado, descifrado);
    
    cout << "Tu clave descifrada es: " << descifrado << endl;
    
    char l;
    cin >> l;

}


