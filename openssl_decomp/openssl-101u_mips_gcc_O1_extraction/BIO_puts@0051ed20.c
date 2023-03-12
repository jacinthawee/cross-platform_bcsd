
int BIO_puts(BIO *bp,char *buf)

{
  long lVar1;
  int iVar2;
  int reason;
  _func_603 *p_Var3;
  
  if (((bp == (BIO *)0x0) || (bp->method == (BIO_METHOD *)0x0)) ||
     (bp->method->bputs == (_func_597 *)0x0)) {
    reason = 0x79;
    iVar2 = 0x103;
  }
  else {
    p_Var3 = bp->callback;
    if ((p_Var3 != (_func_603 *)0x0) && (lVar1 = (*p_Var3)(bp,4,buf,0,0,1), lVar1 < 1)) {
      return lVar1;
    }
    if (bp->init != 0) {
      iVar2 = (*bp->method->bputs)(bp,buf);
      if (0 < iVar2) {
        bp->num_write = bp->num_write + iVar2;
      }
      if (p_Var3 == (_func_603 *)0x0) {
        return iVar2;
      }
      lVar1 = (*p_Var3)(bp,0x84,buf,0,0,iVar2);
      return lVar1;
    }
    reason = 0x78;
    iVar2 = 0x10d;
  }
  ERR_put_error(0x20,0x6e,reason,"bio_lib.c",iVar2);
  return -2;
}

