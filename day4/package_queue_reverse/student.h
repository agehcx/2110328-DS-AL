#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <cassert>

template <typename T>
void CP::queue<T>::reverse(int a, int b) {
    while (a < b) {
        T tmp = mData[(mFront + a) % mCap];
        mData[(mFront + a) % mCap] = mData[(mFront + b) % mCap];
        mData[(mFront + b) % mCap] = tmp;
        a++;b--;
    }
}

#endif
