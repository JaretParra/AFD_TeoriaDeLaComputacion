#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//Estructura del AFD
struct AFD {
    unordered_set<string> Estados;
    unordered_set<char> Alfabeto;
    unordered_map<string,unordered_map<char,string>> Transiciones;
    string EstadoInicial;
    string EstadoFinal;
};

//Definicion del AFD
AFD DefAutomata(){
    AFD Automata;

    Automata.Estados = {"q0", "q1", "q2"};
    Automata.Alfabeto = {'a', 'b'};
    Automata.EstadoInicial = "q0";
    Automata.EstadoFinal = "q2";

    //Se definen las transiciones
    Automata.Transiciones["q0"]['b'] = "q0";
    Automata.Transiciones["q0"]['a'] = "q1";
    Automata.Transiciones["q1"]['a'] = "q1";
    Automata.Transiciones["q1"]['b'] = "q2";
    Automata.Transiciones["q2"]['a'] = "q2";
    Automata.Transiciones["q2"]['b'] = "q2";

    return Automata;
}

//Define el funcionamiento del AFD
bool Proceso(const AFD& Automata, const string& Cadena){
    string EstadoActual = Automata.EstadoInicial;
    
    //Permite recorrer la cadena
    for(char Valor : Cadena){

        //Detecta un Valor invalido del Alfabeto
        if(Automata.Alfabeto.find(Valor) == Automata.Alfabeto.end()){  
            cout<<"Simbolo no valido: "<<Valor<<endl;
            return false;
        }

        //Detecta las transiciones no Validas
        auto Estado = Automata.Transiciones.find(EstadoActual);
        if(Estado == Automata.Transiciones.end() || Estado->second.find(Valor) == Estado->second.end()){
            cout<<"NO existe la Transicion "<<EstadoActual<<" con "<<Valor<<endl;
            return false;
        }
        
        //Cambia al estado siguiente
        string SigEstado = Estado->second.at(Valor);
        cout<<EstadoActual<<" -> "<<Valor<<" -> "<<SigEstado<<endl;
        EstadoActual = SigEstado;
    }

    //Detecta si se llego a un estado de Aceptacion
    if(EstadoActual == Automata.EstadoFinal){
        cout<<EstadoActual<<" Es de Aceptacion."<<endl;
        return true;
    }else{
        cout<<EstadoActual<<" No es de Aceptacion."<<endl;
        return false;
    }
}

int main(){
    //Se inicia el AFD
    AFD automata = DefAutomata();
    string cadena="";

    cout<<"\tBienvenido al programa de Visualizacion del AFD."<<endl;
    cout<<"(Solo ingrese combinaciones de 'a' y 'b')"<<endl;
    cout<<"Ingrese su cadena: ";
    cin>>cadena;

    //Cambia los valores a minuscula
    for(char X:cadena){
        X = tolower(X);
    }

    //Concluye si la cadena es Valida
    if(Proceso(automata,cadena)){
        cout<<"La cadena es Valida."<<endl;
    }else{
        cout<<"La cadena NO es Valida."<<endl;
    }

    return 0;
}