package stack1;
import java.util.Scanner;

public class StackMain {
	public static void main(String[] args){
		Scanner scanner=new Scanner(System.in);
		int number=scanner.nextInt();
		
		Stack stack=new Stack();
		if(1<=number&&number<=10000){
			while(number!=0){
				String s=scanner.next();
				if(s.equals("push")){
					int x=scanner.nextInt();
					stack.push(x);
					number--;
				}
				else if(s.equals("pop")){
					stack.pop();
					number--;
				}
				else if(s.equals("size")){
					stack.size();
					number--;
				}
				else if(s.equals("empty")){
					stack.empty();
					number--;
				}
				else if(s.equals("top")){
					stack.top();
					number--;
				}
				else{
					System.out.println("rewrite!");
				}
			}
		}		
		scanner.close();
	}

}
