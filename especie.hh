#include<vector>
#include<iostream>
using namespace std;

class especie{
private:
	int N;
	vector<int> l;
	int ly;
	int lx;
	int l0;
public:
	
	especie();
	/** @brief Constructora de la clase especie
        \pre Cert
        \post Obtenin una especie sense informació
    */
	int getN();
	/** @brief Obtenir el nombre de cromosomes
        \pre Cert
        \post El valor retornat es N (nombre de cromosomes)
    */
	int getl(int i);
	/** @brief Obtenir la llargada del cromosoma C-i
        \pre el p.i es la posició del cromosoma
        \post El valor retornat es la llargada del cromosoma c-i
    */
	int getly();
	/** @brief Obtenir la llargada del cromosoma sexual Y
        \pre Cert
        \post El valor retornat es la llargada del cromosoma sexual Y
    */
	int getlx();
	/** @brief Obtenir la llargada del cromosoma sexual X
        \pre Cert
        \post El valor retornat es la llargada del cromosoma sexual X
    */
    int getl0();
    /** @brief Obtenir la part comuna dels cromosomes sexuals
        \pre cert
        \post Retornem el parametre l0
    */
    void llegir();
    /** @brief Definim els parametres de la especie
        \pre Al canal estandard d'entrada tenim: N(nombre de cromosomes), li longituds(i = N), longitud dels cromosomes sexual x (lx) e y (ly)
        \post Aquetses dades pasen a ser els parametres de la especie
    */

};
