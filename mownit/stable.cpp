#include <iostream>
#include <cmath>
using namespace ::std;

double unstable_e_x(double x){
    double sum=1+x;
    double czesc=(x*x)/2;
  
    int counter=2;
    while(counter!=100){
        sum+=czesc;
        czesc=(czesc*x)/(counter+1);
        counter++;
    }
    return sum;
}

double stable_e_x(double x){
    double copyx = abs(x);
    double sum=1+copyx;
    double czesc=(copyx*copyx)/2;
    int counter=2;
    while(counter!=100){
        sum+=czesc;
        czesc=(czesc*copyx)/(counter+1);
        counter++;
    }
    if(x>0){
        return sum;
    }
    else if(x<0) return 1/sum;
    else return -1;
}


int main(){
    
    double x1;
    cin >> x1;
    cout<< "Unstable algorithm:"<< unstable_e_x(x1);
    cout<< "\n";
    cout<< "Stable algorithm:"<<stable_e_x(x1);
}