
int BIO_puts(BIO *bp,char *buf)

{
  _func_603 *p_Var1;
  long lVar2;
  int iVar3;
  int line;
  
  if (((bp == (BIO *)0x0) || (bp->method == (BIO_METHOD *)0x0)) ||
     (bp->method->bputs == (_func_597 *)0x0)) {
    line = 0x108;
    iVar3 = 0x79;
  }
  else {
    p_Var1 = bp->callback;
    if ((p_Var1 != (_func_603 *)0x0) && (lVar2 = (*p_Var1)(bp,4,buf,0,0,1), lVar2 < 1)) {
      return lVar2;
    }
    if (bp->init != 0) {
      iVar3 = (*bp->method->bputs)(bp,buf);
      if (0 < iVar3) {
        bp->num_write = bp->num_write + iVar3;
      }
      if (p_Var1 == (_func_603 *)0x0) {
        return iVar3;
      }
      lVar2 = (*p_Var1)(bp,0x84,buf,0,0,iVar3);
      return lVar2;
    }
    line = 0x114;
    iVar3 = 0x78;
  }
  ERR_put_error(0x20,0x6e,iVar3,"bio_lib.c",line);
  return -2;
}

