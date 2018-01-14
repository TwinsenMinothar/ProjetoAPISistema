//
// Created by camil on 13/01/2018.
//

#include "Sistema.h"

Sistema &Sistema::operator=(const Sistema &sistema) {
    this->nome = sistema.nome;
    this->valor = sistema.valor;
    return *this;
}

bool Sistema::operator==(const Sistema &rhs) const {
    return nome == rhs.nome &&
           valor == rhs.valor;
}

bool Sistema::operator!=(const Sistema &rhs) const {
    return !(rhs == *this);
}

const string &Sistema::getNome() const {
    return nome;
}

void Sistema::setNome(const string &nome) {
    Sistema::nome = nome;
}

double Sistema::getValor() const {
    return valor;
}

void Sistema::setValor(double valor) {
    Sistema::valor = valor;
}

bool Sistema::operator>(const Sistema &rhs) const {
    return rhs < *this;
}

bool Sistema::operator<(const Sistema &rhs) const {
    return valor < rhs.valor;
}

bool Sistema::operator<=(const Sistema &rhs) const {
    return !(rhs < *this);
}

bool Sistema::operator>=(const Sistema &rhs) const {
    return !(*this < rhs);
}

Sistema::Sistema() {
    this->nome = "";
    this->valor = 0;
}

Sistema::Sistema(string nome, double valor) {
    this->nome = nome;
    this->valor = valor;
}

Sistema::Sistema(Sistema &sistema) {
    this->nome = sistema.nome;
    this->valor = sistema.valor;
}

Sistema::~Sistema() {

}
