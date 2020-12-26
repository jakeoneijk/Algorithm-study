//
//  BJ10953.cpp
//  algorithm
//
//  Created by Jakeone Im on 2020/12/26.
//  Copyright © 2020 Jakeone Im. All rights reserved.
//

#include <stdio.h>

class BJ10953{
public:
    int run()
    {
        int rotation_number;
        scanf("%d",&rotation_number);
        for(int i=0;i<rotation_number;i++){
            int first_num,second_num;
            scanf("%d,%d",&first_num,&second_num);
            printf("%d\n",first_num+second_num);
        }
        return 0;
    }
};
