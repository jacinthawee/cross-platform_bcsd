
bool cca_rsa_priv_dec(undefined4 param_1,undefined4 param_2,undefined4 param_3,RSA *param_4)

{
  undefined4 *puVar1;
  int in_GS_OFFSET;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined local_28 [8];
  undefined4 local_20;
  undefined4 local_1c;
  undefined local_18 [8];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_3c = 0;
  local_38 = 1;
  local_40 = param_1;
  local_20 = 0x53434b50;
  local_1c = 0x322e312d;
  local_34 = 0;
  local_30 = RSA_size(param_4);
  puVar1 = (undefined4 *)RSA_get_ex_data(param_4,hndidx);
  local_2c = *puVar1;
  (*pkaDecrypt)(&local_48,&local_44,&local_3c,local_28,&local_38,&local_20,&local_40,param_2,
                &local_34,local_18,&local_2c,puVar1 + 1,&local_30,param_3);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (local_48 | local_44) == 0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

