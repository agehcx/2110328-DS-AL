#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  if (!((begin() <= a) && (a < end()) && (begin() <= b) && (b < end()) && (begin() <= a + m - 1) && (a + m - 1 < end()) && (begin() <= b + m - 1) && (b + m - 1 < end()) && (a + m - 1 < b || b + m - 1 < a) && (m > 0))) return false;
  while(m--) std::swap(*(a++), *(b++));
  return true;
}

#endif
