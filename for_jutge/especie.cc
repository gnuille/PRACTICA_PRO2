/** @file especie.cc
    @brief Codi de la clase especie
*/

#include "especie.hh"
using namespace std;

/* ----Constructores---- */
especie::especie(){

}

/* ----Consultores---- */
int especie::getN() const{
    return N;
}

int especie::getl(int i) const{
    return l[i];
}

int especie::getly() const{
    return ly;
}

int especie::getlx() const{
    return lx;
}

int especie::getl0() const{
    return l0;
}

/* ----Lectura---- */
void especie::llegir(){
    cin>>N;
    cin>>l0;
    for(int i = 0; i<N; ++i){
       	int a;
        cin>>a;
        l.push_back(a);
    }
    cin>>lx;
    cin>>ly;

}
