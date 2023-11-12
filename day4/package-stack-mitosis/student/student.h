#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b) {
    T tmp[b + 1];
    for (int i = 0; i <= b; i++) {
        tmp[b - i] = top();
        pop();
    }
    for (int i = 0; i <= b; i++) {
        push(tmp[i]);
        if (i < b - a + 1) push(tmp[i]);
    }
}

#endif