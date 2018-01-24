//
// Created by camil on 23/01/2018.
//

#ifndef PROJETOAPISISTEMA_MODELOIMP_H
#define PROJETOAPISISTEMA_MODELOIMP_H

#include "Fluxo.h"
#include "Modelo.h"
#include <vector>
using std::vector;

class ModeloImp : public Modelo {
private:
    string nome;
    vector<Fluxo *> fluxos;
    vector<Sistema *> sistemas;

public:
    ModeloImp();

    ModeloImp(string string1, vector<Fluxo *> vector1, vector<Sistema *> vector2);

    virtual ~ModeloImp();

    const string &getNome() const override;

    void setNome(const string &nome) override;

    const vector<Fluxo *> &getFluxos() const override;

    void setFluxos(const vector<Fluxo *> &fluxos) override;

    const vector<Sistema *> &getSistemas() const override;

    void setSistemas(const vector<Sistema *> &sistemas) override;

    bool operator==(const Modelo &rhs) const override;

    bool operator!=(const Modelo &rhs) const override;

    Modelo &operator=(const Modelo &modelo) override;

    bool adicionar(Fluxo *fluxo) override;

    bool adicionar(Sistema *sistema) override;

    bool remover(Fluxo *fluxo) override;

    bool remover(Sistema *sistema) override;

    Fluxo *getFluxo(string string1) override;

    Sistema *getSistema(string string1) override;

    bool executar(int i) override;
};


#endif //PROJETOAPISISTEMA_MODELOIMP_H
