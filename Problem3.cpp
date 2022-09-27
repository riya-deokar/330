#include "Problem3.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateVec(string word){
    vector<int> diff(word.length()); 
    if(word == ""){
        return diff;
    }
    for(int i =0; i<word.size()-1; i++){
        if(int(word[i+1])-int(word[i]) >= 0) {
            diff[i] = int(word[i+1])-int(word[i]);
        } 
        else{
            diff[i] = (int(word[i+1])-int(word[i]))+26;
        }
    }
    return diff; 
} 

void findRotations(string list[], int length){
    int flag[length];
    vector<int> nothing(1,1);
    vector<vector<int>> spaces(length,nothing); 
    for(int i=0; i<length; i++){
        spaces.at(i) = rotateVec(list[i]); 
    }
    for(int j=0; j<length; j++){
        for(int k=j+1; k<length; k++){
            if(spaces.at(j) == spaces.at(k)){
                flag[k] = 1; 
                flag[j] = 1;
                
            }
        }
    }
    for(int i = 0; i < length; i++){
        if(flag[i] == 1)
            cout << list[i] << endl;
    }
}