//
// Created by camil on 13/01/2018.
//

#include "Fluxo.h"


Fluxo::Fluxo() {
    this->origem = nullptr;
    this->destino = nullptr;
    this->nome = "";
}

Fluxo::Fluxo(string nome, Sistema *origem, Sistema *destino) {
    this->origem = origem;
    this->destino = destino;
    this->nome = nome;
}

Fluxo &Fluxo::operator=(const Fluxo &fluxo) {
    this->nome = fluxo.nome;
    this->origem = fluxo.origem;
    this->destino = fluxo.destino;
    return *this;
}

const string &Fluxo::getNome() const {
    return nome;
}

Sistema *Fluxo::getOrigem() const {
    return origem;
}

Sistema *Fluxo::getDestino() const {
    return destino;
}

void Fluxo::setNome(const string &nome) {
    Fluxo::nome = nome;
}

void Fluxo::setOrigem(Sistema *origem) {
    Fluxo::origem = origem;
}

void Fluxo::setDestino(Sistema *destino) {
    Fluxo::destino = destino;
}

bool Fluxo::operator==(const Fluxo &rhs) const {
    return nome == rhs.nome &&
           origem == rhs.origem &&
           destino == rhs.destino;
}

bool Fluxo::operator!=(const Fluxo &rhs) const {
    return !(rhs == *this);
}


Fluxo::~Fluxo() {

}
