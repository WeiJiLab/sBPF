//
// Created by XingfengYang on 2020/5/13.
//

#ifndef HM_NET_LOG_H
#define HM_NET_LOG_H

#include <stdio.h>

#define LogError(fmt, arg  ...)    \
    do{printf("\033[31m" fmt"\033[0m \n" ,##arg );  }while(0);

#define LogInfo(fmt, arg  ...)    \
    do{printf("\033[32m" fmt"\033[0m \n" ,##arg );  }while(0);

#define LogWarnning(fmt, arg  ...)    \
    do{printf("\033[33m" fmt"\033[0m \n" ,##arg );  }while(0);

#endif //HM_NET_LOG_H
