
int BIO_read(BIO *b,void *data,int len)

{
  int iVar1;
  _func_596 *p_Var2;
  _func_603 *p_Var3;
  
  if (((b == (BIO *)0x0) || (b->method == (BIO_METHOD *)0x0)) ||
     (b->method->bread == (_func_596 *)0x0)) {
    ERR_put_error(0x20,0x6f,0x79,"bio_lib.c",0xc4);
    iVar1 = -2;
  }
  else {
    p_Var3 = b->callback;
    if ((p_Var3 == (_func_603 *)0x0) || (iVar1 = (*p_Var3)(b,2,(char *)data,len,0,1), 0 < iVar1)) {
      if (b->init == 0) {
        ERR_put_error(0x20,0x6f,0x78,"bio_lib.c",0xce);
        iVar1 = -2;
      }
      else {
        p_Var2 = b->method->bread;
        iVar1 = (*p_Var2)(b,(char *)data,len);
        if (0 < iVar1) {
          p_Var2 = (_func_596 *)(b->num_read + iVar1);
        }
        if (0 < iVar1) {
          b->num_read = (ulong)p_Var2;
        }
        if (p_Var3 != (_func_603 *)0x0) {
          iVar1 = (*p_Var3)(b,0x82,(char *)data,len,0,iVar1);
        }
      }
    }
  }
  return iVar1;
}

