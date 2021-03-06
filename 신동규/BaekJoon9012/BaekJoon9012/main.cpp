//
//  main.cpp
//  BaekJoon9012
//
//  Created by 신동규 on 2018. 5. 21..
//  Copyright © 2018년 신동규. All rights reserved.
//

#include <iostream>
#include <string> // c++ 의 string 객체를 사용.

using namespace std;

int main(int argc, const char * argv[]) {
    
    int num; // 몇번의 문자열을 판별할것인지에대한 변수 선언 .
    string parenthesis; //string 객체에 변수 선언.
    
    cin >> num ; // 몇번 문자열을 받을것인지 받아옴.
    
    for (int i = 0 ; i < num; i++){
        // 받은 문자열 만큼 반복해서 문자열을 받기위한 반복문.
        
        cin >> parenthesis;
        int length = (int)parenthesis.length(); // 문자열 길이 반환.
        char *stack = new char[length];// 문자열 길이 만큼의 동적배열 선언.
        int top = -1; // 탑은 -1 부터 시작.
        
        for (int j = 0 ; j < length; j++){
            
            char value = parenthesis[j];
            
            if (value == '('){
                //'x' 는 기계의 문자 집합에있는 문자 x의 숫자 값을 나타내는 정수.
                //"x" 는 길이가 2 자이고 'x' 다음에 '\0' 으로 구성된 문자 배열.
                //' ' 와 "" 를 혼동하지 말것!
                
                top++;
                stack[top] = value;// top을 하나 올려주고 value를 넣는다 . (push 연산)
                
            }
            else{
                if (top == -1){
                    top = 1;
                    //마지막에 다 pop연산 처리되어 top 이 -1 이되어야 YES ,NO 판별
                    //중간에 첫 index에 ')'들어오면 pop 연산이 안되므로 top을 1 로 바꾸고 탈출
                    
                    break;
                    
                }
                else{
                    stack[top] = NULL;//top 위치를 비우고  top을 하나 내린다 (pop 연산)
                    top--;
                    
                }
            }
            
            
        }
        if (top == -1) {
            cout <<"YES"<< endl; // pop 연산이 다되어 스택이 비어있어야 YES
            
        }
        else{
            cout << "NO"<< endl;// pop 연산이 남았거나,
            //첫 index에 ')'이들어와 top 이 1이 된경우 에는     NO
        }
        
        delete [] stack;// 동적할당된 배열 해제
        
        
    }
    
    
    
}
