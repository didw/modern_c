#include <stdbool.h>
#include "stack.h"

static bool isStackFull(const Stack* p) {
    return p->top == p->size;
}

static bool isStackEmpty(const Stack* p) {
    return p->top == 0;
}

bool validateRange(Validator *p, int val) {
    RangeValidator *pThis = (RangeValidator*)p;
    return pThis->min <= val && val <= pThis->max;
}

bool validatePrevious(Validator *p, int val) {
    PreviousValueValidator *pThis = (PreviousValueValidator*)p;
    if (val < pThis->previousValue) return false;
    pThis->previousValue = val;
    return true;
}

bool validate(Validator *p, int val) {
    if (!p) return true;
    return p->validate(p, val);
}

bool push(Stack* p, int val) {
    if (isStackFull(p) || !validate(p->pValidator, val)) return false;
    p->pBuf[p->top++] = val;
    return true;
}

bool pop(Stack* p, int *pRet) {
    if (isStackEmpty(p)) return false;
    *pRet = p->pBuf[--p->top];
    return true;
}

int main_stack() {
    int buf[16];
    RangeValidator validator = newRangeValidator(0, 9);
    Stack stack = newStackWithValidator(buf, &validator.base);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 10);
    while (true) {
        int val;
        if (!pop(&stack, &val))
            break;
        printf("%d\n", val);
    }

    PreviousValueValidator validator2 = newPreviousValidator;
    Stack stack2 = newStackWithValidator(buf, &validator2.base);
    push(&stack2, 4);
    push(&stack2, 3);
    push(&stack2, 5);
    push(&stack2, 10);
    while (true) {
        int val;
        if (!pop(&stack2, &val))
            break;
        printf("%d\n", val);
    }
    return 0;
}
