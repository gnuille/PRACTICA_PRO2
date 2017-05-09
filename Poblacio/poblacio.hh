/** @file poblacio.hh
    @brief Especificació de la clase poblacio
*/

#include "individu.hh"

typedef map<string,familia>::iterator mapiterator;

class poblacio{

private:
	struct familia{
		individu in;
		mapiterator pare;
		mapiterator mare;
	}
    map<string,familia> pob;


public:
    poblacio();
    /** @brief Retorna una poblacio buida
        \pre buit
        \post Retornem una poblacio buida
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

    void reproduir(string pare, string mare, string fill);
    /** @brief reproduim els individus pare mare i afegim el fill al sistema
        \pre pare i mare estan a pob, nfill no
        \post s'ha introduit mitjançant reproducció el fill al map d'individus
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
    void llegir();
    /** @brief Llegim una població inicial
        \pre El conjunt es buit, rebem una M i seguidament la informació de M individus
        \post  els M individus queden registrats en al map pob sense pares.
    */

}
