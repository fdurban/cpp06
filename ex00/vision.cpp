#include <iostream>
#include <iomanip>
#include <bitset>

// Unión para acceder a los bits reales del float
union FloatConverter {
    float f;
    uint32_t bits;
};

void printFloatDetails(float val) {
    FloatConverter conv;
    conv.f = val;

    // Desglosamos los bits según el estándar IEEE 754
    // 1 bit de signo (bit 31)
    unsigned int sign = (conv.bits >> 31) & 1;
    // 8 bits de exponente (bits 30 a 23)
    unsigned int exponent = (conv.bits >> 23) & 0xFF;
    // 23 bits de mantisa (bits 22 a 0)
    unsigned int mantissa = conv.bits & 0x7FFFFF;

    std::cout << "VALOR: " << std::fixed << std::setprecision(1) << val << std::endl;
    std::cout << "Signo:     " << sign << std::endl;
    std::cout << "Exponente: " << (int)exponent - 127 << " (bits: " << std::bitset<8>(exponent) << ")" << std::endl;
    // Mostramos la mantisa con el "1." implícito para que se entienda mejor
    std::cout << "Mantisa:   1." << std::bitset<23>(mantissa) << " (binario)" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}

int main() {
    // Caso 1: Justo en el límite (2^24)
    std::cout << "--- LÍMITE DE PRECISIÓN (16,777,216) ---" << std::endl;
    printFloatDetails(16777216.0f);

    // Caso 2: El impar que el float "no ve" (redondea al anterior)
    std::cout << "--- INTENTO DE IMPAR (16,777,217) ---" << std::endl;
    printFloatDetails(16777217.0f);

    // Caso 3: El siguiente par que sí existe
    std::cout << "--- SIGUIENTE PAR (16,777,218) ---" << std::endl;
    printFloatDetails(16777218.0f);

    return 0;
}
