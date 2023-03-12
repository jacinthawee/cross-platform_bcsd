
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_get_new_dynlockid(void)

{
  code *pcVar1;
  undefined4 *ptr;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (dynlock_create_callback == (code *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xf,0x67,100,s_cryptlib_c_0064d554,0xf3);
    return 0;
  }
  if (locking_callback == (code *)0x0) {
    if (dyn_locks == 0) goto LAB_004bf668;
  }
  else {
    (*locking_callback)(9,0x1d,s_cryptlib_c_0064d554,0xf6);
    if (dyn_locks == 0) {
LAB_004bf668:
      dyn_locks = (*(code *)PTR_sk_new_null_006a80a4)();
      if (dyn_locks == 0) {
        if (locking_callback != (code *)0x0) {
          (*locking_callback)(10,0x1d,s_cryptlib_c_0064d554,0xfa);
        }
        uVar4 = 0xfb;
        goto LAB_004bf718;
      }
    }
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(10,0x1d,s_cryptlib_c_0064d554,0xfe);
    }
  }
  ptr = (undefined4 *)CRYPTO_malloc(8,s_cryptlib_c_0064d554,0x100);
  pcVar1 = dynlock_create_callback;
  if (ptr == (undefined4 *)0x0) {
    uVar4 = 0x103;
LAB_004bf718:
    (*(code *)PTR_ERR_put_error_006a9030)(0xf,0x67,0x41,s_cryptlib_c_0064d554,uVar4);
    return 0;
  }
  *ptr = 1;
  iVar2 = (*pcVar1)(s_cryptlib_c_0064d554,0x107);
  ptr[1] = iVar2;
  if (iVar2 == 0) {
    CRYPTO_free(ptr);
    uVar4 = 0x10b;
    goto LAB_004bf718;
  }
  if (locking_callback != (code *)0x0) {
    (*locking_callback)(9,0x1d,s_cryptlib_c_0064d554,0x10f);
  }
  uVar3 = (*(code *)PTR_sk_find_006a906c)(dyn_locks,0);
  if (uVar3 == 0xffffffff) {
    iVar2 = (*(code *)PTR_sk_push_006a80a8)(dyn_locks,ptr);
    uVar3 = iVar2 - 1;
    if (locking_callback == (code *)0x0) goto LAB_004bf5e0;
  }
  else {
    (*(code *)PTR_sk_set_006a9478)(dyn_locks,uVar3,ptr);
    if (locking_callback == (code *)0x0) {
      return ~uVar3;
    }
  }
  (*locking_callback)(10,0x1d,s_cryptlib_c_0064d554,0x11d);
LAB_004bf5e0:
  if (uVar3 == 0xffffffff) {
    (*dynlock_destroy_callback)(ptr[1],s_cryptlib_c_0064d554,0x121);
    CRYPTO_free(ptr);
    uVar3 = 1;
  }
  else {
    uVar3 = ~uVar3;
  }
  return uVar3;
}

