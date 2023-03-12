
int CRYPTO_add_lock(int *pointer,int amount,int type,char *file,int line)

{
  bool bVar1;
  code *pcVar2;
  int iVar3;
  CRYPTO_dynlock_value *pCVar4;
  
  if (add_lock_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004bfee8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*add_lock_callback)();
    return iVar3;
  }
  if (type < 0) {
    if (dynlock_lock_callback != (code *)0x0) {
      pCVar4 = CRYPTO_get_dynlock_value(type);
      if (pCVar4 != (CRYPTO_dynlock_value *)0x0) {
        (*dynlock_lock_callback)(9,pCVar4,file,line);
        CRYPTO_destroy_dynlockid(type);
        iVar3 = amount + *pointer;
        bVar1 = dynlock_lock_callback == (code *)0x0;
        *pointer = iVar3;
        if (bVar1) {
          return iVar3;
        }
        pCVar4 = CRYPTO_get_dynlock_value(type);
        if (pCVar4 != (CRYPTO_dynlock_value *)0x0) {
          (*dynlock_lock_callback)(10,pCVar4,file,line);
          CRYPTO_destroy_dynlockid(type);
          return iVar3;
        }
      }
      OpenSSLDie(s_cryptlib_c_0064d554,0x253,"pointer != NULL");
      return *(int *)PTR_stderr_006aac00;
    }
  }
  else if (locking_callback != (code *)0x0) {
    (*locking_callback)(9,type,file,line);
    pcVar2 = locking_callback;
    iVar3 = amount + *pointer;
    bVar1 = locking_callback == (code *)0x0;
    *pointer = iVar3;
    if (bVar1) {
      return iVar3;
    }
    (*pcVar2)(10,type,file,line);
    return iVar3;
  }
  iVar3 = *pointer;
  *pointer = amount + iVar3;
  return amount + iVar3;
}

