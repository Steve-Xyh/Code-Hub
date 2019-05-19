//
//  main.cpp
//  sunyb
//
//  Created by Steve X on 2018/9/19.
//  Copyright © 2018年 Steve X. All rights reserved.
//
#pragma GCC optimize(0)
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> v;

int main(int argc, const char * argv[]) {
    // insert code here...
    for (int i = 0; i < (int)1e8; ++i) {
        //std::system("sleep 0.001");
        v.push_back(i);
    }
    for (auto i : v) {
            std::cout << i << std::endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
