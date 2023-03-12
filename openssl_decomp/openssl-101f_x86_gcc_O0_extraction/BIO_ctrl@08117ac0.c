
long BIO_ctrl(BIO *bp,int cmd,long larg,void *parg)

{
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var1;
  long lVar2;
  
  if (bp == (BIO *)0x0) {
    return 0;
  }
  if ((bp->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = bp->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    lVar2 = -2;
  }
  else {
    p_Var1 = bp->callback;
    if (p_Var1 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08117b57. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      lVar2 = (*UNRECOVERED_JUMPTABLE)(bp,cmd,larg,parg);
      return lVar2;
    }
    lVar2 = (*p_Var1)(bp,6,(char *)parg,cmd,larg,1);
    if (0 < lVar2) {
      lVar2 = (*bp->method->ctrl)(bp,cmd,larg,parg);
      lVar2 = (*p_Var1)(bp,0x86,(char *)parg,cmd,larg,lVar2);
    }
  }
  return lVar2;
}

