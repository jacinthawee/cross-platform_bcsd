
int **** pkey_GOST01cp_encrypt(undefined4 *param_1,int ****param_2,int ***param_3,uint param_4)

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
  int ****ppppiVar11;
  int iVar12;
  int ****ppppiVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int *piVar16;
  int **ppiVar17;
  int ***pppiVar18;
  uint uVar19;
  int ****ppppiVar20;
  int iVar21;
  undefined4 *puVar22;
  char *pcVar23;
  uint uVar24;
  char *pcVar25;
  uint uVar26;
  int ***in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  int ****ppppiVar27;
  int ****ppppiVar28;
  int unaff_s6;
  int iStack_21cc;
  int iStack_21c8;
  int iStack_21c4;
  int iStack_21c0;
  int iStack_21bc;
  int iStack_21b8;
  int iStack_21b4;
  char *pcStack_21ac;
  int ****ppppiStack_21a8;
  undefined *puStack_21a4;
  int ****ppppiStack_21a0;
  int ****ppppiStack_219c;
  int ****ppppiStack_2198;
  undefined4 uStack_2194;
  undefined4 uStack_2180;
  undefined4 uStack_217c;
  undefined *puStack_2178;
  uint uStack_216c;
  undefined auStack_2168 [4128];
  int ***apppiStack_1148 [8];
  int ***pppiStack_1128;
  char *pcStack_1124;
  uint uStack_1120;
  uint uStack_111c;
  uint uStack_1118;
  uint uStack_1114;
  uint uStack_1110;
  uint uStack_110c;
  uint uStack_1108;
  uint uStack_1104;
  undefined4 uStack_1100;
  int iStack_10fc;
  int ****ppppiStack_10f4;
  int ****ppppiStack_10f0;
  undefined4 *puStack_10ec;
  undefined4 *puStack_10e8;
  undefined *puStack_10e4;
  int ****ppppiStack_10e0;
  int iStack_10dc;
  int ***pppiStack_10d8;
  code *pcStack_10d4;
  undefined *local_10c0;
  undefined4 local_10bc;
  undefined *local_10b8;
  int ****local_10ac;
  int ***local_10a8;
  int ****local_10a4;
  undefined auStack_10a0 [4128];
  int ***local_80;
  undefined4 local_7c;
  int ***apppiStack_78 [8];
  undefined auStack_58 [8];
  int ***apppiStack_50 [8];
  int ***pppiStack_30;
  int ****local_2c;
  
  puStack_10e4 = PTR___stack_chk_guard_006a9ae8;
  local_10b8 = &_gp;
  local_2c = *(int *****)PTR___stack_chk_guard_006a9ae8;
  pcStack_21ac = (char *)param_3;
  uVar26 = param_4;
  local_10a4 = param_2;
  ppppiVar11 = (int ****)(*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)();
  iVar12 = (**(code **)(local_10b8 + -0x5810))(param_1);
  puStack_10e8 = (undefined4 *)get_encryption_params(0);
  ppppiVar13 = (int ****)(**(code **)(local_10b8 + -0x55bc))(param_1);
  puVar22 = *(undefined4 **)(iVar12 + 8);
  if (puVar22 == (undefined4 *)0x0) {
    if (local_10a4 == (int ****)0x0) {
      if (ppppiVar13 == (int ****)0x0) goto LAB_00612454;
      goto LAB_0061207c;
    }
    param_2 = (int ****)&DAT_00000008;
    iVar12 = (**(code **)(local_10b8 + -0x786c))(&local_80);
    if (0 < iVar12) goto LAB_00612070;
    uVar26 = 0x86;
    pcStack_21ac = "gost2001_keyx.c";
    ppppiStack_21a0 = (int ****)&DAT_0000007c;
    ppppiStack_10f4 = (int ****)0x0;
    ERR_GOST_error(0x77);
  }
  else {
    local_80 = (int ***)*puVar22;
    local_7c = puVar22[1];
LAB_00612070:
    if (ppppiVar13 == (int ****)0x0) {
      if (local_10a4 == (int ****)0x0) {
LAB_00612454:
        ppppiVar13 = (int ****)0x0;
        unaff_s6 = 1;
        goto LAB_00612090;
      }
      ppppiVar13 = (int ****)(**(code **)(local_10b8 + -0x77c0))();
      unaff_s6 = (**(code **)(local_10b8 + -0x7ed4))(ppppiVar11);
      pcStack_21ac = (char *)(**(code **)(local_10b8 + -0x7c38))();
      (**(code **)(local_10b8 + -0x6a14))(ppppiVar13,unaff_s6);
      ppppiStack_21a0 = ppppiVar11;
      (**(code **)(local_10b8 + -0x7c6c))(ppppiVar13);
      uVar14 = (**(code **)(local_10b8 + -0x5808))(ppppiVar13);
      iVar12 = gost2001_keygen(uVar14);
      if (iVar12 != 0) {
        unaff_s6 = 1;
        iVar12 = get_gost_engine_param(0);
        goto joined_r0x006123c8;
      }
      piVar16 = (int *)0x0;
LAB_006123ec:
      if (ppppiVar13 != (int ****)0x0) {
        (**(code **)(local_10b8 + -0x7f68))(ppppiVar13);
      }
    }
    else {
LAB_0061207c:
      unaff_s6 = 0;
      iVar12 = gost_get0_priv_key(ppppiVar13);
      if (iVar12 == 0) {
        uVar26 = 0x8f;
        pcStack_21ac = "gost2001_keyx.c";
        ppppiStack_21a0 = (int ****)&DAT_00000079;
        piVar16 = (int *)0x0;
        ERR_GOST_error(0x77);
      }
      else {
LAB_00612090:
        iVar12 = get_gost_engine_param(0);
        ppppiStack_21a0 = param_2;
joined_r0x006123c8:
        if ((iVar12 == 0) && (puStack_10e8 == *(undefined4 **)(local_10b8 + -0x559c))) {
          puStack_10e8 = puStack_10e8 + 3;
        }
        if (local_10a4 != (int ****)0x0) {
          uVar14 = (**(code **)(local_10b8 + -0x5808))(ppppiVar11);
          uVar14 = (**(code **)(local_10b8 + -0x72fc))(uVar14);
          uVar15 = (**(code **)(local_10b8 + -0x5808))(ppppiVar13);
          local_10a8 = (int ***)&local_80;
          local_10ac = apppiStack_78;
          VKO_compute_key_isra_0(local_10ac,uVar14,uVar15,local_10a8);
          gost_init(auStack_10a0,puStack_10e8[1]);
          local_10c0 = auStack_58;
          ppppiStack_21a0 = local_10ac;
          pcStack_21ac = (char *)local_10a8;
          in_t0 = local_10a8;
          keyWrapCryptoPro(auStack_10a0);
          uVar26 = param_4;
        }
        piVar16 = (int *)GOST_KEY_TRANSPORT_new();
        if (piVar16 != (int *)0x0) {
          pcStack_21ac = &DAT_00000008;
          ppppiStack_21a0 = &local_80;
          iVar12 = (**(code **)(local_10b8 + -0x6774))(*(undefined4 *)(piVar16[1] + 8));
          if (iVar12 != 0) {
            pcStack_21ac = &SUB_00000004;
            ppppiStack_21a0 = &pppiStack_30;
            iVar12 = (**(code **)(local_10b8 + -0x6774))(*(undefined4 *)(*piVar16 + 4));
            if (iVar12 != 0) {
              pcStack_21ac = &DAT_00000020;
              ppppiStack_21a0 = apppiStack_50;
              iVar12 = (**(code **)(local_10b8 + -0x6774))(*(undefined4 *)*piVar16);
              if (iVar12 != 0) {
                if (unaff_s6 == 0) {
                  (**(code **)(local_10b8 + -0x7ddc))(*(undefined4 *)piVar16[1]);
                  ppppiVar13 = (int ****)piVar16[1];
                  pppiVar18 = (int ***)(**(code **)(local_10b8 + -0x7ca0))(*puStack_10e8);
                  uVar26 = 2;
                  pcStack_21ac = (char *)0xffffffff;
                  *ppppiVar13 = pppiVar18;
                  local_10bc = 0;
                  local_10c0 = (undefined *)0x3;
                  iVar12 = (**(code **)(local_10b8 + -0x7df4))(param_1,0xffffffff);
                  if (iVar12 < 1) {
                    uVar26 = 0xc6;
                    pcStack_21ac = "gost2001_keyx.c";
                    ppppiStack_21a0 = (int ****)&DAT_00000084;
                    ERR_GOST_error(0x77);
                    goto LAB_0061231c;
                  }
                }
                else {
                  if (local_10a4 != (int ****)0x0) {
                    ppppiVar11 = ppppiVar13;
                  }
                  iVar12 = (**(code **)(local_10b8 + -0x5f18))(piVar16[1] + 4,ppppiVar11);
                  if (iVar12 == 0) {
                    uVar26 = 0xba;
                    pcStack_21ac = "gost2001_keyx.c";
                    ppppiStack_21a0 = (int ****)&DAT_00000065;
                    ERR_GOST_error(0x77);
                    goto LAB_006123ec;
                  }
                  (**(code **)(local_10b8 + -0x7ddc))(*(undefined4 *)piVar16[1]);
                  param_1 = (undefined4 *)piVar16[1];
                  uVar14 = (**(code **)(local_10b8 + -0x7ca0))(*puStack_10e8);
                  *param_1 = uVar14;
                  if (ppppiVar13 != (int ****)0x0) {
                    (**(code **)(local_10b8 + -0x7f68))(ppppiVar13);
                  }
                }
                ppppiStack_21a0 = (int ****)0x0;
                if (local_10a4 != (int ****)0x0) {
                  ppppiStack_21a0 = (int ****)&local_10a4;
                }
                ppiVar17 = (int **)i2d_GOST_KEY_TRANSPORT(piVar16);
                ppppiStack_10f4 = (int ****)(uint)(ppiVar17 != (int **)0x0);
                *param_3 = ppiVar17;
                GOST_KEY_TRANSPORT_free(piVar16);
                goto LAB_00612260;
              }
            }
          }
        }
        if (unaff_s6 != 0) goto LAB_006123ec;
      }
    }
LAB_0061231c:
    ppppiStack_10f4 = (int ****)0xffffffff;
    GOST_KEY_TRANSPORT_free(piVar16);
  }
LAB_00612260:
  if (local_2c == *(int *****)puStack_10e4) {
    return ppppiStack_10f4;
  }
  pcStack_10d4 = pkey_GOST01cp_decrypt;
  ppppiStack_219c = local_2c;
  (**(code **)(local_10b8 + -0x5330))();
  puStack_21a4 = PTR___stack_chk_guard_006a9ae8;
  puStack_2178 = &_gp;
  iStack_10fc = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppppiVar20 = ppppiStack_21a0;
  uStack_216c = uVar26;
  ppppiStack_10f0 = ppppiVar13;
  puStack_10ec = param_1;
  ppppiStack_10e0 = ppppiVar11;
  iStack_10dc = unaff_s6;
  pppiStack_10d8 = param_3;
  uVar14 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)();
  if (ppppiStack_21a0 == (int ****)0x0) {
    ppppiVar28 = (int ****)0x1;
    *(undefined **)pcStack_21ac = &DAT_00000020;
    goto LAB_006127a8;
  }
  pcStack_21ac = (char *)d2i_GOST_KEY_TRANSPORT(0,&uStack_216c,local_10c0);
  if ((int ***)pcStack_21ac == (int ***)0x0) {
    ppppiVar20 = (int ****)&DAT_00000068;
    ERR_GOST_error(0x76,0x68,"gost2001_keyx.c",0xee);
    ppppiVar28 = (int ****)0xffffffff;
    goto LAB_006127a8;
  }
  ppppiVar13 = (int ****)
               (**(code **)(puStack_2178 + -0x607c))((*(int ***)((int)pcStack_21ac + 4))[1]);
  if (ppppiVar13 == (int ****)0x0) {
    uVar26 = 2;
    uStack_217c = 0;
    ppppiVar20 = (int ****)0xffffffff;
    uStack_2180 = 3;
    iVar12 = (**(code **)(puStack_2178 + -0x7df4))(ppppiStack_219c,0xffffffff,0xffffffff);
    if (0 < iVar12) goto LAB_0061257c;
    ppppiVar20 = (int ****)&DAT_00000084;
    ppppiVar28 = (int ****)0x0;
    ERR_GOST_error(0x76,0x84,"gost2001_keyx.c",0xfe);
  }
  else {
    ppppiVar20 = ppppiVar13;
    iVar12 = (**(code **)(puStack_2178 + -0x70f0))(ppppiStack_219c);
    if (iVar12 < 1) {
      ppppiVar20 = (int ****)0x83;
      ppppiVar28 = (int ****)0x0;
      ERR_GOST_error(0x76,0x83,"gost2001_keyx.c",0xf7);
    }
    else {
LAB_0061257c:
      ppppiStack_219c = (int ****)(**(code **)(puStack_2178 + -0x55bc))(ppppiStack_219c);
      if (ppppiStack_219c == (int ****)0x0) {
        ppppiVar20 = (int ****)&DAT_00000078;
        ppppiVar28 = (int ****)0x0;
        ERR_GOST_error(0x76,0x78,"gost2001_keyx.c",0x104);
      }
      else {
        iVar12 = get_encryption_params(**(int ***)((int)pcStack_21ac + 4));
        if (iVar12 == 0) {
          ppppiVar28 = (int ****)0x0;
        }
        else {
          gost_init(auStack_2168,*(undefined4 *)(iVar12 + 4));
          piVar16 = (*(int ***)((int)pcStack_21ac + 4))[2];
          if (*piVar16 != 8) {
            (**(code **)(puStack_2178 + -0x7184))
                      ("gost2001_keyx.c",0x10e,"gkt->key_agreement_info->eph_iv->length == 8");
            piVar16 = (*(int ***)((int)pcStack_21ac + 4))[2];
          }
          ppppiVar11 = &pppiStack_1128;
          uVar24 = 0x20;
          pppiStack_1128 = *(int ****)(char **)piVar16[2];
          pcStack_1124 = ((char **)piVar16[2])[1];
          piVar16 = **(int ***)pcStack_21ac;
          pcVar25 = (char *)0x680000;
          pcVar23 = (char *)pppiStack_1128;
          if (*piVar16 != 0x20) {
            pcVar25 = "gkt->key_info->encrypted_key->length == 32";
            uVar24 = 0x110;
            pcVar23 = "gost2001_keyx.c";
            (**(code **)(puStack_2178 + -0x7184))();
            piVar16 = **(int ***)pcStack_21ac;
          }
          uVar19 = piVar16[2];
          uVar1 = uVar19 & 3;
          uVar2 = uVar19 + 4 & 3;
          uVar3 = uVar19 + 8 & 3;
          uVar4 = uVar19 + 0xc & 3;
          uVar5 = uVar19 + 0x10 & 3;
          uVar6 = uVar19 + 0x14 & 3;
          uVar7 = uVar19 + 0x18 & 3;
          uVar8 = uVar19 + 0x1c & 3;
          uVar9 = uVar19 + 3 & 3;
          uStack_1120 = (*(int *)(uVar19 - uVar1) << uVar1 * 8 |
                        in_t3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar9 + 1) * 8 |
                        *(uint *)((uVar19 + 3) - uVar9) >> (3 - uVar9) * 8;
          uVar1 = uVar19 + 7 & 3;
          uStack_111c = (*(int *)((uVar19 + 4) - uVar2) << uVar2 * 8 |
                        in_t2 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar19 + 7) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar19 + 0xb & 3;
          uStack_1118 = (*(int *)((uVar19 + 8) - uVar3) << uVar3 * 8 |
                        in_t1 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar19 + 0xb) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar19 + 0xf & 3;
          uStack_1114 = (*(int *)((uVar19 + 0xc) - uVar4) << uVar4 * 8 |
                        (uint)in_t0 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar19 + 0xf) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar19 + 0x13 & 3;
          uStack_1110 = (*(int *)((uVar19 + 0x10) - uVar5) << uVar5 * 8 |
                        uVar26 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar19 + 0x13) - uVar1) >> (3 - uVar1) * 8;
          uVar26 = uVar19 + 0x17 & 3;
          uStack_110c = (*(int *)((uVar19 + 0x14) - uVar6) << uVar6 * 8 |
                        (uint)pcVar25 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar26 + 1) * 8 |
                        *(uint *)((uVar19 + 0x17) - uVar26) >> (3 - uVar26) * 8;
          uVar26 = uVar19 + 0x1b & 3;
          uStack_1108 = (*(int *)((uVar19 + 0x18) - uVar7) << uVar7 * 8 |
                        uVar24 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar26 + 1) * 8 |
                        *(uint *)((uVar19 + 0x1b) - uVar26) >> (3 - uVar26) * 8;
          uVar26 = uVar19 + 0x1f & 3;
          uStack_1104 = (*(int *)((uVar19 + 0x1c) - uVar8) << uVar8 * 8 |
                        (uint)pcVar23 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar26 + 1) * 8 |
                        *(uint *)((uVar19 + 0x1f) - uVar26) >> (3 - uVar26) * 8;
          piVar16 = (*(int ***)pcStack_21ac)[1];
          if (*piVar16 != 4) {
            (**(code **)(puStack_2178 + -0x7184))
                      ("gost2001_keyx.c",0x112,"gkt->key_info->imit->length == 4");
            piVar16 = (*(int ***)pcStack_21ac)[1];
          }
          uStack_1100 = *(undefined4 *)piVar16[2];
          uVar15 = (**(code **)(puStack_2178 + -0x5808))(ppppiStack_219c);
          uVar15 = (**(code **)(puStack_2178 + -0x72fc))(uVar15);
          uVar14 = (**(code **)(puStack_2178 + -0x5808))(uVar14);
          ppppiStack_219c = apppiStack_1148;
          VKO_compute_key_isra_0(ppppiStack_219c,uVar15,uVar14,ppppiVar11);
          ppppiVar20 = ppppiStack_219c;
          iVar12 = keyUnwrapCryptoPro(auStack_2168,ppppiStack_219c,ppppiVar11,ppppiStack_21a0);
          if (iVar12 == 0) {
            ppppiVar20 = (int ****)0x66;
            ppppiVar28 = (int ****)0x0;
            ERR_GOST_error(0x76,0x66,"gost2001_keyx.c",0x119);
          }
          else {
            ppppiVar28 = (int ****)0x1;
          }
        }
      }
      if (ppppiVar13 == (int ****)0x0) goto LAB_00612798;
    }
    (**(code **)(puStack_2178 + -0x7f68))(ppppiVar13);
  }
LAB_00612798:
  GOST_KEY_TRANSPORT_free(pcStack_21ac);
  ppppiStack_21a0 = ppppiVar28;
LAB_006127a8:
  if (iStack_10fc == *(int *)puStack_21a4) {
    return ppppiVar28;
  }
  uStack_2194 = 0x6128f8;
  iVar12 = iStack_10fc;
  (**(code **)(puStack_2178 + -0x5330))();
  puVar10 = PTR___stack_chk_guard_006a9ae8;
  iStack_21cc = 0;
  iStack_21c8 = 0;
  iStack_21c4 = 0;
  iStack_21c0 = 0;
  iStack_21bc = 0;
  iStack_21b8 = 0;
  iStack_21b4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppppiStack_21a8 = ppppiVar13;
  ppppiStack_2198 = ppppiVar11;
  ppppiVar28 = (int ****)(*(code *)PTR_BN_CTX_new_006a794c)();
  if (ppppiVar28 == (int ****)0x0) {
    ppppiVar27 = (int ****)0x0;
    ERR_GOST_error(0x65,0x41,"gost2001.c",0x2d);
    ppppiVar28 = ppppiVar13;
    goto LAB_00612a90;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(ppppiVar28);
  iStack_21cc = (*(code *)PTR_BN_CTX_get_006a852c)(ppppiVar28);
  iStack_21c4 = (*(code *)PTR_BN_CTX_get_006a852c)(ppppiVar28);
  iStack_21c0 = (*(code *)PTR_BN_CTX_get_006a852c)(ppppiVar28);
  iStack_21bc = (*(code *)PTR_BN_CTX_get_006a852c)(ppppiVar28);
  iStack_21b8 = (*(code *)PTR_BN_CTX_get_006a852c)(ppppiVar28);
  iStack_21c8 = (*(code *)PTR_BN_CTX_get_006a852c)(ppppiVar28);
  if ((((iStack_21cc == 0) || (iStack_21c4 == 0)) || (iStack_21c0 == 0)) ||
     (((iStack_21bc == 0 || (iStack_21b8 == 0)) || (iStack_21c8 == 0)))) {
    uVar14 = 0x39;
LAB_00612acc:
    ERR_GOST_error(0x65,0x41,"gost2001.c",uVar14);
  }
  else {
    ppppiVar13 = *(int *****)PTR_R3410_2001_paramset_006a95f8;
    ppppiVar27 = (int ****)PTR_R3410_2001_paramset_006a95f8;
    while (ppppiVar13 != (int ****)0x0) {
      if (ppppiVar13 == ppppiVar20) {
        iVar21 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_21cc,ppppiVar27[3]);
        if (((iVar21 == 0) ||
            (iVar21 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_21c4,ppppiVar27[1]), iVar21 == 0))
           || (iVar21 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_21c0,ppppiVar27[2]), iVar21 == 0))
        {
          ERR_GOST_error(0x65,0x44,"gost2001.c",0x47);
          goto LAB_00612a6c;
        }
        ppppiVar20 = (int ****)
                     (*(code *)PTR_EC_GROUP_new_curve_GFp_006a8638)
                               (iStack_21cc,iStack_21c4,iStack_21c0,ppppiVar28);
        if (ppppiVar20 != (int ****)0x0) {
          ppppiVar11 = (int ****)(*(code *)PTR_EC_POINT_new_006a7fc0)(ppppiVar20);
          if (ppppiVar11 == (int ****)0x0) {
            ppppiVar27 = (int ****)0x0;
            ERR_GOST_error(0x65,0x41,"gost2001.c",0x53);
            goto LAB_00612c18;
          }
          iVar21 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_21bc,ppppiVar27[5]);
          if ((((iVar21 != 0) &&
               (iVar21 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_21b8,ppppiVar27[6]), iVar21 != 0)
               ) && (iVar21 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a8634)
                                        (ppppiVar20,ppppiVar11,iStack_21bc,iStack_21b8,ppppiVar28),
                    iVar21 != 0)) &&
             (iVar21 = (*(code *)PTR_BN_hex2bn_006a70f0)(&iStack_21c8,ppppiVar27[4]), iVar21 != 0))
          {
            iVar21 = (*(code *)PTR_EC_GROUP_set_generator_006a863c)
                               (ppppiVar20,ppppiVar11,iStack_21c8,0);
            if (iVar21 != 0) goto LAB_00612cd4;
            uVar14 = 0x66;
            goto LAB_00612bec;
          }
          uVar14 = 0x5b;
          goto LAB_00612bec;
        }
        uVar14 = 0x4d;
        goto LAB_00612acc;
      }
      ppppiVar27 = ppppiVar27 + 7;
      ppppiVar13 = (int ****)*ppppiVar27;
    }
    ERR_GOST_error(0x65,0x82,"gost2001.c",0x40);
  }
LAB_00612a6c:
  ppppiVar27 = (int ****)0x0;
  while( true ) {
    (*(code *)PTR_BN_CTX_end_006a8530)(ppppiVar28);
    (*(code *)PTR_BN_CTX_free_006a7954)(ppppiVar28);
LAB_00612a90:
    if (iStack_21b4 == *(int *)puVar10) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00612cd4:
    (*(code *)PTR_EC_GROUP_set_curve_name_006a862c)(ppppiVar20,*ppppiVar27);
    iVar21 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(iVar12,ppppiVar20);
    if (iVar21 == 0) {
      uVar14 = 0x6b;
LAB_00612bec:
      ppppiVar27 = (int ****)0x0;
      ERR_GOST_error(0x65,0x44,"gost2001.c",uVar14);
    }
    else {
      ppppiVar27 = (int ****)0x1;
    }
    (*(code *)PTR_EC_POINT_free_006a7fac)(ppppiVar11);
LAB_00612c18:
    (*(code *)PTR_EC_GROUP_free_006a719c)(ppppiVar20);
  }
  return ppppiVar27;
}

