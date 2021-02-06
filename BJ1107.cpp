//
//  BJ1107.cpp
//  algorithm
//
//  Created by Jakeone Im on 2021/01/21.
//  Copyright © 2021 Jakeone Im. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

class BJ1107
{
public:
    
    bool is_it_possible(int number,int broken_num[10]){
        string str_number = to_string(number);
        for (int i = 0; i < str_number.size();i++){
            if(broken_num[str_number.at(i)-'0']==1){
                return false;
            }
        }
        return true;
    }
    
    int run()
    {
        int want_number;
        int broken_num[10] = {0,};
        int number_broken_num;
        
        scanf("%d",&want_number);
        scanf("%d",&number_broken_num);
        
        for (int i =0; i <number_broken_num ; i++){
            int broken;
            scanf("%d",&broken);
            broken_num[broken] = 1;
        }
        
        int answer = abs(100-want_number);
        
        for (int i = 0; i < 1000001; i++){
            if(is_it_possible(i,broken_num)){
                int number_to_click = (int)to_string(i).size()+abs(want_number-i);
                answer = min(answer,number_to_click);
            }
        }
        
        printf("%d",answer);
        
        
        return 0;
    }
    
};
