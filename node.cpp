#include "node.hpp"
#include "person.hpp"

Node::Node(){}

Node::Node(Person persona):persona(persona)
{
	next = new Node(Person());
}
Node::~Node(){}

Person Node::getValue()
{
	return persona;
}

Node* Node::getNext()
{
	return next;
}

void Node::setValue(Person newPersona)
{
	persona = newPersona;
}

void Node::setNext(Node* newNext)
{
	next = newNext;
}
bool Node::hasNext(){}