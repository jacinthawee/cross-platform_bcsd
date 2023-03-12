
/* WARNING: Could not reconcile some variable overlaps */

byte * tls1_final_finish_mac(uint param_1,int **param_2,int **param_3,int **param_4)

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
  byte bVar21;
  byte bVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  int **ppiVar26;
  undefined4 uVar27;
  char cVar32;
  uint *puVar28;
  int iVar29;
  uint *puVar30;
  undefined4 uVar31;
  uint *puVar33;
  undefined uVar38;
  uint uVar34;
  uint *puVar35;
  int iVar36;
  int iVar37;
  uint uVar39;
  char *pcVar40;
  int *piVar41;
  uint uVar42;
  uint uVar43;
  int **ppiVar44;
  uint uVar45;
  uint in_t0;
  uint uVar46;
  uint in_t1;
  uint uVar47;
  uint in_t2;
  uint uVar48;
  uint in_t3;
  uint uVar49;
  uint uVar50;
  int unaff_s2;
  int **unaff_s3;
  int *unaff_s4;
  undefined *puVar51;
  int iVar52;
  byte *unaff_s5;
  byte *pbVar53;
  byte *unaff_s7;
  int **unaff_s8;
  int iVar54;
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
  int **ppiStack_210;
  int *piStack_20c;
  byte **ppbStack_208;
  uint uStack_204;
  undefined *puStack_200;
  undefined *puStack_1fc;
  int *piStack_1f8;
  byte *pbStack_1f4;
  int **ppiStack_1f0;
  code *pcStack_1ec;
  byte *pbStack_1d8;
  byte *pbStack_1d4;
  byte *pbStack_1d0;
  int iStack_1cc;
  undefined4 uStack_1c8;
  undefined4 uStack_1c4;
  undefined *puStack_1c0;
  int *piStack_1b4;
  int *piStack_1b0;
  int **ppiStack_1ac;
  int *piStack_1a8;
  undefined auStack_1a4 [24];
  undefined auStack_18c [4];
  undefined auStack_188 [4];
  int *piStack_184;
  int *piStack_180;
  undefined uStack_17c;
  undefined uStack_17b;
  undefined uStack_17a;
  undefined uStack_179;
  undefined uStack_178;
  int iStack_174;
  byte *pbStack_170;
  uint uStack_16c;
  int iStack_168;
  int **ppiStack_164;
  int *piStack_160;
  byte *pbStack_15c;
  int **ppiStack_158;
  byte *pbStack_154;
  int **ppiStack_150;
  code *pcStack_14c;
  int **local_138;
  byte *local_134;
  int local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  byte *local_11c;
  undefined4 local_118;
  undefined *local_110;
  int local_108;
  byte *local_104;
  int **local_100;
  int local_fc;
  int local_f8;
  int **local_f4;
  undefined *local_f0;
  byte *local_ec;
  int **local_e4;
  uint local_e0;
  undefined4 local_dc;
  int local_d8;
  int *local_d4;
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
  byte abStack_ac [128];
  int *local_2c;
  
  local_f4 = (int **)PTR___stack_chk_guard_006a9ae8;
  piStack_1f8 = *(int **)PTR___stack_chk_guard_006a9ae8;
  local_110 = &_gp;
  ppiVar44 = param_4;
  local_100 = param_2;
  local_2c = piStack_1f8;
  ppiStack_158 = param_4;
  if ((*(int *)(*(int *)(param_1 + 0x58) + 0x178) == 0) ||
     (ppiStack_1f0 = param_3, iVar23 = ssl3_digest_cached_records(), uStack_16c = param_1,
     ppiStack_150 = unaff_s8, iVar23 != 0)) {
    local_f0 = auStack_d0;
    pbVar53 = abStack_ac;
    local_104 = pbVar53;
    (**(code **)(local_110 + -0x7fc4))(local_f0);
    iVar23 = 0;
    local_f8 = 0;
    local_108 = 0;
    while (iVar24 = ssl_get_handshake_digest(iVar23,&local_e0,&local_dc), iVar24 != 0) {
      uVar25 = ssl_get_algorithm2(param_1);
      if ((uVar25 & local_e0) == 0) {
        iVar23 = iVar23 + 1;
      }
      else {
        ppiVar26 = (int **)(**(code **)(local_110 + -0x6fa4))(local_dc);
        if (((*(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + iVar23 * 4) == 0) ||
            ((int)ppiVar26 < 0)) || (0x80 - local_108 < (int)ppiVar26)) {
          iVar23 = iVar23 + 1;
          local_f8 = 1;
        }
        else {
          iVar24 = (**(code **)(local_110 + -0x6cdc))(local_f0);
          if (((iVar24 == 0) ||
              (iVar24 = (**(code **)(local_110 + -0x785c))(local_f0,pbVar53,&local_e4), iVar24 == 0)
              ) || (ppiVar44 = local_e4, local_e4 != ppiVar26)) {
            local_f8 = 1;
            ppiVar44 = ppiVar26;
          }
          pbVar53 = pbVar53 + (int)ppiVar44;
          iVar23 = iVar23 + 1;
          local_108 = (int)pbVar53 - (int)local_104;
        }
      }
    }
    unaff_s3 = &local_d4;
    uStack_16c = ssl_get_algorithm2(param_1);
    unaff_s4 = &local_d8;
    unaff_s7 = (byte *)0x0;
    unaff_s2 = *(int *)(param_1 + 0xc0) + 0x14;
    ppiStack_150 = *(int ***)(*(int *)(param_1 + 0xc0) + 0x10);
    iVar23 = 0;
    while (pbStack_170 = (byte *)ssl_get_handshake_digest(unaff_s7,unaff_s4,unaff_s3),
          pbStack_170 != (byte *)0x0) {
      unaff_s7 = unaff_s7 + 1;
      if ((local_d8 << 10 & uStack_16c) != 0) {
        iVar23 = iVar23 + 1;
      }
    }
    if (iVar23 == 0) {
      ppiStack_1f0 = (int **)0x44;
      ppiVar26 = (int **)&DAT_0064760c;
      local_138 = (int **)0x10a;
      (**(code **)(local_110 + -0x6eac))(0x14,0x11c);
LAB_0049748c:
      unaff_s5 = &local_b8;
      (**(code **)(local_110 + -0x7fac))(local_f0);
      (**(code **)(local_110 + -0x7d6c))(local_104,local_108);
      piStack_1f8 = (int *)&SUB_0000000c;
      (**(code **)(local_110 + -0x7d6c))(unaff_s5);
    }
    else {
      if (iVar23 == 0) {
        trap(7);
      }
      local_fc = (int)ppiStack_150 / iVar23;
      *(byte *)param_4 = 0;
      if (iVar23 == 1) {
        ppiStack_150 = (int **)0x0;
      }
      unaff_s7 = (byte *)0x0;
      *(byte *)((int)param_4 + 1) = 0;
      *(byte *)((int)param_4 + 2) = 0;
      *(byte *)((int)param_4 + 3) = 0;
      *(byte *)(param_4 + 1) = 0;
      unaff_s5 = &local_b8;
      *(byte *)((int)param_4 + 5) = 0;
      *(byte *)((int)param_4 + 6) = 0;
      *(byte *)((int)param_4 + 7) = 0;
      *(byte *)(param_4 + 2) = 0;
      *(byte *)((int)param_4 + 9) = 0;
      *(byte *)((int)param_4 + 10) = 0;
      *(byte *)((int)param_4 + 0xb) = 0;
      ppiStack_158 = (int **)(((uint)ppiStack_150 & 1) + local_fc);
      ppiStack_1f0 = unaff_s3;
      local_ec = pbStack_170;
      iVar23 = ssl_get_handshake_digest(0,unaff_s4);
      ppiVar26 = local_100;
      pbStack_170 = local_ec;
      while (ppiStack_150 = param_3, local_100 = ppiVar26, local_ec = pbStack_170, iVar23 != 0) {
        if ((local_d8 << 10 & uStack_16c) != 0) {
          if (local_d4 == (int *)0x0) {
            ppiStack_1f0 = (int **)0x146;
            ppiVar26 = (int **)&DAT_0064760c;
            local_138 = (int **)0x115;
            (**(code **)(local_110 + -0x6eac))(0x14,0x11c);
            goto LAB_0049748c;
          }
          local_120 = 0;
          local_118 = 0xc;
          local_124 = 0;
          local_128 = 0;
          local_12c = 0;
          ppiStack_1f0 = ppiStack_158;
          local_138 = param_3;
          local_134 = local_104;
          local_130 = local_108;
          local_11c = unaff_s5;
          iVar23 = tls1_P_hash_constprop_2(local_d4,unaff_s2);
          pbStack_170 = local_ec;
          if (iVar23 == 0) goto LAB_0049748c;
          unaff_s2 = unaff_s2 + local_fc;
          bVar1 = *(byte *)((int)param_4 + 3) ^ local_b5;
          in_t3 = (uint)bVar1;
          bVar21 = *(byte *)((int)param_4 + 6) ^ local_b2;
          ppiVar44 = (int **)(uint)bVar21;
          in_t2 = (uint)(*(byte *)(param_4 + 1) ^ local_b4);
          bVar22 = *(byte *)((int)param_4 + 5) ^ local_b3;
          in_t1 = (uint)bVar22;
          *(byte *)param_4 = *(byte *)param_4 ^ local_b8;
          *(byte *)((int)param_4 + 1) = *(byte *)((int)param_4 + 1) ^ local_b7;
          *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) ^ local_b6;
          *(byte *)((int)param_4 + 3) = bVar1;
          *(byte *)(param_4 + 1) = *(byte *)(param_4 + 1) ^ local_b4;
          *(byte *)((int)param_4 + 5) = bVar22;
          *(byte *)((int)param_4 + 6) = bVar21;
          *(byte *)((int)param_4 + 7) = *(byte *)((int)param_4 + 7) ^ local_b1;
          *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) ^ local_b0;
          *(byte *)((int)param_4 + 9) = *(byte *)((int)param_4 + 9) ^ local_af;
          *(byte *)((int)param_4 + 10) = *(byte *)((int)param_4 + 10) ^ local_ae;
          *(byte *)((int)param_4 + 0xb) = *(byte *)((int)param_4 + 0xb) ^ local_ad;
        }
        unaff_s7 = unaff_s7 + 1;
        ppiStack_1f0 = unaff_s3;
        iVar23 = ssl_get_handshake_digest(unaff_s7,unaff_s4);
        ppiVar26 = local_100;
        pbStack_170 = local_ec;
      }
      (**(code **)(local_110 + -0x7fac))(local_f0);
      (**(code **)(local_110 + -0x7d6c))(local_104,local_108);
      piStack_1f8 = (int *)&SUB_0000000c;
      (**(code **)(local_110 + -0x7d6c))(unaff_s5);
      if (local_f8 != 0) goto LAB_00497418;
      pbStack_170 = &SUB_0000000c;
      ppiVar26 = ppiVar44;
    }
  }
  else {
LAB_00497418:
    pbStack_170 = (byte *)0x0;
    ppiVar26 = ppiVar44;
  }
  if (local_2c == *local_f4) {
    return pbStack_170;
  }
  pcStack_14c = tls1_mac;
  piStack_20c = local_2c;
  (**(code **)(local_110 + -0x5330))();
  puStack_1fc = PTR___stack_chk_guard_006a9ae8;
  puStack_1c0 = &_gp;
  iStack_174 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar23 = piStack_20c[0x16];
  ppbStack_208 = (byte **)(iVar23 + 0x10c);
  if (ppiStack_1f0 == (int **)0x0) {
    puVar51 = (undefined *)piStack_20c[0x21];
    ppiStack_210 = (int **)(iVar23 + 8);
    uStack_204 = piStack_20c[0x1f] & 1;
  }
  else {
    puVar51 = (undefined *)piStack_20c[0x24];
    ppbStack_208 = (byte **)(iVar23 + 0x130);
    ppiStack_210 = (int **)(iVar23 + 0x54);
    uStack_204 = piStack_20c[0x1f] & 2;
  }
  pcVar40 = (char *)ppiStack_1f0;
  iStack_168 = unaff_s2;
  ppiStack_164 = unaff_s3;
  piStack_160 = unaff_s4;
  pbStack_15c = unaff_s5;
  pbStack_154 = unaff_s7;
  uVar27 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(puVar51);
  piStack_1a8 = (int *)(**(code **)(puStack_1c0 + -0x6fa4))(uVar27);
  if ((int)piStack_1a8 < 0) {
    pcVar40 = "t >= 0";
    piStack_1b4 = piStack_1a8;
    (**(code **)(puStack_1c0 + -0x7184))(&DAT_0064760c,0x3f4);
    piStack_1a8 = piStack_1b4;
  }
  puStack_200 = puVar51;
  if (uStack_204 == 0) {
    puStack_200 = auStack_1a4;
    iVar23 = (**(code **)(puStack_1c0 + -0x6be0))(puStack_200,puVar51);
    if (iVar23 == 0) {
      piVar41 = (int *)0xffffffff;
      goto LAB_0049788c;
    }
  }
  iVar23 = *piStack_20c;
  if ((iVar23 == 0xfeff) || (iVar23 == 0x100)) {
    if (ppiStack_1f0 == (int **)0x0) {
      uVar2 = *(undefined2 *)(piStack_20c[0x17] + 0x208);
      uVar38 = (undefined)((ushort)uVar2 >> 8);
    }
    else {
      uVar2 = *(undefined2 *)(piStack_20c[0x17] + 0x20a);
      uVar38 = (undefined)((ushort)uVar2 >> 8);
    }
    auStack_18c = (undefined  [4])CONCAT13(uVar38,CONCAT12((char)uVar2,SUB42(auStack_18c,0)));
    bVar1 = *(byte *)((int)ppiStack_210 + 6);
    in_t0 = (uint)bVar1;
    uVar34 = *(uint *)((int)ppiStack_210 + 2);
    cVar32 = *(char *)((int)ppiStack_210 + 7);
    puVar51 = auStack_18c + 2;
    uVar25 = (uint)puVar51 & 3;
    *(uint *)(puVar51 + -uVar25) =
         *(uint *)(puVar51 + -uVar25) & -1 << (4 - uVar25) * 8 | uVar34 >> uVar25 * 8;
    puVar51 = auStack_188 + 1;
    uVar25 = (uint)puVar51 & 3;
    *(uint *)(puVar51 + -uVar25) =
         *(uint *)(puVar51 + -uVar25) & 0xffffffffU >> (uVar25 + 1) * 8 | uVar34 << (3 - uVar25) * 8
    ;
    auStack_188 = (undefined  [4])CONCAT31(CONCAT21(auStack_188._0_2_,bVar1),cVar32);
    piStack_180 = (int *)auStack_188;
    piStack_184 = (int *)auStack_18c;
  }
  else {
    piStack_184 = *ppiStack_210;
    piStack_180 = ppiStack_210[1];
  }
  piStack_1b4 = (int *)ppbStack_208[1];
  unaff_s7 = *ppbStack_208;
  piStack_1b0 = piStack_1a8;
  ppiVar26 = (int **)((uint)unaff_s7 & 0xff);
  *ppbStack_208 = (byte *)ppiVar26;
  uStack_17c = SUB41(unaff_s7,0);
  uStack_17b = (undefined)((uint)iVar23 >> 8);
  uStack_17a = (undefined)iVar23;
  uStack_179 = (undefined)((uint)piStack_1b4 >> 8);
  uStack_178 = SUB41(piStack_1b4,0);
  if (((ppiStack_1f0 == (int **)0x0) &&
      (ppiStack_1ac = &piStack_184, uVar25 = (**(code **)(puStack_1c0 + -0x6cd8))(piStack_20c[0x20])
      , (uVar25 & 0xf0007) == 2)) &&
     (iVar23 = ssl3_cbc_record_digest_supported(puStack_200,ppiStack_1ac), iVar23 != 0)) {
    in_t0 = (uint)unaff_s7 >> 8;
    uStack_1c4 = 0;
    iStack_1cc = piStack_20c[0x16] + 0x14;
    uStack_1c8 = *(undefined4 *)(piStack_20c[0x16] + 0x10);
    unaff_s7 = (byte *)((int)piStack_1b4 + (int)piStack_1b0) + in_t0;
    pcVar40 = (char *)&piStack_1a8;
    pbStack_1d4 = ppbStack_208[1] + (int)piStack_1a8;
    pbStack_1d8 = ppbStack_208[4];
    ppiVar26 = ppiStack_1ac;
    pbStack_1d0 = unaff_s7;
    iVar23 = ssl3_cbc_digest_record(puStack_200,piStack_1f8);
joined_r0x004976bc:
    if (0 < iVar23) {
      if (uStack_204 == 0) {
        (**(code **)(puStack_1c0 + -0x7fac))(auStack_1a4);
      }
      piVar41 = piStack_1a8;
      if (((*piStack_20c != 0xfeff) && (*piStack_20c != 0x100)) &&
         ((((cVar32 = *(char *)((int)ppiStack_210 + 7) + '\x01',
            *(char *)((int)ppiStack_210 + 7) = cVar32, cVar32 == '\0' &&
            ((cVar32 = *(char *)((int)ppiStack_210 + 6) + '\x01',
             *(char *)((int)ppiStack_210 + 6) = cVar32, cVar32 == '\0' &&
             (cVar32 = *(char *)((int)ppiStack_210 + 5) + '\x01',
             *(char *)((int)ppiStack_210 + 5) = cVar32, cVar32 == '\0')))) &&
           (cVar32 = *(char *)(ppiStack_210 + 1), *(char *)(ppiStack_210 + 1) = cVar32 + '\x01',
           (char)(cVar32 + '\x01') == '\0')) &&
          (((cVar32 = *(char *)((int)ppiStack_210 + 3) + '\x01',
            *(char *)((int)ppiStack_210 + 3) = cVar32, cVar32 == '\0' &&
            (cVar32 = *(char *)((int)ppiStack_210 + 2) + '\x01',
            *(char *)((int)ppiStack_210 + 2) = cVar32, cVar32 == '\0')) &&
           (cVar32 = *(char *)((int)ppiStack_210 + 1) + '\x01',
           *(char *)((int)ppiStack_210 + 1) = cVar32, cVar32 == '\0')))))) {
        *(char *)ppiStack_210 = *(char *)ppiStack_210 + '\x01';
      }
      goto LAB_0049788c;
    }
  }
  else {
    pcVar40 = &DAT_0000000d;
    iVar23 = (**(code **)(puStack_1c0 + -0x7860))(puStack_200);
    if (0 < iVar23) {
      pcVar40 = (char *)ppbStack_208[1];
      iVar23 = (**(code **)(puStack_1c0 + -0x7860))(puStack_200,ppbStack_208[4]);
      if (0 < iVar23) {
        pcVar40 = (char *)&piStack_1a8;
        iVar23 = (**(code **)(puStack_1c0 + -0x7910))(puStack_200,piStack_1f8);
        goto joined_r0x004976bc;
      }
    }
  }
  if (uStack_204 == 0) {
    (**(code **)(puStack_1c0 + -0x7fac))(auStack_1a4);
  }
  piVar41 = (int *)0xffffffff;
LAB_0049788c:
  if (iStack_174 == *(int *)puStack_1fc) {
    return (byte *)piVar41;
  }
  pcStack_1ec = tls1_generate_master_secret;
  iVar23 = iStack_174;
  (**(code **)(puStack_1c0 + -0x5330))();
  puVar51 = PTR___stack_chk_guard_006a9ae8;
  uStack_214 = *(uint *)PTR___stack_chk_guard_006a9ae8;
  ppiVar44 = ppiVar26;
  pbStack_1f4 = unaff_s7;
  uVar25 = ssl_get_algorithm2();
  iVar54 = *(int *)(iVar23 + 0xc0);
  iVar52 = 0;
  iVar24 = *(int *)(iVar23 + 0x58) + 0xc0;
  puVar28 = (uint *)(iVar54 + 0x14);
  iVar23 = 0;
  while (iVar29 = ssl_get_handshake_digest(iVar52,&iStack_24c,&iStack_248), iVar29 != 0) {
    iVar52 = iVar52 + 1;
    if ((iStack_24c << 10 & uVar25) != 0) {
      iVar23 = iVar23 + 1;
    }
  }
  if (iVar23 == 0) {
    piVar41 = (int *)0x44;
    ppiVar44 = (int **)&DAT_0064760c;
    uStack_2a0 = 0x10a;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11c);
  }
  else {
    if (iVar23 == 0) {
      trap(7);
    }
    iVar52 = (int)ppiVar26 / iVar23;
    if (iVar23 == 1) {
      ppiVar26 = (int **)0x0;
    }
    (*(code *)PTR_memset_006a99f4)(puVar28,0,0x30);
    iVar23 = 0;
    pcStack_260 = "master secret";
    piVar41 = &iStack_248;
    iVar29 = ssl_get_handshake_digest(0,&iStack_24c);
    while (iVar29 != 0) {
      if ((iStack_24c << 10 & uVar25) != 0) {
        if (iStack_248 == 0) {
          piVar41 = (int *)0x146;
          ppiVar44 = (int **)&DAT_0064760c;
          uStack_2a0 = 0x115;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11c);
          break;
        }
        uStack_298 = 0x20;
        iStack_294 = 0;
        uStack_2a0 = 0xd;
        piVar41 = (int *)(((uint)ppiVar26 & 1) + iVar52);
        ppiVar44 = (int **)pcStack_260;
        iVar29 = tls1_P_hash_constprop_2(iStack_248,pcVar40);
        iStack_29c = iVar24;
        if (iVar29 == 0) break;
        pcVar40 = (char *)((int)pcVar40 + iVar52);
        puVar33 = &uStack_244;
        puVar35 = puVar28;
        if (((uint)puVar28 & 3) == 0 &&
            ((uint *)(iVar54 + 0x18) <= &uStack_244 || &uStack_240 <= puVar28)) {
          *(uint *)(iVar54 + 0x14) = *(uint *)(iVar54 + 0x14) ^ uStack_244;
          *(uint *)(iVar54 + 0x18) = uStack_240 ^ *(uint *)(iVar54 + 0x18);
          ppiVar44 = (int **)(uStack_22c ^ *(uint *)(iVar54 + 0x2c));
          in_t3 = uStack_230 ^ *(uint *)(iVar54 + 0x28);
          *(uint *)(iVar54 + 0x1c) = uStack_23c ^ *(uint *)(iVar54 + 0x1c);
          *(uint *)(iVar54 + 0x20) = uStack_238 ^ *(uint *)(iVar54 + 0x20);
          *(uint *)(iVar54 + 0x24) = uStack_234 ^ *(uint *)(iVar54 + 0x24);
          *(uint *)(iVar54 + 0x28) = in_t3;
          *(int ***)(iVar54 + 0x2c) = ppiVar44;
          *(uint *)(iVar54 + 0x30) = uStack_228 ^ *(uint *)(iVar54 + 0x30);
          *(uint *)(iVar54 + 0x38) = uStack_220 ^ *(uint *)(iVar54 + 0x38);
          *(uint *)(iVar54 + 0x34) = uStack_224 ^ *(uint *)(iVar54 + 0x34);
          *(uint *)(iVar54 + 0x3c) = uStack_21c ^ *(uint *)(iVar54 + 0x3c);
          *(uint *)(iVar54 + 0x40) = *(uint *)(iVar54 + 0x40) ^ uStack_218;
        }
        else {
          do {
            puVar30 = (uint *)((int)puVar33 + 1);
            *(byte *)puVar35 = *(byte *)puVar35 ^ *(byte *)puVar33;
            puVar33 = puVar30;
            puVar35 = (uint *)((int)puVar35 + 1);
          } while (puVar30 != &uStack_214);
        }
      }
      iVar23 = iVar23 + 1;
      piVar41 = &iStack_248;
      iVar29 = ssl_get_handshake_digest(iVar23,&iStack_24c);
    }
  }
  uVar27 = 0x30;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(&uStack_244);
  if (uStack_214 == *(uint *)puVar51) {
    return &DAT_00000030;
  }
  uVar25 = uStack_214;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppiVar26 = ppiVar44;
  iVar23 = (*(code *)PTR_CRYPTO_malloc_006a7008)(piVar41,&DAT_0064760c,0x4a2);
  if (iVar23 == 0) {
    pbVar53 = (byte *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
  }
  else {
    iVar24 = uStack_2a0 + 0x40;
    if (iStack_294 == 0) {
      iVar54 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar24,&DAT_0064760c,0x4b0);
      iVar52 = iVar24;
    }
    else {
      iVar52 = uStack_298 + 2 + iVar24;
      iVar54 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar52,&DAT_0064760c,0x4b0);
    }
    if (iVar54 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar23);
      return (byte *)0x0;
    }
    uVar42 = uStack_2a0;
    (*(code *)PTR_memcpy_006a9aec)(iVar54);
    puVar33 = (uint *)(iVar54 + uStack_2a0);
    iVar36 = *(int *)(uVar25 + 0x58);
    puVar28 = (uint *)(iVar54 + uStack_2a0 + 0x20);
    uVar50 = *(uint *)(iVar36 + 0xc0);
    uVar34 = iVar36 + 0xc4U & 3;
    uVar3 = iVar36 + 200U & 3;
    uVar4 = iVar36 + 0xccU & 3;
    uVar5 = iVar36 + 0xd0U & 3;
    uVar6 = iVar36 + 0xd4U & 3;
    uVar7 = iVar36 + 0xd8U & 3;
    iVar29 = *(int *)((iVar36 + 0xd8U) - uVar7);
    uVar8 = iVar36 + 0xdcU & 3;
    iVar9 = *(int *)((iVar36 + 0xdcU) - uVar8);
    uVar12 = iVar36 + 199U & 3;
    uVar49 = (*(int *)((iVar36 + 0xc4U) - uVar34) << uVar34 * 8 |
             in_t3 & 0xffffffffU >> (4 - uVar34) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)((iVar36 + 199U) - uVar12) >> (3 - uVar12) * 8;
    uVar34 = iVar36 + 0xcbU & 3;
    uVar48 = (*(int *)((iVar36 + 200U) - uVar3) << uVar3 * 8 |
             in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar34 + 1) * 8 |
             *(uint *)((iVar36 + 0xcbU) - uVar34) >> (3 - uVar34) * 8;
    uVar34 = iVar36 + 0xcfU & 3;
    uVar47 = (*(int *)((iVar36 + 0xccU) - uVar4) << uVar4 * 8 |
             in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar34 + 1) * 8 |
             *(uint *)((iVar36 + 0xcfU) - uVar34) >> (3 - uVar34) * 8;
    uVar34 = iVar36 + 0xd3U & 3;
    uVar46 = (*(int *)((iVar36 + 0xd0U) - uVar5) << uVar5 * 8 |
             in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar34 + 1) * 8 |
             *(uint *)((iVar36 + 0xd3U) - uVar34) >> (3 - uVar34) * 8;
    uVar34 = iVar36 + 0xd7U & 3;
    uVar45 = (*(int *)((iVar36 + 0xd4U) - uVar6) << uVar6 * 8 |
             (uint)ppiVar26 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar34 + 1) * 8 |
             *(uint *)((iVar36 + 0xd7U) - uVar34) >> (3 - uVar34) * 8;
    uVar34 = iVar36 + 0xdbU & 3;
    uVar4 = *(uint *)((iVar36 + 0xdbU) - uVar34);
    uVar3 = iVar36 + 0xdfU & 3;
    uVar5 = *(uint *)((iVar36 + 0xdfU) - uVar3);
    *puVar33 = uVar50;
    puVar33[1] = uVar49;
    puVar33[2] = uVar48;
    puVar33[3] = uVar47;
    puVar33[4] = uVar46;
    puVar33[5] = uVar45;
    puVar33[6] = (iVar29 << uVar7 * 8 | uVar42 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar34 + 1) * 8 | uVar4 >> (3 - uVar34) * 8;
    puVar33[7] = (iVar9 << uVar8 * 8 | (uint)ppiVar44 & 0xffffffffU >> (4 - uVar8) * 8) &
                 -1 << (uVar3 + 1) * 8 | uVar5 >> (3 - uVar3) * 8;
    iVar37 = *(int *)(uVar25 + 0x58);
    uVar34 = iVar37 + 0xa0U & 3;
    uVar3 = iVar37 + 0xa4U & 3;
    iVar29 = *(int *)((iVar37 + 0xa4U) - uVar3);
    uVar4 = iVar37 + 0xa8U & 3;
    iVar9 = *(int *)((iVar37 + 0xa8U) - uVar4);
    uVar5 = iVar37 + 0xacU & 3;
    iVar36 = *(int *)((iVar37 + 0xacU) - uVar5);
    uVar6 = iVar37 + 0xb0U & 3;
    iVar10 = *(int *)((iVar37 + 0xb0U) - uVar6);
    uVar7 = iVar37 + 0xb4U & 3;
    iVar11 = *(int *)((iVar37 + 0xb4U) - uVar7);
    uVar8 = iVar37 + 0xa3U & 3;
    uVar12 = iVar37 + 0xa7U & 3;
    uVar16 = *(uint *)((iVar37 + 0xa7U) - uVar12);
    uVar42 = iVar37 + 0xabU & 3;
    uVar17 = *(uint *)((iVar37 + 0xabU) - uVar42);
    uVar13 = iVar37 + 0xafU & 3;
    uVar18 = *(uint *)((iVar37 + 0xafU) - uVar13);
    uVar14 = iVar37 + 0xb3U & 3;
    uVar19 = *(uint *)((iVar37 + 0xb3U) - uVar14);
    uVar15 = iVar37 + 0xb7U & 3;
    uVar20 = *(uint *)((iVar37 + 0xb7U) - uVar15);
    uVar43 = *(uint *)(iVar37 + 0xb8);
    uVar39 = *(uint *)(iVar37 + 0xbc);
    *puVar28 = (*(int *)((iVar37 + 0xa0U) - uVar34) << uVar34 * 8 |
               uVar50 & 0xffffffffU >> (4 - uVar34) * 8) & -1 << (uVar8 + 1) * 8 |
               *(uint *)((iVar37 + 0xa3U) - uVar8) >> (3 - uVar8) * 8;
    puVar28[1] = (iVar29 << uVar3 * 8 | uVar49 & 0xffffffffU >> (4 - uVar3) * 8) &
                 -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
    puVar28[2] = (iVar9 << uVar4 * 8 | uVar48 & 0xffffffffU >> (4 - uVar4) * 8) &
                 -1 << (uVar42 + 1) * 8 | uVar17 >> (3 - uVar42) * 8;
    puVar28[3] = (iVar36 << uVar5 * 8 | uVar47 & 0xffffffffU >> (4 - uVar5) * 8) &
                 -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
    puVar28[4] = (iVar10 << uVar6 * 8 | uVar46 & 0xffffffffU >> (4 - uVar6) * 8) &
                 -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
    puVar28[5] = (iVar11 << uVar7 * 8 | uVar45 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar15 + 1) * 8 | uVar20 >> (3 - uVar15) * 8;
    puVar28[6] = uVar43;
    puVar28[7] = uVar39;
    if (iStack_294 != 0) {
      *(char *)(iVar54 + iVar24) = (char)((uint)uStack_298 >> 8);
      *(undefined *)((int)puVar33 + 0x41) = (undefined)uStack_298;
      if ((uStack_298 != 0) || (iStack_29c != 0)) {
        (*(code *)PTR_memcpy_006a9aec)(iVar54 + uStack_2a0 + 0x42,iStack_29c,uStack_298);
      }
    }
    iVar24 = (*(code *)PTR_memcmp_006a9ad0)(iVar54,"client finished",0xf);
    if (((iVar24 == 0) ||
        (iVar24 = (*(code *)PTR_memcmp_006a9ad0)(iVar54,"server finished",0xf), iVar24 == 0)) ||
       ((iVar24 = (*(code *)PTR_memcmp_006a9ad0)(iVar54,"master secret",0xd), iVar24 == 0 ||
        (iVar24 = (*(code *)PTR_memcmp_006a9ad0)(iVar54,"key expansion",0xd), iVar24 == 0)))) {
      pbVar53 = (byte *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x16f,&DAT_0064760c,0x4e8);
    }
    else {
      uVar31 = ssl_get_algorithm2(uVar25);
      pbVar53 = (byte *)tls1_PRF_constprop_1
                                  (uVar31,iVar54,iVar52,0,0,0,0,0,0,*(int *)(uVar25 + 0xc0) + 0x14,
                                   *(undefined4 *)(*(int *)(uVar25 + 0xc0) + 0x10),uVar27,iVar23,
                                   piVar41);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar54,iVar52);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar23,piVar41);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar23);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar54);
  }
  return pbVar53;
}

