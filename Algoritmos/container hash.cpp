template <typename Container>
struct container_hash {
    size_t operator()(Container const& c) const {
        return hash<string>() (string(c.cbegin(), c.cend()));
    }
};
unordered_map<vector<int>, int, container_hash<vector<int>>>mp;
