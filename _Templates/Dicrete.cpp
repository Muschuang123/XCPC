struct di {
    vector<i64> a;
    void add(i64 x) {
        a.push_back(x);
    }
    int flush() {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()));
        return a.size();
    }
    int operator[](const i64 &x) {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }
};