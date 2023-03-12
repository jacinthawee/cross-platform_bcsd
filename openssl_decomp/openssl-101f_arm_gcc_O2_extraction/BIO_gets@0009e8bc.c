
int BIO_gets(BIO *bp,char *buf,int size)

{
  long lVar1;
  int iVar2;
  _func_603 *p_Var3;
  
  if (((bp == (BIO *)0x0) || (bp->method == (BIO_METHOD *)0x0)) ||
     (bp->method->bgets == (_func_598 *)0x0)) {
    ERR_put_error(0x20,0x68,0x79,"bio_lib.c",0x129);
    iVar2 = -2;
  }
  else {
    p_Var3 = bp->callback;
    if ((p_Var3 != (_func_603 *)0x0) && (lVar1 = (*p_Var3)(bp,5,buf,size,0,1), lVar1 < 1)) {
      return lVar1;
    }
    if (bp->init == 0) {
      ERR_put_error(0x20,0x68,0x78,"bio_lib.c",0x135);
      iVar2 = -2;
    }
    else {
      iVar2 = (*bp->method->bgets)(bp,buf,size);
      if (p_Var3 != (_func_603 *)0x0) {
        iVar2 = (*p_Var3)(bp,0x85,buf,size,0,iVar2);
      }
    }
  }
  return iVar2;
}

