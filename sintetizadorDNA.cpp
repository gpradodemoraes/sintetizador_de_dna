//
// Created by gabriel.moraes on 11/11/2025.
//
#include "sintetizadorDNA.h"
#include <map>
#define FMT_HEADER_ONLY
#include <fmt/core.h>

static std::map<std::string, sequencia> memorizacaoDeCustos = {
    { "A:AT", sequencia{"A","AT", 2} },
    { "G:GC", sequencia{"G", "GC", 2} },
    { "TT:A", sequencia{"TT", "A", 5} },
    { "CG:G", sequencia{"CG", "G", 1} },
    { "AT:TA", sequencia{"AT", "TA", 1} },
    { "C:G", sequencia{"C", "G", 3} },
    { "T:A", sequencia{"T", "A", 3} },
    { "AGA:C", sequencia{"AGA", "C", 8} },
    { "CC:G", sequencia{"CC", "G", 4} },
    { "TATA:GC", sequencia{"TATA", "GC", 10} },
};

void print_memorizacao() {
    for (auto i : memorizacaoDeCustos) {
        fmt::println("{} => [{}=>{} ({})]", i.first,
            i.second.sequenciaInicial,
            i.second.sequenciaFinal,
            i.second.custo);
    }
}