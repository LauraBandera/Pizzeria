# Pizzeria

Desarrolle un programa (pizzeria_casa.cpp) para la gestión de los pedidos realizados por los clientes de una pizzería durante un día. La estructura de datos, 
denominada Pizzeria, contiene dos campos, denominados num_pedidos y lista_pedidos. El campo num_pedidos es un número entero que representa la cantidad de pedidos 
almacenados en el campo lista_pedidos, el cual es un array de Pedido que almacena la secuencia de pedidos que se han realizado en una pizzería, con un máximo de 
0 pedidos.

Además, los datos de cada pedido se almacenan en una estructura de tipo Pedido que contiene tres campos, denominados nombre, num_ingredientes y lista_ingredientes. 
El campo nombre representa una cadena de caracteres (de tipo string) con el nombre del cliente que realiza el pedido. El campo num_ingredientes es un número entero
que contiene la cantidad de ingredientes solicitados en el pedido, que están almacenados en el campo lista_ingredientes, el cual es un array de cadenas de caracteres 
(de tipo string), que contiene un máximo de 12 de los nombres de los ingredientes de la pizza pedida.

Los ingredientes disponibles en la pizzería son (en minúsculas): "tomate", "queso", "nata", "cebolla", "pollo", "huevo", "salami", "anchoa", "bacon" y "gamba".

Se deben desarrollar los subprogramas especificados a continuación, aunque se recomienda que también se desarrollen más subprogramas auxiliares:
void inicializar_datos(Pizzeria& pz).
Inicializa la estructura de datos de la pizzería pz con la lista de pedidos vacía (num_pedidos a cero). void leer_pedido(Pedido& ped)
Lectura de los datos de un pedido desde teclado, que serán devueltos en el parámetro de salida ped. Leerá de teclado, en el orden especificado a continuación, 
el nombre del cliente y el número de ingredientes de la pizza. Si el número de ingredientes leído es erróneo, entonces se vuelve a leer de teclado el número de 
ingredientes, hasta que sea un número válido. Finalmente se leerán tantos nombres de ingredientes como especifique el número de ingredientes leído anteriormente. 
Si un determinado nombre de ingrediente no es correcto, entonces se volverá a leer dicho nombre hasta que se lea un nombre de ingrediente correcto. Nótese que sí 
es posible que haya ingredientes repetidos en el mismo pedido.
    Introduzca nombre:  Juan
    Introduzca número ingredientes:  22
    Error. Introduzca número ingredientes:  4
    Introduzca ingrediente:  tomate
    Introduzca ingrediente:  xxxxx
    Error. Introduzca ingrediente:  queso
    Introduzca ingrediente:  cebolla
    Introduzca ingrediente:  bacon
    
void insertar_pedido(Pizzeria& pz, const Pedido& ped, bool& ok)
Si no hay espacio en la lista de pedidos de la pizzería pz, entonces se devuelve false a través del parámetro ok de salida, y no se hace nada más. En otro caso, 
se inserta el pedido ped, recibido como parámetro, al final de la lista de pedidos de la pizzería pz (recibida como parámetro), incrementándose el número total de 
pedidos almacenados (num_pedidos), y se devuelve true a través del parámetro ok de salida. Nótese que sí es posible que haya varios pedidos del mismo cliente. Este 
subprograma no muestra nada en pantalla, ni lee nada de teclado.

void mostrar_pedido(const Pedido& ped)
Escribe en pantalla una línea con los datos del pedido ped que recibe como parámetro, según el formato del siguiente ejemplo (nótese que se muestra el valor del 
número de ingredientes antes que los nombres de los ingredientes).
     Juan 4 tomate queso cebolla bacon
     
void mostrar_pedidos(const Pizzeria& pz)
Escribe en pantalla el contenido de toda la estructura de datos pz, utilizando el subprograma mostrar_pedido para cada pedido de la lista de pedidos, exactamente
según el formato del siguiente ejemplo (nótese que se muestra el valor del número de pedidos antes que los datos de los pedidos):
     3
     Juan 4 tomate queso cebolla bacon
     Jose 2 nata pollo
     Julia 3 queso huevo gamba
     
int buscar_pedido(const Pizzeria& pz, const string& nombre)
Devuelve el índice en la lista de pedidos donde se encuentra almacenado el primer pedido de una persona cuyo nombre se recibe como parámetro, considerando que el 
primer pedido de la lista se encuentra en el índice 0. En caso de no encontrar ningún pedido bajo dicho nombre se devolverá el valor -1. Este subprograma no 
muestra nada en pantalla, ni lee nada de teclado.

void eliminar_pedido(Pizzeria& pz, const string& nombre, bool& ok)
Busca, en la lista de pedidos de la pizzería pz, el índice donde se encuentra el primer pedido de una persona cuyo nombre se recibe como parámetro, y si el 
pedido con ese nombre no existe, entonces se devuelve false a través del parámetro ok de salida. En otro caso, si el pedido especificado sí existe, entonces se 
elimina de la lista (los pedidos a su derecha se desplazan una posición a la izquierda para mantener el orden en la lista), se disminuye el número total de pedidos 
y se devuelve true a través del parámetro ok de salida. Este subprograma no muestra nada en pantalla, ni lee nada de teclado.

void cuenta_ingredientes(const Pizzeria& pz)
Muestra en pantalla el número de veces que cada ingrediente aparece en los pedidos de la lista de pedidos de la pizzería pz, en el orden mostrado en la lista de 
ingredientes disponibles, según el formato del siguiente ejemplo:
           tomate: 1
           queso: 2
           nata: 1
           cebolla: 1
           pollo: 1
           huevo: 1
           salami: 0
           anchoa: 0
           bacon: 1
           gamba: 1
Para realizar este subprograma, puede ser conveniente utilizar un array auxiliar de 10 números enteros (uno por cada ingrediente disponible que exista), y 
utilizarlo para contar las veces que aparece cada ingrediente en la lista de todos los pedidos de la pizzería. Para cada ingrediente de la lista de pedidos, 
se puede buscar su nombre en el array de pedidos disponibles, para así saber cual es el índice que le corresponde en el array de cuentas. Por ejemplo, al 
ingrediente "tomate" le corresponde el índice 0, al ingrediente "pollo" le corresponde el índice 4, y al ingrediente "gamba" le corresponde el índice 9.

char menu()
Muestra en pantalla un menú con las opciones necesarias para probar los subprogramas especificados anteriormente, lee la opción seleccionada por el operador, 
y la devuelve como resultado de la función.

int main()
Permite ejecutar iterativamente y de forma arbitraria, seleccionada por medio de un menú, los subprogramas especificados anteriormente. Nótese que i
nicialmente deberá invocar (antes del menú de selección) al subprograma inicializar_datos(...) para inicializar la estructura de datos de forma adecuada.
