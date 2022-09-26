#include "Problem3.h"
#include <iostream>
#include <string>
#include <vector>

vector<int> rotateVec(string word){
    vector<int> diff(word.length()); 
    for(int i =0; i<word.size()-1; i++){
        if(int(word[i+1])-int(word.at(i)) >= 0) {
            diff.at(i) = int(word[i+1])-int(word.at(i));
        } 
        else{
            diff.at(i) = (int(word[i+1])-int(word.at(i)))+26;
        }
    }
    return diff; 
} 

void findRotations(string list[], int length){
    int flag[length];
    vector<int> nothing(1,1);
    vector<vector<int>> spaces(length,nothing); 
    bool flag = false; 
    for(int i=0; i<length; i++){
        spaces.at(i) = rotateVec(list[i]); 
    }
    for(int j=0; j<length-1; j++){
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