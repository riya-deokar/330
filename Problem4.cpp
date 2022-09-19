#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool isJumbled(char* str1, char* str2){
    if(strlen(str1) != strlen(str2)){
        return false;
    }
    
    int z = 0; 
    vector<int> repeat; 
    
    for(int i = 0; i<strlen(str1); i++){
        for(int j = 0; j<strlen(str2); j++){
            for(int k = 0; k < repeat.size() ; k++){
                    if(j == repeat[k]){
                        j++; 
                    }
            }
            if(str1[i]==str2[j]){
                repeat.push_back(j); 
                sort(repeat.begin(), repeat.end()); 
                z++;
                break;
            }
        }
    }
    if(z==strlen(str1)){
        return true; 
    }
    return false;
}

int main(int argc, char**argv){
    if(isJumbled(argv[1], argv[2]))
        cout << "jumbled" << endl; 
    else
        cout << "not jumbled" << endl; 
    return 0; 
}