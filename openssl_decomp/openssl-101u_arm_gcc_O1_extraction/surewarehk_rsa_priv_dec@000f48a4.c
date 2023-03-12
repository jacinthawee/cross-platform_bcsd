
void surewarehk_rsa_priv_dec(int param_1,undefined4 param_2,uchar *param_3,RSA *param_4,int param_5)

{
  void *pvVar1;
  size_t sVar2;
  uchar *f;
  size_t local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 local_58;
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
  int local_2c;
  
  local_6c = *(undefined4 *)PTR_s_ENGINE_rsa_priv_dec_000f4ac4;
  uStack_68 = *(undefined4 *)(PTR_s_ENGINE_rsa_priv_dec_000f4ac4 + 4);
  uStack_64 = *(undefined4 *)(PTR_s_ENGINE_rsa_priv_dec_000f4ac4 + 8);
  uStack_60 = *(undefined4 *)(PTR_s_ENGINE_rsa_priv_dec_000f4ac4 + 0xc);
  local_5c = *(undefined4 *)(PTR_s_ENGINE_rsa_priv_dec_000f4ac4 + 0x10);
  local_2c = __stack_chk_guard;
  local_58 = 0;
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
      goto LAB_000f4946;
    }
  }
  if (param_5 == 1) {
    sVar2 = (*p_surewarehk_Rsa_Priv_Dec)(&local_6c,param_1,param_2,&local_70,param_3,pvVar1,1);
    surewarehk_error_handling(&local_6c,0x6e,sVar2);
    if (sVar2 == 1) {
      sVar2 = local_70;
    }
    goto LAB_000f4946;
  }
  sVar2 = (*p_surewarehk_Rsa_Priv_Dec)(&local_6c,param_1,param_2,&local_70,param_3,pvVar1,0);
  surewarehk_error_handling(&local_6c,0x6e,sVar2);
  if (sVar2 != 1) goto LAB_000f4946;
  f = (uchar *)CRYPTO_malloc(local_70,"e_sureware.c",0x3ac);
  if (f == (uchar *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6e,0x41,"e_sureware.c",0x3ae);
    goto LAB_000f4946;
  }
  memcpy(f,param_3,local_70);
  if (param_5 == 3) {
    sVar2 = RSA_padding_check_none(param_3,local_70,f,param_1,local_70);
LAB_000f4a44:
    if ((int)sVar2 < 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,0x6e,0x6a,"e_sureware.c",0x3cb);
    }
  }
  else {
    if (param_5 == 4) {
      sVar2 = RSA_padding_check_PKCS1_OAEP(param_3,local_70,f,local_70,local_70,(uchar *)0x0,0);
      goto LAB_000f4a44;
    }
    if (param_5 == 2) {
      sVar2 = RSA_padding_check_SSLv23(param_3,local_70,f,param_1,local_70);
      goto LAB_000f4a44;
    }
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,0x6e,0x6b,"e_sureware.c",0x3c6);
  }
  OPENSSL_cleanse(f,local_70);
  CRYPTO_free(f);
LAB_000f4946:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(sVar2);
  }
  return;
}

