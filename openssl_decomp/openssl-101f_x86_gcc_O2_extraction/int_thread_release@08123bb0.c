
void int_thread_release(int *param_1)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    iVar1 = CRYPTO_add_lock(&int_thread_hash_references,-1,1,"err.c",0x1d5);
    if (iVar1 < 1) {
      *param_1 = 0;
      return;
    }
  }
  return;
}

