//
//  BJ11021.cpp
//  algorithm
//
//  Created by Jakeone Im on 2020/12/26.
//  Copyright © 2020 Jakeone Im. All rights reserved.
//

#include <stdio.h>

class BJ11021
{
public:
    int run()
    {
        int rotation_num,first_num,second_num;
        scanf("%d",&rotation_num);
        for (int i =0; i < rotation_num; i++){
            scanf("%d %d",&first_num,&second_num);
            printf("Case #%d: %d\n",i+1,first_num+second_num);
        }
        return 0;
    }
};
