
size_t BIO_ctrl_wpending(BIO *b)

{
  _func_599 *p_Var1;
  _func_603 *p_Var2;
  size_t sVar3;
  long lVar4;
  
  if (b == (BIO *)0x0) {
    return 0;
  }
  if ((b->method == (BIO_METHOD *)0x0) || (p_Var1 = b->method->ctrl, p_Var1 == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x168);
    sVar3 = 0xfffffffe;
  }
  else {
    p_Var2 = b->callback;
    if (p_Var2 == (_func_603 *)0x0) {
      sVar3 = (*p_Var1)(b,0xd,0,(void *)0x0);
      return sVar3;
    }
    sVar3 = (*p_Var2)(b,6,(char *)0x0,0xd,0,1);
    if (0 < (int)sVar3) {
      lVar4 = (*b->method->ctrl)(b,0xd,0,(void *)0x0);
      sVar3 = (*p_Var2)(b,0x86,(char *)0x0,0xd,0,lVar4);
    }
  }
  return sVar3;
}

