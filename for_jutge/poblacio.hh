/** @file poblacio.hh
    @brief Especificació de la clase poblacio
*/

#include "individu.hh"
#include<map>
#include<queue>

using namespace std;

class poblacio{

private:
    struct familia{
	    individu in;
        map<string,familia>::iterator  pare;
        map<string,familia>::iterator  mare;
    };
    map<string, familia> pob;
    typedef map<string,familia>::iterator mapiterator;

	bool reproduccio_posible(mapiterator pare, mapiterator mare, mapiterator fill){
		if(pare == pob.end() or mare == pob.end() or fill !=pob.end()){
			cout<<"  error"<<endl;
			return false;
		}
		if((*pare).second.in.consultar_sexe() or !(*mare).second.in.consultar_sexe()){
			cout<<"  no es posible reproduccion"<<endl;
			return false;
		}
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

		if(son_antecesors((*pare).first, (*mare).first)){
			cout<<"  no es posible reproduccion"<<endl;
			return false;
		}
		return true;

	}
    /** @brief diem si es posible la reproduccio
        \pre cert
        \post retornem cert si la reproduccio es posible i fals si no, a demes a quedat escrit el tipus de error
    */


    bool te_pares(mapiterator a){
      return (*a).second.pare != pob.end();
    }
    /** @brief Retorna cert si l'individu te pares
        operacio privada ja que treballem amb mapiterator
        \pre cert
        \post Retornem cert si l'individu apuntat per el mapiterator te pares
    */

    bool es_antecesor_aux(mapiterator low, string high){
      bool b;
      if(low == this->pob.end()) b = false;
      else b =((*low).first == high or es_antecesor_aux((*low).second.pare, high) or es_antecesor_aux((*low).second.mare, high));
	  return b;
    }
    /** @brief Retorna cert si el nom de l'individu high es un antecesor de l'individu low
        operacio privada ja que treballem amb mapiterator's
        \pre cert
        \post Retornem cert si l'individu al qual correspon el nom high es antecesor de low.
    */

    void completar(queue<string>&to_print, mapiterator actual){
      if(actual != pob.end()){
        to_print.push("*"+(*actual).first+"*");
        (*this).completar(to_print, (*actual).second.pare);
        (*this).completar(to_print, (*actual).second.mare);
      }else{
        to_print.push("$");
      }
    }
    bool completar_arbre_aux(queue<string>&to_print, mapiterator actual){
      string s;
      cin>>s;
      bool b;
      if(s == "$"){
        completar(to_print, actual);
        b = true;
      }else{
        mapiterator mare, pare;
        to_print.push(s);
        if(actual == pob.end()){
          mare = pob.end();  //per consumir dades:)
          pare = pob.end();
          b = false;
        }
        else{
          mare = (*actual).second.mare;
          pare = (*actual).second.pare;
          b = true;
        }
        b = b and (*actual).first == s;
        b = completar_arbre_aux(to_print, pare) and b;
        b = completar_arbre_aux(to_print, mare) and b;
      }

      return b;
    }
    /** @brief Retorna cert si l'arbre introduit en preordre es subarbre
        \pre Al canal estandard de entrada hi ha un arbre en preordre
        \post Retornem una poblacio buida
    */

public:
    poblacio();
    /** @brief Retorna una poblacio buida
        \pre cert
        \post Retornem una poblacio buida
    */


    individu consultar_individu(string nom);
    /** @brief Consultem un individu
	\pre el nom de l'individu esta al map
	\post retornem l'individu al qual li correspon el nom
    */

    void afegir_individu(string nom, const individu&ind);
    /** @brief Afegim un individu al map pob
        \pre El parametre implicit es un individu que no esta a pob i el seu nom
        \post El parametre implicit esta dintre de pob sense pares i amb el seu respectiu nom
    */
    bool esta_individu(string nom);
     /** @brief Busquem un individu al sistema
        \pre cert
        \post retornem cert si hi ha un individu amb el nom, fals, si no.
    */

    void reproduir(string pare, string mare, string fill, especie&esp);
    /** @brief reproduim dos individus i si es posible l'afegim al sistema
        \pre pare i mare es poden reproduir
        \post si es poden reproduir entrarem a fill al sistema mitjançant el metode de reproduccio sino retornarem error
    */

    void completar_arbre();
    /** @brief llegim un arbre diem si es o no subarbre de l'arbre geneologic d'algun individu i si ho es el completem marcant els nous
        \pre rebem un arbre amb noms d'individus en preordre
        \post ha quedat escrit en preordre el nom dels individus de l'arbre complret si es que era subarbre
    */

    bool son_antecesors(string a, string b);
	/** @brief Busquem si els elements son antecesors
        \pre a i b son noms d'individus dintre del sistea
        \post Retornem cert si a es antecesor de b o b es antecesor de a, fals eb altres casos
    */
    void llegir(especie&esp);
    /** @brief Llegim una població inicial
        \pre El conjunt es buit, rebem una M i seguidament la informació de M individus
        \post  els M individus queden registrats en al map pob sense pares.
    */

    void escriure();
    /** @brief Escribim tots els elements per ordre alfabetic
        \pre Cert
        \post El conjunt queda escrit al canal estandard de sortida per ordre alfabetic
    */

    void escriure_arbre_geneologic(string nom);
    /** @brief Escribim l'arbre geneologic de l'individu
        \pre cert
        \post Ha quedat escrit l'arbre geneologic de l'individu ordenat per nivells
    */

};
