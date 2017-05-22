/** @file poblacio.cc
    @brief Codi de la clase poblacio
*/

#include "poblacio.hh"
using namespace std;

/*PRIVADES*/ 
bool poblacio::reproduccio_posible(mapiterator pare, mapiterator mare, mapiterator fill){
    //comprovem que pare i mare estiguin al sistema,i que el fill no hi sigui
		if(pare == pob.end() or mare == pob.end() or fill !=pob.end()){
			cout<<"  error"<<endl;
			return false;
		}

    //Comprobem els sexes del pare i la mare
		if((*pare).second.in.consultar_sexe() or !(*mare).second.in.consultar_sexe()){
			cout<<"  no es posible reproduccion"<<endl;
			return false;
		}

    //mirem que no siguin germans (no tinguin ni el mateix pare ni la mateixa mare)
		mapiterator avip = (*pare).second.pare;
		mapiterator avim = (*mare).second.pare;
		mapiterator aviap = (*pare).second.mare;
		mapiterator aviam = (*mare).second.mare;

		if(avip != pob.end() and avim != pob.end()){
			if((*avip).first == (*avim).first){
				cout<<"  no es posible reproduccion"<<endl;
				return false;
			}
		}

		if(aviap != pob.end() and aviam != pob.end()){
			if((*aviap).first == (*aviam).first){
				cout<<"  no es posible reproduccion"<<endl;
				return false;
			}
		}

    //finalment mirem que un no sigui antecesor de l'altre i viceversa
		if(son_antecesors((*pare).first, (*mare).first)){
			cout<<"  no es posible reproduccion"<<endl;
			return false;
		}
    //si compleix totes les condicions retornem cert
		return true;

}

bool poblacio::te_pares(mapiterator a){
  return (*a).second.pare != pob.end();
}

bool poblacio::es_antecesor_aux(mapiterator low, string high){
      bool b;
      if(low == this->pob.end()) b = false; //si no el trobem retornem fals
      else b = ((*low).first == high or es_antecesor_aux((*low).second.pare, high) or es_antecesor_aux((*low).second.mare, high));
      //^si el nom es igual al que busquem retornem cert i no fem les crides recursives i sino doncs mirem a partir del pare i despres de la mare
	  return b;
}

void poblacio::completar(queue<string>&to_print, mapiterator actual){
      if(actual != pob.end()){
        //afegim lelement a la cua entre asteriscs per a imprimirlo com a nou
        to_print.push("*"+(*actual).first+"*");
        //realitzem crides recursives per al pare i la mare respectant el preordre
        (*this).completar(to_print, (*actual).second.pare);
        (*this).completar(to_print, (*actual).second.mare);
      }else{
        //si es un valor null afegil un $ i aturem les crides recursives (cas base)
        to_print.push("$");
      }
}

bool poblacio::completar_arbre_aux(queue<string>&to_print, mapiterator actual){
      //rebem el element
      string s;
      cin>>s;
      bool b;
      if(s == "$"){
        //cas base, completem l'arbre a partir de l'element null i retornem cert
        completar(to_print, actual);
        b = true;
      }else{
        //afegim l'element actual a la cua
        mapiterator mare, pare;
        to_print.push(s);
        //per a consumir dades i evitar errors de execucio
        if(actual == pob.end()){
          mare = pob.end();  //per consumir dades:)
          pare = pob.end();
          //retornem fals ja que l'arbre de individus s'ha acabat pero seguim rebent dades
          b = false;
        }
        else{
          mare = (*actual).second.mare;
          pare = (*actual).second.pare;
          //comprovem si l'element actual coincideix amb el seu nom
          b = (*actual).first == s;
        }
        //realitzem les crides comparades amb el boolea b en aquest ordre per a seguir consumint dades i mirant primer el pare i despres la mare
        b = completar_arbre_aux(to_print, pare) and b;
        b = completar_arbre_aux(to_print, mare) and b;
      }

      return b;
}
/*PUBLIQUES*/

/* ----Constructores---- */
poblacio::poblacio(){

}

/* ----Modificadores---- */

void poblacio::afegir_individu(string nom, const individu&ind){
    familia fami;
    fami.in = ind;
    fami.pare = pob.end();
    fami.mare = pob.end();
    //creem una familia
    pob.insert(pair<string, familia>(nom, fami));
    //la introduim al mapa
}

void poblacio::reproduir(string pare, string mare, string fill, const especie&esp){
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

/* ----Consultores---- */

bool poblacio::esta_individu(string nom){
    return pob.find(nom) != pob.end();
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

bool poblacio::son_antecesors(string a, string b){
  //per a comprovar si son antecesors em de mirar que un no estigui en el arbre genealogic de l'altre i viceversa
  //busquem els individus i fem crides a les funcions recursives que ho comproven
    mapiterator pare = pob.find(a);
    mapiterator mare = pob.find(b);

    return (*this).es_antecesor_aux(pare, b) or (*this).es_antecesor_aux(mare, a); //inmersio
}

individu poblacio::consultar_individu(string nom){
    return pob[nom].in;

}

/* ----Lectura i escriptura---- */

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
