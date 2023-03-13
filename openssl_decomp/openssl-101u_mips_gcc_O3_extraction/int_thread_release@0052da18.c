
void int_thread_release(int *param_1)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) &&
     (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)
                        (&int_thread_hash_references,0xffffffff,1,"err.c",0x1d9), iVar1 < 1)) {
    *param_1 = 0;
  }
  return;
}

