
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_get_new_dynlockid(void)

{
  undefined4 *ptr;
  int iVar1;
  uint uVar2;
  int line;
  
  if (dynlock_create_callback == (code *)0x0) {
    line = 0xf3;
    iVar1 = 100;
    goto LAB_080d1ec7;
  }
  if (locking_callback == (code *)0x0) {
    if (dyn_locks == (_STACK *)0x0) goto LAB_080d1e7d;
LAB_080d1d8d:
    ptr = (undefined4 *)CRYPTO_malloc(8,"cryptlib.c",0x100);
    if (ptr == (undefined4 *)0x0) {
      line = 0x103;
    }
    else {
      *ptr = 1;
      iVar1 = (*dynlock_create_callback)("cryptlib.c",0x107);
      ptr[1] = iVar1;
      if (iVar1 != 0) {
        if (locking_callback != (code *)0x0) {
          (*locking_callback)(9,0x1d,"cryptlib.c",0x10f);
        }
        uVar2 = sk_find(dyn_locks,(void *)0x0);
        if (uVar2 == 0xffffffff) {
          iVar1 = sk_push(dyn_locks,ptr);
          uVar2 = iVar1 - 1;
          if (locking_callback != (code *)0x0) goto LAB_080d1e27;
        }
        else {
          sk_set(dyn_locks,uVar2,ptr);
          if (locking_callback == (code *)0x0) goto LAB_080d1e43;
LAB_080d1e27:
          (*locking_callback)(10,0x1d,"cryptlib.c",0x11d);
        }
        if (uVar2 == 0xffffffff) {
          (*dynlock_destroy_callback)(ptr[1],"cryptlib.c",0x121);
          CRYPTO_free(ptr);
          return 1;
        }
LAB_080d1e43:
        return ~uVar2;
      }
      CRYPTO_free(ptr);
      line = 0x10b;
    }
  }
  else {
    (*locking_callback)(9,0x1d,"cryptlib.c",0xf6);
    if (dyn_locks != (_STACK *)0x0) {
LAB_080d1d71:
      if (locking_callback != (code *)0x0) {
        (*locking_callback)(10,0x1d,"cryptlib.c",0xfe);
      }
      goto LAB_080d1d8d;
    }
LAB_080d1e7d:
    dyn_locks = sk_new_null();
    if (dyn_locks != (_STACK *)0x0) goto LAB_080d1d71;
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(10,0x1d,"cryptlib.c",0xfa);
    }
    line = 0xfb;
  }
  iVar1 = 0x41;
LAB_080d1ec7:
  ERR_put_error(0xf,0x67,iVar1,"cryptlib.c",line);
  return 0;
}

