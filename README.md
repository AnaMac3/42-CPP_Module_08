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
- **Sequence Containers**: implement data structures which can be accessed sequentially

| Container | Description |
|-----------|------------|
| `array` | fixed-sized inplace contiguous array -> HAY ARRAY EN C++98?? |
| `vector` | resizable contiguous array |
| `deque` | double-ended queue |
| `list` | doubly-linked list |

- **Associative Containers**: implement sorted data structures that can be quickly searched (O(log n) complexity)

| Container | Description |
|-----------|------------|
| `set` | collection of unique keys, sorted by keys |
| `multiset` | collection of keys, sorted by keys |
| `map` | collection of key-value pairs, sorted by keys, keys are unique |
| `multimap` | collecton of key-vaklye pairs, sorted by keys |

- **Container Adaptors**: provide a different interface for sequential containers 

| Container | Description |
|-----------|------------|
| `stack` | adapts a container to provide stack (LIFO data structure)|
| `queue` | adapts a container to provide queue (FIFO data structure)|
| `priority queue` | adapts a container to provide a priority queue |

- **Unordered Associated Containers**: implement unsorted (hashed) data structures that can be quickly searched ...???
 `unordered set`, `unordered multiset`, `unordered map`, `unordered multimap`. Son de C++11, creo, no tocan en C++98??

-> EXPLICAR DIFERENCIAS ENTRE DIFERENTES TIPOS DE CONTAINERS
#### Vectors
- dinamic size array
- los elementos se almacenan de manera contigua -> los elementos se pueden acceder no solo a partir de iteradores, sino tb mediante offsets a punteros regulares a elementos
- se puede usar la función reserve() para eliminar realocaciones en el número de elemento

- reserve: increase the capacity of the vector (the total number of elements that the vector can hold wthout requiring reallocation). no crea elementos. No impone un límite de tamaño. Solo sirve para evitar realocaciones innecesarias cuando ya sabes cuántos elementos vas a tener. es más por eficiencia que por otra cosa.
- size(): en vector: devuelve el numero de elementos actuales

#### Lists
- Cada elemento es accesible por su posición en la secuencia ordenada linear.
- Cada elemento guarda infor sobre la ubicación del elemento previo y del siguiente.
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


Vector:

      std::vector myVector; //crear un vector
      myVector.push_back(3); //adds an element to the end
      myVector.pop_back(); //removes the last element
      myVector.insert(0, 2); //inserta en pos 0 el elemento 2

      int arr[] = {10, 20, 30};
      myVector.insert(my.Vector.end(), //insertion pos (at the end)
                      arr, //begining of the range
                      arr + sizeof(arra) / sizeof(int)); //end of the range (not included)

#### Stack
`std::stack` class is a **container adaptor** that gives the programmer the functionality of a stack - LIFO (last-in, first-out) data structure.  
**Nota para el ex02**: std::stack normalmente usa de std::deque<T> internamente. Los iteradores de stack no son accesibles directamente, pero el contenedor subyacente, que se llama c (protected en std::stack), sí los tiene. 
https://en.cppreference.com/w/cpp/container/stack.html  
**Member types de Stack:**
- container_type: container
- value_type: container::value_type
- size_type: container::size_type
- reference: container::reference
- const_reference: container::const_reference

**Member objects de Stack:**
- c: the underlying container

**Member functions de Stack:**
- top: accesses the top element
- empty: checks whether the contaienr adaptor is empty
- size: returns the number of elements
- push: inserts element at the top
- push_range: inserts a range of elements at the top
- emplace: constructs element in-place at the top
- pop: removes the top element
- swap: swaps the contents

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
- Los diferentes containers tienen diferentes tipos de iteradores
- funciones relacionadas con iteradores?
  - std::distance


## More info
[STL - geeksforgeeks](https://www.geeksforgeeks.org/cpp/the-c-standard-template-library-stl/)  
[Containers Library - cppreference](https://en.cppreference.com/w/cpp/container.html)  
[Interator - cppreference](https://en.cppreference.com/w/cpp/iterator/iterator.html)  
[cplusplus - Standard C++ Library reference](https://cplusplus.com/reference/#google_vignette)  
