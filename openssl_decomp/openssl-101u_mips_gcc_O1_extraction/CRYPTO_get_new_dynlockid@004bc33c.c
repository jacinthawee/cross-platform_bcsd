
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
    (*(code *)PTR_ERR_put_error_006a7f34)(0xf,0x67,100,s_cryptlib_c_0064cbb4,0xf8);
    return 0;
  }
  if (locking_callback == (code *)0x0) {
    if (dyn_locks == 0) goto LAB_004bc508;
  }
  else {
    (*locking_callback)(9,0x1d,s_cryptlib_c_0064cbb4,0xfb);
    if (dyn_locks == 0) {
LAB_004bc508:
      dyn_locks = (*(code *)PTR_sk_new_null_006a6fa4)();
      if (dyn_locks == 0) {
        if (locking_callback != (code *)0x0) {
          (*locking_callback)(10,0x1d,s_cryptlib_c_0064cbb4,0xfe);
        }
        uVar4 = 0xff;
        goto LAB_004bc5b8;
      }
    }
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(10,0x1d,s_cryptlib_c_0064cbb4,0x102);
    }
  }
  ptr = (undefined4 *)CRYPTO_malloc(8,s_cryptlib_c_0064cbb4,0x104);
  pcVar1 = dynlock_create_callback;
  if (ptr == (undefined4 *)0x0) {
    uVar4 = 0x106;
LAB_004bc5b8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0xf,0x67,0x41,s_cryptlib_c_0064cbb4,uVar4);
    return 0;
  }
  *ptr = 1;
  iVar2 = (*pcVar1)(s_cryptlib_c_0064cbb4,0x10a);
  ptr[1] = iVar2;
  if (iVar2 == 0) {
    CRYPTO_free(ptr);
    uVar4 = 0x10d;
    goto LAB_004bc5b8;
  }
  if (locking_callback != (code *)0x0) {
    (*locking_callback)(9,0x1d,s_cryptlib_c_0064cbb4,0x111);
  }
  uVar3 = (*(code *)PTR_sk_find_006a8044)(dyn_locks,0);
  if (uVar3 == 0xffffffff) {
    iVar2 = (*(code *)PTR_sk_push_006a6fa8)(dyn_locks,ptr);
    uVar3 = iVar2 - 1;
    if (locking_callback == (code *)0x0) goto LAB_004bc480;
  }
  else {
    (*(code *)PTR_sk_set_006a8358)(dyn_locks,uVar3,ptr);
    if (locking_callback == (code *)0x0) {
      return ~uVar3;
    }
  }
  (*locking_callback)(10,0x1d,s_cryptlib_c_0064cbb4,0x121);
LAB_004bc480:
  if (uVar3 == 0xffffffff) {
    (*dynlock_destroy_callback)(ptr[1],s_cryptlib_c_0064cbb4,0x124);
    CRYPTO_free(ptr);
    uVar3 = 1;
  }
  else {
    uVar3 = ~uVar3;
  }
  return uVar3;
}

