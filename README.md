# 42-CPP_Module_08
42 Common Core CPP Module 08
- STL
- Containers
- Algorithms
- Iterators

## Table of Contents
- [STL - Standard Template Library](#stl---standard-template-library)
- [Containers](#containers)
  - [Sequence Containers](sequence-containers)
  - [Associative Containers](associative-containers)
  - [Container Adaptors](container-adaptators)
  - [Containers used in Module 08](containers-used-in-module-08)
- [Algorithms](#algorithms)
  - [Algorithms used in Module 08](algorithms-used-in-module-08)
- [Iterators](iterators)
  - [Iterators used in Module 08](iterators-used-in-module-08)
- [More info](#more-info)

### STL - Standard Template Library
The **STL (Standard Template Library)** is part of the C++ Standard Library. It provides a collection of template-based classes and functions that implement common data structures and algorithms.  
Main componentes of the STL:
- **Containers**: classes that store and orgaize data(`vector`, `list`, `map`, `set`, etc.)
- **Algorithms**: generic functions that operate on ranges (`sort`, `find`, `count`, `copy`, etc.)
- **Iterators**: generalized pointers used to traverse the elements in containers and apply algorithms.

### Containers
Containers are **template classes** that store collections of objects. They provide methods for basic operations such as insertion, deletion, and accesing elements.  
In C++98, containers are divided into three main categories (unordered containers were added later in C++11):
#### Sequence Containers
Sequence containers implement data structures which can be accessed sequentially, in **linear order**.

| Container | Description |
|-----------|------------|
| `vector` | Dynamic array that can resize itself. Provides fast random access and efficient inserttion/removal at the end. |
| `deque` | Double-ended queue allowing fast insertion and deletion at both ends. |
| `list` | Doubly-linked list. Efficient insertion and removal anywhere, but no random access. |

Note: the `array` container was introduced in C++11.

#### Associative Containers
Associative containers store in a **sorted structure**, typically implemented as balance binary trees.  
They allow fast lookup, insertion, and removal with logarithmic complexity (`O(log n))`).

| Container | Description |
|-----------|------------|
| `set` | Collection of unique keys, sorted by keys. |
| `multiset` | Collection of keys, sorted by keys (duplicates allowed). |
| `map` | Collection of key-value pairs, sorted by keys. Keys are unique. |
| `multimap` | Collecton of key-vaklue pairs, sorted by keys (duplicates allowed). |

#### Container Adaptors
Container adaptors provide a simplified interface built on top of existing sequence containers.

| Adaptor | Description |
|-----------|------------|
| `stack` | Adapts a container to provide **LIFO** (Last In, First Out) behaviour.|
| `queue` | Adapts a container to provide **FIFO** (First In, First Out) behaviour.|
| `priority_queue` | Adapts a container to provide priority-based access to elements. |

⚠️ For detailed information on each container, visit [cppreference.com - Containers](https://en.cppreference.com/w/cpp/container.html)

### Containers used in Module 08
#### [`std::vector`](https://en.cppreference.com/w/cpp/container/vector.html)
**`std::vector `** is a **sequence container** that stores elements in **contiguous memory**, providing dynamic array functionality. 
  Characteristics:
  - Fully **contigous memory**
  - **Fast random access** (`operator[]`)
  - **Dinamic resizing**: you can pre-allocate with `reserve()` and it automatically grows when needed.
  - **Efficient insertions** at the end (`push_back()`)
  - **Iteration stability**: iterators remain valid unless the vector beyond capacity or elements are erased/moved
  - Works very well with algorithms from `<algorithm>`

Used in **ex00 (Span)** to store integers.  
Why `vector` is suitable for *Span*:
- Allows pre-allocation with `reserve()`.
- Allows element insertion via `push_back()`and `insert()`
- It provides `size()` for tracking the number of stored elements
- Supports random access via `operator[]`
- It works well with <algorithm> functions, such as `sort`, `min_element` and `max_element`.

#### [`std::stack`](https://en.cppreference.com/w/cpp/container/stack.html)
`std::stack` is a **container adaptor** that gives the programmer the functionality of a stack - **LIFO (last-in, first-out)** data structure -.  
Used in **ex02 (MutantStack)** to build a stack with iterator support.  
- `std::stack` **does not expose iterators**.
- However, the underlying container (accesible as the protected member `c`) is typically a `std::deque<T>`, which does provide iterators. 
- To expose the iterators of the underlying countainer, MutantStack inhertis from `std::stack` and uses:

    typedef typename std::stack<T>::container_type::iterator iterator

Explanation:  
- `std::stack<T>container_type` is the protected type alias refering to the internal container (`std::deque<T>`).
- `::iterator` gives access to that container's iterator type
- MutantStack exposes these iterators through public `begin()` and `end()` methods

### Algorithms
STL algorithms are defined mainly in `<algorithm>`and `<numeric>`. They operate on **iterator ranges** (`[first, last]`), not containers, which is what makes them generic.  
Common algorithms include:
- `sort`: sorts a range
- `find`: searches for a value
- `count`: counts occurences
- `reverse`: reverses a range
- `accumulate`: computes the sum of a range
- `unique`: removes consecutive duplicates
- `lower_bound`: finds the first element >= a given value in a sorted range
- `upper_bound`: finds the first element > a given value in a sorted range
- `replace`: replaces all occurences of a value

#### Algorithms used in Module 08

| Algorithm | Declaration | Parameters | Description |
|-----------|-------------|-------------|-------------|
| [`std::find`](https://en.cppreference.com/w/cpp/algorithm/find.html) | `InputIt find( InputIt first, InputIt last, const T& value )`| `first`, `last`: the pair of iterators defining the range of elements to examine. `value`: value to comare the elements to. | Returns an iterator to the first element equal to `value` in the range [first, last]`, or `last` if no match is found. |
| [`std::sort`](https://en.cppreference.com/w/cpp/algorithm/sort.html) | `void sort( RandomIt first, RandomIt last )`| `first`, `last`: the pair of iterators defining the range of elements to sort.| Sorts the elements in the range [first, last] in non-descending order. The order of equal elements is not guaranteed to be preserved.|
| [`std::max_element`](https://en.cppreference.com/w/cpp/algorithm/max_element.html) | `Forward It max_element( ForwardIt first, ForwardIt last)`| `first`, `last`: the pair of iterators defining the range of elements to examine. | Returns an iterator to the largest element in the range `[first, last]`, or `last if the range is empty. |
| [`std::min_element`](https://en.cppreference.com/w/cpp/algorithm/min_element.html) | `Forward It min_element( ForwardIt first, ForwardIt last)`| `first`, `last`: the pair of iterators defining the range of elements to examine. | Returns an iterator to the smallest element, or `last` if the range is empty. |

### Iterators
Iterators act similarly to pointers. They "point" to elements in STL containers and can be used to traverse, access, and modify container contents.  
Iterator types depend on the container (e.g., vectors use random-access iterators, lists use bidirectional iterators, etc).  
Defined primarly in `<iterator>`.

#### Some iterator-related functions
| Function/iterator | Declaration | Parameters | Description |
|-----------|-------------|-------------|-------------|
| [`std::distance`](https://en.cppreference.com/w/cpp/iterator/distance.html) | `typename std::iterator_traits<InputIt>::difference_type distance( InputIt first, InputIt last )`| `first`, `last`: the pair of iterators defining the range of elements to examine. | Returns how many increments are needed to go from `first` to `last`. Effectively, the number of elements in the range. |
| [`begin`](https://en.cppreference.com/w/cpp/container/vector/begin.html) | `iterator begin()`, `const_iterator begin()`| - | Returns an iterator to the first element of `*this`|
| [`end`](https://en.cppreference.com/w/cpp/container/vector/end.html) | `iterator end()`, `const_iterator end()`| - | Returns an iterator past the last element of`*this` (one-past-the-end) |


## More info
[STL - geeksforgeeks](https://www.geeksforgeeks.org/cpp/the-c-standard-template-library-stl/)  
[Containers Library - cppreference](https://en.cppreference.com/w/cpp/container.html)  
[Interator - cppreference](https://en.cppreference.com/w/cpp/iterator/iterator.html)  
[cplusplus - Standard C++ Library reference](https://cplusplus.com/reference/#google_vignette)  
