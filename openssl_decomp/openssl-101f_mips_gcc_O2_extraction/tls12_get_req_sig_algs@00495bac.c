
undefined4 tls12_get_req_sig_algs(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar6 = tls12_sigalgs._24_4_;
  uVar5 = tls12_sigalgs._20_4_;
  uVar4 = tls12_sigalgs._16_4_;
  uVar3 = tls12_sigalgs._12_4_;
  uVar2 = tls12_sigalgs._8_4_;
  uVar1 = tls12_sigalgs._4_4_;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = tls12_sigalgs._0_4_;
    param_2[1] = uVar1;
    param_2[2] = uVar2;
    param_2[3] = uVar3;
    param_2[4] = uVar4;
    param_2[5] = uVar5;
    param_2[6] = uVar6;
    *(undefined *)(param_2 + 7) = tls12_sigalgs[28];
    *(undefined *)((int)param_2 + 0x1d) = tls12_sigalgs[29];
  }
  return 0x1e;
}

