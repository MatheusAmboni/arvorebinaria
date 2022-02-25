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
    };

    ~MinhaArvoreDeBuscaBinaria(){
        Nodo<T> * nodo = this->_raiz;
        if (this->_raiz != NULL){
            Destrutor_aux(nodo->filhoEsquerda);
            Destrutor_aux(nodo->filhoDireita);
            delete nodo;
        }
    };

    void Destrutor_aux(Nodo<T> * nodo){
        if(nodo != NULL){
            Destrutor_aux(nodo->filhoDireita);
            Destrutor_aux(nodo->filhoEsquerda);
            delete nodo;
        }
    };

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
    };

    std::optional<int> altura(T chave) const{
        Nodo<T>* nodo_chave = nodo_chave_aux(chave);
        if(altura_aux(nodo_chave) == 0){
            return std::nullopt;
        }
        return altura_aux(nodo_chave) -1;
    };

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
    };

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
        bool check = false;                   
        Nodo<int> *nodo = new Nodo<int>(); 
        nodo->chave = chave;               
        nodo->filhoDireita = nullptr;
        nodo->filhoEsquerda = nullptr;

        Nodo<T> *raiz = this->_raiz;
        if (raiz == NULL){
        raiz = nodo;
        this->_raiz = nodo;
        }else{
            while (raiz && check == false){
                if (raiz->chave < chave){
                    if (raiz->filhoDireita == NULL){
                        raiz->filhoDireita = nodo; 
                        check = true;
                    } else{
                        raiz = raiz->filhoDireita;
                    }
                } else if (raiz->chave > chave){
                    if (raiz->filhoEsquerda == NULL){
                        raiz->filhoEsquerda = nodo; 
                        check = true;
                    } else{
                        raiz = raiz->filhoEsquerda; 
                    }
                }
            }
        }
    };

    void remover(T chave){
        this->_raiz = remover_aux(this->_raiz, chave);
    };

    Nodo<T>* remover_aux (Nodo<T>* nodo, T chave){   
        if(nodo == NULL){
            return nodo;
        }else if(chave < nodo->chave){
            nodo->filhoEsquerda = remover_aux(nodo->filhoEsquerda, chave);
        }else if (chave > nodo->chave){
            nodo->filhoDireita = remover_aux(nodo->filhoDireita, chave);
        }else{
            if(nodo->filhoEsquerda == NULL && nodo->filhoDireita == NULL){
                delete nodo;
                return nullptr;
            }else if(nodo->filhoEsquerda == NULL){
                Nodo<T>*removendo_esquerda = nodo;
                nodo = nodo->filhoDireita;
                delete removendo_esquerda;
                return nodo;
            }else if (nodo->filhoDireita == NULL){
                Nodo<T>*removendo_direita = nodo;
                nodo = nodo->filhoEsquerda;
                delete removendo_direita;
                return nodo;
            }else{
                Nodo<T>*removendo_2 = min(nodo->filhoDireita);
                nodo->chave= removendo_2->chave;
                nodo->filhoDireita = remover_aux(nodo->filhoDireita,nodo->chave);
                return nodo;
            }
        }
        return nodo;
    };

   Nodo<T>* min(Nodo<T>* minimo){
        if(minimo == NULL){
            return NULL;
        }else if(minimo->filhoEsquerda == NULL){
            return minimo;
        }else{
            return min(minimo->filhoEsquerda);
        }
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
        ListaEncadeadaAbstrata<T>*lista_ordem = new MinhaListaEncadeada<T>;
        return emordem_aux(this->_raiz, lista_ordem);
    };
    
    ListaEncadeadaAbstrata<T>* emordem_aux (Nodo<T>*nodo, ListaEncadeadaAbstrata<T>*lista_emordem) const {
        if(nodo){
            if(nodo->filhoEsquerda){
                emordem_aux(nodo->filhoEsquerda, lista_emordem);
            }
            lista_emordem->adicionaNoFim(nodo->chave);
            if(nodo->filhoDireita){
                emordem_aux(nodo->filhoDireita, lista_emordem);
            }
        }
        return lista_emordem;
    };


    ListaEncadeadaAbstrata<T>* preOrdem() const{
        ListaEncadeadaAbstrata<T>*lista_ordem2 = new MinhaListaEncadeada<T>;
        return preordem_aux(this->_raiz, lista_ordem2);
    };

    ListaEncadeadaAbstrata<T>* preordem_aux (Nodo<T>*nodo, ListaEncadeadaAbstrata<T>*lista_preordem) const {
        if(nodo)
        {
            lista_preordem->adicionaNoFim(nodo->chave);
            if (nodo->filhoEsquerda)
            {
                preordem_aux(nodo->filhoEsquerda, lista_preordem);
            }
            if (nodo->filhoDireita)
            {
                preordem_aux(nodo->filhoDireita, lista_preordem);
            }
        }
            return lista_preordem;
    };

    ListaEncadeadaAbstrata<T>* posOrdem() const{
        ListaEncadeadaAbstrata<T>*lista_ordem3 = new MinhaListaEncadeada<T>;
        return posordem_aux(this->_raiz, lista_ordem3);
    };

    ListaEncadeadaAbstrata<T>* posordem_aux (Nodo<T>*nodo, ListaEncadeadaAbstrata<T>*lista_posordem) const {
        if (nodo)
        {
            if (nodo->filhoEsquerda)
            {
                posordem_aux(nodo->filhoEsquerda, lista_posordem);
            }
            if (nodo->filhoDireita)
            {
                posordem_aux(nodo->filhoDireita, lista_posordem);
            }
            
            lista_posordem->adicionaNoFim(nodo->chave);
        }
        return lista_posordem;
    };
};

#endif
