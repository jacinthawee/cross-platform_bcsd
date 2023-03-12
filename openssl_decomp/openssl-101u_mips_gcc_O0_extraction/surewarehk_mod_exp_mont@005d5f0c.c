
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int surewarehk_mod_exp_mont
              (int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  char *pcStack_ec;
  undefined4 uStack_e8;
  char cStack_e4;
  undefined auStack_e3 [47];
  int iStack_b4;
  int *piStack_ac;
  undefined *puStack_a8;
  undefined4 *puStack_a4;
  undefined *puStack_a0;
  code *pcStack_9c;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  int local_7c;
  undefined *local_78;
  int local_6c;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_58;
  undefined auStack_56 [50];
  undefined4 *local_24;
  
  puStack_a8 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iVar6 = 0;
  local_78 = &_gp;
  local_64 = DAT_0067430c;
  local_60 = DAT_00674310;
  local_5c = DAT_00674314;
  local_58 = DAT_00674318;
  (*(code *)PTR_memset_006a99f4)(auStack_56,0,0x32);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
    param_1 = (int *)&_gp_1;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(local_78 + -0x58a8))();
    }
    local_88 = 0x435;
    iVar6 = 0x6b;
    (**(code **)(local_78 + -0x6eac))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
    iVar2 = 0;
  }
  else {
    if (param_1 != (int *)0x0) {
      (**(code **)(local_78 + -0x68bc))(param_1,param_4[1]);
      iVar6 = param_1[2];
      if (iVar6 == param_4[1]) {
        local_88 = *param_3;
        local_7c = *param_1;
        local_84 = param_2[1] << 2;
        local_80 = *param_2;
        local_6c = (*p_surewarehk_Mod_Exp)(&local_64,iVar6 << 2,*param_4,param_3[1] << 2);
        iVar6 = 0x6b;
        surewarehk_error_handling(&local_64,0x6b,local_6c);
        iVar2 = local_6c;
        if (local_6c == 1) {
          iVar4 = param_4[1];
          param_1[1] = iVar4;
          if (0 < iVar4) {
            iVar5 = *param_1 + iVar4 * 4 + -8;
            do {
              iVar6 = *(int *)(iVar5 + 4);
              if (iVar6 != 0) break;
              iVar4 = iVar4 + -1;
              iVar5 = iVar5 + -4;
            } while (iVar4 != 0);
            param_1[1] = iVar4;
          }
        }
        goto LAB_005d5fcc;
      }
    }
    iVar2 = 0;
  }
LAB_005d5fcc:
  if (local_24 == *(undefined4 **)puStack_a8) {
    return iVar2;
  }
  pcStack_9c = surewarehk_rand_add;
  puVar7 = local_24;
  (**(code **)(local_78 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_a0 = &_gp_1;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_f4 = s_ENGINE_rand_seed_0067434c._0_4_;
  uStack_f0 = s_ENGINE_rand_seed_0067434c._4_4_;
  pcStack_ec = s_ENGINE_rand_seed_0067434c._8_4_;
  uStack_e8 = s_ENGINE_rand_seed_0067434c._12_4_;
  cStack_e4 = s_ENGINE_rand_seed_0067434c[16];
  pcVar9 = s_ENGINE_rand_seed_0067434c._8_4_;
  piStack_ac = param_1;
  puStack_a4 = param_4;
  (*(code *)PTR_memset_006a99f4)(auStack_e3,0,0x2f);
  if (p_surewarehk_Rand_Seed == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    pcVar9 = "e_sureware.c";
    puVar7 = (undefined4 *)&DAT_0000006d;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6d,0x75,"e_sureware.c",0x2a1);
  }
  else {
    uVar3 = (*p_surewarehk_Rand_Seed)(&uStack_f4,puVar7,iVar6);
    switch(uVar3) {
    case 1:
      goto switchD_005d61c8_caseD_1;
    case 0xfffffffb:
      uVar8 = 0x6a;
      uVar3 = 0x27b;
      break;
    case 0xfffffffc:
      uVar8 = 0x67;
      uVar3 = 0x278;
      break;
    case 0xfffffffd:
      uVar8 = 0x68;
      uVar3 = 0x272;
      break;
    case 0xfffffffe:
      uVar8 = 0x66;
      uVar3 = 0x275;
      break;
    default:
      uVar8 = 0x65;
      uVar3 = 0x27e;
    }
    pcVar9 = "e_sureware.c";
    puVar7 = (undefined4 *)&DAT_0000006d;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0x6d,uVar8,"e_sureware.c",uVar3);
    if ((uStack_f4._0_1_ != '\0') &&
       (puVar7 = &uStack_f4, (*(code *)PTR_ERR_add_error_data_006a813c)(1), logstream != (char *)0x0
       )) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x15,"e_sureware.c",0x286);
      uVar3 = (*(code *)PTR_strlen_006a9a24)(&uStack_f4);
      (*(code *)PTR_BIO_write_006a6e14)(logstream,&uStack_f4,uVar3);
      pcVar9 = (char *)0x288;
      puVar7 = (undefined4 *)&DAT_00000015;
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x15,"e_sureware.c");
    }
  }
switchD_005d61c8_caseD_1:
  if (iStack_b4 == *(int *)puVar1) {
    return *(int *)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (puVar7 == (undefined4 *)0x1) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_sureware.c",0x19a);
    if (logstream != (char *)0x0) {
      (*(code *)PTR_BIO_free_006a6e70)();
      logstream = (char *)0x0;
    }
    iVar6 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(pcVar9 + 0x2c,1,0x15,"e_sureware.c",0x19f);
    if (iVar6 < 2) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,100,100,"e_sureware.c",0x1a3);
      pcVar9 = logstream;
    }
    logstream = pcVar9;
    uVar3 = 0x1a5;
  }
  else {
    if (puVar7 != (undefined4 *)&DAT_00000065) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,100,0x77,"e_sureware.c",0x1b7);
      return 0;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_sureware.c",0x1af);
    uVar3 = 0x1b1;
    threadsafe = 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_sureware.c",uVar3);
  return 1;
}

