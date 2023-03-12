
undefined4 gost_digests(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  if (param_2 == (undefined4 *)0x0) {
    *param_3 = gost_digest_nids;
    return 2;
  }
  if (param_4 != 0x329) {
    if (param_4 != 0x32f) {
      *param_2 = 0;
      return 0;
    }
    *param_2 = PTR_imit_gost_cpa_006a958c;
    return 1;
  }
  *param_2 = PTR_digest_gost_006a9588;
  return 1;
}

