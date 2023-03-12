
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
    (*locking_callback)(9,0x1d,s_cryptlib_c_0064d554,0x131);
    if (dyn_locks == 0) goto LAB_004bf7f8;
  }
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)();
  if ((int)uVar2 < iVar1) {
    ptr = (int *)(*(code *)PTR_sk_value_006a7f24)(dyn_locks,uVar2);
    if ((ptr != (int *)0x0) && (iVar1 = *ptr, *ptr = iVar1 + -1, iVar1 + -1 < 1)) {
      (*(code *)PTR_sk_set_006a9478)(dyn_locks,uVar2,0);
      if (locking_callback != (code *)0x0) {
        (*locking_callback)(10,0x1d,s_cryptlib_c_0064d554,0x14b);
      }
      (*dynlock_destroy_callback)(ptr[1],s_cryptlib_c_0064d554,0x14f);
      CRYPTO_free(ptr);
      return;
    }
    if (locking_callback == (code *)0x0) {
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x004bf894. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*locking_callback)(10,0x1d,s_cryptlib_c_0064d554,0x14b);
    return;
  }
LAB_004bf7f8:
  if (locking_callback == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004bf82c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*locking_callback)(10,0x1d,s_cryptlib_c_0064d554,0x135);
  return;
}

