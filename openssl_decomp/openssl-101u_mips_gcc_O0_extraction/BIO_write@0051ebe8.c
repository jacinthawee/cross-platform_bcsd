
int BIO_write(BIO *b,void *data,int len)

{
  long lVar1;
  int iVar2;
  int reason;
  _func_603 *p_Var3;
  
  if (b == (BIO *)0x0) {
    return 0;
  }
  p_Var3 = b->callback;
  if ((b->method == (BIO_METHOD *)0x0) || (b->method->bwrite == (_func_595 *)0x0)) {
    reason = 0x79;
    iVar2 = 0xe6;
  }
  else {
    if ((p_Var3 != (_func_603 *)0x0) && (lVar1 = (*p_Var3)(b,3,(char *)data,len,0,1), lVar1 < 1)) {
      return lVar1;
    }
    if (b->init != 0) {
      iVar2 = (*b->method->bwrite)(b,(char *)data,len);
      if (0 < iVar2) {
        b->num_write = b->num_write + iVar2;
      }
      if (p_Var3 == (_func_603 *)0x0) {
        return iVar2;
      }
      lVar1 = (*p_Var3)(b,0x83,(char *)data,len,0,iVar2);
      return lVar1;
    }
    reason = 0x78;
    iVar2 = 0xef;
  }
  ERR_put_error(0x20,0x71,reason,"bio_lib.c",iVar2);
  return -2;
}

