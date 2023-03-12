
int cca_rsa_pub_enc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_38;
  undefined auStack_34 [8];
  undefined4 local_2c;
  undefined4 local_28;
  undefined auStack_24 [8];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_44 = 1;
  local_48 = 0;
  local_40 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_2c = DAT_00673d70;
  local_28 = DAT_00673d74;
  local_4c = param_1;
  local_3c = (*(code *)PTR_RSA_size_006a8730)(param_4);
  puVar2 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006aa640)(param_4,hndidx);
  local_38 = *puVar2;
  (*pkaEncrypt)(&local_54,&local_50,&local_48,auStack_34,&local_44,&local_2c,&local_4c,param_2,
                &local_40,auStack_24,&local_38,puVar2 + 1,&local_3c,param_3);
  if ((local_54 != 0) || (iVar3 = local_3c, local_50 != 0)) {
    iVar3 = -(local_54 << 0x10 | local_50);
  }
  if (local_1c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (CCA4758_LIB_NAME != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    CCA4758_LIB_NAME = 0;
    if (dso == 0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(CCA4758_lib_error_code,0x65,0x6a,"e_4758cca.c",0x158);
      return 0;
    }
    iVar3 = (*(code *)PTR_DSO_free_006a9994)();
    if (iVar3 == 0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(CCA4758_lib_error_code,0x65,0x6c,"e_4758cca.c",0x15e);
      return 0;
    }
    dso = 0;
    keyRecordRead = 0;
    randomNumberGenerate = 0;
    digitalSignatureGenerate = 0;
    digitalSignatureVerify = 0;
    publicKeyExtract = 0;
    pkaEncrypt = (code *)0x0;
    pkaDecrypt = 0;
    return 1;
  }
  return iVar3;
}

