//COMPUTACI�N II, Pr�ctica 15, Resoluci�n de ecuaciones diferenciales de orden n con condiciones iniciales
// RK4 with second order ODE

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
const int n=4;// numero de ecuaciones de primer orden acopladas
const double PI=2.0*asin(1.0);
double f1 (double t, double y[n]);
double f2 (double t, double y[n]);
double f3 (double t, double y[n]);
double f4 (double t, double y[n]);
double (*Af[n]) (double t, double y[n])={f1, f2, f3, f4}; // array de punteros a funciones 
void RK4(double (*Af[n])(double t, double y[n]), double t0, double h, double y[n]);

int main()
{   
double t0=0, h=0.1;
double y[n]={3,4,0,0}; // condiciones iniciales
cout << setprecision(15);
RK4(Af,t0,h,y); // llamada a la funcion RK4
return 0;
}

double f1(double t, double y[n])
{ return y[2];}

double f2(double t, double y[n])
{ return y[3];}

double f3(double t, double y[n])
{ 
double k1=2.5, k2=3.5, m1=2.0, m2=3.5;
return (-(k1/m1)*y[0]-(k2/m1)*(y[0]-y[1]));
}

double f4(double t, double y[n])
{ 
double k1=2.5, k2=3.5, m1=2.0, m2=3.5;
return ((k2/m2)*(y[0]-y[1]));
}

void RK4(double (*Af[n])(double t, double y[n]), double t0, double h, double y[n])
{
  int j;
  // Hay que abrir el flujo en la funcion
  ofstream fsalida("Oscilaciones.dat", ios::out);
  if (!fsalida)
    {cout << "No se puede abrir el archivo";}
  double t=t0, k1[n], k2[n], k3[n], k4[n], yy[n];
  cout << t;
  fsalida << t;
    for (j=0; j<n; j++) 
    { cout << "   " << y[j];
      fsalida << "   " << y[j];
    }
    cout << endl;
    fsalida << endl;
   do {
    for (j=0; j<n; j++)    { k1[j]=h*Af[j](t,y);}
    for (j=0; j<n; j++)    { yy[j]=y[j]+0.5*k1[j];}
    for (j=0; j<n; j++)    { k2[j]=h*Af[j](t+0.5*h,yy);}
    for (j=0; j<n; j++)    { yy[j]=y[j]+0.5*k2[j];}
    for (j=0; j<n; j++)    { k3[j]=h*Af[j](t+0.5*h,yy); }
    for (j=0; j<n; j++)    { yy[j]=y[j]+k3[j];}
    for (j=0; j<n; j++)    { k4[j]=h*Af[j](t+h,yy);}
    // nueva aproximaci�n
    for (j=0; j<n; j++) 
    { y[j]=y[j] + (1.0/6.0)*(k1[j] + 2.0*k2[j] + 2.0*k3[j] + k4[j]);}
    t=t+h;
    cout << t;
    fsalida << t;
    for (j=0; j<n; j++) 
    { cout << "   " << y[j];
      fsalida << "   " << y[j];}
    cout << endl;
    fsalida << endl;
    } while (t <= 100);
   fsalida.close();
}
