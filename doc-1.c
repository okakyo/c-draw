
#include <stdlib.h>
#include <string.h>
#include <math.h>


#include"ps.h"


void frame(void){
	int n,i;
	double x,y,dx,dy;
	arrow(-1.1,0.0,1.1,0.0,0.02,0.0,1.0);	
	arrow(0.0,-1.1,0.0,1.1,0.02,0.0,1.0);
	
	text(1.1,-0.1,1,"x");
	text(-1.1,-0.12,2,"-1");
	text(0.98,-0.12,1,"1");
	text(-0.1,1.1,1,"y");
	text(-0.12,-1.02,2,"-1");
	text(-0.12,0.98,1,"1");
	text(-0.12,-0.1,1,"0");
	
	n=10;
	for(i=1;i<=n;i++){
		x=0.1*i;
		if(i/5*5==i){
			dy=0.02;
				
		}
		else{
			dy=0.01;	
		}
		
		line(-x,-dy,-x,dy,0.0,1.0,1);
		line(x,-dy,x,dy,0.0,1.0,1);
	}
	for(i=1;i<=n;i++){
		y=0.1*i;
		if(i/5*5==i){
			dx=0.02;
				
		}
		else{
			dx=0.01;	
		}
		
		line(-dx,-y,dx,-y,0.0,1.0,1);
		line(-dx,y,dx, y,0.0,1.0,1);
	}
	
	stroke();
	return;
}

void drawline(void){
	int i,nx =100;
	double x,y,x2,y2,pi;
	
	x =-1.0;
	y= 0.0;
	y2=0.0;
	pi = 4.0*atan(1.0);
	
	linewidth(1.5);
	plot(x,y,3);
	
	for(i=-nx+1;i<=nx;i++){
		x = (double) i/(double)nx;
		y = sin(x*pi);
		
		plot(x,y,2);
	}
	
	plot(-1.0,-0.5,3);
	for(i=-nx+1;i<=nx;i++){
		x2 = (double) i/(double)nx;
		y2 = x2/2.0;
		plot(x2,y2,2);
	}

	
	stroke();
	return;
}

int main(){
	init();
	viewport(0.2, 0.2, 0.8, 0.8);
	xyworld(-1.2, -1.2, 1.2, 1.2);
	frame();

	drawline();
	fin();
	return 0;
		
}

