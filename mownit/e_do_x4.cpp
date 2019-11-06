

#include <iostream>
#include <cmath>
using namespace ::std;


int main(){
     double x1;
    cin >> x1;
    double x;
    x=abs(x1);
    int licznik=10; 
    double suma=0;
    double wynik=x;
    int i=0;

    while (i!=25){
            wynik= wynik*x;
            wynik=wynik/(i+1);
            i++;
        }

    while (licznik!=0){
        
        suma = wynik+(wynik/x)*(licznik);
        cout << suma <<"  ";
        licznik--;
    }
    
    if(x1>0){
        cout<<(suma);
    }
    else {
        cout<<1/(suma)<< "" ;
    }
    return 0;


}

