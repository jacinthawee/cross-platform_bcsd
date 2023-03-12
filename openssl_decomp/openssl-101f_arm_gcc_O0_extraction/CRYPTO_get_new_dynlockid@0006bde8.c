
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_get_new_dynlockid(void)

{
  undefined4 *ptr;
  uint uVar1;
  int iVar2;
  
  if (dynlock_create_callback == (code *)0x0) {
    ERR_put_error(0xf,0x67,100,"cryptlib.c",0xf3);
    return 0;
  }
  if (locking_callback != (code *)0x0) {
    (*locking_callback)(9,0x1d,"cryptlib.c",0xf6);
  }
  if ((dyn_locks == (_STACK *)0x0) && (dyn_locks = sk_new_null(), dyn_locks == (_STACK *)0x0)) {
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(10,0x1d,"cryptlib.c",0xfa);
    }
    iVar2 = 0xfb;
  }
  else {
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(10,0x1d,"cryptlib.c",0xfe);
    }
    ptr = (undefined4 *)CRYPTO_malloc(8,"cryptlib.c",0x100);
    iVar2 = 0x103;
    if (ptr != (undefined4 *)0x0) {
      *ptr = 1;
      iVar2 = (*dynlock_create_callback)("cryptlib.c",0x107);
      ptr[1] = iVar2;
      if (iVar2 == 0) {
        CRYPTO_free(ptr);
        ERR_put_error(0xf,0x67,0x41,"cryptlib.c",0x10b);
        return 0;
      }
      if (locking_callback != (code *)0x0) {
        (*locking_callback)(9,0x1d,"cryptlib.c",0x10f);
      }
      uVar1 = sk_find(dyn_locks,(void *)0x0);
      if (uVar1 == 0xffffffff) {
        iVar2 = sk_push(dyn_locks,ptr);
        uVar1 = iVar2 - 1;
      }
      else {
        sk_set(dyn_locks,uVar1,ptr);
      }
      if (locking_callback != (code *)0x0) {
        (*locking_callback)(10,0x1d,"cryptlib.c",0x11d);
      }
      if (uVar1 == 0xffffffff) {
        (*dynlock_destroy_callback)(ptr[1],"cryptlib.c",0x121);
        CRYPTO_free(ptr);
        return 1;
      }
      return ~uVar1;
    }
  }
  ERR_put_error(0xf,0x67,0x41,"cryptlib.c",iVar2);
  return 0;
}

