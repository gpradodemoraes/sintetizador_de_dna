#include "sintetizadorDNA.h"
#define FMT_HEADER_ONLY
#include <fmt/core.h>

int main() {
    sequencia_log root{};
    root.parent = nullptr;
    root.operacao = std::string("INICIO");

    std::string inicial{"A"};
    std::string final{"TATA"};

    if (sintetizadorDNA(&inicial, &final, 0, 20, &root)) {
        fmt::println("É possível sintetizar essa sequência.");
    } else {
        fmt::println("Não é possível sintetizar essa sequência.");
    }
    //print_memorizacao();
    return 0;
}