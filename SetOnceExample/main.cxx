//#define DELETE_COPY_CONSTRUCTOR
//#define DELETE_MOVE_CONSTRUCTOR

#include <SetOnce.hxx>
#include <iostream>

typedef struct
{
	int a;
	float b;
	bool c;
	std::string d;
}test_struct_t;

using namespace set_once;

int main(void)
{
	SetOnce<int> a; //Create an instance of interger whoes value can be only set once
	std::cout << "Is the value of 'a' set : " << std::boolalpha << a.is_set() << std::endl; //Check if the value of a has been set
	a.set(66); //Set the value of a
	std::cout << "Is the value of 'a' set : " << std::boolalpha << a.is_set() << std::endl; //Check if the value of a has been set
	std::cout << std::noboolalpha;
	std::cout << "a : " << a.get() << std::endl; //Get the value of a

	SetOnce<test_struct_t> b;
	try
	{
		std::cout << "Is the value of 'b' set : " << std::boolalpha << b.is_set() << std::endl; //Check if the value of b has been set
		test_struct_t c = b.get(); //Get the value of c - Will cause an exception
	}
	catch (const DataNotSetException& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	test_struct_t d{
		100,
		3.14,
		true,
		"Hello, World!!!"
	};
	b.set(d);
	std::cout << "Is the value of 'b' set : " << std::boolalpha << b.is_set() << std::endl; //Check if the value of b has been set
	test_struct_t e = b.get(); //Get the value of d
	std::cout << "e.a : " << e.a << "\te.b : " << e.b << "\te.c : " << std::boolalpha << e.c << std::noboolalpha << "\te.d : " << e.d << std::endl;
	e.d = "Test String";
	std::cout << "e.a : " << e.a << "\te.b : " << e.b << "\te.c : " << std::boolalpha << e.c << std::noboolalpha << "\te.d : " << e.d << std::endl;
	test_struct_t f = b.get(); //Get the value of d
	std::cout << "f.a : " << f.a << "\tf.b : " << f.b << "\tf.c : " << std::boolalpha << f.c << std::noboolalpha << "\tf.d : " << f.d << std::endl;

}
