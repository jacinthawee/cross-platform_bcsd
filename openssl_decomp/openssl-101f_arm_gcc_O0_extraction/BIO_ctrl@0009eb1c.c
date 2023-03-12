
long BIO_ctrl(BIO *bp,int cmd,long larg,void *parg)

{
  long lVar1;
  _func_603 *p_Var2;
  _func_599 *UNRECOVERED_JUMPTABLE;
  
  if (bp == (BIO *)0x0) {
    return 0;
  }
  if ((bp->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = bp->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    lVar1 = -2;
  }
  else {
    p_Var2 = bp->callback;
    if (p_Var2 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009eb74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar1 = (*UNRECOVERED_JUMPTABLE)(bp,cmd,larg,parg);
      return lVar1;
    }
    lVar1 = (*p_Var2)(bp,6,(char *)parg,cmd,larg,1);
    if (0 < lVar1) {
      lVar1 = (*bp->method->ctrl)(bp,cmd,larg,parg);
      lVar1 = (*p_Var2)(bp,0x86,(char *)parg,cmd,larg,lVar1);
    }
  }
  return lVar1;
}

