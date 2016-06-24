#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Validator {
    bool(*const validate)(struct Validator *pThis, int val);
} Validator;

typedef struct {
    Validator base;
    const int min;
    const int max;
} RangeValidator;

typedef struct {
    Validator base;
    int previousValue;
} PreviousValueValidator;

typedef struct {
    int top;
    const size_t size;
    int* const pBuf;
    Validator *const pValidator;
} Stack;

bool validateRange(Validator *pThis, int val);
bool validatePrevious(Validator *pThis, int val);

bool push(Stack* p, int val);
bool pop(Stack* p, int *pRet);

#define newStack(buf) {                   \
    0, sizeof(buf) / sizeof(int), (buf),  \
    NULL                                  \
}

#define newRangeValidator(min, max)  \
    {{validateRange}, (min), (max)}

#define newPreviousValidator \
    {{validatePrevious}, 0}

#define newStackWithValidator(buf, pValidator) { \
    0, sizeof(buf) / sizeof(int), (buf),         \
    pValidator                                   \
}

#ifdef __cpluspluc
}
#endif

#endif