#include <iostream>
#include "Problem5.h"

void oneRow(vector<string> words){
    vector<string> keys; 
    keys.push_back("qQwWeErRtTyYuUiIoOpP");
    keys.push_back("aAsSdDfFgGhHjJkKlL");
    keys.push_back("zZxXcCvVbBnNmM");

    for(int i = 0; i<words.size(); i++){
        int one, two=0, three=0;
        for(int j=0; j<words[i].size(); j++){ 
            char c = words[i][j];
            for(int k=0; k<keys.size(); k++){
                for(int l = 0; l<keys[k].size(); l++){
                    if(c==keys[k][l]){
                        if(k==0)
                            one++; 
                        else if(k==1)
                            two++; 
                        else if(k==2)
                            three++; 
                    }
                }
            }
            if(j == words[i].size()-1){
                if((one && (!two && !three) || (two && (!one && !three)) || (three && (!one && !two))))
                    cout << words[i] << "\n"; 
            }
        }
    }
}