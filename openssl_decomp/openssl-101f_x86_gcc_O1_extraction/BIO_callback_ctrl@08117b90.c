
long BIO_callback_ctrl(BIO *b,int cmd,fp *fp)

{
  _func_602 *p_Var1;
  _func_603 *p_Var2;
  long lVar3;
  
  if (b == (BIO *)0x0) {
    return 0;
  }
  if ((b->method == (BIO_METHOD *)0x0) ||
     (p_Var1 = b->method->callback_ctrl, p_Var1 == (_func_602 *)0x0)) {
    ERR_put_error(0x20,0x83,0x79,"bio_lib.c",0x183);
    lVar3 = -2;
  }
  else {
    p_Var2 = b->callback;
    if (p_Var2 == (_func_603 *)0x0) {
      lVar3 = (*p_Var1)(b,cmd,fp);
      return lVar3;
    }
    lVar3 = (*p_Var2)(b,6,(char *)&fp,cmd,0,1);
    if (0 < lVar3) {
      lVar3 = (*b->method->callback_ctrl)(b,cmd,fp);
      lVar3 = (*p_Var2)(b,0x86,(char *)&fp,cmd,0,lVar3);
    }
  }
  return lVar3;
}

