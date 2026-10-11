#include <bits/stdc++.h>

int main() {
    std::map<char, int> map;

    std::string s;
    std::cin >> s;

    int max = 0;
    int act = 0;
    char lastChar = s[0];
    for(size_t i = 0; i < s.size(); i++) {
        // std::cout << "i: " << i << ", s[i]: " << s[i] << ", lastChar == s[i]: " << (lastChar == s[i]) << std::endl;
        if (lastChar == s[i]) {
            act++;
        } else {
            act = 1;
        }
        if(act > max)
            max = act;
        lastChar = s[i];
    }

    std::cout << max << std::endl;

    return 0;
}