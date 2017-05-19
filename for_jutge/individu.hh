/** @file individu.hh
    @brief Especificació de la clase Individu
*/


#include "parell_cromosomes.hh"
#include "especie.hh"

using namespace std;

class individu{

private:
	vector<parell_cromosomes> cromosomes;
	vector<int> x;
	vector<int> x_y;
	bool sexe;

public:
    individu();
    /** @brief Generem un individu buit
        \pre cert
        \post Retornem un individu buit
    */

    individu(const individu&pare, const individu&mare, especie&esp);
    /** @brief Retornem un individu nou, fill del pare i la mare mitjançant la reproducció
        \pre Al P.I estan el pare, la mare(on pare XY, mare XX)
        \post Retornem un individu nou mitjançant la reproduccio
    */

    bool consultar_sexe();
    /** @brief Retornem el sexe de l'individu
        \pre cert
        \post Retornem cert si dona, fals si home.
    */
    void llegir(especie&esp);
    /** @brief Llegim un individu
        \pre Al pi tenim una especie. Al canal estandard d'entrada tenim les dades de un individu, l'individu es buit
        \post Assignem els valors que rebem al individus
    */

    void escriure_genotip();
    /** @brief Escribim la informacio genetica de l'individu
        \pre cert
        \post S'ha escrit la informacio genetica de l'individu al canal estandard de sortida
    */


};
