#include "sintetizadorDNA.h"
#define FMT_HEADER_ONLY
#include <fmt/core.h>

int main() {
    print_memorizacao();
    if (sintetizadorDNA("A", "TATA", 0, 20)) {
        fmt::println("É possível sintetizar essa sequência.");
    } else {
        fmt::println("Não é possível sintetizar essa sequência.");
    }
    return 0;
}