#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <unordered_set>
#include <algorithm>

template <typename T>
void CP::vector<T>::uniq() {
  std::unordered_set<T> s;
  CP::vector<T> v;
  T* res = new T[mSize];
  int cnt = 0;
  for (int i = 0; i < mSize; i++) {
    if (s.find(mData[i]) != s.end()) {
      s.insert(mData[i]);
      v.push_back(mData[i]);
    }
  }
  // delete mData;
  mData = v;
  mSize = cnt;
}

#endif
