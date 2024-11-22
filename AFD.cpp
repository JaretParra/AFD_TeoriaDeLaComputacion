#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

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

bool ValidarCadena(const AFD& Automata, const string& Cadena){
    for(char valor : Cadena){
        if (Automata.Alfabeto.find(valor) == Automata.Alfabeto.end()) {
            cout<<"Símbolo no valido: "<<valor<<endl;
            return false;
        }
    }
}

bool Proceso(const AFD& Automata, const string& Cadena){
    string EstadoActual = Automata.EstadoInicial;
    
    for(char Valor : Cadena){
        auto Estado = Automata.Transiciones.find(EstadoActual);
        if(Estado == Automata.Transiciones.end() || Estado->second.find(Valor) == Estado->second.end()) {
            cout<<"NO existe la Transicion "<<EstadoActual<<" con "<<Valor<<endl;
            return false;
        }
    }
}

int main(){
    string cadena="";
    cout<<"\tBienvenido al programa de Visualizacion del AFD."<<endl;
    cout<<"(Solo ingrese combinaciones de 'a' y 'b')"<<endl;
    cout<<"Ingrese su cadena: ";
    cin>>cadena;
}