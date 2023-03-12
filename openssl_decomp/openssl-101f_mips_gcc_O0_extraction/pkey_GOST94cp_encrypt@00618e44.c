
undefined4 pkey_GOST94cp_encrypt(undefined4 param_1,int param_2,int *param_3,uint param_4)

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
  int iVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int **ppiVar15;
  int iVar16;
  int *piVar17;
  uint uVar18;
  int *piVar19;
  uint uVar20;
  char *pcVar21;
  char *pcVar22;
  uint uVar23;
  uint in_t0;
  uint in_t1;
  uint in_t2;
  uint in_t3;
  uint uStack_2164;
  undefined auStack_2160 [4128];
  undefined auStack_1140 [32];
  char *pcStack_1120;
  char *pcStack_111c;
  uint uStack_1118;
  uint uStack_1114;
  uint uStack_1110;
  uint uStack_110c;
  uint uStack_1108;
  uint uStack_1104;
  uint uStack_1100;
  uint uStack_10fc;
  undefined4 uStack_10f8;
  int iStack_10f4;
  int *piStack_10ec;
  int *piStack_10e8;
  undefined4 uStack_10e4;
  undefined4 *puStack_10e0;
  undefined *puStack_10dc;
  int iStack_10d8;
  int *piStack_10d4;
  int *piStack_10d0;
  code *pcStack_10cc;
  undefined *local_10b8;
  undefined4 local_10b4;
  undefined *local_10b0;
  int local_10a4;
  undefined auStack_10a0 [4128];
  undefined4 local_80;
  undefined4 local_7c;
  undefined auStack_78 [32];
  undefined auStack_58 [8];
  undefined auStack_50 [32];
  undefined auStack_30 [4];
  int local_2c;
  
  puStack_10dc = PTR___stack_chk_guard_006aabf0;
  local_10b0 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar23 = param_4;
  local_10a4 = param_2;
  puStack_10e0 = (undefined4 *)get_encryption_params(0);
  piStack_10d4 = (int *)(**(code **)(local_10b0 + -0x5800))(param_1);
  iVar11 = (**(code **)(local_10b0 + -0x5804))(param_1);
  piStack_10e8 = (int *)(**(code **)(local_10b0 + -0x55ac))(param_1);
  iVar12 = get_gost_engine_param(0);
  if ((iVar12 == 0) && (puStack_10e0 == *(undefined4 **)(local_10b0 + -0x558c))) {
    puStack_10e0 = puStack_10e0 + 3;
  }
  if (piStack_10e8 != (int *)0x0) {
    iStack_10d8 = 0;
    iVar12 = gost_get0_priv_key(piStack_10e8);
    if (iVar12 != 0) {
      if (local_10a4 == 0) goto LAB_006191cc;
LAB_00618f28:
      uVar13 = gost_get0_priv_key(piStack_10e8);
      make_cp_exchange_key(uVar13,piStack_10d4,auStack_78);
      puVar14 = *(undefined4 **)(iVar11 + 8);
      if (puVar14 != (undefined4 *)0x0) {
        local_80 = *puVar14;
        iVar11 = local_10a4;
        goto LAB_00618f58;
      }
      if (local_10a4 == 0) goto LAB_00618fac;
      iVar12 = (**(code **)(local_10b0 + -0x719c))(&local_80,8);
      iVar11 = local_10a4;
      if (iVar12 < 1) {
        uVar23 = 0x8e;
        pcVar21 = "gost94_keyx.c";
        piVar19 = (int *)&DAT_0000007c;
        piStack_10ec = (int *)0x0;
        ERR_GOST_error(0x7b);
        goto LAB_00619208;
      }
      goto LAB_00618f6c;
    }
    uVar23 = 0x70;
    pcVar21 = "gost94_keyx.c";
    piVar19 = (int *)0x79;
    piStack_10ec = (int *)0x0;
    ERR_GOST_error(0x7b);
    goto LAB_00619208;
  }
  if (local_10a4 == 0) {
    iStack_10d8 = 1;
  }
  else {
    piStack_10e8 = (int *)(**(code **)(local_10b0 + -0x77d0))();
    iStack_10d8 = (**(code **)(local_10b0 + -0x7ed4))(piStack_10d4);
    pcVar21 = (char *)(**(code **)(local_10b0 + -0x78bc))();
    (**(code **)(local_10b0 + -0x69fc))(piStack_10e8,iStack_10d8);
    piVar19 = piStack_10d4;
    (**(code **)(local_10b0 + -0x7c6c))(piStack_10e8);
    uVar13 = (**(code **)(local_10b0 + -0x57fc))(piStack_10e8);
    iVar12 = (**(code **)(local_10b0 + -0x57c0))(uVar13);
    if (iVar12 == 0) {
      piStack_10ec = (int *)0x0;
      goto LAB_00619208;
    }
    iStack_10d8 = 1;
    if (local_10a4 != 0) goto LAB_00618f28;
  }
LAB_006191cc:
  puVar14 = *(undefined4 **)(iVar11 + 8);
  iVar11 = 0;
  if (puVar14 != (undefined4 *)0x0) {
    local_80 = *puVar14;
LAB_00618f58:
    local_7c = puVar14[1];
LAB_00618f6c:
    if (iVar11 != 0) {
      gost_init(auStack_10a0,puStack_10e0[1]);
      local_10b8 = auStack_58;
      keyWrapCryptoPro(auStack_10a0,auStack_78,&local_80);
      uVar23 = param_4;
    }
  }
LAB_00618fac:
  piStack_10ec = (int *)GOST_KEY_TRANSPORT_new();
  if (((piStack_10ec == (int *)0x0) ||
      (iVar11 = (**(code **)(local_10b0 + -0x6750))
                          (*(undefined4 *)(piStack_10ec[1] + 8),&local_80,8), iVar11 == 0)) ||
     (iVar11 = (**(code **)(local_10b0 + -0x6750))(*(undefined4 *)(*piStack_10ec + 4),auStack_30,4),
     iVar11 == 0)) {
LAB_006191e0:
    if (iStack_10d8 != 0) {
      (**(code **)(local_10b0 + -0x7f68))(piStack_10e8);
    }
    uVar23 = 0xca;
    pcVar21 = "gost94_keyx.c";
    piVar19 = (int *)0x75;
    ERR_GOST_error(0x7b);
LAB_00619208:
    GOST_KEY_TRANSPORT_free(piStack_10ec);
    uVar13 = 0xffffffff;
  }
  else {
    pcVar21 = &DAT_00000020;
    iVar11 = (**(code **)(local_10b0 + -0x6750))(*(undefined4 *)*piStack_10ec,auStack_50);
    if (iVar11 == 0) goto LAB_006191e0;
    if (iStack_10d8 != 0) {
      if (local_10a4 != 0) {
        piStack_10d4 = piStack_10e8;
      }
      iVar11 = (**(code **)(local_10b0 + -0x5efc))(piStack_10ec[1] + 4,piStack_10d4);
      if (iVar11 == 0) {
        uVar23 = 0xac;
        pcVar21 = "gost94_keyx.c";
        piVar19 = (int *)&DAT_00000065;
        ERR_GOST_error(0x7b);
        goto LAB_00619208;
      }
      if (local_10a4 != 0) {
        (**(code **)(local_10b0 + -0x7f68))(piStack_10e8);
      }
    }
    (**(code **)(local_10b0 + -0x7ddc))(*(undefined4 *)piStack_10ec[1]);
    piStack_10e8 = (int *)piStack_10ec[1];
    iVar11 = (**(code **)(local_10b0 + -0x7ca0))(*puStack_10e0);
    *piStack_10e8 = iVar11;
    if (local_10a4 == 0) {
      piVar19 = (int *)0x0;
    }
    else {
      piVar19 = &local_10a4;
    }
    iVar11 = i2d_GOST_KEY_TRANSPORT(piStack_10ec);
    *param_3 = iVar11;
    if (iVar11 == 0) {
      uVar23 = 0xb6;
      pcVar21 = "gost94_keyx.c";
      piVar19 = (int *)0x67;
      ERR_GOST_error(0x7b);
      goto LAB_00619208;
    }
    if (iStack_10d8 == 0) {
      uVar23 = 2;
      local_10b4 = 0;
      pcVar21 = (char *)0xffffffff;
      piVar19 = (int *)0xffffffff;
      local_10b8 = (undefined *)0x3;
      iVar11 = (**(code **)(local_10b0 + -0x7df4))(param_1);
      if (iVar11 < 1) {
        uVar23 = 0xbf;
        pcVar21 = "gost94_keyx.c";
        piVar19 = (int *)&DAT_00000084;
        ERR_GOST_error(0x7b);
        goto LAB_00619208;
      }
    }
    GOST_KEY_TRANSPORT_free(piStack_10ec);
    uVar13 = 1;
  }
  if (local_2c == *(int *)puStack_10dc) {
    return uVar13;
  }
  pcStack_10cc = pkey_GOST94cp_decrypt;
  iVar11 = local_2c;
  (**(code **)(local_10b0 + -0x5328))();
  puVar10 = PTR___stack_chk_guard_006aabf0;
  iStack_10f4 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_2164 = uVar23;
  uStack_10e4 = param_1;
  piStack_10d0 = param_3;
  uVar13 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006aa6e0)();
  if (piVar19 == (int *)0x0) {
    uVar13 = 1;
    *(undefined4 *)pcVar21 = 0x20;
    goto LAB_006195fc;
  }
  ppiVar15 = (int **)d2i_GOST_KEY_TRANSPORT(0,&uStack_2164,local_10b8);
  if (ppiVar15 == (int **)0x0) {
    ERR_GOST_error(0x7a,0x68,"gost94_keyx.c",0xe8);
    uVar13 = 0;
    goto LAB_006195fc;
  }
  iVar12 = (*(code *)PTR_X509_PUBKEY_get_006a9e84)(ppiVar15[1][1]);
  if (iVar12 == 0) {
    uVar23 = 2;
    iVar16 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(iVar11,0xffffffff,0xffffffff,2,3,0);
    if (0 < iVar16) goto LAB_00619404;
    ERR_GOST_error(0x7a,0x84,"gost94_keyx.c",0xfb);
  }
  else {
    iVar16 = (*(code *)PTR_EVP_PKEY_derive_set_peer_006a8de0)(iVar11,iVar12);
    if (iVar16 < 1) {
      ERR_GOST_error(0x7a,0x83,"gost94_keyx.c",0xf1);
    }
    else {
LAB_00619404:
      iVar11 = (*(code *)PTR_EVP_PKEY_CTX_get0_peerkey_006aa934)(iVar11);
      if (iVar11 == 0) {
        ERR_GOST_error(0x7a,0x78,"gost94_keyx.c",0x103);
      }
      else {
        iVar16 = get_encryption_params(*ppiVar15[1]);
        if (iVar16 != 0) {
          gost_init(auStack_2160,*(undefined4 *)(iVar16 + 4));
          piVar17 = (int *)ppiVar15[1][2];
          if (*piVar17 != 8) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)
                      ("gost94_keyx.c",0x10d,"gkt->key_agreement_info->eph_iv->length==8");
            piVar17 = (int *)ppiVar15[1][2];
          }
          uVar20 = 0x20;
          pcStack_1120 = *(char **)piVar17[2];
          pcStack_111c = ((char **)piVar17[2])[1];
          piVar17 = (int *)**ppiVar15;
          pcVar22 = (char *)0x680000;
          pcVar21 = pcStack_1120;
          if (*piVar17 != 0x20) {
            pcVar22 = "gkt->key_info->encrypted_key->length==32";
            uVar20 = 0x10f;
            pcVar21 = "gost94_keyx.c";
            (*(code *)PTR_OpenSSLDie_006a8d4c)();
            piVar17 = (int *)**ppiVar15;
          }
          uVar18 = piVar17[2];
          uVar1 = uVar18 & 3;
          uVar2 = uVar18 + 4 & 3;
          uVar3 = uVar18 + 8 & 3;
          uVar4 = uVar18 + 0xc & 3;
          uVar5 = uVar18 + 0x10 & 3;
          uVar6 = uVar18 + 0x14 & 3;
          uVar7 = uVar18 + 0x18 & 3;
          uVar8 = uVar18 + 0x1c & 3;
          uVar9 = uVar18 + 3 & 3;
          uStack_1118 = (*(int *)(uVar18 - uVar1) << uVar1 * 8 |
                        in_t3 & 0xffffffffU >> (4 - uVar1) * 8) & -1 << (uVar9 + 1) * 8 |
                        *(uint *)((uVar18 + 3) - uVar9) >> (3 - uVar9) * 8;
          uVar1 = uVar18 + 7 & 3;
          uStack_1114 = (*(int *)((uVar18 + 4) - uVar2) << uVar2 * 8 |
                        in_t2 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar18 + 7) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar18 + 0xb & 3;
          uStack_1110 = (*(int *)((uVar18 + 8) - uVar3) << uVar3 * 8 |
                        in_t1 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar18 + 0xb) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar18 + 0xf & 3;
          uStack_110c = (*(int *)((uVar18 + 0xc) - uVar4) << uVar4 * 8 |
                        in_t0 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar18 + 0xf) - uVar1) >> (3 - uVar1) * 8;
          uVar1 = uVar18 + 0x13 & 3;
          uStack_1108 = (*(int *)((uVar18 + 0x10) - uVar5) << uVar5 * 8 |
                        uVar23 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar1 + 1) * 8 |
                        *(uint *)((uVar18 + 0x13) - uVar1) >> (3 - uVar1) * 8;
          uVar23 = uVar18 + 0x17 & 3;
          uStack_1104 = (*(int *)((uVar18 + 0x14) - uVar6) << uVar6 * 8 |
                        (uint)pcVar22 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar23 + 1) * 8 |
                        *(uint *)((uVar18 + 0x17) - uVar23) >> (3 - uVar23) * 8;
          uVar23 = uVar18 + 0x1b & 3;
          uStack_1100 = (*(int *)((uVar18 + 0x18) - uVar7) << uVar7 * 8 |
                        uVar20 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar23 + 1) * 8 |
                        *(uint *)((uVar18 + 0x1b) - uVar23) >> (3 - uVar23) * 8;
          uVar23 = uVar18 + 0x1f & 3;
          uStack_10fc = (*(int *)((uVar18 + 0x1c) - uVar8) << uVar8 * 8 |
                        (uint)pcVar21 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar23 + 1) * 8 |
                        *(uint *)((uVar18 + 0x1f) - uVar23) >> (3 - uVar23) * 8;
          piVar17 = (int *)(*ppiVar15)[1];
          if (*piVar17 != 4) {
            (*(code *)PTR_OpenSSLDie_006a8d4c)
                      ("gost94_keyx.c",0x111,"gkt->key_info->imit->length==4");
            piVar17 = (int *)(*ppiVar15)[1];
          }
          uStack_10f8 = *(undefined4 *)piVar17[2];
          uVar13 = gost_get0_priv_key(uVar13);
          make_cp_exchange_key(uVar13,iVar11,auStack_1140);
          iVar11 = keyUnwrapCryptoPro(auStack_2160,auStack_1140,&pcStack_1120,piVar19);
          if (iVar11 != 0) {
            (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar12);
            GOST_KEY_TRANSPORT_free(ppiVar15);
            uVar13 = 1;
            goto LAB_006195fc;
          }
          ERR_GOST_error(0x7a,0x66,"gost94_keyx.c",0x117);
        }
      }
    }
  }
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(iVar12);
  GOST_KEY_TRANSPORT_free(ppiVar15);
  uVar13 = 0xffffffff;
LAB_006195fc:
  if (iStack_10f4 != *(int *)puVar10) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return 0x40;
  }
  return uVar13;
}

