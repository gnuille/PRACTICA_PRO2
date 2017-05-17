/** @file poblacio.hh
    @brief Especificació de la clase poblacio
*/

#include "individu.hh"
#include "Arbre.hh"
#include "Arb_string_IO.hh"
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
      if(!te_pares(low)){
          b = false;
      }else{
          if((*low).first == high) b = true;
          else{
              b = es_antecesor_aux((*low).second.pare, high) or es_antecesor_aux((*low).second.mare, high);
          }
      }
      return b;
    }
    /** @brief Retorna cert si el nom de l'individu high es un antecesor de l'individu low
        operacio privada ja que treballem amb mapiterator's
        \pre cert
        \post Retornem cert si l'individu al qual correspon el nom high es antecesor de low.
    */

    bool completar_arbre_aux(Arbre<string>&a, mapiterator raiz){
      bool b;
      Arbre<string> a1;
      Arbre<string> a2;
      if(!a.es_buit()){
        string arr = a.arrel();
        a.fills(a1, a2);
        b = ((*raiz).first == arr) and (*this).completar_arbre_aux(a1, (*raiz).second.pare) and (*this).completar_arbre_aux(a2, (*raiz).second.mare);
        a.plantar(arr, a1, a2);

      }else if(raiz != pob.end()){
        string centr = "*" + (*raiz).first + "*";
        completar_arbre_aux(a1, (*raiz).second.pare);
        completar_arbre_aux(a2, (*raiz).second.mare);
        a.plantar(centr, a1, a2);
        b = true;
      }
      return b;
    }

    /** @brief Retorna cert si es subarbre i modifica l'arbre
        operacio privada ja que treballem amb mapiterator's
        \pre cert
        \post Retornem cert si l'arbre a es subarbre de pob i en cas de ser cert el modifiquem completant-lo i afegint * * als nous.
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

    int reproduccio_posible(string pare, string mare, string fill);
    /** @brief diem si es posible la reproduccio
        \pre cert
        \post retornem 1 si pare o mare no estan en el sistema o si fill ja hi es, 2 si no es posible la reproducio i 0 si ho es.
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
