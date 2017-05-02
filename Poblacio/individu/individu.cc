#include "individu.hh"

individu::individu(){

}

individu::individu(const individu&pare, const individu&mare){


}

bool individu::consultar_sexe(){
	return x.size() == x_y.size();
}

void individu::llegir(Especie&esp){
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
		cout<<i+1<<".";
		cromosomes[i].escriure_c2();
	}

}
