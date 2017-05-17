#include "poblacio.hh"
using namespace std;
enum string_code{
    addIn,
    reproduccion,
    escribir_arbol,
    completar_arbol,
    escribir_pob,
    escribir_gen

};

string_code hashit (string const& inString) {
    if (inString == "anadir_individuo") return addIn;
    if (inString == "reproduccion_sexual") return reproduccion;
    if (inString == "escribir_arbol_genealogico") return escribir_arbol;
    if (inString == "completar_arbol_genealogico") return completar_arbol;
    if (inString == "escribir_poblacion") return escribir_pob;
    return escribir_gen;
}


int main(){
    especie esp;
    esp.llegir();
    poblacio pob;
    pob.llegir(esp);
    string op;
    cin>>op;

    while(op != "acabar"){
        switch(hashit(op)){
            case addIn:{  //funciona !:)
		            string name;
		            cin>>name;
		            individu in;
		            in.llegir(esp);
                if(pob.esta_individu(name)) cout<<"error"<<endl;
		            else pob.afegir_individu(name, in);

		            break;
	          }
	          case reproduccion:{
	                string mare, pare, fil;  //funciona !:) falta mirar si f:son_antecesors funciona!
		            cin>>mare>>pare>>fil;
		            pob.reproduir(pare, mare, fil, esp);
		            break;
	          }
    	      case escribir_arbol:{
		            string nom;
		            cin>>nom;
		            if(pob.esta_individu(nom)) pob.escriure_arbre_geneologic(nom);
		            else cout<<"error"<<endl;
		            break;
	          }
	          case completar_arbol:{
		            pob.completar_arbre();
		            break;
	         }
	          case escribir_pob:{  //funciona !:)
		            pob.escriure();
		            break;
	         }
	          case escribir_gen:{  //funciona !:)
	              string nom;
                cin>>nom;
                if(pob.esta_individu(nom)) pob.consultar_individu(nom).escriure_genotip();
      	        else cout<<"error"<<endl;
		            break;
	        }
	       default:
		       cout<<"no se que fas!"<<endl;
		       break;

	    }
	     cin>>op;
  }
}
