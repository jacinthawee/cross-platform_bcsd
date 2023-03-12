
long BIO_callback_ctrl(BIO *b,int cmd,fp *fp)

{
  long lVar1;
  _func_603 *p_Var2;
  _func_602 *p_Var3;
  fp *local_res8 [2];
  
  if (b == (BIO *)0x0) {
    return 0;
  }
  local_res8[0] = fp;
  if ((b->method == (BIO_METHOD *)0x0) ||
     (p_Var3 = b->method->callback_ctrl, p_Var3 == (_func_602 *)0x0)) {
    ERR_put_error(0x20,0x83,0x79,"bio_lib.c",0x179);
    lVar1 = -2;
  }
  else {
    p_Var2 = b->callback;
    if (p_Var2 == (_func_603 *)0x0) {
      lVar1 = (*p_Var3)(b,cmd,fp);
      return lVar1;
    }
    lVar1 = (*p_Var2)(b,6,(char *)local_res8,cmd,0,1);
    if (0 < lVar1) {
      lVar1 = (*b->method->callback_ctrl)(b,cmd,local_res8[0]);
      lVar1 = (*p_Var2)(b,0x86,(char *)local_res8,cmd,0,lVar1);
    }
  }
  return lVar1;
}

