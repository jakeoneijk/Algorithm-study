//
//  BJ1700.cpp
//  algorithm
//
//  Created by Jakeone Im on 2021/01/16.
//  Copyright © 2021 Jakeone Im. All rights reserved.
//
/*
 
 3가지 경우
 1. 코드가 남았을 경우
 2. 이미 꽃혀있을 경우
 3. 뽑힐 코드를 골라야 할 경우
 
 3번의 경우에는 어떻게 하면 현재로부터의 거리를 잘 구할 수 있을 까
 */

#include <stdio.h>
#include <queue>
using namespace std;

class BJ1700
{
public:
    int run(){
        int use_util_num[101]={0};
        int multi_tab[101] = {0};
        queue<int> use_index[101];
        
        int multi_tab_number,total_use_number;
        scanf("%d %d",&multi_tab_number,&total_use_number);
        
        for (int i = 0; i < total_use_number;i++){
            scanf("%d",&use_util_num[i]);
            use_index[use_util_num[i]].push(i);
        }
        
        bool plug_in_this_time = false;
        int answer = 0;
        
        for (int i = 0; i < total_use_number;i++){
            int replace_multitab_number = -1;
            plug_in_this_time = false;
            use_index[use_util_num[i]].pop();
            
            for (int j = 0; j < multi_tab_number;j++){
                if (multi_tab[j] == 0 || multi_tab[j] == use_util_num[i]){
                    multi_tab[j] = use_util_num[i];
                    plug_in_this_time = true;
                    break;
                }else{
                    if (replace_multitab_number == -1 || use_index[multi_tab[j]].empty()){
                        replace_multitab_number = j;
                    }else if (!use_index[multi_tab[j]].empty() &&
                              !use_index[multi_tab[replace_multitab_number]].empty() &&
                              use_index[multi_tab[j]].front() > use_index[multi_tab[replace_multitab_number]].front()){
                            replace_multitab_number = j;
                        }
                }
            }
            if (plug_in_this_time == false){
                multi_tab[replace_multitab_number] = use_util_num[i];
                answer++;
            }
        }
        printf("%d",answer);
        
        return 0;
    }
};
