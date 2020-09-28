#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.141592653585793

void init(void);
void viewport(double, double, double, double);
void xyworld(double, double, double, double);
void fin(void);
void linety(int);
void linewidth(double);
void setgray(double);
void setrgb(double, double, double);
void newpath(void);
void fill(void);
void closepath(void);
void stroke(void);
void rotate(int);
void scale(double, double);
void transrate(double, double);
void clipon(double, double, double, double);
void eoclipon(double, double, double, double);
void clipoff(void);
void plot(double, double, int);
void line(double, double, double, double, double, double, int);
void line1(double, double, double, double);
void rect(double, double, double, double, double, double, int);
void rect1(double, double, double, double);
void rectfill1(double, double, double, double);
void circ(double, double, double, double, double, int);
void circ1(double, double, double);
void circfill1(double, double, double);
void ellipse(double, double, double, double, double, double, int);
void ellipse1(double, double, double, double);
void ellipsefill1(double, double, double, double);
void arc(double, double, double, double, double, double, double, int);
void arc1(double, double, double, double, double);
void curv(double, double, double, double, double, double, double, double, double, double, int);
void curv1(double, double, double, double, double, double, double, double);
void triangl(double, double, double, double, double, double, int);
void triangl1(double, double, double, double);
void trianglfill1(double, double, double, double);
void spline(double, double, double, double, double, double, double, double, int, double, double);
void spline1(double, double, double, double, double, double, double, double, int);
void parabola(double, double, double, double, double, double, double, double, int);
void parabola1(double, double, double, double, double, double);
void arrow(double, double, double, double, double, double, double);
void arrow1(double, double, double, double, double);
void resist(double, double, double, double, double, double); 
void battery(double, double, double, double, double, double);
void coil(double, double, double, double, double, int, double);
void text(double, double, int, char* );
void textx(double, double, int, char* );
void texty(double, double, int, char* );

void setchar(int, int);
void square(double, double);

