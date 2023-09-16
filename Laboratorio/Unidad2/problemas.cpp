#include "funcionalidades.h"
#include "problemas.h"


void MachineMoney_Problema1(){

    /*
     * Problema 1
     * Se necesita un programa que permita determinar la mínima combinación de billetes y monedas para
     * una cantidad de dinero determinada. Los billetes en circulación son de $50.000, $20.000, $10.000, $5.000, $2.000
     * y $1.000, y las monedas son de $500, $200, $100 y $50. Hacer un programa que entregue el número de billetes
     * y monedas de cada denominación para completar la cantidad deseada. Si por medio de los billetes y monedas
     * disponibles no se puede lograr la cantidad deseada, el sistema deberá decir lo que resta para lograrla. Use arreglos
     * y ciclos para realizar el programa.
     *
     * Variables, constantes y arreglos:
     * dinero_restante: variable que almacena el dinero restante durante el tiempo de ejecución.
     * denominaciones: arreglo de numeros enteros con todas las denominaciones posibles de las monedas.
     * cantidad: arreglo donde se almacenerá la cantidad de billetes o monedas necesarias para cada denominación.
     *
     * Retorno:
     * Vacio
    */


    int dinero_restante = 0;
    int denominaciones[10] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int cantidad[10];
    cout << "Ingrese la devuelta: ";
    cin >> dinero_restante;

    for(int i = 0; i < 10; i++){
        cantidad[i] = dinero_restante / denominaciones[i];
        dinero_restante %= denominaciones[i];
        cout << "De " << denominaciones[i] << ": " << cantidad[i] << endl;
        if(i == 9){
            cout << "El dinero restante es: " << dinero_restante << endl;
        }
    }
}

void contAlphabet_Problema2(){

    /*
     * Problema 2
     * Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprima este arreglo
     * y luego imprima cuantas veces se repite cada letra en el arreglo.
     * Ejemplo: supóngase que se genera el arreglo de 10 elementos: ABARSECAAB. El programa debe imprimir: ABAR-SECAAB
     *
     * Variables, constantes y arreglos:
     * arregloLetras: arreglo definido por el usuario y dado como parametro.
     * punteroIterador: almacena la dirección de memoria del primer elemento del arreglo.
     * contAparicion: contador de apariciones de una letra.
     *
     * Retorno:
     * Vacio
    */

    char* arregloLetras = genDinamicRandomAlphabet(200);
    char* punteroIterador = arregloLetras;
    int contAparicion = 0;

    for (char letra = 'A'; letra <= 'Z'; letra++) {
        while(*punteroIterador != '\0'){
            if(letra == *punteroIterador){
                contAparicion ++;
            }
            punteroIterador ++;
        }
        cout << letra << ":" << contAparicion << endl;
        contAparicion = 0;
        punteroIterador = arregloLetras;
    }
    delete[] arregloLetras;

}


bool sameChain_Problema3(char* cadena1,char* cadena2){

    /*
     * Problema 3
     * Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
     * iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas.
     * Escriba un programa de prueba.
     *
     * Variables, constantes y arreglos:
     * cadena1: primera cadena utilizada para la comparación.
     * cadena2: segunda cadena utilizada para la compatación.
     *
     * Retorno:
     * Valor booleano en base a la comparación.
     *
    */

    if(lenChar(cadena1)!= lenChar(cadena2)){
        return false;
    }

    for(int i = 0; i < lenChar(cadena1); i++){
        if(cadena1[i] != cadena2[i]){
            return false;
        }
    }
    return true;

}


int charsToInt_Problema4(char* cadenaD){

    /*
     * Problema 4
     * Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero
     * y retorne dicho número. Escriba un programa de prueba.
     * Ejemplo: si recibe la cadena “123”, debe retornar un int con valor 123.
     *
     * Variables, constantes y arreglos:
     * resultado: calculo inicial equivalente a las cadenas de caracteres.
     * cadenaD: arreglo definido por el usuario y dado como parametro.
     * punteroIterador: almacena la dirección de memoria del primer elemento del arreglo.
     * signo: valor que determina si el valor entero será positivo o negativo.
     *
     * Retorno:
     * Vacio
    */

    int resultado = 0;
    char* punteroIterador = cadenaD;
    int signo = 1;

    if(*punteroIterador == '-'){
        signo = -1;
    }
    while(*punteroIterador != '\0'){
        if(*punteroIterador >= '0' && *punteroIterador <= '9'){
            resultado = resultado * 10 + (*punteroIterador - '0');
        }
        punteroIterador ++;
    }

    cout << "El numero entero es: " << resultado * signo << endl;

    return resultado * signo;

}


void IntToChar_Problema5(int numero, char cadena[], int& longitud){

    /*
     * Problema 5
     * Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres. Use
     * parámetros por referencia para retornar la cadena. Escriba un programa de prueba.
     * Ejemplo: si recibe un int con valor 123, la cadena que se retorne debe ser “123”.
     *
     * Variables, constantes y arreglos:
     * numero: numero entero que será convertido a un arreglo de caracteres.
     * cadena: cadena en la que será almacenado el valor entero.
     * longitud: tamaño de la cadena que será cambiado por referencia.
     *
     * Retorno:
     * Vacio.
     *
     * Ejemplo de uso
     * int numero = 1234567;
     * char resultado[20];
     * int longitud;
     * IntToChar_Problema5(numero, resultado, longitud);
     * cout << "El numero " << numero << " convertido a cadena es: " << resultado << endl;
     *
    */

    int num = numero;
    int digitos = contDigits(numero);
    int indice = 0;

    if (numero == 0) {
        cadena[0] = '0';
        cadena[1] = '\0';
        longitud = 1;
        return;
    }

    if (numero < 0) {
        digitos++;
        num = -numero;
        cadena[0] = '-';
    }

    indice = digitos - 1;
    while (num != 0) {
        int digito = num % 10;
        cadena[indice] = '0' + digito;
        num /= 10;
        indice--;
    }

    cadena[digitos] = '\0';
    longitud = digitos;
}

void upperWord_Problema6(char* cadenaC){

    /*
     * Problema 6
     * Escriba un programa que reciba una cadena de caracteres y cambie las letras minúsculas por
     * mayúsculas, los demás caracteres no deben ser alterados.
     * Ejemplo: se recibe Man-zana debe mostrar MAN-ZANA.
     *
     * Variables, constantes y arreglos:
     * cadenaC: arreglo definido por el usuario y dado como parametro.
     * punteroIterador: almacena dirección de memoria del primer elemento de CadenaC.
     *
     * Retorno:
     * Vacio
    */

    char* punteroIterador = cadenaC;

    cout << "Original: ";

    while(*punteroIterador != '\0'){
        cout << *punteroIterador;
        punteroIterador ++;
    }

    cout << ". En mayuscula: ";
    punteroIterador = cadenaC;
    while(*punteroIterador != '\0'){
        cout << upperChar(*punteroIterador);
        punteroIterador ++;
    }

    cout << endl;

}


void DeleteRepeatedCharacters_Problema7(char* cadena){

    /*
     * Problema 7. Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.
     * Ejemplo: se recibe bananas debe mostrar bans.
     * Nota: la salida del programa debe ser: Original: bananas. Sin repetidos: bans.
     *
     * Variables, constantes y arreglos:
     * cadena: cadena original.
     * caracteres: arreglo de caracteres que se van encontrando en la cadena.
     * encontrado: variable booleana para indentificar aparición de caracter.
     *
     * Retorno:
     * Vacio.
     *
    */

    char caracteres[lenChar(cadena)] = " ";
    bool encontrado = false;


    cout << "Original: " << cadena << endl;
    cout << "Sin repetidos: ";

    for(int i = 0; i < lenChar(cadena); i++) {
        encontrado = false;

        for(int j = 0; j < lenChar(cadena); j++) {
            if(cadena[i] == caracteres[j]) {
                encontrado = true;
                break;
            }
        }

        if(!encontrado) {
            caracteres[i] = cadena[i];
            cout << cadena[i];

        }
    }
    cout << endl;
}

void splitCharNum_Problema8(char* cadenaC){

    /*
     * Problema 8
     * Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
     * generando una cadena que no tiene números y otra con los números que había en la cadena original.
     * Si se recibe abc54rst el programa debe imprimir las cadenas: abcrst y 54.
     *
     * Variables, constantes y arreglos:
     * cadenaC: arreglo definido por el usuario y dado como parametro.
     * punteroIterador: almacena dirección de memoria del primer elemento de CadenaC.
     *
     * Retorno:
     * Vacio.
    */

    char* punteroIterador = cadenaC;

    //Se itera en todo el arreglo con el rango de las letras mayúsculas y minúsculas en ASCII
    while(*punteroIterador != '\0'){
        if((*punteroIterador >= 'a' && *punteroIterador <= 'z') || (*punteroIterador >= 'A' && *punteroIterador <= 'Z') ){
            cout << *punteroIterador;
        }
        punteroIterador++;
    }

    punteroIterador = cadenaC;
    cout << " y ";

    //Se itera en todo el arreglo con el rango de los números en ASCII
    while(*punteroIterador != '\0'){
        if(*punteroIterador >= '0' && *punteroIterador <= '9'){
            cout << *punteroIterador;
        }
        punteroIterador++;
    }

    cout << endl;

}

void SumSubstring_Problema9(char* cadenaC, int n){

    /*
     * Problema 9. Escribir un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa
     * debe separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse
     * dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número.
     * Ejemplo: Si n=3 y se lee el arreglo 87512395 la suma seria 087+512+395=994.
     * Nota: la salida del programa debe ser:
     * Original: 87512395.
     * Suma: 994.
     *
     * Variables, constantes y arreglos:
     * cadenaC: cadena de caracteres numericos.
     * n: numero n que determina la cantidad de elementos que tendrá cada subcadena.
     * faltantes: cantidad de caracteres faltantes para ser divisible entre n.
     * longitudOriginal: longitud de la cadena numerica original.
     * extremoInferior: extremo inferior para extraer la subcadena.
     * extremoSuperior: extremo superior para extraer la subcadena.
     * suma: suma de substrings.
     * i: variable de control del while
     *
     * Retorno:
     * Vacio.
     *
    */

    int faltantes = 0;
    int longitudOriginal = lenChar(cadenaC);
    int extremoInferior = 0;
    int extremoSuperior = 0;
    int suma = 0;
    int i = 0;
    faltantes = NearbyMulti(n, longitudOriginal) - longitudOriginal;
    char* arregloAux = new char[longitudOriginal + faltantes + 1];



    while (i < faltantes + longitudOriginal) {
        if (i < faltantes) {
            arregloAux[i] = '0';
        } else {
            arregloAux[i] = cadenaC[i - faltantes];
        }
        i++;
    }

    arregloAux[i] = '\0';

    extremoSuperior += n;

    while(extremoSuperior <= lenChar(arregloAux)){
        suma += charToInt(slicing(arregloAux,extremoInferior,extremoSuperior));
        extremoInferior += n;
        extremoSuperior += n;
    }

    cout << "El numero original es: " << cadenaC << endl;
    cout << "La suma es: " << suma << endl;

}

void romanToArabic_problema10(char* romanNumber){

    /*
     * Problema 10
     * Escribir un programa que permita convertir un número en el sistema romano al sistema arábigo
     * usado actualmente. A continuación se encuentran los caracteres usados en el sistema romano y su
     * equivalente arábigo:
     * M: 1000
     * D: 500
     * C: 100
     * L: 50
     * X: 10
     * V: 5
     * I: 1
     *
     * Variables, constantes y arreglos:
     * romanNumber: arreglo definido por el usuario y dado como parametro.
     * punteroIterador: almacena dirección de memoria del primer elemento de romanNumber.
     * romanoActual: numero romano equivalente relacionado a una posicion y una letra.
     * romanoSiguiente: numero siguiente a romano actual.
     * total: contador total de numero arabico.
     *
     * Retorno:
     * Vacio.
    */

    char* punteroIterador = romanNumber;
    int romanoActual = 0;
    int romanoSiguiente = 0;
    int total = 0;

    if (!checkRoman(romanNumber)) {
        cout << "El numero romano ingresado no es valido" << endl;
    }

    else {
        while (*punteroIterador != '\0') {
            cout << *punteroIterador;
            romanoActual = equivRoman(*punteroIterador);

            // Verificamos si existe un numero después del actual
            if (*(punteroIterador + 1) != '\0') {
                romanoSiguiente = equivRoman(*(punteroIterador + 1));

                if(romanoActual < romanoSiguiente){
                    total -= romanoActual;
                }

                else{
                    total += romanoActual;
                }

            }

            else {
                total += romanoActual;
            }

            punteroIterador++;
        }
    }

    cout << endl << "Corresponde a: " << total << endl;
}

void cinemaSeats_Problema11(){
    /*
     * Problema 11
     *
     * Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de
     * la sala de cine están organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación
     * de la sala que indique que asientos están disponibles y cuales se encuentran reservados. Además debe permitir
     * realizar reservas o cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).
     *
     * Que se muestre como:
     *
     * A1 +   +   +   +
     * B1 -   -   +   +
     * C1 -   -   -   - , Donde + representa los asientos reservados y - representa asientos disponibles.
     *
     * Variables, constantes y arreglos-
     * letterReservation: letra para indicar en que fila nos vamos a ubicar de la matriz
     * numberSeat: numero de columna donde nos iremos a ubicar
     * arreglo: variable que lleva la matriz completa de chars
     *
     * Retorno:
     * Vacio.
     */

    char letterReservation;
    int numberSeat;
    int optionSeats;
    char **arreglo;
    arreglo = llenarMatrizCine();
    cout << "*** Menu del Cine ***" << endl;
    cout << "1. Para reservar una silla" << endl << "2. Para cancelar una reserva" << endl << "3. Para salir" << endl;
    cin >> optionSeats;

    while(optionSeats != 0){
        if (optionSeats == 1){
            int columna = -1;
            int fila = 0;
            cout << "Ingrese la fila a reservar: ";
            cin >> letterReservation;

            cout << "Ingrese el numero de asiento: ";
            cin >> numberSeat;

            for(char i = 'A'; i <= letterReservation; i++){
                if(i == letterReservation){
                    for(int j = 0; j <= numberSeat; ++j){
                        if(j == numberSeat){
                            arreglo[fila][columna] = '+';
                        }
                        else{
                            columna++;
                        }
                    }
                }
                else{
                    fila++;
                }
            }
            cout << "1. Para reservar otro asiento" << endl << "2. Para cancelar una reserva" << endl << "3. Para salir" << endl;
            cin >> optionSeats;
        }
        else if(optionSeats == 2){
            int columna = -1;
            int fila = 0;
            cout << "Ingrese la fila a reservar: ";
            cin >> letterReservation;

            cout << "Ingrese el numero de asiento: ";
            cin >> numberSeat;

            for(char i = 'A'; i <= letterReservation; i++){
                if(i == letterReservation){
                    for(int j = 0; j <= numberSeat; ++j){
                        if(j == numberSeat){
                            arreglo[fila][columna] = '-';
                        }
                        else{
                            columna++;
                        }
                    }
                }
                else{
                    fila++;
                }
            }
            cout << "1. Para reservar un asiento" << endl << "2. Para cancelar otra reserva" << endl << "3. Para salir" << endl;
            cin >> optionSeats;
        }
        else if(optionSeats == 3){
            printMatrizCine(arreglo);
            cout << "*** Vuelva pronto ***" << endl;
            break;
        }
    }
    delete[] arreglo;
}

void magicSquare_Problema12(){

    /*
     * Problema 12
     * Un cuadrado mágico es una matriz de números enteros sin repetir, en la que la suma de los números
     * en cada columna, cada fila y cada diagonal principal tienen como resultado la misma constante. Escriba
     * un programa que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique si la
     * matriz es un cuadrado mágico.
     *
     * Nota:
     * 4 9 2
     * 3 5 7
     * 8 1 6
     *
     * Variables, constantes y arreglos:
     * arreglo: arreglo definido por el usuario y dado como parametro.
     * n: tamaño de uno de los lados de la matriz.
     * sumConst: total de la suma de la diagonal que será usada como referencia.
     * sumFilas: suma de las filas.
     * sumColumnas: suma de las columnas.
     * estado: indicador de si es o no cudrado mágico.
     *
     * Retorno:
     * Vacio.
    */

    int** arreglo;
    int n = 0;
    int sumConst = 0;
    int sumFilas = 0;
    int sumColumnas = 0;
    bool estado = true;

    cout << "Ingrese el tamano de un lado de la matriz: ";cin>> n;

    arreglo = genDinamicMatriz(n,n);
    fillMatriz(arreglo,n,n);
    printMatriz(arreglo,n,n);

    for(int i = 0; i < n; i++){
        sumConst += arreglo[i][i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sumFilas += arreglo[i][j];
            sumColumnas += arreglo[j][i];
        }
        if(sumFilas != sumConst || sumColumnas != sumConst){
            estado = false;
            break;
        }
        sumFilas = 0;
        sumColumnas = 0;
    }

    if(estado != true){
        cout << "No es un cuadrado magico" << endl;
    }
    else{
        cout << "Es un cuadrado magico" << endl;
    }

    cleanMemoryMatrizmxn(n,arreglo);
}


int starmatrix_Problema13(int** imagen, int fil, int col){
    /*
     * Problema 13
     *
     * Se tiene una fotografía digitalizada de una porción de la galaxia NGC 1300 que está ubicada a
     * 61.000.000 de años luz del planeta Tierra. La representación digital de la imagen está constituida por una matriz
     * de números enteros; en la cual, cada uno representa la cantidad de luz en ese punto de la imagen.
     *
     * La ecuacion de indices es (E(i, j)+E(i, j-1)+E(i-1,j)+E(i+1, j))/5 > 6
     *
     * Variables, constantes o arreglos.
     * cuentas: variable que me lleva la sumatoria de los indices en la matriz (sea Eij)
     * stars: cuantas estrellas habra dentro de la matriz impuesta.
     *
     * Retorno:
     *  - stars
     *
     */
    int cuentas;
    int stars;
    for(int i = 1; i < col-1;i++){
        for(int j = 1; j < fil-1; j++){
            cuentas = imagen[i][j]+imagen[i][j-1]+imagen[i][j+1]+imagen[i-1][j]+imagen[i+1][j];
            if(cuentas/5 > 6){
                stars++;
            }
        }
    }
    cout << "Hay " << stars << " estrellas" << endl;
    return stars;
}

void rotatedMatriz_Problema14(){

    /*
     * Problema 14
     *
     * Elabore un programa que llene una matriz 5x5 con los números del 1 al 25 y la imprima, luego
     * imprima la matriz rotada 90, 180 y 270 grados.
     *
     * Variables, constantes y arreglos.
     * matriz: matriz o doble puntero donde está almacenada.
     * val: inicialización del elemento inicial de la matriz
     *
     * Retorno:
     * Vacio.
    */

    int** matriz = genDinamicMatriz(5,5);
    int val = 1;

    for(int i = 0; i<5;i++){
        for(int j = 0; j<5;j++){
            matriz[i][j] = val;
            val ++;
        }
    }

    cout << "Matriz Original:" << endl;
    rotatedMatriz(matriz,5,5,0);

    cout << "\nMatriz Rotada 90 Grados:" << endl;
    rotatedMatriz(matriz,5,5,90);

    cout << "\nMatriz Rotada 180 Grados:" << endl;
    rotatedMatriz(matriz,5,5,180);

    cout << "\nMatriz Rotada 270 Grados:" << endl;
    rotatedMatriz(matriz,5,5,270);

    cleanMemoryMatrizmxn(5,matriz);

}

void squareintersec_Problema15(int arregloA[4] , int arregloB[4], int (&interseccion)[4]){
    /*
     * Problema 15
     *
     * Implemente una función que reciba 2 arreglos que representen los rectángulos A y B, y por referencia retorne un
     * rectángulo C (con la misma estructura descrita anteriormente) que corresponda a la intersección de A y B
     *
     * Variables, constantes y arreglos.
     * x1_arregloA: componente x del rectangulo A
     * x1_arregloB: componente x del rectangulo B
     * y1_arregloA: componente y del rectangulo A
     * y1_arregloB: componente y del rectangulo A
     *
     * interseccion: arreglo vacio donde tenemos que ubicar nuestros datos de la interseccion
     *
     * Retorno:
     * n/a
     *
     */
    int x1_arregloA = 0;
    int x1_arregloB = 0;
    int y1_arregloA = 0;
    int y1_arregloB = 0;

    if (arregloA[0] > arregloB[0]) {
        interseccion[0] = arregloA[0];
    }

    else {
        interseccion[0] = arregloB[0];
    }

    if (arregloA[1] > arregloB[1]) {
        interseccion[1] = arregloA[1];
    }

    else {
        interseccion[1] = arregloB[1];
    }

    x1_arregloA = arregloA[0] + arregloA[2];
    x1_arregloB = arregloB[0] + arregloB[2];

    if (x1_arregloA < x1_arregloB) {
        interseccion[2] = x1_arregloA - interseccion[0];
    }

    else {
        interseccion[2] = x1_arregloB - interseccion[0];
    }

    y1_arregloA = arregloA[1] + arregloA[3];
    y1_arregloB = arregloB[1] + arregloB[3];
    if (y1_arregloA < y1_arregloB) {
        interseccion[3] = y1_arregloA - interseccion[1];
    }

    else {
        interseccion[3] = y1_arregloB - interseccion[1];
    }

}

void CombiPaths_Problema16(int n){

    /*
     * Problema 16
     *
     * En una malla de 2x2, realizando únicamente movimientos hacia la derecha y hacia abajo hay 6
     * posibles caminos para llegar de la esquina superior izquierda a la inferior derecha.
     *
     * Se usa una generalización de la combinatoria coeficiente binomial (nb,k)
     * C(n, k) = n! / (k! * (n - k)!))
     *
     * Variables, constantes y arreglos.
     * n: numero ingresado por el usuario que determina el tamaño de la malla.
     *
     * Retorno:
     * Vacio.
    */

    unsigned long long caminos = 1;

    for (int i = 0; i < n; ++i) {
        caminos *= (2 * n - i);
        caminos /= (i + 1);
    }

    cout << "Para una malla de " << n << "x" << n << " puntos hay " << caminos << " caminos." << endl;
}

void friendlynumbers_Problema17(int numero){

    /*
     * Problema 17
     *
     * Dos números a y b (a != b) son amigables si la suma de los divisores de a (excluyéndose el mismo)
     * es igual a b, y viceversa. Ej: los divisores de 220 son 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110; y suman 284. Los divisores
     * de 284 son 1, 2, 4, 71 y 142; y suman 220. Entonces 220 y 284 son amigables. Escribir un programa que reciba un
     * número y halle la suma de todos los números amigables menores al número ingresado.
     *
     * Variables, constantes y arreglos.
     * numero: el numero ingresado por el usuario que determina el "limite" para calcular sus amigables
     *
     * Retorno:
     * n/a
     *
     *
     */
    int sumaAmigables = 0;
    int b = 0;


    for(int a = 1; a <= numero; a++) {
        b = divisoresSum(a);
        if (a == numero) {
            sumaAmigables += b;
        }
    }

    cout << "El resultado de la suma es: " << sumaAmigables << endl;

}


void permulexicographical_Problema18(int n){

    /*
     * Problema 18
     *
     * Las permutaciones lexicográficas son permutaciones ordenadas numérica o alfabéticamente, por ejemplo
     * las permutaciones lexicográficas de 0,1 y 2 son: 012, 021, 102, 120, 201, 210. Escribir un programa que
     * reciba un número n y halle la enésima permutación lexicográfica de los números entre 0 y 9.
     *
     * Variables, constantes y arreglos.
     * n: numero ingresado por el usuario para determinar la enesima permutación.
     *
     * Retorno:
     * Vacio.
    */


    int numeros[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    long long permutacion = 0;
    int nAux = n;
    long long fact = 0;
    n--;

    for (int i = 9; i >= 0; i--) {
        fact = factorial(i);
        int indice = n / fact;
        permutacion = permutacion * 10 + numeros[indice];

        // Eliminar el número usado moviendo los elementos a la izquierda
        for (int j = indice; j < 9; j++) {
            numeros[j] = numeros[j + 1];
        }

        n %= fact;
    }

    cout << "La permutacion numero " << nAux << " es: " << permutacion << endl;

}
