#include <iostream>

template<class T1, class T2>
struct xPair
{
	xPair(){}
	xPair(T1 first_, T2 second_) : first(first_), second(second_)
	{

	}

	//factory mehtod.
	static xPair Make_xPair(T1 local_first, T2 local_second)
	{
		//xPair temp_pair(local_first,local_second );
		return xPair(local_first, local_second);
	}

T1 first;
T2 second;
};

int main()
{
    auto x_pair = xPair<int,std::string>::Make_xPair(11,"Mohamed Salah");
}