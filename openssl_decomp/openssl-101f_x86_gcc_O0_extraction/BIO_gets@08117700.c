
int BIO_gets(BIO *bp,char *buf,int size)

{
  _func_598 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var1;
  long lVar2;
  int iVar3;
  int line;
  
  if (((bp == (BIO *)0x0) || (bp->method == (BIO_METHOD *)0x0)) ||
     (UNRECOVERED_JUMPTABLE = bp->method->bgets, UNRECOVERED_JUMPTABLE == (_func_598 *)0x0)) {
    line = 0x129;
    iVar3 = 0x79;
  }
  else {
    p_Var1 = bp->callback;
    if (p_Var1 == (_func_603 *)0x0) {
      if (bp->init != 0) {
                    /* WARNING: Could not recover jumptable at 0x0811779a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar3 = (*UNRECOVERED_JUMPTABLE)(bp,buf,size);
        return iVar3;
      }
    }
    else {
      lVar2 = (*p_Var1)(bp,5,buf,size,0,1);
      if (lVar2 < 1) {
        return lVar2;
      }
      if (bp->init != 0) {
        iVar3 = (*bp->method->bgets)(bp,buf,size);
        lVar2 = (*p_Var1)(bp,0x85,buf,size,0,iVar3);
        return lVar2;
      }
    }
    line = 0x135;
    iVar3 = 0x78;
  }
  ERR_put_error(0x20,0x68,iVar3,"bio_lib.c",line);
  return -2;
}

