#include "especie.hh"
#include<iostream>
#include<vector>
using namespace std;

especie::especie(){

}

int especie::getN(){
    return N;
}

int especie::getl(int i){
    return l[i];
}

int especie::getly(){
    return ly;
}

int especie::getlx(){
    return lx;
}

int especie::getl0(){
    return l0;
}

void especie::llegir(){
    cin>>N;
    cin>>l0;
    for(int i = 0; i<N; ++i){
        cin>>l[i];
    }
    cin>>lx;
    cin>>ly;

}
