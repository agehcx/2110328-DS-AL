#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int>& pos) {
  T* res = new T[mSize - pos.size()];
  int c = 0;
  int cnt = 0;
  for (int i = 0; i < mSize; i++) {
    if (c < pos.size()) {
      if (i == pos[c]) {
        c++;
      }
      else {
        res[cnt++] = mData[i];
      }
    } else {
      res[cnt++] = mData[i];
    }
  }
  delete[] mData;
  mSize = mSize - pos.size();
  mCap = mSize;
  mData = res;

}

#endif
