//
//  BJ10972.cpp
//  algorithm
//
//  Created by Jakeone Im on 2021/01/23.
//  Copyright © 2021 Jakeone Im. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <cstdlib>
#include <math.h>
using namespace std;

class BJ16234{
public:
    int N,L,R;
    int map[51][51]={0,};
    int map_visited[51][51]={0,};
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    bool is_happen = true;
    int sum = 0;
    
    void check_friend(int current_x, int current_y, int new_x,int new_y, queue<pair<int, int>> &friend_nation, queue<pair<int,int>> &travel_friend_nation){
        if (new_x >= N || new_y >= N || new_x < 0 || new_y < 0){
            return;
        }
        
        if(map_visited[new_x][new_y] == 1){
            return;
        }
        
        int difference = abs(map[current_x][current_y]-map[new_x][new_y]);
        if(difference >=L && difference <=R){
            map_visited[new_x][new_y] = 1;
            friend_nation.push(make_pair(new_x, new_y));
            travel_friend_nation.push(make_pair(new_x, new_y));
            is_happen = true;
            sum += map[new_x][new_y];
        }
    }
    
    int run(){
        
        scanf("%d %d %d",&N,&L,&R);
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                scanf("%d",&map[i][j]);
            }
        }
        
        queue<pair<int, int>> friend_nation;
        queue<pair<int,int>> travel_friend_nation;
        int answer = 0;
        
        while(is_happen == true){
            is_happen = false;
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    if (map_visited[i][j] == 1){
                        continue;
                    }
                    sum = map[i][j];
                    map_visited[i][j] = 1;
                    
                    friend_nation.push(make_pair(i, j));
                    travel_friend_nation.push(make_pair(i, j));
                    
                    while (!travel_friend_nation.empty()) {
                        pair<int,int> current_nation = travel_friend_nation.front();
                        travel_friend_nation.pop();
                        for (int move_index = 0; move_index < 4; move_index++){
                            check_friend(current_nation.first, current_nation.second, current_nation.first+dx[move_index], current_nation.second+dy[move_index], friend_nation, travel_friend_nation);
                        }
                    }
                    
                    int number_of_people = (int)trunc(sum/friend_nation.size());
                    while (!friend_nation.empty()) {
                        map[friend_nation.front().first][friend_nation.front().second] = number_of_people;
                        friend_nation.pop();
                    }
                }
            }
            if (is_happen == true){
                answer++;
            }
            for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                map_visited[i][j]=0;
            }}
            
        }
        printf("%d",answer);
        
        return 0;
    }
};
