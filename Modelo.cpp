//
// Created by camil on 13/01/2018.
//

#include "Modelo.h"

const string &Modelo::getNome() const {
    return nome;
}

void Modelo::setNome(const string &nome) {
    Modelo::nome = nome;
}

const vector<Fluxo *> &Modelo::getFluxos() const {
    return fluxos;
}

void Modelo::setFluxos(const vector<Fluxo *> &fluxos) {
    Modelo::fluxos = fluxos;
}

const vector<Sistema *> &Modelo::getSistemas() const {
    return sistemas;
}

void Modelo::setSistemas(const vector<Sistema *> &sistemas) {
    Modelo::sistemas = sistemas;
}

bool Modelo::operator==(const Modelo &rhs) const {
    return nome == rhs.nome &&
           fluxos == rhs.fluxos &&
           sistemas == rhs.sistemas;
}

bool Modelo::operator!=(const Modelo &rhs) const {
    return !(rhs == *this);
}

Modelo::Modelo() {
    this->nome = "";
}

Modelo::Modelo(string nome, vector<Fluxo *> fluxos, vector<Sistema *> sistemas) {
    this->nome = nome;
    this->fluxos = fluxos;
    this->sistemas = sistemas;
}

Modelo &Modelo::operator=(const Modelo &modelo) {
    this->nome = modelo.nome;
    this->fluxos = modelo.fluxos;
    this->sistemas = modelo.sistemas;
    return *this;
}

bool Modelo::adicionar(Fluxo *fluxo) {
    auto size = this->fluxos.size();
    this->fluxos.push_back(fluxo);
    return size + 1 == this->fluxos.size();
}

bool Modelo::adicionar(Sistema *sistema) {
    auto size = this->sistemas.size();
    this->sistemas.push_back(sistema);
    return size + 1 == this->sistemas.size();
}

bool Modelo::remover(Fluxo *fluxo) {
    for (auto it = this->fluxos.begin(); it != this->fluxos.end(); it++) {
        if (*it == fluxo) {
            this->fluxos.erase(it);
            return true;
        }
    }
    return false;
}

bool Modelo::remover(Sistema *sistema) {
    for (auto it = this->sistemas.begin(); it != this->sistemas.end(); it++) {
        if (*it == sistema) {
            this->sistemas.erase(it);
            return true;
        }
    }
    return false;
}

Fluxo *Modelo::getFluxo(string nomeFluxo) {
    for (auto *fluxo : this->fluxos) {
        if (fluxo->getNome() == nomeFluxo) {
            return fluxo;
        }
    }
    return nullptr;
}

Sistema *Modelo::getSistema(string nomeSistema) {
    for (auto *sistema : this->sistemas) {
        if (sistema->getNome() == nomeSistema) {
            return sistema;
        }
    }
    return nullptr;
}

bool Modelo::executar(int tempo) {
    vector<double> resultado(this->fluxos.size());

    for (auto i = 0; i < tempo; i++) {
        for (auto j = 0; j < this->fluxos.size(); j++) {
            resultado[j] = this->fluxos[j]->executa();
        }

        for (auto j = 0; j < this->fluxos.size(); j++) {
            this->fluxos[j]->getDestino()->setValor(this->fluxos[j]->getDestino()->getValor() + resultado[j]);
            this->fluxos[j]->getOrigem()->setValor(this->fluxos[j]->getOrigem()->getValor() - resultado[j]);
        }
    }
    return true;
}

Modelo::~Modelo() {

}
