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

    };

    bool vazia() const{
        if (this->_raiz == NULL){
            return true;
        }
        else{
            return false;
        }
    };
    
    int quantidade() const{
        return 0;
    };

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
