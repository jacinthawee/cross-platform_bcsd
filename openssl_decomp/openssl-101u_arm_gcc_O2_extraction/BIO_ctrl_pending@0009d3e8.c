
size_t BIO_ctrl_pending(BIO *b)

{
  size_t sVar1;
  long lVar2;
  _func_599 *UNRECOVERED_JUMPTABLE;
  _func_603 *p_Var3;
  
  if (b == (BIO *)0x0) {
    return 0;
  }
  if ((b->method == (BIO_METHOD *)0x0) ||
     (UNRECOVERED_JUMPTABLE = b->method->ctrl, UNRECOVERED_JUMPTABLE == (_func_599 *)0x0)) {
    ERR_put_error(0x20,0x67,0x79,"bio_lib.c",0x15d);
    sVar1 = 0xfffffffe;
  }
  else {
    p_Var3 = b->callback;
    if (p_Var3 == (_func_603 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009d43e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      sVar1 = (*UNRECOVERED_JUMPTABLE)(b,10,0,(void *)0x0);
      return sVar1;
    }
    sVar1 = (*p_Var3)(b,6,(char *)0x0,10,0,1);
    if (0 < (int)sVar1) {
      lVar2 = (*b->method->ctrl)(b,10,0,(void *)0x0);
      sVar1 = (*p_Var3)(b,0x86,(char *)0x0,10,0,lVar2);
    }
  }
  return sVar1;
}

