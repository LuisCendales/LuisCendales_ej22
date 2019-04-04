#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using std::cout;
using std::endl;

float g(float x);
void MCMC(int N);

float g(float x){
    double a;
    
    a=exp(-x*x/2);
    return a;
}

void MCMC(int N){
    
    int i;
    float propuesta;
    srand48(time(0));
    float valor;
    float r;
    float alfa;
    float res;
    double div;
    
    for(i=0;i<N;i++){
        valor = drand48()*3.141592;
        propuesta = valor + (drand48()*2 -1);
        div = g(propuesta)/g(valor);
        r = std::min(1.0,div);
        alfa = drand48();
        if(alfa<r){
            res=propuesta;
        }else{
            res=valor;
        }
        cout << i << " " << res << endl;
        valor=res;
    }
}

int main(){
    MCMC(1000);
}