#pragma once
#include<iostream>
#include "Node.h"
namespace GameEngine
{
    // The Iterator class provides a way to access elements in a linked list sequentially without exposing its underlying representation.
    template <typename AnyType>
    class Iterator
    {
    public:
        // Default constructor for the Iterator class.
        // Initializes the current node to nullptr.
        Iterator();

        // Overloaded constructor for the Iterator class.
        // Initializes the current node to the provided node.
        Iterator(Node<AnyType>* node);

        // Overloads the pre-increment operator for the Iterator class.
        // Advances the iterator to the next node in the list.
        Iterator<AnyType> operator ++();

        // Overloads the pre-decrement operator for the Iterator class.
        // Moves the iterator to the previous node in the list.
        Iterator<AnyType> operator --();

        // Overloads the equality operator for the Iterator class.
        // Checks if two iterators point to the same node.
        const bool operator == (const Iterator<AnyType>& iter);

        // Overloads the inequality operator for the Iterator class.
        // Checks if two iterators point to different nodes.
        const bool operator != (const Iterator<AnyType>& iter);

        // Overloads the dereference operator for the Iterator class.
        // Returns the data stored in the current node.
        AnyType operator *();

    private:
        // Pointer to the current node in the list.
        Node<AnyType>* m_current;
    };

    // Implementation of the default constructor for the Iterator class.
    template<typename AnyType>
    inline Iterator<AnyType>::Iterator()
    {
        m_current = nullptr;
    }

    // Implementation of the overloaded constructor for the Iterator class.
    template<typename AnyType>
    inline Iterator<AnyType>::Iterator(Node<AnyType>* node)
    {
        m_current = node;
    }
    // Implementation of the pre-increment operator for the Iterator class.
    template<typename AnyType>
    inline Iterator<AnyType> Iterator<AnyType>::operator++()
    {
        if (m_current == nullptr)
        {
            return Iterator<AnyType>(nullptr);
        }
        m_current = m_current->next;
        return *this;
    }

    // Implementation of the pre-decrement operator for the Iterator class.
    template<typename AnyType>
    inline Iterator<AnyType> Iterator<AnyType>::operator--()
    {
        if (m_current != nullptr)
        {
            m_current = m_current->previous;
        }
        return *this;
    }

    // Implementation of the equality operator for the Iterator class.
    template<typename AnyType>
    inline const bool Iterator<AnyType>::operator==(const Iterator<AnyType>& iter)
    {
        if (this->m_current == &iter.m_current)
        {
            return true;
        }
        return false;
    }

    // Implementation of the inequality operator for the Iterator class.
    template<typename AnyType>
    inline const bool Iterator<AnyType>::operator!=(const Iterator<AnyType>& iter)
    {
        if (this->m_current == iter.m_current)
        {
            return false;
        }
        return true;
    }

    // Implementation of the dereference operator for the Iterator class.
    template<typename AnyType>
    inline AnyType Iterator<AnyType>::operator*()
    {
        if (m_current == nullptr)
        {
            return AnyType();
        }
        return m_current->data;
    }
}
