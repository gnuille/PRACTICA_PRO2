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

void poblacio::reproduir(string pare, string mare, string fill, especie&esp){
  mapiterator par, mar, fil;
  par = this->pob.find(pare);
  mar = this->pob.find(mare);
  fil = this->pob.find(fill);
  
  if(this->reproduccio_posible(par, mar, fil)){
	  individu ind((*par).second.in, (*mar).second.in, esp);
	  familia fam;
	  fam.pare = par;
	  fam.mare = mar;
	  fam.in = ind;
	  pob.insert(pair<string, familia>(fill, fam));
  }else{
	  int inutil;
	  for(int i = 0; i<(esp.getN()+1); ++i) cin>>inutil>>inutil>>inutil;
  }
}

void poblacio::escriure(){
    mapiterator it;
    for(it = pob.begin(); it != pob.end(); ++it){
        cout<<"  "<<(*it).first<<" "<<"X";
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
  string ar =a.arrel();
  cout<<" "<<ar<<endl;
  base = pob.find(ar);

  if(base == pob.end()) cout<<"  no es arbol parcial";
  else{
    if(completar_arbre_aux(a, base)){      
      cout<<" ";     
      escriure_arbre_string(a);     
	}
    else cout<<"  no es arbol parcial";
  }
  cout<<endl;

}

void poblacio::escriure_arbre_geneologic(string nom){
  mapiterator ind = pob.find(nom);
  if(ind == pob.end()) cout<<"  error"<<endl;
  else{
	queue<mapiterator> to_print;
	to_print.push(ind);
	int nivell = 0;
	while(!to_print.empty()){
		cout<<"  Nivel "<<nivell<<":";
		int tam  = to_print.size();
		mapiterator act;
		for(int i = 0; i<tam; ++i){
			act = to_print.front();
			cout<<" "<<(*act).first;
			if((*this).te_pares(act)){
				to_print.push((*act).second.pare);
				to_print.push((*act).second.mare);
			}
			to_print.pop();
		}
		++nivell;
		cout<<endl;
	}
  }
  

}
