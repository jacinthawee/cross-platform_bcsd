
int BN_GENCB_call(BN_GENCB *cb,int a,int b)

{
  int iVar1;
  
  if (cb == (BN_GENCB *)0x0) {
    return 1;
  }
  if (cb->ver == 1) {
    iVar1 = 1;
    if ((cb->cb).cb_1 != (_func_414 *)0x0) {
      (*(cb->cb).cb_1)(a,b,cb->arg);
      return 1;
    }
  }
  else {
    if (cb->ver == 2) {
                    /* WARNING: Could not recover jumptable at 0x080fc034. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(cb->cb).cb_1)(a,b,cb);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}

