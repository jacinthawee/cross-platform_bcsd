
undefined4 tls12_get_req_sig_algs(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = DAT_0018dee0;
  uVar2 = DAT_0018dedc;
  uVar1 = DAT_0018ded8;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = tls12_sigalgs;
    param_2[1] = uVar1;
    param_2[2] = uVar2;
    param_2[3] = uVar3;
    uVar2 = DAT_0018deec;
    uVar1 = DAT_0018dee8;
    param_2[4] = DAT_0018dee4;
    param_2[5] = uVar1;
    param_2[6] = uVar2;
    *(undefined2 *)(param_2 + 7) = DAT_0018def0;
  }
  return 0x1e;
}

