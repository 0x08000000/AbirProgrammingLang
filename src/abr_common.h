#ifndef __ABR_COMMON_H
#define __ABR_COMMON_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define abr_nullptr NULL


#define abr_ssize_t 
#define BUG_ON(cond, err_msg) \
    do {    \
        if (cond) \
            printf("%s:%d -> %s raised %s", __FILE__, __LINE__, #cond, err_msg); \
        exit(1); \
    }while(0) 

#define LOG(msg)  printf("%s:%d -> %s", __FUNCTION__, __LINE__, msg);

#endif

