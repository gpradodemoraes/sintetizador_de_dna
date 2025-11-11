//
// Created by gabriel.moraes on 11/11/2025.
//
#pragma once
#include <string>

struct sequencia {
    std::string sequenciaInicial;
    std::string sequenciaFinal;
    unsigned int custo;
};

void print_memorizacao();
bool sintetizadorDNA(std::string* sequencia_atual,
    std::string* sequencia_final,
    unsigned int custo_atual,
    unsigned int MAX_CUSTO);
