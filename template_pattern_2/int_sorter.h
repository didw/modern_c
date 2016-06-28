#ifndef _INT_SORTER_H_
#define _INT_SORTER_H_

#include <stdio.h>

#if __cplusplus
extern "C" {
#endif

typedef enum {
    ERR_CAT_OK = 0,
    ERR_CAT_FILE,
    ERR_CAT_MEMORY
} IntSorterError;

typedef struct {
    const char *const pFname;
    int errorCategory;
} Context;

typedef struct {
    BufferContext base;
    Context *pAppCtx;
} MyBufferContext;

typedef struct {
    FileAccessorContext base;
    MyBufferContext *pBufCtx;
} MyFileAccessorContext;

#if __cplusplus
}
#endif

#endif
