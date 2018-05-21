//
//  main.cpp
//  BaekJoon10828
//
//  Created by 신동규 on 2018. 5. 21..
//  Copyright © 2018년 신동규. All rights reserved.
//

#include <iostream>
#include <string>


int main(int argc, const char * argv[]) {
    
    
    int orderea;
    int num;
    int top = -1;
    
    std::string order;
    
    std::cin >> orderea;
    
    
    int stack[10000];
    
    for (int i = 0; i < orderea; i++){
        
        std::cin >> order ;
        
     
        if (order == "push"){

            std::cin >> num;
            top++;
            stack[top] = num;

        }
        
        else if (order == "top"){
            if (top == -1){
                std::cout << -1<<std::endl;
                
            }
            else{
            std::cout << stack[top]<<std::endl;
            }

        }
        
        else if (order == "size"){
            
            std::cout << top+1<<std::endl;
           

        }
        
        else if (order == "empty"){
            if (top == -1){
                std::cout << 1<<std::endl;
            }
            else{
                std::cout << 0<<std::endl;
            
            }
        }
        
        else if (order == "pop") {
            if (top == -1){
                std::cout << top<<std::endl;
                
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
