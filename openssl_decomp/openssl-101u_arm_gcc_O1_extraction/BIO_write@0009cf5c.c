
int BIO_write(BIO *b,void *data,int len)

{
  int iVar1;
  _func_595 *p_Var2;
  _func_603 *p_Var3;
  
  if (b != (BIO *)0x0) {
    p_Var3 = b->callback;
    if ((b->method == (BIO_METHOD *)0x0) || (b->method->bwrite == (_func_595 *)0x0)) {
      ERR_put_error(0x20,0x71,0x79,"bio_lib.c",0xe6);
      iVar1 = -2;
    }
    else if ((p_Var3 == (_func_603 *)0x0) ||
            (iVar1 = (*p_Var3)(b,3,(char *)data,len,0,1), 0 < iVar1)) {
      if (b->init == 0) {
        ERR_put_error(0x20,0x71,0x78,"bio_lib.c",0xef);
        iVar1 = -2;
      }
      else {
        p_Var2 = b->method->bwrite;
        iVar1 = (*p_Var2)(b,(char *)data,len);
        if (0 < iVar1) {
          p_Var2 = (_func_595 *)(b->num_write + iVar1);
        }
        if (0 < iVar1) {
          b->num_write = (ulong)p_Var2;
        }
        if (p_Var3 != (_func_603 *)0x0) {
          iVar1 = (*p_Var3)(b,0x83,(char *)data,len,0,iVar1);
        }
      }
    }
    return iVar1;
  }
  return 0;
}

