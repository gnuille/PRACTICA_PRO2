/** @file especie.hh
    @brief Especificació de la clase especie.hh
*/
#ifndef _ESPECIE_
#define _ESPECIE_
#ifndef NO_DIAGRAM
#include<iostream>
#include<vector>
#endif
using namespace std;

class especie{
        /**
        @class especie
        @brief Guardem la informacio genetica de la especie 
        */
private:
        /** @brief Nombre de cromosomes*/
	int N;
        /** @brief Vector que emagatzema la longitud dels cromosomes*/
	vector<int> l;
        /** @brief Longitud del cromosoma sexual Y*/
	int ly;
        /** @brief Longitud del cromosoma sexual X*/
	int lx;
        /** @brief Part comuna entre els cromosomes X i Y*/
	int l0;
public:
        //Constructores
        /** @brief Constructora de la clase especie
        \pre Cert
        \post Obtenin una especie sense informació
        */
	especie();
        
        //Consultores
        /** @brief Obtenim el nombre de cromosomes
        \pre Cert
        \post El valor retornat es N (nombre de cromosomes)
        */
	int getN() const;
        
	/** @brief Obtenir la llargada del cromosoma c_i
        \pre 0<i<N
        \post El valor retornat es la llargada del cromosoma de posicio i
        */
	int getl(int i) const;
	
        /** @brief Obtenir la llargada del cromosoma sexual Y
        \pre Cert
        \post El valor retornat es la llargada del cromosoma sexual Y
        */
	int getly() const;
	
        /** @brief Obtenir la llargada del cromosoma sexual X
        \pre Cert
        \post El valor retornat es la llargada del cromosoma sexual X
        */
	int getlx() const;
	
        /** @brief Obtenir la part comuna dels cromosomes sexuals
        \pre Cert
        \post Retornem el parametre l0
        */
        int getl0() const;
        
        //Lectura
        /** @brief Definim els parametres de la especie
        \pre Al canal estandard d'entrada tenim: N(nombre de cromosomes), li longituds(i = N), longitud dels cromosomes sexual x (lx) e y (ly)
        \post Aquetses dades pasen a ser els parametres de la especie
        */       
        void llegir();
        

};
#endif
