//
// Created by camil on 23/01/2018.
//

#ifndef PROJETOAPISISTEMA_FLUXOIMP_H
#define PROJETOAPISISTEMA_FLUXOIMP_H


#include "Fluxo.h"
#include "SistemaImp.h"

class FluxoImp : public Fluxo {
protected:
    string nome;
    Sistema *origem;
    Sistema *destino;
public:

    FluxoImp();

    FluxoImp(string string1, Sistema *sistema, Sistema *sistema1);

    Fluxo &operator=(const Fluxo &fluxo) override;

    virtual ~FluxoImp();

    double executa() override;

    const string &getNome() const override;

    Sistema *getOrigem() const override;

    Sistema *getDestino() const override;

    void setNome(const string &nome) override;

    void setOrigem(Sistema *origem) override;

    void setDestino(Sistema *destino) override;

    bool operator==(const Fluxo &rhs) const override;

    bool operator!=(const Fluxo &rhs) const override;


};


#endif //PROJETOAPISISTEMA_FLUXOIMP_H
