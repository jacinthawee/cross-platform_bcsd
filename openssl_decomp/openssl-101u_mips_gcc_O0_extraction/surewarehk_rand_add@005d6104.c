
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int surewarehk_rand_add(undefined4 *param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 local_5c;
  undefined4 local_58;
  char *local_54;
  undefined4 local_50;
  char local_4c;
  undefined auStack_4b [47];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_5c = s_ENGINE_rand_seed_0067434c._0_4_;
  local_58 = s_ENGINE_rand_seed_0067434c._4_4_;
  local_54 = s_ENGINE_rand_seed_0067434c._8_4_;
  local_50 = s_ENGINE_rand_seed_0067434c._12_4_;
  local_4c = s_ENGINE_rand_seed_0067434c[16];
  pcVar5 = s_ENGINE_rand_seed_0067434c._8_4_;
  (*(code *)PTR_memset_006a99f4)(auStack_4b,0,0x2f);
  if (p_surewarehk_Rand_Seed == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    pcVar5 = "e_sureware.c";
    param_1 = (undefined4 *)&DAT_0000006d;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6d,0x75,"e_sureware.c",0x2a1);
  }
  else {
    uVar2 = (*p_surewarehk_Rand_Seed)(&local_5c,param_1,param_2);
    switch(uVar2) {
    case 1:
      goto switchD_005d61c8_caseD_1;
    case 0xfffffffb:
      uVar4 = 0x6a;
      uVar2 = 0x27b;
      break;
    case 0xfffffffc:
      uVar4 = 0x67;
      uVar2 = 0x278;
      break;
    case 0xfffffffd:
      uVar4 = 0x68;
      uVar2 = 0x272;
      break;
    case 0xfffffffe:
      uVar4 = 0x66;
      uVar2 = 0x275;
      break;
    default:
      uVar4 = 0x65;
      uVar2 = 0x27e;
    }
    pcVar5 = "e_sureware.c";
    param_1 = (undefined4 *)&DAT_0000006d;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0x6d,uVar4,"e_sureware.c",uVar2);
    if ((local_5c._0_1_ != '\0') &&
       (param_1 = &local_5c, (*(code *)PTR_ERR_add_error_data_006a813c)(1), logstream != (char *)0x0
       )) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x15,"e_sureware.c",0x286);
      uVar2 = (*(code *)PTR_strlen_006a9a24)(&local_5c);
      (*(code *)PTR_BIO_write_006a6e14)(logstream,&local_5c,uVar2);
      pcVar5 = (char *)0x288;
      param_1 = (undefined4 *)&DAT_00000015;
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x15,"e_sureware.c");
    }
  }
switchD_005d61c8_caseD_1:
  if (local_1c == *(int *)puVar1) {
    return *(int *)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (param_1 == (undefined4 *)0x1) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_sureware.c",0x19a);
    if (logstream != (char *)0x0) {
      (*(code *)PTR_BIO_free_006a6e70)();
      logstream = (char *)0x0;
    }
    iVar3 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(pcVar5 + 0x2c,1,0x15,"e_sureware.c",0x19f);
    if (iVar3 < 2) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,100,100,"e_sureware.c",0x1a3);
      pcVar5 = logstream;
    }
    logstream = pcVar5;
    uVar2 = 0x1a5;
  }
  else {
    if (param_1 != (undefined4 *)&DAT_00000065) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,100,0x77,"e_sureware.c",0x1b7);
      return 0;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_sureware.c",0x1af);
    uVar2 = 0x1b1;
    threadsafe = 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_sureware.c",uVar2);
  return 1;
}

