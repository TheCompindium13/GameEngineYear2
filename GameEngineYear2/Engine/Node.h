namespace GameEngine
{
    // The Node class represents a node in a linked list.
    // It contains a data member of type AnyType and pointers to the next and previous nodes in the list.
    template <typename AnyType>
    class Node
    {
    public:
        // Default constructor for the Node class.
        // Initializes the data member to 0 and the next and previous pointers to nullptr.
        Node();

        // Overloaded constructor for the Node class.
        // Initializes the data member to the provided value and the next and previous pointers to nullptr.
        Node(AnyType value);

        // Pointer to the next node in the list.
        Node<AnyType>* next;

        // Pointer to the previous node in the list.
        Node<AnyType>* previous;

        // The data stored in the node.
        AnyType data;
    };

    // Implementation of the default constructor for the Node class.
    template<typename AnyType>
    inline Node<AnyType>::Node()
    {
        data = 0;
        next = nullptr;
        previous = nullptr;
    }

    template<typename AnyType>
    inline Node<AnyType>::Node(AnyType value)
    {
        data = value;
        next = nullptr;
        previous = nullptr;
    }



    // Implementation of the overloaded constructor for the Node class.

}
