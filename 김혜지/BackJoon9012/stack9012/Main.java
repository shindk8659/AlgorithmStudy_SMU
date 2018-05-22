package stack2;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner=new Scanner(System.in);
		int num=scanner.nextInt();
		
		while(num!=0){
			Stack stack=new Stack();
			String s=scanner.next();
			breakOut:
			if(2<=s.length()&&s.length()<=50){
				for(int i=0;i<s.length();i++){
					char ch=s.charAt(i);
					switch(ch){
						case '(':
							stack.push(ch);
							break;
							
						case ')':
							if(stack.empty()){
								System.out.println("NO");
								num--;
								break breakOut;
							}
							
							else{
								char p=stack.pop();
								if(p !='('){
									System.out.println("NO");
									num--;
									break breakOut;
								}
							}
					}
				}
				if(stack.empty()){
					System.out.println("YES");
					num--;
				}
				else{
					System.out.println("NO");
					num--;
				}
			}
			else
				System.out.println("다시 입력해주세요.");
		}
	}
}