
undefined4 tls12_get_req_sig_algs(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = tls12_sigalgs._0_4_;
    param_2[1] = tls12_sigalgs._4_4_;
    param_2[2] = tls12_sigalgs._8_4_;
    param_2[3] = tls12_sigalgs._12_4_;
    param_2[4] = tls12_sigalgs._16_4_;
    param_2[5] = tls12_sigalgs._20_4_;
    param_2[6] = tls12_sigalgs._24_4_;
    *(undefined2 *)(param_2 + 7) = tls12_sigalgs._28_2_;
  }
  return 0x1e;
}

