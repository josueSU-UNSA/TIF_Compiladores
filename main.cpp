#include<iostream>
#include<fstream>
#include"Syntax.h"
using namespace std;
//-----------------------------------------------------------------
// Our Spanish Programming language Syntax 
//<Prog>::<Inicio><Bloque>"Final"
//<Inicio>::<Forma>'\n'
//<Forma>::"Tortuga"|"Cuadrado"|"Flecha"|"Circulo"|"Triangulo"|"Clasico"

//<Bloque>:: avanzar(<DIST>)'n'<Bloque>
//<Bloque>::gira_izquierda(<DIST>)'n'<Bloque>
//<Bloque>::gira_derecha(<DIST>)'n'<Bloque>
//<Bloque>::'\n'

//<DIST>::number
// --------------------------------------------------------------------

int main(){
    Syntax test("testing_class_Syntax.txt","code_python_generated");
    (test.run_code())?cout<<"Succesfully execution\n":cout<<"There was a Mistake in the execution\n";
        // string hola="hello";
    // string instruction_to_run_code="py "+hola+".py";
    // char *instruction_to_run_code_char_array=new char[instruction_to_run_code.size()+1];
    // for(int i=0;i<instruction_to_run_code.size();i++){
    //     instruction_to_run_code_char_array[i]=instruction_to_run_code[i];
    // }
    // instruction_to_run_code_char_array[instruction_to_run_code.size()]='\0';
    // for(int i=0;i<instruction_to_run_code.size();i++){
    //     cout<<instruction_to_run_code_char_array[i];
    // }


    // string code_py="";
    // t.open("Hello.py");
    // aux_to_t.open("test.txt");
    // while(!aux_to_t.eof()){
    //     getline(aux_to_t,code_py);
    //     t<<code_py<<endl;
    // }

    // aux_to_t.close();
    // t.close();
    // if(analisis(test.txt)==true)system("py Hello.py");
    // else {
    //     // cout<""
    // }
    
    return 1;
}
