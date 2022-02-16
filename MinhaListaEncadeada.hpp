#ifndef MINHALISTAENCADEADA_H
#define MINHALISTAENCADEADA_H

#include "ListaEncadeadaAbstrata.hpp"

template <typename T>
class MinhaListaEncadeada :  public ListaEncadeadaAbstrata<T>{
  MinhaListaEncadeada(){
      this->_primeiro = NULL;
      this->_tamanho = 0;
  }

  ~MinhaListaEncadeada(){
    Elemento<T> *ProximoElemento = NULL;
    Elemento<T> *ElementoAuxiliar = this->_primeiro;
    while(ElementoAuxiliar != NULL){
      ProximoElemento = ElementoAuxiliar->proximo;
      delete ElementoAuxiliar;
      ElementoAuxiliar = ProximoElemento;
    }
  };

  std::size_t tamanho() const{
    int count = 0;
    Elemento<T> *atual = this->_primeiro;
    if (atual == NULL){
      return count;
    }
    else{
      while (atual != NULL){
        atual = atual->proximo;
        count++;
      }
    }
    return count;
  };

  bool vazia() const{
    if (this->_primeiro == NULL){
      return true;
    }
    else{
      return false;
    }
  };

  std::size_t posicao(T dado) const{
    if(this->_tamanho == 0){
      throw lista_encadeada_vazia_exception();
    }
    else{
      Elemento<T> *ElementoAuxiliar = this->_primeiro;
      size_t indice = 0;
      while (ElementoAuxiliar != NULL){
        if(dado == ElementoAuxiliar->dado){
          return indice;
        }
        indice++;
        ElementoAuxiliar = ElementoAuxiliar->proximo;
      }
      if(ElementoAuxiliar == NULL){
        throw nao_implementado_exception();
      } 
      return 0;
    }
  };

  bool contem(T dado) const{
    Elemento<T> *ElemAtual = (this->_primeiro);
      while(ElemAtual != NULL){
        if (ElemAtual->dado == dado){
          return true;
        }
        ElemAtual = ElemAtual->proximo;
      }
      return false;
  };

  void inserirNoInicio(T dado){
    Elemento<T> *novoElemento = new Elemento<T>(dado, nullptr);
    novoElemento->proximo = this->_primeiro;
    this->_primeiro = novoElemento;
    this->_tamanho++;
  };

  void inserir(size_t posicao, T dado){
    if(posicao == 0 and tamanho() >= 0){
      inserirNoInicio(dado);
    }
    else if (posicao < 0 or posicao > tamanho()){
      throw nao_implementado_exception();
    }
    else if(posicao == tamanho()){
      inserirNoFim(dado);
    }
    else{
      int aux = 0;
      Elemento<T> *ElementoAuxiliar = this->_primeiro ;
      while(aux < posicao - 1 and ElementoAuxiliar->proximo != NULL and ElementoAuxiliar != NULL){
        ElementoAuxiliar = ElementoAuxiliar->proximo;
        aux++;
      };
      Elemento<T> *NovoElemento = new Elemento<T>(dado, nullptr);
      NovoElemento->proximo = ElementoAuxiliar->proximo;
      ElementoAuxiliar->proximo = NovoElemento;
      this->_tamanho++;
    }
    return;
  };

  void inserirNoFim(T dado){
    if(this->_primeiro == NULL){
      inserirNoInicio(dado);
      return;
    }
    else{
      Elemento<T> *NovoElemento = new Elemento<T>(dado, nullptr);
      NovoElemento->proximo = NULL;
      Elemento<T> *UltimoElemento = this->_primeiro;
      while (UltimoElemento->proximo != NULL){
        UltimoElemento = UltimoElemento->proximo;
      }
      UltimoElemento->proximo = NovoElemento;
      this->_tamanho++;
      return;
    }
  };

  T removerDoInicio(){
    if(this->_tamanho == 0){
      throw lista_encadeada_vazia_exception();
    }
    else{
      Elemento<T> *ElementoAuxiliar = this->_primeiro;
      T dadoAux = ElementoAuxiliar->dado;
      this->_primeiro = this->_primeiro->proximo;
      delete ElementoAuxiliar;
      this->_tamanho--;
      return dadoAux;
    }
  };

  T removerDe(size_t posicao){
    if (vazia()){
      throw nao_implementado_exception();
    }
    else if(posicao < 0 or posicao >= tamanho()){
      throw nao_implementado_exception();
    }
    else if (posicao == 0){
      return removerDoInicio();
    }
    else{
      Elemento<T> *ElementoAuxiliar = this->_primeiro;
      for (int i = 0; ElementoAuxiliar != NULL and i < posicao-1; i++){
        ElementoAuxiliar = ElementoAuxiliar->proximo;
      }
      if (ElementoAuxiliar->proximo->proximo == NULL){
        return removerDoFim(); 
      }
      else if (ElementoAuxiliar != NULL or ElementoAuxiliar->proximo != NULL){
        Elemento<T> *ElementoDeleta = ElementoAuxiliar->proximo;
        ElementoAuxiliar->proximo = ElementoAuxiliar->proximo->proximo;
        T aux = ElementoDeleta->dado;
        delete ElementoDeleta;
        this->_tamanho--;
        return aux;
      }
    }
    return 0;
  };

  T removerDoFim(){
    Elemento<T> *ElementoAuxiliar = this->_primeiro;
    if (this->_primeiro == NULL){
      throw lista_encadeada_vazia_exception();
    }
    else if (ElementoAuxiliar->proximo == NULL){
      return removerDoInicio();
    }
    else{
      while (ElementoAuxiliar->proximo->proximo != NULL){
        ElementoAuxiliar = ElementoAuxiliar->proximo;
      }
      Elemento<T> *ultimoElemento = ElementoAuxiliar->proximo;
      T DadoRemovido = ultimoElemento->dado;
      delete ultimoElemento;
      ElementoAuxiliar->proximo = NULL;
      this->_tamanho--;
      return DadoRemovido;
    }
    return 0;
  };

  void remover(T dado){
    if(this->_primeiro == NULL){
      throw lista_encadeada_vazia_exception();
    }
    else if(contem(dado) == false){
      throw nao_implementado_exception();
    }
    else{
      size_t indice = posicao(dado);
      removerDe(indice);
    } 
  };
};

#endif