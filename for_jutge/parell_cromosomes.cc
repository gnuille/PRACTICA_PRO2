
#include "parell_cromosomes.hh"
using namespace std;
parell_cromosomes::parell_cromosomes(){

}

parell_cromosomes::parell_cromosomes(const vector<bool>&c1,const vector<bool>&c2){
    (*this).c1 = c1;

    (*this).c2 = c2;
}

vector<bool> parell_cromosomes::consultar_c1() const{
    return c1;
}
/** @brief Retornem el cromosoma c1
    \pre cert
    \post retornem el cromosoma c1
*/
vector<bool> parell_cromosomes::consultar_c2() const{
    return c2;
}
/** @brief Retornem el cromosoma c2
    \pre cert
    \post retornem el cromosoma c2
*/
void parell_cromosomes::tallar(int i){
  for(int j = i; j<c1.size(); ++j){
    bool aux;
    aux = c1[j];
    c1[j] = c2[j];
    c2[j] = aux;

  }
}
void parell_cromosomes::llegir(int tam){
    c1 = vector<bool>(tam);
    c2 = vector<bool>(tam);
    int inp;
    for(int i = 0; i<tam; ++i){
        cin>>inp;
        c1[i] = inp;
    }

    for(int i = 0; i<tam; ++i){
        cin>>inp;
        c2[i] = inp;
    }
}

void parell_cromosomes::escriure_c1(){
    cout<<"1:";
    for(int i = 0; i<c1.size(); ++i){
        cout<<" ";
        if(c1[i])cout<<1;
        else cout<<0;
    }
}

void parell_cromosomes::escriure_c2(){
    cout<<"2:";
    for(int i = 0; i<c2.size(); ++i){
        cout<<" ";
        if(c1[i])cout<<1;
        else cout<<0;
    }
}
