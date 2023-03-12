
uint cca_rsa_priv_dec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  int iStack_ec;
  uint uStack_e8;
  int iStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  uint uStack_d4;
  undefined4 uStack_d0;
  undefined auStack_cc [8];
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined auStack_bc [8];
  int iStack_b4;
  undefined *puStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  code *pcStack_9c;
  undefined4 *local_88;
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined *local_74;
  undefined4 *local_70;
  undefined4 *local_6c;
  undefined4 *local_68;
  undefined4 local_64;
  undefined *local_60;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined auStack_34 [8];
  undefined4 local_2c;
  undefined4 local_28;
  undefined auStack_24 [8];
  int local_1c;
  
  puStack_ac = PTR___stack_chk_guard_006aabf0;
  local_44 = 1;
  local_60 = &_gp;
  local_48 = 0;
  local_40 = 0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_2c = DAT_00673d70;
  local_28 = DAT_00673d74;
  local_4c = param_1;
  local_3c = (*(code *)PTR_RSA_size_006a8730)(param_4);
  puVar2 = (undefined4 *)(**(code **)(local_60 + -0x58a0))(param_4,hndidx);
  local_6c = puVar2 + 1;
  local_38 = *puVar2;
  puVar6 = auStack_34;
  puVar2 = &local_48;
  local_70 = &local_38;
  local_68 = &local_3c;
  local_74 = auStack_24;
  local_78 = &local_40;
  local_80 = &local_4c;
  local_84 = &local_2c;
  local_88 = &local_44;
  local_7c = param_2;
  local_64 = param_3;
  (*pkaDecrypt)(&local_54,&local_50);
  if (local_1c == *(int *)puStack_ac) {
    return (uint)((local_54 | local_50) == 0);
  }
  pcStack_9c = cca_rsa_pub_enc;
  iStack_e4 = local_1c;
  (**(code **)(local_60 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uStack_dc = 1;
  uStack_e0 = 0;
  uStack_d8 = 0;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_c4 = DAT_00673d70;
  uStack_c0 = DAT_00673d74;
  uStack_a8 = param_4;
  uStack_a4 = param_2;
  uStack_a0 = param_3;
  uStack_d4 = (*(code *)PTR_RSA_size_006a8730)(puVar6);
  puVar3 = (undefined4 *)(*(code *)PTR_RSA_get_ex_data_006aa640)(puVar6,hndidx);
  uStack_d0 = *puVar3;
  (*pkaEncrypt)(&iStack_ec,&uStack_e8,&uStack_e0,auStack_cc,&uStack_dc,&uStack_c4,&iStack_e4,
                local_50,&uStack_d8,auStack_bc,&uStack_d0,puVar3 + 1,&uStack_d4,puVar2);
  if ((iStack_ec != 0) || (uVar4 = uStack_d4, uStack_e8 != 0)) {
    uVar4 = -(iStack_ec << 0x10 | uStack_e8);
  }
  if (iStack_b4 != *(int *)puVar1) {
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
    iVar5 = (*(code *)PTR_DSO_free_006a9994)();
    if (iVar5 == 0) {
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
    pkaDecrypt = (code *)0x0;
    return 1;
  }
  return uVar4;
}

