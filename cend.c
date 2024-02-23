
#include <stdio.h>
#include <caml/callback.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>

CAMLprim value forasc(value f, value n) {
  CAMLparam2(f, n);
  int end = Int_val(n);
  for (int i = 0; i < end; i++) {
    caml_callback(f, Val_int(i));
  }
  CAMLreturn (Val_unit);
}

CAMLprim value c_print_char(value c) {
  CAMLparam1(c);
  printf("%c", Int_val(c));
  CAMLreturn (Val_unit);
}
