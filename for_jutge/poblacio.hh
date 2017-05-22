
/** @file poblacio.hh
    @brief Especificació de la clase poblacio
*/
#ifndef _POBLACIO_
#define _POBLACIO_
#include "individu.hh"
#include "especie.hh" //redundant, inclos per el diagrama
#ifndef NO_DIAGRAM
#include<map>
#include<queue>
#endif

using namespace std;

class poblacio{
/** @class poblacio
    @brief Sistema on emmagatzemem els individus amb el seu nom i un iterador que apunta al pare i la
    mare de cada individu.

    Les operacions que tracten amb iteradors les em declarat com a privades
*/

private:
    /** @brief Estructura familia amb iteradors que apunten al pare i a la mare de l'individu*/
    struct familia{
        /** @struct familia
            @brief Estructura on emmagetzem l'individu, i el seu pare i la mare
        */
        /** @brief L'individu emmagatzemat en el sistema */
	    individu in;
        /** @brief L'iterador que apunta al seu pare */
        map<string,familia>::iterator  pare;
        /** @brief L'iterador que apunta a la seva mare */
        map<string,familia>::iterator  mare;

    };

    /** @brief Mapa on guardem les families amb els seus noms*/
    map<string, familia> pob;

    /** @brief Typedef per a amenitzar la programacio*/
    typedef map<string,familia>::iterator mapiterator;

    /** @brief Diem si es posible la reproduccio, metode privat ja que treballem amb mapiteradors.
        \pre Cert
        \post Retornem cert si la reproduccio es posible i fals si no, a demes a quedat escrit el tipus de error
    */
	bool reproduccio_posible(mapiterator pare, mapiterator mare, mapiterator fill);



    /** @brief Retorna cert si l'individu te pares ademés, la operacio es privada ja que treballem amb mapiteradors
        \pre Cert
        \post Retornem cert si l'individu apuntat per el P.I te pares
    */
    bool te_pares(mapiterator a);

    /** @brief Retorna cert si el nom de l'individu high es un antecesor de l'individu low o es ell mateix, operacio privada ja que treballem amb mapiterator's
        \pre Cert
        \post Retornem cert si l'individu al qual correspon el nom high es antecesor de low o el nom de low = high.
    */
    bool es_antecesor_aux(mapiterator low, string high);

    /** @brief Donada una cua i un mapiterador, la plenem completant l'arbre geneologic de l'individu actual
        \pre Cert
        \post To_print ha quedat plenada amb l'arbre geneologic de l'individu "actual" en preordre i respectant els elements que hi habia abans
    */
    void completar(queue<string>&to_print, mapiterator actual);

    /** @brief Retorna cert si donat un arbre en preordre es subarbre de l'inidividu actual, a mes a mes, plenem la cua amb l'arbre geneologic de l'individu, marcant els individus nous
        \pre Al canal estandard de entrada hi ha un arbre en preordre
        \post Retornem cert si l'arbre en preordre introduit es subarbre i el completem en tots casos
    */
    bool completar_arbre_aux(queue<string>&to_print, mapiterator actual);

public:

    //Constructores

    /** @brief Retorna una poblacio buida
        \pre Cert
        \post Retornem una poblacio buida
    */
    poblacio();

    //Modificadores

    /** @brief Afegim un individu al map sistema
        \pre El parametre implicit es un individu que no esta a pob i el seu nom
        \post El parametre implicit esta dintre de pob sense pares i amb el seu respectiu nom
    */
    void afegir_individu(string nom, const individu&ind);

    /** @brief Reproduim dos individus i si es posible l'afegim al sistema
        \pre cert
        \post Si es poden reproduir entrarem a fill al sistema mitjançant el metode de reproduccio sino escriurem el error corresponent
    */
    void reproduir(string pare, string mare, string fill, const especie&esp);


    //Consultores

    /** @brief Busquem un individu al sistema
        \pre Cert
        \post Retornem cert si hi ha un individu amb el nom, fals, si no.
    */
    bool esta_individu(string nom);

    /** @brief Llegim un arbre en preordre, retornem cert si es un subarbre de algun individu del sistema i a mes a mes si ho es, imprimim l'arbre complert marcant entre asteriscs els elements afegits
        \pre Rebem un arbre amb noms d'individus en preordre
        \post Ha quedat escrit en preordre el nom dels individus de l'arbre complret si es que era subarbre
    */
    void completar_arbre();

    /** @brief Busquem si els elements son antecesors
        \pre Cert
        \post Retornem cert si a es antecesor de b o b es antecesor de a, fals en altres casos
    */
    bool son_antecesors(string a, string b);

    /** @brief Consultem un individu
	    \pre El nom de l'individu esta al map
	    \post Retornem l'individu al qual li correspon el nom
    */
    individu consultar_individu(string nom);


    //Lectura i escriptura

    /** @brief Llegim una població inicial
        \pre El conjunt es buit, rebem una M i seguidament la informació de M individus
        \post  Els M individus queden registrats en el sistema sense antecesors.
    */
    void llegir(especie&esp);

    /** @brief Escribim tots els elements per ordre alfabetic
        \pre Cert
        \post El conjunt queda escrit al canal estandard de sortida per ordre alfabetic
    */
    void escriure();

    /** @brief Escribim l'arbre geneologic de l'individu
        \pre Cert
        \post Ha quedat escrit l'arbre geneologic de l'individu ordenat per nivells
    */
    void escriure_arbre_geneologic(string nom);

};

#endif
