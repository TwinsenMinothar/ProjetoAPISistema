//
// Created by camil on 13/01/2018.
//

#ifndef PROJETOAPISISTEMA_MODELO_H
#define PROJETOAPISISTEMA_MODELO_H

#include "Fluxo.h"
#include <vector>

using std::vector;

class Modelo {
public:

    virtual const string &getNome() const =0;

    virtual void setNome(const string &nome)=0;

    virtual const vector<Fluxo *> &getFluxos() const =0;

    virtual void setFluxos(const vector<Fluxo *> &fluxos)=0;

    virtual const vector<Sistema *> &getSistemas() const =0;

    virtual void setSistemas(const vector<Sistema *> &sistemas)=0;

    virtual bool operator==(const Modelo &rhs) const =0;

    virtual bool operator!=(const Modelo &rhs) const =0;

    virtual Modelo &operator=(const Modelo &)=0;

    virtual bool adicionar(Fluxo *fluxo)=0;

    virtual bool adicionar(Sistema *sistema)=0;

    virtual bool remover(Fluxo *fluxo)=0;

    virtual bool remover(Sistema *sistema)=0;

    virtual Fluxo *getFluxo(string)=0;

    virtual Sistema *getSistema(string)=0;

    virtual bool executar(int)=0;
};


#endif //PROJETOAPISISTEMA_MODELO_H
