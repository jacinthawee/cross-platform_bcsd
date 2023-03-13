
int surewarehk_rsa_sign(undefined4 param_1,undefined4 param_2,undefined4 param_3,RSA *param_4,
                       int param_5)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_GS_OFFSET;
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [12];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_50 = 0x49474e45;
  puVar3 = local_40;
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_4c = 0x725f454e;
  local_48 = 0x735f6173;
  local_44 = 0x6e6769;
  if (p_surewarehk_Rsa_Sign == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6f,0x75,"e_sureware.c",0x3df);
    iVar2 = 0;
  }
  else {
    pvVar1 = RSA_get_ex_data(param_4,rsaHndidx);
    if (pvVar1 == (void *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6f,0x69,"e_sureware.c",0x3e4);
      iVar2 = 0;
    }
    else if (param_5 == 1) {
      iVar2 = (*p_surewarehk_Rsa_Sign)(&local_50,param_1,param_2,&local_54,param_3,pvVar1,1);
      surewarehk_error_handling();
      if (iVar2 == 1) {
        iVar2 = local_54;
      }
    }
    else {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6f,0x6b,"e_sureware.c",0x3f1);
      iVar2 = 0;
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

