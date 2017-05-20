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
    /** @brief Estructura familia amb iteradors que apunten al pare i a la mare de l'individu*/

    map<string, familia> pob;
    /** @brief Mapa on guardem els individus amb els seus noms*/

    typedef map<string,familia>::iterator mapiterator;
    /** @brief Typedef per a amenitzar la programacio*/

	bool reproduccio_posible(mapiterator pare, mapiterator mare, mapiterator fill){
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
    /** @brief diem si es posible la reproduccio, metode privat ja que treballem amb mapiteradors.
        \pre cert
        \post retornem cert si la reproduccio es posible i fals si no, a demes a quedat escrit el tipus de error
    */


    bool te_pares(mapiterator a){
      return (*a).second.pare != pob.end();
    }
    /** @brief Retorna cert si l'individu te pares operacio privada ja que treballem amb mapiterator
        \pre cert
        \post Retornem cert si l'individu apuntat per el mapiterator te pares
    */

    bool es_antecesor_aux(mapiterator low, string high){
      bool b;
      if(low == this->pob.end()) b = false; //si no el trobem retornem fals
      else b =((*low).first == high or es_antecesor_aux((*low).second.pare, high) or es_antecesor_aux((*low).second.mare, high));
      //^si el nom es igual al que busquem retornem cert i no fem les crides recursives i sino doncs mirem a partir del pare i despres de la mare
	    return b;
    }
    /** @brief Retorna cert si el nom de l'individu high es un antecesor de l'individu low operacio privada ja que treballem amb mapiterator's
        \pre cert
        \post Retornem cert si l'individu al qual correspon el nom high es antecesor de low.
    */

    void completar(queue<string>&to_print, mapiterator actual){
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
    /** @brief Donada una cua i un mapiterador, la plenem completant l'arbre geneolofic de l'individu actual
        \pre cert
        \post to_print ha quedat plenada amb l'arbre geneologic de l'individu
    */
    bool completar_arbre_aux(queue<string>&to_print, mapiterator actual){
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
    /** @brief Retorna cert si donat un arbre en preordre es subarbre de l'inidividu actual, a mes a mes, el completem
        \pre Al canal estandard de entrada hi ha un arbre en preordre
        \post Retornem cert si l'arbre en preordre introduit es subarbre i el completem en tots casos
    */

public:

    //Constructores
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

    //Modificadores
    void afegir_individu(string nom, const individu&ind);
    /** @brief Afegim un individu al map pob
        \pre El parametre implicit es un individu que no esta a pob i el seu nom
        \post El parametre implicit esta dintre de pob sense pares i amb el seu respectiu nom
    */

    void reproduir(string pare, string mare, string fill, especie&esp);
    /** @brief reproduim dos individus i si es posible l'afegim al sistema
        \pre pare i mare es poden reproduir
        \post si es poden reproduir entrarem a fill al sistema mitjançant el metode de reproduccio sino retornarem error
    */

    //Consultores

    bool esta_individu(string nom);
     /** @brief Busquem un individu al sistema
        \pre cert
        \post retornem cert si hi ha un individu amb el nom, fals, si no.
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

    //Lectura i escriptura

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
