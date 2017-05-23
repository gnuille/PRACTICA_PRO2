/** @file parell_cromosomes.hh
    @brief Especificació de la clase parell_cromosomes
*/
#ifndef _PARELL_CROMOSOMES_
#define _PARELL_CROMOSOMES_

#ifndef NO_DIAGRAM
#include<iostream>
#include<vector>
#endif

using namespace std;

class parell_cromosomes{
/** @class parell_cromosomes
    @brief Emmagatzema la informacio de un parell de cromosomes amb metodes per a fer posible la reproduccio i escriure els genotips
           El tamany dels cromosomes sempre es igual.
*/
private:
        /** @brief Vector que representa el cromosoma 1*/
	vector<bool> c1;
        /** @brief Vector que representa el cromosoma 2*/
	vector<bool> c2;
public:
        //Constructores        
        /** @brief Constructora del parell de cromosomes
        \pre Cert
        \post Retornem un parell de cromosomes buit
        */
        parell_cromosomes();
	
        /** @brief Constructora del parell de cromosomes
        \pre C1 i C2 son cromosomes
        \post Retornem un parell de cromosomes on c1 i c2 equivalen al eqivalen a C1 i C2
        */
        parell_cromosomes(const vector<bool>&c1,const vector<bool>&c2);
	
        //Modificadores
         /** @brief Tallem els cromosomes
        \pre 0<i<lc(longitud dels cromosomes)
        \post Els gens de l'interval [i, lc] han quedat intercambiats entre c1 i c2
	*/
        void tallar(int i);        
       
        //Consultores
        /** @brief Retornem el cromosoma c1
        \pre Cert
        \post Retornem el cromosoma c1
	*/
	vector<bool> consultar_c1() const;
        
	/** @brief Retornem el cromosoma c2
        \pre Cert
        \post Retornem el cromosoma c2
	*/
	vector<bool> consultar_c2() const;      
        
	//Lectura i escriptura
        /** @brief LLegim el parell de cromosomes
        \pre Al canal estandard d'entrada esta la sequencia de gens dels dos cromosomes
        \post Cr1 i cr2 han quedat definits amb una llargada = tam
        */
        void llegir(int tam);
        
        /** @brief Escribim el cromosoma c1
        \pre cert
        \post El canal estandard de sortida ha quedat escrit amb la sequencia de gens del cromosoma c1
        */
        void escriure_c1();
        
        /** @brief Escribim el cromosoma c2
        \pre cert
        \post El canal estandard de sortida ha quedat escrit amb la sequencia de gens del cromosoma c2
        */
	void escriure_c2();
};
#endif
