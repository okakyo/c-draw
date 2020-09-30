#include <stdio.h>
#include<string.h>
#include<math.h>


double f(double x, double y){
    return x-y;
} 

double g(double x, double y){
    return 4.0-pow(x,2)-pow(y,2);
}

double dfx(double x, double y){
    return 1.0;
}

double dfy(double x, double y){
    return -1.0;
    
}
    
double dgx(double x, double y){
    return -2.0*x;
    
}
    
double dgy(double x, double y){
    return -2.0*y;
}
    
int main(void){
    // Your code here!
    
    int i, n;
    double x0, y0, x, y, f1,g1, ep;
    double a11, a12, a21, a22;
    n = 100;
    i = 0;
    x0 = -1.0;
    y0 = -1.0;
    ep = pow(f(x0,y0),2)+pow(g(x0,y0),2);
    printf("‰Šú’lx:%f,y:%f\n",x0,y0);
    for (i=1; i<=n; i++) {
        f1 = f(x0,y0);
        g1 = g(x0,y0);
        a11= dfx(x0,y0);
        a12= dfy(x0,y0);
        a21= dgx(x0,y0);
        a22= dgy(x0,y0);
        x = x0-( a22*f1-a12*g1)/(a11*a22-a12*a21);
        y = y0-(-a21*f1+a11*g1)/(a11*a22-a12*a21);
        ep = pow(f(x,y),2)+pow(g(x,y),2);
        printf("%3d ‰ñ–Ú, x=%12.7lf, y=%12.7lf, ep= %16.7e\n", i, x, y, ep); 
         if (ep <= 1.0e-12){     
             break;
        };
        x0=x;
        y0=y;
        
    }
    
    return 0;  
}
