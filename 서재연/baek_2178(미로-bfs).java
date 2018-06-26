
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
   /*
    *4 6
101111
101010
101011
111011
    */
   
   /* ���� ��ġ���� �ش� �������� �Ÿ��� ������ �� �ֵ��� ����*/

   public static void main(String[] args) {
      // TODO Auto-generated method stub
        Scanner scan=new Scanner(System.in);
          
          int N=scan.nextInt(); int M=scan.nextInt();
          int[][] matrix=new int[N][M];
       
          Vertex[][] vertex=new Vertex[N][M];
          for(int i=0; i<N; i++)
        	  for(int j=0; j<M; j++) {
        		  vertex[i][j]=new Vertex();
        		  vertex[i][j].dist=N*M;
        	    }

          
          scan.nextLine();
          for(int i=0; i<N; i++){
            String line=scan.nextLine();
            for(int j=0; j<M; j++){
              matrix[i][j]=Integer.parseInt(line.substring(j,j+1));
              vertex[i][j].x=i; vertex[i][j].y=j;
            }
          }
          


          Queue<Vertex> queue=new LinkedList<Vertex>();
          vertex[0][0].dist=1;
          queue.add(vertex[0][0]);

          
          while(queue.peek()!=null) {
        	//���̻� �湮�� ��尡 ���ٸ�
        	if(queue.peek()==null) break;
        	
          	if(queue.peek().visited==true) {
          		//�̹� �湮�� ����� �Ѿ
          		queue.poll();
          		continue;
          	}
          	else {
          		//ó�� �湮�ߴٸ� �湮 üũ�ϰ� ���� ����
          		queue.peek().visited=true;
          		
          	}

          	int nx=queue.peek().x; int ny=queue.peek().y;
          	//���� �� ����
          	if(nx!=0 && matrix[nx-1][ny]==1) {
          		if(vertex[nx-1][ny].dist>queue.peek().dist+1) 
          			vertex[nx-1][ny].dist=queue.peek().dist+1;
          		queue.add(vertex[nx-1][ny]);
          		
          	}
          	//������ �� ����
          	if(ny!=M-1 && matrix[nx][ny+1]==1) {
          		if(vertex[nx][ny+1].dist>queue.peek().dist+1)
          			vertex[nx][ny+1].dist=queue.peek().dist+1;
          		queue.add(vertex[nx][ny+1]);
          	}
          	//���� �� ����
          	if(ny!=0 && matrix[nx][ny-1]==1) {
          		if(vertex[nx][ny-1].dist>queue.peek().dist+1)
          			vertex[nx][ny-1].dist=queue.peek().dist+1;
          		queue.add(vertex[nx][ny-1]);
          	}
          	//�Ʒ��� �� ����
          	if(nx!=N-1 && matrix[nx+1][ny]==1) 
          	{
          		if(vertex[nx+1][ny].dist>queue.peek().dist+1)
          			vertex[nx+1][ny].dist=queue.peek().dist+1;
          		queue.add(vertex[nx+1][ny]);
          	}
          	queue.poll();
          }
          
          System.out.println(vertex[N-1][M-1].dist);
          
          
     }
       

   

}

class Vertex{
   //�ʱ� �ε��� 
    int x=-1; int y=-1;
    //���� Vertex
    LinkedList<Vertex> linkedList=new LinkedList<Vertex>();
    int dist=-1;
    
    boolean visited=false;
    
  }

