
void int_thread_release(int *param_1)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) &&
     (iVar1 = CRYPTO_add_lock((int *)PTR_int_thread_hash_references_000a3eb8,-1,1,"err.c",0x1d9),
     iVar1 < 1)) {
    *param_1 = 0;
  }
  return;
}

