#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>>& ls) {
  for (auto it = ls.begin(); it != ls.end(); it++) {
    CP::list<T>& tmp = *it;
    mHeader->prev->next = tmp.mHeader->next;
    tmp.mHeader->next->prev = mHeader->prev;
    tmp.mHeader->prev->next = mHeader;
    mHeader->prev = tmp.mHeader->prev;

    tmp.mHeader->prev = tmp.mHeader;
    tmp.mHeader->next = tmp.mHeader;
    mSize += (*it).mSize;
    tmp.mSize = 0;
  }
}

#endif


