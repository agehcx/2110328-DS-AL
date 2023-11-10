#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <unordered_set>

template <typename T>
void CP::vector<T>::uniq() {
  //do someting here
  T* res = new T[mSize];
  unordered_set<string> s;
  int cnt = 0;
  for (auto t : mData) {
    if (s.find(to_string(t)) != s.end()) res[cnt++] = to_string(cnt++);
    s.insert(to_string(t));
  }
}

#endif
