
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 *
surewarehk_modexp_dh
          (undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
          undefined4 *param_5)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined4 *unaff_s6;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  char *pcStack_184;
  undefined4 uStack_180;
  char cStack_17c;
  undefined auStack_17b [47];
  undefined4 *puStack_14c;
  int *piStack_144;
  undefined *puStack_140;
  char *pcStack_13c;
  undefined *puStack_138;
  code *pcStack_134;
  undefined4 uStack_120;
  int iStack_11c;
  undefined4 uStack_118;
  int iStack_114;
  undefined *puStack_110;
  undefined4 *puStack_104;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined2 uStack_f0;
  undefined auStack_ee [50];
  undefined4 *puStack_bc;
  int *piStack_b8;
  undefined *puStack_b4;
  undefined4 *puStack_b0;
  undefined *puStack_ac;
  undefined4 *puStack_a8;
  undefined4 *puStack_a4;
  undefined4 *puStack_a0;
  code *pcStack_9c;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  int local_7c;
  undefined *local_78;
  undefined4 *local_6c;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined2 local_58;
  undefined auStack_56 [50];
  int *local_24;
  
  puStack_b4 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int **)PTR___stack_chk_guard_006a9ae8;
  puVar8 = (undefined4 *)&DAT_00000032;
  puVar6 = (undefined4 *)0x0;
  local_78 = &_gp;
  local_64 = DAT_0067430c;
  local_60 = DAT_00674310;
  local_5c = DAT_00674314;
  local_58 = DAT_00674318;
  pcStack_13c = (char *)param_4;
  (*(code *)PTR_memset_006a99f4)(auStack_56);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
    param_2 = (int *)&_gp_1;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(local_78 + -0x58a8))();
    }
    puVar8 = (undefined4 *)0x75;
    pcStack_13c = "e_sureware.c";
    local_88 = 0x435;
    puVar6 = (undefined4 *)&DAT_0000006b;
    (**(code **)(local_78 + -0x6eac))(SUREWARE_lib_error_code);
    puVar2 = (undefined4 *)0x0;
  }
  else {
    if (param_2 != (int *)0x0) {
      (**(code **)(local_78 + -0x68bc))(param_2,param_5[1]);
      puVar6 = (undefined4 *)param_2[2];
      if (puVar6 == (undefined4 *)param_5[1]) {
        unaff_s6 = &local_64;
        local_88 = *param_4;
        local_7c = *param_2;
        local_84 = param_3[1] << 2;
        local_80 = *param_3;
        pcStack_13c = (char *)(param_4[1] << 2);
        puVar8 = (undefined4 *)(*p_surewarehk_Mod_Exp)(unaff_s6,(int)puVar6 << 2,*param_5);
        puVar6 = (undefined4 *)&DAT_0000006b;
        local_6c = puVar8;
        surewarehk_error_handling(unaff_s6);
        puVar2 = local_6c;
        if (local_6c == (undefined4 *)0x1) {
          iVar7 = param_5[1];
          param_2[1] = iVar7;
          if (0 < iVar7) {
            iVar4 = *param_2 + iVar7 * 4 + -8;
            do {
              puVar6 = *(undefined4 **)(iVar4 + 4);
              if (puVar6 != (undefined4 *)0x0) break;
              iVar7 = iVar7 + -1;
              iVar4 = iVar4 + -4;
            } while (iVar7 != 0);
            param_2[1] = iVar7;
          }
        }
        goto LAB_005d5dd4;
      }
    }
    puVar2 = (undefined4 *)0x0;
  }
LAB_005d5dd4:
  if (local_24 == *(int **)puStack_b4) {
    return puVar2;
  }
  pcStack_9c = surewarehk_mod_exp_mont;
  piStack_144 = local_24;
  (**(code **)(local_78 + -0x5330))();
  puStack_140 = PTR___stack_chk_guard_006a9ae8;
  puStack_ac = &_gp_1;
  puStack_bc = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iVar7 = 0;
  puStack_b0 = param_5;
  puStack_110 = &_gp;
  uStack_fc = DAT_0067430c;
  uStack_f8 = DAT_00674310;
  uStack_f4 = DAT_00674314;
  uStack_f0 = DAT_00674318;
  piStack_b8 = param_2;
  puStack_a8 = param_3;
  puStack_a4 = param_4;
  puStack_a0 = unaff_s6;
  (*(code *)PTR_memset_006a99f4)(auStack_ee,0,0x32);
  if (p_surewarehk_Mod_Exp == (code *)0x0) {
    piStack_144 = (int *)&_gp_1;
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (**(code **)(puStack_110 + -0x58a8))();
    }
    uStack_120 = 0x435;
    iVar7 = 0x6b;
    (**(code **)(puStack_110 + -0x6eac))(SUREWARE_lib_error_code,0x6b,0x75,"e_sureware.c");
    puVar8 = (undefined4 *)0x0;
  }
  else {
    if (piStack_144 != (int *)0x0) {
      (**(code **)(puStack_110 + -0x68bc))(piStack_144,*(undefined4 *)((int)pcStack_13c + 4));
      iVar7 = piStack_144[2];
      if (iVar7 == *(int *)((int)pcStack_13c + 4)) {
        uStack_120 = *puVar8;
        iStack_114 = *piStack_144;
        iStack_11c = puVar6[1] << 2;
        uStack_118 = *puVar6;
        puStack_104 = (undefined4 *)
                      (*p_surewarehk_Mod_Exp)
                                (&uStack_fc,iVar7 << 2,*(undefined4 *)pcStack_13c,puVar8[1] << 2);
        iVar7 = 0x6b;
        surewarehk_error_handling(&uStack_fc,0x6b,puStack_104);
        puVar8 = puStack_104;
        if (puStack_104 == (undefined4 *)0x1) {
          iVar4 = *(int *)((int)pcStack_13c + 4);
          piStack_144[1] = iVar4;
          if (0 < iVar4) {
            iVar5 = *piStack_144 + iVar4 * 4 + -8;
            do {
              iVar7 = *(int *)(iVar5 + 4);
              if (iVar7 != 0) break;
              iVar4 = iVar4 + -1;
              iVar5 = iVar5 + -4;
            } while (iVar4 != 0);
            piStack_144[1] = iVar4;
          }
        }
        goto LAB_005d5fcc;
      }
    }
    puVar8 = (undefined4 *)0x0;
  }
LAB_005d5fcc:
  if (puStack_bc == *(undefined4 **)puStack_140) {
    return puVar8;
  }
  pcStack_134 = surewarehk_rand_add;
  puVar8 = puStack_bc;
  (**(code **)(puStack_110 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_138 = &_gp_1;
  puStack_14c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  uStack_18c = s_ENGINE_rand_seed_0067434c._0_4_;
  uStack_188 = s_ENGINE_rand_seed_0067434c._4_4_;
  pcStack_184 = s_ENGINE_rand_seed_0067434c._8_4_;
  uStack_180 = s_ENGINE_rand_seed_0067434c._12_4_;
  cStack_17c = s_ENGINE_rand_seed_0067434c[16];
  pcVar10 = s_ENGINE_rand_seed_0067434c._8_4_;
  (*(code *)PTR_memset_006a99f4)(auStack_17b,0,0x2f);
  if (p_surewarehk_Rand_Seed == (code *)0x0) {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    pcVar10 = "e_sureware.c";
    puVar8 = (undefined4 *)&DAT_0000006d;
    (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,0x6d,0x75,"e_sureware.c",0x2a1);
  }
  else {
    uVar3 = (*p_surewarehk_Rand_Seed)(&uStack_18c,puVar8,iVar7);
    switch(uVar3) {
    case 1:
      goto switchD_005d61c8_caseD_1;
    case 0xfffffffb:
      uVar9 = 0x6a;
      uVar3 = 0x27b;
      break;
    case 0xfffffffc:
      uVar9 = 0x67;
      uVar3 = 0x278;
      break;
    case 0xfffffffd:
      uVar9 = 0x68;
      uVar3 = 0x272;
      break;
    case 0xfffffffe:
      uVar9 = 0x66;
      uVar3 = 0x275;
      break;
    default:
      uVar9 = 0x65;
      uVar3 = 0x27e;
    }
    pcVar10 = "e_sureware.c";
    puVar8 = (undefined4 *)&DAT_0000006d;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x26,0x6d,uVar9,"e_sureware.c",uVar3);
    if ((uStack_18c._0_1_ != '\0') &&
       (puVar8 = &uStack_18c, (*(code *)PTR_ERR_add_error_data_006a813c)(1),
       logstream != (char *)0x0)) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x15,"e_sureware.c",0x286);
      uVar3 = (*(code *)PTR_strlen_006a9a24)(&uStack_18c);
      (*(code *)PTR_BIO_write_006a6e14)(logstream,&uStack_18c,uVar3);
      pcVar10 = (char *)0x288;
      puVar8 = (undefined4 *)&DAT_00000015;
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x15,"e_sureware.c");
    }
  }
switchD_005d61c8_caseD_1:
  if (puStack_14c == *(undefined4 **)puVar1) {
    return *(undefined4 **)puVar1;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (puVar8 == (undefined4 *)0x1) {
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_sureware.c",0x19a);
    if (logstream != (char *)0x0) {
      (*(code *)PTR_BIO_free_006a6e70)();
      logstream = (char *)0x0;
    }
    iVar7 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(pcVar10 + 0x2c,1,0x15,"e_sureware.c",0x19f);
    if (iVar7 < 2) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,100,100,"e_sureware.c",0x1a3);
      pcVar10 = logstream;
    }
    logstream = pcVar10;
    uVar3 = 0x1a5;
  }
  else {
    if (puVar8 != (undefined4 *)&DAT_00000065) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(SUREWARE_lib_error_code,100,0x77,"e_sureware.c",0x1b7);
      return (undefined4 *)0x0;
    }
    (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"e_sureware.c",0x1af);
    uVar3 = 0x1b1;
    threadsafe = 0;
  }
  (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"e_sureware.c",uVar3);
  return (undefined4 *)0x1;
}

