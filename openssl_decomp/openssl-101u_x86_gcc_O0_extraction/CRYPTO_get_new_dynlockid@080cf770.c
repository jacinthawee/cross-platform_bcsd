
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int CRYPTO_get_new_dynlockid(void)

{
  undefined4 *ptr;
  int iVar1;
  uint uVar2;
  int line;
  
  if (dynlock_create_callback == (code *)0x0) {
    line = 0xf8;
    iVar1 = 100;
    goto LAB_080cf907;
  }
  if (locking_callback == (code *)0x0) {
    if (dyn_locks == (_STACK *)0x0) goto LAB_080cf8bd;
LAB_080cf7cd:
    ptr = (undefined4 *)CRYPTO_malloc(8,"cryptlib.c",0x104);
    if (ptr == (undefined4 *)0x0) {
      line = 0x106;
    }
    else {
      *ptr = 1;
      iVar1 = (*dynlock_create_callback)("cryptlib.c",0x10a);
      ptr[1] = iVar1;
      if (iVar1 != 0) {
        if (locking_callback != (code *)0x0) {
          (*locking_callback)(9,0x1d,"cryptlib.c",0x111);
        }
        uVar2 = sk_find(dyn_locks,(void *)0x0);
        if (uVar2 == 0xffffffff) {
          iVar1 = sk_push(dyn_locks,ptr);
          uVar2 = iVar1 - 1;
          if (locking_callback != (code *)0x0) goto LAB_080cf867;
        }
        else {
          sk_set(dyn_locks,uVar2,ptr);
          if (locking_callback == (code *)0x0) goto LAB_080cf883;
LAB_080cf867:
          (*locking_callback)(10,0x1d,"cryptlib.c",0x121);
        }
        if (uVar2 == 0xffffffff) {
          (*dynlock_destroy_callback)(ptr[1],"cryptlib.c",0x124);
          CRYPTO_free(ptr);
          return 1;
        }
LAB_080cf883:
        return ~uVar2;
      }
      CRYPTO_free(ptr);
      line = 0x10d;
    }
  }
  else {
    (*locking_callback)(9,0x1d,"cryptlib.c",0xfb);
    if (dyn_locks != (_STACK *)0x0) {
LAB_080cf7b1:
      if (locking_callback != (code *)0x0) {
        (*locking_callback)(10,0x1d,"cryptlib.c",0x102);
      }
      goto LAB_080cf7cd;
    }
LAB_080cf8bd:
    dyn_locks = sk_new_null();
    if (dyn_locks != (_STACK *)0x0) goto LAB_080cf7b1;
    if (locking_callback != (code *)0x0) {
      (*locking_callback)(10,0x1d,"cryptlib.c",0xfe);
    }
    line = 0xff;
  }
  iVar1 = 0x41;
LAB_080cf907:
  ERR_put_error(0xf,0x67,iVar1,"cryptlib.c",line);
  return 0;
}

