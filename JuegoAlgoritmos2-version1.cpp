#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;


// Juego de Daniel Adivinar palabras 

string jugadores() {
    // En esta funcion vamos a poner a los jugadores a que ingresen su nombre 
    string nombre;
    cout << "Ingrese el nombre del jugador ";
    getline(cin, nombre);
    cout << endl << endl;
    return nombre;
}
map<string, string> palabras_significados = {// El map almacena valores de tio clave valor 
    {"thor", "PrÃ­ncipe y guerrero de Asgard, dios del trueno, protector de la tierra, y de los 9 reinos."},
    {"loki", "El Dios de las Mentiras y un experto ilusionista, puede cambiar su aspecto fÃ­sico a voluntad."},
    {"ironman", "Genio, multimillonario, playboy y filantropo. AÃºn con metralla en su pecho, existe la prueba de que si tiene corazÃ³n."},
    {"spiderman", "Capaz de treparse y adherirse a las paredes y un sentido subconsciente de premoniciÃ³n de peligro. 'Un gran poder conlleva una gran responsabilidad'."},
    {"hulk", "Salvage y furioso, la mÃ¡quina de rabia verde."},
    {"thanos", "Su unico objetivo es obtener las seis Gemas del Infinito, para estabilizar la superpoblaciÃ³n del universo y evitar lo que Ã©l ve como su inevitable desapariciÃ³n."},
    {"antman", "Tiene la capacidad de reducirse a tamaÃ±o subatÃ³mico."},
    {"brujaescarlata", "Es la magia del caos y tiene el control mental. Hydra realizÃ³ experimentos con la Gema de la Mente."},
    {"vision", "NaciÃ³ como un nuevo cuerpo para UltrÃ³n, con sentidos sobre humanos gracias a la gema de la mente."},
    {"capitanamerica", "SÃ­mbolo de libertad, un supersoldado que lucha contra las potencias enemigas de la Segunda Guerra Mundial."}
};


pair<string, string> obtenerPalabraAleatoria() { //Pair tiene la capacidad de alamcenar dos elementos como uno solo objeto.
    auto aleatorio = palabras_significados.begin(); // auto: Define automaticamente el parametro de aleatorio y palabras_significados.begin() indica  que aleatorio va a ser el primer valor del map en esta linea
    advance(aleatorio, rand() % palabras_significados.size());// la funcion advance avanza aleatorio en n posiciones, en este caso en el numero que se genere aleatoriamente, 
    return *aleatorio;
}

void eliminarPalabra(string palabra) {
    // En esta funcion cada vez que la llamemos va a eliminar un par clave valor de palabras_significados
    palabras_significados.erase(palabra);// la palabra erase es la encargada de eliminar el elemento ingresado
}

void reglasdejuego3() {
    cout << "-----------------Bienvenido al juego Adivinar la palabras-------------------" << endl;
    cout << "En este juego te vamos a dar la descripcion de los personajes y tu tienes que adivinar el personaje correcto" << endl << endl;
    cout << "Vas a tener 5 oportunidades por turno, cada respuesta correcta suma 10 puntos, y por cada incorrecta se te restan 5 puntos " << endl;

    cout << "-----------------Listo empecemos-------------------" << endl << endl;


}


void juego3Adivinarpalabra() {


    reglasdejuego3();
    //Llamamos la funcion jugador y comenzamos los contadores del jugador 1 
    string jugador1 = jugadores();
    int conta1 = 0;
    int intentos1 = 0;
    //Creamos un ciclo con la cantidad de oportunidades que tiene el jugador 
    while (intentos1 < 5) {
        pair<string, string> palabras_significado = obtenerPalabraAleatoria(); // llamamos un elemento de map alatoriamente con obtenerPalabraAleatorio
        // Pair deja amacenar dos valores en un solo objeto, y para llamarlos podemos utilizar .first para el primero y .second para el segundo
        string palabra_seleccionada = palabras_significado.first;
        string significado = palabras_significado.second;
        cout << significado << endl;//Aca mostramos el significado de la palabra a adivinar Y seguido le pedimos al usuario que ingrese la palabra 
        cout << "ingrese la palabra correcta: ";
        string palabra;
        getline(cin, palabra);

        if (palabra_seleccionada == palabra) { //Si es correcta entra a este condicional y muestra un mensaje ademas suma 10 puntos a conta1
            cout << "Su palabra es correcta sumas 10 puntos" << endl << endl;
            conta1 = conta1 + 10;
            intentos1 = intentos1 + 1;

        }
        else { //Si es incorrecta entra en ese condicional y muestra el mensaje corresponsiente y le resta 5 puntos a conta1
            cout << "la palabra es incorrecta" << endl;
            cout << "La palabra corresta es:  " << palabra_seleccionada << endl << endl;
            conta1 = conta1 - 5;
            intentos1 = intentos1 + 1;

        }

        //Llamamos la funcion eliminarpalabra para que elimine el elemeto que se utilizo y no se vuelva a repetir 
        eliminarPalabra(palabra_seleccionada);

    }

    cout << "Turno del jugador 2" << endl;//Aca hacemos absolutamente lo mismo que con el jugador 1
    string jugador2 = jugadores();
    int conta2 = 0;
    int intentos2 = 0;


    while (intentos2 < 5) {
        pair<string, string> palabras_significados = obtenerPalabraAleatoria();
        string palabra_seleccionada = palabras_significados.first;
        string significado = palabras_significados.second;

        cout << significado << endl;
        cout << "ingrese la palabra correcta: ";
        string palabra;
        getline(cin, palabra);
        if (palabra_seleccionada == palabra) {
            cout << "Su palabra es correcta sumas 10 puntos" << endl << endl;
            conta2 = conta2 + 10;
            intentos2 = intentos2 + 1;
        }
        else {
            cout << "la palabra es incorrecta" << endl;
            cout << "La palabra corresta es:  " << palabra_seleccionada << endl << endl;
            conta2 = conta2 - 5;
            intentos2 = intentos2 + 1;
        }
        eliminarPalabra(palabra_seleccionada);
    }

    if (conta1 > conta2) { //Comparamos los puntajes obtenidos por los dos jugadores y damos el mensaje correspondiente a cada caso 
        cout << "Felicidades " << jugador1 << " Fuiste el ganador con: " << conta1 << endl;
    }
    else {
        if (conta1 < conta2) {
            cout << "Felicidades " << jugador2 << " fuiste el ganador con: " << conta2 << endl;
        }
        else {
            cout << "Los jugadores " << jugador1 << " y " << jugador2 << " quedaron empatados ambos con: " << conta1 << " puntos" << endl;
        }
    }

    //preguntamos al jugador si quiere volver a jugar
    cout << "Quieres volver a jugar:(S o N)  ";
    string respuesta;
    cin >> respuesta;
    cin.ignore();// reinicia los valores y elimmina el salto de linea 
    if (respuesta == "S") { // si la respuesta es afirmativa, llena otra vez los valores del map y vuelve a iniciar el juego 
        palabras_significados = {   // map almacena valores de tipo clave valor 
        {"thor", "PrÃ­ncipe y guerrero de Asgard, dios del trueno, protector de la tierra, y de los 9 reinos."},
        {"loki", "El Dios de las Mentiras y un experto ilusionista, puede cambiar su aspecto fÃ­sico a voluntad."},
        {"ironman", "Genio, multimillonario, playboy y filantropo. AÃºn con metralla en su pecho, existe la prueba de que si tiene corazÃ³n."},
        {"spiderman", "Capaz de treparse y adherirse a las paredes y un sentido subconsciente de premoniciÃ³n de peligro. 'Un gran poder conlleva una gran responsabilidad'."},
        {"hulk", "Salvage y furioso, la mÃ¡quina de rabia verde."},
        {"thanos", "Su unico objetivo es obtener las seis Gemas del Infinito, para estabilizar la superpoblaciÃ³n del universo y evitar lo que Ã©l ve como su inevitable desapariciÃ³n."},
        {"antman", "Tiene la capacidad de reducirse a tamaÃ±o subatÃ³mico."},
        {"brujaescarlata", "Es la magia del caos y tiene el control mental. Hydra realizÃ³ experimentos con la Gema de la Mente."},
        {"vision", "NaciÃ³ como un nuevo cuerpo para UltrÃ³n, con sentidos sobre humanos gracias a la gema de la mente."},
        {"capitanamerica", "SÃ­mbolo de libertad, un supersoldado que lucha contra las potencias enemigas de la Segunda Guerra Mundial."}
        };
        juego3Adivinarpalabra();
    }
    else {
        cout << "Fin del juego";
    }


}

//juego alexa

const int fil = 10; //numero de filas
const int col = 16; //numero de columnas

bool verificar_palabra(string, char[fil][col]); // FunciÃ³n para verificar si una palabra estÃ¡ en la sopa de letras
void sopa_letras(string, char[fil][col]); // FunciÃ³n principal del juego de sopa de letras

void juegosopaletras() {
    string palabra;
    vector<string> palabras_acertadas;
    // DefiniciÃ³n de la sopa de letras
    char sopa[fil][col] = { {'a','n','t','b','y','n','e','r','d','t','h','o','r','s','y','j'},
                          {'x','w','l','o','k','i','r','t','f','t','s','y','d','t','i','y'},
                          {'a','t','h','a','n','o','s','r','d','t','n','a','m','p','n','s'},
                          {'b','r','u','j','a','e','s','c','a','r','l','a','t','a','o','g'},
                          {'e','s','t','u','d','i','r','o','n','m','a','n','l','a','n','x'},
                          {'m','l','a','o','g','i','o','i','d','t','h','e','l','a','m','m'},
                          {'v','i','s','i','o','n','s','b','d','t','u','e','l','a','a','o'},
                          {'s','p','i','d','e','r','m','a','n','t','l','e','l','a','n','s'},
                          {'v','e','a','n','t','m','a','n','d','t','k','e','l','a','d','o'},
                          {'h','e','c','a','p','i','t','a','n','a','m','e','r','i','c','a'}
    };

    // Imprimir la sopa de letras
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << sopa[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Palabra a buscar: ";

    // Leer la palabra a buscar
    do
        cin >> palabra;

    while (palabra.length() < 4);

    // Llamar a la funciÃ³n principal del juego
    sopa_letras(palabra, sopa);

}

// FunciÃ³n para verificar si una palabra estÃ¡ en la sopa de letras
bool verificar_palabra(string palabra, char letras[fil][col])
{
    string aux, vacia;
    int cont = 0;

    // Verificar horizontalmente
    for (int i = 0; i < fil; i++)// i contador para moverse entre filas 
    {
        for (int k = 0; k <= col - palabra.length(); k++)
        {
            for (int j = k; j < palabra.length() + k; j++)//j contador para sumar 
            {
                aux += letras[i][j];
            }
            if (palabra == aux)
            {
                cont++;
                return true;
            }
            aux = vacia; //aux guarda palabras y vacia resetea
        }
    }

    // Buscar palabras en la horizontal de derecha a izquierda
    for (int i = 0; i < fil; i++)
    {
        for (int k = col - 1; k >= fil - palabra.length(); k--)
        {
            for (int j = k; j > k - palabra.length(); j--)
            {
                aux += letras[j][i];
            }

            if (palabra == aux)
            {
                cont++;
                return true;
            }
            aux = vacia;
        }
    }

    // Verificar en la vertical bajando
    for (int i = 0; i < col; i++)
    {
        for (int k = 0; k <= fil - palabra.length(); k++)
        {
            for (int j = k; j < palabra.length() + k; j++)
            {
                aux += letras[j][i];
            }
            if (palabra == aux)
            {
                cont++;
                return true;
            }
            aux = vacia;
        }
    }

    // Verificar en vertical subiendo 
    for (int i = 0; i < col; i++)
    {
        for (int k = fil - 1; k >= palabra.length(); k--)
        {
            for (int j = k; j > k - palabra.length(); j--)
            {
                aux += letras[j][i];
            }
            if (palabra == aux)
            {
                cont++;
                return true;
            }
            aux = vacia;
        }
    }


    if (cont == 0)
        return false;
}

// FunciÃ³n principal del juego de sopa de letras
void sopa_letras(string palabra, char sopa[fil][col])
{
    int acertadas = 0, erradas = 0;
    char salir;
    vector<string> palabras_acertadas;

    do
    {
        if (find(palabras_acertadas.begin(), palabras_acertadas.end(), palabra) != palabras_acertadas.end())
        {
            cout << "La palabra '" << palabra << "' ya fue ingresada." << endl;
        }
        else if (verificar_palabra(palabra, sopa))
        {
            cout << "Palabra Encontrada" << endl;
            acertadas++;
            palabras_acertadas.push_back(palabra);
        }
        else
        {
            cout << "La Palabra no se encuentra en la sopa de letras" << endl;
            erradas++;
        }
        cout << "Para salir s/n: ";
        cin >> salir;

        if (acertadas == 10) // Verifica si se han acertado 10 palabras
        {
            cout << "Has acertado 10 palabras! Saliendo del juego..." << endl;
            return;
        }

        if (salir == 'n')
        {
            system("cls");
            for (int i = 0; i < fil; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cout << sopa[i][j] << " ";
                }
                cout << endl;
            }
            cout << "Acertadas: " << acertadas << " - Erradas: " << erradas << endl;
            cout << "Introduzca palabra a buscar:";

            do
                cin >> palabra;
            while (palabra.length() < 4);
        }
    } while (salir != 's');
    system("cls");
    cout << "Acertadas: " << acertadas << " - Erradas: " << erradas << endl;
    system("pause");
}


//Juego Andrea

void LimpiarPantalla();
void JugarPartida(int jugador);
void Dibujar();
pair<string, string> obtenerPalabraAleatoria2();//pair se utiliza para almacenar un par de objetos heterogÃ©neos. Es muy Ãºtil cuando se necesita almacenar dos valores relacionados juntos y mantenerlos juntos en una sola estructura.En este caso, la funciÃ³n obtenerPalabraAleatoria() devuelve un objeto pair<string, string>, que significa que retorna dos strings.

void deletreo();// FunciÃ³n principal del juego.


char eleccion;// Variable para guardar la elecciÃ³n del jugador.
map<int, int> puntos_jugadores;//El map es una estructura de datos que se utiliza para almacenar elementos en pares clave-valor, para organizar y acceder a datos de manera rÃ¡pida y eficiente.

map<string, string> palabras_significado = {// Mapa para guardar los puntos de los jugadores.
    {"thor", "PrÃ­ncipe y guerrero de Asgard, dios del trueno, protector de la tierra, y de los 9 reinos."},
    {"loki", "El Dios de las Mentiras y un experto ilusionista, puede cambiar su aspecto fÃ­sico a voluntad."},
    {"ironman", "Genio, multimillonario, playboy y filantropo. AÃºn con metralla en su pecho, existe la prueba de que si tiene corazÃ³n."},
    {"spiderman", "Capaz de treparse y adherirse a las paredes y un sentido subconsciente de premoniciÃ³n de peligro. 'Un gran poder conlleva una gran responsabilidad'."},
    {"hulk", "Salvage y furioso, la mÃ¡quina de rabia verde."},
    {"thanos", "Su unico objetivo es obtener las seis Gemas del Infinito, para estabilizar la superpoblaciÃ³n del universo y evitar lo que Ã©l ve como su inevitable desapariciÃ³n."},
    {"antman", "Tiene la capacidad de reducirse a tamaÃ±o subatÃ³mico."},
    {"brujaescarlata", "Es la magia del caos y tiene el control mental. Hydra realizÃ³ experimentos con la Gema de la Mente."},
    {"vision", "NaciÃ³ como un nuevo cuerpo para UltrÃ³n, con sentidos sobre humanos gracias a la gema de la mente."},
    {"capitanamerica", "SÃ­mbolo de libertad, un supersoldado que lucha contra las potencias enemigas de la Segunda Guerra Mundial."}
};

string palabra, fallidas;// Variables para la palabra a adivinar y las letras fallidas.
int vida;
bool correcta, completa;// Variables para indicar si la letra es correcta y si la palabra se completÃ³.


void deletreo() {
    int jugador = 1; // Comenzamos con el jugador 1.
    while (true) {// Bucle infinito para mantener el juego en ejecuciÃ³n.
        vida = 6;
        palabra = "";
        fallidas = "";//Las palabras y fallidas se asignan con comillas porque son cadenas de texto.
        LimpiarPantalla();
        cout << "\t::::MENU::::" << endl;
        cout << "1) Jugar Partida Jugador 1." << endl;
        cout << "2) Jugar Partida Jugador 2." << endl;
        cout << "Puntos Jugador 1: " << puntos_jugadores[1] << endl;//los puntos se almacenan en el map.
        cout << "Puntos Jugador 2: " << puntos_jugadores[2] << endl;
        cout << "3) Reiniciar Puntos." << endl;
        cout << "4) Salir." << endl;
        cout << "Eleccion: ";
        cin >> eleccion;
        switch (eleccion) {
        case '1':
            JugarPartida(1);
            break;
        case '2':
            JugarPartida(2);
            break;
        case '3':
            puntos_jugadores[1] = 0;
            puntos_jugadores[2] = 0;
            break;
        case '4':
            return;
        }
    }
}

void JugarPartida(int jugador) {
    srand((unsigned int)time(NULL));// srand((unsigned int)time(NULL)), se genera una semilla Ãºnica en funciÃ³n del tiempo actual, lo que permite obtener una secuencia de nÃºmeros aleatorios diferente en cada ejecuciÃ³n del programa. srand es una funciÃ³n de la librerÃ­a estÃ¡ndar que se utiliza para inicializar el generador de nÃºmeros aleatorios. La funciÃ³n time(NULL) de la librerÃ­a <ctime> devuelve el tiempo actual en segundos.

    pair<string, string> palabraAleatoria = obtenerPalabraAleatoria2();
    string palabraClave = palabraAleatoria.first;// Guardamos la palabra a adivinar.
    string significado = palabraAleatoria.second;// Guardamos el significado de la palabra

    // Inicializar la palabra a adivinar con guiones bajos
    int tamanoPalabra = palabraClave.size();//la palabra clave que se elige aleatoriamente para que el jugador adivine en el juego del ahorcado. Se obtiene el tamaÃ±o de la palabra clave utilizando la funciÃ³n size() de la variable palabraClave. Luego, se crea una cadena de caracteres llamada palabraAdivinar que tiene el mismo tamaÃ±o que la palabra clave y se inicializa con guiones bajos ('-'). Esta cadena servirÃ¡ para mostrar al jugador la palabra que estÃ¡ intentando adivinar, con guiones bajos representando las letras que aÃºn no ha adivinado.

    string palabraAdivinar(tamanoPalabra, '-');// Inicializamos la palabra a adivinar con guiones bajos.

    int puntos = (vida - fallidas.length()) * tamanoPalabra;// Calculamos los puntos de la partida.
    puntos_jugadores[jugador] += puntos;// AÃ±adimos los puntos al jugador.

    while (vida > 0) { //Mientras el jugador todavÃ­a tenga vidas disponibles para seguir intentando adivinar la palabra.
        LimpiarPantalla();
        cout << "\t::: A H O R C A D O :::" << endl;
        Dibujar();
        cout << "Fallos: " << fallidas;
        cout << "  Progreso: " << palabraAdivinar << endl;
        cout << "Deletree el nombre de este personaje en minuscula: " << endl << significado << endl;
        cout << "Ingrese una letra (minuscula): ";
        cin >> eleccion;

        correcta = false;
        for (int i = 0; i < tamanoPalabra; i++) {
            if (palabraClave[i] == eleccion) {
                palabraAdivinar[i] = eleccion;
                correcta = true;
                //se recorre cada letra de la palabra clave a adivinar. Si la letra ingresada por el jugador coincide con alguna de las letras de la palabra clave, se actualiza la letra correspondiente en la palabra a adivinar. AdemÃ¡s, se cambia el valor de correcta a true.
            }
        }

        if (!correcta) {
            vida--;
            fallidas += eleccion;
        }//si la letra no coincide con ninguna de las letras de la palabra clave, se decrementa la vida del jugador y se agrega la letra a la lista de letras fallidas.

        completa = true;
        for (int i = 0; i < tamanoPalabra; i++) {
            if (palabraAdivinar[i] == '-') {
                completa = false;
            }
        }//se verifica si la palabra a adivinar ha sido completada por el jugador. Esto se realiza recorriendo todas las letras de la palabra a adivinar y verificando si aÃºn quedan guiones bajos. Si es asÃ­, se cambia el valor de la variable completa a false, indicando que la palabra aÃºn no ha sido completada.

        if (completa) {
            LimpiarPantalla();
            cout << "\t::: A H O R C A D O :::" << endl;
            Dibujar();
            cout << "Palabra: " << palabraClave << endl;
            cout << "Jugador " << jugador << " ha ganado. Puntos: " << puntos << ". Ingresa un caracter para continuar: ";
            cin >> eleccion;
            return;
        }
    }


    LimpiarPantalla();
    cout << "\t::: A H O R C A D O :::" << endl;
    Dibujar();
    cout << "Palabra: " << palabraClave << endl;
    cout << "Jugador " << jugador << " ha perdido. Puntos: 0. Ingresa un caracter para continuar: ";
    cin >> eleccion;
    return;
}

void Dibujar() {
    switch (vida) {// Switch para mostrar el ahorcado segÃºn la vida restante del jugador.
    case 6:
        cout << " --------" << endl;
        cout << " | |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " ---" << endl;
        break;
    case 5:
        cout << " --------" << endl;
        cout << " | |" << endl;
        cout << " | O" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " ---" << endl;
        break;
    case 4:
        cout << " --------" << endl;
        cout << " | |" << endl;
        cout << " | O" << endl;
        cout << " | |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " ---" << endl;
        break;
    case 3:
        cout << " --------" << endl;
        cout << " | |" << endl;
        cout << " | O" << endl;
        cout << " |/|" << endl;
        cout << " | " << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " ---" << endl;
        break;
    case 2:
        cout << " --------" << endl;
        cout << " | |" << endl;
        cout << " | O" << endl;
        cout << " |/|\\" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " ---" << endl;
        break;
    case 1:
        cout << " --------" << endl;
        cout << " | |" << endl;
        cout << " | O" << endl;
        cout << " |/|\\" << endl;
        cout << " | /" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " ---" << endl;
        break;
    case 0:
        cout << " --------" << endl;
        cout << " | |" << endl;
        cout << " | O" << endl;
        cout << " |/|\\" << endl;
        cout << " |/ \\" << endl;
        cout << " |" << endl;
        cout << " |" << endl;
        cout << " ---" << endl;
        break;
    }
}

pair<string, string> obtenerPalabraAleatoria2() {// FunciÃ³n para obtener una palabra aleatoria.
    auto aleatorio = palabras_significado.begin();
    advance(aleatorio, rand() % palabras_significado.size());
    //  rand() se utiliza para generar un nÃºmero entero pseudoaleatorio y el % para obtener el residuo de la divisiÃ³n de un nÃºmero por otro. Esto genera un nÃºmero aleatorio entre 0 y el tamaÃ±o del contenedor llamado palabras_significado. Luego, este nÃºmero aleatorio se usa como Ã­ndice en el contenedor palabras_significado.
    pair<string, string> palabraAleatoria = *aleatorio;
    palabras_significado.erase(aleatorio); // CÃ³digo para obtener una palabra aleatoria del mapa y eliminarla.

    return palabraAleatoria;
}

void LimpiarPantalla() {
    if (system("clear") == -1) {
        cout << "Error al borrar la pantalla.";// Mostramos un mensaje de error si no se pudo limpiar la pantalla.
    }
}



int main() {
    srand(time(0)); // Inicializar la semilla para generar nÃºmeros aleatorios

    cout << "Bienvenido a la Suite de Juegos" << endl;
    cout << "Seleccione el juego que desea jugar:" << endl;
    cout << "1. Adivinar la Palabra" << endl;
    cout << "2. Sopa de Letras" << endl;
    cout << "3. Ahorcado (Deletreo)" << endl;
    cout << "4. Salir" << endl;
    int ingresejuego;
    cin >> ingresejuego;
    cin.ignore();

    switch (ingresejuego)
    {
    case  1: juego3Adivinarpalabra();
        break;
    case 2: juegosopaletras();
        break;
    case 3: deletreo();
        break;
    default: cout << "Fin del juego";
        break;
    }
}