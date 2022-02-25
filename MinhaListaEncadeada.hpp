#ifndef MINHALISTAENCADEADA_H
#define MINHALISTAENCADEADA_H

#include "ListaEncadeadaAbstrata.hpp"

template <typename T>
class MinhaListaEncadeada :  public ListaEncadeadaAbstrata<T>{
  public:
  MinhaListaEncadeada(){
      this->_primeiro = NULL;
      this->_tamanho = 0;
  }

  ~MinhaListaEncadeada(){
    Elemento<T> *proximoElemento = NULL;
    Elemento<T> *ElementoAuxiliar = this->_primeiro;
    while(ElementoAuxiliar != NULL){
      proximoElemento = ElementoAuxiliar->_proximo;
      delete ElementoAuxiliar;
      ElementoAuxiliar = proximoElemento;
    }
  };

  int getTamanho(){
    int count = 0;
    Elemento<T> *atual = this->_primeiro;
    if (atual == NULL){
      return count;
    }
    else{
      while (atual != NULL){
        atual = atual->_proximo;
        count++;
      }
    }
    return count;
  };

  bool estaVazia(){
    if (this->_primeiro == NULL){
      return true;
    }
    else{
      return false;
    }
  };

  int posicao(T umDado){
    if(this->_tamanho == 0){
      throw lista_encadeada_vazia_exception();
    }
    else{
      Elemento<T> *ElementoAuxiliar = this->_primeiro;
      size_t indice = 0;
      while (ElementoAuxiliar != NULL){
        if(umDado == ElementoAuxiliar->_dado){
          return indice;
        }
        indice++;
        ElementoAuxiliar = ElementoAuxiliar->_proximo;
      }
      if(ElementoAuxiliar == NULL){
        throw posicao_invalida_exception();
      } 
      return 0;
    }
  };

  bool contem(T umDado){
    Elemento<T> *ElemAtual = (this->_primeiro);
      while(ElemAtual != NULL){
        if (ElemAtual->_dado == umDado){
          return true;
        }
        ElemAtual = ElemAtual->_proximo;
      }
      return false;
  };

  void adicionaNoInicio(T umDado){
    Elemento<T> *novoElemento = new Elemento<T>;
    novoElemento->_proximo = this->_primeiro;
    novoElemento->_dado = umDado;
    this->_primeiro = novoElemento;
    this->_tamanho++;
  };

  void adicionaNaPosicao(T umDado, int posicao) {
    if(posicao == 0 and getTamanho() >= 0){
      adicionaNoInicio(umDado);
    }
    else if (posicao < 0 or posicao > getTamanho()){
      throw posicao_invalida_exception();
    }
    else if(posicao == getTamanho()){
      adicionaNoFim(umDado);
    }
    else{
      int aux = 0;
      Elemento<T> *ElementoAuxiliar = this->_primeiro ;
      while(aux < posicao - 1 and ElementoAuxiliar->_proximo != NULL and ElementoAuxiliar != NULL){
        ElementoAuxiliar = ElementoAuxiliar->_proximo;
        aux++;
      };
      Elemento<T> *NovoElemento = new Elemento<T>;
      NovoElemento->_dado = umDado;
      NovoElemento->_proximo = ElementoAuxiliar->_proximo;
      ElementoAuxiliar->_proximo = NovoElemento;
      this->_tamanho++;
    }
    return;
  };

  void adicionaNoFim(T umDado){
    if(this->_primeiro == NULL){
      adicionaNoInicio(umDado);
      return;
    }
    else{
      Elemento<T> *NovoElemento = new Elemento<T>;
      NovoElemento->_dado = umDado;
      NovoElemento->_proximo = NULL;
      Elemento<T> *UltimoElemento = this->_primeiro;
      while (UltimoElemento->_proximo != NULL){
        UltimoElemento = UltimoElemento->_proximo;
      }
      UltimoElemento->_proximo = NovoElemento;
      this->_tamanho++;
      return;
    }
  };

  T retiraDoInicio(){
    if(this->_tamanho == 0){
      throw lista_encadeada_vazia_exception();
    }
    else{
      Elemento<T> *ElementoAuxiliar = this->_primeiro;
      T dadoAux = ElementoAuxiliar->_dado;
      this->_primeiro = this->_primeiro->_proximo;
      delete ElementoAuxiliar;
      this->_tamanho--;
      return dadoAux;
    }
  };

  T retiraDaPosicao(int posicao){
    if (estaVazia()){
      throw lista_encadeada_vazia_exception();
    }
    else if(posicao < 0 or posicao >= getTamanho()){
      throw posicao_invalida_exception();
    }
    else if (posicao == 0){
      return retiraDoInicio();
    }
    else{
      Elemento<T> *ElementoAuxiliar = this->_primeiro;
      for (int i = 0; ElementoAuxiliar != NULL and i < posicao-1; i++){
        ElementoAuxiliar = ElementoAuxiliar->_proximo;
      }
      if (ElementoAuxiliar->_proximo->_proximo == NULL){
        return retiraDoFim(); 
      }
      else if (ElementoAuxiliar != NULL or ElementoAuxiliar->_proximo != NULL){
        Elemento<T> *ElementoDeleta = ElementoAuxiliar->_proximo;
        ElementoAuxiliar->_proximo = ElementoAuxiliar->_proximo->_proximo;
        T aux = ElementoDeleta->_dado;
        delete ElementoDeleta;
        this->_tamanho--;
        return aux;
      }
    }
    return 0;
  };

  T retiraDoFim(){
    Elemento<T> *ElementoAuxiliar = this->_primeiro;
    if (this->_primeiro == NULL){
      throw lista_encadeada_vazia_exception();
    }
    else if (ElementoAuxiliar->_proximo == NULL){
      return retiraDoInicio();
    }
    else{
      while (ElementoAuxiliar->_proximo->_proximo != NULL){
        ElementoAuxiliar = ElementoAuxiliar->_proximo;
      }
      Elemento<T> *ultimoElemento = ElementoAuxiliar->_proximo;
      T DadoRemovido = ultimoElemento->_dado;
      delete ultimoElemento;
      ElementoAuxiliar->_proximo = NULL;
      this->_tamanho--;
      return DadoRemovido;
    }
    return 0;
  };

  T retiraEspecifico(T umDado){
    if(this->_primeiro == NULL){
      throw lista_encadeada_vazia_exception();
    }
    else if(contem(umDado) == false){
      throw posicao_invalida_exception();
    }
    else{
      size_t indice = posicao(umDado);
      retiraDaPosicao(indice);
    } 
  return 0;
  };
};

#endif