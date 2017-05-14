/** @file poblacio.hh
    @brief Especificació de la clase poblacio
*/

#include "individu.hh"
#include<map>

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





public:
    poblacio();
    /** @brief Retorna una poblacio buida
        \pre buit
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
    void escriure();
    /** @brief Escribim tots els elements per ordre alfabetic
        \pre Cert
        \post El conjunt queda escrit al canal estandard de sortida per ordre alfabetic
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

};
