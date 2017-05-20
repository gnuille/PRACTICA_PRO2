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
    fami.in = ind;
    fami.pare = pob.end();
    fami.mare = pob.end();
    //creem una familia
    pob.insert(pair<string, familia>(nom, fami));
    //la introduim al mapa
}

bool poblacio::esta_individu(string nom){
    return pob.find(nom) != pob.end();
}

void poblacio::reproduir(string pare, string mare, string fill, especie&esp){
  mapiterator par, mar, fil;
  par = this->pob.find(pare);
  mar = this->pob.find(mare);
  fil = this->pob.find(fill);
  //busquem els individus al map

  if(this->reproduccio_posible(par, mar, fil)){ //comprovem si la reproduccio es possible
	  individu ind((*par).second.in, (*mar).second.in, esp); //cridem a la constructora per reprodccio de individu
	  familia fam;
	  fam.pare = par;
	  fam.mare = mar;
	  fam.in = ind;
    //generem la familia de l'individu
	  pob.insert(pair<string, familia>(fill, fam)); //l'insertem al mapa
  }else{
    //en el cas que la reproduccio no sigui posible, consumim dades
	  int inutil;
	  for(int i = 0; i<(esp.getN()+1); ++i) cin>>inutil>>inutil>>inutil;
  }
}

void poblacio::escriure(){
    mapiterator it;
    //recorrem tot el map imprimint el seu sexe, individus, pare i mare en un for
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
  //inicialitzaco del sistema poblacio, rebem m individus i els llegim i els afegim al sistema
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
  //per a comprovar si son antecesors em de mirar que un no estigui en el arbre genealogic de l'altre i viceversa
  //busquem els individus i fem crides a les funcions recursives que ho comproven
    mapiterator pare = pob.find(a);
    mapiterator mare = pob.find(b);

    return (*this).es_antecesor_aux(pare, b) or (*this).es_antecesor_aux(mare, a); //inmersio!
}


void poblacio::completar_arbre(){
  string s;
  cin>>s;
  cout<<" "<<s<<endl;
  //llegim el primer invidividu per a inicialitzar el algoritme
  mapiterator m = pob.find(s);
  mapiterator mare, pare;
  if(m != pob.end()){
    mare = (*m).second.mare;
    pare = (*m).second.pare;
  }else{   //per seguretat i evitar errors de execucio
    mare = pob.end();
    pare = pob.end();
  }
  queue<string> to_print;  //inicialitzem la cua on anirem posant els noms a imprimir de l'arbre en preordre
  to_print.push(s); //posem l'element arrel, es a dir, el primer
  bool b;
  //fem les crides a les funcions recursives, primer el pare i despres la mare, i per ultim comprovem que l'individu no hi sigui al sistema, (ja que em de consumir les dades)
  if(s != "$") b = (*this).completar_arbre_aux(to_print, pare) and (*this).completar_arbre_aux(to_print, mare) and m != pob.end();
  cout<<" ";
  //si es arbre l'imprimim
  if(b){
    int tam = to_print.size();
    for(int i = 0; i<tam; ++i){
      cout<<" "<<to_print.front();
      to_print.pop();
    }
    cout<<endl;
  //sino imprimim error
  }else{
    cout<<" no es arbol parcial"<<endl;
  }

}

void poblacio::escriure_arbre_geneologic(string nom){
  //busquem l'individu i mirem si hi es o no
  mapiterator ind = pob.find(nom);
  if(ind == pob.end()) cout<<"  error"<<endl;
  else{
    //inicialitzem la cua i afegim el primer individu
	queue<mapiterator> to_print;
	to_print.push(ind);
	int nivell = 0;
  //mentre la cua no sigui buida(no quedin antecesors) imprimim els individus actuals amb el seu nivell i afegim els seus antecesors
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
