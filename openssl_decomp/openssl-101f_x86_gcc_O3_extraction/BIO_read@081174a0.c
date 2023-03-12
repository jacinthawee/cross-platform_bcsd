
int BIO_read(BIO *b,void *data,int len)

{
  _func_603 *p_Var1;
  long lVar2;
  int iVar3;
  int line;
  
  if (((b == (BIO *)0x0) || (b->method == (BIO_METHOD *)0x0)) ||
     (b->method->bread == (_func_596 *)0x0)) {
    line = 0xc5;
    iVar3 = 0x79;
  }
  else {
    p_Var1 = b->callback;
    if ((p_Var1 != (_func_603 *)0x0) && (lVar2 = (*p_Var1)(b,2,(char *)data,len,0,1), lVar2 < 1)) {
      return lVar2;
    }
    if (b->init != 0) {
      iVar3 = (*b->method->bread)(b,(char *)data,len);
      if (0 < iVar3) {
        b->num_read = b->num_read + iVar3;
      }
      if (p_Var1 == (_func_603 *)0x0) {
        return iVar3;
      }
      lVar2 = (*p_Var1)(b,0x82,(char *)data,len,0,iVar3);
      return lVar2;
    }
    line = 0xd0;
    iVar3 = 0x78;
  }
  ERR_put_error(0x20,0x6f,iVar3,"bio_lib.c",line);
  return -2;
}

