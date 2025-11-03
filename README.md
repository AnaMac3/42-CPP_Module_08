# 42-CPP_Module_08
42 Common Core CPP Module 08

- Containers

## Table of Contents
- [STL - Standard Template Library](#stl---standard-template-library)
- [Containers](#containers)
- [Algorithms](#algorithms)
- [More things](#more-things)
- [More info](#more-info)

### STL - Standard Template Library

La STL es una parte de la biblioteca estándar de C++ que incluye principalmente estructuras y algoritmos genéricos basados en plantillas.   
Componentes principales de la STL:
- **Contenedores**: que contienen y organizan datos: `vector`, `list`, `map`, `set`....
- **Algoritmos**: llevan a cabo acciones como ordenar o buscar datos: `sort`, `find`, `count`, `copy`...
- **Iteradores**: ayudan a moverse a través de los datos en los contenedores.

### Containers

Los contenedores son estructuras de datos que se utilizan para almacenar objetos y datos. Cada contenedor se implementa como una template class que a su vez puede contener métodos para realizar operaciones básicas en él. Todos los contenedores STL se definen dentro de su propio archivo header.  
4 tipos de contenedores:
- Sequence Containers: `vector`, `deque`, `list`, `forward list`, `array`
- Container Adaptors: `stack`, `queue`, `priority queue`
- Associative Containers: `set`, `multiset`, `map`, `multimap`
- Unordered Associated Containers: `unordered set`, `unordered multiset`, `unordered map`, `unordered multimap`.

-> EXPLICAR DIFERENCIAS ENTRE DIFERENTES TIPOS DE CONTAINERS
#### Vectors

#### Lists
- Cada elemento es accesible por su posición en la secuencia ordenada linear.
- Cada elemento guarda infor sobre la uicación del elemento previo y del siguiente.
- They are very similar to forward_list: The main difference being that forward_list objects are single-linked lists, and thus they can only be iterated forwards, in exchange for being somewhat smaller and more efficient.
- Compared to other base standard sequence containers, lists perform better in inserting, extracting and moving elements


#### Forward list


#### Deque
- double-ended queue
- contenedores secuenciales con tamaños dinámicos que se pueden expandir o contraer desde sus dos extremos (front y back).
- no garantiza que todos los elementos estén almacenados en direcciones de memoria contiguas, por lo que no se puede acceder a los elementos moviendo un puntero de sitio.
- Both vectors and deques provide a very similar interface and can be used for similar purposes, but internally both work in quite different ways: While vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage, with the container keeping the necessary information internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators). Therefore, deques are a little more complex internally than vectors, but this allows them to grow more efficiently under certain circumstances, especially with very long sequences, where reallocations become more expensive. NO ENTIENDO

#### Array
- Fixed-size sequence containers
- Orden en estricta secuencia linear
- contiguos storage: los elementos están almacenados en ubicaciones de memoria contiguas. Un puntero a un elemento puede utilizarse para acceder al resto de elementos.
- tiene el operador[]
- alocación de memoria estática. El tamaño del array es una constante en tiempo de compilación. No cambia de tamaño, entiendo.




-> muchos de estos containers tienen funciones miembro compartidos, como:
- begin: iterador que devuelve un iterador al principio del container (primer elemento)
- end: devuelve un interador al final del container (pasado el último elemento)
- front: referencia al primer elemento
- back: referencia al último elemento
- operator[]:
- ...

Vector:

      std::vector myVector; //crear un vector
      myVector.push_back(3); //adds an element to the end
      myVector.pop_back(); //removes the last element
      myVector.insert(0, 2); //inserta en pos 0 el elemento 2

      int arr[] = {10, 20, 30};
      myVector.insert(my.Vector.end(), //insertion pos (at the end)
                      arr, //begining of the range
                      arr + sizeof(arra) / sizeof(int)); //end of the range (not included)


### Algorithms
Los algoritmos STL ofrecen funciones para realizar operaciones comunes en datos, normalmente en contenedores. Todos los algoritmso STL están definidos en los headers `<algoritm>` y `<numeric>`. Algunos de los algoritmos más frecuentes, son:
- `sort`: ordena elementos en orden ascendente (por defecto)
- `binary search`: comprueba si un valor existe en un rango ordenado
- `find`: buscar la primera ocurrencia de un valor dado
- `count`: cuenta cuántas veces aparece un valor en un rango dado
- `reverse`: revierte el orden de los elementos de un rango dado
- `accumulate`: computa la suma de todos los elementos en un rango
- `unique`: borra elementos duplicados consecutivos
- `lower bound`: devuelve el iterador al primer elemento > o = valor en un rango ordenado
- `upper bound`: devuelve el iterador al primer elemento mayor que el valor en un rango ordenado
- `replace`: reemplaza todas las ocurrencias de un valor con nuevo valor en un rango dado.

| Algorithm | Declaration (?) | Parameters | Description |
|-----------|-------------|-------------|
| `std::find` | `InputIt find( InputIt first, InputIt last, const T& value )`| `first`, `last`: the pair of iterators defining the range of elements to examine. `value`: value to comare the elements to. | Devuelve un iterator al primer elemento en el rango [first, last] que coindica con value, o last si no hay concidencias. |

### Iterators
Los iteradores son los punteros que se usan para apuntar a las direcciones de memoria de los containers STL. Se encuentran en el header <iterator>.   



## More info
[STL - geeksforgeeks](#https://www.geeksforgeeks.org/cpp/the-c-standard-template-library-stl/)  
[Containers Library - cppreference](#https://en.cppreference.com/w/cpp/container.html)  
[Interator - cppreference](#https://en.cppreference.com/w/cpp/iterator/iterator.html)  
[cplusplus - Standard C++ Library reference](#https://cplusplus.com/reference/#google_vignette)  
