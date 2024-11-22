#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

bool ValidacionCadena(string cadena){
    for(int i=0; i<cadena.size(); i++){
        switch (cadena.at(i)){
        case 'a':
            break;
        case 'b':
            break;
        default:
            i = cadena.size();
            return false;
            break;
        }
    }
}

struct AFD {        //Definicion del AFD
    unordered_set<string> Estados;
    unordered_set<char> Alfabeto;
    unordered_map<string,unordered_map<char,string>> Transiciones;
    string EstadoInicial;
    string EstadoFinal;
};

AFD DefAutomata(){
    AFD Automata;

    Automata.Estados = {"q0", "q1", "q2"};
    Automata.Alfabeto = {'a', 'b'};
    Automata.EstadoInicial = "q0";
    Automata.EstadoFinal = "q2";

    Automata.Transiciones["q0"]['b'] = "q0";
    Automata.Transiciones["q0"]['a'] = "q1";
    Automata.Transiciones["q1"]['a'] = "q1";
    Automata.Transiciones["q1"]['b'] = "q2";
    Automata.Transiciones["q2"]['a'] = "q2";
    Automata.Transiciones["q2"]['b'] = "q2";

    return Automata;
}



int main(){
    string cadena="";
    cout<<"\tBienvenido al programa de Visualizacion del AFD."<<endl;
    cout<<"(Solo ingrese combinaciones de 'a' y 'b')"<<endl;
    cout<<"Ingrese su cadena: ";
    cin>>cadena;
}