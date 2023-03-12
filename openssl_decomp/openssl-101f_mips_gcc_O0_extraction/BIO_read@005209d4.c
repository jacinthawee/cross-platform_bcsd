
int BIO_read(BIO *b,void *data,int len)

{
  long lVar1;
  int iVar2;
  int reason;
  _func_603 *p_Var3;
  
  if (((b == (BIO *)0x0) || (b->method == (BIO_METHOD *)0x0)) ||
     (b->method->bread == (_func_596 *)0x0)) {
    reason = 0x79;
    iVar2 = 0xc5;
  }
  else {
    p_Var3 = b->callback;
    if ((p_Var3 != (_func_603 *)0x0) && (lVar1 = (*p_Var3)(b,2,(char *)data,len,0,1), lVar1 < 1)) {
      return lVar1;
    }
    if (b->init != 0) {
      iVar2 = (*b->method->bread)(b,(char *)data,len);
      if (0 < iVar2) {
        b->num_read = b->num_read + iVar2;
      }
      if (p_Var3 == (_func_603 *)0x0) {
        return iVar2;
      }
      lVar1 = (*p_Var3)(b,0x82,(char *)data,len,0,iVar2);
      return lVar1;
    }
    reason = 0x78;
    iVar2 = 0xd0;
  }
  ERR_put_error(0x20,0x6f,reason,"bio_lib.c",iVar2);
  return -2;
}

