#ifndef MINHAARVOREDEBUSCABINARIA_HPP
#define MINHAARVOREDEBUSCABINARIA_HPP

#include "ArvoreDeBuscaBinaria.hpp"
#include <cassert>
#include <utility>

/**
 * @brief Representa uma árvore binária de busca.
 * 
 * @tparam T O tipo de dado guardado na árvore.
 */
template<typename T>
class MinhaArvoreDeBuscaBinaria : public ArvoreDeBuscaBinaria<T>{
    public:

    MinhaArvoreDeBuscaBinaria(){
        ArvoreDeBuscaBinaria<T>::_raiz = NULL;
    };

    ~MinhaArvoreDeBuscaBinaria(){
        Nodo<T> * nodo = this->_raiz;
        Destrutor_aux(nodo);
    };

    void Destrutor_aux(Nodo<T> * nodo){
        Destrutor_aux(nodo->filhoDireita);
        Destrutor_aux(nodo->filhoEsquerda);
        delete nodo;
    }

    bool vazia() const{
        if (this->_raiz == NULL){
            return true;
        }
        else{
            return false;
        }
    };
    
    int quantidade() const{
        Nodo<int> * nodo = this->_raiz;
        if(nodo == NULL){
            return 0;
        }
        int quantidade = quantidade_aux(nodo);
        return quantidade;
    };

    int quantidade_aux(Nodo<int> * nodo) const {
        if (nodo){
            return 1 + quantidade_aux(nodo->filhoDireita) + quantidade_aux(nodo->filhoEsquerda);
        }
        else{
            return 0;
        }
    }

    bool contem(T chave) const{
        return 0;
    };

    std::optional<int> altura(T chave) const{
        return 0;
    };
        
    void inserir(T chave){
        
    };
        
    void remover(T chave){
        
    };

    std::optional<T> filhoEsquerdaDe(T chave) const{
        return 0;
    };
   
    std::optional<T> filhoDireitaDe(T chave) const{
        return 0;
    };

    ListaEncadeadaAbstrata<T>* emOrdem() const{
        return 0;
    };
    
    ListaEncadeadaAbstrata<T>* preOrdem() const{
        return 0;
    };

    ListaEncadeadaAbstrata<T>* posOrdem() const{
        return 0;
    };

    

};

#endif
