#include "ps.h"

//papersize
double xsize, ysize;

//viewpoint
double xv1, yv1, xv2, yv2;

//world coordinate
double xw1, yw1, xw2, yw2;

FILE* stream;

// plotting routines for general purpose using postscript

void init(void)
{ stream = fopen("temp1.ps", "w");

  // aspect ratio of the paper is 1.4143
    fprintf(stream, "%%! Created by Jiro Mizushima \n");
    fprintf(stream, "/Times-Roman findfont 18 scalefont setfont \n");
    fprintf(stream, "/cm {28.35 mul} def \n");

  xsize = 21.0;/* ysize = 29.7;*/ ysize = 21.0;
  viewport(0.2, 0.2, 0.8, 0.8);
  xyworld(0.0, 0.0, 1.0, 1.0);
  linety(1); linewidth(1);
  return;
}

void viewport(double xv1d, double yv1d, double xv2d, double yv2d)
{
  xv1 = xv1d; yv1 = yv1d; xv2 = xv2d; yv2 = yv2d;
  return;
}

void xyworld(double xw1d, double yw1d, double xw2d, double yw2d)
{
  xw1 = xw1d; yw1 = yw1d; xw2 = xw2d; yw2 = yw2d;
  return;
}

void fin(void)
{
  stroke(); fprintf(stream, "showpage\n"); fclose(stream);
  return;
}

void linety(int ichar)
{
  switch (ichar) {
    case 1: fprintf(stream, "[] 0 setdash \n"); break;
    case 2: fprintf(stream, "[2 2] 0 setdash \n");break;
    case 3: fprintf(stream, "[8 2] 0 setdash \n");break;
    case 4: fprintf(stream, "[8 1 1 1] 0 setdash \n");break;
  }
  return;
}

void linewidth(double w)
{
  fprintf(stream, "%lf setlinewidth\n", w); return;
}

void setgray(double g)
{
  fprintf(stream, "%lf setgray\n", g); return;
}

void setrgb(double r,double g,double b)
{
  fprintf(stream, "%lf %lf %lf setrgbcolor\n",r,g,b); return;
}

void newpath(void)
{
  fprintf(stream, "newpath\n"); return;
}

void closepath(void)
{
  fprintf(stream, "closepath\n"); return;
}

void fill(void)
{
  fprintf(stream, "fill\n"); return;
}

void stroke(void)
{ 
  fprintf(stream, "stroke\n"); 
}

void rotate(int itheta)
{ 
  fprintf(stream, "%d rotate\n",itheta); 
}

void scale(double tx, double ty)
{ 
  fprintf(stream, "%lf %lf scale\n",tx, ty); 
}

void transrate(double x, double y)
{ double x1,y1;
  x1 = ((x-xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  y1 = ((y-yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
  fprintf(stream, "%lf cm %lf cm translate\n", x1, y1);
}

void clipon(double x1, double y1, double x2, double y2)
{ 
  newpath();
  plot(x1, y1, 3);plot(x2, y1, 2);plot(x2, y2,2); plot(x1, y2, 2);
  closepath();
  fprintf(stream, "clip\n");
}

void eoclipon(double x1, double y1, double x2, double y2)
{ 
  newpath();
  plot(x1, y1, 3);plot(x2, y1, 2);plot(x2, y2,2); plot(x1, y2, 2);
  closepath();
  fprintf(stream, "eoclip\n");
}

void clipoff(void)
{
  fprintf(stream, "clip\n");
}

void plot(double x, double y, int ipen)
{
  double x1, y1;

  x1 = ((x-xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  y1 = ((y-yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
  switch (ipen) {
    case 3: fprintf(stream, "%lf cm %lf cm moveto\n", x1,y1);
      break;
    case 2: fprintf(stream, "%lf cm %lf cm lineto\n", x1,y1);
      break;
     }
  return;
}

void line(double x, double y, double xx, double yy, double g, double w, int it)
{
  double x1, y1, xx1, yy1;

  x1  = ((x -xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  y1  = ((y -yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
  xx1 = ((xx-xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  yy1 = ((yy-yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
  linewidth(w);linety(it);setgray(g);
  fprintf(stream, "%lf cm %lf cm moveto\n", x1, y1);
  fprintf(stream, "%lf cm %lf cm lineto\n", xx1, yy1);
  stroke();
  linety(1); linewidth(1);setgray(0.0);
  return;
}

void line1(double x, double y, double xx, double yy)
{
  double x1, y1, xx1, yy1;

  x1  = ((x -xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  y1  = ((y -yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
  xx1 = ((xx-xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  yy1 = ((yy-yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
  fprintf(stream, "%lf cm %lf cm moveto\n", x1, y1);
  fprintf(stream, "%lf cm %lf cm lineto\n", xx1, yy1);
  stroke();
  return;
}


void rect(double x1, double y1, double x2, double y2, double g, double w, int it)
{
  linewidth(w);linety(it);setgray(g);
  newpath();plot(x1,y1,3);plot(x2,y1,2);plot(x2,y2,2);plot(x1,y2,2);
  closepath();
  if(g!=0.0) fprintf(stream, " fill\n");
  stroke();
  linety(1); linewidth(1);setgray(0.0);
  return;
}

void rect1(double x1, double y1, double x2, double y2)
{
  newpath();plot(x1,y1,3);plot(x2,y1,2);plot(x2,y2,2);plot(x1,y2,2);
  closepath();
  stroke();
  return;
}

void rectfill1(double x1, double y1, double x2, double y2)
{
  newpath();plot(x1,y1,3);plot(x2,y1,2);plot(x2,y2,2);plot(x1,y2,2);
  closepath();
  fprintf(stream, " fill\n");
  stroke();
  return;
}

void circ(double x1, double y1, double r1, double g, double w, int it)
{ 
  double xx1,yy1,rr1;
  xx1 = ((x1-xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  yy1 = ((y1-yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
  rr1 = r1/(xw2-xw1)*(xv2-xv1)*xsize;
  linewidth(w);linety(it);setgray(g);
  newpath();
  fprintf(stream, "%lf cm %lf cm %lf cm 0 360 arc\n", xx1, yy1, rr1);
  if(g!=0.0) fprintf(stream, " fill\n");
  stroke();
  linety(1); linewidth(1);setgray(0.0);
  return;
}

void circ1(double x1, double y1, double r1)
{ 
  double xx1,yy1,rr1;
  xx1 = ((x1-xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  yy1 = ((y1-yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
  rr1 = r1/(xw2-xw1)*(xv2-xv1)*xsize;
  newpath();
  fprintf(stream, "%lf cm %lf cm %lf cm 0 360 arc\n", xx1, yy1, rr1);
  stroke();
  return;
}

void circfill1(double x1, double y1, double r1)
{ 
  double xx1,yy1,rr1;
  xx1 = ((x1-xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  yy1 = ((y1-yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
 //  rr1 = (r1-xw1)/(xw2-xw1)*(xv2-xv1)*xsize;
  rr1 = r1/(xw2-xw1)*(xv2-xv1)*xsize;
  newpath();
  fprintf(stream, "%lf cm %lf cm %lf cm 0 360 arc\n", xx1, yy1, rr1);
  fprintf(stream, " fill\n");
  stroke();
  return;
}

void ellipse(double x1, double y1, double rx, double ry, double g, double w, int it)
{     
      double x, y, dt; int i;

      linety(it);
      linewidth(w);
      setgray(g);
      newpath();
      x=x1+rx; y=y1; dt=3.14156*2.0/20.0;
      plot(x,y,3); 
      for (i=1;i<=20;i++) { 
             x=x1+rx*cos(dt*i);y=y1+ry*sin(dt*i); plot(x,y,2);
             }
      if(g!=0.0) {fprintf(stream, "fill\n");}
      stroke();  
      linety(1); linewidth(1.0); setgray(0.0); return; 
}

void ellipse1(double x1, double y1, double rx, double ry)
{     
      double x, y, dt; int i;

      newpath(); 
      x=x1+rx; y=y1; dt=3.14156*2.0/20.0;
      plot(x,y,3); 
      for (i=1;i<=20;i++) { 
             x=x1+rx*cos(dt*i);y=y1+ry*sin(dt*i); plot(x,y,2);
             }
      stroke();  
}

void ellipsefill1(double x1, double y1, double rx, double ry)
{     
      double x, y, dt; int i;

      newpath(); 
      x=x1+rx; y=y1; dt=3.14156*2.0/20.0;
      plot(x,y,3); 
      for (i=1;i<=20;i++) { 
             x=x1+rx*cos(dt*i);y=y1+ry*sin(dt*i); plot(x,y,2);
             }
      fprintf(stream, "fill\n");
      stroke();  
}

void arc(double x1, double y1, double r1, double t1, double t2, double g, double w, int it)
{ 
   double xx1,yy1,rr1;
   
   xx1=((x1-xw1)/(xw2-xw1)*(xv2-xv1)+xv1)*xsize; 
   yy1=((y1-yw1)/(yw2-yw1)*(yv2-yv1)+yv1)*ysize; 
   rr1=(r1/(xw2-xw1)*(xv2-xv1))*xsize; 
   linety(it); linewidth(w); setgray(g); 
   newpath(); 
   fprintf(stream,"%lf cm %lf cm %lf cm %lf %lf arc \n",xx1,yy1,rr1,t1,t2);
   stroke(); linety(1); linewidth(1.0); setgray(0.0); 
   return;
}

void arc1(double x1, double y1, double r1, double t1, double t2)
{ 
   double xx1,yy1,rr1;
   
   xx1=((x1-xw1)/(xw2-xw1)*(xv2-xv1)+xv1)*xsize; 
   yy1=((y1-yw1)/(yw2-yw1)*(yv2-yv1)+yv1)*ysize; 
   rr1=(r1/(xw2-xw1)*(xv2-xv1))*xsize; 
   newpath(); 
   fprintf(stream,"%lf cm %lf cm %lf cm %lf %lf arc \n",xx1,yy1,rr1,t1,t2);
   return;
}

void curv(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double g, double w, int it)
{
      double xx2,yy2,xx3,yy3,xx4,yy4;

     xx2=((x2-xw1)/(xw2-xw1)*(xv2-xv1)+xv1)*xsize;
     yy2=((y2-yw1)/(yw2-yw1)*(yv2-yv1)+yv1)*ysize;
     xx3=((x3-xw1)/(xw2-xw1)*(xv2-xv1)+xv1)*xsize;
     yy3=((y3-yw1)/(yw2-yw1)*(yv2-yv1)+yv1)*ysize;
     xx4=((x4-xw1)/(xw2-xw1)*(xv2-xv1)+xv1)*xsize;
     yy4=((y4-yw1)/(yw2-yw1)*(yv2-yv1)+yv1)*ysize;
     linety(it); linewidth(w); setgray(g);
     newpath(); plot(x1,y1,3);
     fprintf(stream, "%lf cm %lf cm %lf cm %lf cm %lf cm %lf cm curveto\n", xx2 ,yy2,xx3,yy3,xx4,yy4); 
      stroke();
      linety(1);linewidth(1.0); setgray(0.0);
      return;
}

void curv1(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
      double xx2,yy2,xx3,yy3,xx4,yy4;

     xx2=((x2-xw1)/(xw2-xw1)*(xv2-xv1)+xv1)*xsize;
     yy2=((y2-yw1)/(yw2-yw1)*(yv2-yv1)+yv1)*ysize;
     xx3=((x3-xw1)/(xw2-xw1)*(xv2-xv1)+xv1)*xsize;
     yy3=((y3-yw1)/(yw2-yw1)*(yv2-yv1)+yv1)*ysize;
     xx4=((x4-xw1)/(xw2-xw1)*(xv2-xv1)+xv1)*xsize;
     yy4=((y4-yw1)/(yw2-yw1)*(yv2-yv1)+yv1)*ysize;
     newpath(); plot(x1,y1,3);
     fprintf(stream, "%lf cm %lf cm %lf cm %lf cm %lf cm %lf cm curveto\n", xx2 ,yy2,xx3,yy3,xx4,yy4); 
      stroke();
      return;
}

void triangl(double x1, double y1, double r1, double a1, double g, double w, int it)
{
    double aa1,aa2;

     aa1=a1*3.14159/180.0;
     aa2=aa1+3.14159/3.0;
     linety(it); linewidth(w); setgray(g); 
     newpath(); plot(x1,y1,3); plot(x1+r1*cos(aa1), y1+r1*sin(aa1), 2);
     plot(x1+r1*cos(aa2), y1+r1*sin(aa2), 2);
     closepath();
       if(g!=0.0) {fprintf(stream, "fill\n");}
     stroke(); 
     linety(1); linewidth(1.0); setgray(0.0);
     return; 
}

void triangl1(double x1, double y1, double r1, double a1)
{
    double aa1,aa2;

     aa1=a1*3.14159/180.0;
     aa2=aa1+3.14159/3.0;
     newpath(); plot(x1,y1,3); plot(x1+r1*cos(aa1), y1+r1*sin(aa1), 2);
     plot(x1+r1*cos(aa2), y1+r1*sin(aa2), 2);
     closepath();
     stroke(); 
     return; 
}

void trianglfill1(double x1, double y1, double r1, double a1)
{
    double aa1,aa2;

     aa1=a1*3.14159/180.0;
     aa2=aa1+3.14159/3.0;
     newpath(); plot(x1,y1,3); plot(x1+r1*cos(aa1), y1+r1*sin(aa1), 2);
     plot(x1+r1*cos(aa2), y1+r1*sin(aa2), 2);
     closepath();
     fprintf(stream, "fill\n");
     stroke(); 
     return; 
}


void spline(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int ipart, double g, double w)
{ int ns=10,i; double u,x,y; 
   
  linewidth(w); setgray(g); 
  newpath(); 
  u=(double) ipart; 
  x=-u*(u-1.)*(u-2.)/6.*x1+(u+1.)*(u-1.)*(u-2.)/2.*x2-(u+1.)*u*(u-2.)/2.*x3+(u+1.)*u*(u-1.)/6.*x4; 
  y=-u*(u-1.)*(u-2.)/6.*y1+(u+1.)*(u-1.)*(u-2.)/2.*y2-(u+1.)*u*(u-2.)/2.*y3+(u+1.)*u*(u-1.)/6.*y4; 
  plot(x,y,3); 
   for (i=1;i<=ns;i++){
    u=(double) ipart +(double) i /(double) ns;
    x=-u*(u-1.)*(u-2.)/6.*x1+(u+1.)*(u-1.)*(u-2.)/2.*x2-(u+1.)*u*(u-2.)/2.*x3+(u+1.)*u*(u-1.)/6.*x4; 
    y=-u*(u-1.)*(u-2.)/6.*y1+(u+1.)*(u-1.)*(u-2.)/2.*y2-(u+1.)*u*(u-2.)/2.*y3+(u+1.)*u*(u-1.)/6.*y4; 
    plot(x,y,2); 
    }
   stroke();
   linewidth(1.0); setgray(0.0); 
   return;
}

void spline1(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int ipart)
{ int ns=10,i; double u,x,y; 
   
  newpath(); 
  u=(double) ipart; 
  x=-u*(u-1.)*(u-2.)/6.*x1+(u+1.)*(u-1.)*(u-2.)/2.*x2-(u+1.)*u*(u-2.)/2.*x3+(u+1.)*u*(u-1.)/6.*x4; 
  y=-u*(u-1.)*(u-2.)/6.*y1+(u+1.)*(u-1.)*(u-2.)/2.*y2-(u+1.)*u*(u-2.)/2.*y3+(u+1.)*u*(u-1.)/6.*y4; 
  plot(x,y,3); 
   for (i=1;i<=ns;i++){
    u=(double) ipart +(double) i/(double) ns;
    x=-u*(u-1.)*(u-2.)/6.*x1+(u+1.)*(u-1.)*(u-2.)/2.*x2-(u+1.)*u*(u-2.)/2.*x3+(u+1.)*u*(u-1.)/6.*x4; 
    y=-u*(u-1.)*(u-2.)/6.*y1+(u+1.)*(u-1.)*(u-2.)/2.*y2-(u+1.)*u*(u-2.)/2.*y3+(u+1.)*u*(u-1.)/6.*y4; 
    plot(x,y,2); 
    }
   stroke();
   return;
}

void parabola(double x1, double y1, double x2, double y2, double x3, double y3, double g, double w, int it)
{
      double u,x,y; int i,ns=20; u=0.0;
      linewidth(w); setgray(g); linety(it); 
      newpath(); 
      x=(u-1.)*(u-2.)/2.*x1-u*(u-2.)*x2+u*(u-1.)/2.*x3; 
      y=(u-1.)*(u-2.)/2.*y1-u*(u-2.)*y2+u*(u-1.)/2.*y3; 
      plot(x,y,3); 
      for (i=1; i<=2*ns; i++)
        { u=(double) i/(double) ns; 
          x=(u-1.)*(u-2.)/2.*x1-u*(u-2.)*x2+u*(u-1.)/2.*x3; 
          y=(u-1.)*(u-2.)/2.*y1-u*(u-2.)*y2+u*(u-1.)/2.*y3; 
          plot(x,y,2); 
         } stroke(); 
      linewidth(1.0); setgray(0.0); linety(1);
      return; 
}

void parabola1(double x1, double y1, double x2, double y2, double x3, double y3)
{
      double u,x,y; int i,ns=20; u=0.0;
      newpath(); 
      x=(u-1.)*(u-2.)/2.*x1-u*(u-2.)*x2+u*(u-1.)/2.*x3; 
      y=(u-1.)*(u-2.)/2.*y1-u*(u-2.)*y2+u*(u-1.)/2.*y3; 
      plot(x,y,3); 
      for (i=1; i<=2*ns; i++)
        { u=(double) i/(double) ns; 
          x=(u-1.)*(u-2.)/2.*x1-u*(u-2.)*x2+u*(u-1.)/2.*x3; 
          y=(u-1.)*(u-2.)/2.*y1-u*(u-2.)*y2+u*(u-1.)/2.*y3; 
          plot(x,y,2); 
         } stroke(); 
      return; 
}

void arrow(double x1, double y1, double x2, double y2, double d, double g, double w)
{
   double alpha=2.2,s,x3,y3,x4,y4;
   s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
   x3=x2-(x2-x1)/s*d*alpha-(y2-y1)/s*d;
   y3=y2-(y2-y1)/s*d*alpha+(x2-x1)/s*d;
   x4=x2-(x2-x1)/s*d*alpha+(y2-y1)/s*d;
   y4=y2-(y2-y1)/s*d*alpha-(x2-x1)/s*d;
   linewidth(w); setgray(g); 
   plot(x1, y1, 3); plot(x2, y2, 2); 
   plot(x2, y2, 3); plot(x3, y3, 2); plot(x2, y2, 3); plot(x4, y4, 2); 
   stroke(); linety(1); linewidth(1.0); setgray(0.0); 
   return; 
}

void arrow1(double x1, double y1, double x2, double y2, double d)
{
   double alpha=2.2,s,x3,y3,x4,y4;
   s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
   x3=x2-(x2-x1)/s*d*alpha-(y2-y1)/s*d;
   y3=y2-(y2-y1)/s*d*alpha+(x2-x1)/s*d;
   x4=x2-(x2-x1)/s*d*alpha+(y2-y1)/s*d;
   y4=y2-(y2-y1)/s*d*alpha-(x2-x1)/s*d;
   plot(x1, y1, 3); plot(x2, y2, 2); 
   plot(x2, y2, 3); plot(x3, y3, 2); plot(x2, y2, 3); plot(x4, y4, 2); 
   stroke(); 
   return; 
}


void resist(double x1, double y1, double x2, double y2, double d, double w)
{
   double s, dx, dy, ex, ey, xx, yy;int i; 
      s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
      linewidth(w); 
      dx=(x2-x1)/12.0; dy=(y2-y1)/12.0; 
      ex=-d*dy; ey=d*dx; 
       plot(x1, y1, 3); xx=x1+dx+ex; yy=y1+dy+ey; plot(xx, yy, 2); 
      for(i=1;i<=5; i++){
        xx=x1+(i*2+1)*dx+pow(-1,i)*ex; yy=y1+(i*2+1)*dy+pow(-1,i)*ey; 
        plot(xx, yy, 2);
        }
      plot(x2, y2, 2); 
      stroke(); linety(1); linewidth(1.0); 
     return;
}

void battery(double x1, double y1, double x2, double y2, double d, double w)
{
    double s,dx,dy,ex,ey,xx,yy; 
  
    s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)); 
    linewidth(w); 
     dx=(x2-x1)/3.0; dy=(y2-y1)/3.0; 
     ex=-dy; ey=dx; 
     plot(x1, y1, 3); xx=x1+dx; yy=y1+dy; plot(xx, yy, 2); stroke();
    linewidth(2.0*w); 
     xx=x1+dx+3.0*ex; yy=y1+dy+3.0*ey; 
      plot(xx, yy, 3); xx=x1+dx-3.0*ex; yy=y1+dy-3.0*ey; plot(xx, yy, 2); stroke(); 
     xx=x1+2.0*dx+ex; yy=y1+2.0*dy+ey; 
      plot(xx, yy, 3); xx=x1+2.0*dx-ex; yy=y1+2.0*dy-ey; plot(xx, yy, 2); stroke(); 
    linewidth(w);
      plot(x2, y2, 3); xx=x2-dx; yy=y2-dy; plot(xx, yy, 2); stroke(); 
    linewidth(1.0); linety(1); 
    return;
}

void coil(double x1, double y1, double x2, double y2, double d, int n, double w)
{
   double s,ex,ey,ds,a,xx,yy,t;
   int i;

   s=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
   linewidth(w);
   ex=(x2-x1)/s;
   ey=(y2-y1)/s;
   a=2.0; ds=(s-2.0*d)/((double) n +0.5);
     plot(x1, y1, 3);
     for(i=1;i<=(40*n+20);i++) {
      t=2.0*3.14159*(double) i/40.0; 
      xx=x1+((d-d*cos(t))+t/2.0/3.14159*ds)*ex-a*d*sin(t)*ey;
      yy=y1+((d-d*cos(t))+t/2.0/3.14159*ds)*ey+a*d*sin(t)*ex;
      plot(xx, yy, 2);
      }  stroke();
    linewidth(1.0);linety(1);
    return;
}

void text(double x, double y, int n, char* str1)
{
  double x1, y1;

  x1 = ((x-xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  y1 = ((y-yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
    fprintf(stream, "%lf cm %lf cm moveto\n", x1, y1);
    fprintf(stream, "(%s) show\n", str1);
  return;
}

void textx(double x, double y, int n, char* str1)
{
      plot(x, y, 3); 
      fprintf(stream, "%lf %lf rmoveto\n", -n/2.0*9.0,-3.0/2.0*15.0);
      fprintf(stream, "(%s) show\n", str1);
      return;
}

void  texty(double x, double y, int n, char* str1)
{ 
      plot(x, y, 3); 
       fprintf(stream, "%lf %lf rmoveto\n", -(n+1)*9.0,-1.0/2.0*12.0);
      fprintf(stream, "(%s) show\n", str1);
      return;
}

void setchar(int ichar, int ip)
{
 switch (ichar) {
  case 1:fprintf(stream, "/Times-Roman findfont %d scalefont setfont \n",ip);
      break;
  case 2:fprintf(stream, "/Times-Bold findfont %d scalefont setfont \n",ip);
      break;
  case 3:fprintf(stream, "/Times-Italic findfont %d scalefont setfont \n",ip);
      break;
  case 4:fprintf(stream, "/Times-BoldItalic findfont %d scalefont setfont \n",ip);
      break;
  case 5:fprintf(stream, "/Helvetica findfont %d scalefont setfont \n",ip);
      break;
  case 6:fprintf(stream, "/Helvetica-Bold findfont %d scalefont setfont \n",ip);
      break;
  case 7:fprintf(stream, "/Helvetica-Oblique findfont %d scalefont setfont \n",ip);
      break;
  case 8:fprintf(stream, "/Helvetica-BoldOblique findfont %d scalefont setfont \n",ip);
      break;
  case 9:fprintf(stream, "/Courier findfont %d scalefont setfont \n",ip);
      break;
  case 10:fprintf(stream, "/Courier-Bold findfont %d scalefont setfont \n",ip);
      break;
  case 11:fprintf(stream, "/Courier-Oblique findfont %d scalefont setfont \n",ip);
      break;
  case 12:fprintf(stream, "/Courier-BoldOblique findfont %d scalefont setfont \n",ip);
      break;
  case 13:fprintf(stream, "/Symbol findfont %d scalefont setfont \n",ip);
      break;
   }
  return;
}

void square(double x, double y)
{
  double x1, y1, delta;

  x1 = ((x-xw1)/(xw2-xw1)*(xv2-xv1) + xv1)*xsize;
  y1 = ((y-yw1)/(yw2-yw1)*(yv2-yv1) + yv1)*ysize;
  delta = 0.1;
  fprintf(stream, "%lf cm %lf cm moveto\n", x1-delta,y1-delta);
  fprintf(stream, "%lf cm %lf cm lineto\n", x1+delta,y1-delta);
  fprintf(stream, "%lf cm %lf cm moveto\n", x1+delta,y1+delta);
  fprintf(stream, "%lf cm %lf cm lineto\n", x1-delta,y1+delta);
  closepath();stroke();
  return;
}

