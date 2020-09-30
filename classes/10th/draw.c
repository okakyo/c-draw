
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ps.h"

/*
	Void 型
	ここで、デカルト座標を描写する
*/

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



int main(){
	init();
	viewport(0.2, 0.2, 0.8, 0.8);
	xyworld(-1.2, -1.2, 1.2, 1.2);
	frame();
	fin();
	return 0;
		
}

