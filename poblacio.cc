#include<iostream>
#include "poblacio.hh"
using namespace std;

poblacio::poblacio(){

}

individu poblacio::consultar_individu(string nom){
    return pob[nom].in;

}


void poblacio::afegir_individu(string nom, const individu&ind){
    familia fami;
    fami.in = ind; //cal fer l'operador?
    fami.pare = pob.end();
    fami.mare = pob.end();
    pob.insert(pair<string, familia>(nom, fami));
}

bool poblacio::esta_individu(string nom){
    return pob.find(nom) != pob.end();
}

int poblacio::reproduccio_posible(string pare, string mare, string fill){

    mapiterator dad, mum, son;
    dad = this->pob.find(pare);
    mum = this->pob.find(mare);
    son = this->pob.find(fill);
    if(dad == this->pob.end() or mum == this->pob.end() or son != this->pob.end()){
        return 2;
    }
    if((*dad).second.in.consultar_sexe() or !(*mum).second.in.consultar_sexe()){

      return 1;
    }

    mapiterator avim, avip, aviam, aviap;
    avim = (*mum).second.pare;
    aviam = (*mum).second.mare;
    avip = (*dad).second.pare;
    aviap = (*dad).second.mare;
    if(avim != this->pob.end() and avip != this->pob.end()){
      if((*avim).first == (*avip).first or (*aviam).first == (*aviap).first) return 1;
    }
    if(!son_antecesors(pare, mare)){
      cout<<"son antecesors!!!"<<endl;
       return 0;
    }
    return 1;
}

void poblacio::reproduir(string pare, string mare, string fill, especie&esp){
  int repr = (*this).reproduccio_posible(pare, mare, fill);

  if(repr == 0){//reproduccio posible i normal :)
    mapiterator dad, mum;
    dad = pob.find(pare);
    mum = pob.find(mare);
    individu fil((*dad).second.in, (*mum).second.in, esp);
    familia fam;
    fam.mare = mum;
    fam.pare = dad;
    fam.in = fil;

    pob.insert(pair<string, familia>(fill, fam));
    cout<<"Reproduccion hecha con exito"<<endl;
  }else{
    int inutil;
    for(int i = 0; i<(esp.getN()+1)*3; ++i) cin>>inutil;
    if(repr == 2)cout<<"error"<<endl;
    else cout<<"no es posible reproduccion"<<endl;
  }

}

void poblacio::escriure(){
    mapiterator it;
    for(it = pob.begin(); it != pob.end(); ++it){
        cout<<(*it).first<<" "<<"X";
        if(!(*it).second.in.consultar_sexe()) cout<<"Y";
        else cout<<"X";
        cout<<" (";
        if((*it).second.pare == pob.end() or (*it).second.mare == pob.end()){
            cout<<"$,$)"<<endl;
        }else{
            cout<<(*((*it).second.pare)).first<<","<<(*((*it).second.mare)).first<<")"<<endl;
        }
    }
}

void poblacio::llegir(especie&esp){
    int m;
    cin>>m;
    for(int i = 0; i<m; ++i){
        string nom;
        cin>>nom;
        individu in;
        in.llegir(esp);
        (*this).afegir_individu(nom, in);
    }
}

bool poblacio::son_antecesors(string a, string b){
    mapiterator pare = pob.find(a);
    mapiterator mare = pob.find(b);

    return (*this).es_antecesor_aux(pare, b) or (*this).es_antecesor_aux(mare, a); //inmersio!
}


void poblacio::completar_arbre(){
  Arbre<string> a;
  llegir_arbre_string(a);
  mapiterator base;
  base = pob.find(a.arrel());

  if(base == pob.end()) cout<<"no es arbol parcial";
  else{
    if(completar_arbre_aux(a, base)){
      Arbre<string> a1,a2;
      cout<<a.arrel();
      a.fills(a1,a2);
      escriure_arbre_string(a1);
      escriure_arbre_string(a2);

    }
    else cout<<"no es arbol parcial";
  }
  cout<<endl;

}

void poblacio::escriure_arbre_geneologic(string nom){
  mapiterator in = pob.find(nom);
  if(in == pob.end()) cout<<"error"<<endl;
  else{
    int lvl = 0;
    queue<mapiterator> familia;
    familia.push(in);
    while(!familia.empty()){
      cout<<"Nivel "<<lvl<<":";
      int tam = familia.size();
      for(int i = 0; i<tam; ++i){
        cout<<" "<<(*familia.front()).first;
        if((*this).te_pares(familia.front())){
          familia.push((*familia.front()).second.pare);
          familia.push((*familia.front()).second.mare);
        }

        familia.pop();
      }
      cout<<endl;
      ++lvl;
    }
  }

}
