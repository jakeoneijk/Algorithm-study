//
//  BJ10952.cpp
//  algorithm
//
//  Created by Jakeone Im on 2020/12/26.
//  Copyright © 2020 Jakeone Im. All rights reserved.
//

#include <stdio.h>

class BJ10952
{
public:
    int run()
    {
        int first_num,second_num;
        while(true){
            scanf("%d %d",&first_num,&second_num);
            if (first_num == 0 && second_num == 0){
                break;
            }
            printf("%d\n",first_num+second_num);
        }
        return 0;
    }
    
};
