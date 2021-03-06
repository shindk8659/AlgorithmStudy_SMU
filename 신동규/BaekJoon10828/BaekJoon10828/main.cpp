//
//  main.cpp
//  BaekJoon10828
//
//  Created by 신동규 on 2018. 5. 21..
//  Copyright © 2018년 신동규. All rights reserved.
//

#include <iostream>
#include <string> // string 객체 사용을 위한 선언


int main(int argc, const char * argv[]) {
    
    
    int orderea; //명령어 개수 에대한 변수선언.
    int num;
    int top = -1;
    
    std::string order;// string 객체를 사용한 order 변수 선언.
    
    std::cin >> orderea; //명령어 개수를 받아옴.
    
    
    int stack[10000]; //명령수의 최대 치는 10,000이므로 최대 10,000 push 될수있어 10,000크기 배열선언
    
    for (int i = 0; i < orderea; i++){
        
        std::cin >> order ;// 명령어를 받음.
        
        
        if (order == "push"){// push 연산
            
            std::cin >> num;
            top++;
            stack[top] = num;
            
        }
        
        else if (order == "top"){//top 에 있는 값을 출력.
            if (top == -1){
                std::cout << -1<<std::endl;
                
            }
            else{
                std::cout << stack[top]<<std::endl;
            }
            
        }
        
        else if (order == "size"){// 현재  스택의 크기를 출력 top +1의 값은 스택의 크기
            
            std::cout << top+1<<std::endl;
            
            
        }
        
        else if (order == "empty"){ // 스택이 비어있는지 판별 . 1이면 비어있음 0이면 비어있지않음.
            if (top == -1){
                std::cout << 1<<std::endl;
            }
            else{
                std::cout << 0<<std::endl;
                
            }
        }
        
        else if (order == "pop") {
            // pop 연산 top에있는 value를 출력하고 그 인덱스의 값을 초기화 후
            //top을 하나 내린다.
            if (top == -1){
                std::cout << top<<std::endl;// 이미 스택이 비어있으면 -1 를 출력.
                
            }
            else{
                
                std::cout << stack[top]<<std::endl;
                stack[top] = NULL;
                top--;
                
            }
        }
        
        
    }
    
    return 0;
}

