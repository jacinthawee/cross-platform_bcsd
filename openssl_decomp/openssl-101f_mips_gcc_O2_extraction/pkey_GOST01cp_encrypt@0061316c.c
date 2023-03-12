
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
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int *piVar14;
  int **ppiVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  int iVar22;
  int ***pppiVar23;
  undefined4 *puVar24;
  char *pcVar25;
  uint uVar26;
  int iVar27;
  char *pcVar28;
  uint uVar29;
  int ***in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  int ****ppppiVar30;
  int iVar31;
  int ****ppppiVar32;
  int unaff_s6;
  int iVar33;
  int iVar34;
  int iStack_222c;
  int ****ppppiStack_2220;
  undefined4 uStack_21cc;
  char *pcStack_21c8;
  undefined4 uStack_21c4;
  undefined4 uStack_21c0;
  undefined4 uStack_21bc;
  undefined4 uStack_21b8;
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
  
  puStack_10e4 = PTR___stack_chk_guard_006aabf0;
  local_10b8 = &_gp;
  local_2c = *(int *****)PTR___stack_chk_guard_006aabf0;
  pcStack_21ac = (char *)param_3;
  uVar29 = param_4;
  local_10a4 = param_2;
  ppppiStack_2198 = (int ****)(*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006aa6e0)();
  iVar11 = (**(code **)(local_10b8 + -0x5804))(param_1);
  puStack_10e8 = (undefined4 *)get_encryption_params(0);
  ppppiStack_21a8 = (int ****)(**(code **)(local_10b8 + -0x55ac))(param_1);
  puVar24 = *(undefined4 **)(iVar11 + 8);
  if (puVar24 == (undefined4 *)0x0) {
    if (local_10a4 == (int ****)0x0) {
      if (ppppiStack_21a8 == (int ****)0x0) goto LAB_00613614;
      goto LAB_0061323c;
    }
    param_2 = (int ****)&DAT_00000008;
    iVar11 = (**(code **)(local_10b8 + -0x719c))(&local_80);
    if (0 < iVar11) goto LAB_00613230;
    uVar29 = 0x8a;
    pcStack_21ac = "gost2001_keyx.c";
    ppppiStack_21a0 = (int ****)&DAT_0000007c;
    ppppiStack_10f4 = (int ****)0x0;
    ERR_GOST_error(0x77);
  }
  else {
    local_80 = (int ***)*puVar24;
    local_7c = puVar24[1];
LAB_00613230:
    if (ppppiStack_21a8 == (int ****)0x0) {
      if (local_10a4 == (int ****)0x0) {
LAB_00613614:
        ppppiStack_21a8 = (int ****)0x0;
        unaff_s6 = 1;
        goto LAB_00613250;
      }
      ppppiStack_21a8 = (int ****)(**(code **)(local_10b8 + -0x77d0))();
      unaff_s6 = (**(code **)(local_10b8 + -0x7ed4))(ppppiStack_2198);
      pcStack_21ac = (char *)(**(code **)(local_10b8 + -0x7c38))();
      (**(code **)(local_10b8 + -0x69fc))(ppppiStack_21a8,unaff_s6);
      ppppiStack_21a0 = ppppiStack_2198;
      (**(code **)(local_10b8 + -0x7c6c))(ppppiStack_21a8);
      uVar12 = (**(code **)(local_10b8 + -0x57fc))(ppppiStack_21a8);
      iVar11 = gost2001_keygen(uVar12);
      if (iVar11 != 0) {
        unaff_s6 = 1;
        iVar11 = get_gost_engine_param(0);
        goto joined_r0x00613588;
      }
      piVar14 = (int *)0x0;
LAB_006135ac:
      if (ppppiStack_21a8 != (int ****)0x0) {
        (**(code **)(local_10b8 + -0x7f68))(ppppiStack_21a8);
      }
    }
    else {
LAB_0061323c:
      unaff_s6 = 0;
      iVar11 = gost_get0_priv_key(ppppiStack_21a8);
      if (iVar11 == 0) {
        uVar29 = 0x95;
        pcStack_21ac = "gost2001_keyx.c";
        ppppiStack_21a0 = (int ****)0x79;
        piVar14 = (int *)0x0;
        ERR_GOST_error(0x77);
      }
      else {
LAB_00613250:
        iVar11 = get_gost_engine_param(0);
        ppppiStack_21a0 = param_2;
joined_r0x00613588:
        if ((iVar11 == 0) && (puStack_10e8 == *(undefined4 **)(local_10b8 + -0x558c))) {
          puStack_10e8 = puStack_10e8 + 3;
        }
        if (local_10a4 != (int ****)0x0) {
          uVar12 = (**(code **)(local_10b8 + -0x57fc))(ppppiStack_2198);
          uVar12 = (**(code **)(local_10b8 + -0x7310))(uVar12);
          uVar13 = (**(code **)(local_10b8 + -0x57fc))(ppppiStack_21a8);
          local_10a8 = (int ***)&local_80;
          local_10ac = apppiStack_78;
          VKO_compute_key_isra_0(local_10ac,uVar12,uVar13,local_10a8);
          gost_init(auStack_10a0,puStack_10e8[1]);
          local_10c0 = auStack_58;
          ppppiStack_21a0 = local_10ac;
          pcStack_21ac = (char *)local_10a8;
          in_t0 = local_10a8;
          keyWrapCryptoPro(auStack_10a0);
          uVar29 = param_4;
        }
        piVar14 = (int *)GOST_KEY_TRANSPORT_new();
        if (piVar14 != (int *)0x0) {
          pcStack_21ac = &DAT_00000008;
          ppppiStack_21a0 = &local_80;
          iVar11 = (**(code **)(local_10b8 + -0x6750))(*(undefined4 *)(piVar14[1] + 8));
          if (iVar11 != 0) {
            pcStack_21ac = &SUB_00000004;
            ppppiStack_21a0 = &pppiStack_30;
            iVar11 = (**(code **)(local_10b8 + -0x6750))(*(undefined4 *)(*piVar14 + 4));
            if (iVar11 != 0) {
              pcStack_21ac = &DAT_00000020;
              ppppiStack_21a0 = apppiStack_50;
              iVar11 = (**(code **)(local_10b8 + -0x6750))(*(undefined4 *)*piVar14);
              if (iVar11 != 0) {
                if (unaff_s6 == 0) {
                  (**(code **)(local_10b8 + -0x7ddc))(*(undefined4 *)piVar14[1]);
                  ppppiStack_21a8 = (int ****)piVar14[1];
                  pppiVar23 = (int ***)(**(code **)(local_10b8 + -0x7ca0))(*puStack_10e8);
                  uVar29 = 2;
                  pcStack_21ac = (char *)0xffffffff;
                  *ppppiStack_21a8 = pppiVar23;
                  local_10bc = 0;
                  local_10c0 = (undefined *)0x3;
                  iVar11 = (**(code **)(local_10b8 + -0x7df4))(param_1,0xffffffff);
                  if (iVar11 < 1) {
                    uVar29 = 0xd4;
                    pcStack_21ac = "gost2001_keyx.c";
                    ppppiStack_21a0 = (int ****)&DAT_00000084;
                    ERR_GOST_error(0x77);
                    goto LAB_006134dc;
                  }
                }
                else {
                  if (local_10a4 != (int ****)0x0) {
                    ppppiStack_2198 = ppppiStack_21a8;
                  }
                  iVar11 = (**(code **)(local_10b8 + -0x5efc))(piVar14[1] + 4,ppppiStack_2198);
                  if (iVar11 == 0) {
                    uVar29 = 199;
                    pcStack_21ac = "gost2001_keyx.c";
                    ppppiStack_21a0 = (int ****)&DAT_00000065;
                    ERR_GOST_error(0x77);
                    goto LAB_006135ac;
                  }
                  (**(code **)(local_10b8 + -0x7ddc))(*(undefined4 *)piVar14[1]);
                  param_1 = (undefined4 *)piVar14[1];
                  uVar12 = (**(code **)(local_10b8 + -0x7ca0))(*puStack_10e8);
                  *param_1 = uVar12;
                  if (ppppiStack_21a8 != (int ****)0x0) {
                    (**(code **)(local_10b8 + -0x7f68))(ppppiStack_21a8);
                  }
                }
                ppppiStack_21a0 = (int ****)0x0;
                if (local_10a4 != (int ****)0x0) {
                  ppppiStack_21a0 = (int ****)&local_10a4;
                }
                ppiVar15 = (int **)i2d_GOST_KEY_TRANSPORT(piVar14);
                ppppiStack_10f4 = (int ****)(uint)(ppiVar15 != (int **)0x0);
                *param_3 = ppiVar15;
                GOST_KEY_TRANSPORT_free(piVar14);
                goto LAB_00613420;
              }
            }
          }
        }
        if (unaff_s6 != 0) goto LAB_006135ac;
      }
    }
LAB_006134dc:
    ppppiStack_10f4 = (int ****)0xffffffff;
    GOST_KEY_TRANSPORT_free(piVar14);
  }
LAB_00613420:
  if (local_2c == *(int *****)puStack_10e4) {
    return ppppiStack_10f4;
  }
  pcStack_10d4 = pkey_GOST01cp_decrypt;
  ppppiStack_219c = local_2c;
  (**(code **)(local_10b8 + -0x5328))();
  puStack_21a4 = PTR___stack_chk_guard_006aabf0;
  puStack_2178 = &_gp;
  iStack_10fc = *(int *)PTR___stack_chk_guard_006aabf0;
  ppppiVar30 = ppppiStack_21a0;
  uStack_216c = uVar29;
  ppppiStack_10f0 = ppppiStack_21a8;
  puStack_10ec = param_1;
  ppppiStack_10e0 = ppppiStack_2198;
  iStack_10dc = unaff_s6;
  pppiStack_10d8 = param_3;
  uVar12 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006aa6e0)();
  if (ppppiStack_21a0 == (int ****)0x0) {
    ppppiVar32 = (int ****)0x1;
    *(undefined **)pcStack_21ac = &DAT_00000020;
    goto LAB_00613968;
  }
  pcStack_21ac = (char *)d2i_GOST_KEY_TRANSPORT(0,&uStack_216c,local_10c0);
  if ((int ***)pcStack_21ac == (int ***)0x0) {
    ppppiVar30 = (int ****)&DAT_00000068;
    ERR_GOST_error(0x76,0x68,"gost2001_keyx.c",0xf9);
    ppppiVar32 = (int ****)0xffffffff;
    goto LAB_00613968;
  }
  ppppiStack_21a8 =
       (int ****)(**(code **)(puStack_2178 + -0x605c))((*(int ***)((int)pcStack_21ac + 4))[1]);
  if (ppppiStack_21a8 == (int ****)0x0) {
    uVar29 = 2;
    uStack_217c = 0;
    ppppiVar30 = (int ****)0xffffffff;
    uStack_2180 = 3;
    iVar11 = (**(code **)(puStack_2178 + -0x7df4))(ppppiStack_219c,0xffffffff,0xffffffff);
    if (0 < iVar11) goto LAB_0061373c;
    ppppiVar30 = (int ****)&DAT_00000084;
    ppppiVar32 = (int ****)0x0;
    ERR_GOST_error(0x76,0x84,"gost2001_keyx.c",0x10e);
  }
  else {
    ppppiVar30 = ppppiStack_21a8;
    iVar11 = (**(code **)(puStack_2178 + -0x7100))(ppppiStack_219c);
    if (iVar11 < 1) {
      ppppiVar30 = (int ****)0x83;
      ppppiVar32 = (int ****)0x0;
      ERR_GOST_error(0x76,0x83,"gost2001_keyx.c",0x104);
    }
    else {
LAB_0061373c:
      ppppiStack_219c = (int ****)(**(code **)(puStack_2178 + -0x55ac))(ppppiStack_219c);
      if (ppppiStack_219c == (int ****)0x0) {
        ppppiVar30 = (int ****)&DAT_00000078;
        ppppiVar32 = (int ****)0x0;
        ERR_GOST_error(0x76,0x78,"gost2001_keyx.c",0x116);
      }
      else {
        iVar11 = get_encryption_params(**(int ***)((int)pcStack_21ac + 4));
        if (iVar11 == 0) {
          ppppiVar32 = (int ****)0x0;
        }
        else {
          gost_init(auStack_2168,*(undefined4 *)(iVar11 + 4));
          piVar14 = (*(int ***)((int)pcStack_21ac + 4))[2];
          if (*piVar14 != 8) {
            (**(code **)(puStack_2178 + -0x7194))
                      ("gost2001_keyx.c",0x120,"gkt->key_agreement_info->eph_iv->length==8");
            piVar14 = (*(int ***)((int)pcStack_21ac + 4))[2];
          }
          ppppiStack_2198 = &pppiStack_1128;
          uVar26 = 0x20;
          pppiStack_1128 = *(int ****)(char **)piVar14[2];
          pcStack_1124 = ((char **)piVar14[2])[1];
          piVar14 = **(int ***)pcStack_21ac;
          pcVar28 = (char *)0x680000;
          pcVar25 = (char *)pppiStack_1128;
          if (*piVar14 != 0x20) {
            pcVar28 = "gkt->key_info->encrypted_key->length==32";
            uVar26 = 0x122;
            pcVar25 = "gost2001_keyx.c";
            (**(code **)(puStack_2178 + -0x7194))();
            piVar14 = **(int ***)pcStack_21ac;
          }
          uVar16 = piVar14[2];
          uVar1 = uVar16 & 3;
          uVar2 = uVar16 + 4 & 3;
          uVar3 = uVar16 + 8 & 3;
          uVar4 = uVar16 + 0xc & 3;
          uVar5 = uVar16 + 0x10 & 3;
          uVar6 = uVar16 + 0x14 & 3;
          uVar7 = uVar16 + 0x18 & 3;
          uVar8 = uVar16 + 0x1c & 3;
          uVar9 = uVar16 + 3 & 3;
          uStack_1120 = (*(int *)(uVar16 - uVar1) << uVar1 * 8 |
                        in_t3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar9 + 1) * 8 |
                        *(uint *)((uVar16 + 3) - uVar9) >> (3 - uVar9) * 8;
          uVar1 = uVar16 + 7 & 3;
          uStack_111c = (*(int *)((uVar16 + 4) - uVar2) << uVar2 * 8 |
                        in_t2 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar16 + 7) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar16 + 0xb & 3;
          uStack_1118 = (*(int *)((uVar16 + 8) - uVar3) << uVar3 * 8 |
                        in_t1 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar16 + 0xb) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar16 + 0xf & 3;
          uStack_1114 = (*(int *)((uVar16 + 0xc) - uVar4) << uVar4 * 8 |
                        (uint)in_t0 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar16 + 0xf) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar16 + 0x13 & 3;
          uStack_1110 = (*(int *)((uVar16 + 0x10) - uVar5) << uVar5 * 8 |
                        uVar29 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar16 + 0x13) - uVar1) >> (3 - uVar1) * 8;
          uVar29 = uVar16 + 0x17 & 3;
          uStack_110c = (*(int *)((uVar16 + 0x14) - uVar6) << uVar6 * 8 |
                        (uint)pcVar28 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar29 + 1) * 8 |
                        *(uint *)((uVar16 + 0x17) - uVar29) >> (3 - uVar29) * 8;
          uVar29 = uVar16 + 0x1b & 3;
          uStack_1108 = (*(int *)((uVar16 + 0x18) - uVar7) << uVar7 * 8 |
                        uVar26 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar29 + 1) * 8 |
                        *(uint *)((uVar16 + 0x1b) - uVar29) >> (3 - uVar29) * 8;
          uVar29 = uVar16 + 0x1f & 3;
          uStack_1104 = (*(int *)((uVar16 + 0x1c) - uVar8) << uVar8 * 8 |
                        (uint)pcVar25 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar29 + 1) * 8 |
                        *(uint *)((uVar16 + 0x1f) - uVar29) >> (3 - uVar29) * 8;
          piVar14 = (*(int ***)pcStack_21ac)[1];
          if (*piVar14 != 4) {
            (**(code **)(puStack_2178 + -0x7194))
                      ("gost2001_keyx.c",0x124,"gkt->key_info->imit->length==4");
            piVar14 = (*(int ***)pcStack_21ac)[1];
          }
          uStack_1100 = *(undefined4 *)piVar14[2];
          uVar13 = (**(code **)(puStack_2178 + -0x57fc))(ppppiStack_219c);
          uVar13 = (**(code **)(puStack_2178 + -0x7310))(uVar13);
          uVar12 = (**(code **)(puStack_2178 + -0x57fc))(uVar12);
          ppppiStack_219c = apppiStack_1148;
          VKO_compute_key_isra_0(ppppiStack_219c,uVar13,uVar12,ppppiStack_2198);
          ppppiVar30 = ppppiStack_219c;
          iVar11 = keyUnwrapCryptoPro(auStack_2168,ppppiStack_219c,ppppiStack_2198,ppppiStack_21a0);
          if (iVar11 == 0) {
            ppppiVar30 = (int ****)0x66;
            ppppiVar32 = (int ****)0x0;
            ERR_GOST_error(0x76,0x66,"gost2001_keyx.c",299);
          }
          else {
            ppppiVar32 = (int ****)0x1;
          }
        }
      }
      if (ppppiStack_21a8 == (int ****)0x0) goto LAB_00613958;
    }
    (**(code **)(puStack_2178 + -0x7f68))(ppppiStack_21a8);
  }
LAB_00613958:
  GOST_KEY_TRANSPORT_free(pcStack_21ac);
  ppppiStack_21a0 = ppppiVar32;
LAB_00613968:
  if (iStack_10fc == *(int *)puStack_21a4) {
    return ppppiVar32;
  }
  uStack_2194 = 0x613ab8;
  iVar11 = iStack_10fc;
  (**(code **)(puStack_2178 + -0x5328))();
  puVar10 = PTR___stack_chk_guard_006aabf0;
  uStack_21cc = 0;
  pcStack_21c8 = (char *)0x0;
  uStack_21c4 = 0;
  uStack_21c0 = 0;
  uStack_21bc = 0;
  uStack_21b8 = 0;
  iStack_21b4 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar12 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar12);
  uStack_21cc = (*(code *)PTR_BN_CTX_get_006a9648)(uVar12);
  uStack_21c4 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar12);
  uStack_21c0 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar12);
  uStack_21bc = (*(code *)PTR_BN_CTX_get_006a9648)(uVar12);
  uStack_21b8 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar12);
  pcStack_21c8 = (char *)(*(code *)PTR_BN_CTX_get_006a9648)(uVar12);
  ppppiVar32 = *(int *****)PTR_R3410_2001_paramset_006aa704;
  puVar24 = (undefined4 *)PTR_R3410_2001_paramset_006aa704;
  while (ppppiVar32 != (int ****)0x0) {
    if (ppppiVar30 == ppppiVar32) {
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_21cc,puVar24[3]);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_21c4,puVar24[1]);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_21c0,puVar24[2]);
      iVar31 = (*(code *)PTR_EC_GROUP_new_curve_GFp_006a975c)
                         (uStack_21cc,uStack_21c4,uStack_21c0,uVar12);
      uVar13 = (*(code *)PTR_EC_POINT_new_006a9140)(iVar31);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_21bc,puVar24[5]);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&uStack_21b8,puVar24[6]);
      (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a9758)
                (iVar31,uVar13,uStack_21bc,uStack_21b8,uVar12);
      (*(code *)PTR_BN_hex2bn_006a81f0)(&pcStack_21c8,puVar24[4]);
      pcVar25 = pcStack_21c8;
      (*(code *)PTR_EC_GROUP_set_generator_006a9760)(iVar31,uVar13,pcStack_21c8,0);
      ppppiVar30 = (int ****)0x1;
      (*(code *)PTR_EC_GROUP_set_curve_name_006a9750)(iVar31,*puVar24);
      iVar27 = iVar31;
      (*(code *)PTR_EC_KEY_set_group_006a82d0)(iVar11);
      goto LAB_00613c04;
    }
    puVar24 = puVar24 + 7;
    ppppiVar32 = (int ****)*puVar24;
  }
  pcVar25 = "gost2001.c";
  iVar27 = 0x82;
  ppppiVar30 = (int ****)0x0;
  ERR_GOST_error(0x65,0x82,"gost2001.c",0x35);
  uVar13 = 0;
  iVar31 = 0;
LAB_00613c04:
  (*(code *)PTR_EC_POINT_free_006a9134)(uVar13);
  (*(code *)PTR_EC_GROUP_free_006a829c)(iVar31);
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar12);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar12);
  if (iStack_21b4 == *(int *)puVar10) {
    return ppppiVar30;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar12 = (*(code *)PTR_hashsum2bn_006aa960)();
  uVar13 = (*(code *)PTR_BN_CTX_new_006a8a38)();
  (*(code *)PTR_BN_CTX_start_006a9644)(uVar13);
  if (iVar27 != 0x20) {
    (*(code *)PTR_OpenSSLDie_006a8d4c)("gost2001.c",0x69,"dlen==32");
  }
  ppppiStack_2220 = (int ****)(*(code *)PTR_DSA_SIG_new_006a9880)();
  if (ppppiStack_2220 == (int ****)0x0) {
    uVar21 = 0;
    ERR_GOST_error(0x69,0x76,"gost2001.c",0x6d);
  }
  else {
    uVar17 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(pcVar25);
    uVar18 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
    (*(code *)PTR_EC_GROUP_get_order_006a82ec)(uVar17,uVar18,uVar13);
    uVar19 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(pcVar25);
    iVar11 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
    (*(code *)PTR_BN_div_006a967c)(0,iVar11,uVar12,uVar18,uVar13);
    if (*(int *)(iVar11 + 4) == 0) {
      (*(code *)PTR_BN_set_word_006a8820)(iVar11,1);
    }
    iVar34 = 0;
    iVar27 = 0;
    uVar20 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
    iVar33 = 0;
    iVar31 = 0;
    uVar21 = (*(code *)PTR_EC_POINT_new_006a9140)(uVar17);
    iStack_222c = 0;
    do {
      do {
        iVar22 = (*(code *)PTR_BN_rand_range_006a97b0)(uVar20,uVar18);
        if (iVar22 == 0) {
          uVar18 = 0x89;
          uVar17 = 0x7d;
LAB_006140dc:
          ERR_GOST_error(0x69,uVar17,"gost2001.c",uVar18);
          (*(code *)PTR_DSA_SIG_free_006a987c)(ppppiStack_2220);
          ppppiStack_2220 = (int ****)0x0;
          goto LAB_006140fc;
        }
        iVar22 = (*(code *)PTR_EC_POINT_mul_006a976c)(uVar17,uVar21,uVar20,0,0,uVar13);
        if (iVar22 == 0) {
          uVar18 = 0x90;
LAB_0061418c:
          uVar17 = 0x10;
          goto LAB_006140dc;
        }
        if (iVar27 == 0) {
          iVar27 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
        }
        iVar22 = (*(code *)PTR_EC_POINT_get_affine_coordinates_GFp_006a97bc)
                           (uVar17,uVar21,iVar27,0,uVar13);
        if (iVar22 == 0) {
          uVar18 = 0x98;
          goto LAB_0061418c;
        }
        if (iVar31 == 0) {
          iVar31 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
        }
        (*(code *)PTR_BN_nnmod_006a9664)(iVar31,iVar27,uVar18,uVar13);
      } while (*(int *)(iVar31 + 4) == 0);
      if (iStack_222c == 0) {
        iStack_222c = (*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
      }
      (*(code *)PTR_BN_mod_mul_006a9698)(iStack_222c,uVar19,iVar31,uVar18,uVar13);
      if (iVar34 == 0) {
        iVar34 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
      }
      (*(code *)PTR_BN_mod_mul_006a9698)(iVar34,uVar20,iVar11,uVar18,uVar13);
      if (iVar33 == 0) {
        iVar33 = (*(code *)PTR_BN_CTX_get_006a9648)(uVar13);
      }
      (*(code *)PTR_BN_mod_add_006aa61c)(iVar33,iStack_222c,iVar34,uVar18,uVar13);
    } while (*(int *)(iVar33 + 4) == 0);
    pppiVar23 = (int ***)(*(code *)PTR_BN_dup_006a9100)(iVar33);
    puVar10 = PTR_BN_dup_006a9100;
    ppppiStack_2220[1] = pppiVar23;
    pppiVar23 = (int ***)(*(code *)puVar10)(iVar31);
    *ppppiStack_2220 = pppiVar23;
  }
LAB_006140fc:
  (*(code *)PTR_BN_CTX_end_006a9654)(uVar13);
  (*(code *)PTR_BN_CTX_free_006a8a40)(uVar13);
  (*(code *)PTR_EC_POINT_free_006a9134)(uVar21);
  (*(code *)PTR_BN_free_006a811c)(uVar12);
  return ppppiStack_2220;
}

