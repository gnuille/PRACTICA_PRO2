/** @file individu.hh
    @brief Especificació de la clase Individu
*/

#ifndef _INDIVIDU_
#define _INDIVIDU_
#include "parell_cromosomes.hh"
#include "especie.hh"

using namespace std;

class individu{
/** @class individu
	@brief Emmagatzema la informacio genetica dels individus.
	Guarda els parells de cromosomes normals i els cromosomes x i x_y

*/
private:
    /** @brief Cromosomes normals */ 
	vector<parell_cromosomes> cromosomes;
    /** @brief Cromosoma sexual x */
	vector<bool> x;
    /** @brief Cromosoma sexual x o y depenent del sexe de l'individu*/
	vector<bool> x_y;
    /** @brief Sexe de l'individu cert si dona fals si home*/
	bool sexe;

public:

    //Constructores
    /** @brief Generem un individu buit
        \pre Cert
        \post Retornem un individu buit
    */
    individu();
    
    /** @brief Retornem un individu nou, fill del pare i la mare mitjançant la reproducció
        \pre Al P.I estan el pare, la mare(on pare XY, mare XX)
        \post Retornem un individu nou mitjançant la reproduccio
    */
    individu(const individu&pare, const individu&mare, const especie&esp);
    
    //Consultores
    /** @brief Retornem el sexe de l'individu
        \pre Cert
        \post Retornem cert si dona, fals si home.
    */   
    bool consultar_sexe();
    
     //Lectura i escriptura
    /** @brief Llegim un individu
        \pre Al pi tenim una especie. Al canal estandard d'entrada tenim les dades de un individu.
        \post Assignem els valors que rebem al individu
    */  
    void llegir(const especie&esp);
    
    /** @brief Escribim la informacio genetica de l'individu
        \pre Cert
        \post S'ha escrit la informacio genetica de l'individu al canal estandard de sortida
    */
    void escriure_genotip();
    


};
#endif
