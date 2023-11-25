#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last) {
  T* res = new T[mSize + last - first];
  int cnt = 0;
  iterator tmp = first;
  for (int i = 0; i <= mSize; i++) {
    if (i == position - begin())
      for (int j = 0; j < last - tmp; j++)
        res[cnt++] = *(first++);
    if (i < mSize) res[cnt++] = mData[i];
  }
  delete mData;
  mData = res;
  mSize += last - tmp;
  mCap = mSize;
}
#endif
