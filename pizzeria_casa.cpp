#include <iostream>
#include <array>
#include <string>
using namespace std;

const int MAX_PEDIDOS = 20;
const int MAX_INGREDIENTES_PIZZA = 12;
const int NUM_INGREDIENTES = 10;

//Ingredientes posibles
  typedef array <string, NUM_INGREDIENTES> Nombres_Ingredientes;
//Declaracion de ingredientes posibles
const Nombres_Ingredientes ingre_disponibles = {{
        "tomate", "queso", "nata", "cebolla", "pollo",
        "huevo", "salami", "anchoa", "bacon", "gamba"
      }};

typedef array <string, MAX_INGREDIENTES_PIZZA> Lista_Ingredientes;

//Datos de cada pedido
struct Pedido{
  string nombre; // nombre del cliente
  int num_ingredientes; // numero entero de ingredientes solicitados
  Lista_Ingredientes lista_ingredientes; // lista que almacena los posibles ingredientes (max 12)
};

typedef array <Pedido, MAX_PEDIDOS> Lista_Pedidos;

//Gestionar pedidos realizados durante un dia.
struct Pizzeria {
  int num_pedidos; // Cantidad de pedidos almacenados en Lista_Pedidos
  Lista_Pedidos lista_pedidos; //Secuencia de pedidos realizados (max 20)
};

//Estructura pizzeria vacia
void inicializar_datos(Pizzeria& pz){
  pz.num_pedidos = 0;
  //Comprobacion
  //cout  << "Inicializados a " << pz.num_pedidos << endl;
}

/*Metodo auxiliar para comprobar si el ingrediente por pantalla
 se encuentra en la lista de posibles. */
bool posible (const string& leido, const Nombres_Ingredientes& list_ingre){
  bool esta = false;
  int i = 0;
  while (i < list_ingre.size() && !esta) {
    if (leido == list_ingre[i]) {
      esta = true;
    }
    i++;
  }
  return esta;
}

// Metodo simplificar introduccion ingredientes en leer_pedido
void introducir (Pedido& ped, string& teclado){
  do {
    cout << "Introduzca ingrediente: ";
    cin >> teclado;
    if (!posible(teclado, ingre_disponibles)) {
      cout << "Error. ";
    }
  } while(!posible(teclado, ingre_disponibles));
}

void leer_pedido (Pedido& ped){
  string posible_ingrediente;
  //Pedimos nombre cliente
  cout << "Introduzca nombre: ";
  cin >> ped.nombre;
  // Numero de ingredientes hasta que sea correcto
  do {
    cout << "Introduzca numero ingredientes: ";
    cin >> ped.num_ingredientes;
  } while(ped.num_ingredientes < 0 || ped.num_ingredientes > MAX_INGREDIENTES_PIZZA);
  //Bucle para pedir tantos ingredientes como numero anterior
  for (int i = 0; i < ped.num_ingredientes; i++) {
    introducir (ped, posible_ingrediente);
    ped.lista_ingredientes[i] = posible_ingrediente;
  }
}

void insertar_pedido (Pizzeria& pz, const Pedido& ped, bool& ok){
  ok = false;
  //No metemos mas pedidos porque alcanzamos el maximo
  if (pz.num_pedidos < MAX_PEDIDOS) {
    pz.lista_pedidos[pz.num_pedidos] = ped;
    pz.num_pedidos++;
    ok = true;
  }
}

void mostrar_pedido (const Pedido& ped){
  cout << ped.nombre << " " << ped.num_ingredientes;
  //Mostramos todos los ingredientes que tiene el pedido
  for (int j = 0; j < ped.num_ingredientes; j++) {
    cout << " " << ped.lista_ingredientes[j];
  }
  cout << endl;
}

void mostrar_pedidos (const Pizzeria& pz){
  cout << pz.num_pedidos << endl;
  for (int i = 0; i < pz.num_pedidos; i++) {
    mostrar_pedido (pz.lista_pedidos[i]);
  }
}

int buscar_pedido (const Pizzeria& pz, const string& nombre){
  int i = 0;
  bool encontrado = false; // Una vez que lo encontramos salimos del bucle
  while (i < pz.num_pedidos && !encontrado) {
    if (nombre == pz.lista_pedidos[i].nombre) {
      encontrado = true;
    }else{
      i++; //Seguimos recirriendo el array
    }
  }
  if (!encontrado) {
    i = -1;
  }
  return i;
}
void eliminar_pedido (Pizzeria& pz, const string& nombre, bool& ok){
  ok = true;
  int posicion = buscar_pedido(pz,nombre);
  if (posicion == -1) { // No se encuentra el nombre del pedido
    ok = false;
  }else{
    //Desplazamos todos los pedidos hacia la izquierda para sobreescribir el eliminado
    for (int i = posicion + 1; i < pz.num_pedidos; i++) {
      pz.lista_pedidos[i-1] = pz.lista_pedidos[i];
    }
    pz.num_pedidos--;
  }
}

//Array para siguiente subprograma.
typedef array <int, NUM_INGREDIENTES> contar_ingre;

//Metodo auxiliar inicializar array arriba.
void inicializar_array (contar_ingre& contar){
  for (int i = 0; i < NUM_INGREDIENTES; i++) {
    contar[i] = 0;
  }
}

int buscar_posicion (const string& ingre){
  int i = 0;
  bool encontrado = false;
  while (i < NUM_INGREDIENTES && !encontrado) {
    if (ingre == ingre_disponibles[i]) {
      encontrado = true;
    }else {
      i++;
    }
  }

  return i;
}

void cuenta_ingredientes (const Pizzeria& pz){
  contar_ingre contar;
  inicializar_array (contar);
  for (int i = 0; i < pz.num_pedidos; i++) {
    for (int j = 0; j < pz.lista_pedidos[i].num_ingredientes; j++) {
      //Opcion propuesta profesor
      int pos = buscar_posicion(pz.lista_pedidos[i].lista_ingredientes[j]);
      contar[pos]++;

    }
    for (int i = 0; i < NUM_INGREDIENTES; i++) {
      cout << ingre_disponibles[i] << ": " << contar[i] << endl;
    }
  }
}

char menu(){
  char res;

  cout << "A.- Leer e Insertar Pedido" << endl;
  cout << "B.- Eliminar Pedido" << endl;
  cout << "C.- Mostar Pedido" << endl;
  cout << "D.- Buscar Pedido" << endl;
  cout << "E.- Contar ingredientes" << endl;
  cout << "X.- Salir" << endl;

  do {
    cout << "Introduzca Opcion: ";
    cin >> res;
  } while ( ! (((res >= 'A') && (res <= 'E')) || (res == 'X')));

  return res;
}

int main(){

  string nom = "";
  Pizzeria pz;
  Pedido num1;
  bool introducido, encontrado;
  char opcion;
  inicializar_datos(pz);

  do {
    opcion = menu();
    switch (opcion) {
      case 'A':
      leer_pedido(num1);
      insertar_pedido (pz, num1, introducido);
      if (introducido) {
        cout << "El pedido se ha añadido correctamente." << endl;
      }else{
        cout << "El pedido no se ha podido añadir por falta de tamaño." << endl;
      }
      break;

      case 'B':
      cout << "Introduzca nombre para elimnar pedido. ";
      cin >> nom;
      eliminar_pedido(pz, nom, encontrado);
      if (encontrado) {
        cout << "El pedido se ha elimnado correctamente." << endl;
      }else{
        cout << "El nombre buscado no se encuentra en la lista de pedidos, no se ha podido elimnar." << endl;
      }
      break;

      case 'C':
      mostrar_pedidos(pz);
      break;

      case 'D':
      cout << "Introduzca nombre a buscar: ";
      cin >> nom;
      cout << "La poscion del pedido en el array es: " << buscar_pedido(pz, nom) << endl;
      break;

      case 'E':
      cuenta_ingredientes(pz);
      break;
    }
  } while(opcion != 'X');

  return 0;
}
