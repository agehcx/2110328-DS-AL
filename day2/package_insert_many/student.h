#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data) {
    T* res = new T[mSize + data.size()];
    std::sort(data.begin(), data.end());
    int c = 0, cnt = 0;
    for (int i = 0; i < mSize; i++) {
        if (i == data[c].first) res[cnt++] = data[c++].second;
        res[cnt++] = mData[i];
    }
    if (data[c].first == mSize) res[cnt++] = data[c++].second;
    delete mData;
    mData = res;
    mSize += data.size();
    mCap = mSize;
}

#endif
