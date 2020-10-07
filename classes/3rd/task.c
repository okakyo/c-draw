// 1116174065 ���@���� 2020/10/5

#include<stdio.h>
#include<string.h>
#include<math.h>

#include"ps.h"

double func(double x){
	
	return -3.0*pow(x,2)+2.0*x;
	
	}
 

// �f�J���g���W�������ɐݒ肷��
void frame(){
    int n,i;
    double x,y,dx,dy;
    arrow(0,0.0,1.1,0.0,0.02,0.0,1.0);   
    arrow(0.0,0.0,0.0,1.1,0.02,0.0,1.0);

   
    text(1.1,-0.1,1,"t[s]");
    text(0.98,-0.12,1,"5");
    text(-0.1,1.1,1,"theta");
    text(-0.12,0.98,1,"1");
    text(-0.12,0.48,1,"0.5");
    text(-0.12,-0.1,1,"0");

    n=10;
    for(i=1;i<=n;i++){
        x=0.1*i;
        dy=i/5*5==i?0.02:0.01;
       
        line(x,-dy,x,dy,0.0,1.0,1);
    }
    for(i=1;i<=n;i++){
        y=0.1*i;
        dx=i/5*5==i?0.02:0.01;
        
        line(-dx,y,dx, y,0.0,1.0,1);
    }

    stroke();
    
  return;
}


// �`�ʂ������O���t�������ɐݒ肷��
void drawline(){

    int i;
    double l=0.25,dt=0.01, g=9.8,t =5.0;
    double A[1000],V[1000],Theta[1000];
    int n = (int) t / dt;

    double w2=g/l;
    V[0],Theta[0]=0.0,0.5;
    plot(0,Theta[0],3);
    
    A[0]= -w2*sin(Theta[0]);
    V[1] = V[0]+A[0]*dt/2.0;
    Theta[1] = Theta[0]+V[0]*dt/2.0;

    plot(dt,Theta[1],2);

    for(i=2;i<=n;i++){
        A[0]= -w2*sin(Theta[0]);
        V[1] = V[0]+A[0]*dt/2.0;
        Theta[1] = Theta[0]+V[0]*dt/2.0;

        plot(dt*i,Theta[i],2);

    }
    stroke();
    return ;
}

int main(){

  init();
  viewport(0.2, 0.2, 0.8, 0.8); 
  xyworld(-0.2, -1.2, 1.2, 1.2); 
  frame();
  drawline();  
  stroke();
  fin();

  return 0;
}
