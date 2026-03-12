#include <iostream>
#include <vector>

using namespace std;

// Estructura define los campos de cada estudiante

struct Estudiante{
    string nombre;
    string cedula;
    float nota1;
    float nota2;
    float nota3;
    float promedio;
    string materia;
    string estado;
};
// Vector global  accesible por todas las funciones del programa
vector<Estudiante> estudiantes;

//Función registrar nuevo estudiante
void registrar(){
    Estudiante e;// se crea un estudiante vacio

    cout<<"Nombre: ";
    cin>>e.nombre;

    cout<<"Cedula: ";
    cin>>e.cedula;

    //pide nota uno con validacion
    do {
        cout<<"Nota 1 (0-10): ";
        cin>>e.nota1;
        if(e.nota1 < 0 || e.nota1 > 10)
            cout<<"Nota invalida, ingrese entre 0 y 10\n";
    } while(e.nota1 < 0 || e.nota1 > 10);

    //pide nota dos con validacion
    do {
        cout<<"Nota 2 (0-10): ";
        cin>>e.nota2;
        if(e.nota2 < 0 || e.nota2 > 10)
            cout<<"Nota invalida, ingrese entre 0 y 10\n";
    } while(e.nota2 < 0 || e.nota2 > 10);

        //pide nota tres con validacion
    do {
        cout<<"Nota 3 (0-10): ";
        cin>>e.nota3;
        if(e.nota3 < 0 || e.nota3 > 10)
            cout<<"Nota invalida, ingrese entre 0 y 10\n";
    } while(e.nota3 < 0 || e.nota3 > 10);

    //Calcula el promedio y estado
    e.promedio = (e.nota1 + e.nota2 + e.nota3)/3;
    e.estado = (e.promedio >= 6.0) ? "Aprobado" : "Reprobado";

    estudiantes.push_back(e);

    cout<<"Estudiante registrado\n";
}

//Funcion mostrar todos los registros
void mostrar(){
    //Verifica si esta registrado
    if(estudiantes.size() == 0){
        cout << "No hay estudiantes registrados\n";
        return;
    }
    for(int i=0;i<estudiantes.size();i++){
        cout << "\n--- Estudiante " << i+1 << " ---";
        cout<<"\nNombre: "<<estudiantes[i].nombre;
        cout<<"\nCedula: "<<estudiantes[i].cedula;
        cout<<"\nNota1: "<<estudiantes[i].nota1;
        cout<<"\nNota2: "<<estudiantes[i].nota2;
        cout<<"\nNota3: "<<estudiantes[i].nota3;
        cout<<"\nPromedio: "<<estudiantes[i].promedio<<endl;
        cout << "\nEstado: "   << estudiantes[i].estado << endl;
    }
}

//Funcion buscar estudiante con cedula
void buscar(){
    string ced;
    cout<<"Ingrese cedula: ";
    cin>>ced;
//Recorre el vector buscando la cedula
    for(int i=0;i<estudiantes.size();i++){
        if(estudiantes[i].cedula==ced){
            cout<<"Estudiante encontrado\n";
            cout << "Nombre  : " << estudiantes[i].nombre   << endl;
            cout << "Promedio: " << estudiantes[i].promedio << endl;
            cout << "Estado  : " << estudiantes[i].estado   << endl;
            //cout<<estudiantes[i].nombre<<" Promedio: "<<estudiantes[i].promedio<<endl;
            return;
        }
    }
    cout << "Estudiante no encontrado\n";
}

//Funcion modificar las notas de un estudiante
void modificar(){
    string ced;
    cout<<"Cedula del estudiante: ";
    cin>>ced;

    for(int i=0;i<estudiantes.size();i++){
        if(estudiantes[i].cedula==ced){

            // Pedir nuevas notas con validación
            do {
                cout << "Nueva nota 1 (0-10): ";
                cin  >> estudiantes[i].nota1;
                if(estudiantes[i].nota1 < 0 || estudiantes[i].nota1 > 10)
                    cout << "Nota invalida\n";
            } while(estudiantes[i].nota1 < 0 || estudiantes[i].nota1 > 10);

            do {
                cout << "Nueva nota 2 (0-10): ";
                cin  >> estudiantes[i].nota2;
                if(estudiantes[i].nota2 < 0 || estudiantes[i].nota2 > 10)
                    cout << "Nota invalida\n";
            } while(estudiantes[i].nota2 < 0 || estudiantes[i].nota2 > 10);

            do {
                cout << "Nueva nota 3 (0-10): ";
                cin  >> estudiantes[i].nota3;
                if(estudiantes[i].nota3 < 0 || estudiantes[i].nota3 > 10)
                    cout << "Nota invalida\n";
            } while(estudiantes[i].nota3 < 0 || estudiantes[i].nota3 > 10);;

            estudiantes[i].promedio =(estudiantes[i].nota1 +estudiantes[i].nota2 +estudiantes[i].nota3)/3;
             estudiantes[i].estado = (estudiantes[i].promedio >= 6.0) ? "Aprobado" : "Reprobado";

            cout<<"Datos modificados\n";
             return;
        }
    }
    cout << "Estudiante no encontrado\n";
}


//Funcion eliminar un estudiante por cedula
void eliminar(){
    string ced;
    cout<<"Cedula a eliminar: ";
    cin>>ced;

    for(int i=0;i<estudiantes.size();i++){
        if(estudiantes[i].cedula==ced){
            // erase elimina el elemento en la posición i
            estudiantes.erase(estudiantes.begin()+i);
            cout<<"Registro eliminado\n";
            break;
        }
    }
    cout << "Estudiante no encontrado\n";
}
//Funcion genera un reporte final
void reporte(){
    // Verificar si hay datos para reportar
    if(estudiantes.size() == 0){
        cout << "No hay estudiantes registrados\n";
        return;
    }
    int aprobados = 0;
    int reprobados = 0;
    float suma = 0;
    float mayor = 0;

    for(int i=0; i<estudiantes.size(); i++){
        suma += estudiantes[i].promedio;
        //cuenta aprobados y reprobados
        if(estudiantes[i].promedio >= 7.0)
            aprobados++;
        else
            reprobados++;
        //actualiza el mayor promedio
        if(estudiantes[i].promedio > mayor)
            mayor = estudiantes[i].promedio;
    }



    cout << "";
    cout << "Total     : " << estudiantes.size() << endl;
    cout << "Aprobados : " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
    cout << "Mayor     : " << mayor << endl;

}

//Funcion principal
int main(){
    //Datos iniciales
    estudiantes.push_back({"Juan", "0101",8,9,7, 8,"Aprobado"});
    estudiantes.push_back({"Maria", "0102",9,8,10, 9,"Aprobado"});
    estudiantes.push_back({"Pedro","0103", 3, 4, 2,  3.00, "Reprobado"});
    estudiantes.push_back({"Ana", "0104",10,9,9, 9.3,"Aprobado"});
    estudiantes.push_back({"Luis","0105",2,3,4, 3.00, "Reprobado"});
    estudiantes.push_back({"Carlos","0106",5,5,6, 5.3,"Reprobado"});
    estudiantes.push_back({"Sofia","0107",2,7,6, 5,"Reprobado"});
    estudiantes.push_back({"Diego","0108",6,5,7, 6,"Reprobado"});
    estudiantes.push_back({"Elena","0109",8,9,10, 9,"Aprobado"});
    estudiantes.push_back({"Mateo","0110",4,3,5,4.00, "Reprobado"});

    int op;

    // Ciclo principal del menú, se repite hasta que el usuario elija 7
    do{
        cout<<"\nMENU\n";
        cout<<"1 Registrar\n";
        cout<<"2 Mostrar\n";
        cout<<"3 Buscar\n";
        cout<<"4 Modificar\n";
        cout<<"5 Eliminar\n";
        cout<<"6 Reporte\n";
        cout<<"7 Salir\n";
        cout << "Seleccione: ";

        cin>>op;
    // Ejecutar la función segun la opcion escogida
        switch(op){

            case 1: registrar(); break;
            case 2: mostrar(); break;
            case 3: buscar(); break;
            case 4: modificar(); break;
            case 5: eliminar(); break;
            case 6: reporte(); break;

        }

    }while(op!=7);

}
