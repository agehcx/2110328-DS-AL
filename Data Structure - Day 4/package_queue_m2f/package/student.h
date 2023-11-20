#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos) {
    if (pos >= mSize) return;
    for (int i = 0; i < pos ; i++)
        std::swap(mData[(mFront + pos - i) % mCap], mData[(mFront + pos - i - 1) % mCap]);
}

#endif
