#ifndef __ABR_COMMON_H
#define __ABR_COMMON_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define abr_nullptr NULL
#define _UNUSED(x) (void)(x)


#define abr_ssize_t 
#if 1 == 0
#define BUG_ON(cond, err_msg) \
    do {    \
        if ((cond)) { \
            printf("%s:%d -> %s raised %s\n", __FILE__, __LINE__, #cond, err_msg); \
            exit(1); \
        } \
    }while(0) 
#else
#define BUG_ON(x, y)
#endif

#define LOG(msg)  printf("%s:%d -> %s", __FUNCTION__, __LINE__, msg);

#endif

