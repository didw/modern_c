#ifndef _FILE_ACCESSOR_H_
#define _FILE_ACCESSOR_H_

#include <stdio.h>
#if __cplusplus
extern "C" {
#endif


typedef struct {
    FILE *fp;
    const char * const pMode;
    const char * const pFname;
    bool (*const processor)(struct FileAccessorContext *pThis);
} FileAccessorContext;

FILE *get_file_pointer(FileAccessorContext *pThis);

#if __cplusplus
}
#endif

#endif
