
void CRYPTO_destroy_dynlockid(int i)

{
  int iVar1;
  int *ptr;
  undefined4 uVar2;
  
  if (i != 0) {
    i = ~i;
  }
  if (dynlock_destroy_callback == (code *)0x0) {
    return;
  }
  if (locking_callback == (code *)0x0) {
    if (dyn_locks == (_STACK *)0x0) {
      return;
    }
LAB_080cf9c4:
    iVar1 = sk_num(dyn_locks);
    if (i < iVar1) {
      ptr = (int *)sk_value(dyn_locks,i);
      if ((ptr != (int *)0x0) && (iVar1 = *ptr, *ptr = iVar1 + -1, iVar1 + -1 < 1)) {
        sk_set(dyn_locks,i,(void *)0x0);
        if (locking_callback != (code *)0x0) {
          (*locking_callback)(10,0x1d,"cryptlib.c",0x148);
        }
        (*dynlock_destroy_callback)(ptr[1],"cryptlib.c",0x14b);
        CRYPTO_free(ptr);
        return;
      }
      if (locking_callback == (code *)0x0) {
        return;
      }
      uVar2 = 0x148;
      goto LAB_080cf9e2;
    }
  }
  else {
    (*locking_callback)(9,0x1d,"cryptlib.c",0x133);
    if (dyn_locks != (_STACK *)0x0) goto LAB_080cf9c4;
  }
  if (locking_callback == (code *)0x0) {
    return;
  }
  uVar2 = 0x136;
LAB_080cf9e2:
  (*locking_callback)(10,0x1d,"cryptlib.c",uVar2);
  return;
}

