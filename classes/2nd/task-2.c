// 1116174065 ���@���� 2020/10/5

#include<stdio.h>
#include<string.h>
#include<math.h>

#include"ps.h"

double func(double x){
	
	return -pow(x,2)+x;
	
	}
 

// �f�J���g���W�������ɐݒ肷��
void frame(){
    int n,i;
    double x,y,dx,dy;
    arrow(0,0.0,1.1,0.0,0.02,0.0,1.0);   
    arrow(0.0,0.0,0.0,1.1,0.02,0.0,1.0);

   // text(x, y, word): ���W(x,y) �� ����word ����͂���
    text(1.1,-0.1,1,"t[s]");
    text(0.98,-0.12,1,"20");
    text(-0.1,1.1,1,"x");
    text(-0.12,0.98,1,"2");
    text(-0.12,0.48,1,"1");
    text(-0.12,-0.1,1,"0");

  // �����ŃO���t�ɖڐ������͂���
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
  int i,nt =200;
  double x,t,mt,k1,k2,dt=0.1;
  double X[1000],T[1000];
  t = 0.0; x =0.1;
   
  X[0]=0.1;
  T[0]=0.0;
  plot ( t, x, 3);
  for ( i= 0 ; i <= nt; i++ ){
    t = (double) i / (double) nt;
    mt =20.0*t;
    x = 1.0/(9.0*exp(-mt)+1.0);  
    plot ( t, x/2.0, 2 ); 
  }
  
  plot ( T[0], X[0]/2.0, 3);
  plot ( T[0], X[0]/2.0, 2);
  for(i=1;i<=nt;i++){
	k1 =func(X[i-1]) * dt;
	k2 = func(X[i-1] + k1) * dt;
	X[i] = X[i-1] + 0.5 * (k1 + k2);
	T[i] = (double) i * dt;
	plot(T[i]/20.0,X[i]/2.0,2);
  }
  
  stroke();
  return ;
}

int main(){

  init();
  viewport(0.2, 0.2, 0.8, 0.8); 
  xyworld(0, 0, 1.2, 1.2); 
  frame();
  drawline();  
  stroke();
  fin();

  return 0;
}
