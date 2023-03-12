
undefined4 gost_ciphers(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  if (param_2 == (undefined4 *)0x0) {
    *param_3 = gost_cipher_nids;
    return 2;
  }
  if (param_4 != 0x32d) {
    if (param_4 != 0x32e) {
      *param_2 = 0;
      return 0;
    }
    *param_2 = PTR_cipher_gost_cpacnt_006a9594;
    return 1;
  }
  *param_2 = PTR_cipher_gost_006a9590;
  return 1;
}

