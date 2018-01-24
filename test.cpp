//
// Created by camil on 14/01/2018.
//

#include <iostream>
#include <cassert>
#include <cmath>
#include "Modelo.h"
#include "ModeloImp.h"
#include "SistemaImp.h"
#include "FluxoImp.h"

using namespace std;

void testarUnitario() {

    class FluxoTeste : public FluxoImp {
    public:
        double executa() {
            return 10;
        }
    };

    //Sistema
    Sistema *sistema1 = new SistemaImp();
    //Construtor Padrao
    assert(sistema1->getNome() == "");
    assert(sistema1->getValor() == 0);
    //Construtor Atributos
    Sistema *sistema2 = new SistemaImp("sistema2", 12);
    assert(sistema2->getNome() == "sistema2");
    assert(sistema2->getValor() == 12);
    //Set Get
    sistema1->setNome("sistema1");
    assert(sistema1->getNome() == "sistema1");
    sistema1->setValor(55);
    assert(sistema1->getValor() == 55);
    //Operadores
    Sistema *sistema3 = new SistemaImp();
    assert(*sistema1 != *sistema2);
    sistema2 = sistema1;
    assert(sistema1 == sistema2);
    sistema1->setValor(100);
    sistema3->setValor(80);
    assert(sistema1 > sistema3);
    assert(sistema3 < sistema1);

    //Fluxo
    FluxoTeste *fluxo1 = new FluxoTeste();
    //Construtor Padrao
    assert(fluxo1->getNome() == "");
    assert(fluxo1->getOrigem() == nullptr);
    assert(fluxo1->getDestino() == nullptr);
    //Set Get
    fluxo1->setNome("fluxo1");
    assert(fluxo1->getNome() == "fluxo1");
    fluxo1->setOrigem(sistema1);
    assert(fluxo1->getOrigem() == sistema1);
    fluxo1->setDestino(sistema2);
    assert(fluxo1->getDestino() == sistema2);
    //Operadores
    FluxoTeste *fluxo2 = new FluxoTeste();
    assert(fluxo1 != fluxo2);
    fluxo2 = fluxo1;
    assert(fluxo1 == fluxo2);

    //Modelo
    Modelo *modelo1 = new ModeloImp();
    //Construtor Padrao
    assert(modelo1->getNome() == "");
    //Set Get
    vector<Fluxo *> f1;
    vector<Sistema *> s1;
    modelo1->setNome("modelo1");
    assert(modelo1->getNome() == "modelo1");
    modelo1->setFluxos(f1);
    assert(modelo1->getFluxos() == f1);
    modelo1->setSistemas(s1);
    assert(modelo1->getSistemas() == s1);
    //Adicionar e remover
    FluxoTeste *f2 = new FluxoTeste();
    f2->setNome("FluxoTeste1");
    Sistema *s2 = new SistemaImp();
    s2->setNome("SistemaTeste1");
    modelo1->adicionar(f2);
    assert(modelo1->getFluxo("FluxoTeste1") == f2);
    modelo1->adicionar(s2);
    assert(modelo1->getSistema("SistemaTeste1") == s2);

    modelo1->remover(f2);
    assert(modelo1->getFluxo("FluxoTeste1") == nullptr);
    modelo1->remover(s2);
    assert(modelo1->getSistema("SistemaTeste1") == nullptr);
    //Operadores
    Modelo *modelo2 = new ModeloImp();
    assert(modelo1 != modelo2);
    modelo1 = modelo2;
    assert(modelo1 == modelo2);

    //Executar
    sistema1->setValor(10);
    sistema2->setValor(100);
    fluxo1->setOrigem(sistema1);
    fluxo1->setDestino(sistema2);
    modelo1->adicionar(fluxo1);
    modelo1->executar(1);
    assert(fluxo1->getOrigem()->getValor() == 0);
    assert(fluxo1->getDestino()->getValor() == 110);
    cout << "TESTES UNITARIOS COMPLETADOS" << endl;

}

int testarFuncional() {
    class Exponencial : public FluxoImp {
    public:
        double executa() {
            return this->getOrigem()->getValor() * 1.01;
        }
    };

    class Logaritimo : public FluxoImp {
    public:
        double executa() {
            return this->getOrigem()->getValor() * 0.95;
        }
    };
    Fluxo *fluxo1 = new Exponencial();
    Fluxo *fluxo2 = new Logaritimo();
    Modelo *modeloTeste1 = new ModeloImp();
    Sistema *sistemaTeste1 = new SistemaImp("SistemaTeste1", 100);
    Sistema *sistemaTeste2 = new SistemaImp("SistemaTeste2", 10);
    fluxo1->setOrigem(sistemaTeste1);
    fluxo1->setDestino(sistemaTeste2);
    fluxo2->setOrigem(sistemaTeste2);
    fluxo2->setDestino(sistemaTeste1);
    modeloTeste1->adicionar(fluxo1);
    modeloTeste1->adicionar(fluxo2);
    modeloTeste1->executar(2);
    assert(sistemaTeste2->getValor() - 16.66 <= 0.0001);
    cout << "TESTE FUNCIONAL COMPLETO" << endl;
    return 0;

}

int main() {
    testarUnitario();
    testarFuncional();
    return 0;
}


