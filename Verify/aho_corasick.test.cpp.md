---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number/modint.hpp
    title: Number/modint.hpp
  - icon: ':heavy_check_mark:'
    path: String/aho_corasick.hpp
    title: String/aho_corasick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1269
    links:
    - https://yukicoder.me/problems/no/1269
  bundledCode: "#line 1 \"Verify/aho_corasick.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1269\"\
    \n\n#line 2 \"Number/modint.hpp\"\n\n#include <iostream>\n\ntemplate <int MOD>\n\
    struct ModInt {\n    using lint = long long;\n    int val;\n\n    // constructor\n\
    \    ModInt(lint v = 0) : val(v % MOD) {\n        if (val < 0) val += MOD;\n \
    \   };\n\n    // unary operator\n    ModInt operator+() const { return ModInt(val);\
    \ }\n    ModInt operator-() const { return ModInt(MOD - val); }\n    ModInt inv()\
    \ const { return this->pow(MOD - 2); }\n\n    // arithmetic\n    ModInt operator+(const\
    \ ModInt& x) const { return ModInt(*this) += x; }\n    ModInt operator-(const\
    \ ModInt& x) const { return ModInt(*this) -= x; }\n    ModInt operator*(const\
    \ ModInt& x) const { return ModInt(*this) *= x; }\n    ModInt operator/(const\
    \ ModInt& x) const { return ModInt(*this) /= x; }\n    ModInt pow(lint n) const\
    \ {\n        auto x = ModInt(1);\n        auto b = *this;\n        while (n >\
    \ 0) {\n            if (n & 1) x *= b;\n            n >>= 1;\n            b *=\
    \ b;\n        }\n        return x;\n    }\n\n    // compound assignment\n    ModInt&\
    \ operator+=(const ModInt& x) {\n        if ((val += x.val) >= MOD) val -= MOD;\n\
    \        return *this;\n    }\n    ModInt& operator-=(const ModInt& x) {\n   \
    \     if ((val -= x.val) < 0) val += MOD;\n        return *this;\n    }\n    ModInt&\
    \ operator*=(const ModInt& x) {\n        val = lint(val) * x.val % MOD;\n    \
    \    return *this;\n    }\n    ModInt& operator/=(const ModInt& x) { return *this\
    \ *= x.inv(); }\n\n    // compare\n    bool operator==(const ModInt& b) const\
    \ { return val == b.val; }\n    bool operator!=(const ModInt& b) const { return\
    \ val != b.val; }\n    bool operator<(const ModInt& b) const { return val < b.val;\
    \ }\n    bool operator<=(const ModInt& b) const { return val <= b.val; }\n   \
    \ bool operator>(const ModInt& b) const { return val > b.val; }\n    bool operator>=(const\
    \ ModInt& b) const { return val >= b.val; }\n\n    // I/O\n    friend std::istream&\
    \ operator>>(std::istream& is, ModInt& x) noexcept {\n        lint v;\n      \
    \  is >> v;\n        x = v;\n        return is;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val;\
    \ }\n};\n\n// constexpr int MOD = 1000000007;\n// constexpr int MOD = 998244353;\n\
    // using mint = ModInt<MOD>;\n#line 2 \"String/aho_corasick.hpp\"\n\n#include\
    \ <algorithm>\n#include <vector>\n#include <array>\n#include <queue>\n#include\
    \ <functional>\n\ntemplate <int K, class T>\nstruct PatternsMatching {\n    struct\
    \ Node {\n        std::array<int, K> nxt;\n        int fail;\n        std::vector<int>\
    \ ids;\n\n        explicit Node() : fail(0) { nxt.fill(-1); }\n    };\n\n    std::vector<Node>\
    \ nodes;\n    std::function<int(T)> enc;\n\n    explicit PatternsMatching(T base)\n\
    \        : nodes(1), enc([=](T c) { return c - base; }) {}\n\n    template <class\
    \ Container>\n    void add(const Container& s, int id) {\n        int pos = 0;\n\
    \        for (T ci : s) {\n            int c = enc(ci);\n\n            int npos\
    \ = nodes[pos].nxt[c];\n            if (npos == -1) {\n                npos =\
    \ nodes.size();\n                nodes[pos].nxt[c] = npos;\n                nodes.emplace_back();\n\
    \            }\n            pos = npos;\n        }\n        nodes[pos].ids.push_back(id);\n\
    \    }\n\n    void build() {\n        std::queue<int> que;\n        for (int&\
    \ pos : nodes[0].nxt) {\n            if (pos == -1) {\n                pos = 0;\n\
    \            } else {\n                que.push(pos);\n            }\n       \
    \ }\n\n        while (!que.empty()) {\n            int pos = que.front();\n  \
    \          que.pop();\n\n            for (int c = 0; c < K; ++c) {\n         \
    \       int npos = nodes[pos].nxt[c];\n                if (npos == -1) continue;\n\
    \n                int p = nodes[pos].fail;\n                while (nodes[p].nxt[c]\
    \ == -1) p = nodes[p].fail;\n                int fpos = next(nodes[pos].fail,\
    \ c);\n\n                nodes[npos].fail = fpos;\n                std::copy(nodes[fpos].ids.begin(),\
    \ nodes[fpos].ids.end(),\n                          std::back_inserter(nodes[npos].ids));\n\
    \n                que.push(npos);\n            }\n        }\n    }\n\n    int\
    \ next(int pos, int c) const {\n        while (nodes[pos].nxt[c] == -1) pos =\
    \ nodes[pos].fail;\n        return nodes[pos].nxt[c];\n    }\n\n    // (id, end\
    \ of matching)\n    template <class Container>\n    std::vector<std::pair<int,\
    \ int>> matching(const Container& s) const {\n        std::vector<std::pair<int,\
    \ int>> ret;\n\n        int pos = 0;\n        for (int i = 0; i < (int)s.size();\
    \ ++i) {\n            pos = next(pos, enc(s[i]));\n            for (auto id :\
    \ nodes[pos].ids) {\n                ret.emplace_back(id, i + 1);\n          \
    \  }\n        }\n\n        return ret;\n    }\n\n    Node& operator[](int pos)\
    \ { return nodes[pos]; }\n    Node operator[](int pos) const { return nodes[pos];\
    \ }\n};\n#line 5 \"Verify/aho_corasick.test.cpp\"\n\n#line 7 \"Verify/aho_corasick.test.cpp\"\
    \n#include <numeric>\n#include <string>\n\nusing lint = long long;\nusing mint\
    \ = ModInt<1000000007>;\n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \n    int n;\n    lint l, r;\n    std::cin >> n >> l >> r;\n\n    PatternsMatching<10,\
    \ char> pm('0');\n    {\n        lint a = 1, b = 1;\n        while (a <= r) {\n\
    \            if (l <= a && a <= r)\n                pm.add(std::to_string(a),\
    \ 0);\n            lint s = a + b;\n            b = a;\n            a = s;\n \
    \       }\n    }\n\n    pm.build();\n    int m = pm.nodes.size();\n\n    std::vector<mint>\
    \ dp(m, 0);\n    dp[0] = 1;\n    auto ndp = dp;\n\n    while (n--) {\n       \
    \ std::fill(ndp.begin(), ndp.end(), 0);\n\n        for (int i = 0; i < m; ++i)\
    \ {\n            for (int d = 0; d < 10; ++d) {\n                int j = pm.next(i,\
    \ d);\n                if (!pm[j].ids.empty()) continue;\n                ndp[j]\
    \ += dp[i];\n            }\n        }\n\n        std::swap(dp, ndp);\n    }\n\n\
    \    std::cout << std::accumulate(dp.begin(), dp.end(), mint(0)) - 1 << \"\\n\"\
    ;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1269\"\n\n#include \"\
    ../Number/modint.hpp\"\n#include \"../String/aho_corasick.hpp\"\n\n#include <iostream>\n\
    #include <numeric>\n#include <string>\n\nusing lint = long long;\nusing mint =\
    \ ModInt<1000000007>;\n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \n    int n;\n    lint l, r;\n    std::cin >> n >> l >> r;\n\n    PatternsMatching<10,\
    \ char> pm('0');\n    {\n        lint a = 1, b = 1;\n        while (a <= r) {\n\
    \            if (l <= a && a <= r)\n                pm.add(std::to_string(a),\
    \ 0);\n            lint s = a + b;\n            b = a;\n            a = s;\n \
    \       }\n    }\n\n    pm.build();\n    int m = pm.nodes.size();\n\n    std::vector<mint>\
    \ dp(m, 0);\n    dp[0] = 1;\n    auto ndp = dp;\n\n    while (n--) {\n       \
    \ std::fill(ndp.begin(), ndp.end(), 0);\n\n        for (int i = 0; i < m; ++i)\
    \ {\n            for (int d = 0; d < 10; ++d) {\n                int j = pm.next(i,\
    \ d);\n                if (!pm[j].ids.empty()) continue;\n                ndp[j]\
    \ += dp[i];\n            }\n        }\n\n        std::swap(dp, ndp);\n    }\n\n\
    \    std::cout << std::accumulate(dp.begin(), dp.end(), mint(0)) - 1 << \"\\n\"\
    ;\n}\n"
  dependsOn:
  - Number/modint.hpp
  - String/aho_corasick.hpp
  isVerificationFile: true
  path: Verify/aho_corasick.test.cpp
  requiredBy: []
  timestamp: '2020-10-29 01:25:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/aho_corasick.test.cpp
layout: document
redirect_from:
- /verify/Verify/aho_corasick.test.cpp
- /verify/Verify/aho_corasick.test.cpp.html
title: Verify/aho_corasick.test.cpp
---
