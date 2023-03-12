
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_get_new_dynlockid(void)

{
  undefined4 *ptr;
  uint uVar1;
  int iVar2;
  
  if (dynlock_create_callback == (code *)0x0) {
    ERR_put_error(0xf,0x67,100,"cryptlib.c",0xf8);
    return 0;
  }
  if (locking_callback != (code *)0x0) {
    (*locking_callback)(9,0x1d,"cryptlib.c",0xfb);
  }
  if ((dyn_locks == (_STACK *)0x0) && (dyn_locks = sk_new_null(), dyn_locks == (_STACK *)0x0)) {
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(10,0x1d,"cryptlib.c",0xfe);
    }
    iVar2 = 0xff;
  }
  else {
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(10,0x1d,"cryptlib.c",0x102);
    }
    ptr = (undefined4 *)CRYPTO_malloc(8,"cryptlib.c",0x104);
    iVar2 = 0x106;
    if (ptr != (undefined4 *)0x0) {
      *ptr = 1;
      iVar2 = (*dynlock_create_callback)("cryptlib.c",0x10a);
      ptr[1] = iVar2;
      if (iVar2 == 0) {
        CRYPTO_free(ptr);
        ERR_put_error(0xf,0x67,0x41,"cryptlib.c",0x10d);
        return 0;
      }
      if (locking_callback != (code *)0x0) {
        (*locking_callback)(9,0x1d,"cryptlib.c",0x111);
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
        (*locking_callback)(10,0x1d,"cryptlib.c",0x121);
      }
      if (uVar1 == 0xffffffff) {
        (*dynlock_destroy_callback)(ptr[1],"cryptlib.c",0x124);
        CRYPTO_free(ptr);
        return 1;
      }
      return ~uVar1;
    }
  }
  ERR_put_error(0xf,0x67,0x41,"cryptlib.c",iVar2);
  return 0;
}

