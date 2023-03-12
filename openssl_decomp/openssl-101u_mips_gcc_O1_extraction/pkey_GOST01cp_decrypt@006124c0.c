
int ** pkey_GOST01cp_decrypt
                 (int **param_1,int **param_2,int **param_3,uint param_4,undefined4 param_5)

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
  int **ppiVar16;
  int **ppiVar17;
  int iVar18;
  char *pcVar19;
  uint uVar20;
  char *pcVar21;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  int **ppiVar22;
  int **unaff_s1;
  int **ppiVar23;
  char **unaff_s5;
  int iStack_10fc;
  int iStack_10f8;
  int iStack_10f4;
  int iStack_10f0;
  int iStack_10ec;
  int iStack_10e8;
  int iStack_10e4;
  int **ppiStack_10dc;
  int **ppiStack_10d8;
  undefined *puStack_10d4;
  int **ppiStack_10d0;
  int **ppiStack_10cc;
  char **ppcStack_10c8;
  undefined4 uStack_10c4;
  undefined4 local_10b0;
  undefined4 local_10ac;
  undefined *local_10a8;
  uint local_109c;
  undefined auStack_1098 [4128];
  int *apiStack_78 [8];
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
  
  puStack_10d4 = PTR___stack_chk_guard_006a9ae8;
  local_10a8 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppiVar17 = param_2;
  local_109c = param_4;
  uVar11 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)();
  if (param_2 == (int **)0x0) {
    ppiVar23 = (int **)0x1;
    *param_3 = (int *)&DAT_00000020;
    goto LAB_006127a8;
  }
  param_3 = (int **)d2i_GOST_KEY_TRANSPORT(0,&local_109c,param_5);
  if (param_3 == (int **)0x0) {
    ppiVar17 = (int **)&DAT_00000068;
    ERR_GOST_error(0x76,0x68,"gost2001_keyx.c",0xee);
    ppiVar23 = (int **)0xffffffff;
    goto LAB_006127a8;
  }
  unaff_s1 = (int **)(**(code **)(local_10a8 + -0x607c))(param_3[1][1]);
  if (unaff_s1 == (int **)0x0) {
    param_4 = 2;
    local_10ac = 0;
    ppiVar17 = (int **)0xffffffff;
    local_10b0 = 3;
    iVar12 = (**(code **)(local_10a8 + -0x7df4))(param_1,0xffffffff,0xffffffff);
    if (0 < iVar12) goto LAB_0061257c;
    ppiVar17 = (int **)&DAT_00000084;
    ppiVar23 = (int **)0x0;
    ERR_GOST_error(0x76,0x84,"gost2001_keyx.c",0xfe);
  }
  else {
    ppiVar17 = unaff_s1;
    iVar12 = (**(code **)(local_10a8 + -0x70f0))(param_1);
    if (iVar12 < 1) {
      ppiVar17 = (int **)0x83;
      ppiVar23 = (int **)0x0;
      ERR_GOST_error(0x76,0x83,"gost2001_keyx.c",0xf7);
    }
    else {
LAB_0061257c:
      param_1 = (int **)(**(code **)(local_10a8 + -0x55bc))(param_1);
      if (param_1 == (int **)0x0) {
        ppiVar17 = (int **)&DAT_00000078;
        ppiVar23 = (int **)0x0;
        ERR_GOST_error(0x76,0x78,"gost2001_keyx.c",0x104);
      }
      else {
        iVar12 = get_encryption_params(*param_3[1]);
        if (iVar12 == 0) {
          ppiVar23 = (int **)0x0;
        }
        else {
          gost_init(auStack_1098,*(undefined4 *)(iVar12 + 4));
          piVar13 = (int *)param_3[1][2];
          if (*piVar13 != 8) {
            (**(code **)(local_10a8 + -0x7184))
                      ("gost2001_keyx.c",0x10e,"gkt->key_agreement_info->eph_iv->length == 8");
            piVar13 = (int *)param_3[1][2];
          }
          unaff_s5 = &local_58;
          uVar20 = 0x20;
          local_58 = *(char **)piVar13[2];
          local_54 = ((char **)piVar13[2])[1];
          piVar13 = (int *)**param_3;
          pcVar21 = (char *)0x680000;
          pcVar19 = local_58;
          if (*piVar13 != 0x20) {
            pcVar21 = "gkt->key_info->encrypted_key->length == 32";
            uVar20 = 0x110;
            pcVar19 = "gost2001_keyx.c";
            (**(code **)(local_10a8 + -0x7184))();
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
                     (uint)pcVar21 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar14 + 0x17) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar14 + 0x1b & 3;
          local_38 = (*(int *)((uVar14 + 0x18) - uVar7) << uVar7 * 8 |
                     uVar20 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar1 + 1) * 8 |
                     *(uint *)((uVar14 + 0x1b) - uVar1) >> (3 - uVar1) * 8;
          uVar20 = uVar14 + 0x1f & 3;
          local_34 = (*(int *)((uVar14 + 0x1c) - uVar8) << uVar8 * 8 |
                     (uint)pcVar19 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar20 + 1) * 8 |
                     *(uint *)((uVar14 + 0x1f) - uVar20) >> (3 - uVar20) * 8;
          piVar13 = (int *)(*param_3)[1];
          if (*piVar13 != 4) {
            (**(code **)(local_10a8 + -0x7184))
                      ("gost2001_keyx.c",0x112,"gkt->key_info->imit->length == 4");
            piVar13 = (int *)(*param_3)[1];
          }
          local_30 = *(undefined4 *)piVar13[2];
          uVar15 = (**(code **)(local_10a8 + -0x5808))(param_1);
          uVar15 = (**(code **)(local_10a8 + -0x72fc))(uVar15);
          uVar11 = (**(code **)(local_10a8 + -0x5808))(uVar11);
          param_1 = apiStack_78;
          VKO_compute_key_isra_0(param_1,uVar15,uVar11,unaff_s5);
          ppiVar17 = param_1;
          iVar12 = keyUnwrapCryptoPro(auStack_1098,param_1,unaff_s5,param_2);
          if (iVar12 == 0) {
            ppiVar17 = (int **)0x66;
            ppiVar23 = (int **)0x0;
            ERR_GOST_error(0x76,0x66,"gost2001_keyx.c",0x119);
          }
          else {
            ppiVar23 = (int **)0x1;
          }
        }
      }
      if (unaff_s1 == (int **)0x0) goto LAB_00612798;
    }
    (**(code **)(local_10a8 + -0x7f68))(unaff_s1);
  }
LAB_00612798:
  GOST_KEY_TRANSPORT_free(param_3);
  param_2 = ppiVar23;
LAB_006127a8:
  if (local_2c == *(int *)puStack_10d4) {
    return ppiVar23;
  }
  uStack_10c4 = 0x6128f8;
  iVar12 = local_2c;
  (**(code **)(local_10a8 + -0x5330))();
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  iStack_10fc = 0;
  iStack_10f8 = 0;
  iStack_10f4 = 0;
  iStack_10f0 = 0;
  iStack_10ec = 0;
  iStack_10e8 = 0;
  iStack_10e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppiStack_10dc = param_3;
  ppiStack_10d8 = unaff_s1;
  ppiStack_10d0 = param_2;
  ppiStack_10cc = param_1;
  ppcStack_10c8 = unaff_s5;
  ppiVar23 = (int **)(*(code *)PTR_BN_CTX_new_006a794c)();
  if (ppiVar23 == (int **)0x0) {
    ppiVar22 = (int **)0x0;
    ERR_GOST_error(0x65,0x41,"gost2001.c",0x2d);
    ppiVar23 = unaff_s1;
    goto LAB_00612a90;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(ppiVar23);
  iStack_10fc = (*(code *)PTR_BN_CTX_get_006a852c)(ppiVar23);
  iStack_10f4 = (*(code *)PTR_BN_CTX_get_006a852c)(ppiVar23);
  iStack_10f0 = (*(code *)PTR_BN_CTX_get_006a852c)(ppiVar23);
  iStack_10ec = (*(code *)PTR_BN_CTX_get_006a852c)(ppiVar23);
  iStack_10e8 = (*(code *)PTR_BN_CTX_get_006a852c)(ppiVar23);
  iStack_10f8 = (*(code *)PTR_BN_CTX_get_006a852c)(ppiVar23);
  if ((((iStack_10fc == 0) || (iStack_10f4 == 0)) || (iStack_10f0 == 0)) ||
     (((iStack_10ec == 0 || (iStack_10e8 == 0)) || (iStack_10f8 == 0)))) {
    uVar11 = 0x39;
LAB_00612acc:
    ERR_GOST_error(0x65,0x41,"gost2001.c",uVar11);
  }
  else {
    ppiVar16 = *(int ***)PTR_R3410_2001_paramset_006a95f8;
    ppiVar22 = (int **)PTR_R3410_2001_paramset_006a95f8;
    while (ppiVar16 != (int **)0x0) {
      if (ppiVar16 == ppiVar17) {
        iVar18 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_10fc,ppiVar22[3]);
        if (((iVar18 == 0) ||
            (iVar18 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_10f4,ppiVar22[1]), iVar18 == 0)) ||
           (iVar18 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_10f0,ppiVar22[2]), iVar18 == 0)) {
          ERR_GOST_error(0x65,0x44,"gost2001.c",0x47);
          goto LAB_00612a6c;
        }
        ppiVar17 = (int **)(*(code *)PTR_EC_GROUP_new_curve_GFp_006a8638)
                                     (iStack_10fc,iStack_10f4,iStack_10f0,ppiVar23);
        if (ppiVar17 != (int **)0x0) {
          unaff_s5 = (char **)(*(code *)PTR_EC_POINT_new_006a7fc0)(ppiVar17);
          if (unaff_s5 == (char **)0x0) {
            ppiVar22 = (int **)0x0;
            ERR_GOST_error(0x65,0x41,"gost2001.c",0x53);
            goto LAB_00612c18;
          }
          iVar18 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_10ec,ppiVar22[5]);
          if ((((iVar18 != 0) &&
               (iVar18 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_10e8,ppiVar22[6]), iVar18 != 0))
              && (iVar18 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a8634)
                                     (ppiVar17,unaff_s5,iStack_10ec,iStack_10e8,ppiVar23),
                 iVar18 != 0)) &&
             (iVar18 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_10f8,ppiVar22[4]), iVar18 != 0)) {
            iVar18 = (*(code *)PTR_EC_GROUP_set_generator_006a863c)(ppiVar17,unaff_s5,iStack_10f8,0)
            ;
            if (iVar18 != 0) goto LAB_00612cd4;
            uVar11 = 0x66;
            goto LAB_00612bec;
          }
          uVar11 = 0x5b;
          goto LAB_00612bec;
        }
        uVar11 = 0x4d;
        goto LAB_00612acc;
      }
      ppiVar22 = ppiVar22 + 7;
      ppiVar16 = (int **)*ppiVar22;
    }
    ERR_GOST_error(0x65,0x82,"gost2001.c",0x40);
  }
LAB_00612a6c:
  ppiVar22 = (int **)0x0;
  while( true ) {
    (*(code *)PTR_BN_CTX_end_006a8530)(ppiVar23);
    (*(code *)PTR_BN_CTX_free_006a7954)(ppiVar23);
LAB_00612a90:
    if (iStack_10e4 == *(int *)puVar10) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00612cd4:
    (*(code *)PTR_EC_GROUP_set_curve_name_006a862c)(ppiVar17,*ppiVar22);
    iVar18 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar12,ppiVar17);
    if (iVar18 == 0) {
      uVar11 = 0x6b;
LAB_00612bec:
      ppiVar22 = (int **)0x0;
      ERR_GOST_error(0x65,0x44,"gost2001.c",uVar11);
    }
    else {
      ppiVar22 = (int **)0x1;
    }
    (*(code *)PTR_EC_POINT_free_006a7fac)(unaff_s5);
LAB_00612c18:
    (*(code *)PTR_EC_GROUP_free_006a719c)(ppiVar17);
  }
  return ppiVar22;
}

