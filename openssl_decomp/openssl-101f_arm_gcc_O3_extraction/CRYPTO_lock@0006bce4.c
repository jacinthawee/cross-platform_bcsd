
void CRYPTO_lock(int mode,int type,char *file,int line)

{
  CRYPTO_dynlock_value *pCVar1;
  
  if (type < 0) {
    if (dynlock_lock_callback != (code *)0x0) {
      pCVar1 = CRYPTO_get_dynlock_value(type);
      if (pCVar1 != (CRYPTO_dynlock_value *)0x0) {
        (*dynlock_lock_callback)(mode,pCVar1,file,line);
        CRYPTO_destroy_dynlockid(type);
        return;
      }
                    /* WARNING: Subroutine does not return */
      CRYPTO_lock_part_0(0,0);
    }
  }
  else if (locking_callback != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0006bcfe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*locking_callback)();
    return;
  }
  return;
}

