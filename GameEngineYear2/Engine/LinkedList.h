#pragma once
#include<iostream>
#include "Iterator.h"
#include "Node.h"
template <typename AnyType>
class LinkedList
{
public:
	LinkedList();

	LinkedList(const LinkedList<AnyType>& other);
	
	/// <summary>
	/// destroys all nodes in the list using destroy function
	/// </summary>
	~LinkedList();
	
	//deletes all nodes in the list
	void destroy();
	
	//returns an iterator pointing to the first node in the list
	Iterator<AnyType> begin() const;
	
	//returns the next item after the last node in the list
	Iterator<AnyType> end() const;
	
	//returns the first value in the list
	AnyType first() const;
	
	//returns the last value in the list
	AnyType last() const;
	
	//checks to see if the given item is in the list
	bool contains(const AnyType value) const;
	
	//adds a new node to the beginning of the list
	void pushFront(const AnyType& value);
	
	//adds a new node to the end of the list
	void pushBack(const AnyType& value);
	
	//removes the node at the beginning of the list and returns the value
	AnyType popFront();
	
	//removes the node at the end of the list and returns the value
	AnyType popBack();
	
	//adds a new node at the given index
	bool insert(const AnyType& value, int index);
	
	//removes the first node with the given value
	bool remove(const AnyType& value);
	
	//prints the values for all the nodes
	void print() const;
	
	//set the default values for the first node pointer, the last node pointer, and the node count
	void initialize();
	
	//returns whether or not the list has any nodes in it
	bool isEmpty() const;
	
	//sets the given iterator to point to a node at the given index
	bool getData(Iterator<AnyType>& iter, int index);
	
	//returns the amount of nodes in the list
	int getLength() const;
	
	void operator = (const LinkedList<AnyType>& otherList);
	
	//sorts a linked list using the bubble sort method
	void sort();

private:
	Node<AnyType>* m_first;
	Node<AnyType>* m_last;
	int m_nodeCount;


};

// Default constructor for the LinkedList class.
// Calls the initialize function to set up the list.
template<typename AnyType>
inline LinkedList<AnyType>::LinkedList()
{
	initialize();
}

// Copy constructor for the LinkedList class.
// Copies the other list and then calls the initialize function.
template<typename AnyType>
inline LinkedList<AnyType>::LinkedList(const LinkedList<AnyType>& other)
{
	*this = other;
	initialize();
}

// Destructor for the LinkedList class.
// Calls the destroy function to clean up the list.
template<typename AnyType>
inline LinkedList<AnyType>::~LinkedList()
{
	destroy();
}

// Destroys the list by popping all elements from the back until the list is empty.
// Then calls the initialize function to reset the list.
template<typename AnyType>
inline void LinkedList<AnyType>::destroy()
{
	Node<AnyType>* nn;
	Node<AnyType>* cn = m_first;
	if (m_nodeCount == 0)
	{
		return;
	}
	for (int i = 0; i < m_nodeCount; i++)
	{
		popBack();
	}
	initialize();
}

// Returns an iterator pointing to the first element in the list.
template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::begin() const
{
	Iterator<AnyType> ni = Iterator<AnyType>(m_first);
	return ni;
}

// Returns an iterator pointing one past the last element in the list.
template<typename AnyType>
inline Iterator<AnyType> LinkedList<AnyType>::end() const
{
	Iterator<AnyType> ni = Iterator<AnyType>(m_last->next);
	return ni;
}

// Returns the first element in the list.
template<typename AnyType>
inline AnyType LinkedList<AnyType>::first() const
{
	return m_first->data;
}

// Returns the last element in the list.
template<typename AnyType>
inline AnyType LinkedList<AnyType>::last() const
{
	return m_last->data;
}

// Checks if the list contains the given value.
// Returns true if the value is found, false otherwise.
template<typename AnyType>
inline bool LinkedList<AnyType>::contains(const AnyType value) const
{
	for (Iterator<AnyType> iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
		{
			return true;
		}
	}
	return false;
}

// Adds a new element to the front of the list.
template<typename AnyType>
inline void LinkedList<AnyType>::pushFront(const AnyType& value)
{
	Node<AnyType>* nn = new Node<AnyType>(value);
	if (m_nodeCount == 0)
	{
		m_first = nn;
		m_last = nn;
		m_nodeCount++;
		return;
	}
	nn->next = m_first;
	nn->next->previous = nn;
	nn->previous = nullptr;
	m_first = nn;
	m_nodeCount++;
	return;
}

// Adds a new element to the back of the list.
template<typename AnyType>
inline void LinkedList<AnyType>::pushBack(const AnyType& value)
{
	Node<AnyType>* nn = new Node<AnyType>(value);
	if (m_nodeCount == 0)
	{
		m_first = nn;
		m_last = nn;
		m_nodeCount++;
		return;
	}
	nn->previous = m_last;
	nn->previous->next = nn;
	nn->next = nullptr;
	m_last = nn;
	m_nodeCount++;
	return;
}

// Removes and returns the first element in the list.
template<typename AnyType>
inline AnyType LinkedList<AnyType>::popFront()
{
	if (m_nodeCount == 0)
	{
		return AnyType();
	}
	Node<AnyType>* first = m_first;
	AnyType data = first->data;
	m_first->next->previous = nullptr;
	m_first = m_first->next;
	delete first;
	m_nodeCount--;
	return data;
}

// Removes and returns the last element in the list.
template<typename AnyType>
inline AnyType LinkedList<AnyType>::popBack()
{
	if (m_nodeCount == 0)
	{
		return AnyType();
	}
	Node<AnyType>* last = m_last;
	AnyType data = last->data;
	m_last->previous->next = nullptr;
	m_last = m_last->previous;
	delete last;
	m_nodeCount--;
	return data;
}

// Inserts a new element at the given index in the list.
template<typename AnyType>
inline bool LinkedList<AnyType>::insert(const AnyType& value, int index)
{
	Node<AnyType>* nn = new Node<AnyType>(value);
	Node<AnyType>* cn = m_first;
	if (index < 0 && index >= m_nodeCount)
	{
		return false;
	}
	if (m_nodeCount == 0)
	{
		pushBack(value);
		return true;
	}
	if (index == 0)
	{
		pushFront(value);
		return true;
	}
	for (int i = 0; i < index; i++)
	{
		if (cn->next == nullptr)
		{
			break;
		}
		cn = cn->next;
	}
	nn->next = cn;
	nn->previous = cn->previous;
	cn->previous->next = nn;
	cn->previous = nn;
	m_nodeCount++;
	return true;
}

// Removes the first occurrence of the given value from the list.
template<typename AnyType>
inline bool LinkedList<AnyType>::remove(const AnyType& value)
{
	Node<AnyType>* nn = m_first;
	for (int i = 0; i < m_nodeCount; i++)
	{
		if (nn == nullptr)
		{
			return false;
		}
		if (nn->data == value)
		{
			break;
		}
		nn = nn->next;
	}
	if (nn == m_last)
	{
		popBack();
		return true;
	}
	if (nn == m_first)
	{
		popFront();
		return true;
	}
	nn->next->previous = nn->previous;
	nn->previous->next = nn->next;
	delete nn;
	m_nodeCount--;
	return true;
}

// Prints all elements in the list.
template<typename AnyType>
inline void LinkedList<AnyType>::print() const
{
	if (getLength() < 1)
	{
		return;
	}
	for (Iterator<AnyType> ni = begin(); ni != end(); ++ni)
	{
		std::cout << *ni << std::endl;
	}
}
// Initializes the linked list by setting the first and last nodes to nullptr and the node count to 0.
template<typename AnyType>
inline void LinkedList<AnyType>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_nodeCount = 0;
}

// Checks if the linked list is empty by checking if the node count is less than 1.
// Returns true if the list is empty, false otherwise.
template<typename AnyType>
inline bool LinkedList<AnyType>::isEmpty() const
{
	if (m_nodeCount < 1)
	{
		return true;
	}
	return false;
}

// Gets the data at the given index in the list using an iterator.
// Returns false if the index is out of bounds.
template<typename AnyType>
inline bool LinkedList<AnyType>::getData(Iterator<AnyType>& iter, int index)
{
	if (index < 0 || index >= m_nodeCount)
	{
		return false;
	}
	for (int i = 0; i < index; i++, ++iter);

	return true;
}

// Returns the length of the list, which is the number of nodes in the list.
template<typename AnyType>
inline int LinkedList<AnyType>::getLength() const
{
	return m_nodeCount;
}

// Overloads the assignment operator for the LinkedList class.
// Destroys the current list, initializes a new list, and then copies the elements from the other list.
template<typename AnyType>
inline void LinkedList<AnyType>::operator=(const LinkedList<AnyType>& otherList)
{
	destroy();
	initialize();
	for (Iterator<AnyType> iter = otherList.begin(); iter != otherList.end(); ++iter)
	{
		pushBack(*iter);
	}
}

// Sorts the elements in the list using bubble sort.
template<typename AnyType>
inline void LinkedList<AnyType>::sort()
{
	int i, j;
	bool swapped;
	if (m_first == nullptr)
	{
		return;
	}
	AnyType hn = m_first->data;
	Node<AnyType>* cn = m_first;
	for (i = 0; i < m_nodeCount - 1; i++)
	{
		hn = m_first->data;
		cn = m_first;
		swapped = false;
		for (j = 0; j < m_nodeCount - i - 1; j++)
		{
			Node<AnyType>* nn = cn->next;
			AnyType data = nn->data;
			if (data < hn)
			{
				cn->data = data;
				nn->data = hn;
				swapped = true;
			}
			cn = cn->next;
			hn = cn->data;
		}
		if (swapped == false)
		{
			return;
		}
	}
}