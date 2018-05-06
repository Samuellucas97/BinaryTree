/**
 * @file      main.cpp
 * @brief     Contém a função main e alguns testes com as classes Node e BinarySeachTree
 * @author    Samuel Lucas de Moura Ferino
 * @since     26.04.2018
 * @version   0.0.8
 */ 
 
 
/// BILIOTECAS STL 
#include <iostream>
using std::cout;
using std::endl;

/// BILIOTECAS PRÓPRIAS
#include "Node.h"
#include "BinarySeachTree.h"

int main() {
  
  //// NÓ
  
  // 1° TESTE
    
  Node<int>* b = new Node<int>(10);
  Node<int> c (b->getChave(), b, b->getEsquerda() );

  // 2° TESTE

  Node<int>* a;
  a = new Node<int>();
  Node<int>* g = a->getEsquerda();
  a->setEsquerda(b);
  
  // 3° TESTE
    
  cout << "Conteudo do filho esquerdo do no a: " << a->getEsquerda()->getChave() << endl << "Conteudo de a: " << a->getChave() << endl;
  
  delete b;
  delete g;
  delete a;
  
  //// ÁRVORE DE BUSCA BINÁRIA

  BinarySearchTree<int> tree;

  if(tree.empty()){
    cout << "A arvore esta vazia!" << endl;;
  }
  
  cout <<"Tamanho da arvore: "<< tree.size() << endl; 
  
  tree.insert(30);  
  tree.insert(-3); 
  tree.insert(-3); 
  tree.insert(150); 
  tree.insert(-150);
  
  cout << "Percorrendo a arvore: ";
  tree.travellingNonRecursively();
  cout << endl;
  
  cout << "Maior elemento: " << tree.maximum()->getChave() << endl;
  cout << "Menor elemento: " << tree.minimum()->getChave() << endl;
  
  cout << "Sucessor de " << tree.minimum()->getChave() << " eh " << tree.sucessor( tree.minimum() )->getChave() << endl;
  
  if( tree.sucessor( tree.maximum() ) == nullptr){
    cout << "Sucessor de " << tree.maximum()->getChave() << " eh *NULO*" << endl;
  }
  
  cout << "Predecessor de " << tree.maximum()->getChave() << " eh " << tree.predecessor( tree.maximum() )->getChave() << endl;
  
  if( tree.predecessor( tree.minimum() ) == nullptr){
    cout << "Predecessor de " << tree.minimum()->getChave() << " eh **NULO**" << endl;
  }
  
  tree.travellingRecursively();
  
  if(!tree.empty()){
    cout << "A arvore NAO esta vazia!" << endl;;
  }
  
  return 0;  
}