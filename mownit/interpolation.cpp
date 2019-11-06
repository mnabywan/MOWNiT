

#include<bits/stdc++.h> 
using namespace std; 
  
// To represent a data point corresponding to x and y = f(x) 
struct Data 
{ 
    double x, y; 
}; 
  

double interpolate(Data f[], int xi, int n) 
{ 
    double result; 
    for (int i=0; i<n; i++) 
    { 
        
        double term = f[i].y; 
        for (int j=0;j<n;j++) 
        { 
            if (j!=i) 
                term = term*(xi - f[j].x)/double(f[i].x - f[j].x); 
        } 
  
        result += term; 
    } 
  
    return result; 
}  

int main(){
    int a =-1;
    int b = 1;
    int n; 
    cin>> n;
    double h;
    h=(b-a)/n;
    Data f[n];
    for (int i=0; i<n; i++){
        f[i].x=a+i*h;
        f[i].y=1/(1+(25*(f[i].x)*(f[i].x)));
    }

    Data wyniki[201];
    wyniki[0].x= -1;
    wyniki[0].y=interpolate(wyniki, wyniki[0].x, n);
    for (int i=1; i<21; i++){
        wyniki[i].x= -1+i*0.1;
        wyniki[i].y=interpolate(wyniki, wyniki[i].x, n);
    }
    for (int i=0; i<201; i++){
        cout<< wyniki[i].x<< "   ";
       cout<< wyniki[i].y<< " ";
     }

}