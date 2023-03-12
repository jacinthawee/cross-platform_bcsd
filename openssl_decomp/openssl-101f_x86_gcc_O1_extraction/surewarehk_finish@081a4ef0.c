
undefined4 surewarehk_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  int line;
  
  if (surewarehk_dso == (DSO *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    line = 0x227;
    iVar1 = 0x70;
  }
  else {
    (*p_surewarehk_Finish)();
    uVar2 = 1;
    iVar1 = DSO_free(surewarehk_dso);
    if (iVar1 != 0) goto LAB_081a4f25;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    line = 0x22e;
    iVar1 = 0x68;
  }
  uVar2 = 0;
  ERR_put_error(SUREWARE_lib_error_code,0x67,iVar1,"e_sureware.c",line);
LAB_081a4f25:
  if (logstream != (BIO *)0x0) {
    BIO_free(logstream);
  }
  surewarehk_dso = (DSO *)0x0;
  p_surewarehk_Init = 0;
  p_surewarehk_Finish = (code *)0x0;
  p_surewarehk_Rand_Bytes = 0;
  p_surewarehk_Rand_Seed = 0;
  p_surewarehk_Load_Privkey = 0;
  p_surewarehk_Load_Rsa_Pubkey = 0;
  p_surewarehk_Free = 0;
  p_surewarehk_Rsa_Priv_Dec = 0;
  p_surewarehk_Rsa_Sign = 0;
  p_surewarehk_Dsa_Sign = 0;
  p_surewarehk_Info_Pubkey = 0;
  p_surewarehk_Load_Dsa_Pubkey = 0;
  p_surewarehk_Mod_Exp = 0;
  return uVar2;
}

