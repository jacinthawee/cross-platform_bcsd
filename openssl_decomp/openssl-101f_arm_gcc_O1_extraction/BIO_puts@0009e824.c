
int BIO_puts(BIO *bp,char *buf)

{
  int iVar1;
  _func_597 *p_Var2;
  _func_603 *p_Var3;
  
  if (((bp == (BIO *)0x0) || (bp->method == (BIO_METHOD *)0x0)) ||
     (bp->method->bputs == (_func_597 *)0x0)) {
    ERR_put_error(0x20,0x6e,0x79,"bio_lib.c",0x108);
    iVar1 = -2;
  }
  else {
    p_Var3 = bp->callback;
    if ((p_Var3 == (_func_603 *)0x0) || (iVar1 = (*p_Var3)(bp,4,buf,0,0,1), 0 < iVar1)) {
      if (bp->init == 0) {
        ERR_put_error(0x20,0x6e,0x78,"bio_lib.c",0x114);
        iVar1 = -2;
      }
      else {
        p_Var2 = bp->method->bputs;
        iVar1 = (*p_Var2)(bp,buf);
        if (0 < iVar1) {
          p_Var2 = (_func_597 *)(bp->num_write + iVar1);
        }
        if (0 < iVar1) {
          bp->num_write = (ulong)p_Var2;
        }
        if (p_Var3 != (_func_603 *)0x0) {
          iVar1 = (*p_Var3)(bp,0x84,buf,0,0,iVar1);
        }
      }
    }
  }
  return iVar1;
}

