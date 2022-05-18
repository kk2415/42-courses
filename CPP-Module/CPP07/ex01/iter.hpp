#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T array[], int length, void (*p)(const T& arg))
{
	for (int i = 0; i < length; i++)
	{
		(*p)(array[i]);
	}
}

#endif
