#include <iostream>
#include <cmath>
using namespace ::std;

int main(){

    double x;
    cin >> x;
    double sum=1+x;
    double czesc=(x*x)/2;
  
    int counter=2;
    cout<< 1 << " ";
    while(counter!=100){
        sum+=czesc;
        czesc=(czesc*x)/(counter+1);
        counter++;
    }
    
    cout<< "SUMA " << sum << endl;

}