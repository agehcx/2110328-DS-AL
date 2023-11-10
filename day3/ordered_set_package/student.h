#include <vector>
using namespace std;

#include <set>

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    for (auto& it : A) {
        v.push_back(it);
        s.insert(it);
    }
    for (auto& it : B) {
        if (s.find(it) == s.end()) {
            v.push_back(it);
            s.insert(it);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;
    for (auto& it : B) s.insert(it);
    for (auto& it : A) if (s.find(it) != s.end()) v.push_back(it);
    return v;
}
