
int BIO_write(BIO *b,void *data,int len)

{
  _func_603 *p_Var1;
  long lVar2;
  int iVar3;
  int line;
  
  if (b == (BIO *)0x0) {
    return 0;
  }
  p_Var1 = b->callback;
  if ((b->method == (BIO_METHOD *)0x0) || (b->method->bwrite == (_func_595 *)0x0)) {
    line = 0xe6;
    iVar3 = 0x79;
  }
  else {
    if ((p_Var1 != (_func_603 *)0x0) && (lVar2 = (*p_Var1)(b,3,(char *)data,len,0,1), lVar2 < 1)) {
      return lVar2;
    }
    if (b->init != 0) {
      iVar3 = (*b->method->bwrite)(b,(char *)data,len);
      if (0 < iVar3) {
        b->num_write = b->num_write + iVar3;
      }
      if (p_Var1 == (_func_603 *)0x0) {
        return iVar3;
      }
      lVar2 = (*p_Var1)(b,0x83,(char *)data,len,0,iVar3);
      return lVar2;
    }
    line = 0xef;
    iVar3 = 0x78;
  }
  ERR_put_error(0x20,0x71,iVar3,"bio_lib.c",line);
  return -2;
}

