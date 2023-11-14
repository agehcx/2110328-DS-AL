#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

#include <bits/stdc++.h>

template <typename T, typename Comp >
T CP::priority_queue<T, Comp>::get_kth(size_t k) const {
  T arr[7];
  int tmp = 0;
  for (int i = 0; i < 7 && i < mSize; i++) {
    arr[i] = mData[i];
    tmp = i;
  }
  std::sort(arr, arr + tmp, mLess);
  return arr[tmp - k];
}

#endif
