#include "sintetizadorDNA.h"
#define FMT_HEADER_ONLY
#include <fmt/core.h>

static void print_all_substrings(std::string in) {
    const int length = in.length();

    for (int i = 0; i < length; i++)
        for (int k = 1; k < length - i + 1; k++)
            fmt::println("{}/{}={}", i,k,in.substr(i, k));
}
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