# Introdution

## About *Gaia*

*Gaia* is a micro-services developement kit including basic functional modules, a platform and a framework.

The mainly supported language is C++, but some component of the platform maybe written in other languages, such as C# and Java.

## About *Gaia Connections*

*Gaia Connections* is a series of C++ libraries providing interprocess communication ability.

Main communication methods are TCP, UDP, and shared memory. *Gaia Connections* only provide their basic encapsulation. 

# Collaborators

Thank you for your contribution. *Gaia* is a huge and complex project which can only be developed and improved with the effort of the open-source community. The administration committee sincerely appreciate your issues and pull requests.

To make it fast, stable, and easy to use, there is still much work to do, but the committee deeply believe that step by step the goal will be achieved if we all do our part.  

## File Extension Types

*Gaia* may contained some modules desgined for embedded devices, and those modules will be written in C and no C++ feature is allowed. To distinguish the C and C++ files especially header files, file extensions are specified in the following table.

| Type | Extension |
|:----:|:---------:|
| C++ Source File | .cpp |
| C++ Header File | .hpp |
| C Source File | .c |
| C Header File | .h |
| CUDA Source File | .cu |
| CUDA Header File | .cuh |

## Naming Style

To make the source code uniformed and easy to read, please use the naming style specified in the following table.

| Type | Style |
|:-----|:-----:|
| File | BigCamel |
| Namespace | BigCamel |
| Class | BigCamel |
| Class Memeber Variable | BigCamel |
| Class Member Function | BigCamel |
| Global Function | BigCamel |
| Global Variable | BigCamel |
| Macro | BIG_SNAKE |
| Macro Functions | BIG_SNAKE or BigCamel |
| Local Variable | smallCamel_underscore_tolerant |
| Function Parameter | smallCamel_underscore_tolerant |
| Template Parameter | BigCamel

## Comment and Document

Part of the document is converted from the comments in the code. Please use *Doxygen* comment style, for example:
```C++
/**
 @brief Write the brief introdution here.
 @details Write detialed information here.
 @param parameter_name Descibe how this variable will be used
 @return Describe what will be returned
 */
 int Foo();
```

As for functions, please comment the parameters, return value,  the brief introduction, and exceptions if it will throw, and other detials to which users should pay attention to.

As for classes and structures, besides the brief introduction and detials, please comment its author's name, real name or nick name. Also, you have the right to keep anonymous, but this may cause unnecessary trouble if other developers want to contact the author of a class or structure.

## Contribute and Contact

You are welcomed to open issues and make pull requests. The administer on duty will try to contact you in e-mail if there is any problem. 

As for languages, you can contact the committee in English and Chinese, but we do recommend you write *Issues*, *Commit Comment* and *Pull Request Comment* in English. Text written in other languages will be translated with online translation tools, thus it may cause misunderstanding or other unnecessary trouble.
