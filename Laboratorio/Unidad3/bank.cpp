#include <codecs.h>
#include <funcionalidades.h>
#include <codecs.h>
using namespace std;


bool uaccess(string user, string password,string origen, string** estructura){
    int col = 0;
    int colsU = countCols(origen);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < colsU; j++){
            if(estructura[i][j] == user){
                col = j;
                break;
            }
        }
        if(estructura[i][col] == password){
            return true;
        }
    }
    return false;
}

void userAccess(string** estructura, int j, string rutaIn, string rutaOut){
    int userOpt;
    long long nwSalary = stoi(estructura[4][j]);
    long long retiro;
    string newString = "";

    cout << "**** USUARIO ****" << endl;
    cout << "1. Para revisar el saldo actual (Se le debitara 1000 por realizar esta operacion)\n2. Para retirar dinero\n3. Para salir" << endl;
    cout << "Ingrese la opcion que desea realizar: ";
    cin >> userOpt;
    switch(userOpt){
        case 1:
            cout << "Su saldo era: " << estructura[4][j] << endl;
            nwSalary -= 1000;
            cout << "Actualizado: " << nwSalary << endl;
            break;
        case 2:
            cout << "Usted posee: " << estructura[4][j] << endl;
            cout << "Indique la cantidad que quiere retirar: " << endl;
            cin >> retiro;
            nwSalary -= 1000+retiro;
            cout << "Actualizado: " << nwSalary << endl;
            break;
    }

    if(nwSalary == 0){
        estructura[4][j] = to_string(nwSalary)+"0";
    }
    else{
        estructura[4][j] = to_string(nwSalary);
    }


    newString = convertArray(estructura,rutaIn,0);
    write_file(rutaIn,newString,1);
    write_file(rutaOut,metodo2(4,rutaIn),2);
    remove("../Unidad3/Archivos/structU.txt");
    menu_principal();
}


void adminAccess(string** estructura, int j, string rutaIn, string rutaOut){
    int admOpt;
    string opcion = "";
    string** newArray;
    string newString = "";
    cout << "**** ADMINISTRADOR ****" << endl;
    cout << "1. Para registrar un nuevo usuario\n2. Eliminar usuario \n3. Menu principal" << endl;
    cout << "Ingrese la opcion que desea realizar: ";
    cin >> admOpt;
    switch(admOpt){
        case 1:
            newArray = addCol(rutaIn);
            newString = convertArray(newArray,rutaIn,1);
            write_file(rutaIn,newString,1);
            write_file(rutaOut,metodo2(4,rutaIn),2);
            remove("../Unidad3/Archivos/structU.txt");
            menu_principal();
            break;
        case 2:
            opcion = printUsers(rutaIn);
            newArray = deleteCol(rutaIn, opcion);
            newString = convertArray(newArray,rutaIn,2);
            write_file(rutaIn,newString,1);
            write_file(rutaOut,metodo2(4,rutaIn),2);
            remove("../Unidad3/Archivos/structU.txt");
            menu_principal();
            break;
        case 3:
            menu_principal();
    }
}

void bankSession(string origenA, string origenU){

    string destinoU = "../Unidad3/Archivos/structU.txt";
    string destinoA = "../Unidad3/Archivos/structA.txt";

    decodiWrite(origenA,destinoA);
    decodiWrite(origenU,destinoU);
    string** estructuraU = strucT(destinoU);
    string** estructuraA = strucT(destinoA);
    string user = "";
    string password = "";
    int init = 0;
    int col = 0;
    bool granted;


    cout << "1. Para iniciar sesion como usuario \n2. Para iniciar sesion como administrador \n3. Menu principal " << endl;
    cout << "Ingrese una opcion: ";
    cin >> init;

    switch(init){
        case 1:
            cout << "Ingrese su cedula: ";
            cin >> user;
            cout << "Ingrese su contrasena: ";
            cin >> password;
            granted = uaccess(user,password,destinoU,estructuraU);
            col = posColumna(destinoU,estructuraU,user);
            if(granted == true){
                userAccess(estructuraU,col,destinoU,origenU);
            }
            else{
                cout << "Accesso invalido." << endl;
                menu_principal();
            }
            break;
        case 2:
            cout << "Ingrese su cedula: ";
            cin >> user;
            cout << "Ingrese su contrasena: ";
            cin >> password;
            granted = uaccess(user,password,destinoA,estructuraA);
            col = posColumna(destinoA,estructuraU,user);
            if(granted == true){
                adminAccess(estructuraU,col,destinoU,origenU);
            }

            else{
                cout << "Acceso Invalido." << endl;
                menu_principal();
            }
            break;
        case 3:
            menu_principal();

    }

}


void menu_principal(){

    string rutaU = "../Unidad3/Archivos/structU.dat";
    string rutaA = "../Unidad3/Archivos/structA.dat";

    string origen = "../Unidad3/Archivos/natural.txt";
    string destino = "../Unidad3/Archivos/natural.dat";

    int opcion = 0;
    cout << "|------ Menu principal ------|" << endl;
    cout << "1. Codecs \n2. Banco \n3. Salir" << endl;

    while(true){
    cout << "Selecciona una opcion: ";
    cin >> opcion;
    if(opcion == 1 || opcion == 2 || opcion == 3){
        break;
    }
    else{
        cout << "Ingrese una opcion valida." << endl;
    }

    }

    switch(opcion){
        case 1:
            cout << "Codificadores y decodificadores:" << endl;
            submenu(origen,destino);
        break;

        case 2:
            cout << "Aplicacion de banco: " << endl;
            bankSession(rutaA,rutaU);
        break;

        case 3:
        exit(1);

    }

}

