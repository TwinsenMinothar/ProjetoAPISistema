//
// Created by camil on 23/01/2018.
//

#include "SistemaImp.h"

SistemaImp::SistemaImp() : Sistema() {
    this->nome = "";
    this->valor = 0;
}

SistemaImp::SistemaImp(string nome, double valor) {
    this->nome = nome;
    this->valor = valor;
}

SistemaImp::SistemaImp(Sistema &sistema) {
    this->nome = sistema.getNome();
    this->valor = sistema.getValor();
}

SistemaImp::~SistemaImp() {

}

Sistema &SistemaImp::operator=(const Sistema &sistema) {
    if (&sistema == this)
        return *this;
    this->nome = sistema.getNome();
    this->valor = sistema.getValor();
    return *this;
}

bool SistemaImp::operator==(const Sistema &rhs) const {
    return nome == rhs.getNome() && valor == rhs.getValor();
}

bool SistemaImp::operator!=(const Sistema &rhs) const {
    return !(rhs == *this);
}

const string &SistemaImp::getNome() const {
    return nome;
}

void SistemaImp::setNome(const string &nome) {
    this->nome = nome;
}

double SistemaImp::getValor() const {
    return valor;
}

void SistemaImp::setValor(double valor) {
    this->valor = valor;
}

bool SistemaImp::operator>(const Sistema &rhs) const {
    return valor > rhs.getValor();
}

bool SistemaImp::operator<=(const Sistema &rhs) const {
    return !(*this >= rhs);
}

bool SistemaImp::operator>=(const Sistema &rhs) const {
    return valor >= rhs.getValor();
}

bool SistemaImp::operator<(const Sistema &rhs) const {
    return !(*this > rhs);
}
