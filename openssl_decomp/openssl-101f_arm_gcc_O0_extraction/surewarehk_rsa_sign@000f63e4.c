
void surewarehk_rsa_sign(undefined4 param_1,undefined4 param_2,undefined4 param_3,RSA *param_4,
                        int param_5)

{
  void *pvVar1;
  int iVar2;
  int local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  local_64 = *(undefined4 *)PTR_s_ENGINE_rsa_sign_000f6500;
  uStack_60 = *(undefined4 *)(PTR_s_ENGINE_rsa_sign_000f6500 + 4);
  uStack_5c = *(undefined4 *)(PTR_s_ENGINE_rsa_sign_000f6500 + 8);
  uStack_58 = *(undefined4 *)(PTR_s_ENGINE_rsa_sign_000f6500 + 0xc);
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = __TMC_END__;
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6f,0x75,"e_sureware.c",0x3ad);
  }
  else {
    pvVar1 = RSA_get_ex_data(param_4,rsaHndidx);
    if (pvVar1 == (void *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6f,0x69,"e_sureware.c",0x3b2);
    }
    else {
      if (param_5 == 1) {
        iVar2 = (*p_surewarehk_Rsa_Sign)(&local_64,param_1,param_2,&local_68,param_3,pvVar1,1);
        surewarehk_error_handling(&local_64,0x6f,iVar2);
        if (iVar2 == 1) {
          iVar2 = local_68;
        }
        goto LAB_000f647a;
      }
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6f,0x6b,"e_sureware.c",0x3be);
    }
  }
  iVar2 = 0;
LAB_000f647a:
  if (local_24 == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(iVar2);
}

