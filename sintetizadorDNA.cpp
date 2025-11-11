//
// Created by gabriel.moraes on 11/11/2025.
//
#include "sintetizadorDNA.h"
#include <map>
#define FMT_HEADER_ONLY
#include <fmt/core.h>

static std::map<std::string, sequencia*> memorizacaoDeCustos = {
    { "A:AT", new sequencia{"A","AT", 2} },
    { "G:GC", new sequencia{"G", "GC", 2} },
    { "TT:A", new sequencia{"TT", "A", 5} },
    { "CG:G", new sequencia{"CG", "G", 1} },
    { "AT:TA", new sequencia{"AT", "TA", 1} },
    { "C:G", new sequencia{"C", "G", 3} },
    { "T:A", new sequencia{"T", "A", 3} },
    { "AGA:C", new sequencia{"AGA", "C", 8} },
    { "CC:G", new sequencia{"CC", "G", 4} },
    { "TATA:GC", new sequencia{"TATA", "GC", 10} },
};

static void print_operacao(sequencia_log *l) {
    if (l != nullptr) {
        fmt::println("OP: {}", l->operacao);
        print_operacao(l->parent);
    }
}
void print_memorizacao() {
    for (auto i : memorizacaoDeCustos) {
        fmt::println("{} => [{}=>{} ({})]", i.first,
            i.second->sequenciaInicial,
            i.second->sequenciaFinal,
            i.second->custo);
    }
}

bool sintetizadorDNA(const std::string* sequencia_atual,
    const std::string* sequencia_final,
    const unsigned int custo_atual,
    const unsigned int MAX_CUSTO,
    sequencia_log* parent) {
    const auto length = sequencia_atual->length();

    // SEQUENCIA ATUAL: ATTT
    // SEQUENCIA FINAL: TATA
    // custo_atual: 2+2+2
    for (int i = 0; i < length; i++)
        for (int k = 1; k < length - i + 1; k++) {
            std::string s = sequencia_atual->substr(i, k);
            fmt::println("{}/{}={}", i,k,s);
            std::string key = s + ":" + *sequencia_final;
            // key = TT:TATA onde TT vem de A(TT)T
            try {
                sequencia* seq = memorizacaoDeCustos.at(key);
                // existe uma sequência que chega na string final sem ultrapassar os custos. Retornar true
                if(seq->custo + custo_atual <= MAX_CUSTO) {
                    sequencia_log* log = new sequencia_log;
                    log->parent = parent;
                    std::string operacao = fmt::format("{} {} => {} ({}/{})", seq->sequenciaInicial, s, seq->sequenciaFinal, seq->custo, custo_atual + seq->custo);
                    log->operacao = operacao;

                    return true;
                }
            } catch (std::out_of_range& e) {
            }
            // Não tem na memorização AINDA uma sequência que chega na string final.
            // Ela pode existir ou pode não existir.
            // Vamos percorrer o map calculando todas as sequencias começando no nosso substring atual s = "TT"
            for (const auto& iterator: memorizacaoDeCustos) {
                // s = TT
                sequencia* pSequencia = iterator.second;
                if (pSequencia->sequenciaInicial == s) {
                    // encontramos o elemento no mapa "TT:A"
                    // vamos fazer a substiuição de TT na sequencia_atual A(TT)T onde i = 1 e k = 2
                    // o resultado final deve ser A(TT)T => A(A)T
                    std::string new_sequencia_atual;
                    for (int j = 0; j < i; j++)
                        new_sequencia_atual.push_back((*sequencia_atual)[j]);
                    new_sequencia_atual.append(pSequencia->sequenciaFinal);
                    for (int j = i + k; j < length; j++)
                        new_sequencia_atual.push_back((*sequencia_atual)[j]);
                    // ATTT TT => AAT 5/20
                    std::string operacao = fmt::format("{} {} => {} ({}/{})", *sequencia_atual,s,  new_sequencia_atual, pSequencia->custo, custo_atual + pSequencia->custo);
                    memorizacaoDeCustos.insert( { *sequencia_atual + ":" + new_sequencia_atual,
                        new sequencia{s, new_sequencia_atual, pSequencia->custo }});
                    if (pSequencia->custo + custo_atual > MAX_CUSTO) {
                        // Não precisamos seguir adiante!
                        continue;
                    }
                    auto* log = new sequencia_log;
                    log->parent = parent;
                    log->operacao = operacao;
                    if (!sintetizadorDNA(&new_sequencia_atual, sequencia_final, pSequencia->custo + custo_atual, MAX_CUSTO, log)) {
                        // achamos uma solução! Não precisamos fazer mais nada
                        // vamos retornar true para encerrar!
                    } else {
                        // Não achamos a solução! Vamos continuar tentando opções!
                    }

                }

            }

        }
    return false;
}
