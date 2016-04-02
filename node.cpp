#include <string>
#include "person.hpp"
#include "node.hpp"

using namespace std;

Node::Node(){

}
Node::Node(Person persona):persona(persona){
	next=new Node();
	setValue(persona);
}
Node::~Node(){
	delete next;
}
Person Node::getValue(){
	return persona;
}
Node* Node::getNext(){
	return next;
}
void Node::setValue(Person persona){
	this->persona.setName(persona.getName());
	this->persona.setPhone(persona.getPhone());
}
void Node::setNext(Node* next){
	this->next=next;
}
bool Node::hasNext(){
	if (next!=NULL){
		return true;
	}else{
		return false;
	}
}