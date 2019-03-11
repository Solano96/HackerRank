#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string special_characters = "!@#$%^&*()-+";    
    set<char> sc;
    
    for(int i = 0; i < special_characters.size(); i++)
        sc.insert(special_characters[i]);
    
    vector<bool> criteria(4, false);
    
    for(int i = 0; i < n; i++){
        if(isdigit(password[i])) criteria[0] = true;
        if(islower(password[i])) criteria[1] = true;
        if(isupper(password[i])) criteria[2] = true;
        if(sc.find(password[i]) != sc.end()) criteria[3] = true;
    }
    
    int c = 0;    
    for(int i = 0; i < 4; i++)
        if(!criteria[i])
            c++;
    
    if(n >= 6 || 6-n <= c)
        return c;
    else
        return 6-n;
}

int main() {
    int n;
    cin >> n;
    string password;
    cin >> password;
    int answer = minimumNumber(n, password);
    cout << answer << endl;
    return 0;
}
