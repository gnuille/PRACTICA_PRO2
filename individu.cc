#include<vector>
#include<iostream>
#include "individu.hh"
using namespace std;

individu::individu(){

}

individu::individu(const individu&pare, const individu&mare){
			this->cromosomes = pare.cromosomes;
			int cp, cm, tall;
			for(int i = 0; (*this).cromosomes.size(); ++i){
				cin>>cm;
				vector<int> c1;
				if(cm) c1 = mare.cromosomes.consultar_c2();
				else c1 = mare.cromosomes.consultar_c1();
				cin>>cp;
				vector<int> c2;
				if(cp) c2 = pare.cromosomes.consultar_c2();
				else c2 = pare.cromosomes.consultar_c1();

				cin>>tall;
				parell_cromosomes cr(c1, c2);
				cr.tallar(tall);

				//todo: sexuals;
			}


}

bool individu::consultar_sexe(){
	return x.size() == x_y.size();
}

void individu::llegir( especie&esp){
	x = vector<int>(esp.getlx());

	char sexe;
	cin>>sexe;
	if(sexe == 'X'){
		x_y = vector<int>(esp.getlx());    //preguntar si millor fer push_back o fer aquesta asignacio
	}else{
		x_y = vector<int>(esp.getly());
	}

	for(int i = 0; i<x.size();++i){
		cin>>x[i];
	}
	for(int i = 0; i<x_y.size(); ++i){
		cin>>x_y[i];
	}
	cromosomes = vector<parell_cromosomes>(esp.getN());
	for(int i = 0; i<esp.getN(); ++i){

		cromosomes[i].llegir(esp.getl(i));

	}
}

void individu::escriure_genotip(){
	cout<<"X:";
	for(int i = 0; i<x.size(); ++i){
		cout<<" "<<x[i];
	}
	cout<<endl;
	if(x.size()!=x_y.size()) cout<<"Y:";
	else cout<<"X:";
	for(int i = 0; i<x_y.size(); ++i){
		cout<<" "<<x_y[i];
	}
	cout<<endl;
	for(int i = 0; i<cromosomes.size(); ++i){
		cout<<i+1<<".";
		cromosomes[i].escriure_c1();
		cout<<endl;
		cout<<i+1<<".";
		cromosomes[i].escriure_c2();
		cout<<endl;
	}

}

void individu::escriure_arbre_geneologic(){

}
