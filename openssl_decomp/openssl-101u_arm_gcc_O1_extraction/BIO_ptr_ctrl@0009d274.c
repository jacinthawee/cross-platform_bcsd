
char * BIO_ptr_ctrl(BIO *bp,int cmd,long larg)

{
  long lVar1;
  int iVar2;
  _func_603 *p_Var3;
  _func_599 *p_Var4;
  char *local_1c;
  
  local_1c = (char *)0x0;
  if (bp != (BIO *)0x0) {
    if ((bp->method == (BIO_METHOD *)0x0) || (p_Var4 = bp->method->ctrl, p_Var4 == (_func_599 *)0x0)
       ) {
      ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
    }
    else {
      p_Var3 = bp->callback;
      if (p_Var3 == (_func_603 *)0x0) {
        iVar2 = (*p_Var4)(bp,cmd,larg,&local_1c);
      }
      else {
        lVar1 = (*p_Var3)(bp,6,(char *)&local_1c,cmd,larg,1);
        if (lVar1 < 1) {
          return (char *)0x0;
        }
        lVar1 = (*bp->method->ctrl)(bp,cmd,larg,&local_1c);
        iVar2 = (*p_Var3)(bp,0x86,(char *)&local_1c,cmd,larg,lVar1);
      }
      if (0 < iVar2) {
        return local_1c;
      }
    }
  }
  return (char *)0x0;
}

