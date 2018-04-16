//
// Created by recall on 2018/4/16.
//

#ifndef REDISFORANDROID_WAIT3_H
#define REDISFORANDROID_WAIT3_H

#include <sys/types.h>

pid_t  wait3(int *status, int options, struct rusage *rusage);

#endif //REDISFORANDROID_WAIT3_H
