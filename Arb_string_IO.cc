#include "Arb_string_IO.hh"

void llegir_arbre_string(Arbre<string> & a){
  Arbre<string> a1, a2;
  string s;
  cin>>s;
  if(s != "$"){
    llegir_arbre_string(a1);
    llegir_arbre_string(a2);
    a.plantar(s, a1, a2);
  }
}

void escriure_arbre_string(Arbre<string> &a){
  if(!a.es_buit()){
    Arbre<string> a1, a2;
    string s = a.arrel();
    a.fills(a1,a2);
    cout<<" "<<s;
    escriure_arbre_string(a1);
    escriure_arbre_string(a2);
    a.plantar(s, a1, a2);
  }else{
    cout<<" "<<"$";
  }
}
