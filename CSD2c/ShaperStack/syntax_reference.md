# Syntax Reference <br>

<!--
Made on 20-2-25 by Fabean
recommended to use with Obsidian: https://obsidian.md/
-->

<!--
TODO:
- Group syntax categories
- Add tags openfor obsidian searching
-->

- Public and Private
  All the class members declared under public will be available to everyone. The data members and member functions declared public can be accessed by other classes too. The public members of a class can be accessed from anywhere in the program using the direct member access operator (.) [Link](https://www.geeksforgeeks.org/cpp/difference-between-public-and-private-in-c-with-example/) <br>

- Environment variables
  Environment variables are globally accessible named values that store information about the system environment where your code is executed. They are also used to store configuration settings, paths to important directories, and other system-specific data as well. In this article, we will learn how to get environment variables in C++. [Link](https://www.geeksforgeeks.org/cpp/how-to-get-environment-variable-in-c/) <br>

- Inheritance in C++
  [Link](https://www.geeksforgeeks.org/cpp/inheritance-in-c/) <br>

- Parameter passing techniques
  (over mutable variables enzo) [Link](https://www.geeksforgeeks.org/cpp/parameter-passing-techniques-in-cpp/) <br>

- Include Guards
  [Link](https://medium.com/@tomsvoj/implementing-member-methods-in-c-classes-9eb4fb1a258f) <br>

- 'This->' pointer
  [Link](https://www.geeksforgeeks.org/cpp/this-pointer-in-c/) <br>

- Nullptr (nullptr, NULL or 0)
  [Link](https://cppscripts.com/cpp-null-vs-nullptr) <br>

- Initialization list
  [Link](https://www.tutorialspoint.com/cplusplus/cpp_constructor_initialization_list.html) <br>

- Constructor delegation
  Dit kan gebruikt worden voor constructor overloading wanneer de tweede constructor dezelfde code heeft als de eerste maar nu met meer dingen erbij.
  Het kan ook wanneer je een derived class hebt en daar code aan wilt toevoegen uit de superclass. dit heet constructor delegation in inheritance. [Link](https://www.geeksforgeeks.org/cpp/constructor-delegation-c/) <br>

- iostream cin object
  [Link](https://www.w3schools.com/cpp/ref_iostream_cin.asp) <br>

- if else ternery operator
  [Link](https://www.w3schools.com/cpp/cpp_conditions_shorthand.asp) <br>

- Comparing strings in c++
  [Link](https://www.geeksforgeeks.org/cpp/stdstringcompare-in-c/) <br>

- Switch Case in c++
  0 if the same, 1 if not the same [Link](https://www.geeksforgeeks.org/cpp/switch-statement-in-cpp/) <br>

- Exceptions
  (equivalent of try except in python)  [Link](https://www.w3schools.com/cpp/cpp_exceptions.asp) <br>

- Input validation
  [Link](https://www.w3schools.com/cpp/cpp_input_validation.asp) <br>

- cin methods (cin.ignore is useful for input validation)
  [Link](https://www.w3schools.com/cpp/ref_iostream_cin.asp) <br>

- getline function (is different from cin.getline!)
  [Link](https://www.geeksforgeeks.org/cpp/getline-string-c/) <br>

- Functions in c++
  [Link](https://www.geeksforgeeks.org/cpp/functions-in-cpp/) <br>

- Get the length of a string
  [Link](https://www.geeksforgeeks.org/cpp/5-different-methods-to-find-length-of-a-string-in-cpp/) <br>

- Object delegation
  [Link](https://www.geeksforgeeks.org/cpp/object-delegation-in-cpp/) <br>

- What is const
  Runs code in compile time -> makes things read-only. It's possible to copy and edit const values by using 'unconst' or something. can't remember. [Link](https://www.geeksforgeeks.org/cpp/const-keyword-in-cpp/) <br>

- Destructor
  A destructor is a *special member function* of a class that is executed automatically whenever an object of its class goes out of scope or whenever the delete expression is applied to a pointer to the object of that class.

  Dus een *functie* in een class die uitgevoerd wordt wanneer het object *'out of scope'* gaat of wanneer het object wordt verwijdert met *'delete'*.
  Een tilde ~ betekent dat iets een destructor is

  Eigenschappen van een destructor:
	  - Destructors are automatically called when an object goes out of scope.
	  - Destructor has the same name as the class and is denoted using tilde(~)   sign.
	  - It is automatically created when a class is created.
	  - Destructors do not have any return type and do not accept any parameters/ arguments.
	  - You can't define more than one destructor
	  - Destructors cannot be inherited.
	  - Destructors cannot be overloaded.
- New and Delete operators in c++
  [Link](https://www.geeksforgeeks.org/cpp/new-and-delete-operators-in-cpp-for-dynamic-memory/) <br>

- Scope resolution indicator '::'
  [Link](https://www.tutorialspoint.com/cplusplus/cpp_scope_resolution_operator.htm) <br>

- Namespace
  A namespace is used to differentiate similar functions, classes, variables, etc., with the same name available in different libraries. To access members which are defined inside a namespace, we use the scope resolution operator '::'. [Link](https://www.tutorialspoint.com/cplusplus/cpp_scope_resolution_operator.htm) <br>

- Conditional processing blocks aka Macros
  **ifdef** identifier is essentially equivalent to **if** defined identifier.
  **ifndef** identifier is essentially equivalent to **if** !defined identifier.
  **elifdef** identifier is essentially equivalent to **elif** defined identifier.
  **elifndef** identifier is essentially equivalent to **elif** !defined identifier. (since C++23) [Link](https://en.cppreference.com/w/cpp/preprocessor/conditional)<br>

- polymorphism
  [Link](https://www.geeksforgeeks.org/cpp/cpp-polymorphism/) <br>

- Type-inference (auto)
  auto is a non-specific type, if it is a float array, auto will turn into a float, if it's an int auto will turn into an int etc. [Link](https://www.geeksforgeeks.org/cpp/type-inference-in-c-auto-and-decltype/) <br>

- Difference between signed int and unsigned int
  [Link](https://  www.geeksforgeeks.org/c/difference-between-unsigned-int-and-signed-int-in-c/) <br>

- Struct
  struct is just a class without public and private [Link](https://www.w3schools.com/cpp/cpp_structs.asp) <br>

- Templates
  Templates let you write a function or class that works with different data types, kinda cool. Might be useful with input validation? It is convention to use T as a placeholder for a data type. [Link](https://www.w3schools.com/cpp/cpp_templates.asp) <br>

- constexpr
  - This is a feature added in C++ 11. The main idea is a performance improvement of programs by doing computations at compile time rather than run time.
  - Constexpr specifies that the value of an object or function can be evaluated at compile-time and the expression can be used in other constant expressions. [Link1](https://www.geeksforgeeks.org/cpp/understanding-constexper-specifier-in-cpp/) [Link2](https://www.geeksforgeeks.org/cpp/understanding-constexper-specifier-in-cpp/) <br>

- template metaprogramming
  Vgm is de basis een beetje dat je de compiler allemaal dingen laat uitrekenen zodat het geen recourses meer kost tijdens run-time! cool [Link](https://www.geeksforgeeks.org/cpp/template-metaprogramming-in-c/) <br>

- Lexical cast (typecasting)
  [Link](https://www.geeksforgeeks.org/cpp/boost-lexical_cast-in-cpp/) <br>

- Converting variable type (string to char)
  [Link](https://www.geeksforgeeks.org/cpp/how-to-convert-std-string-to-char-in-cpp/) <br>

- Const to non-const (const_cast)
  [Link](https://www.geeksforgeeks.org/cpp/const_cast-in-c-type-casting-operators/) <br>

- Explicit Keyword
  [Link](https://www.geeksforgeeks.org/cpp/use-of-explicit-keyword-in-cpp/) <br>

- Inheritance, Composition, Aggregation
  [Link](https://dev.to/adhirajk/inheritance-vs-composition-vs-aggregation-432i) <br>

- Colors in terminal
  [Link](https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c#4053879) <br>

- String concatenation
  [Link](https://www.geeksforgeeks.org/computer-science-fundamentals/concatenation-of-two-strings/) <br>

- Pointer Arithmatic
  [Link](https://www.geeksforgeeks.org/cpp/cpp-pointer-arithmetic/) <br>

- Pointer Address to string
  [Link](https://stackoverflow.com/questions/7850125/convert-this-pointer-to-string#7850160) <br>

- Removing certain characters from a string
  [Link](https://stackoverflow.com/questions/5891610/how-to-remove-certain-characters-from-a-string-in-c#5891643) <br>

- Reinterpret_cast
  again typecasting but cool because it converts pointer while not caring about Type [Link](https://www.geeksforgeeks.org/cpp/reinterpret_cast-in-c-type-casting-operators/) <br>

- Convert/cast string to char array
  A constant char array is good enough for you so you go with, const char *array = tmp.c_str(); Or you need to modify the char array so constant is not ok, then just go with this char *array = &tmp[0];

  Both of them are just assignment operations and most of the time that is just what you need, if you really need a new copy then follow other fellows answers. [Link](https://stackoverflow.com/questions/13294067/how-to-convert-string-to-char-array-in-c#13294114) <br>

- Convert/cast string (actually char array) to long int
- String length .length()
  [Link](https://www.w3schools.com/cpp/cpp_strings_length.asp) <br>

- Vector erase()
  Delete elements from a vector with iterators [Link](https://www.geeksforgeeks.org/cpp/vector-erase-in-cpp-stl/) <br>

- Vector find()
  [Link](https://www.geeksforgeeks.org/cpp/std-find-in-cpp/) <br>

- Vector begin() 'end is kinda the same'
  [Link](https://www.geeksforgeeks.org/cpp/vector-begin-in-cpp-stl/) <br>

- Vector remove()
  [Link](https://www.geeksforgeeks.org/cpp/std-remove-algorithm-in-cpp/) <br>

- Template non-type arguments
  [Link](https://www.geeksforgeeks.org/cpp/template-non-type-arguments-in-c/) <br>

- Stringstream \<sstream>
  [Link](https://www.geeksforgeeks.org/cpp/stringstream-c-applications/) <br>

- Typedef
  [Link](https://www.geeksforgeeks.org/cpp/typedef-in-cpp/) <br>

- Factory Method "virtual constructors (but not really)"
  [Link](https://www.geeksforgeeks.org/cpp/advanced-c-virtual-constructor/#the-factory-method-best) <br>

- Tuple (tuples)
  [Link](https://www.geeksforgeeks.org/cpp/tuples-in-c/) <br>

- Smart-pointers (unique_ptr shared_ptr weak_ptr)
  [Link](https://www.geeksforgeeks.org/cpp/smart-pointers-cpp/) <br>

- iterator
  [Link](https://www.geeksforgeeks.org/cpp/introduction-iterators-c/) <br>

- .h vs .hpp file extention
  Both work for c++, hpp doesn't work in c coding language. People writing code for c++ inside .h files can be ambiguous because it's not clear if the code inside the header is meant for c++ or c. [Link](https://blog.fileformat.com/programming/h-vs-hpp/) <br>

- clear console
  [Link](https://www.geeksforgeeks.org/cpp/how-to-clear-console-in-cpp/)<br>

- Multithreading
  [Link](https://www.geeksforgeeks.org/cpp/multithreading-in-cpp/)<br>

- Malloc and free
  'malloc' (memory allocate) and 'free()' (free memory) are alternatives for new and delete. New calls the constructor. malloc only allocates the memory. Also, new will throw on failure while malloc returns Null. new is an operator and malloc() is a function.
  [Link](https://www.geeksforgeeks.org/cpp/cpp-malloc/)<br>

- Observer design pattern
  Met 'Observer Pattern' wordt een type design bedoelt waarbij:
  1. Een ==subject== die de 'main data' bevat
  2. Meerdere ==observers== op de hoogte gesteld worden wanneer deze data verandert
  [Link](https://www.geeksforgeeks.org/system-design/observer-pattern-c-design-patterns/)<br>

- Inline keyword or 'inlining'
  [Link](https://www.geeksforgeeks.org/cpp/inline-functions-cpp/)<br>
