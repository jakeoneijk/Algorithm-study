//
//  BJ10950.cpp
//  algorithm
//
//  Created by Jakeone Im on 2020/12/26.
//  Copyright © 2020 Jakeone Im. All rights reserved.
//
#include <stdio.h>

class BJ10950
{
public:
    int run()
    {
        int routin_number;
        int first_number;
        int second_number;
        
        scanf("%d",&routin_number);
        for (int i = 0; i < routin_number; i++){
            scanf("%d %d",&first_number,&second_number);
            int result = first_number + second_number;
            printf("%d\n",result);
        }
        return 0;
    }
};
