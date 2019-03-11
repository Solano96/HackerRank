#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

vector<string> split_string(string);

struct node{
    int value;
    int height;
    node *left, *right, *father;    
};

/*
 * Complete the function below.
 */
vector<int> heightAndTotalHeight(vector<int> arr) {
    // Write your code here.
    node *root; 
    root->value = arr[0];
    root->height = 0;
    root->left = root->right = root->father = NULL;
    int max = 0;
    int sum = 0;
    cout << "llega" << endl;
    for(int i = 1; i < arr.size(); i++){
        bool seguir = true;
        node *act = root;
        while(seguir){

            if(arr[i] < act->value){
                if(act->left == NULL){
                    node *n;
                    n->value = arr[i];
                    n->left = n->right = NULL;
                    n->father = act;
                    act->left = n;
                    n->height = 0;
                    int k = 1;
                    while(n->father != NULL){
                        if(n->father->height < k){
                            n->father->height = k;
                            sum++;
                        }
                        k++;
                    }
                    
                    seguir = false;
                }
                else{
                    act = act->left;
                }
            }
            else if(arr[i] > act->value){
                if(act->right == NULL){
                    node *n;
                    n->value = arr[i];
                    n->left = n->right = NULL;
                    n->father = act;
                    act->right = n;
                    int k = 1;
                    while(n->father != NULL){
                        if(n->father->height < k){
                            n->father->height = k;
                            sum++;
                        }
                        k++;
                    }
                    seguir = false;
                }
                else{
                    act = act->right;
                }
            }
            else{
                seguir = false;
            }
        }
    }
    vector<int> s;
    s.push_back(root->height);
    s.push_back(sum);
    return s;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_size;
    cin >> arr_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_str_temp;
    getline(cin, arr_str_temp);

    vector<string> arr_str = split_string(arr_str_temp);

    vector<int> arr(arr_size);
    for (int arr_i = 0; arr_i < arr_size; arr_i++) {
        int arr_item = stoi(arr_str[arr_i]);

        arr[arr_i] = arr_item;
    }

    vector<int> result = heightAndTotalHeight(arr);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

