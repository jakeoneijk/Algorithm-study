//
//  BJ14890.cpp
//  algorithm
//
//  Created by Jakeone Im on 2021/02/02.
//  Copyright © 2021 Jakeone Im. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>

class BJ14890{
  
public:
    int map[101][101]={0,};
    int N;
    int L;
    int previous_block = -1;
    int how_long = 0;
    bool alert = false;
    
    bool way_check(bool is_start,int current_block){
        if (is_start){
            how_long = 1;
            alert = false;
        }else{
            
            if (alert){
                if (previous_block != current_block){
                    return false;
                }
                how_long++;
                if (how_long>=L){
                    alert = false;
                    how_long=0;
                    
                }
                return true;
            }
            
            int difference = previous_block - current_block;
            if (abs(difference)>1){
                return false;
            }else if(difference==0){
                how_long++;
            }else{
                if (difference<0){
                    if (how_long>=L){
                        how_long = 1;
                    }else{
                        return false;
                    }
                }else{
                    alert = true;
                    how_long = 1;
                    if(L==1){
                        alert = false;
                        how_long=0;
                    }
                    
                }
            }
        }
        return true;
    }
    
    int run()
    {
        scanf("%d %d",&N,&L);
        
        
        for (int i = 0; i < N; i++){
            for(int j =0; j < N; j++){
                scanf("%d",&map[i][j]);
            }
        }
        
        int answer = 0;
        
        
        for (int i = 0; i < N; i++){
            
            for(int j =0; j < N; j++){
                if (j == 0){
                    way_check(true,map[i][j]);
                }else{
                    if(!way_check(false, map[i][j])){
                        break;
                    }
                }
                
                previous_block = map[i][j];
                if(j==(N-1) && alert==false){
                    answer++;
                }
            }
        }
        
        for (int j = 0; j < N; j++){
            for(int i =0; i < N; i++){
                if (i == 0){
                    way_check(true,map[i][j]);
                }else{
                    if(!way_check(false, map[i][j])){
                        break;
                    }
                }
                
                previous_block = map[i][j];
                if(i==(N-1)&& alert==false){
                    answer++;
                }
            }
        }
        
        printf("%d",answer);
        
        
        
        return 0;
    }
};
