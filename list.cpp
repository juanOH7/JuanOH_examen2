#include "node.hpp"
#include "list.hpp"
#include "person.hpp"
#include <iostream>

using std::cerr;

using namespace std;

List::List(){
	head=new Node();
}

List::List(Person persona){
	head= new Node(persona);
}

List::~List(){
	delete head;
}

void List::setHead(Person persona){
	this->head=new Node(persona);
}

Person List::getHead(){
	return head->getValue();

}

void List::insert(int posicion, Person persona){
	if (posicion > 0 ){
		if (!head->hasNext()){
			if (posicion==1){
				head->setNext(new Node(persona));
			}else if (posicion>1){
				cerr<<"INDEX OUT OF BOUND"<<endl;
			}else{
				Node* temp=head;
				head->setValue(persona);
				head->setNext(temp);
			}
		}else{
			Node* temp=head;
			int count=0;
			if (size()>=posicion){
				while(count<posicion-1){
					temp=temp->getNext();
					count++;
				}
				Node* nuevo=new Node(persona);
				if (temp->hasNext()){
					 Node*temp2=temp->getNext();
					 nuevo->setNext(temp2);
				}

				temp->setNext(nuevo);
			}
		}

	}else if (posicion==0){
		if (head!=NULL){
			Node* temp=head;
			setHead(persona);
			head->setNext(temp);
		}else{
			setHead(persona);
		}
	}else{
		cerr<<"Invalid Position"<<endl;
	}

}


Person List::at(int posicion){
	Node* temp=head;
	int contador=0;
	if (size()>posicion){
		if (posicion==0){
			return head->getValue();
		}
		while(contador<posicion){
			temp = temp->getNext();
			contador++;
		}
		return temp->getValue();
	}
}

void List::erase(int posicion){
	Node* temp=head;
	int contador=0;
	if (size()>posicion){
		if (posicion==0){
			delete head;
		}
		Node* nuevo=new Node();
		while(contador=posicion){
			Node*temp2=temp->getNext();
			temp2->setNext(temp2);
			delete temp;
		}
	}
}

void List::concat(List* lista){
	push_back(lista->getHead());
}

int List::find(Person persona){
	Node* temp=head;
	bool encontrado=false;
	int contador=0;
	while(temp->hasNext()){
		temp=temp->getNext();
		contador+=1;
		if ( (temp->getValue()).getName()==persona.getName()){
			encontrado=true;
			break;
		}
	}

	if (encontrado){
		return contador;
	}else{
		return -1;
	}
}

int List::size(){
	Node* temp;
	int contador=0;
	if (head!=NULL){
		contador++;
		temp=head;
		while(temp->getNext()){
			contador++;
			temp=temp->getNext();
		}
	}
	return contador;
}

void List::push_back(Person persona){
	insert(size(), persona);
}

Node* List::first(){
	return head;
}
