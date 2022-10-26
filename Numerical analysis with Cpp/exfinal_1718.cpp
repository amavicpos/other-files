// Exam practice
// Integral of second order ODE with RK4

#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
const int n=2;// numero de ecuaciones de primer orden acopladas
const double PI=2.0*asin(1.0);
double f1 (double t, double y[n]);
double f2 (double t, double y[n]);
double (*Af[n]) (double t, double y[n])={f1, f2}; // array de punteros a funciones 
void RK4(double (*Af[n])(double t, double y[n]), double t0, double h, double y[n], double &integral, double tol);

int main()
{
ofstream fborrar;
fborrar.open("exfinal1718_resultados.txt", ofstream::out | ofstream::trunc);
fborrar.close();

ofstream fsalida("exfinal1718_resultados.txt", ios::app);
  if (!fsalida)
    {cout << "No se puede abrir el archivo";}
double t0=0, h=0.1, integral=0, tol=1e-30;
double y[n]={0,1}; // condiciones iniciales
cout << "t:      g:         g':       Integral:" << endl;
fsalida << "t:      g:         g':       Integral:" << endl;
RK4(Af,t0,h,y,integral,tol); // llamada a la funcion RK4
cout << endl << "Integral con error menor de " << tol << ":" << endl << integral << endl;
fsalida << endl << "Integral con error menor de " << tol << ":" << endl << integral << endl;
return 0;
}

double f1(double t, double y[n])
{ return y[1];}

double f2(double t, double y[n])
{ return (-y[1]-y[0]);}

void RK4(double (*Af[n])(double t, double y[n]), double t0, double h, double y[n], double &integral, double tol)
{
  int j;
  double integral2=0;
  // Hay que abrir el flujo en la funcion
	ofstream fsalida("exfinal1718_resultados.txt", ios::app);
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
    integral2=integral;
    integral = integral + y[0];
    cout << "   " << integral;
    fsalida << "   " << integral;
    cout << endl;
    fsalida << endl;
    } while (fabs(integral-integral2)>=tol);
   fsalida.close();
}
