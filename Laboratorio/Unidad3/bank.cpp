#include <codecs.h>
#include <funcionalidades.h>

using namespace std;

void confirmedASession(string origen, int col){
    string** estructura = strucT(origen);
    int adminOpt;
    cout << "Usted ha iniciado como administrador " << endl;
    cout << "1. Para agregar un usuario nuevo" << endl;
    cout << "2. Salir" << endl;
    cin >> adminOpt;
    switch(adminOpt){
        case 1:
            cout << "Aqui es donde se supone que uno agrega/eliminar usuarios como admin" << endl;
            break;
        case 2:
            cout << "Aqui es donde se supone que uno se sale pq ajajaja no falta más" << endl; //No se si un admin tambien es usuario eso ni idea
    }
}


void confirmedUSession(string origen, int col){
    string** estructura = strucT(origen);
    int userOpt;
    unsigned long long nwsaldo;
    unsigned long long retiro;
    bool validR = true;
    nwsaldo = stoi(estructura[4][col]);
    cout << "1. Para consultar su saldo" << endl;
    cout << "2. Para hacer retiro de su dinero." << endl;
    cout << "3. Para salir" << endl;
    cin >> userOpt;
    switch(userOpt){
        case 1:
            cout << "Su saldo es: " << estructura[4][col] << endl;
            nwsaldo -= 1000;
            cout << nwsaldo << endl;
            cout << "Aqui es donde se supone que consulte saldo (-1000) xd" << endl;
            break;
        case 2:
            while(validR){
                cout << "Ingrese el monto a retirar: " << endl;
                cin >> nwsaldo;
                nwsaldo -= retiro;
                cout << nwsaldo << endl;
                }
            cout << "Aqui es donde se supone que pueda retirar (resta plata y los 1000 de ahorita)" << endl;
            break;
        case 3:
            cout << "Gracias por usar nuestro servicio de banco, vuelva pronto." << endl;
            break;
    }

    //Write_file----

}

int bankSession(string origen){
    string user;
    string password;
    string** estructura = strucT(origen);
    int b = countCols(origen);
    int col = 0;
    int state = 0;

    cout <<"Ingrese su cedula: ";
    cin >> user;

    for(int i = 1; i < 5; i++){
        for(int j = 0; j < b; j++){
            if(estructura[i][j] == user){
                col = j;
                cout << "Ingrese la contrasena: ";
                cin >> password;
                break;
            }
        }
        if(estructura[i][col] == password){
            state = 1;
            break;
        }
    }

    if(state == 1){
        cout << endl;
        if(estructura[3][col] == "1"){
            cout << endl << "****** ADMINISTRADOR ******" << endl << endl;
            confirmedASession(origen, col);
        }
        else if(estructura[3][col] == "0"){
            cout << endl << "****** USUARIO ******" << endl << endl;
            cout << "Usted ha ingresado como: " << estructura[0][col] << endl << endl;
            confirmedUSession(origen, col);
        }
    }

    if(state == 0){
       cout << "Credenciales Incorrectas" << endl;
    }

    return state;
}
