
void CRYPTO_destroy_dynlockid(int i)

{
  int iVar1;
  int *ptr;
  uint uVar2;
  
  uVar2 = ~i;
  if (i == 0) {
    uVar2 = 0;
  }
  if (dynlock_destroy_callback == (code *)0x0) {
    return;
  }
  if (locking_callback == (code *)0x0) {
    if (dyn_locks == 0) {
      return;
    }
  }
  else {
    (*locking_callback)(9,0x1d,s_cryptlib_c_0064cbb4,0x133);
    if (dyn_locks == 0) goto LAB_004bc698;
  }
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)();
  if ((int)uVar2 < iVar1) {
    ptr = (int *)(*(code *)PTR_sk_value_006a6e24)(dyn_locks,uVar2);
    if ((ptr != (int *)0x0) && (iVar1 = *ptr, *ptr = iVar1 + -1, iVar1 + -1 < 1)) {
      (*(code *)PTR_sk_set_006a8358)(dyn_locks,uVar2,0);
      if (locking_callback != (code *)0x0) {
        (*locking_callback)(10,0x1d,s_cryptlib_c_0064cbb4,0x148);
      }
      (*dynlock_destroy_callback)(ptr[1],s_cryptlib_c_0064cbb4,0x14b);
      CRYPTO_free(ptr);
      return;
    }
    if (locking_callback == (code *)0x0) {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x004bc734. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*locking_callback)(10,0x1d,s_cryptlib_c_0064cbb4,0x148);
    return;
  }
LAB_004bc698:
  if (locking_callback == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004bc6cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*locking_callback)(10,0x1d,s_cryptlib_c_0064cbb4,0x136);
  return;
}

