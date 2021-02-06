//
//  BJ17070.cpp
//  algorithm
//
//  Created by Jakeone Im on 2021/01/21.
//  Copyright © 2021 Jakeone Im. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

class BJ17070
{
public:
    
    void add_position(queue<pair<pair<int, int>, pair<int, int>>> &position_of_pipe,
                      pair<pair<int, int>, pair<int, int>> current_position_of_pipe,
                      int new_x,int new_y,int map_size, int map[17][17]){
        if (new_x >= map_size){
            return;
        }
        if (new_y >= map_size){
            return;
        }
        if (map[new_x][new_y]==1){
            return;
        }
        
        if (current_position_of_pipe.second.first != new_x &&
            current_position_of_pipe.second.second != new_y){
            if(map[new_x-1][new_y] == 1){
                return;
            }
            if(map[new_x][new_y-1] == 1){
                return;
            }
            
        }
        position_of_pipe.push(make_pair(make_pair(current_position_of_pipe.second.first,
                                                  current_position_of_pipe.second.second), make_pair(new_x,new_y)));
        
    }
    
    int run()
    {   int map[17][17]={0,};
        int size_of_map;
        scanf("%d",&size_of_map);
        for (int i = 0; i < size_of_map; i++){
            for (int j = 0; j <size_of_map; j++){
                scanf("%d",&map[i][j]);
            }
            
        }
        
        queue<pair<pair<int, int>, pair<int, int>>> position_of_pipe;
        position_of_pipe.push(make_pair(make_pair(0, 0), make_pair(0,1)));
        
        pair<pair<int, int>, pair<int, int>> current_position_of_pipe;
        int answer = 0;
        
        while (!position_of_pipe.empty()) {
            current_position_of_pipe = position_of_pipe.front();
            position_of_pipe.pop();
            
            if (current_position_of_pipe.second.first == (size_of_map-1) &&
                current_position_of_pipe.second.second == (size_of_map-1)){
                answer++;
                continue;
            }
            
            if (current_position_of_pipe.first.first == current_position_of_pipe.second.first){
                add_position(position_of_pipe, current_position_of_pipe, current_position_of_pipe.second.first, current_position_of_pipe.second.second + 1, size_of_map, map);
                add_position(position_of_pipe, current_position_of_pipe, current_position_of_pipe.second.first + 1, current_position_of_pipe.second.second + 1, size_of_map, map);
                
            }else if (current_position_of_pipe.first.second == current_position_of_pipe.second.second){
                add_position(position_of_pipe, current_position_of_pipe, current_position_of_pipe.second.first+1, current_position_of_pipe.second.second, size_of_map, map);
                add_position(position_of_pipe, current_position_of_pipe, current_position_of_pipe.second.first + 1, current_position_of_pipe.second.second + 1, size_of_map, map);
            }else{
                add_position(position_of_pipe, current_position_of_pipe, current_position_of_pipe.second.first + 1, current_position_of_pipe.second.second, size_of_map, map);
                add_position(position_of_pipe, current_position_of_pipe, current_position_of_pipe.second.first, current_position_of_pipe.second.second + 1, size_of_map, map);
                add_position(position_of_pipe, current_position_of_pipe, current_position_of_pipe.second.first + 1, current_position_of_pipe.second.second + 1, size_of_map, map);
            }
            
        }
        
        printf("%d",answer);
        
        
        return 0;
    }
    
};
