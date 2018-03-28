//
//  main.cpp
//  vector test
//
//  Created by Steve X on 2018/3/21.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string>a;
    
    a.push_back("1");
    cout<<*(a.end())<<endl;
    return 0;
}
