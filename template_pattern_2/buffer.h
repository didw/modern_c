#ifndef _BUFFER_H_
#define _BUFFER_H_

#if __cplusplus
extern "C" {
#endif

typedef struct BufferContext {
    void *pBuf;
    size_t size;
    bool (*processor)(struct BufferContext *p);
} BufferContext;

void *allocate_buffer(BufferContext *pThis, size_t size);

#if __cplusplus
}
#endif

#endif
