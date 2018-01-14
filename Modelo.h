//
// Created by camil on 13/01/2018.
//

#ifndef PROJETOAPISISTEMA_MODELO_H
#define PROJETOAPISISTEMA_MODELO_H

#include "Fluxo.h"
#include <vector>

using std::vector;

class Modelo {
private:
    string nome;
    vector<Fluxo *> fluxos;
    vector<Sistema *> sistemas;
public:
    Modelo();

    Modelo(string, vector<Fluxo *>, vector<Sistema *>);

    virtual ~Modelo();

    const string &getNome() const;

    void setNome(const string &nome);

    const vector<Fluxo *> &getFluxos() const;

    void setFluxos(const vector<Fluxo *> &fluxos);

    const vector<Sistema *> &getSistemas() const;

    void setSistemas(const vector<Sistema *> &sistemas);

    bool operator==(const Modelo &rhs) const;

    bool operator!=(const Modelo &rhs) const;

    Modelo &operator=(const Modelo &);

    bool adicionar(Fluxo *fluxo);

    bool adicionar(Sistema *sistema);

    bool remover(Fluxo *fluxo);

    bool remover(Sistema *sistema);

    Fluxo* getFluxo(string);

    Sistema* getSistema(string);

    bool executar(int);
};


#endif //PROJETOAPISISTEMA_MODELO_H
