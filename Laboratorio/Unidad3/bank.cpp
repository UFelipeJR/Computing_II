#include <codecs.h>
#include <funcionalidades.h>

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
                cout << estructura[i][j] << endl;
                col = j;
                cout << "Ingrese la contrasena: ";
                cin >> password;
                break;
            }
        }
        if(estructura[i][col] == password){
            cout << estructura[i][col] << endl;
            state = 1;
        }
    }
    if(state == 0){
       cout << "Credenciales Incorrectas" << endl;
    }

    return state;

}

void confirmedASession(){
    int adminOpt = 2;
    cout << "Usted ha iniciado como administrador ";
    switch(adminOpt){
        case 1:
            cout << "Aqui es donde se supone que uno agrega usuarios como admin" << endl;
            break;
        case 2:
            cout << "Aqui es donde se supone que uno se sale pq ajajaja no falta más" << endl; //No se si un admin tambien es usuario eso ni idea


    }
}


void confirmedUSession(){
    int userOpt = 2;
    cout << "Usted ha iniciado como usuario ";
    switch(userOpt){
        case 1:
            cout << "Aqui es donde se supone que consulte saldo (-1000) xd" << endl;
            break;
        case 2:
            cout << "Aqui es donde se supone que pueda retirar (resta plata y los 1000 de ahorita)" << endl;
            break;
        case 3:
            cout << "Salite" << endl;
            break;
    }

}
