
void cca_rsa_pub_enc(undefined4 param_1,undefined4 param_2,undefined4 param_3,RSA *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  undefined auStack_3c [8];
  undefined4 local_34;
  undefined4 uStack_30;
  undefined auStack_2c [8];
  int local_24;
  
  local_34 = DAT_0016e3a0;
  uStack_30 = DAT_0016e3a4;
  local_50 = 0;
  local_48 = 0;
  local_4c = 1;
  local_24 = __stack_chk_guard;
  local_54 = param_1;
  local_44 = RSA_size(param_4);
  puVar1 = (undefined4 *)RSA_get_ex_data(param_4,hndidx);
  local_40 = *puVar1;
  (*pkaEncrypt)(&local_5c,&local_58,&local_50,auStack_3c,&local_4c,&local_34,&local_54,param_2,
                &local_48,auStack_2c,&local_40,puVar1 + 1,&local_44,param_3);
  if ((local_5c != 0) || (iVar2 = local_44, local_58 != 0)) {
    iVar2 = -(local_58 | local_5c << 0x10);
  }
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}
