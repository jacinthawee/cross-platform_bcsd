
undefined4 *
pkey_GOST01cp_decrypt
          (undefined4 *param_1,undefined4 *param_2,int **param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined *puVar10;
  undefined4 uVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  int iVar22;
  char *pcVar23;
  uint uVar24;
  int iVar25;
  char *pcVar26;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  undefined4 *puVar27;
  undefined4 *unaff_s1;
  int iVar28;
  undefined4 *puVar29;
  char **unaff_s5;
  int iVar30;
  int iVar31;
  int iStack_115c;
  undefined4 *puStack_1150;
  undefined4 uStack_10fc;
  char *pcStack_10f8;
  undefined4 uStack_10f4;
  undefined4 uStack_10f0;
  undefined4 uStack_10ec;
  undefined4 uStack_10e8;
  int iStack_10e4;
  int **ppiStack_10dc;
  undefined4 *puStack_10d8;
  undefined *puStack_10d4;
  undefined4 *puStack_10d0;
  undefined4 *puStack_10cc;
  char **ppcStack_10c8;
  undefined4 uStack_10c4;
  undefined4 local_10b0;
  undefined4 local_10ac;
  undefined *local_10a8;
  uint local_109c;
  undefined auStack_1098 [4128];
  undefined4 auStack_78 [8];
  char *local_58;
  char *local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  int local_2c;
  
  puStack_10d4 = PTR___stack_chk_guard_006aabf0;
  local_10a8 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar27 = param_2;
  local_109c = param_4;
  uVar11 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006aa6e0)();
  if (param_2 == (undefined4 *)0x0) {
    puVar29 = (undefined4 *)0x1;
    *param_3 = (int *)&DAT_00000020;
    goto LAB_00613968;
  }
  param_3 = (int **)d2i_GOST_KEY_TRANSPORT(0,&local_109c,param_5);
  if (param_3 == (int **)0x0) {
    puVar27 = (undefined4 *)&DAT_00000068;
    ERR_GOST_error(0x76,0x68,"gost2001_keyx.c",0xf9);
    puVar29 = (undefined4 *)0xffffffff;
    goto LAB_00613968;
  }
  unaff_s1 = (undefined4 *)(**(code **)(local_10a8 + -0x605c))(param_3[1][1]);
  if (unaff_s1 == (undefined4 *)0x0) {
    param_4 = 2;
    local_10ac = 0;
    puVar27 = (undefined4 *)0xffffffff;
    local_10b0 = 3;
    iVar12 = (**(code **)(local_10a8 + -0x7df4))(param_1,0xffffffff,0xffffffff);
    if (0 < iVar12) goto LAB_0061373c;
    puVar27 = (undefined4 *)&DAT_00000084;
    puVar29 = (undefined4 *)0x0;
    ERR_GOST_error(0x76,0x84,"gost2001_keyx.c",0x10e);
  }
  else {
    puVar27 = unaff_s1;
    iVar12 = (**(code **)(local_10a8 + -0x7100))(param_1);
    if (iVar12 < 1) {
      puVar27 = (undefined4 *)0x83;
      puVar29 = (undefined4 *)0x0;
      ERR_GOST_error(0x76,0x83,"gost2001_keyx.c",0x104);
    }
    else {
LAB_0061373c:
      param_1 = (undefined4 *)(**(code **)(local_10a8 + -0x55ac))(param_1);
      if (param_1 == (undefined4 *)0x0) {
        puVar27 = (undefined4 *)&DAT_00000078;
        puVar29 = (undefined4 *)0x0;
        ERR_GOST_error(0x76,0x78,"gost2001_keyx.c",0x116);
      }
      else {
        iVar12 = get_encryption_params(*param_3[1]);
        if (iVar12 == 0) {
          puVar29 = (undefined4 *)0x0;
        }
        else {
          gost_init(auStack_1098,*(undefined4 *)(iVar12 + 4));
          piVar13 = (int *)param_3[1][2];
          if (*piVar13 != 8) {
            (**(code **)(local_10a8 + -0x7194))
                      ("gost2001_keyx.c",0x120,"gkt->key_agreement_info->eph_iv->length==8");
            piVar13 = (int *)param_3[1][2];
          }
          unaff_s5 = &local_58;
          uVar24 = 0x20;
          local_58 = *(char **)piVar13[2];
          local_54 = ((char **)piVar13[2])[1];
          piVar13 = (int *)**param_3;
          pcVar26 = (char *)0x680000;
          pcVar23 = local_58;
          if (*piVar13 != 0x20) {
            pcVar26 = "gkt->key_info->encrypted_key->length==32";
            uVar24 = 0x122;
            pcVar23 = "gost2001_keyx.c";
            (**(code **)(local_10a8 + -0x7194))();
            piVar13 = (int *)**param_3;
          }
          uVar14 = piVar13[2];
          uVar1 = uVar14 & 3;
          uVar2 = uVar14 + 4 & 3;
          uVar3 = uVar14 + 8 & 3;
          uVar4 = uVar14 + 0xc & 3;
          uVar5 = uVar14 + 0x10 & 3;
          uVar6 = uVar14 + 0x14 & 3;
          uVar7 = uVar14 + 0x18 & 3;
          uVar8 = uVar14 + 0x1c & 3;
          uVar9 = uVar14 + 3 & 3;
          local_50 = (*(int *)(uVar14 - uVar1) << uVar1 * 8 | in_t3 & 0xffffffffU >> (4 - uVar1) * 8
                     ) & -1 << (uVar9 + 1) * 8 | *(uint *)((uVar14 + 3) - uVar9) >> (3 - uVar9) * 8;
          uVar1 = uVar14 + 7 & 3;
          local_4c = (*(int *)((uVar14 + 4) - uVar2) << uVar2 * 8 |
                     in_t2 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar14 + 7) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar14 + 0xb & 3;
          local_48 = (*(int *)((uVar14 + 8) - uVar3) << uVar3 * 8 |
                     in_t1 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar14 + 0xb) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar14 + 0xf & 3;
          local_44 = (*(int *)((uVar14 + 0xc) - uVar4) << uVar4 * 8 |
                     in_t0 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar14 + 0xf) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar14 + 0x13 & 3;
          local_40 = (*(int *)((uVar14 + 0x10) - uVar5) << uVar5 * 8 |
                     param_4 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar14 + 0x13) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar14 + 0x17 & 3;
          local_3c = (*(int *)((uVar14 + 0x14) - uVar6) << uVar6 * 8 |
                     (uint)pcVar26 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar14 + 0x17) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar14 + 0x1b & 3;
          local_38 = (*(int *)((uVar14 + 0x18) - uVar7) << uVar7 * 8 |
                     uVar24 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar14 + 0x1b) - uVar1) >> (3 - uVar1) * 8;
          uVar24 = uVar14 + 0x1f & 3;
          local_34 = (*(int *)((uVar14 + 0x1c) - uVar8) << uVar8 * 8 |
                     (uint)pcVar23 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar24 + 1) * 8 |
                     *(uint *)((uVar14 + 0x1f) - uVar24) >> (3 - uVar24) * 8;
          piVar13 = (int *)(*param_3)[1];
          if (*piVar13 != 4) {
            (**(code **)(local_10a8 + -0x7194))
                      ("gost2001_keyx.c",0x124,"gkt->key_info->imit->length==4");
            piVar13 = (int *)(*param_3)[1];
          }
          local_30 = *(undefined4 *)piVar13[2];
          uVar15 = (**(code **)(local_10a8 + -0x57fc))(param_1);
          uVar15 = (**(code **)(local_10a8 + -0x7310))(uVar15);
          uVar11 = (**(code **)(local_10a8 + -0x57fc))(uVar11);
          param_1 = auStack_78;
          VKO_compute_key_isra_0(param_1,uVar15,uVar11,unaff_s5);
          puVar27 = param_1;
          iVar12 = keyUnwrapCryptoPro(auStack_1098,param_1,unaff_s5,param_2);
          if (iVar12 == 0) {
            puVar27 = (undefined4 *)0x66;
            puVar29 = (undefined4 *)0x0;
            ERR_GOST_error(0x76,0x66,"gost2001_keyx.c",299);
          }
          else {
            puVar29 = (undefined4 *)0x1;
          }
        }
      }
      if (unaff_s1 == (undefined4 *)0x0) goto LAB_00613958;
    }
    (**(code **)(local_10a8 + -0x7f68))(unaff_s1);
  }
LAB_00613958:
  GOST_KEY_TRANSPORT_free(param_3);
  param_2 = puVar29;
LAB_00613968:
  if (local_2c == *(int *)puStack_10d4) {
    return puVar29;
  }
  uStack_10c4 = 0x613ab8;
  iVar12 = local_2c;
  (**(code **)(local_10a8 + -0x5328))();
  puVar10 = PTR___stack_chk_guard_006aabf0;
  uStack_10fc = 0;
  pcStack_10f8 = (char *)0x0;
  uStack_10f4 = 0;
  uStack_10f0 = 0;
  uStack_10ec = 0;
  uStack_10e8 = 0;
  iStack_10e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  ppiStack_10dc = param_3;
  puStack_10d8 = unaff_s1;
  puStack_10d0 = param_2;
  puStack_10cc = param_1;
  ppcStack_10c8 = unaff_s5;
  uVar11 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar11);
  uStack_10fc = (*(code *)PTR_BN_CTX_get_006a9648)(uVar11);
  uStack_10f4 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar11);
  uStack_10f0 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar11);
  uStack_10ec = (*(code *)PTR_BN_CTX_get_006a9648)(uVar11);
  uStack_10e8 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar11);
  pcStack_10f8 = (char *)(*(code *)PTR_BN_CTX_get_006a9648)(uVar11);
  puVar16 = *(undefined4 **)PTR_R3410_2001_paramset_006aa704;
  puVar29 = (undefined4 *)PTR_R3410_2001_paramset_006aa704;
  while (puVar16 != (undefined4 *)0x0) {
    if (puVar27 == puVar16) {
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_10fc,puVar29[3]);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_10f4,puVar29[1]);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_10f0,puVar29[2]);
      iVar28 = (*(code *)PTR_EC_GROUP_new_curve_GFp_006a975c)
                         (uStack_10fc,uStack_10f4,uStack_10f0,uVar11);
      uVar15 = (*(code *)PTR_EC_POINT_new_006a9140)(iVar28);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_10ec,puVar29[5]);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_10e8,puVar29[6]);
      (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a9758)
                (iVar28,uVar15,uStack_10ec,uStack_10e8,uVar11);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&pcStack_10f8,puVar29[4]);
      pcVar23 = pcStack_10f8;
      (*(code *)PTR_EC_GROUP_set_generator_006a9760)(iVar28,uVar15,pcStack_10f8,0);
      puVar27 = (undefined4 *)0x1;
      (*(code *)PTR_EC_GROUP_set_curve_name_006a9750)(iVar28,*puVar29);
      iVar25 = iVar28;
      (*(code *)PTR_EC_KEY_set_group_006a82d0)(iVar12);
      goto LAB_00613c04;
    }
    puVar29 = puVar29 + 7;
    puVar16 = (undefined4 *)*puVar29;
  }
  pcVar23 = "gost2001.c";
  iVar25 = 0x82;
  puVar27 = (undefined4 *)0x0;
  ERR_GOST_error(0x65,0x82,"gost2001.c",0x35);
  uVar15 = 0;
  iVar28 = 0;
LAB_00613c04:
  (*(code *)PTR_EC_POINT_free_006a9134)(uVar15);
  (*(code *)PTR_EC_GROUP_free_006a829c)(iVar28);
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar11);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar11);
  if (iStack_10e4 == *(int *)puVar10) {
    return puVar27;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar11 = (*(code *)PTR_hashsum2bn_006aa960)();
  uVar15 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar15);
  if (iVar25 != 0x20) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("gost2001.c",0x69,"dlen==32");
  }
  puStack_1150 = (undefined4 *)(*(code *)PTR_DSA_SIG_new_006a9880)();
  if (puStack_1150 == (undefined4 *)0x0) {
    uVar21 = 0;
    ERR_GOST_error(0x69,0x76,"gost2001.c",0x6d);
  }
  else {
    uVar17 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(pcVar23);
    uVar18 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
    (*(code *)PTR_EC_GROUP_get_order_006a82ec)(uVar17,uVar18,uVar15);
    uVar19 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(pcVar23);
    iVar12 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
    (*(code *)PTR_BN_div_006a967c)(0,iVar12,uVar11,uVar18,uVar15);
    if (*(int *)(iVar12 + 4) == 0) {
      (*(code *)PTR_BN_set_word_006a8820)(iVar12,1);
    }
    iVar31 = 0;
    iVar25 = 0;
    uVar20 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
    iVar30 = 0;
    iVar28 = 0;
    uVar21 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar17);
    iStack_115c = 0;
    do {
      do {
        iVar22 = (*(code *)PTR_BN_rand_range_006a97b0)(uVar20,uVar18);
        if (iVar22 == 0) {
          uVar18 = 0x89;
          uVar17 = 0x7d;
LAB_006140dc:
          ERR_GOST_error(0x69,uVar17,"gost2001.c",uVar18);
          (*(code *)PTR_DSA_SIG_free_006a987c)(puStack_1150);
          puStack_1150 = (undefined4 *)0x0;
          goto LAB_006140fc;
        }
        iVar22 = (*(code *)PTR_EC_POINT_mul_006a976c)(uVar17,uVar21,uVar20,0,0,uVar15);
        if (iVar22 == 0) {
          uVar18 = 0x90;
LAB_0061418c:
          uVar17 = 0x10;
          goto LAB_006140dc;
        }
        if (iVar25 == 0) {
          iVar25 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
        }
        iVar22 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                           (uVar17,uVar21,iVar25,0,uVar15);
        if (iVar22 == 0) {
          uVar18 = 0x98;
          goto LAB_0061418c;
        }
        if (iVar28 == 0) {
          iVar28 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
        }
        (*(code *)PTR_BN_nnmod_006a9664)(iVar28,iVar25,uVar18,uVar15);
      } while (*(int *)(iVar28 + 4) == 0);
      if (iStack_115c == 0) {
        iStack_115c = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
      }
      (*(code *)PTR_BN_mod_mul_006a9698)(iStack_115c,uVar19,iVar28,uVar18,uVar15);
      if (iVar31 == 0) {
        iVar31 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
      }
      (*(code *)PTR_BN_mod_mul_006a9698)(iVar31,uVar20,iVar12,uVar18,uVar15);
      if (iVar30 == 0) {
        iVar30 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar15);
      }
      (*(code *)PTR_BN_mod_add_006aa61c)(iVar30,iStack_115c,iVar31,uVar18,uVar15);
    } while (*(int *)(iVar30 + 4) == 0);
    uVar17 = (*(code *)PTR_BN_dup_006a9100)(iVar30);
    puVar10 = PTR_BN_dup_006a9100;
    puStack_1150[1] = uVar17;
    uVar17 = (*(code *)puVar10)(iVar28);
    *puStack_1150 = uVar17;
  }
LAB_006140fc:
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar15);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar15);
  (*(code *)PTR_EC_POINT_free_006a9134)(uVar21);
  (*(code *)PTR_BN_free_006a811c)(uVar11);
  return puStack_1150;
}

