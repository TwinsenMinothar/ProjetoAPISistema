//
// Created by camil on 23/01/2018.
//

#include "FluxoImp.h"

FluxoImp::FluxoImp() {
    this->origem = nullptr;
    this->destino = nullptr;
    this->nome = "";
}

FluxoImp::FluxoImp(string nome, Sistema *origem, Sistema *destino) {
    this->origem = origem;
    this->destino = destino;
    this->nome = nome;
}

Fluxo &FluxoImp::operator=(const Fluxo &fluxo) {
    this->nome = fluxo.getNome();
    this->origem = fluxo.getOrigem();
    this->destino = fluxo.getDestino();
    return *this;
}

FluxoImp::~FluxoImp() {

}

double FluxoImp::executa() {
    return 0;
}

const string &FluxoImp::getNome() const {
    return nome;
}

Sistema *FluxoImp::getOrigem() const {
    return origem;
}

Sistema *FluxoImp::getDestino() const {
    return destino;
}

void FluxoImp::setNome(const string &nome) {
    this->nome = nome;
}

void FluxoImp::setOrigem(Sistema *origem) {
    this->origem = origem;
}

void FluxoImp::setDestino(Sistema *destino) {
    this->destino = destino;
}

bool FluxoImp::operator==(const Fluxo &rhs) const {
    return nome == rhs.getNome() && origem == rhs.getOrigem() && destino == rhs.getDestino();
}

bool FluxoImp::operator!=(const Fluxo &rhs) const {
    return !(rhs == *this);
}
