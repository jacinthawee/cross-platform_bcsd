
/* WARNING: Restarted to delay deadcode elimination for space: ram */

uint ubsec_dh_compute_key(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char *pcVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  code *unaff_s5;
  undefined4 uVar15;
  undefined4 *unaff_s6;
  undefined4 uVar16;
  undefined1 *unaff_s7;
  undefined4 uVar17;
  code *pcVar18;
  undefined4 *unaff_s8;
  int iStack_10c;
  int iStack_108;
  int iStack_104;
  char *pcStack_100;
  undefined *puStack_fc;
  undefined4 *puStack_f8;
  undefined4 *puStack_f4;
  undefined4 *puStack_f0;
  undefined4 *puStack_ec;
  undefined1 *puStack_e8;
  undefined1 *puStack_e4;
  undefined4 *puStack_e0;
  code *pcStack_dc;
  undefined4 *puStack_c8;
  undefined1 *puStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  int *piStack_b8;
  undefined *puStack_b0;
  code *pcStack_a8;
  undefined4 *puStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  int iStack_98;
  int iStack_94;
  undefined4 *puStack_90;
  undefined1 *puStack_8c;
  undefined4 *puStack_88;
  undefined *puStack_84;
  undefined4 uStack_80;
  code *pcStack_7c;
  undefined4 *puStack_78;
  undefined1 *puStack_74;
  undefined4 *puStack_70;
  code *pcStack_6c;
  undefined4 *local_58;
  undefined1 *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined *local_40;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  
  puStack_84 = PTR___stack_chk_guard_006aabf0;
  local_40 = &_gp;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  local_30 = (*(code *)PTR_BN_num_bits_006a82f4)(param_3[2]);
  puStack_8c = (undefined1 *)(*p_UBSEC_ubsec_open)("/dev/ubskey");
  pcVar18 = p_UBSEC_diffie_hellman_agree_ioctl;
  if ((int)puStack_8c < 1) {
    puStack_8c = &_ITM_registerTMCloneTable;
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = (**(code **)(local_40 + -0x589c))();
    }
    pcStack_100 = "e_ubsec.c";
    local_58 = (undefined4 *)0x376;
    (**(code **)(local_40 + -0x6eb0))(UBSEC_lib_error_code,0x65,0x6c);
LAB_005dbe7c:
    iVar2 = (**(code **)(local_40 + -0x6634))();
    puStack_f4 = param_2;
    puStack_f0 = param_3;
    uVar3 = (**(code **)(iVar2 + 8))(param_1);
  }
  else {
    unaff_s8 = *(undefined4 **)(undefined4 *)param_3[6];
    local_34 = (undefined4 *)(**(code **)(local_40 + -0x7bec))((undefined4 *)param_3[6]);
    local_38 = (undefined4 *)*param_2;
    unaff_s6 = (undefined4 *)(**(code **)(local_40 + -0x7bec))(param_2);
    unaff_s7 = *(undefined1 **)(undefined4 *)param_3[2];
    local_50 = (**(code **)(local_40 + -0x7bec))((undefined4 *)param_3[2]);
    local_48 = &local_30;
    puStack_f4 = unaff_s8;
    puStack_f0 = local_34;
    pcStack_100 = (char *)local_38;
    local_58 = unaff_s6;
    local_54 = unaff_s7;
    local_4c = param_1;
    iVar2 = (*pcVar18)(puStack_8c);
    if (iVar2 != 0) {
      unaff_s5 = (code *)&_ITM_registerTMCloneTable;
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (**(code **)(local_40 + -0x589c))();
      }
      pcStack_100 = "e_ubsec.c";
      local_58 = (undefined4 *)0x384;
      (**(code **)(local_40 + -0x6eb0))(UBSEC_lib_error_code,0x65,0x6a);
      (*p_UBSEC_ubsec_close)(puStack_8c);
      goto LAB_005dbe7c;
    }
    (*p_UBSEC_ubsec_close)(puStack_8c);
    uVar3 = (*p_UBSEC_ubsec_bits_to_bytes)(local_30);
    unaff_s5 = pcVar18;
  }
  if (local_2c == *(undefined4 **)puStack_84) {
    return uVar3;
  }
  pcStack_6c = ubsec_mod_exp_mont;
  puStack_f8 = local_2c;
  (**(code **)(local_40 + -0x5328))();
  puStack_e8 = local_54;
  puStack_ec = local_58;
  puStack_fc = PTR___stack_chk_guard_006aabf0;
  puStack_e4 = (undefined1 *)0x6a0000;
  puStack_b0 = &_gp;
  iStack_94 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_90 = param_3;
  puStack_88 = param_2;
  uStack_80 = param_1;
  pcStack_7c = unaff_s5;
  puStack_78 = unaff_s6;
  puStack_74 = unaff_s7;
  puStack_70 = unaff_s8;
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(pcStack_100);
  puVar9 = puStack_f4;
  if (max_key_len < iVar2) {
    iVar2 = (**(code **)(puStack_b0 + -0x7308))();
    puStack_c4 = puStack_e8;
    puStack_c8 = puStack_ec;
    pcVar12 = pcStack_100;
    uVar3 = (**(code **)(iVar2 + 0x18))(puStack_f8,puStack_f4,puStack_f0);
  }
  else {
    iStack_98 = 0;
    if (ubsec_dso == 0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = (**(code **)(puStack_b0 + -0x589c))();
      }
      pcVar18 = *(code **)(puStack_b0 + -0x6eb0);
      uVar15 = 0x69;
      puStack_c8 = (undefined4 *)0x234;
LAB_005dc264:
      pcVar12 = "e_ubsec.c";
      pcStack_100 = &_ITM_registerTMCloneTable;
      puVar9 = (undefined4 *)&DAT_0000006a;
      (*pcVar18)(UBSEC_lib_error_code,0x6a,uVar15);
      uVar3 = 0;
    }
    else {
      iStack_98 = (**(code **)(puStack_b0 + -0x7bec))(pcStack_100);
      if (max_key_len < iStack_98) {
        puStack_e8 = &_ITM_registerTMCloneTable;
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = (**(code **)(puStack_b0 + -0x589c))();
        }
        puStack_c8 = (undefined4 *)0x23b;
        (**(code **)(puStack_b0 + -0x6eb0))(UBSEC_lib_error_code,0x6a,0x6b,"e_ubsec.c");
      }
      else {
        if (((int)puStack_f8[2] < *(int *)((int)pcStack_100 + 4)) &&
           (iVar2 = (**(code **)(puStack_b0 + -0x6860))(puStack_f8), iVar2 == 0)) {
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = (**(code **)(puStack_b0 + -0x589c))();
          }
          pcVar18 = *(code **)(puStack_b0 + -0x6eb0);
          uVar15 = 0x65;
          puStack_c8 = (undefined4 *)0x241;
          goto LAB_005dc264;
        }
        puStack_e8 = (undefined1 *)(*p_UBSEC_ubsec_open)("/dev/ubskey");
        if ((int)puStack_e8 < 1) {
          puStack_e8 = &_ITM_registerTMCloneTable;
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = (**(code **)(puStack_b0 + -0x589c))();
          }
          puStack_c8 = (undefined4 *)0x247;
          (**(code **)(puStack_b0 + -0x6eb0))(UBSEC_lib_error_code,0x6a,0x6c,"e_ubsec.c");
        }
        else {
          uStack_9c = *puStack_f4;
          pcStack_a8 = p_UBSEC_rsa_mod_exp_ioctl;
          uStack_a0 = (**(code **)(puStack_b0 + -0x7bec))(puStack_f4);
          puStack_a4 = *(undefined4 **)pcStack_100;
          unaff_s8 = (undefined4 *)(**(code **)(puStack_b0 + -0x7bec))(pcStack_100);
          puStack_e4 = (undefined1 *)*puStack_f0;
          uStack_c0 = (**(code **)(puStack_b0 + -0x7bec))(puStack_f0);
          uStack_bc = *puStack_f8;
          piStack_b8 = &iStack_98;
          pcVar12 = (char *)puStack_a4;
          puStack_c8 = unaff_s8;
          puStack_c4 = puStack_e4;
          iVar2 = (*pcStack_a8)(puStack_e8,uStack_9c,uStack_a0);
          if (iVar2 == 0) {
            (*p_UBSEC_ubsec_close)(puStack_e8);
            iVar4 = (**(code **)(puStack_b0 + -0x7bec))(pcStack_100);
            uVar3 = 1;
            puVar9 = (undefined4 *)(uint)(iVar4 + 0x1f < 0);
            iVar2 = iVar4 + 0x1f;
            if (puVar9 != (undefined4 *)0x0) {
              iVar2 = iVar4 + 0x3e;
            }
            puStack_f8[1] = iVar2 >> 5;
            goto LAB_005dc104;
          }
          puStack_e4 = &_ITM_registerTMCloneTable;
          if (UBSEC_lib_error_code == 0) {
            UBSEC_lib_error_code = (**(code **)(puStack_b0 + -0x589c))();
          }
          puStack_c8 = (undefined4 *)0x24f;
          (**(code **)(puStack_b0 + -0x6eb0))(UBSEC_lib_error_code,0x6a,0x6a,"e_ubsec.c");
          (*p_UBSEC_ubsec_close)(puStack_e8);
        }
      }
      puStack_c8 = puStack_ec;
      pcVar12 = pcStack_100;
      uVar3 = (**(code **)(puStack_b0 + -0x7498))(puStack_f8,puStack_f4,puStack_f0);
    }
  }
LAB_005dc104:
  if (iStack_94 == *(int *)puStack_fc) {
    return uVar3;
  }
  pcStack_dc = ubsec_dh_generate_key;
  iVar2 = iStack_94;
  (**(code **)(puStack_b0 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  puVar13 = *(undefined4 **)(iVar2 + 0x18);
  uVar15 = 0;
  iStack_10c = 0;
  iStack_108 = 0;
  iStack_104 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_e0 = unaff_s8;
  if (puVar13 == (undefined4 *)0x0) {
    puVar13 = (undefined4 *)(*(code *)PTR_BN_new_006a82b4)();
    if (puVar13 != (undefined4 *)0x0) {
      iStack_108 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar2 + 8));
      puVar9 = (undefined4 *)(*(undefined4 **)(iVar2 + 8))[1];
      puVar14 = *(undefined4 **)(iVar2 + 8);
      if ((int)puVar13[2] < (int)puVar9) {
        iVar4 = (*(code *)PTR_bn_expand2_006a9680)(puVar13);
        if (iVar4 != 0) goto LAB_005dc64c;
        uVar3 = 0;
        goto LAB_005dc490;
      }
      while (puVar9 = puVar14, iVar4 = (*(code *)PTR_BN_rand_range_006a97b0)(puVar13), iVar4 != 0) {
        if (puVar13[1] != 0) {
          uVar15 = (*(code *)PTR_BN_num_bits_006a82f4)(puVar13);
          goto LAB_005dc37c;
        }
LAB_005dc64c:
        puVar14 = *(undefined4 **)(iVar2 + 8);
      }
    }
LAB_005dc5e4:
    uVar3 = 0;
  }
  else {
LAB_005dc37c:
    puVar14 = *(undefined4 **)(iVar2 + 0x14);
    if (puVar14 == (undefined4 *)0x0) {
      puVar14 = (undefined4 *)(*(code *)PTR_BN_new_006a82b4)();
      iStack_10c = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(iVar2 + 8));
      puVar9 = *(undefined4 **)(*(int *)(iVar2 + 8) + 4);
      if (((int)puVar14[2] < (int)puVar9) &&
         (iVar4 = (*(code *)PTR_bn_expand2_006a9680)(puVar14), iVar4 == 0)) goto LAB_005dc5e4;
    }
    iVar4 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
    pcVar18 = p_UBSEC_diffie_hellman_generate_ioctl;
    if (iVar4 < 1) {
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
      uVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 **)(iVar2 + 0xc));
      uVar16 = **(undefined4 **)(iVar2 + 8);
      uVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 **)(iVar2 + 8));
      iVar7 = (*pcVar18)(iVar4,uVar10,&iStack_108,uVar11,&iStack_10c,uVar17,uVar5,uVar16,uVar6,0,0,
                         uVar15);
      if (iVar7 == 0) {
        (*p_UBSEC_ubsec_close)(iVar4);
        uVar3 = 1;
        *(undefined4 **)(iVar2 + 0x14) = puVar14;
        puVar9 = (undefined4 *)(iStack_108 + 0x3e);
        pcVar12 = (char *)(uint)((int)(undefined4 *)(iStack_108 + 0x1f) < 0);
        iVar4 = iStack_10c + 0x1f;
        if (iStack_10c + 0x1f < 0) {
          iVar4 = iStack_10c + 0x3e;
        }
        puVar8 = (undefined4 *)(iStack_108 + 0x1f);
        if ((undefined4 *)pcVar12 != (undefined4 *)0x0) {
          puVar8 = puVar9;
        }
        puVar14[1] = iVar4 >> 5;
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
      (*p_UBSEC_ubsec_close)(iVar4);
    }
    iVar4 = (*(code *)PTR_DH_OpenSSL_006a98ac)();
    uVar3 = (**(code **)(iVar4 + 4))(iVar2);
  }
LAB_005dc490:
  if (iStack_104 == *(int *)puVar1) {
    return uVar3;
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
    uVar5 = 0x43;
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
    uVar5 = 100;
    uVar15 = 0x221;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(UBSEC_lib_error_code,100,uVar5,"e_ubsec.c",uVar15);
  return 0;
}

