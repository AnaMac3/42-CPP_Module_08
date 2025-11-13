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
The **STL (Standard Template Library)** is part of the C++ Standard Library. It provides a collection of template-based classes and functions that implement common data structures and algorithms.  
Main componentes of the STL:
- **Containers**: store and orgaize data(`vector`, `list`, `map`, `set`, etc.)
- **Algorithms**: perform opertaions such as sorting, searching, counting, copying, etc. (`sort`, `find`, `count`, `copy`, etc.)
- **Iterators**: provide a way to traverse the elements in containers.

### Containers
Containers are data structures designed to store collections of objects.  
Each container is implemented as a template class that provides methods for basic operations such as insertion, deletion, and traversal.  
All STL containers are defined in their respective header files.  
In C++98, containers are divided into three main categories (unordered containers were added later in C++11):
#### 1. Sequence Containers
Sequence containers implement data structures which can be accessed sequentially

| Container | Description |
|-----------|------------|
| `vector` | Dynamic array that can resize itself. Provides fast random access and efficient inserttion/removal at the end. |
| `deque` | Double-ended queue allowing fast insertion and deletion at both ends. |
| `list` | Doubly-linked list. Efficient insertion and removal anywhere, but no random access. |

Note: the `array` container was introduced in C++11.

#### 2. Associative Containers
Associative containers store in a **sorted** structure, typically implemented as bañance binary trees.  
They allow fast lookup, insertion, and removal with logarithmic complexity (`O(log n))`).

| Container | Description |
|-----------|------------|
| `set` | Collection of unique keys, sorted by keys. |
| `multiset` | Collection of keys, sorted by keys (duplicates allowed). |
| `map` | Collection of key-value pairs, sorted by keys. Keys are unique. |
| `multimap` | Collecton of key-vaklue pairs, sorted by keys (duplicates allowed). |

#### 3. Container Adaptors
Container adaptors provide a simplified interficebuilt on top of existing sequence containers.

| Adaptor | Description |
|-----------|------------|
| `stack` | Adapts a container to provide **LIFO** (Last In, First Out) behaviour.|
| `queue` | Adapts a container to provide **FIFO** (First In, First Out) behaviour.|
| `priority_queue` | Adapts a container to provide priority-based access to elements. |

⚠️ For detailed information on each container, visit [cppreference.com - Containers](https://en.cppreference.com/w/cpp/container.html)



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
