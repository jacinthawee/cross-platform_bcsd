
int BN_GENCB_call(BN_GENCB *cb,int a,int b)

{
  int iVar1;
  
  if (cb == (BN_GENCB *)0x0) {
    return 1;
  }
  if (cb->ver != 1) {
    if (cb->ver == 2) {
                    /* WARNING: Could not recover jumptable at 0x0008bc86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*(cb->cb).cb_1)(a,b,cb);
      return iVar1;
    }
    return 0;
  }
  if ((cb->cb).cb_1 != (_func_414 *)0x0) {
    (*(cb->cb).cb_1)(a,b,cb->arg);
    return 1;
  }
  return 1;
}

