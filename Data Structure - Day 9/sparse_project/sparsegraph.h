#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

using namespace std;

#include <algorithm>

class SparseGraph{
public:
    SparseGraph() {
        v = new vector<int>[3];
        mSize = 3;
    }

    SparseGraph(int n_in) {
        v = new vector<int>[n_in];
        mSize = n_in;
    }

    SparseGraph(const SparseGraph& G) {
        v = new vector<int>[G.mSize];
        for (int i = 0; i < G.mSize; i++) {
            v[i] = G.v[i];
        }
        mSize = G.mSize;
    }

    void AddEdge(int a, int b) {
        if (find(v[a].begin(), v[a].end(), b) == v[a].end()) {
            v[a].push_back(b);
        }
    }

    void RemoveEdge(int a, int b) {
        auto it = find(v[a].begin(), v[a].end(), b);
        if (!(it == v[a].end())) v[a].erase(it);
    }

    bool DoesEdgeExist(int a, int b) const {
        auto it = find(v[a].begin(), v[a].end(), b);
        if (it == v[a].end()) return false;
        return true;
    }

    SparseGraph Transpose() const {
        SparseGraph res(mSize);
        for (int i = 0; i < mSize; i++) {
            for (auto j : v[i]) {
                res.AddEdge(j,i);
            }
        }
        return res;
    }

protected:
    vector<int>* v;
    int mSize;
};

#endif // __SPARSE_GRAPH_H__

