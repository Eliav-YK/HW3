#include "Vector.h"
Vector::Vector(const int n)
{
	if (n < MIN)
	{
		this->_capacity = MIN;
		this->_resizeFactor = MIN; 
		this->elements = new int[MIN];
	}
	else
	{
		this->_capacity = n;
		this->_resizeFactor = n;
		this->elements = new int[n];
	}
	this->_size = 0;
}
Vector::~Vector()
{
	delete this->elements;
}
int Vector::size() const
{
	return this->_size;
}
int Vector::capacity() const
{
	return this->_capacity;
}
int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}
bool Vector::empty() const
{
	return this->_size == 0;
}
void Vector::push_back(const int& val)
{
	int i = 0;
	int* arr = NULL;
	if (this->_size == this->_capacity) 
	{
		this->_capacity = this->_capacity + this->_resizeFactor; 
		arr = new int[this->_capacity]; 
		for (i = 0; i < this->_size; i++) 
		{
			arr[i] = this->elements[i]; 
		}
		arr[this->_size] = val;
		this->~Vector();
		this->elements = arr; 
	}
	else
	{ 
		this->elements[this->_size] = val; 
	}
	this->_size++;
}
int Vector::pop_back()
{
	int i = 0;
	int valueToReturn = 0;
	if (empty())
	{
		std::cout << "error: pop from empty vector";
		valueToReturn = NO_VARIABLE_FOUND;
	}
	else
	{
		valueToReturn = this->elements[this->_size-1];
		this->elements[this->_size-1] = 0;
		this->_size--;
	}
	return valueToReturn; 
}
void Vector::reserve(const int n)
{
	int i = 0;
	int* arr = nullptr;
	int calcResizeMult = 0;
	if (this->_capacity < n)
	{
		calcResizeMult = (n - this->_capacity) / this->_resizeFactor + 1;
		this->_capacity += calcResizeMult * this->_resizeFactor;
		arr = new int[this->_capacity];
		for (i = 0; i < this->_size; i++)
		{
			arr[i] = this->elements[i];
		}
		this->~Vector();
		this->elements = arr;
	}
}
void Vector::resize(const int n)
{
	int i = 0;
	int* arr = NULL;
	if (n <= this->_capacity)
	{
		while (n < this->_size)
		{
			this->pop_back();
		}
	}
	else if (n > this->_capacity)
	{
		this->reserve(n);
	}
}
void Vector::assign(const int val)
{
	int i = 0;
	for (i = 0; i < this->_capacity; i++)
	{
		this->elements[i] = val;
	}
}
void Vector::resize(const int n, const int& val)
{
	int i = 0;
	if (n > this->_size)
	{
		this->reserve(n);
		for (i = this->_size; i < this->_capacity; i++)
		{
			this->elements[i] = val;
		}
		this->_size = n;
	}
	else
	{
		while (n < this->_size)
		{
			pop_back();
		}
		this->_size = n;
	}

}
Vector::Vector(const Vector& other)
{
	*this = other;
}
Vector& Vector::operator=(const Vector& other)
{
	int i = 0;
	this->_capacity = other._capacity;
	this->_resizeFactor = other._resizeFactor;
	this->_size = other._size;
	this->elements = new int[this->_capacity];
	for (i = 0; i < this->_size; i++)
	{
		this->elements[i] = other.elements[i];
	}
	return *this;
}
int& Vector::operator[](int n) const
{
	if (n < 0 || this->_size <= n)
	{
		return this->elements[0];
	}
	return this->elements[n];
}