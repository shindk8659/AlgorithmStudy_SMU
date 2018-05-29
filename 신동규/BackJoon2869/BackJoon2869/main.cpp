//
//  main.cpp
//  BackJoon2869
//
//  Created by 신동규 on 2018. 5. 29..
//  Copyright © 2018년 신동규. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int A;
    int B;
    int V;
    
    int d;//오늘날짜
    
    cin >> A >> B >> V ;
    
    
  // A + (오늘날짜-1)*(A-B) 낮의위치;
    
    //낮의 위치가 V 보다 크거나 같을때
    
    //V <= A + (오늘날짜-1)*(A-B)
    
    d = (V-A)/(A-B)+1;
    if ((V-A)%(A-B)){// 0.5 일 처럼 나머지가 있을때는 하루를 더 더해준다!
        d++;
    }
    cout << d;
    
    
    
    return 0;
}
