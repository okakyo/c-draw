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

   // text(x, y, word): ���W(x,y) �� ����word ����͂���
    text(1.1,-0.1,1,"t[s]");
    text(0.98,-0.12,1,"20");
    text(-0.1,1.1,1,"x");
    text(-0.12,0.98,1,"1");
    text(-0.12,0.48,1,"0.5");
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
  int i,nt;
  double x,t,mt,k1,k2,k3,k4,dt;
  double X[1000],T[1000];
  t = 0.0; x =0.1;
  
  dt = 0.1; // ���̒l��t= 1.0,1.3 �Ƃŏꍇ�ɉ����ĕύX����
  nt = (int)(1.0/dt)*20.0;
  X[0]=0.1;
  T[0]=0.0;
  plot ( t, x, 3);
  
  // �ȉ�, ���ϖ@
  for ( i= 0 ; i <= nt; i++ ){
    t = (double) i / (double) nt;
    mt =20.0*t;
    x = 2.0/(17.0*exp(-2.0*mt)+3.0);  
    plot ( t, x, 2 ); 
  }
  
  // �ȉ��A4�������Q�E�N�b�^�@
  plot ( T[0], X[0], 3);
  plot ( T[0], X[0], 2);
  for(i=1;i<=nt;i++){
	k1 =func(X[i-1]) * dt;
	k2 = func(X[i-1] + k1/2.0) * dt;
	k3 = func(X[i-1]+k2/2.0)*dt;
	k4 = func(X[i-1]+k3)*dt;
	X[i] = X[i-1] +  1.0/6.0*(k1 + 2.0 *k2 + 2.0 *k3+k4);
	T[i] = (double) i * dt;
	plot(T[i]/20.0,X[i],2);
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
