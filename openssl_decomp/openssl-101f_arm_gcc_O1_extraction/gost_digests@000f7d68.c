
bool gost_digests(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  if (param_2 == (undefined4 *)0x0) {
    *param_3 = &gost_digest_nids;
    return (bool)2;
  }
  if (param_4 == 0x329) {
    *param_2 = &digest_gost;
    return true;
  }
  if (param_4 == 0x32f) {
    *param_2 = imit_gost_cpa;
  }
  else {
    *param_2 = 0;
  }
  return param_4 == 0x32f;
}

