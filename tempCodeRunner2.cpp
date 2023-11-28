#include <bits/stdc++.h>
using namespace std;

struct Box {
    int age;
    string gender;
    bool cool;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> vec = {1,23,2,4,5,6,7,8,1,2,3,9,1,2};
    sort(vec.begin(), vec.end());
    iota(vec.begin(), vec.end(),0);
    accumulate(vec.begin(), vec.end(), 0);
    vector<vector<Box>> v(vector<Box>());
    int arr[5][5];
    Box q[50][50];
    q[0][0].age = 50;
    q[0][0].gender = "ATtack helicopter";
    q[0][0].cool = false;
    q[1][0].age = 12;
    q[1][0].gender = "helicopter";
    q[1][0].cool = true;
}