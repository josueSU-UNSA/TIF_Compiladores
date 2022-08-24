#include<iostream>
#include<string>
#include<fstream>


// Shapes Python:
    // Square
    // Arrow
    // Circle
    // Turtle
    // Triangle
    // Classic

//<Prog>::<Inicio><Bloque>"Final"
//<Inicio>::<Forma>'\n'
//<Forma>::"Tortuga"|"Cuadrado"|"Flecha"|"Circulo"|"Triangulo"|"Clasico"

//<Bloque>:: avanzar(<DIST>)'n'<Bloque>
//<Bloque>::gira_izquierda(<DIST>)'n'<Bloque>
//<Bloque>::gira_derecha(<DIST>)'n'<Bloque>
//<Bloque>::'\n'

//<DIST>::number_double
bool is_number(std::string num_input){
    if(!num_input.size())return false;
    for(int i=0;i<num_input.size();i++){
        if(!isdigit(num_input[i]))return false;
    }
    return true;
}

class Syntax{
    public:
        std::string m_path_script;
        std::string  m_path_script_to_python;
        std::string code_script_to_python;
    public:
    
        Syntax(std::string path_script,std::string path_script_to_python){
            // std::ofstream file_create_py;
            this->m_path_script=path_script;
            this->m_path_script_to_python=path_script_to_python;
            // file_create_py.open(path_script_to_python+".py");
            // file_create_py.close();
            // this->m_number_line=0;
        }
        

        bool Inicio(std::string &code){
            std::string shape="";
            
            
            for(int i=0;i<code.size();i++){
                if(code[i]==' '){
                    break;
                }
                else shape+=code[i];    
            }
            std::cout<<shape<<std::endl;
            if(shape=="Tortuga")shape="\"turtle\"";
            else if(shape=="Cuadrado") shape="\"square\"";
            else if(shape=="Flecha")   shape="\"arrow\"";
            else if(shape=="Circulo")  shape="\"circle\"";
            else if(shape=="Triangulo")shape="\"triangle\"";
            else if(shape=="Clasico")  shape="\"classic\"";
            else return false;


            code="turtle.shape("+shape+")";
            
            return true;
        }
        bool color(std::string &code){
            std::string aux="";
            int i=0;
            for(;i<code.size();i++){
                if(code[i]=='='){
                    i++;
                    break;
                    
                }
                aux+=code[i];
            
            }
            if(aux!="Color")return false;
            aux="";
            for(;i<code.size();i++){
                
                aux+=code[i];
            
            }
        //"red" 
        //"purple"
        //"brown"
        //"pink",
        //"green"


            if(aux=="rojo")aux="\"red\"";
            else if(aux=="purpura") aux="\"purple\"";
            else if(aux=="marron")   aux="\"brown\"";
            else if(aux=="rosado")  aux="\"pink\"";
            else if(aux=="verde")aux="\"green\"";
            else return false;


            code="turtle.color("+aux+")\n\tturtle.pencolor("+aux+")";
            
            return true;
        }
        bool velocidad(std::string &code){
            std::string aux="";
            int i=0;
            for(;i<code.size();i++){
                if(code[i]=='='){
                    i++;
                    break;
                    
                }
                aux+=code[i];
            
            }
            if(aux!="Velocidad")return false;
            aux="";
            for(;i<code.size();i++){
                
                aux+=code[i];
            
            }
        //Number
        //Más rápido: 0
        // Más lento: 1
        // lento : 3
        // normales: 6
        // Rápido: 10

            if(!is_number(aux))return false;


            code="turtle.speed("+aux+")";
            
            return true;
        }


        bool Bloque(std::string &code){
            std::string aux=code;
            if(velocidad(aux)){
                code=aux;
                return true;
            }
            if(color(aux)){
                code=aux;
                return true;
            }
            std::string movement="";
            int i=0;
            for(;i<code.size();i++){
                if(code[i]=='('){
                    i++;
                    break;
                }
                else movement+=code[i];    
            }

            if(movement=="avanzar")movement="forward";
            else if(movement=="gira_izquierda") movement="left";
            else if(movement=="gira_derecha")   movement="right";
            else return false;
            std::string num="";
            for(;i<code.size();i++){
                if(code[i]==')'){
                    
                    break;
                }
                else num+=code[i];    
            }
            if(!is_number(num))return false;
            movement="turtle."+movement+"("+num+")";
            code=movement;
            return true;
        }


        // bool Programa(){
        //     if(!Inicio())return false;
        //     if(!Bloque())return false;
            
        //     return true;
        // }
        
        bool analisis(){
            std::ifstream file_input;




            // std::string code_script_to_python;//Code python
            std::string code_per_line;//Aux to iterate all txt
            this->code_script_to_python+="import turtle\nfrom TurtleGIF import TurtleGIF\ndef draw_func(self):\n";
            
            // "import turtle
            // windows=turtle.Screen()
            // "
            // double parameter_to_function;
            
            

            file_input.open(this->m_path_script);
            if(!file_input.is_open())return false;
            
            // Inicio
            getline(file_input,code_per_line);
            if(Inicio(code_per_line))code_script_to_python+='\t'+code_per_line+'\n';
            else {
                std::cout<<"Wrong in Begin\n";
                file_input.close();
                return false;
            }

            // Bloque y Final
            while(!file_input.eof()){
                getline(file_input,code_per_line);
                if(!(int)(code_per_line[0]));
                
                else if(code_per_line=="Final"||code_per_line=="Final\n")break;
                else if(Bloque(code_per_line))code_script_to_python+='\t'+code_per_line+'\n';
                else{
                    file_input.close();
                    return false;
                } 
            }
            if(code_per_line!="Final"&&code_per_line!="Final\n"){
                this->code_script_to_python="";
                file_input.close();
                return false;
                
            }
            file_input.close();
            



            code_script_to_python+="\tturtle.bye()\n";
            code_script_to_python+="TurtleGIF.draw = draw_func\nnewturtle = TurtleGIF(2, name = \"img\")\nturtle.Screen().setup(1500,1500)\nnewturtle.record(fps=10)";

            return true;
        }
        bool run_code(){
            if(analisis()){
                std::ofstream file_to_run;
                file_to_run.open(this->m_path_script_to_python);
                if(!file_to_run.is_open())return false;
                for(int i=0;i<this->code_script_to_python.size();i++){
                    file_to_run<<this->code_script_to_python[i];
                }





                file_to_run.close();
                std::string instruction_to_run_code="py "+this->m_path_script_to_python;
                
                char *instruction_to_run_code_char_array=new char[instruction_to_run_code.size()+1];
                for(int i=0;i<instruction_to_run_code.size();i++){
                    instruction_to_run_code_char_array[i]=instruction_to_run_code[i];
                }
                instruction_to_run_code_char_array[instruction_to_run_code.size()]='\0';
                
                // system(instruction_to_run_code_char_array);

                return true;
            }

            else return false;
        }

};