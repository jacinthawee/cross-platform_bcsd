
bool keyUnwrapCryptoPro(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int in_GS_OFFSET;
  undefined local_44 [4];
  undefined local_40 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  keyDiversifyCryptoPro(param_1,param_2,param_3,local_40);
  gost_key(param_1,local_40);
  gost_dec(param_1,param_3 + 8,param_4,4);
  gost_mac_iv(param_1,0x20,param_3,param_4,0x20,local_44);
  iVar1 = memcmp(local_44,(void *)(param_3 + 0x28),4);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1 == 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

