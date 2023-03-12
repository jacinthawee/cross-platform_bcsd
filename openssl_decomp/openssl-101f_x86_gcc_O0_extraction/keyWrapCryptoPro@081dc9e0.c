
undefined4
keyWrapCryptoPro(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                undefined4 *param_5)

{
  undefined4 uVar1;
  int in_GS_OFFSET;
  undefined local_40 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  keyDiversifyCryptoPro(param_1,param_2,param_3,local_40);
  gost_key(param_1,local_40);
  uVar1 = param_3[1];
  *param_5 = *param_3;
  param_5[1] = uVar1;
  gost_enc(param_1,param_4,param_5 + 2,4);
  gost_mac_iv(param_1,0x20,param_3,param_4,0x20,param_5 + 10);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

