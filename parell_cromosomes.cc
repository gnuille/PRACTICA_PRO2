
#include "parell_cromosomes.hh"
using namespace std;
parell_cromosomes::parell_cromosomes(){

}

parell_cromosomes::parell_cromosomes(const vector<int>&c1,const vector<int>&c2){
    (*this).c1 = c1;

    (*this).c2 = c2;
}

void parell_cromosomes::reproduir(int punt_tall){

}

void parell_cromosomes::llegir(int tam){
    int inp;
    for(int i = 0; i<tam; ++i){
        cin>>inp;
        c1.push_back(inp);
    }

    for(int i = 0; i<tam; ++i){
        cin>>inp;
        c2.push_back(inp);
    }
}

void parell_cromosomes::escriure_c1(){
    cout<<"1:";
    for(int i = 0; i<c1.size(); ++i){
        cout<<" "<<c1[i];
    }
}

void parell_cromosomes::escriure_c2(){
    cout<<"2:";
    for(int i = 0; i<c2.size(); ++i){
        cout<<" "<<c2[i];
    }
}
