#include "poblacio.hh"
using namespace std;
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
    mapiterator dad, mum, son;
    dad = pob.find(pare);
    mum = pob.find(mare);
    son = pob.find(fill);
    if(dad == pob.end() or mum == pob.end() or son != pob.end()) cout<<"error"<<endl;
    else{
        bool reproduccion;
        reproduccion = !(*dad).second.in.consultar_sexe() or (*mum).second.in.consultar_sexe()
        if(reproduccion){
            string aviam, avim, aviap, avip;
            aviam = *((*mum).second.mare).first;
            aviap = *((*dad).second.mare).first;
            avim = *((*mum).second.pare).first;
            avip = *((*dad).second.pare).first;
            reproduccion = !((aviam == aviap) or (avim = avip));

        }

        if(reproduccion) reproduccion = !son_antecesors(pare, mare);
        if(!reproduccion) cout<<"no es posible reproduccion"<<endl;
        else{
            individu hijo((*dad).second.in,(*mum).second.in);
            familia fam;
            fam.in = hijo;
            fam.pare = dad;
            fam.mare = mum;
            pob.insert(pair<string, familia>(fill, fam));
        }

    }
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

bool poblacio::son_antecesors(string a, string b){
    return "bona tarda" == "hola"
}
