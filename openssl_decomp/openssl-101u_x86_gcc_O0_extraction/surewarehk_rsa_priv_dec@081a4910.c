
size_t surewarehk_rsa_priv_dec
                 (int param_1,undefined4 param_2,uchar *param_3,RSA *param_4,int param_5)

{
  void *pvVar1;
  size_t sVar2;
  uchar *f;
  int iVar3;
  undefined4 *puVar4;
  int in_GS_OFFSET;
  size_t local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c [11];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_50 = 0x49474e45;
  puVar4 = local_3c;
  for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_4c = 0x725f454e;
  local_48 = 0x705f6173;
  local_44 = 0x5f766972;
  local_40 = 0x636564;
  if (p_surewarehk_Rsa_Priv_Dec == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6e,0x75,"e_sureware.c",0x38f);
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = RSA_get_ex_data(param_4,rsaHndidx);
    if (pvVar1 == (void *)0x0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6e,0x69,"e_sureware.c",0x394);
      sVar2 = 0;
      goto LAB_081a49c7;
    }
  }
  if (param_5 == 1) {
    sVar2 = (*p_surewarehk_Rsa_Priv_Dec)(&local_50,param_1,param_2,&local_54,param_3,pvVar1,1);
    surewarehk_error_handling();
    if (sVar2 == 1) {
      sVar2 = local_54;
    }
    goto LAB_081a49c7;
  }
  sVar2 = (*p_surewarehk_Rsa_Priv_Dec)(&local_50,param_1,param_2,&local_54,param_3,pvVar1,0);
  surewarehk_error_handling();
  if (sVar2 != 1) goto LAB_081a49c7;
  f = (uchar *)CRYPTO_malloc(local_54,"e_sureware.c",0x3ac);
  if (f == (uchar *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c",0x3ae);
    goto LAB_081a49c7;
  }
  memcpy(f,param_3,local_54);
  if (param_5 == 3) {
    sVar2 = RSA_padding_check_none(param_3,local_54,f,param_1,local_54);
LAB_081a4b5a:
    if ((int)sVar2 < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c",0x3cb);
    }
  }
  else {
    if (param_5 == 4) {
      sVar2 = RSA_padding_check_PKCS1_OAEP(param_3,local_54,f,local_54,local_54,(uchar *)0x0,0);
      goto LAB_081a4b5a;
    }
    if (param_5 == 2) {
      sVar2 = RSA_padding_check_SSLv23(param_3,local_54,f,param_1,local_54);
      goto LAB_081a4b5a;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c",0x3c6);
  }
  OPENSSL_cleanse(f,local_54);
  CRYPTO_free(f);
LAB_081a49c7:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return sVar2;
}

