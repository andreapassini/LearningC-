# **Learning C++**
 
> "It should have been one language"    
>
>Bjarne Btroustrup

# Basic programming concepts

### **To Compile** means:
- create the **.obj** (in Windows) file, by creating the **binary code**.

### **To Build** means:

- to **compile**
- to **link** the libraries/references used
- to create the **.exe** (in Windows) file.

### **To clean** means:

- **Delete** all the **.obj** files

### **To Rebuild** means:

- To **Clean** and then **Build**.

### **Compile Errors:**

- **Syntax** : **Error** in the **structure** of the code

- **Semantic** : **Error** in the **logical** meaning of the code

### **Compile Warnings:**

- **Something could be problematic, but it still works.**

Try not to ignore those warnings.

### **Linker Errors:**

- **Failing in finding the reference.**

### **Logical Errors:**

- **The one made by the programmers**

### **Keywords:**

- A set of words in a programming language, with a specific meaning. We cannot change the meaning of those words.
- In C++ there are 90ish KEYWORDS (int, char, return…)

### **Identifier:**

- Is a **name set by the programmer**, the name of a **function**, **struct**, **class…**

- example: std::cout

### **Operator**

- A set of signs with a meaning for each type. Their meaning can be overwritten by the programmer.  
- **+, -, \<\<(stream insertion operator), \>\>(stream extraction operator)**

### **Punctuation**

```c++ 
  { }
  ;
  ,
  .
  " "
```

All together they make the **Syntax**

### **Preprocessor and Directives - Macro**

Process the code source before the compiler.

- **Remove the comments** and sub them with a single space
- **Execute Directive**
  - **#**
  - **#include**
    - **Substitute** the 
    ```c++ 
    #include <iostream>
    ``` 
  (or other) with the **library/code** and recursively **preprocess** that **.**

**The preprocessor does not understand c++, simply follows the preprocessor directive and get the code ready for the compiler**

### **Main Function**

- **One must exist.**

- **Return** an **```int```**, 
  - **0** => **correct**, 
  - **something else** => **wrong**

![](RackMultipart20231019-1-z5pq4_html_ffdd9765912924ba.png)

```c++ 
  // applicationName.exe
  int main(){
    return 0;
  }

  // applicationName.exe argument1 argument2 
  int main(int argc, char* argv[]){   // argc counts arguments including app name
    return 0;
  }
``` 

### **ARGC: Argument count**

including the name of the application


### **ARGV: Argument vector**

including the name of the application

### **Namespaces**

Containers to group code entities in namespace scopes, allowing us to avoid name conflicts.

**```std::cout```** and **```andrea::cout```**

***```::```*** Scope Resolution Operator

we can avoid retyping every time the same namespace::identifier with **using**:

```c++ 
using namespace std; //using the entire namespace

using namespace std::cout; //using only that identifier in the namespace

using namespace std::cin;

using namespace std::endl;
```


## **I/O**

- **```std::cout << std::endl```** 
  
  goes to the **next line** and **flushes the buffer**

  - **```\n```** **just** goes to the **next line**

- **```std::cin```** 
      
    **Reads from the keyboard buffer**

    can be combined **```cin >> data1 >> data2```**  
    White spaces are ignored  
    if we have 2 cin, we can reuse the data in the buffer if is spaced, like: 
    ```c++ 
    std::cin >> a; 
    std::cin >> b;
    // By inserting in console:  "123 22"
    a = 123;
    b = 22;
    ```
    - we insert based on the **type specified**, can **throw errors**


- **```std::cerr```**
- **```std::clog```**

- **```<<```**  
  **Insertion operator**, output streams

- **```>>```**  
  **Extraction operator**, input streams

# Variables

> **The name associated with a specific Memory Address (L-Value) and the type of data (R-Value) that the variable will contain.**

![Variables and memory](Images/VariablesAndMemory.png)

## **Initializations**

**Never use a variable that is not initialized**

There are 3 types of initializations in C++

```c++

int age; // Un-initialized

int age = 21;   // .1 - C-Like initialization
int age (21);   // .2 - Constructor initialization
int age {21};   // .3 - C++ List initialization
```


## **Scope of a variable**

>The **area/region** of the code where we can **access** that specific **variable**;

- ### **Local variable** 
  - ```visible inside { }```
- ### **Global variable**   
  - ```visible``` in the ```hole program``` 
  - ```initialized at 0```;


### The compiler looks at variable like this:

- **First** in the scope which there is the variable (looks for a **```local variable```** dec)
- **Then** looks at the **```global variables```**

```c++
#include <iostream>

int age{19};

int main(){

  int age{21};
  std::cout << age << std::endl;

  return 0;
}
```


## **Primitive Data Types**

- ### **```Char```**
- ### **```Int```**
- ### **```Float/Double```**
- ### **```Boolean```**

The size and precision of these data types depend on the machine we are running the program on.  
With the preprocessor directive **```#include <climits>```** we can check that

Usual sizes and [precision](https://www.programiz.com/cpp-programming/data-types#:~:text=C%2B%2B%20int,values%20from%20%2D2147483648%20to%202147483647):

### **Char**

- **char:** 8 bits or 1 byte
- **char16\_t:** 16 bits or 2 bytes
- **char32\_t:** 32 bits
- **wchar\_t:** the largest available character set

Single quotes ' ' will make it a single character

Double quotes " " will make it a string, and give an error if saved into char.

### **Integer**

| _ **SIGNED** _ |
| --- |
| **short** | **16 bits - 2 bytes** |
| **int** | **32 bits - 4 bytes** |
| **long** | **32 bits - 4 bytes** |
| **long long** | **64 bits - 8 bytes** |

| _ **UNSIGNED** _ |
| --- |
| **unsigned short** | **16 bits - 2 bytes** |
| **unsigned int** | **32 bits - 4 bytes** |
| **unsigned long** | **32 bits - 4 bytes** |
| **unsigned long long** **64 bits - 8 bytes** |

### **Float**

| _ **FLOATs** _ |
 |
| --- | --- |
| **flaot** | **4 bytes** |
 |
| **double** | **8 bytes** |
 |
| **long double** | **12 bytes** |
 |

### **Booleans**

To store true or false

- Zero is **false**.
- Non-zero is **true**.

| **Booleans** |
| --- |
| **bool** | **1 byte** |

**Booleans**

**Sizeof()**

To check the size in bytes of a type, we can use the function sizeof(), depending on the machine and compiler we are using.

It comes from the packages **\<climits\>** (for ints) and **\<cfloat\>** (for floats)

They also give some informations about floats and ints

- INT\_MAX
- INT\_MIN
- LONG\_MIN
- LONG\_MAX
- FLT\_MIN
- FLT\_MAX

**Constants**

Variables with a constant value, they cannot change.

We have different type of constants:

- **Literal constants**
  - The value 12, always express 12
    - 12U 12 unsigned int
    - 0.5f float
    - \n or \r
- **Declared constants**
  - const keyword
    - const int a {12};
- **Constant Expressions**
  - constexpr keyword
- **Enumerated constants**
  - enum keywords
- **Defined constants**
  - #define, using preprocessor directive
  - #define pi 3.145926
  - Since the preprocessor don't know cpp, it cannot check for types

**Compound Types**

Types that are made of other types.

**Array**

A compound data type or a data structure that is a collection of elements, all elements must be of the same type.

Characteristics:

- Fix size
- Elements are all of the same type
- Stores contiguous in memory
- Can access each element by the index
  - Starting at 0
  - Ending at size-1
- No bounds check

**Declaration**

Element\_Type array\_name **[constant number of elements/size];**

**Initialization**

- int arr [3] {100, 2, 3}
- int arr [] {100, 2, 3} // Size is implicit
- **int arr [5] {0}** // Init all to zero, like a python vector operation
- **int arr [5] {}** // Init all to zero, like a python vector operation
- const int elements {5}
  - int arr [elements] {0}
- **ATTENTION**
  - **int arr [3] {100}**
    - **[0] 100**
    - **[1] 0**
    - **[2] 0**

**Memory**

The name of the array represent the address/location of the first element of the array (index 0)

The [index] represent the offset from the beginning of the array

That's why I can access it using its like a pointer and adding directly 1 to its address.

**Multidimensional arrays**

Element\_Type array\_name [dim1\_size][dim2\_size]

int movieRating [3][4];

**Vectors**

Vectors come from the **Standard Template Library** of c++.

Dynamic arrays.

**Initialization**

![](RackMultipart20231019-1-z5pq4_html_1a58be942d8a2810.png)

Already set at 0;

![](RackMultipart20231019-1-z5pq4_html_6b2419cd52b527ba.png)

First parameter is the number of elements, the second parameter is the value at which every element will be set to.

**Access element**

- **[]**

![](RackMultipart20231019-1-z5pq4_html_2c1b7e85bd821d01.png)

No boundary check

- **.at ( index )**

![](RackMultipart20231019-1-z5pq4_html_19de238e6b287c70.png)

Boundary check and throw an exception in the compiler

**Pointer**

A pointer is a variable storing as value the address of a variable/function.

Pointer has:

- Type
- Address
- Value: an address

int\* a;

int \*a;

If not initialized they point to somewhere in the memory, a junk address.

**Initialize**

int\* a{};

int\* a{nullptr};

**nullptr** (from c++ 11) represent address 0

**Address operator - &**

An operator that return the address in memory of the variable (L-value)

![](RackMultipart20231019-1-z5pq4_html_60d1c2ff7a26e970.png)

**Dereferencing**

accessing the data that the pointer is pointing to.

Get the L-value;

![](RackMultipart20231019-1-z5pq4_html_8076d9146d6f5887.png)

![](RackMultipart20231019-1-z5pq4_html_f19ae4e4c52d733c.png)

**Dynamic Memory Allocation**

Dynamically allocating memory on the heap

![](RackMultipart20231019-1-z5pq4_html_5bfdc45c11bfebfe.png)

**De-allocating the memory**

![](RackMultipart20231019-1-z5pq4_html_ea2f03201ade7e84.png)

Allocating an array with dynamic size.

![](RackMultipart20231019-1-z5pq4_html_51b4b0c50928374.png)

![](RackMultipart20231019-1-z5pq4_html_22f82a3e18bfb35c.png)

**Memory Leak**

When we lose the pointer that is pointing to the memory allocated on the heap, we have a memory leak.

**Pointer Arithmetic**

**++ and —**

![](RackMultipart20231019-1-z5pq4_html_d7a4b7365ad38d45.png)

_**+/- sizeof( type )**_

To point to the next/previous array element. Incrementing by the size of the type we are currently pointing to. If is a int\*, it will add 4 bytes to the address of memory it is currently pointing at.

**+ and -**

![](RackMultipart20231019-1-z5pq4_html_575ce1ce922ee14d.png)

increment/decrement by _**n \* sizeof( type )**_

– **between 2 pointers**![](RackMultipart20231019-1-z5pq4_html_505d3846a6f8d1f.png)

If the 2 pointer have the same type,

the subtraction will give us the number of elements between the 2.

**= or !=**

Determine if the 2 pointers are pointing at the same location or not

![](RackMultipart20231019-1-z5pq4_html_cf7e79eb48af43cb.png)

To compare the value of the data pointed to we need to dereference those pointers

![](RackMultipart20231019-1-z5pq4_html_aa9885f1b5e7f549.png)

![](RackMultipart20231019-1-z5pq4_html_588aabcfe5943fc0.png)

**Const and pointers**

- **Pointer to constant**

The data pointed by the pointer is constant and cannot be changed

The pointer can change

![](RackMultipart20231019-1-z5pq4_html_df854f351311fd10.png)

- **Constant Pointer**

The pointer itself is constant, cannot point somewhere else.

![](RackMultipart20231019-1-z5pq4_html_a5a665c72ab10b7.png)

- **Constant Pointer to Constant**

The data pointed cannot change, the pointer cannot point to something else.

![](RackMultipart20231019-1-z5pq4_html_2eb2d0d259e97cf7.png)

**DON'T RETURN, FROM A FUNCTION, A POINTER FROM A VARIABLE ALLOCATED ON THE STACK**

**Dangling Pointer**

A pointer that is pointing to a block of memory that has been released, becoming invalid.

Example: 2 pointers that point to the same address, one releases the memory and the other one is still pointing to an invalid memory.

**Not Checking if NEW failed**

If _ **new** _ fails an exception is thrown, and dereferencing a nullptr will crash the program.

**Leaking Memory**

When a pointer to a block of memory is destroyed, that memory is still considered in use but we lost the pointer and so we cannot access it.

**Reference**

Is an alias for a variable

- Cannot be null
- Must be initialized to a variable when declared
- Cannot be made to reference another variable

Can be thinked as a const pointer that automatically dereference when used.

**ATTENTION:**

**str** will be a copy of the value contained in the vector, so it is not taking its referene, meaning that it will not change ithe value of the elements in the vector.

![](RackMultipart20231019-1-z5pq4_html_70296096e9b9ffe3.png)

When using a reference it works.

![](RackMultipart20231019-1-z5pq4_html_fda22094e8e99371.png)

**L-Values**

**An object that occupies space in memory and its addressable.**

- **Addressable: can be used in the left side of and assignment state.**

![](RackMultipart20231019-1-z5pq4_html_6a5ffd10b1a43ef0.png)

**(100+20) and "Frank" are R-VALUES.**

**R-Values**

Everything that is not an L-Value is an R-Value.

They are at the right side of an assignment expression.

- Litterals
- Temporary values

![](RackMultipart20231019-1-z5pq4_html_70365ee47b16efa4.png)

max(10, 20) is also an R-Value since its return is temporary and not addressable.

- R-Values can be assigned to L-Values explicitly

**Usage**

L-values can be both on left and right side of an assignment statement, R-Values can only be on the right.

![](RackMultipart20231019-1-z5pq4_html_d8f94f6fcfe1d1bd.png)

**L-Value References**

**Referring to L-Values**

![](RackMultipart20231019-1-z5pq4_html_f83d55d1468a3b0b.png) ![](RackMultipart20231019-1-z5pq4_html_9e922bdb24fcd1ed.png)

**Pointers v References parameters**

- **Pass-by-Value**
  - Default for C++
  - The Function do not modify the actual parameter
  - Copy of the parameter.
  - Useful for simple types (int, char, double …)

- **Pass-by-reference using a POINTER**
  - Function does modify the actual parameter
  - The parameter is expensive to copy (like a big structure)
  - Is allowed a nullptr value for the pointer (nullptr like leafs in trees)

- **Pass-by-reference using a POINTER to CONST**
  - Function does NOT modify the actual parameter
  - The parameter is expensive to copy (like a big structure)
  - Is allowed a nullptr value for the pointer (nullptr like leafs in trees)
  -
- **Pass-by-reference using a POINTER to CONST**
  - Function does NOT modify the actual parameter
  - The parameter is expensive to copy (like a big structure)
  - Is allowed a nullptr value for the pointer (nullptr like leafs in trees)
  - Do NOT modify the pointer itself

- **Pass-by-reference using a REFERENCE**
  - Function does modify the actual parameter
  - The parameter is expensive to copy (like a big structure)
  - The parameter will never be nullptr

- **Pass-by-reference using a CONST REFERENCE**
  - Function does NOT modify the actual parameter
  - The parameter is expensive to copy (like a big structure)
  - The parameter will never be nullptr

# **OOP**

Model structure at an higher abstraction

- **Class**
- **Object**

**Encapsulation**

- **Abstract data-type**
- **Class/Object** contains **DATA** and **METHODS** on that data

**Information Hiding**

Hide implementation logic and provide interfaces to communicate with that code. (Private and Public)

**Reusability**

Reuse classes in more applications

**Inheritance**

Create a class in relation to another class, extending it.

Can access only its public methods.

**Class and Object**

A **class** is a user defined type, a model/blue-print. An **object** is an instance of a class.

A class can have data, **attributes,** and functions that operate on that data, called **methods.**

Thank to **encapsulation** and keywords **public** and **private** we can hide the implementation of those data and methods from the other classes, providing a public interface to interact with it.

![](RackMultipart20231019-1-z5pq4_html_61d2f6268279682d.png)

![](RackMultipart20231019-1-z5pq4_html_112b012ab6f9788f.png)

![](RackMultipart20231019-1-z5pq4_html_72723f94bc7ba896.png)

**Accessing Class Members**

**Object**

- Dot operator

**Pointer**

- (Dereference)DotOperator
- Arrow Operator (Member of pointer operator)

![](RackMultipart20231019-1-z5pq4_html_8f1574235edef85b.png)

**Class Member Access Modifiers**

- _ **public** _

Accessible everywhere

- _ **private** _

accessible only by members or friends of the class

- _ **protected** _

used with inheritance

**Implementing Member Methods**

- **Inside Class declaration**

They will become inline

![](RackMultipart20231019-1-z5pq4_html_884f8061e0f1fee5.png)

- **Outside a Class declaration**

Need to use _class\_name::method\_name_

![](RackMultipart20231019-1-z5pq4_html_13515e49bf591ba8.png)

- **Separate declaration from implementation**
  - _.h/.hpp_ **declaration**
  - _.cpp_ **implementation**

To prevent the .h file to be included more than once, we can use

- **Include Guards**

![](RackMultipart20231019-1-z5pq4_html_de984fd0da7c3caf.png)

- **Pragma Once**

Does the same job, but may be not declared in every compilers


## Constructors

A special member method:
- invoked during object creation.  
- Useful for initialization.
- Same name as the class
- No return type
- Can ve overloaded

```c++
class Player{
private:
  std::string name;
  int health;
  int xp;
public:
  // Overloaded Constructors
  Player();
  Player(std::string name);
  Player(std::string name, int health, int xp);
}
```

### Default Constructor

Called when we don't write any constructor.
- It does not require any parameters
- It does nothing, it only allocate memory with garbage values

```c++
Player frank;
Player* enemy = new Player;
```

If we write a Constructor, C++ will no longer generate it and it will be used the one you created.

```c++
class Player{
private:
  std::string name;
  int health;
  int xp;
public:
  int getHealth(){
    return this->health;
  }
  // Overloaded Constructors
  Player(){
    name = "None"
    health = 100;
    xp = 3;
  }
}

int main(){
  Player frank;
  std::cout << frank.getHealth();  // Output: 100

  return 0;
}
```

But if we create a non-default constructor and not a zero-args/default constructor, it will not be generated.

```c++
class Player{
private:
  std::string name;
  int health;
  int xp;
public:
  int getHealth(){
    return this->health;
  }
  // Overloaded Constructors
  Player(std::string n){
    this.name = n
    health = 100;
    xp = 3;
  }
}

int main(){
  Player frank; /// ERROR 

  // We have to do this
  Player frank = Player("halo")

  return 0;
}
```

### Constructor Initialization Lists

The other constructor are not really initializing the data with the value that we are passing. They allocate the memory with garbage values and the then change the values.  What we want to achieve is initializing the memory with the right values, making it more efficient and a true initialization.


We can to this with List Initializer that is just a list of initializer after the constructor declaration.

```c++
class Player{
private:
  std::string name;
  int health;
  int xp;
public:
  int getHealth(){
    return this->health;
  }

  Player(): name{"None"}, health{0}, xp{0} {
  }

  Player(std::string name_val, int health_val, int xp_val): 
      name{name_val}, health{health_val}, xp{xp_val} {
  }
}

int main(){
  Player frank;

  return 0;
}
```

The order of the member initialized is not important.

### Delegating Constructor

The goal is to reduce duplicated code.
We can **call another constructor from the initialization list**.  It works only with initialization list as in the example.

```c++
class Player{
private:
  std::string name;
  int health;
  int xp;
public:
  int getHealth(){
    return this->health;
  }

  Player(std::string name_val, int health_val, int xp_val): 
      name{name_val}, health{health_val}, xp{xp_val} {
  }

  Player(): Player{"None", 0, 0} {
  }

  Player(std::string name_val): Player{name_val, 0, 0} {
  }
}

int main(){
  Player frank;

  return 0;
}
```

## Destructors

A special member method, as a Constructor:

- Same name of class, but proceed with a tilde (~)
- Invoked automatically when the object is destroyed.
  - When the object goes out of scope
  - When we delete the pointer to an object
- No return type and no parameters
- Only 1 destructor per class is allowed
- Useful to release memory

```c++
class Player{
private:
  std::string name;
  int health;
  int xp;
public:
  // Overloaded Constructors
  Player();
  Player(std::string name);
  Player(std::string name, int health, int xp);
  
  // Destructor
  ~Player();
}
```

### Example
```c++
{
  Player slayer;
  Player frank("Frank", 100, 4);
  Player hero ("Hero");
  Player villain ("Villain");
  // Created 4 objects in the stack
  // When we go out of this scope they will be deleted
} // 4 destructors called


Player* enemy = new Player("Enemy", 1000, 0);
delete enemy; 
```

