import java.util.Scanner;
import java.util.Comparator;
import java.util.PriorityQueue;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan=new Scanner(System.in);
		int T=scan.nextInt();
		
		for(int i=0; i<T; i++) {
			int command=scan.nextInt();
		
			PriorityQueue<Element>  maxHeap= new PriorityQueue<Element>(command, new Comparator<Element>() { 
				@Override 
				public int compare(Element m1, Element m2)
				{ 
					return m1.n>=m2.n? -1 : 1;
				}
			});
			PriorityQueue<Element>  minHeap= new PriorityQueue<Element>(command, new Comparator<Element>() { 
				@Override 
				public int compare(Element m1, Element m2)
				{ 
					return m1.n>=m2.n? 1 : -1;
				}
			});
			
			
			scan.nextLine();
			for(int j=0; j<command; j++) {
				
				String com=scan.nextLine();
				String qCommand=com.split(" ")[0]; int n=Integer.parseInt(com.split(" ")[1]);
				if(qCommand.equals("I")) {
					Element ele=new Element(n);
					minHeap.add(ele);maxHeap.add(ele);
				}
				else if(qCommand.equals("D")) {
					//���� ��� �� minHeap�� maxHeap ��� visted�� Element�� �����ϰ� ��� ������
					while(maxHeap.isEmpty()==false && maxHeap.peek().visited!=false) {
						//masHeap�� ������� �ʰ� ���ÿ� element�� �̹� �湮 �� ���
						maxHeap.poll();//poll
					}
					while(minHeap.isEmpty()==false && minHeap.peek().visited!=false) {
						minHeap.poll();
					}
					if(maxHeap.isEmpty() || minHeap.isEmpty()) {
						//����ִ� ��� �ƹ� �͵� �������� ���� 
						continue;
					}
					else if(n==1) {
						//�켱���� ���� �� �����ϸ鼭 �ش� Element.visited=true (����ȭ ����)
							maxHeap.poll().visited=true;
					}
					else if(n==-1) {
						//�켱���� ���� �� ����
						minHeap.poll().visited=true;
					}
				}
			}
			while(maxHeap.isEmpty()==false && maxHeap.peek().visited!=false) {
				maxHeap.poll();
			}
			while(minHeap.isEmpty()==false && minHeap.peek().visited!=false) {
				minHeap.poll();
			}
			if(minHeap.isEmpty()||maxHeap.isEmpty())
				System.out.println("EMPTY");
			else {
				System.out.println(maxHeap.peek().n+" "+minHeap.peek().n);
			}		
		}

	}
}

class Element{
	int n;
	boolean visited=false;
	public Element(int n) {
		this.n=n;
	}
}


