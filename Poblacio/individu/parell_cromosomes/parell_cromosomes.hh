/** @file parell_cromosomes.hh
    @brief Especificació de la clase parell_cromosomes
*/

class parell_cromosomes{
private:
	vector<int> c1;
	vector<int> c2;
public:
	parell_cromosomes();
	/** @brief constructora del parell de cromosomes
        \pre cert
        \post Retornem un parell de cromosomes buit
    */
    parell_cromosomes(const vector<int>&c1,const vector<int>&c2);
	/** @brief constructora del parell de cromosomes
        \pre c1 i c2 son cromosomes
        \post Retornem un parell de cromosomes on el P.I son els cromosomes
    */

    void reproduir(int punt_tall);
    /** @brief Reproduccio del parell de cromosomes
        \pre 0<punt_tall<li (cromosoma)
        \post el parell ha quedat modificat segons la reproduccio
    */
    void llegir(int tam)
    /** @brief llegim el parell de cromosomes
        \pre al canal estandard d'entrada esta la sequencia de gens dels dos cromosomes
        \post cr1 i cr2 han quedat definits
    */
    void escriure_c1()
    /** @brief Escribim el cromosoma c1
        \pre cert
        \post El canal estandard de sortida ha quedat escrit amb la sequencia de gens del cromosoma c1
    */

	void escriure_c2()
    /** @brief Escribim el cromosoma c2
        \pre cert
        \post El canal estandard de sortida ha quedat escrit amb la sequencia de gens del cromosoma c2
    */

}
