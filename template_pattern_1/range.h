#ifndef _RANGE_H_
#define _RANGE_H_

#include <stdio.h>
#include "file_reader.h"
#if __cplusplus
extern "C" {
#endif

typedef struct {
    FileReaderContext base;
    int result;
} MyFileReaderContext;

int range(FILE *fp);

#if __cplusplus
}
#endif

#endif
