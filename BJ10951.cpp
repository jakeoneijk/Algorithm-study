//
//  BJ10951.cpp
//  algorithm
//
//  Created by Jakeone Im on 2020/12/26.
//  Copyright © 2020 Jakeone Im. All rights reserved.
//

#include <stdio.h>

class BJ10951
{
public:
    int run()
    {   int first_number,second_number;
        while (scanf("%d %d",&first_number,&second_number) != EOF)
        {
            int result = first_number + second_number;
            printf("%d\n",result);
        }
        return 0;
    }
};
