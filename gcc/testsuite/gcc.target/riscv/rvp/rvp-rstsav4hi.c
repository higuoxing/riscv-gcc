/* { dg-do compile } */
/* { dg-options "-O0 -march=rv64gcp -mabi=lp64d" } */

#include <riscv_dsp.h>

int foo() {
  int16x4_t a = {-1, 2, -3, 4}, b = {-1, 2, -3, 4}, c;
  uintXLEN_t h = 0x01, i = 0x02, j;

  c = __builtin_riscv_v_rstsav4hi(a, b);
  c = __rv__v_rstsa16(a, b);
  j = __builtin_riscv_rstsav4hi(h, i);
  j = __rv__rstsa16(h, i);

  return 0;
}

/* { dg-final { scan-assembler-times "rstsa16" 4 } } */
