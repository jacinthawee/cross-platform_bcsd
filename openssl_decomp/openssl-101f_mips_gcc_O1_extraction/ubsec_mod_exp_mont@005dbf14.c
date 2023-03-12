
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint ubsec_mod_exp_mont(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,
                       undefined4 *param_4,undefined4 param_5,undefined1 *param_6)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char *pcVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  code *pcVar18;
  undefined4 unaff_s8;
  int iStack_a4;
  int iStack_a0;
  int iStack_9c;
  undefined4 *puStack_98;
  undefined *puStack_94;
  undefined4 *puStack_90;
  undefined4 *puStack_8c;
  undefined4 *puStack_88;
  undefined4 uStack_84;
  undefined1 *puStack_80;
  undefined1 *puStack_7c;
  undefined4 uStack_78;
  code *pcStack_74;
  undefined4 local_60;
  undefined1 *local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int *local_50;
  undefined *local_48;
  code *local_40;
  undefined4 *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  
  puStack_94 = PTR___stack_chk_guard_006aabf0;
  puStack_7c = (undefined1 *)0x6a0000;
  local_48 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(param_4);
  puVar9 = param_2;
  if (max_key_len < iVar2) {
    iVar2 = (**(code **)(local_48 + -0x7308))();
    local_5c = param_6;
    local_60 = param_5;
    pcVar12 = (char *)param_4;
    uVar7 = (**(code **)(iVar2 + 0x18))(param_1,param_2,param_3);
  }
  else {
    local_30 = 0;
    if (ubsec_dso == 0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (**(code **)(local_48 + -0x589c))();
      }
      pcVar18 = *(code **)(local_48 + -0x6eb0);
      uVar15 = 0x69;
      local_60 = 0x234;
LAB_005dc264:
      pcVar12 = "e_ubsec.c";
      param_4 = (undefined4 *)&_ITM_registerTMCloneTable;
      puVar9 = (undefined4 *)&DAT_0000006a;
      (*pcVar18)(UBSEC_lib_error_code,0x6a,uVar15);
      uVar7 = 0;
    }
    else {
      local_30 = (**(code **)(local_48 + -0x7bec))(param_4);
      if (max_key_len < local_30) {
        param_6 = &_ITM_registerTMCloneTable;
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (**(code **)(local_48 + -0x589c))();
        }
        local_60 = 0x23b;
        (**(code **)(local_48 + -0x6eb0))(UBSEC_lib_error_code,0x6a,0x6b,"e_ubsec.c");
      }
      else {
        if (((int)param_1[2] < (int)param_4[1]) &&
           (iVar2 = (**(code **)(local_48 + -0x6860))(param_1), iVar2 == 0)) {
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = (**(code **)(local_48 + -0x589c))();
          }
          pcVar18 = *(code **)(local_48 + -0x6eb0);
          uVar15 = 0x65;
          local_60 = 0x241;
          goto LAB_005dc264;
        }
        param_6 = (undefined1 *)(*p_UBSEC_ubsec_open)("/dev/ubskey");
        if ((int)param_6 < 1) {
          param_6 = &_ITM_registerTMCloneTable;
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = (**(code **)(local_48 + -0x589c))();
          }
          local_60 = 0x247;
          (**(code **)(local_48 + -0x6eb0))(UBSEC_lib_error_code,0x6a,0x6c,"e_ubsec.c");
        }
        else {
          local_34 = *param_2;
          local_40 = p_UBSEC_rsa_mod_exp_ioctl;
          local_38 = (**(code **)(local_48 + -0x7bec))(param_2);
          local_3c = (undefined4 *)*param_4;
          unaff_s8 = (**(code **)(local_48 + -0x7bec))(param_4);
          puStack_7c = (undefined1 *)*param_3;
          local_58 = (**(code **)(local_48 + -0x7bec))(param_3);
          local_54 = *param_1;
          local_50 = &local_30;
          pcVar12 = (char *)local_3c;
          local_60 = unaff_s8;
          local_5c = puStack_7c;
          iVar2 = (*local_40)(param_6,local_34,local_38);
          if (iVar2 == 0) {
            (*p_UBSEC_ubsec_close)(param_6);
            iVar3 = (**(code **)(local_48 + -0x7bec))(param_4);
            uVar7 = 1;
            puVar9 = (undefined4 *)(uint)(iVar3 + 0x1f < 0);
            iVar2 = iVar3 + 0x1f;
            if (puVar9 != (undefined4 *)0x0) {
              iVar2 = iVar3 + 0x3e;
            }
            param_1[1] = iVar2 >> 5;
            goto LAB_005dc104;
          }
          puStack_7c = &_ITM_registerTMCloneTable;
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = (**(code **)(local_48 + -0x589c))();
          }
          local_60 = 0x24f;
          (**(code **)(local_48 + -0x6eb0))(UBSEC_lib_error_code,0x6a,0x6a,"e_ubsec.c");
          (*p_UBSEC_ubsec_close)(param_6);
        }
      }
      local_60 = param_5;
      pcVar12 = (char *)param_4;
      uVar7 = (**(code **)(local_48 + -0x7498))(param_1,param_2,param_3);
    }
  }
LAB_005dc104:
  if (local_2c == *(int *)puStack_94) {
    return uVar7;
  }
  pcStack_74 = ubsec_dh_generate_key;
  iVar2 = local_2c;
  (**(code **)(local_48 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar13 = *(undefined4 **)(iVar2 + 0x18);
  uStack_84 = param_5;
  uVar15 = 0;
  iStack_a4 = 0;
  iStack_a0 = 0;
  iStack_9c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_98 = param_4;
  puStack_90 = param_1;
  puStack_8c = param_2;
  puStack_88 = param_3;
  puStack_80 = param_6;
  uStack_78 = unaff_s8;
  if (puVar13 == (undefined4 *)0x0) {
    puVar13 = (undefined4 *)(*(code *)PTR_BN_new_006a82b4)();
    if (puVar13 != (undefined4 *)0x0) {
      iStack_a0 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar2 + 8));
      puVar9 = (undefined4 *)(*(undefined4 **)(iVar2 + 8))[1];
      puVar14 = *(undefined4 **)(iVar2 + 8);
      if ((int)puVar13[2] < (int)puVar9) {
        iVar3 = (*(code *)PTR_bn_expand2_006a9680)(puVar13);
        if (iVar3 != 0) goto LAB_005dc64c;
        uVar7 = 0;
        goto LAB_005dc490;
      }
      while (puVar9 = puVar14, iVar3 = (*(code *)PTR_BN_rand_range_006a97b0)(puVar13), iVar3 != 0) {
        if (puVar13[1] != 0) {
          uVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar13);
          goto LAB_005dc37c;
        }
LAB_005dc64c:
        puVar14 = *(undefined4 **)(iVar2 + 8);
      }
    }
LAB_005dc5e4:
    uVar7 = 0;
  }
  else {
LAB_005dc37c:
    puVar14 = *(undefined4 **)(iVar2 + 0x14);
    if (puVar14 == (undefined4 *)0x0) {
      puVar14 = (undefined4 *)(*(code *)PTR_BN_new_006a82b4)();
      iStack_a4 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar2 + 8));
      puVar9 = *(undefined4 **)(*(int *)(iVar2 + 8) + 4);
      if (((int)puVar14[2] < (int)puVar9) &&
         (iVar3 = (*(code *)PTR_bn_expand2_006a9680)(puVar14), iVar3 == 0)) goto LAB_005dc5e4;
    }
    iVar3 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
    pcVar18 = p_UBSEC_diffie_hellman_generate_ioctl;
    if (iVar3 < 1) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      pcVar12 = "e_ubsec.c";
      puVar9 = (undefined4 *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6f,0x6c,"e_ubsec.c",0x3c2);
    }
    else {
      uVar10 = *puVar13;
      uVar11 = *puVar14;
      uVar17 = **(undefined4 **)(iVar2 + 0xc);
      uVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 **)(iVar2 + 0xc));
      uVar16 = **(undefined4 **)(iVar2 + 8);
      uVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 **)(iVar2 + 8));
      iVar6 = (*pcVar18)(iVar3,uVar10,&iStack_a0,uVar11,&iStack_a4,uVar17,uVar4,uVar16,uVar5,0,0,
                         uVar15);
      if (iVar6 == 0) {
        (*p_UBSEC_ubsec_close)(iVar3);
        uVar7 = 1;
        *(undefined4 **)(iVar2 + 0x14) = puVar14;
        puVar9 = (undefined4 *)(iStack_a0 + 0x3e);
        pcVar12 = (char *)(uint)((int)(undefined4 *)(iStack_a0 + 0x1f) < 0);
        iVar3 = iStack_a4 + 0x1f;
        if (iStack_a4 + 0x1f < 0) {
          iVar3 = iStack_a4 + 0x3e;
        }
        puVar8 = (undefined4 *)(iStack_a0 + 0x1f);
        if ((undefined4 *)pcVar12 != (undefined4 *)0x0) {
          puVar8 = puVar9;
        }
        puVar14[1] = iVar3 >> 5;
        *(undefined4 **)(iVar2 + 0x18) = puVar13;
        puVar13[1] = (int)puVar8 >> 5;
        goto LAB_005dc490;
      }
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      pcVar12 = "e_ubsec.c";
      puVar9 = (undefined4 *)&DAT_0000006f;
      (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,0x6f,0x6a,"e_ubsec.c",0x3d2);
      (*p_UBSEC_ubsec_close)(iVar3);
    }
    iVar3 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
    uVar7 = (**(code **)(iVar3 + 4))(iVar2);
  }
LAB_005dc490:
  if (iStack_9c == *(int *)puVar1) {
    return uVar7;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (puVar9 != (undefined4 *)&DAT_000000c8) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,100,0x66,"e_ubsec.c",0x228);
    return 0;
  }
  if ((undefined4 *)pcVar12 == (undefined4 *)0x0) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar4 = 0x43;
    uVar15 = 0x21c;
  }
  else {
    if (ubsec_dso == 0) {
      if (UBSEC_LIBNAME != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      UBSEC_LIBNAME = 0;
      UBSEC_LIBNAME = (*(code *)PTR_BUF_strdup_006a80dc)(pcVar12);
      return (uint)(UBSEC_LIBNAME != 0);
    }
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    uVar4 = 100;
    uVar15 = 0x221;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,100,uVar4,"e_ubsec.c",uVar15);
  return 0;
}

