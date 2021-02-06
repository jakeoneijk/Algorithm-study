//
//  BJ2862.cpp
//  algorithm
//
//  Created by Jakeone Im on 2021/01/07.
//  Copyright © 2021 Jakeone Im. All rights reserved.
//

#include <stdio.h>



class BJ2862
{
public:
    int win_number[100000]={0,};
    
    bool can_I_win(int left_N,int max_number)
    {
        if (max_number >= left_N){
            return true;
        }
        
        if (win_number[left_N] != 0 && win_number[left_N] <= max_number){
            return true;
        }
        
        for (int i = 1;i<=max_number && i <= left_N/3;i++){
            bool result = can_I_win(left_N-i, 2*i);
            if (result == false){
                win_number[left_N] = i;
                return true;
            }
        }
        
        return false;
        
    }
    int run()
    {
        int N;
        scanf("%d",&N);
        
        for (int i = 1; i <= N/3; i++){
            if (!can_I_win(N-i, 2*i)){
                printf("%d",i);
                return 0;
            }
        }
        printf("%d",N);
        return 0;
    }
    
};
