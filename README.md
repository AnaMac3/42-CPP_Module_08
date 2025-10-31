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
- Sequence Containers: `vector`, `deque`, `list`, `forward list`, `array
- Container Adaptors: `stack`, `queue`, `priority queue`
- Associative Containers: `set`, `multiset`, `map`, `multimap`
- Unordered Associated Containers: `unordered set`, `unordered multiset`, `unordered map`, `unordered multimap`.

-> EXPLICAR DIFERENCIAS ENTRE DIFERENTES TIPOS DE CONTAINERS

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


List: cada elemento es accesible por su posición en la secuencia ordenada linear. Cada elemento guarda infor sobre la uicación del elemento previo y del siguiente. 


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
