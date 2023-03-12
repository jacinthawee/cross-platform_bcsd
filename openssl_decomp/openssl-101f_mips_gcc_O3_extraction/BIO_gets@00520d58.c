
int BIO_gets(BIO *bp,char *buf,int size)

{
  long lVar1;
  int iVar2;
  int reason;
  _func_603 *p_Var3;
  _func_598 *UNRECOVERED_JUMPTABLE;
  
  if (((bp == (BIO *)0x0) || (bp->method == (BIO_METHOD *)0x0)) ||
     (UNRECOVERED_JUMPTABLE = bp->method->bgets, UNRECOVERED_JUMPTABLE == (_func_598 *)0x0)) {
    reason = 0x79;
    iVar2 = 0x129;
  }
  else {
    p_Var3 = bp->callback;
    if (p_Var3 == (_func_603 *)0x0) {
      if (bp->init != 0) {
                    /* WARNING: Could not recover jumptable at 0x00520e48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*UNRECOVERED_JUMPTABLE)(bp,buf,size);
        return iVar2;
      }
    }
    else {
      lVar1 = (*p_Var3)(bp,5,buf,size,0,1);
      if (lVar1 < 1) {
        return lVar1;
      }
      if (bp->init != 0) {
        iVar2 = (*bp->method->bgets)(bp,buf,size);
        lVar1 = (*p_Var3)(bp,0x85,buf,size,0,iVar2);
        return lVar1;
      }
    }
    reason = 0x78;
    iVar2 = 0x135;
  }
  ERR_put_error(0x20,0x68,reason,"bio_lib.c",iVar2);
  return -2;
}

