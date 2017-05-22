/** @file individu.cc
    @brief Codi de la clase individu
*/
#include "individu.hh"
using namespace std;


/* ----Constructores---- */
individu::individu(){

}

individu::individu(const individu&pare, const individu&mare, const especie&esp){
        //llegim i tallem els sexuals de ptall fins a l0
        int cp, cm, tall;
        cin>>cm>>cp>>tall;

        if(cm) this->x = mare.x_y;
        else this->x = mare.x;

        if(cp) this->x_y = pare.x_y;
        else this->x_y = pare.x;

        this->sexe = !cp;

        int limit = esp.getl0();
        for(int i = tall; i<limit; ++i){
                bool aux = this->x[i];
                this->x[i] = this->x_y[i];
                this->x_y[i] = aux;
        }

        //inicialitzem els cromosomes normals
        int N = esp.getN();
        this->cromosomes = vector<parell_cromosomes>(N);

        for(int i = 0; i<N; ++i){
                //agafem els cromosomes respecitus de pare i mare i els tallem
                cin>>cm;
                vector<bool> c1;
                if(cm) c1 = mare.cromosomes[i].consultar_c2();
                else c1 = mare.cromosomes[i].consultar_c1();
                cin>>cp;
                vector<bool> c2;
                if(cp) c2 = pare.cromosomes[i].consultar_c2();
                else c2 = pare.cromosomes[i].consultar_c1();

                cin>>tall;
                parell_cromosomes cr(c1, c2);
                cr.tallar(tall);
                this->cromosomes[i] = cr;
        }
}

/* ----Consultores---- */
bool individu::consultar_sexe(){
	return sexe;
}


/* ----Lectura i escriptura---- */
void individu::llegir(const especie&esp){
        //inicialitzem X i X_Y depenent del sexe de l'individu
	x = vector<bool>(esp.getlx());
	char sexe;
	cin>>sexe;
	if(sexe == 'X'){
		x_y = vector<bool>(esp.getlx());
		this->sexe = true;    
	}else{
		x_y = vector<bool>(esp.getly());
		this->sexe = false;
	}
        
        //llegim els cromosomes sexuals
	for(int i = 0; i<x.size();++i){
		int inp;
		cin>>inp;
		x[i] = inp;
	}
	for(int i = 0; i<x_y.size(); ++i){
		int inp;
		cin>>inp;
		x_y[i] = inp;
	}
        //inicialitzem els cromosomes normals i els llegim
	cromosomes = vector<parell_cromosomes>(esp.getN());
	for(int i = 0; i<esp.getN(); ++i){

		cromosomes[i].llegir(esp.getl(i));

	}
}

void individu::escriure_genotip(){
        //Escribim el primer cromosoma sexual, sempre es X
	cout<<"  X:";
	for(int i = 0; i<x.size(); ++i){
		cout<<" ";
		if(x[i]) cout<<1;
		else cout<<0;
	}
	cout<<endl;
        
        //Escribim el segon cromosoma sexual X o Y depenent del sexe 
	if(!this->sexe) cout<<"  Y:";
	else cout<<"  X:";
	for(int i = 0; i<x_y.size(); ++i){
		cout<<" ";
		if(x_y[i]) cout<<"1";
		else cout<<"0";
	}
	cout<<endl;
        
        //Escribim els cromosomes normals
	for(int i = 0; i<cromosomes.size(); ++i){
		cout<<"  "<<i+1<<".";
		cromosomes[i].escriure_c1();
		cout<<endl;
		cout<<"  "<<i+1<<".";
		cromosomes[i].escriure_c2();
		cout<<endl;
	}

}
