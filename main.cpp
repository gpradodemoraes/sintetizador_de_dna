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
    print_all_substrings("G");
    return 0;
    print_memorizacao();
    if (sintetizadorDNA("A", "TATA", 0, 20)) {
        fmt::println("É possível sintetizar essa sequência.");
    } else {
        fmt::println("Não é possível sintetizar essa sequência.");
    }
    return 0;
}