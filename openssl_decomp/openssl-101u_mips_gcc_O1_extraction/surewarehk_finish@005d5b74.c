
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 surewarehk_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (surewarehk_dso == 0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar2 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x67,0x70,"e_sureware.c",0x250);
  }
  else {
    (*p_surewarehk_Finish)();
    iVar1 = (*(code *)PTR_DSO_free_006a8874)(surewarehk_dso);
    if (iVar1 == 0) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x67,0x68,"e_sureware.c",0x256);
    }
    else {
      uVar2 = 1;
    }
  }
  if (logstream != 0) {
    (*(code *)PTR_BIO_free_006a6e70)();
  }
  surewarehk_dso = 0;
  p_surewarehk_Init = 0;
  p_surewarehk_Finish = (code *)0x0;
  p_surewarehk_Rand_Bytes = 0;
  p_surewarehk_Mod_Exp = 0;
  p_surewarehk_Rand_Seed = 0;
  p_surewarehk_Load_Privkey = 0;
  p_surewarehk_Load_Rsa_Pubkey = 0;
  p_surewarehk_Free = 0;
  p_surewarehk_Rsa_Priv_Dec = 0;
  p_surewarehk_Rsa_Sign = 0;
  p_surewarehk_Dsa_Sign = 0;
  p_surewarehk_Info_Pubkey = 0;
  p_surewarehk_Load_Dsa_Pubkey = 0;
  return uVar2;
}

