#include "poblacio.hh"

poblacio::poblacio(){

}

void poblacio::afegir_individu(string nom, const individu&ind){
    familia fami;
    fami.in = ind; //cal fer l'operador?
    fami.pare = pob.end();
    fami.mare = pob.end();
    pob.insert(pair<string, familia>(nom, fami));
}

bool poblacio::esta_individu(string nom){
    return pob.find(nom) != pob.end();
}

void poblacio::reproduir(string pare, string mare, string fill){

}

void poblacio::escriure(){
    mapiterator it;
    for(it = pob.begin(); it != pob.end(); ++it){
        cout<<(*it).first()<<" "<<"X";
        if((*it).second().in.consultar_sexe()) cout<<"Y";
        else cout<<"X";
        cout<<" ("
        if((*it).second().pare == pob.end() or (*it).second().mare == pob.end()){
            cout<<"$,$)"<<endl;
        }else{
            cout<<*((*it).second().pare).first()<<","<<*((*it).second().mare).first()<<")"<<endl;
        }
    }
}

void poblacio::llegir(){
    int m;
    cin>>m;
    for(int i = 0; i<m; ++i){
        string nom;
        cim>>nom;
        individu in;
        in.llegir();
        (*this).afegir_individu(nom, in);
    }
}
