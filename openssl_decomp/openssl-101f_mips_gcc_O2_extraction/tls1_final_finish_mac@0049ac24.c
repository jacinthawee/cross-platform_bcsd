
/* WARNING: Could not reconcile some variable overlaps */

int tls1_final_finish_mac(int param_1,undefined4 param_2,int *param_3,byte *param_4)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  undefined4 uVar25;
  char cVar29;
  uint *puVar26;
  int iVar27;
  uint *puVar28;
  uint *puVar30;
  undefined uVar35;
  uint uVar31;
  uint *puVar32;
  int iVar33;
  int iVar34;
  int *piVar36;
  uint uVar37;
  int *piVar38;
  uint uVar39;
  uint uVar40;
  undefined4 *puVar41;
  undefined4 *puVar42;
  uint uVar43;
  uint in_t0;
  uint uVar44;
  uint in_t1;
  uint uVar45;
  uint in_t2;
  uint uVar46;
  uint in_t3;
  uint uVar47;
  uint uVar48;
  uint unaff_s0;
  char *pcVar49;
  int *unaff_s2;
  int *unaff_s3;
  int *unaff_s4;
  byte *unaff_s5;
  undefined *puVar50;
  int unaff_s7;
  undefined *unaff_s8;
  int iVar51;
  uint uStack_2a0;
  int iStack_29c;
  undefined4 uStack_298;
  int iStack_294;
  char *pcStack_260;
  int iStack_24c;
  int iStack_248;
  uint uStack_244;
  uint uStack_240;
  uint uStack_23c;
  uint uStack_238;
  uint uStack_234;
  uint uStack_230;
  uint uStack_22c;
  uint uStack_228;
  uint uStack_224;
  uint uStack_220;
  uint uStack_21c;
  uint uStack_218;
  uint uStack_214;
  undefined4 *puStack_210;
  int *piStack_20c;
  uint *puStack_208;
  undefined *puStack_204;
  uint uStack_200;
  undefined *puStack_1fc;
  int *piStack_1f8;
  uint uStack_1f4;
  int *piStack_1f0;
  code *pcStack_1ec;
  uint uStack_1d8;
  int iStack_1d4;
  int iStack_1d0;
  int iStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined *puStack_1c0;
  uint uStack_1b4;
  int iStack_1b0;
  undefined4 *puStack_1ac;
  int iStack_1a8;
  undefined auStack_1a4 [24];
  undefined auStack_18c [4];
  undefined auStack_188 [4];
  undefined4 uStack_184;
  undefined4 uStack_180;
  undefined uStack_17c;
  undefined uStack_17b;
  undefined uStack_17a;
  undefined uStack_179;
  undefined uStack_178;
  int iStack_174;
  uint uStack_170;
  int iStack_16c;
  int *piStack_168;
  int *piStack_164;
  int *piStack_160;
  byte *pbStack_15c;
  byte *pbStack_158;
  int iStack_154;
  undefined *puStack_150;
  code *pcStack_14c;
  int *local_138;
  undefined *local_134;
  int local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  byte *local_11c;
  undefined4 local_118;
  undefined *local_110;
  int local_108;
  undefined4 local_104;
  int *local_100;
  int local_fc;
  int **local_f8;
  undefined *local_f4;
  undefined *local_f0;
  int local_ec;
  int local_e4;
  uint local_e0;
  undefined4 local_dc;
  int local_d8;
  int local_d4;
  undefined auStack_d0 [24];
  byte local_b8;
  byte local_b7;
  byte local_b6;
  byte local_b5;
  byte local_b4;
  byte local_b3;
  byte local_b2;
  byte local_b1;
  byte local_b0;
  byte local_af;
  byte local_ae;
  byte local_ad;
  undefined auStack_ac [128];
  int *local_2c;
  
  local_f8 = (int **)PTR___stack_chk_guard_006aabf0;
  piStack_1f8 = *(int **)PTR___stack_chk_guard_006aabf0;
  local_110 = &_gp;
  local_104 = param_2;
  local_2c = piStack_1f8;
  if ((*(int *)(*(int *)(param_1 + 0x58) + 0x178) == 0) ||
     (piStack_1f0 = param_3, iVar21 = ssl3_digest_cached_records(), pbStack_158 = param_4,
     iVar21 != 0)) {
    local_f4 = auStack_d0;
    puVar50 = auStack_ac;
    local_f0 = puVar50;
    (**(code **)(local_110 + -0x7fc4))(local_f4);
    iVar21 = 0;
    local_fc = 0;
    local_108 = 0;
    while (iVar22 = ssl_get_handshake_digest(iVar21,&local_e0,&local_dc), iVar22 != 0) {
      uVar23 = ssl_get_algorithm2(param_1);
      if ((uVar23 & local_e0) == 0) {
        iVar21 = iVar21 + 1;
      }
      else {
        iVar22 = (**(code **)(local_110 + -0x6fb4))(local_dc);
        if (((*(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar21 * 4) == 0) ||
            (iVar22 < 0)) || (0x80 - local_108 < iVar22)) {
          iVar21 = iVar21 + 1;
          local_fc = 1;
        }
        else {
          iVar24 = (**(code **)(local_110 + -0x6cb4))(local_f4);
          if (((iVar24 == 0) ||
              (iVar24 = (**(code **)(local_110 + -0x7868))(local_f4,puVar50,&local_e4), iVar24 == 0)
              ) || (iVar24 = local_e4, local_e4 != iVar22)) {
            local_fc = 1;
            iVar24 = iVar22;
          }
          puVar50 = puVar50 + iVar24;
          iVar21 = iVar21 + 1;
          local_108 = (int)puVar50 - (int)local_f0;
        }
      }
    }
    unaff_s3 = &local_d4;
    unaff_s0 = ssl_get_algorithm2(param_1);
    unaff_s4 = &local_d8;
    iVar22 = 0;
    unaff_s2 = (int *)(*(int *)(param_1 + 0xc0) + 0x14);
    uVar23 = *(uint *)(*(int *)(param_1 + 0xc0) + 0x10);
    iVar21 = 0;
    while (local_ec = ssl_get_handshake_digest(iVar22,unaff_s4,unaff_s3), unaff_s8 = local_f0,
          local_ec != 0) {
      iVar22 = iVar22 + 1;
      if ((local_d8 << 10 & unaff_s0) != 0) {
        iVar21 = iVar21 + 1;
      }
    }
    if (iVar21 == 0) {
      trap(7);
    }
    unaff_s7 = (int)uVar23 / iVar21;
    *param_4 = 0;
    if (iVar21 == 1) {
      uVar23 = 0;
    }
    pbStack_158 = &local_b8;
    iVar21 = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    param_4[3] = 0;
    param_4[4] = 0;
    param_4[5] = 0;
    param_4[6] = 0;
    param_4[7] = 0;
    param_4[8] = 0;
    param_4[9] = 0;
    param_4[10] = 0;
    param_4[0xb] = 0;
    local_100 = (int *)((uVar23 & 1) + unaff_s7);
    piStack_1f8 = unaff_s4;
    piStack_1f0 = unaff_s3;
    iVar22 = ssl_get_handshake_digest(0);
    piVar36 = local_100;
    iStack_16c = local_ec;
    while (local_100 = piVar36, local_ec = iStack_16c, iVar22 != 0) {
      if ((local_d8 << 10 & unaff_s0) != 0) {
        if (local_d4 == 0) {
          piStack_1f0 = (int *)0x146;
          local_138 = (int *)0x114;
          piStack_1f8 = (int *)0x11c;
          (**(code **)(local_110 + -0x6eb0))(0x14,0x11c,0x146,&DAT_00647bcc);
        }
        else {
          local_118 = 0xc;
          local_120 = 0;
          local_124 = 0;
          local_128 = 0;
          local_12c = 0;
          local_134 = unaff_s8;
          piStack_1f8 = unaff_s2;
          local_138 = param_3;
          local_130 = local_108;
          local_11c = pbStack_158;
          iVar22 = tls1_P_hash_constprop_2();
          piStack_1f0 = piVar36;
          iStack_16c = local_ec;
          if (iVar22 != 0) {
            unaff_s2 = (int *)((int)unaff_s2 + unaff_s7);
            in_t3 = (uint)(param_4[3] ^ local_b5);
            in_t2 = (uint)(param_4[4] ^ local_b4);
            in_t1 = (uint)(param_4[5] ^ local_b3);
            *param_4 = *param_4 ^ local_b8;
            param_4[1] = param_4[1] ^ local_b7;
            param_4[9] = param_4[9] ^ local_af;
            param_4[2] = param_4[2] ^ local_b6;
            param_4[3] = param_4[3] ^ local_b5;
            param_4[4] = param_4[4] ^ local_b4;
            param_4[5] = param_4[5] ^ local_b3;
            param_4[6] = param_4[6] ^ local_b2;
            param_4[7] = param_4[7] ^ local_b1;
            param_4[8] = param_4[8] ^ local_b0;
            param_4[10] = param_4[10] ^ local_ae;
            param_4[0xb] = param_4[0xb] ^ local_ad;
            goto LAB_0049af98;
          }
        }
        (**(code **)(local_110 + -0x7fac))(local_f4);
        goto LAB_0049afd0;
      }
LAB_0049af98:
      iVar21 = iVar21 + 1;
      piStack_1f8 = unaff_s4;
      piStack_1f0 = unaff_s3;
      iVar22 = ssl_get_handshake_digest(iVar21);
      piVar36 = local_100;
      iStack_16c = local_ec;
    }
    (**(code **)(local_110 + -0x7fac))(local_f4);
    unaff_s5 = param_4;
    if (local_fc == 0) {
      iStack_16c = 0xc;
      goto LAB_0049afd0;
    }
  }
  iStack_16c = 0;
  param_4 = unaff_s5;
LAB_0049afd0:
  if (local_2c == *local_f8) {
    return iStack_16c;
  }
  pcStack_14c = tls1_mac;
  piStack_20c = local_2c;
  (**(code **)(local_110 + -0x5328))();
  puStack_1fc = PTR___stack_chk_guard_006aabf0;
  puStack_1c0 = &_gp;
  iStack_174 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar21 = piStack_20c[0x16];
  puStack_208 = (uint *)(iVar21 + 0x10c);
  if (piStack_1f0 == (int *)0x0) {
    puVar50 = (undefined *)piStack_20c[0x21];
    puStack_210 = (undefined4 *)(iVar21 + 8);
    uStack_200 = piStack_20c[0x1f] & 1;
  }
  else {
    puVar50 = (undefined *)piStack_20c[0x24];
    puStack_208 = (uint *)(iVar21 + 0x130);
    puStack_210 = (undefined4 *)(iVar21 + 0x54);
    uStack_200 = piStack_20c[0x1f] & 2;
  }
  uStack_170 = unaff_s0;
  piStack_168 = unaff_s2;
  piStack_164 = unaff_s3;
  piStack_160 = unaff_s4;
  pbStack_15c = param_4;
  iStack_154 = unaff_s7;
  puStack_150 = unaff_s8;
  uVar25 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(puVar50);
  iStack_1a8 = (**(code **)(puStack_1c0 + -0x6fb4))(uVar25);
  if (iStack_1a8 < 0) {
    uStack_1b4 = iStack_1a8;
    (**(code **)(puStack_1c0 + -0x7194))(&DAT_00647bcc,0x3d3,"t >= 0");
    iStack_1a8 = uStack_1b4;
  }
  puStack_204 = puVar50;
  if (uStack_200 == 0) {
    puStack_204 = auStack_1a4;
    (**(code **)(puStack_1c0 + -0x6e2c))(puStack_204,puVar50);
  }
  iVar21 = *piStack_20c;
  if ((iVar21 == 0xfeff) || (iVar21 == 0x100)) {
    if (piStack_1f0 == (int *)0x0) {
      uVar2 = *(undefined2 *)(piStack_20c[0x17] + 0x208);
      uVar35 = (undefined)((ushort)uVar2 >> 8);
    }
    else {
      uVar2 = *(undefined2 *)(piStack_20c[0x17] + 0x20a);
      uVar35 = (undefined)((ushort)uVar2 >> 8);
    }
    auStack_18c = (undefined  [4])CONCAT13(uVar35,CONCAT12((char)uVar2,SUB42(auStack_18c,0)));
    bVar1 = *(byte *)((int)puStack_210 + 6);
    in_t0 = (uint)bVar1;
    uVar31 = *(uint *)((int)puStack_210 + 2);
    cVar29 = *(char *)((int)puStack_210 + 7);
    puVar50 = auStack_18c + 2;
    uVar23 = (uint)puVar50 & 3;
    *(uint *)(puVar50 + -uVar23) =
         *(uint *)(puVar50 + -uVar23) & -1 << (4 - uVar23) * 8 | uVar31 >> uVar23 * 8;
    puVar50 = auStack_188 + 1;
    uVar23 = (uint)puVar50 & 3;
    *(uint *)(puVar50 + -uVar23) =
         *(uint *)(puVar50 + -uVar23) & 0xffffffffU >> (uVar23 + 1) * 8 | uVar31 << (3 - uVar23) * 8
    ;
    auStack_188 = (undefined  [4])CONCAT31(CONCAT21(auStack_188._0_2_,bVar1),cVar29);
    uStack_180 = auStack_188;
    uStack_184 = auStack_18c;
  }
  else {
    uStack_184 = *puStack_210;
    uStack_180 = puStack_210[1];
  }
  uStack_1b4 = puStack_208[1];
  uStack_1f4 = *puStack_208;
  iStack_1b0 = iStack_1a8;
  puVar41 = (undefined4 *)(uStack_1f4 & 0xff);
  *puStack_208 = (uint)puVar41;
  uStack_17c = (undefined)uStack_1f4;
  uStack_17b = (undefined)((uint)iVar21 >> 8);
  uStack_17a = (undefined)iVar21;
  uStack_179 = (undefined)(uStack_1b4 >> 8);
  uStack_178 = (undefined)uStack_1b4;
  puVar42 = &uStack_184;
  if (((piStack_1f0 == (int *)0x0) &&
      (puStack_1ac = &uStack_184, uVar23 = (**(code **)(puStack_1c0 + -0x6cb0))(piStack_20c[0x20]),
      puVar42 = puStack_1ac, (uVar23 & 0xf0007) == 2)) &&
     (iVar21 = ssl3_cbc_record_digest_supported(puStack_204,puStack_1ac), puVar42 = puStack_1ac,
     iVar21 != 0)) {
    uStack_1c4 = 0;
    iStack_1cc = piStack_20c[0x16] + 0x14;
    uStack_1c8 = *(undefined4 *)(piStack_20c[0x16] + 0x10);
    pcVar49 = (char *)&iStack_1a8;
    iStack_1d0 = uStack_1b4 + iStack_1b0 + (uStack_1f4 >> 8);
    iStack_1d4 = puStack_208[1] + iStack_1a8;
    uStack_1d8 = puStack_208[4];
    puVar41 = puStack_1ac;
    ssl3_cbc_digest_record(puStack_204,piStack_1f8);
  }
  else {
    (**(code **)(puStack_1c0 + -0x786c))(puStack_204,puVar42,0xd);
    (**(code **)(puStack_1c0 + -0x786c))(puStack_204,puStack_208[4],puStack_208[1]);
    pcVar49 = (char *)&iStack_1a8;
    iVar21 = (**(code **)(puStack_1c0 + -0x7914))(puStack_204,piStack_1f8);
    if (iVar21 < 1) {
      pcVar49 = "t > 0";
      (**(code **)(puStack_1c0 + -0x7194))(&DAT_00647bcc,0x40d);
    }
  }
  if (uStack_200 == 0) {
    (**(code **)(puStack_1c0 + -0x7fac))(auStack_1a4);
  }
  if (((*piStack_20c != 0xfeff) && (*piStack_20c != 0x100)) &&
     ((((cVar29 = *(char *)((int)puStack_210 + 7) + '\x01', *(char *)((int)puStack_210 + 7) = cVar29
        , cVar29 == '\0' &&
        ((cVar29 = *(char *)((int)puStack_210 + 6) + '\x01',
         *(char *)((int)puStack_210 + 6) = cVar29, cVar29 == '\0' &&
         (cVar29 = *(char *)((int)puStack_210 + 5) + '\x01',
         *(char *)((int)puStack_210 + 5) = cVar29, cVar29 == '\0')))) &&
       (cVar29 = *(char *)(puStack_210 + 1), *(char *)(puStack_210 + 1) = cVar29 + '\x01',
       (char)(cVar29 + '\x01') == '\0')) &&
      (((cVar29 = *(char *)((int)puStack_210 + 3) + '\x01', *(char *)((int)puStack_210 + 3) = cVar29
        , cVar29 == '\0' &&
        (cVar29 = *(char *)((int)puStack_210 + 2) + '\x01', *(char *)((int)puStack_210 + 2) = cVar29
        , cVar29 == '\0')) &&
       (cVar29 = *(char *)((int)puStack_210 + 1) + '\x01', *(char *)((int)puStack_210 + 1) = cVar29,
       cVar29 == '\0')))))) {
    *(char *)puStack_210 = *(char *)puStack_210 + '\x01';
  }
  if (iStack_174 == *(int *)puStack_1fc) {
    return iStack_1a8;
  }
  pcStack_1ec = tls1_generate_master_secret;
  iVar21 = iStack_174;
  (**(code **)(puStack_1c0 + -0x5328))();
  puVar50 = PTR___stack_chk_guard_006aabf0;
  uStack_214 = *(uint *)PTR___stack_chk_guard_006aabf0;
  puVar42 = puVar41;
  uVar23 = ssl_get_algorithm2();
  iVar51 = *(int *)(iVar21 + 0xc0);
  iVar24 = 0;
  iVar22 = *(int *)(iVar21 + 0x58) + 0xc0;
  puVar26 = (uint *)(iVar51 + 0x14);
  iVar21 = 0;
  while (iVar27 = ssl_get_handshake_digest(iVar24,&iStack_24c,&iStack_248), iVar27 != 0) {
    iVar24 = iVar24 + 1;
    if ((iStack_24c << 10 & uVar23) != 0) {
      iVar21 = iVar21 + 1;
    }
  }
  if (iVar21 == 0) {
    trap(7);
  }
  iVar24 = (int)puVar41 / iVar21;
  if (iVar21 == 1) {
    puVar41 = (undefined4 *)0x0;
  }
  (*(code *)PTR_memset_006aab00)(puVar26,0,0x30);
  iVar21 = 0;
  pcStack_260 = "master secret";
  piVar36 = &iStack_24c;
  piVar38 = &iStack_248;
  iVar27 = ssl_get_handshake_digest(0);
  do {
    if (iVar27 == 0) {
LAB_0049b79c:
      if (uStack_214 == *(uint *)puVar50) {
        return 0x30;
      }
      uVar23 = uStack_214;
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      puVar41 = puVar42;
      iVar21 = (*(code *)PTR_CRYPTO_malloc_006a8108)(piVar38,&DAT_00647bcc,0x471);
      if (iVar21 == 0) {
        iVar22 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
      }
      else {
        iVar22 = uStack_2a0 + 0x40;
        if (iStack_294 == 0) {
          iVar51 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar22,&DAT_00647bcc,0x47f);
          iVar24 = iVar22;
        }
        else {
          iVar24 = uStack_298 + 2 + iVar22;
          iVar51 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar24,&DAT_00647bcc,0x47f);
        }
        if (iVar51 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
          (*(code *)PTR_CRYPTO_free_006a7f88)(iVar21);
          return 0;
        }
        uVar39 = uStack_2a0;
        (*(code *)PTR_memcpy_006aabf4)(iVar51);
        puVar30 = (uint *)(iVar51 + uStack_2a0);
        iVar33 = *(int *)(uVar23 + 0x58);
        puVar26 = (uint *)(iVar51 + uStack_2a0 + 0x20);
        uVar48 = *(uint *)(iVar33 + 0xc0);
        uVar31 = iVar33 + 0xc4U & 3;
        uVar3 = iVar33 + 200U & 3;
        uVar4 = iVar33 + 0xccU & 3;
        uVar5 = iVar33 + 0xd0U & 3;
        uVar6 = iVar33 + 0xd4U & 3;
        uVar7 = iVar33 + 0xd8U & 3;
        iVar27 = *(int *)((iVar33 + 0xd8U) - uVar7);
        uVar8 = iVar33 + 0xdcU & 3;
        iVar9 = *(int *)((iVar33 + 0xdcU) - uVar8);
        uVar12 = iVar33 + 199U & 3;
        uVar47 = (*(int *)((iVar33 + 0xc4U) - uVar31) << uVar31 * 8 |
                 in_t3 & 0xffffffffU >> (4 - uVar31) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)((iVar33 + 199U) - uVar12) >> (3 - uVar12) * 8;
        uVar31 = iVar33 + 0xcbU & 3;
        uVar46 = (*(int *)((iVar33 + 200U) - uVar3) << uVar3 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar31 + 1) * 8 |
                 *(uint *)((iVar33 + 0xcbU) - uVar31) >> (3 - uVar31) * 8;
        uVar31 = iVar33 + 0xcfU & 3;
        uVar45 = (*(int *)((iVar33 + 0xccU) - uVar4) << uVar4 * 8 |
                 in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar31 + 1) * 8 |
                 *(uint *)((iVar33 + 0xcfU) - uVar31) >> (3 - uVar31) * 8;
        uVar31 = iVar33 + 0xd3U & 3;
        uVar44 = (*(int *)((iVar33 + 0xd0U) - uVar5) << uVar5 * 8 |
                 in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar31 + 1) * 8 |
                 *(uint *)((iVar33 + 0xd3U) - uVar31) >> (3 - uVar31) * 8;
        uVar31 = iVar33 + 0xd7U & 3;
        uVar43 = (*(int *)((iVar33 + 0xd4U) - uVar6) << uVar6 * 8 |
                 (uint)puVar41 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar31 + 1) * 8 |
                 *(uint *)((iVar33 + 0xd7U) - uVar31) >> (3 - uVar31) * 8;
        uVar31 = iVar33 + 0xdbU & 3;
        uVar4 = *(uint *)((iVar33 + 0xdbU) - uVar31);
        uVar3 = iVar33 + 0xdfU & 3;
        uVar5 = *(uint *)((iVar33 + 0xdfU) - uVar3);
        *puVar30 = uVar48;
        puVar30[1] = uVar47;
        puVar30[2] = uVar46;
        puVar30[3] = uVar45;
        puVar30[4] = uVar44;
        puVar30[5] = uVar43;
        puVar30[6] = (iVar27 << uVar7 * 8 | uVar39 & 0xffffffffU >> (4 - uVar7) * 8) &
                     -1 << (uVar31 + 1) * 8 | uVar4 >> (3 - uVar31) * 8;
        puVar30[7] = (iVar9 << uVar8 * 8 | (uint)puVar42 & 0xffffffffU >> (4 - uVar8) * 8) &
                     -1 << (uVar3 + 1) * 8 | uVar5 >> (3 - uVar3) * 8;
        iVar34 = *(int *)(uVar23 + 0x58);
        uVar31 = iVar34 + 0xa0U & 3;
        uVar3 = iVar34 + 0xa4U & 3;
        iVar27 = *(int *)((iVar34 + 0xa4U) - uVar3);
        uVar4 = iVar34 + 0xa8U & 3;
        iVar9 = *(int *)((iVar34 + 0xa8U) - uVar4);
        uVar5 = iVar34 + 0xacU & 3;
        iVar33 = *(int *)((iVar34 + 0xacU) - uVar5);
        uVar6 = iVar34 + 0xb0U & 3;
        iVar10 = *(int *)((iVar34 + 0xb0U) - uVar6);
        uVar7 = iVar34 + 0xb4U & 3;
        iVar11 = *(int *)((iVar34 + 0xb4U) - uVar7);
        uVar8 = iVar34 + 0xa3U & 3;
        uVar12 = iVar34 + 0xa7U & 3;
        uVar16 = *(uint *)((iVar34 + 0xa7U) - uVar12);
        uVar39 = iVar34 + 0xabU & 3;
        uVar17 = *(uint *)((iVar34 + 0xabU) - uVar39);
        uVar13 = iVar34 + 0xafU & 3;
        uVar18 = *(uint *)((iVar34 + 0xafU) - uVar13);
        uVar14 = iVar34 + 0xb3U & 3;
        uVar19 = *(uint *)((iVar34 + 0xb3U) - uVar14);
        uVar15 = iVar34 + 0xb7U & 3;
        uVar20 = *(uint *)((iVar34 + 0xb7U) - uVar15);
        uVar40 = *(uint *)(iVar34 + 0xb8);
        uVar37 = *(uint *)(iVar34 + 0xbc);
        *puVar26 = (*(int *)((iVar34 + 0xa0U) - uVar31) << uVar31 * 8 |
                   uVar48 & 0xffffffffU >> (4 - uVar31) * 8) & -1 << (uVar8 + 1) * 8 |
                   *(uint *)((iVar34 + 0xa3U) - uVar8) >> (3 - uVar8) * 8;
        puVar26[1] = (iVar27 << uVar3 * 8 | uVar47 & 0xffffffffU >> (4 - uVar3) * 8) &
                     -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
        puVar26[2] = (iVar9 << uVar4 * 8 | uVar46 & 0xffffffffU >> (4 - uVar4) * 8) &
                     -1 << (uVar39 + 1) * 8 | uVar17 >> (3 - uVar39) * 8;
        puVar26[3] = (iVar33 << uVar5 * 8 | uVar45 & 0xffffffffU >> (4 - uVar5) * 8) &
                     -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
        puVar26[4] = (iVar10 << uVar6 * 8 | uVar44 & 0xffffffffU >> (4 - uVar6) * 8) &
                     -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
        puVar26[5] = (iVar11 << uVar7 * 8 | uVar43 & 0xffffffffU >> (4 - uVar7) * 8) &
                     -1 << (uVar15 + 1) * 8 | uVar20 >> (3 - uVar15) * 8;
        puVar26[6] = uVar40;
        puVar26[7] = uVar37;
        if (iStack_294 != 0) {
          *(char *)(iVar51 + iVar22) = (char)((uint)uStack_298 >> 8);
          *(undefined *)((int)puVar30 + 0x41) = (undefined)uStack_298;
          if ((uStack_298 != 0) || (iStack_29c != 0)) {
            (*(code *)PTR_memcpy_006aabf4)(iVar51 + uStack_2a0 + 0x42,iStack_29c,uStack_298);
          }
        }
        iVar22 = (*(code *)PTR_memcmp_006aabd8)(iVar51,"client finished",0xf);
        if (((iVar22 == 0) ||
            (iVar22 = (*(code *)PTR_memcmp_006aabd8)(iVar51,"server finished",0xf), iVar22 == 0)) ||
           ((iVar22 = (*(code *)PTR_memcmp_006aabd8)(iVar51,"master secret",0xd), iVar22 == 0 ||
            (iVar22 = (*(code *)PTR_memcmp_006aabd8)(iVar51,"key expansion",0xd), iVar22 == 0)))) {
          iVar22 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x16f,&DAT_00647bcc,0x4b1);
        }
        else {
          iVar22 = tls1_PRF_constprop_1
                             (*(undefined4 *)(*(int *)(*(int *)(uVar23 + 0x58) + 0x344) + 0x24),
                              iVar51,iVar24,0,0,0,0,0,0,*(int *)(uVar23 + 0xc0) + 0x14,
                              *(undefined4 *)(*(int *)(uVar23 + 0xc0) + 0x10),piVar36,iVar21,piVar38
                             );
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar21);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar51);
      }
      return iVar22;
    }
    if ((iStack_24c << 10 & uVar23) != 0) {
      if (iStack_248 == 0) {
        piVar38 = (int *)0x146;
        puVar42 = (undefined4 *)&DAT_00647bcc;
        uStack_2a0 = 0x114;
        piVar36 = (int *)0x11c;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14);
        goto LAB_0049b79c;
      }
      uStack_298 = 0x20;
      iStack_294 = 0;
      uStack_2a0 = 0xd;
      piVar36 = (int *)pcVar49;
      piVar38 = (int *)(((uint)puVar41 & 1) + iVar24);
      puVar42 = (undefined4 *)pcStack_260;
      iVar27 = tls1_P_hash_constprop_2();
      iStack_29c = iVar22;
      if (iVar27 == 0) goto LAB_0049b79c;
      pcVar49 = (char *)((int)pcVar49 + iVar24);
      puVar30 = &uStack_244;
      puVar32 = puVar26;
      if (((uint)puVar26 & 3) == 0 &&
          ((uint *)(iVar51 + 0x18) <= &uStack_244 || &uStack_240 <= puVar26)) {
        *(uint *)(iVar51 + 0x14) = *(uint *)(iVar51 + 0x14) ^ uStack_244;
        *(uint *)(iVar51 + 0x18) = uStack_240 ^ *(uint *)(iVar51 + 0x18);
        puVar42 = (undefined4 *)(uStack_22c ^ *(uint *)(iVar51 + 0x2c));
        in_t3 = uStack_230 ^ *(uint *)(iVar51 + 0x28);
        *(uint *)(iVar51 + 0x1c) = uStack_23c ^ *(uint *)(iVar51 + 0x1c);
        *(uint *)(iVar51 + 0x20) = uStack_238 ^ *(uint *)(iVar51 + 0x20);
        *(uint *)(iVar51 + 0x24) = uStack_234 ^ *(uint *)(iVar51 + 0x24);
        *(uint *)(iVar51 + 0x28) = in_t3;
        *(undefined4 **)(iVar51 + 0x2c) = puVar42;
        *(uint *)(iVar51 + 0x30) = uStack_228 ^ *(uint *)(iVar51 + 0x30);
        *(uint *)(iVar51 + 0x38) = uStack_220 ^ *(uint *)(iVar51 + 0x38);
        *(uint *)(iVar51 + 0x34) = uStack_224 ^ *(uint *)(iVar51 + 0x34);
        *(uint *)(iVar51 + 0x3c) = uStack_21c ^ *(uint *)(iVar51 + 0x3c);
        *(uint *)(iVar51 + 0x40) = *(uint *)(iVar51 + 0x40) ^ uStack_218;
      }
      else {
        do {
          puVar28 = (uint *)((int)puVar30 + 1);
          *(byte *)puVar32 = *(byte *)puVar32 ^ *(byte *)puVar30;
          puVar30 = puVar28;
          puVar32 = (uint *)((int)puVar32 + 1);
        } while (puVar28 != &uStack_214);
      }
    }
    iVar21 = iVar21 + 1;
    piVar36 = &iStack_24c;
    piVar38 = &iStack_248;
    iVar27 = ssl_get_handshake_digest(iVar21);
  } while( true );
}

