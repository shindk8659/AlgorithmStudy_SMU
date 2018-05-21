//
//  main.cpp
//  BaekJoon9012
//
//  Created by 신동규 on 2018. 5. 21..
//  Copyright © 2018년 신동규. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int num;
    string parenthesis;
    string open = "(";
    
    
    cin >> num ;
    
    for (int i = 0 ; i < num; i++){
        
        
        cin >> parenthesis;
        int length = (int)parenthesis.length();
        char *stack = new char[length];
        int top = -1;
        
        for (int j = 0 ; j < length; j++){
        
            char value = parenthesis[j];
            
            if (value == '('){//'x' 는 기계의 문자 집합에있는 문자 x의 숫자 값을 나타내는 정수입니다.
                             //"x" 는 길이가 2 자이고 'x' 다음에 '\0' 으로 구성된 문자 배열입니다.
                top++;
                stack[top] = value;
               
            }
            else{
                if (top == -1){
                    top = 1;
                    break;
                }
                else{
                stack[top] = NULL;
                top--;
              
                }
            }
            
           
        }
        if (top == -1) {
            cout <<"YES"<< endl;
            
        }
        else{
             cout << "NO"<< endl;
        }
        


    }
    
    
       
        
        

    
    
}
