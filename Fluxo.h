//
// Created by camil on 13/01/2018.
//

#ifndef PROJETOAPISISTEMA_FLUXO_H
#define PROJETOAPISISTEMA_FLUXO_H

#include "Sistema.h"

class Fluxo {
private:
    string nome;
    Sistema *origem;
    Sistema *destino;
public:
    Fluxo();

    Fluxo(string, Sistema *, Sistema *);

    Fluxo &operator=(const Fluxo &);

    virtual ~Fluxo();

    virtual double executa()=0;

    const string &getNome() const;

    Sistema *getOrigem() const;

    Sistema *getDestino() const;

    void setNome(const string &nome);

    void setOrigem(Sistema *origem);

    void setDestino(Sistema *destino);

    bool operator==(const Fluxo &rhs) const;

    bool operator!=(const Fluxo &rhs) const;

};


#endif //PROJETOAPISISTEMA_FLUXO_H
