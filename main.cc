/** @file main.cc
    @brief Programa principal, estructura bàsica
*/
#include "poblacio.hh"
#ifndef NO_DIAGRAM 
#include<iostream>
#include "Arbre.hh"
#endif

typedef set<individu>::iterator setiterator;

using namespace std;

int main(){
    
	poblacio p;
	p.llegir();
	
    int op;
    cin>>op;
    while(op!=7){
        switch (op) {
            case 1:
				individu in;
				in.llegir();
				if(p.esta_individu(in.consultar_nom()) cout<<"error"<<endl;
				else p.afegir_individu(in);
                break;
            case 2:
                string pare, mare, fill;
                cin>>mare>>pare>>fill;
               
                setiterator madre = p.trobar(mare);
                setiterator padre = p.trobar(pare);
                if(madre == p.end() or padre == p.end()) cout<<"error"<<endl;
                else{
					if(!p.esta_individu(fill) and *madre.consultar_sexe() and !*padre.consultar_sexe()){
						if(*(*madre.pare()).consultar_nom() != *(*padre.pare()).consultar_nom()){ 
							if(*(*madre.mare()).consultar_nom() != *(*padre.mare()).consultar_nom()){
								if(!*madre.es_antecesor(padre) and !*padre.es_antecesor(madre)){
									individu hijo(padre, madre, fill); 
									p.afegir_individu(hijo);
								}
							}
						}
					}
				}
				
                break;
            case 3:
				string in;
				cin>>in;
				setiterator ind = p.trobar(in);
				if(ind == p.end()) cout<<"error"<<endl;
				else *ind.escriure_arbe();
                break;
            case 4:
				string in;
				cin>>in;
				setiterator ind = p.trobar(int);
				if(ind = p.end()) cout<<"error"<<endl;
				else{
					Arbre arb;
					arb.llegir(); //no tinc gens clara aquesta part 
					*in.completar_arbre(arb);  //molt provisional              
                break;
            case 5:
				p.escriure();
            
                break;
            case 6:
				string in;
				string in;
				cin>>in;
				setiterator ind = p.trobar(in);
				if(ind == p.end()) cout<<"error"<<endl;
				else *ind.escriure();
              
                break;
            }
            cin>>op;

        }
    }
}
