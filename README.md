# SetOnce

SetOnce is a header ony library that allows you to initialize the value of an object only once.

Build enviroment must support C++11 standard.

### Features

* Ultralight (less than 100 LOC)
* Easy to use
* Headers only
* No 3rd-party dependencies
* Cross-platform (Windows, Linux, vxWorks, FreeBSD, macOS, Android)
* Thread and type safe
* Uses modern CMake; alternatively can be used wothout CMake by just adding the header file to source-code
* Only C++11 support required

### Usage

1. Import Library Header

```C++
#include <SetOnce.hxx>
#include <iostream> //Not needed by SetOnce library but is needed for std::cout [Step 3, 5, 6]
```

2. Create an object of SetOnce class.

```C++
SetOnce<int> a; //Craete an instance of SetOnce object holding integer data
```

3. Check if data has been set i.e. the data has been initialized in SetOnce object

```C++
std::cout << "Is the value of 'a' set : " << std::boolalpha << a.is_set() << std::endl; //Check if the value of a has been set
```

4. Set the value (data) to the SetOnce object

```C++
a.set(66); //Set the value of 66 to a
```

5.  Check if data has been set i.e. the data has been initialized in SetOnce object

```C++
std::cout << "Is the value of 'a' set : " << std::boolalpha << a.is_set() << std::endl; //Check if the value of a has been set
```

6. Read the value stored in the SetOnce object (return by value)

```C++
std::cout << "a : " << a.get() << std::endl; //Get the value of a
```

7. Alternatively read the value stored in the SetOnce object (return by constant reference)

```C++
const int& b = a.get_const_reference();
std::cout << "a : " << b << std::endl; //Get the value of a
```

# License

This version of SetOnce is licensed under the Apache2 license. You can freely use it in your commercial or opensource software.

# Version history

## Version 2.0.0 (20-08-2023)

Initial public release
