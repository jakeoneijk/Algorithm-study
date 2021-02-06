//
//  BJ2146.cpp
//  algorithm
//
//  Created by Jakeone Im on 2021/02/06.
//  Copyright © 2021 Jakeone Im. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

class BJ2146{
public:
    int map[102][102] = {0,};
    bool visit[102][102] = {false,};
    int N;
    int land_number = 1;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    queue<pair<int, int>> find_land_que;
    queue<pair<pair<int, int>, pair<int, int>>> land_num_bridge_len_position;
    
    int make_bridge(){
        while (!land_num_bridge_len_position.empty()){
            pair<pair<int, int>, pair<int, int>> info = land_num_bridge_len_position.front();
            land_num_bridge_len_position.pop();
            int current_land_num = info.first.first;
            int current_bridge_length = info.first.second;
            int current_x = info.second.first;
            int current_y = info.second.second;
            
            for (int k = 0; k < 4; k++){
                int new_x = current_x + dx[k];
                int new_y = current_y + dy[k];
                
                if (new_x < 0 || new_x>=N||new_y < 0 || new_y>=N){
                    continue;
                }
                
                if (map[new_x][new_y] == current_land_num){
                    continue;
                }
                
                if(map[new_x][new_y] != 0){
                    return current_bridge_length;
                }
                
                if (visit[new_x][new_y] == true){
                    continue;
                }
                visit[new_x][new_y] = true;
                land_num_bridge_len_position.push(make_pair(make_pair(current_land_num, current_bridge_length+1), make_pair(new_x, new_y)));
            }
            
            
            
            
        }
        return 0;
    }
    
    bool is_start_land(int x,int y){
           for (int k = 0; k < 4; k++){
               int new_x = x + dx[k];
               int new_y = y + dy[k];
               if (new_x < 0 || new_x>=N||new_y < 0 || new_y>=N){
                   continue;
               }
               if (map[new_x][new_y] == 0){
                   return true;
               }
           }
           return false;
           
       }
    
    void find_land(int x,int y){
        find_land_que.push(make_pair(x, y));
        while(!find_land_que.empty()){
            pair<int,int> position = find_land_que.front();
            find_land_que.pop();
            for (int k = 0; k < 4; k++){
                int new_x = position.first + dx[k];
                int new_y = position.second + dy[k];
                if (new_x < 0 || new_x>=N||new_y < 0 || new_y>=N){
                    continue;
                }
                if (map[new_x][new_y] == 1){
                    map[new_x][new_y] = land_number;
                    find_land_que.push(make_pair(new_x, new_y));
                }
            }
            
        }
        
    }
    
    int run(){
        scanf("%d",&N);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d",&map[i][j]);
            }
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(map[i][j]==1){
                    land_number++;
                    map[i][j] = land_number;
                    find_land(i, j);
                }
            }
        }
        
        int answer = 100000;
        
        for (int land = 2; land <= land_number; land++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(map[i][j]==land){
                        if(is_start_land(i, j)){
                            land_num_bridge_len_position.push(make_pair(make_pair(land, 0),make_pair(i, j)));
                        }
                        
                    }
            }
        }
            
            int this_land_answer = make_bridge();
            
            if(this_land_answer < answer){
                answer = this_land_answer;
            }
            
            for(int i=0; i<N; i++){
                memset(visit[i], false, sizeof(bool)*102);
            }
            
            while (!land_num_bridge_len_position.empty()) {
                land_num_bridge_len_position.pop();
            }
        }
        
        printf("%d",answer);
        
        return 0;
    }
};
