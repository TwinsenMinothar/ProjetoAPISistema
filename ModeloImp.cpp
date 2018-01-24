//
// Created by camil on 23/01/2018.
//

#include "ModeloImp.h"

ModeloImp::ModeloImp() {
    nome = "";
}

ModeloImp::ModeloImp(string nome, vector<Fluxo *> fluxos, vector<Sistema *> sistemas) {
    this->nome = nome;
    this->fluxos = fluxos;
    this->sistemas = sistemas;
}

ModeloImp::~ModeloImp() {

}

const string &ModeloImp::getNome() const {
    return nome;
}

void ModeloImp::setNome(const string &nome) {
    this->nome = nome;
}

const vector<Fluxo *> &ModeloImp::getFluxos() const {
    return fluxos;
}

void ModeloImp::setFluxos(const vector<Fluxo *> &fluxos) {
    this->fluxos = fluxos;
}

const vector<Sistema *> &ModeloImp::getSistemas() const {
    return sistemas;
}

void ModeloImp::setSistemas(const vector<Sistema *> &sistemas) {
    this->sistemas = sistemas;
}

bool ModeloImp::operator==(const Modelo &rhs) const {
    return (nome == rhs.getNome() && fluxos == rhs.getFluxos() && sistemas == rhs.getSistemas());
}

bool ModeloImp::operator!=(const Modelo &rhs) const {
    return !(*this == rhs);
}

Modelo &ModeloImp::operator=(const Modelo &modelo) {
    if (this == &modelo)
        return *this;
    nome = modelo.getNome();
    fluxos = modelo.getFluxos();
    sistemas = modelo.getSistemas();
    return *this;
}

bool ModeloImp::adicionar(Fluxo *fluxo) {
    auto size = fluxos.size();
    fluxos.push_back(fluxo);
    return size + 1 == fluxos.size();
}

bool ModeloImp::adicionar(Sistema *sistema) {
    auto size = sistemas.size();
    sistemas.push_back(sistema);
    return size + 1 == sistemas.size();
}

bool ModeloImp::remover(Fluxo *fluxo) {
    for (auto it = fluxos.begin(); it != fluxos.end(); it++) {
        if (*it == fluxo) {
            fluxos.erase(it);
            return true;
        }
    }
    return false;
}

bool ModeloImp::remover(Sistema *sistema) {
    for (auto it = sistemas.begin(); it != sistemas.end(); it++) {
        if (*it == sistema) {
            sistemas.erase(it);
            return true;
        }
    }
    return false;
}

Fluxo *ModeloImp::getFluxo(string nomeFluxo) {
    for (auto *fluxo : fluxos) {
        if (fluxo->getNome() == nomeFluxo) {
            return fluxo;
        }
    }
    return nullptr;
}

Sistema *ModeloImp::getSistema(string nomeSistema) {
    for (auto *sistema : this->sistemas) {
        if (sistema->getNome() == nomeSistema) {
            return sistema;
        }
    }
    return nullptr;
}

bool ModeloImp::executar(int tempo) {
    vector<double> resultado(fluxos.size());
    for (auto i = 0; i < tempo; i++) {
        for (auto j = 0; j < fluxos.size(); j++) {
            resultado[j] = fluxos[j]->executa();
        }
        for (auto j = 0; j < fluxos.size(); j++) {
            fluxos[j]->getDestino()->setValor(fluxos[j]->getDestino()->getValor() + resultado[j]);
            fluxos[j]->getOrigem()->setValor(fluxos[j]->getOrigem()->getValor() - resultado[j]);
        }
    }
    return true;
}
