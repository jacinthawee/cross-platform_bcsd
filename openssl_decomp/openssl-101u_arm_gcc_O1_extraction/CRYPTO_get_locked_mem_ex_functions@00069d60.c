
void CRYPTO_get_locked_mem_ex_functions(m *m,f *f)

{
  int iVar1;
  
  if (m != (m *)0x0) {
    iVar1 = malloc_locked_ex_func;
    if (malloc_locked_ex_func == 0x69b61) {
      iVar1 = 0;
    }
    *(int *)m = iVar1;
  }
  if (f != (f *)0x0) {
    *(undefined **)f = free_locked_func;
  }
  return;
}

