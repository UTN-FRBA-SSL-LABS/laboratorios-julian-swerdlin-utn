#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_compra_con_descuento(void) {
    Carrito c;
    carrito_init(&c);
    Producto leche = {"Leche",   350, 2};
    Producto pan   = {"Pan",     200, 3};
    carrito_agregar(&c, leche);
    carrito_agregar(&c, pan);
    int total = carrito_total(&c);  /* 350*2 + 200*3 = 700 + 600 = 1300 */
    ASSERT_IGUAL(1300, total);
    int total_con_descuento = carrito_descuento(total, 10);
    ASSERT_IGUAL(1170, total_con_descuento);  /* 1300 - 10% = 1300 - 130 = 1170 */
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

void test_agregar_hasta_llenar(void) {
    Carrito c;
    carrito_init(&c);
    Producto p = {"Producto", 100, 1};
    for (int i = 0; i < MAX_ITEMS; i++) {
        ASSERT_IGUAL(1, carrito_agregar(&c, p));
    }
    ASSERT_IGUAL(0, carrito_agregar(&c, p));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
