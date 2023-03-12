
bool gost_ciphers(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  if (param_2 == (undefined4 *)0x0) {
    *param_3 = PTR_gost_cipher_nids_000f7de8;
    return (bool)2;
  }
  if (param_4 == 0x32d) {
    *param_2 = cipher_gost;
    return true;
  }
  if (param_4 == 0x32e) {
    *param_2 = cipher_gost_cpacnt;
  }
  else {
    *param_2 = 0;
  }
  return param_4 == 0x32e;
}

