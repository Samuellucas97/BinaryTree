/**
 * @file		BinarySearchTree.h 
 * @brief     	Contém a classe BinarySearchTree a implementação de seus métodos
 * @author 		Samuel Lucas de Moura Ferino
 * @since 		26.04.2018
 * @version		0.1.3
*/

#ifndef	_BINARYSEARCHTREE_H
#define	_BINARYSEARCHTREE_H

/// BIBLIOTECAS PRÓPRIAS

#include "Node.h"

/// BIBLIOTECAS USADAS (STL)

#include <ostream>		/// cout
using std::cout;	
using std::endl;

#include <stack>		///	stack
using std::stack;

/*!
 * \class 		BinarySearchTree
*/
template< typename T>
class BinarySearchTree{
	
	/// ATRIBUTOS

	private:
	
		/*!	\var	Node<T>* raiz	
				\brief	Nó raiz 
		 */
		Node<T>* raiz;
		
		/*!	\var 	stack<Node<T>*> pilha	
		 		\brief	Guardará os nó no momento de percorrer a árvore não recursivamente
		 */
		stack<Node<T>*> pilha;

	    /*! \var  int quantidadeDeElementos
	     *  \brief  Quantidade de elementos/nós que a árvore contém
	     */
	    int quantidadeDeElementos;
	
	/// MÉTODOS	PÚBLICOS

	public:

		/**
		 * @brief Construtor padrão.
		 *        A árvore será iniciada com um nó para facilitar na adição dos nós   
		 */	
		BinarySearchTree(){
			
			this->raiz = new Node<T>();
			quantidadeDeElementos = 0;
		
		}

		/**
		 * @brief   Construtor parametrizado ao mesmo tempo
		 * @param 	raizNova			Nó novo
		 */	
		explicit BinarySearchTree(Node<T>* raizNova ): raiz(raizNova), quantidadeDeElementos(0){}

		/**
		 * @brief   Construtor cópia
		 * @param 	tree			Árvore que será usada como molde para construir esta árvore
		 */	
		BinarySearchTree( const BinarySearchTree<T> &tree){
			
			this->raiz = tree.getRaiz();
			this->quantidadeDeElementos = tree.getQuantidadeDeElementos();

		}

		/**
		 * @brief	Sobrecarga do operador =
		 *			Obs.: Pode atuar como um dos construtores
		 * @param 	outroTree 		Árvore usada como referência 	
		 */
		BinarySearchTree& operator=(const BinarySearchTree<T> &outroTree){
			
			this->raiz = outroTree.getRaiz();
			this->quantidadeDeElementos = outroTree.getQuantidadeDeElementos();
			
			return *this;
		}

		/**
		 * @brief	Destrutor padrão 
		 */	
		~BinarySearchTree(){
		  
		  destroyTheTree(this->raiz);
			
		}


		///\/\/\/\/\/\/\/ 						****** GETTERS E SETTERS *****							\/\/\/\/\/\/\/\/
		
		/**
		 * @brief 		Método get do atributo raiz
		 * @return 		Nó raiz
		*/
		Node<T>* getRaiz() const{ 
			return this->raiz; 
		}

		/**
		 * @brief 		Método set do atributo raiz
		 * @return 		raizNova		Novo nó raiz
		*/
		void setRaiz( Node<T>* raizNova){
			this->raiz = raizNova;
		}

		/**
		 * @brief 		Método get do atributo raiz
		 * @return 		Nó raiz
		*/
		int getQuantidadeDeElementos() const{	
			return this->quantidadeDeElementos; 
		}


		///\/\/\/\/\/\/\/ 						****** 					 *****							\/\/\/\/\/\/\/\/

	    /**
	     * @brief   Verifica se a árvore está vazia 
	     * @return  True se a árvore estiver vazia, false senão
	     */
	    bool empty(){
	      if( size() == 0 ) /// QUANTIDADE DE NÓS **IGUAL** A ZERO
	        return true;
	      else   /// QUANTIDADE DE NÓS **DIFERENTE** DE ZERO
	        return false;
	    }
	  
	    /**
	     * @brief   Percorre a árvore, contando a quantidade de nós que a compõem
	     * @return  Quantidade de nós na árvore
	     */ 
	    int size(){
	      
	      	/*! \var  int quantidadeNos
	       	 *  \brief  Guarda a quantidadeNos
	       	 */
	      	int quantidadeNos = 0;
		  
	    	/*!	\var	Node<T>* copyRoot 
					\brief	 Copia do nó raiz da árvore
			 */
			Node<T>* copyRoot = this->raiz;				
			
			/*!	\var	bool PERCORRER 
			  		\brief	Condição de loop continuar 
			 */
			bool LOOP = true;

			while( LOOP ){ 
				if(copyRoot != nullptr){	/// CASO O NÓ **NÃO SEJA** NULO
					pilha.push(copyRoot);
					copyRoot = copyRoot->getEsquerda(); 				
				}						
				else{		/// CASO O NÓ **SEJA** NULO
					if( !pilha.empty() ){			/// CASO A PILHA **NÃO ESTEJA** VAZIA
						copyRoot = pilha.top(); 
						pilha.pop();
						quantidadeNos++;	
						copyRoot = copyRoot->getDireita();
					}
					else{			/// CASO A PILHA **ESTEJA** VAZIA
						LOOP = false;		
					}
				}
			}
			
			/// LEMBRE-SE: A ÁRVORE É INICIADO COM UM NÓ
			return quantidadeNos-1;
	      
	    }
	    
		/**
		 * @brief		Percorre a árvore toda recursivamente, imprimindo-a
		 */
		void travellingRecursively(void){

			/// PRE-ORDEM

			/*!	\var	Node<T>* copyRootPre 
			 		\brief	 Copia do nó raiz que será usado no momento de percorrer pré-ordem a árvore 
			 */
			Node<T>* copyRootPre = this->raiz; 			
	 
	    	cout << "PRE-ORDEM: ";
	 
			preOrderTreeWalk(copyRootPre);

			/// IN-ORDEM

			/*!	\var	Node<T>* copyRootIn 
					\brief	 Copia do nó raiz que será usado no momento de percorrer em ordem a árvore	 
			 */
			Node<T>* copyRootIn = this->raiz; 			
	    
	    	cout << endl << "IN-ORDEM: ";
	      
			inOrderTreeWalk(copyRootIn);
		
			/// POS-ORDEM

			/*!	\var	Node<T>* copyRootPos 
					\brief	 Copia do nó raiz que será usado no momento de percorrer pós-ordem a árvore	 
			 */
			Node<T>* copyRootPos = this->raiz; 				
   
      		cout << endl << "POS-ORDEM: ";
	 
			posOrderTreeWalk(copyRootPos);
			
			cout << endl;
			
		}

		/**
		 * @brief		Percorre a árvore toda não recursivamente, imprimindo-a
		 */
		void travellingNonRecursively(){

			/*!	\var	Node<T>* copyRoot 
					\brief	 Copia do nó raiz da árvore
			 */
			Node<T>* copyRoot = this->raiz;				
			
			/*!	\var	bool PERCORRER 
			  		\brief	Condição de loop continuar 
			 */
			bool LOOP = true;

			while( LOOP ){ 

				if(copyRoot != nullptr){	/// CASO O NÓ **NÃO SEJA** NULO

					pilha.push(copyRoot);
					copyRoot = copyRoot->getEsquerda(); 				

				}						

				else{		/// CASO O NÓ **SEJA** NULO

					if( !pilha.empty() ){			/// CASO A PILHA **NÃO ESTEJA** VAZIA

						copyRoot = pilha.top();
						pilha.pop();
						cout << " " << copyRoot->getChave() << " ";	
						copyRoot = copyRoot->getDireita();

					}

					else{			/// CASO A PILHA **ESTEJA** VAZIA

						LOOP = false;		
					}
											
				}

			}

		}
    
	    /**
	     * @brief   Busca recursivamente a chave na árvore
	     * @param   x     Nó a partir do qual será buscado
	     * @param   key   Chave a ser buscada
	     * @return  Um ponteiro nulo ou o ponteiro para o nó buscado
	     */ 
	    Node<T>* searchRecursively(Node<T>*& x, T key){
				  
			if( x == nullptr || x->getChave() == key){ /// CONDIÇÃO DE PARADA: Chave encontrada ou ponteiro nulo (fim desse caminho )
			 
			   return x;
			 
			}
			else if( key > x->getChave() ){  /// A CHAVE É MAIOR QUE A CHAVE DO NÓ ATUAL. LOGO, BUSCA-SE NO NÓ/CAMINHO À DIREITA
			   
			   x = searchRecursively(x->getDireita(), key );
			 
			}
			else{/// A CHAVE É MENOR QUE A CHAVE DO NÓ ATUAL. LOGO, BUSCA-SE NO NÓ/CAMINHO À ESQUERDA
			   
			   x = searchRecursively(x->getEsquerda(), key );
			   
			}
			  
		}

	    /**
	     * @brief   Busca recursivamente a chave na árvore
	     * @param   key   Chave a ser buscada
	     * @return  True se encontrado ou False senão
	     */ 
		bool searchRecursivelyBOOLEAN( T key){
			
			 /*!	\var	Node<T>* copyRoot 
					\brief	 Copia do nó raiz da árvore	 
			  */
			 Node<T>* copyRoot = this->raiz;	
			
			/// CHAMANDO O MÉTODO DE BUSCA RECURSIVA
			copyRoot = searchRecursively(copyRoot, key);
		
			if(copyRoot == nullptr){  /// SITUAÇÃO EM QUE NÃO FOI ENCONTRADO O NÓ
			  
			  return false;
			  
			}
			
			else{  /// SITUAÇÃO EM QUE FOI ENCONTRADO O NÓ
			  
			  return true;
			
			}  
					
		}
	  
		  /**
	     * @brief   Busca iterativamente a chave na árvore
	     * @param   key   Chave a ser buscada
	     * @return  Um ponteiro nulo ou o ponteiro para o nó buscado
	     */ 
	    Node<T>* seachIterative(T key){
		    
		    /*!	\var	Node<T>* copyRoot 
						\brief	 Copia do nó raiz que será usado no momento de percorrer em ordem a árvore	 
				 */
				Node<T>* copyRoot = this->raiz;
		    
		    while( copyRoot != nullptr || copyRoot->getChave() != key ){
		      if( key > copyRoot->getChave() ){
		        copyRoot = copyRoot->getEsquerda();
		      }
		      else{
		        copyRoot = copyRoot->getDireita();
		      }
		    }
		    
		    return copyRoot;
		    
		  }
		  
	    /**
	     * @brief   Busca iterativamente a chave na árvore
	     * @param   key   Chave a ser buscada
	     * @return  True se encontrado ou False senão
	     */ 
		bool seachIterativeBOOLEAN(T key){
		 
		    /*! \var  Node<T>* result 
		          \brief   Busca na árvore a menor chave
		     */ 
		    Node<T>* result = seachIterative(key);
		    
		    if( result == nullptr){   /// A CHAVE **FOI ENCONTRADA**
		      return false;
		    }
		    else{   /// A CHAVE **NÃO FOI ENCONTRADA** 
		      return true;
		    }
		    
		}
		  
	  	/**
	   	 * @brief   Busca o nó da árvore mais à esquerda
	   	 * @return  O nó da árvore com a menor chave
	   	 */ 
	  	Node<T>* minimum() const{
	    
	    	/*!	\var	Node<T>* copyRoot 
					\brief	 Copia do nó raiz que será usado no momento de percorrer em ordem a árvore	 
				 */
			Node<T>* copyRoot = this->raiz;
	    
		    while(copyRoot->getEsquerda() != nullptr){ /// ENQUANTO O FILHO ESQUERDO NÃO FOR NULO O PONTEIRO ATUAL RECEBE O ENDEREÇO DO FILHO ESQUERDO
		      copyRoot = copyRoot->getEsquerda();  
		    }
		    
		    return copyRoot;
	    
	 	}
	  
		/**
		 * @brief   Busca o nó da árvore mais à direita
		 * @return  O nó da árvore com a maior chave
		 */ 
		Node<T>* maximum() const{
		    
		   	/*!	\var	Node<T>* copyRoot 
				\brief	 Copia do nó raiz que será usado no momento de percorrer em ordem a árvore	 
		     */
			Node<T>* copyRoot = this->raiz;
		    
		    while(copyRoot->getDireita() != nullptr){   /// ENQUANTO O FILHO DIREITO NÃO FOR NULO O PONTEIRO ATUAL RECEBE O ENDEREÇO DO FILHO DIREITO
		      copyRoot = copyRoot->getDireita();  
		    }
		    
		    return copyRoot;
		    
		}
	  
		/**
		 * @brief   Busca o nó que contém o sucessor do nó x
		 * @param   x   Nó o qual será buscando o seu sucessor
		 * @return  Nó sucessor
		 */ 
		Node<T>* sucessor(Node<T>* x)
		{
		    
		    if(x->getDireita() != nullptr){ /// O NÓ x TEM FILHO À DIREITA
		      return mimimunOfAnyNode( x->getDireita() );
		    }
		    
		    /*!	\var	Node<T>* copyFather 
						\brief	 Copia do nó pai do nó x	 
				 */
		    Node<T>* copyFather = x->getP(); 
		     
		     while(copyFather != nullptr && copyFather->getDireita() == x ){  /// SUBINDO PELA ÁRVORE
		       x = copyFather;
		       copyFather = copyFather->getP();
		     }
		     
		     return copyFather;
		}
		  
		/**
		 * @brief   Busca o nó que contém o sucessor do nó x
		 * @param   x   Nó o qual será buscando o seu sucessor
		 * @return  Nó sucessor
		 */ 
		Node<T>* predecessor(Node<T>* x){
		     
		    if(x->getEsquerda() != nullptr){ /// O NÓ x TEM FILHO À ESQUERDA
		        return maximumOfAnyNode( x->getEsquerda() );
		    }
		     
		    /*!	\var	Node<T>* copyFather 
						\brief	 Copia do nó pai do nó x	 
				 */
		    Node<T>* copyFather = x->getP(); 
		     
		    while(copyFather != nullptr && copyFather->getEsquerda() == x ){  /// SUBINDO PELA ÁRVORE
		       x = copyFather;
		       copyFather = copyFather->getP();
		    }
		     
		    return copyFather;
		     
		}
		  
		/**
		 * @brief   Cria um novo nó com o conteúdo entrado, identifica o local 
		 *          onde ele deve ser colocado na árvore e adiciona-o
		 * @param   value   Conteúdo do novo nó
		 */ 
		void insert(T value){
		    
		    /*!	\var	Node<T>* copyRoot 
						\brief	 Copia do nó raiz que será usado no momento de percorrer em ordem a árvore	 
				 */
		    Node<T>* copyRoot = this->raiz;
		    
		    if( this->quantidadeDeElementos > 0){
	  	    
	  	    /*!	\var	Node<T>* nodeSearch 
						\brief	 Nó anterior ao local em que será adicionado o novo nó	 
				 */
		    Node<T>* nodeSearch = nullptr;
	  	    
	  	    /// BUSCANDO SE O NÓ JÁ EXISTE
	  	    while( copyRoot != nullptr){
	  	      
	  	    	nodeSearch = copyRoot;
	  	      
	  		    if( value < copyRoot->getChave() ){ /// Value MENOR QUE CHAVE DO PONTEIRO ATUAL
	  	        	copyRoot = copyRoot->getEsquerda();
	  	    	}
	  	    	else if( value == copyRoot->getChave() ){ /// Value IGUAL A CHAVE DO PONTEIRO ATUAL
	  	        	break;
	  	      	}
	  	      	else{ /// Value MAIOR QUE CHAVE DO PONTEIRO ATUAL
	  	        	copyRoot = copyRoot->getDireita(); 
	  	      	}
	  	    }   
	  	      
	  	    /// CRIANDO NOVO NÓ 
	  	    Node<T>* newNode = new Node<T>(value, nodeSearch, nullptr, nullptr);
	  	     
	  	                	    
	  	    /// ADICIONANDO O NÓ
	        if( value < nodeSearch->getChave() ){   /// TORNANDO newNode O FILHO ESQUERDO DE nodeSearch
	          nodeSearch->setEsquerda(newNode);  
	        }	 
	  	    else{
	  	      nodeSearch->setDireita(newNode);    /// TORNANDO newNode O FILHO DIREITO DE nodeSearch
	  	    }  
	  	   
	  	   	++(this->quantidadeDeElementos);   /// INCREMENTANDO NA QUANTIDADE TOTAL DE NÓS DA ÁRVORE
		    
		    }
		    else{ /// PRIMEIRA INSERÇÃO NA ÁRVORE
		   
		      	copyRoot->setChave(value);
	  	   		++(this->quantidadeDeElementos);   /// INCREMENTANDO NA QUANTIDADE TOTAL DE NÓS DA ÁRVORE
		   
		    }
		}
    
      	/**
		 * @brief   Identifica o local onde deve ser colocado o novo nó na árvore e adiciona-o
		 * @param   novoNoh   Novo nó
		 * @return  True caso tenha sido adiciona, false caso contrário
		 */ 
		bool insertNode(Node<T>* novoNoh){
		    
  		  if(novoNoh != nullptr){  
  		    /*!	\var	Node<T>* copyRoot 
  						\brief	 Copia do nó raiz que será usado no momento de percorrer em ordem a árvore	 
  				 */
  		    Node<T>* copyRoot = this->raiz;
  		    
  		    if( this->quantidadeDeElementos > 0){
  	  	    
  	  	    /*!	\var	Node<T>* nodeSearch 
  						\brief	 Nó anterior ao local em que será adicionado o novo nó	 
  				   */
  		      Node<T>* nodeSearch = nullptr;
  	  	    
  	  	    /// BUSCANDO SE O NÓ JÁ EXISTE
  	  	    while( copyRoot != nullptr){
  	  	      
  	  	      nodeSearch = copyRoot;
  	  	      
  	  	      if( novoNoh->getChave() < copyRoot->getChave() ){ /// Value MENOR QUE CHAVE DO PONTEIRO ATUAL
  	  	        copyRoot = copyRoot->getEsquerda();
  	  	      }
  	  	      else if( novoNoh->getChave() == copyRoot->getChave() ){ /// Value IGUAL A CHAVE DO PONTEIRO ATUAL
  	  	        break;
  	  	      }
  	  	      else{ /// Value MAIOR QUE CHAVE DO PONTEIRO ATUAL
  	  	        copyRoot = copyRoot->getDireita(); 
  	  	      }
  	  	    }   
  	  	      
  	  	    novoNoh->setP(nodeSearch); 
  	  	                	    
  	  	    /// ADICIONANDO O NÓ
  	        if( novoNoh->getChave() < nodeSearch->getChave() ){   /// TORNANDO newNode O FILHO ESQUERDO DE nodeSearch
  	          nodeSearch->setEsquerda(novoNoh);  
  	        }	 
  	  	    else{
  	  	      nodeSearch->setDireita(novoNoh);    /// TORNANDO newNode O FILHO DIREITO DE nodeSearch
  	  	    }  
  	  	   
  	  	   ++(this->quantidadeDeElementos);   /// INCREMENTANDO NA QUANTIDADE TOTAL DE NÓS DA ÁRVORE
  		      
  		      return true;
  		    
  		    }
  		    else{   /// PRIMEIRA INSERÇÃO NA ÁRVORE
  		   
  		      copyRoot->setChave( novoNoh->getChave() );
  	  	   ++(this->quantidadeDeElementos);   /// INCREMENTANDO NA QUANTIDADE TOTAL DE NÓS DA ÁRVORE
  		    
  		      return true;
  		      
  		    }
		    }
		    else{ /// O NÓ novoNoh É NULO
		      
		      return false;
		      
		    }
		  }

		/**
	   	 * @brief   Busca o extremo nó à esquerda de qualquer nó
	   	 * @param   x   Nó usado como ponto de partida
	   	 * @return  O nó extremo à esquerda
	   	 */
		Node<T>* mimimunOfAnyNode(Node<T>* x){
		  
		  while(x->getEsquerda() != nullptr){ /// ENQUANTO TIVER DESCENTE À ESQUERDA
		    x = x->getEsquerda();
		  }
		  
		  return x;
		  
		}
		
		/**
		 * @brief   Busca o extremo nó à direita de qualquer nó
		 * @param   x   Nó usado como ponto de partida
		 * @return  O nó extremo à direita
		 */ 
		Node<T>* maximumOfAnyNode(Node<T>* x){
			  
		  while(x->getDireita() != nullptr){ /// ENQUANTO TIVER DESCENTE À DIREITA
		    x = x->getDireita();
		  }
		  
		  return x;
			  
		}
		
		/**
		 * @brief   Remove da árvore o nó nodeAlvo
		 * @param   nodeAlvo  Nó que será removido
		 */ 
		bool removeNode(Node<T>* nodeAlvo){	
  		  
	  		if(nodeAlvo !=  nullptr){ 
	  		
	  		  if( nodeAlvo->getEsquerda() == nullptr){  /// O NÓ nodeAlvo A SER REMOVIDO **NÃO TEM** FILHO À ESQUERDA
	  		    transplant(nodeAlvo, nodeAlvo->getDireita() );
	  		  }
	  		  else if( nodeAlvo->getDireita() == nullptr){  /// O NÓ nodeAlvo A SER REMOVIDO **NÃO TEM** FILHO À DIREITA
	  		    transplant(nodeAlvo, nodeAlvo->getEsquerda() );
	  		  }
	  		  else{  /// O NÓ nodeAlvo A SER REMOVIDO **TEM** FILHO À ESQUERDA E À DIREITA
	  		    
	  		    Node<T>* menorMaiorNoh = mimimunOfAnyNode(nodeAlvo->getDireita() ); /// PEGO O MENOR DOS FILHOS À DIREITA DE nodeAlvo PARA GARANTIR QUE SEJA MAIOR QUE TODOS OS DESCENTES À ESQUERDA DE nodeAlvo
	  		    
	  		    if(menorMaiorNoh->getP() != nodeAlvo){
	  		      transplant(menorMaiorNoh, menorMaiorNoh->getDireita() );
	  		      menorMaiorNoh->setDireita( nodeAlvo->getDireita() );
	  		      menorMaiorNoh->getP()->setDireita( menorMaiorNoh );
	  		    }
	  		    
	  		    transplant( nodeAlvo, menorMaiorNoh );
	  		    menorMaiorNoh->setEsquerda( nodeAlvo->getEsquerda() );
	  		    menorMaiorNoh->getP()->setEsquerda( menorMaiorNoh ) ;
	  		  }
	  		  
	  		  return true;
	  		
	  		}
	  		
	  		else{
	  		
	  		  return false;
	  		}
  		
		} 
		
	 ///    /\/\/\/\/\/\      MÉTODOS PRIVADOS    /\/\/\/\/\/\      
	  
	private:
  
	    /**
	     * @brief   Substitui uma subárvore como um filho de seu pai por outra subárvore
	     * @param   u 	Nó que será substituído pelo nó v
	     * @param   v 	Nó que substituirá o nó u
	     */
    	void transplant(Node<T>* u, Node<T>* v){
       
	        if( u->getP() == nullptr ){ /// CASO EM QUE SERÁ REMOVIDA A RAIZ, POR ISSO, v SERÁ A NOVA RAIZ 
	          this->raiz = v;
	        }
	        else if( u == u->getP()->getEsquerda() ){ /// u É O FILHO À ESQUERDA
	          u->getP()->setEsquerda(v);
	        }
	        else{ /// u É O FILHO À DIREITA
	          u->getP()->setDireita(v);
	        }
	        if(v != nullptr){ /// JÁ QUE FOI MOVIDO UM FILHO NÃO NULO, FALTA DIZER QUEM É O PAI DELE 
	          v->setP(u->getP());
	        }
        
      	} 
  
	    /**
	     * @brief   Destrói os nós da árvore
	     * @param   x   Nó a terá os subnós destruídos
	     */ 
	    void destroyTheTree(Node<T>* x){
	      
	      if(x != nullptr){     /// CASO O NÓ **NÃO SEJA** NULO
	        
	        Node<T>* copyLeft = x->getEsquerda();
	        Node<T>* copyRight = x->getDireita();
	        
	        destroyTheTree(copyLeft);
	        destroyTheTree(copyRight);
	        
	        delete x;
	        delete copyLeft;
	        delete copyRight;
	        
	          cout << std::endl << "Arvore sendo destruida... " ;
	        
	      }
	      
	    }

		///   ********* PERCORRENDO ATRAVÉS DA ÁRVORE  ********** 
	
		/**
		 *	@brief		Parte recursiva Pré-Ordem
		 * 	@param		x 	Nó atual 
		*/	
		void preOrderTreeWalk(Node<T>* x){
			
			if( x != nullptr){			/// CASO O NÓ **NÃO SEJA** NULO
				
				cout << " " << x->getChave() << " ";
				preOrderTreeWalk( x->getEsquerda() );
				preOrderTreeWalk( x->getDireita() );

			}

		}

		/**
		 *	@brief		Parte recursiva In-Ordem
		 * 	@param		x 	Nó atual 
		*/	
		void inOrderTreeWalk(Node<T>* x){
			
			if( x != nullptr){			/// CASO O NÓ **NÃO SEJA** NULO
				
				inOrderTreeWalk( x->getEsquerda() );
				cout << " " << x->getChave() << " ";
				inOrderTreeWalk( x->getDireita() );

			}
			
		}

		/**
		 *	@brief		Parte recursiva Pós-Ordem
		 * 	@param		x 	Nó atual 
		*/	
		void posOrderTreeWalk(Node<T>* x){
			
			if( x != nullptr){			/// CASO O NÓ **NÃO SEJA** NULO
				
				posOrderTreeWalk( x->getEsquerda() );
				posOrderTreeWalk( x->getDireita() );
				cout << " " << x->getChave() << " ";

			}

		}

};

#endif
