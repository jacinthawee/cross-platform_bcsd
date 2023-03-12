
int CRYPTO_add_lock(int *pointer,int amount,int type,char *file,int line)

{
  code *pcVar1;
  int iVar2;
  CRYPTO_dynlock_value *pCVar3;
  bool bVar4;
  
  if (add_lock_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x080d24ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*add_lock_callback)();
    return iVar2;
  }
  if (type < 0) {
    if (dynlock_lock_callback != (code *)0x0) {
      pCVar3 = CRYPTO_get_dynlock_value(type);
      if (pCVar3 != (CRYPTO_dynlock_value *)0x0) {
        (*dynlock_lock_callback)(9,pCVar3,file,line);
        CRYPTO_destroy_dynlockid(type);
        iVar2 = amount + *pointer;
        bVar4 = dynlock_lock_callback == (code *)0x0;
        *pointer = iVar2;
        if (bVar4) {
          return iVar2;
        }
        pCVar3 = CRYPTO_get_dynlock_value(type);
        if (pCVar3 != (CRYPTO_dynlock_value *)0x0) {
          (*dynlock_lock_callback)(10,pCVar3,file,line);
          CRYPTO_destroy_dynlockid(type);
          return iVar2;
        }
      }
      OpenSSLDie("cryptlib.c",0x253,"pointer != NULL");
      return stderr;
    }
  }
  else if (locking_callback != (code *)0x0) {
    (*locking_callback)(9,type,file,line);
    pcVar1 = locking_callback;
    iVar2 = amount + *pointer;
    bVar4 = locking_callback == (code *)0x0;
    *pointer = iVar2;
    if (bVar4) {
      return iVar2;
    }
    (*pcVar1)(10,type,file,line);
    return iVar2;
  }
  iVar2 = *pointer;
  *pointer = amount + iVar2;
  return amount + iVar2;
}

