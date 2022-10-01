# include <iostream> //for any character output (cout)
# include "Instance.cpp"

/*
	The main function will call the initialization of the program. This will pause the main function
	until the program has run through each of its various parts, and then will return 0 to this 
	main function telling it to stop.
*/
int main()
{
	Instance i;
	i.run();
	return 0;//tells the program to end
}