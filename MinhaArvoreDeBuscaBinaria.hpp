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
        this->_raiz = NULL;
    }

    ~MinhaArvoreDeBuscaBinaria(){
        Nodo<T> * nodo = this->_raiz;
        Destrutor_aux(nodo);
    }

    void Destrutor_aux(Nodo<T> * nodo){
        Destrutor_aux(nodo->filhoDireita);
        Destrutor_aux(nodo->filhoEsquerda);
        delete nodo;
    }

    bool vazia() const{
        if (this->_raiz == NULL){
            return true;
        } else{
            return false;
        }
    };
    
    int quantidade() const{
        Nodo<int> * nodo = this->_raiz;
        int quantidade = quantidade_aux(nodo);
        return quantidade;
    };

    int quantidade_aux(Nodo<int> * nodo) const {
        if (nodo){
            return 1 + quantidade_aux(nodo->filhoDireita) + quantidade_aux(nodo->filhoEsquerda);
        } else{
            return 0;
        }
    };

    bool contem(T chave) const{
        Nodo<T>* nodo = this->_raiz;
        while(nodo!= NULL){
            if (chave == nodo->chave){
                return true;
            } else if (chave < nodo->chave){
                nodo = nodo->filhoEsquerda;
            } else if ( chave > nodo->chave){
                nodo = nodo->filhoDireita;
            }
        }
        return false;
    }

    std::optional<int> altura(T chave) const{
        Nodo<T>* nodo_chave = nodo_chave_aux(chave);
        if(altura_aux(nodo_chave) == 0){
            return std::nullopt;
        }
        return altura_aux(nodo_chave) -1;
    }

    Nodo<T>* nodo_chave_aux(T chave) const {
        Nodo<T>* nodo = this->_raiz;
        while(nodo != NULL){
            if (chave == nodo->chave){
                return nodo;
            } else if (chave < nodo->chave){
                nodo = nodo->filhoEsquerda;
            } else if ( chave > nodo->chave){
                nodo = nodo->filhoDireita;
            }    
        }
        return nodo;
    }

    int altura_aux(Nodo<T>* nodo) const {
        if (nodo == NULL){
            return 0;
        } else {
            int tamanho_esquerda = altura_aux(nodo->filhoEsquerda);
            int tamanho_direita = altura_aux(nodo->filhoDireita);

            if(tamanho_esquerda > tamanho_direita){
                return (tamanho_esquerda + 1);
            } else {
                return (tamanho_direita + 1);
            }
        }
    };

    void inserir(T chave){
        
    };
        
    void remover(T chave){
        
    };

    std::optional<T> filhoEsquerdaDe(T chave) const{
        Nodo<T>* nodo = this->_raiz;
        while(nodo != NULL){
            if (chave == nodo->chave){
                if(nodo->filhoEsquerda){
                    return nodo->filhoEsquerda->chave;
                }
                return std::nullopt;
            } else if (chave < nodo->chave){
                nodo = nodo->filhoEsquerda;
            } else if ( chave > nodo->chave){
                nodo = nodo->filhoDireita;
            }
        }
        return std::nullopt;
    };
   
    std::optional<T> filhoDireitaDe(T chave) const{
        Nodo<T>* nodo = this->_raiz;
        while(nodo != NULL){
            if (chave == nodo->chave){
                if(nodo->filhoDireita){
                    return nodo->filhoDireita->chave;
                }
                return std::nullopt;
            } else if (chave < nodo->chave){
                nodo = nodo->filhoEsquerda;
            } else if ( chave > nodo->chave){
                nodo = nodo->filhoDireita;
            }
        }
        return std::nullopt;
    };

    ListaEncadeadaAbstrata<T>* emOrdem() const{
        return 0;
    };
    
    ListaEncadeadaAbstrata<T>* emordem_aux (Nodo<T>*nodo, ListaEncadeadaAbstrata<T>*lista_auxiliar) const {
        return 0;
    }


    ListaEncadeadaAbstrata<T>* preOrdem() const{
        return 0;
    };

    ListaEncadeadaAbstrata<T>* posOrdem() const{
        return 0;
    };
};

#endif
