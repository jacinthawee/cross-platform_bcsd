
/* WARNING: Could not reconcile some variable overlaps */

byte * tls1_cert_verify_mac(byte **param_1,byte **param_2,byte **param_3,byte **param_4)

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
  byte *pbVar23;
  undefined4 uVar24;
  byte **ppbVar25;
  int iVar26;
  int iVar27;
  uint uVar28;
  byte **ppbVar29;
  char cVar34;
  uint *puVar30;
  int iVar31;
  uint *puVar32;
  undefined4 uVar33;
  uint *puVar35;
  undefined uVar40;
  uint uVar36;
  uint *puVar37;
  int iVar38;
  int iVar39;
  uint uVar41;
  byte **ppbVar42;
  char *pcVar43;
  int *piVar44;
  uint uVar45;
  uint uVar46;
  byte **ppbVar47;
  uint uVar48;
  uint in_t0;
  uint uVar49;
  uint in_t1;
  uint uVar50;
  uint in_t2;
  uint uVar51;
  uint in_t3;
  uint uVar52;
  uint uVar53;
  byte **unaff_s0;
  byte *unaff_s2;
  undefined *puVar54;
  int iVar55;
  byte *unaff_s7;
  byte **unaff_s8;
  int iVar56;
  uint uStack_300;
  int iStack_2fc;
  undefined4 uStack_2f8;
  int iStack_2f4;
  char *pcStack_2c0;
  int iStack_2ac;
  int iStack_2a8;
  uint uStack_2a4;
  uint uStack_2a0;
  uint uStack_29c;
  uint uStack_298;
  uint uStack_294;
  uint uStack_290;
  uint uStack_28c;
  uint uStack_288;
  uint uStack_284;
  uint uStack_280;
  uint uStack_27c;
  uint uStack_278;
  uint uStack_274;
  byte **ppbStack_270;
  int *piStack_26c;
  byte **ppbStack_268;
  uint uStack_264;
  undefined *puStack_260;
  undefined *puStack_25c;
  int *piStack_258;
  byte *pbStack_254;
  byte **ppbStack_250;
  code *pcStack_24c;
  byte *pbStack_238;
  byte *pbStack_234;
  byte *pbStack_230;
  int iStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined *puStack_220;
  byte *pbStack_214;
  byte *pbStack_210;
  byte **ppbStack_20c;
  byte *pbStack_208;
  undefined auStack_204 [24];
  undefined auStack_1ec [4];
  undefined auStack_1e8 [4];
  byte *pbStack_1e4;
  byte *pbStack_1e0;
  undefined uStack_1dc;
  undefined uStack_1db;
  undefined uStack_1da;
  undefined uStack_1d9;
  undefined uStack_1d8;
  int iStack_1d4;
  byte *pbStack_1d0;
  byte **ppbStack_1cc;
  byte *pbStack_1c8;
  byte **ppbStack_1c4;
  int *piStack_1c0;
  byte **ppbStack_1bc;
  byte **ppbStack_1b8;
  byte *pbStack_1b4;
  byte **ppbStack_1b0;
  code *pcStack_1ac;
  byte **ppbStack_198;
  byte *pbStack_194;
  int iStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  byte **ppbStack_17c;
  undefined4 uStack_178;
  undefined *puStack_170;
  int iStack_168;
  byte *pbStack_164;
  byte **ppbStack_160;
  int iStack_15c;
  int iStack_158;
  int **ppiStack_154;
  undefined *puStack_150;
  byte *pbStack_14c;
  byte **ppbStack_144;
  uint uStack_140;
  undefined4 uStack_13c;
  int iStack_138;
  byte *pbStack_134;
  undefined auStack_130 [24];
  byte bStack_118;
  byte bStack_117;
  byte bStack_116;
  byte bStack_115;
  byte bStack_114;
  byte bStack_113;
  byte bStack_112;
  byte bStack_111;
  byte bStack_110;
  byte bStack_10f;
  byte bStack_10e;
  byte bStack_10d;
  byte abStack_10c [128];
  int *piStack_8c;
  byte **ppbStack_88;
  byte **ppbStack_84;
  byte *pbStack_80;
  byte **ppbStack_7c;
  undefined *puStack_78;
  byte **ppbStack_74;
  byte *local_40;
  byte *apbStack_3c [6];
  byte **local_24;
  
  piStack_1c0 = (int *)PTR___stack_chk_guard_006a9ae8;
  pbVar23 = param_1[0x16];
  ppbStack_160 = *(byte ***)PTR___stack_chk_guard_006a9ae8;
  ppbVar42 = param_3;
  local_24 = ppbStack_160;
  if (*(int *)(pbVar23 + 0x178) == 0) {
LAB_00496ed4:
    unaff_s0 = (byte **)0x0;
    unaff_s2 = (byte *)0x18;
LAB_00496ee4:
    if (*(int *)(*(int *)(pbVar23 + 0x17c) + (int)unaff_s0) == 0) {
LAB_00496f18:
      unaff_s0 = unaff_s0 + 1;
      if (unaff_s0 == (byte **)&DAT_00000018) goto LAB_00496f24;
      pbVar23 = param_1[0x16];
      goto LAB_00496ee4;
    }
    uVar24 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)();
    ppbVar25 = (byte **)(*(code *)PTR_EVP_MD_type_006a73cc)(uVar24);
    if (ppbVar25 != param_2) goto LAB_00496f18;
    unaff_s0 = (byte **)(*(int *)(param_1[0x16] + 0x17c) + (int)unaff_s0);
    param_1 = (byte **)*unaff_s0;
    if (param_1 != (byte **)0x0) {
      unaff_s0 = apbStack_3c;
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(unaff_s0);
      ppbStack_160 = param_1;
      iVar26 = (*(code *)PTR_EVP_MD_CTX_copy_ex_006a8104)(unaff_s0);
      if (iVar26 < 1) {
LAB_00496ff4:
        local_40 = (byte *)0x0;
      }
      else {
        ppbVar42 = &local_40;
        ppbStack_160 = param_3;
        iVar26 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(unaff_s0);
        if (iVar26 < 1) goto LAB_00496ff4;
      }
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(unaff_s0);
      pbVar23 = local_40;
      goto LAB_00496f50;
    }
LAB_00496f24:
    ppbVar42 = (byte **)0x144;
    param_4 = (byte **)&DAT_0064760c;
    ppbStack_160 = (byte **)0x11e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14);
    pbVar23 = (byte *)0x0;
  }
  else {
    pbVar23 = (byte *)ssl3_digest_cached_records();
    if (pbVar23 != (byte *)0x0) {
      pbVar23 = param_1[0x16];
      goto LAB_00496ed4;
    }
  }
LAB_00496f50:
  if (local_24 == (byte **)*piStack_1c0) {
    return pbVar23;
  }
  ppbVar47 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppiStack_154 = (int **)PTR___stack_chk_guard_006a9ae8;
  piStack_258 = *(int **)PTR___stack_chk_guard_006a9ae8;
  puStack_78 = (undefined *)piStack_1c0;
  puStack_170 = &_gp;
  ppbVar25 = param_4;
  piStack_8c = piStack_258;
  ppbStack_88 = unaff_s0;
  ppbStack_84 = param_1;
  pbStack_80 = unaff_s2;
  ppbStack_7c = param_2;
  ppbStack_74 = param_3;
  ppbStack_1b8 = param_4;
  if ((*(int *)(ppbVar47[0x16] + 0x178) == 0) ||
     (ppbStack_250 = ppbVar42, iVar26 = ssl3_digest_cached_records(), ppbStack_1cc = ppbVar47,
     ppbStack_1b0 = unaff_s8, iVar26 != 0)) {
    puStack_150 = auStack_130;
    pbVar23 = abStack_10c;
    pbStack_164 = pbVar23;
    (**(code **)(puStack_170 + -0x7fc4))(puStack_150);
    iVar26 = 0;
    iStack_158 = 0;
    iStack_168 = 0;
    while (iVar27 = ssl_get_handshake_digest(iVar26,&uStack_140,&uStack_13c), iVar27 != 0) {
      uVar28 = ssl_get_algorithm2(ppbVar47);
      if ((uVar28 & uStack_140) == 0) {
        iVar26 = iVar26 + 1;
      }
      else {
        ppbVar29 = (byte **)(**(code **)(puStack_170 + -0x6fa4))(uStack_13c);
        if (((*(int *)(*(int *)(ppbVar47[0x16] + 0x17c) + iVar26 * 4) == 0) || ((int)ppbVar29 < 0))
           || (0x80 - iStack_168 < (int)ppbVar29)) {
          iVar26 = iVar26 + 1;
          iStack_158 = 1;
        }
        else {
          iVar27 = (**(code **)(puStack_170 + -0x6cdc))(puStack_150);
          if (((iVar27 == 0) ||
              (iVar27 = (**(code **)(puStack_170 + -0x785c))(puStack_150,pbVar23,&ppbStack_144),
              iVar27 == 0)) || (ppbVar25 = ppbStack_144, ppbStack_144 != ppbVar29)) {
            iStack_158 = 1;
            ppbVar25 = ppbVar29;
          }
          pbVar23 = pbVar23 + (int)ppbVar25;
          iVar26 = iVar26 + 1;
          iStack_168 = (int)pbVar23 - (int)pbStack_164;
        }
      }
    }
    param_2 = &pbStack_134;
    ppbStack_1cc = (byte **)ssl_get_algorithm2(ppbVar47);
    piStack_1c0 = &iStack_138;
    unaff_s7 = (byte *)0x0;
    unaff_s2 = ppbVar47[0x30] + 0x14;
    ppbStack_1b0 = *(byte ***)(ppbVar47[0x30] + 0x10);
    iVar26 = 0;
    while (pbStack_1d0 = (byte *)ssl_get_handshake_digest(unaff_s7,piStack_1c0,param_2),
          pbStack_1d0 != (byte *)0x0) {
      unaff_s7 = unaff_s7 + 1;
      if ((iStack_138 << 10 & (uint)ppbStack_1cc) != 0) {
        iVar26 = iVar26 + 1;
      }
    }
    if (iVar26 == 0) {
      ppbStack_250 = (byte **)0x44;
      ppbVar47 = (byte **)&DAT_0064760c;
      ppbStack_198 = (byte **)0x10a;
      (**(code **)(puStack_170 + -0x6eac))(0x14,0x11c);
LAB_0049748c:
      param_3 = (byte **)&bStack_118;
      (**(code **)(puStack_170 + -0x7fac))(puStack_150);
      (**(code **)(puStack_170 + -0x7d6c))(pbStack_164,iStack_168);
      piStack_258 = (int *)&SUB_0000000c;
      (**(code **)(puStack_170 + -0x7d6c))(param_3);
    }
    else {
      if (iVar26 == 0) {
        trap(7);
      }
      iStack_15c = (int)ppbStack_1b0 / iVar26;
      *(byte *)param_4 = 0;
      if (iVar26 == 1) {
        ppbStack_1b0 = (byte **)0x0;
      }
      unaff_s7 = (byte *)0x0;
      *(byte *)((int)param_4 + 1) = 0;
      *(byte *)((int)param_4 + 2) = 0;
      *(byte *)((int)param_4 + 3) = 0;
      *(byte *)(param_4 + 1) = 0;
      param_3 = (byte **)&bStack_118;
      *(byte *)((int)param_4 + 5) = 0;
      *(byte *)((int)param_4 + 6) = 0;
      *(byte *)((int)param_4 + 7) = 0;
      *(byte *)(param_4 + 2) = 0;
      *(byte *)((int)param_4 + 9) = 0;
      *(byte *)((int)param_4 + 10) = 0;
      *(byte *)((int)param_4 + 0xb) = 0;
      ppbStack_1b8 = (byte **)(((uint)ppbStack_1b0 & 1) + iStack_15c);
      ppbStack_250 = param_2;
      pbStack_14c = pbStack_1d0;
      iVar26 = ssl_get_handshake_digest(0,piStack_1c0);
      ppbVar47 = ppbStack_160;
      pbStack_1d0 = pbStack_14c;
      while (ppbStack_160 = ppbVar47, ppbStack_1b0 = ppbVar42, pbStack_14c = pbStack_1d0,
            iVar26 != 0) {
        if ((iStack_138 << 10 & (uint)ppbStack_1cc) != 0) {
          if (pbStack_134 == (byte *)0x0) {
            ppbStack_250 = (byte **)0x146;
            ppbVar47 = (byte **)&DAT_0064760c;
            ppbStack_198 = (byte **)0x115;
            (**(code **)(puStack_170 + -0x6eac))(0x14,0x11c);
            goto LAB_0049748c;
          }
          uStack_180 = 0;
          uStack_178 = 0xc;
          uStack_184 = 0;
          uStack_188 = 0;
          uStack_18c = 0;
          ppbStack_250 = ppbStack_1b8;
          ppbStack_198 = ppbVar42;
          pbStack_194 = pbStack_164;
          iStack_190 = iStack_168;
          ppbStack_17c = param_3;
          iVar26 = tls1_P_hash_constprop_2(pbStack_134,unaff_s2);
          pbStack_1d0 = pbStack_14c;
          if (iVar26 == 0) goto LAB_0049748c;
          unaff_s2 = unaff_s2 + iStack_15c;
          bVar1 = *(byte *)((int)param_4 + 3) ^ bStack_115;
          in_t3 = (uint)bVar1;
          bVar21 = *(byte *)((int)param_4 + 6) ^ bStack_112;
          ppbVar25 = (byte **)(uint)bVar21;
          in_t2 = (uint)(*(byte *)(param_4 + 1) ^ bStack_114);
          bVar22 = *(byte *)((int)param_4 + 5) ^ bStack_113;
          in_t1 = (uint)bVar22;
          *(byte *)param_4 = *(byte *)param_4 ^ bStack_118;
          *(byte *)((int)param_4 + 1) = *(byte *)((int)param_4 + 1) ^ bStack_117;
          *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) ^ bStack_116;
          *(byte *)((int)param_4 + 3) = bVar1;
          *(byte *)(param_4 + 1) = *(byte *)(param_4 + 1) ^ bStack_114;
          *(byte *)((int)param_4 + 5) = bVar22;
          *(byte *)((int)param_4 + 6) = bVar21;
          *(byte *)((int)param_4 + 7) = *(byte *)((int)param_4 + 7) ^ bStack_111;
          *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) ^ bStack_110;
          *(byte *)((int)param_4 + 9) = *(byte *)((int)param_4 + 9) ^ bStack_10f;
          *(byte *)((int)param_4 + 10) = *(byte *)((int)param_4 + 10) ^ bStack_10e;
          *(byte *)((int)param_4 + 0xb) = *(byte *)((int)param_4 + 0xb) ^ bStack_10d;
        }
        unaff_s7 = unaff_s7 + 1;
        ppbStack_250 = param_2;
        iVar26 = ssl_get_handshake_digest(unaff_s7,piStack_1c0);
        ppbVar47 = ppbStack_160;
        pbStack_1d0 = pbStack_14c;
      }
      (**(code **)(puStack_170 + -0x7fac))(puStack_150);
      (**(code **)(puStack_170 + -0x7d6c))(pbStack_164,iStack_168);
      piStack_258 = (int *)&SUB_0000000c;
      (**(code **)(puStack_170 + -0x7d6c))(param_3);
      if (iStack_158 != 0) goto LAB_00497418;
      pbStack_1d0 = &SUB_0000000c;
      ppbVar47 = ppbVar25;
    }
  }
  else {
LAB_00497418:
    pbStack_1d0 = (byte *)0x0;
    ppbVar47 = ppbVar25;
  }
  if (piStack_8c == *ppiStack_154) {
    return pbStack_1d0;
  }
  pcStack_1ac = tls1_mac;
  piStack_26c = piStack_8c;
  (**(code **)(puStack_170 + -0x5330))();
  puStack_25c = PTR___stack_chk_guard_006a9ae8;
  puStack_220 = &_gp;
  iStack_1d4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar26 = piStack_26c[0x16];
  ppbStack_268 = (byte **)(iVar26 + 0x10c);
  if (ppbStack_250 == (byte **)0x0) {
    puVar54 = (undefined *)piStack_26c[0x21];
    ppbStack_270 = (byte **)(iVar26 + 8);
    uStack_264 = piStack_26c[0x1f] & 1;
  }
  else {
    puVar54 = (undefined *)piStack_26c[0x24];
    ppbStack_268 = (byte **)(iVar26 + 0x130);
    ppbStack_270 = (byte **)(iVar26 + 0x54);
    uStack_264 = piStack_26c[0x1f] & 2;
  }
  pcVar43 = (char *)ppbStack_250;
  pbStack_1c8 = unaff_s2;
  ppbStack_1c4 = param_2;
  ppbStack_1bc = param_3;
  pbStack_1b4 = unaff_s7;
  uVar24 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(puVar54);
  pbStack_208 = (byte *)(**(code **)(puStack_220 + -0x6fa4))(uVar24);
  if ((int)pbStack_208 < 0) {
    pcVar43 = "t >= 0";
    pbStack_214 = pbStack_208;
    (**(code **)(puStack_220 + -0x7184))(&DAT_0064760c,0x3f4);
    pbStack_208 = pbStack_214;
  }
  puStack_260 = puVar54;
  if (uStack_264 == 0) {
    puStack_260 = auStack_204;
    iVar26 = (**(code **)(puStack_220 + -0x6be0))(puStack_260,puVar54);
    if (iVar26 == 0) {
      pbVar23 = (byte *)0xffffffff;
      goto LAB_0049788c;
    }
  }
  iVar26 = *piStack_26c;
  if ((iVar26 == 0xfeff) || (iVar26 == 0x100)) {
    if (ppbStack_250 == (byte **)0x0) {
      uVar2 = *(undefined2 *)(piStack_26c[0x17] + 0x208);
      uVar40 = (undefined)((ushort)uVar2 >> 8);
    }
    else {
      uVar2 = *(undefined2 *)(piStack_26c[0x17] + 0x20a);
      uVar40 = (undefined)((ushort)uVar2 >> 8);
    }
    auStack_1ec = (undefined  [4])CONCAT13(uVar40,CONCAT12((char)uVar2,SUB42(auStack_1ec,0)));
    bVar1 = *(byte *)((int)ppbStack_270 + 6);
    in_t0 = (uint)bVar1;
    uVar36 = *(uint *)((int)ppbStack_270 + 2);
    cVar34 = *(char *)((int)ppbStack_270 + 7);
    puVar54 = auStack_1ec + 2;
    uVar28 = (uint)puVar54 & 3;
    *(uint *)(puVar54 + -uVar28) =
         *(uint *)(puVar54 + -uVar28) & -1 << (4 - uVar28) * 8 | uVar36 >> uVar28 * 8;
    puVar54 = auStack_1e8 + 1;
    uVar28 = (uint)puVar54 & 3;
    *(uint *)(puVar54 + -uVar28) =
         *(uint *)(puVar54 + -uVar28) & 0xffffffffU >> (uVar28 + 1) * 8 | uVar36 << (3 - uVar28) * 8
    ;
    auStack_1e8 = (undefined  [4])CONCAT31(CONCAT21(auStack_1e8._0_2_,bVar1),cVar34);
    pbStack_1e0 = (byte *)auStack_1e8;
    pbStack_1e4 = (byte *)auStack_1ec;
  }
  else {
    pbStack_1e4 = *ppbStack_270;
    pbStack_1e0 = ppbStack_270[1];
  }
  pbStack_214 = ppbStack_268[1];
  unaff_s7 = *ppbStack_268;
  pbStack_210 = pbStack_208;
  ppbVar47 = (byte **)((uint)unaff_s7 & 0xff);
  *ppbStack_268 = (byte *)ppbVar47;
  uStack_1dc = SUB41(unaff_s7,0);
  uStack_1db = (undefined)((uint)iVar26 >> 8);
  uStack_1da = (undefined)iVar26;
  uStack_1d9 = (undefined)((uint)pbStack_214 >> 8);
  uStack_1d8 = SUB41(pbStack_214,0);
  if (((ppbStack_250 == (byte **)0x0) &&
      (ppbStack_20c = &pbStack_1e4, uVar28 = (**(code **)(puStack_220 + -0x6cd8))(piStack_26c[0x20])
      , (uVar28 & 0xf0007) == 2)) &&
     (iVar26 = ssl3_cbc_record_digest_supported(puStack_260,ppbStack_20c), iVar26 != 0)) {
    in_t0 = (uint)unaff_s7 >> 8;
    uStack_224 = 0;
    iStack_22c = piStack_26c[0x16] + 0x14;
    uStack_228 = *(undefined4 *)(piStack_26c[0x16] + 0x10);
    unaff_s7 = pbStack_214 + (int)pbStack_210 + in_t0;
    pcVar43 = (char *)&pbStack_208;
    pbStack_234 = ppbStack_268[1] + (int)pbStack_208;
    pbStack_238 = ppbStack_268[4];
    ppbVar47 = ppbStack_20c;
    pbStack_230 = unaff_s7;
    iVar26 = ssl3_cbc_digest_record(puStack_260,piStack_258);
joined_r0x004976bc:
    if (0 < iVar26) {
      if (uStack_264 == 0) {
        (**(code **)(puStack_220 + -0x7fac))(auStack_204);
      }
      pbVar23 = pbStack_208;
      if (((*piStack_26c != 0xfeff) && (*piStack_26c != 0x100)) &&
         ((((cVar34 = *(char *)((int)ppbStack_270 + 7) + '\x01',
            *(char *)((int)ppbStack_270 + 7) = cVar34, cVar34 == '\0' &&
            ((cVar34 = *(char *)((int)ppbStack_270 + 6) + '\x01',
             *(char *)((int)ppbStack_270 + 6) = cVar34, cVar34 == '\0' &&
             (cVar34 = *(char *)((int)ppbStack_270 + 5) + '\x01',
             *(char *)((int)ppbStack_270 + 5) = cVar34, cVar34 == '\0')))) &&
           (cVar34 = *(char *)(ppbStack_270 + 1), *(char *)(ppbStack_270 + 1) = cVar34 + '\x01',
           (char)(cVar34 + '\x01') == '\0')) &&
          (((cVar34 = *(char *)((int)ppbStack_270 + 3) + '\x01',
            *(char *)((int)ppbStack_270 + 3) = cVar34, cVar34 == '\0' &&
            (cVar34 = *(char *)((int)ppbStack_270 + 2) + '\x01',
            *(char *)((int)ppbStack_270 + 2) = cVar34, cVar34 == '\0')) &&
           (cVar34 = *(char *)((int)ppbStack_270 + 1) + '\x01',
           *(char *)((int)ppbStack_270 + 1) = cVar34, cVar34 == '\0')))))) {
        *(char *)ppbStack_270 = *(char *)ppbStack_270 + '\x01';
      }
      goto LAB_0049788c;
    }
  }
  else {
    pcVar43 = &DAT_0000000d;
    iVar26 = (**(code **)(puStack_220 + -0x7860))(puStack_260);
    if (0 < iVar26) {
      pcVar43 = (char *)ppbStack_268[1];
      iVar26 = (**(code **)(puStack_220 + -0x7860))(puStack_260,ppbStack_268[4]);
      if (0 < iVar26) {
        pcVar43 = (char *)&pbStack_208;
        iVar26 = (**(code **)(puStack_220 + -0x7910))(puStack_260,piStack_258);
        goto joined_r0x004976bc;
      }
    }
  }
  if (uStack_264 == 0) {
    (**(code **)(puStack_220 + -0x7fac))(auStack_204);
  }
  pbVar23 = (byte *)0xffffffff;
LAB_0049788c:
  if (iStack_1d4 == *(int *)puStack_25c) {
    return pbVar23;
  }
  pcStack_24c = tls1_generate_master_secret;
  iVar26 = iStack_1d4;
  (**(code **)(puStack_220 + -0x5330))();
  puVar54 = PTR___stack_chk_guard_006a9ae8;
  uStack_274 = *(uint *)PTR___stack_chk_guard_006a9ae8;
  ppbVar42 = ppbVar47;
  pbStack_254 = unaff_s7;
  uVar28 = ssl_get_algorithm2();
  iVar56 = *(int *)(iVar26 + 0xc0);
  iVar55 = 0;
  iVar27 = *(int *)(iVar26 + 0x58) + 0xc0;
  puVar30 = (uint *)(iVar56 + 0x14);
  iVar26 = 0;
  while (iVar31 = ssl_get_handshake_digest(iVar55,&iStack_2ac,&iStack_2a8), iVar31 != 0) {
    iVar55 = iVar55 + 1;
    if ((iStack_2ac << 10 & uVar28) != 0) {
      iVar26 = iVar26 + 1;
    }
  }
  if (iVar26 == 0) {
    piVar44 = (int *)0x44;
    ppbVar42 = (byte **)&DAT_0064760c;
    uStack_300 = 0x10a;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11c);
  }
  else {
    if (iVar26 == 0) {
      trap(7);
    }
    iVar55 = (int)ppbVar47 / iVar26;
    if (iVar26 == 1) {
      ppbVar47 = (byte **)0x0;
    }
    (*(code *)PTR_memset_006a99f4)(puVar30,0,0x30);
    iVar26 = 0;
    pcStack_2c0 = "master secret";
    piVar44 = &iStack_2a8;
    iVar31 = ssl_get_handshake_digest(0,&iStack_2ac);
    while (iVar31 != 0) {
      if ((iStack_2ac << 10 & uVar28) != 0) {
        if (iStack_2a8 == 0) {
          piVar44 = (int *)0x146;
          ppbVar42 = (byte **)&DAT_0064760c;
          uStack_300 = 0x115;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11c);
          break;
        }
        uStack_2f8 = 0x20;
        iStack_2f4 = 0;
        uStack_300 = 0xd;
        piVar44 = (int *)(((uint)ppbVar47 & 1) + iVar55);
        ppbVar42 = (byte **)pcStack_2c0;
        iVar31 = tls1_P_hash_constprop_2(iStack_2a8,pcVar43);
        iStack_2fc = iVar27;
        if (iVar31 == 0) break;
        pcVar43 = (char *)((int)pcVar43 + iVar55);
        puVar35 = &uStack_2a4;
        puVar37 = puVar30;
        if (((uint)puVar30 & 3) == 0 &&
            ((uint *)(iVar56 + 0x18) <= &uStack_2a4 || &uStack_2a0 <= puVar30)) {
          *(uint *)(iVar56 + 0x14) = *(uint *)(iVar56 + 0x14) ^ uStack_2a4;
          *(uint *)(iVar56 + 0x18) = uStack_2a0 ^ *(uint *)(iVar56 + 0x18);
          ppbVar42 = (byte **)(uStack_28c ^ *(uint *)(iVar56 + 0x2c));
          in_t3 = uStack_290 ^ *(uint *)(iVar56 + 0x28);
          *(uint *)(iVar56 + 0x1c) = uStack_29c ^ *(uint *)(iVar56 + 0x1c);
          *(uint *)(iVar56 + 0x20) = uStack_298 ^ *(uint *)(iVar56 + 0x20);
          *(uint *)(iVar56 + 0x24) = uStack_294 ^ *(uint *)(iVar56 + 0x24);
          *(uint *)(iVar56 + 0x28) = in_t3;
          *(byte ***)(iVar56 + 0x2c) = ppbVar42;
          *(uint *)(iVar56 + 0x30) = uStack_288 ^ *(uint *)(iVar56 + 0x30);
          *(uint *)(iVar56 + 0x38) = uStack_280 ^ *(uint *)(iVar56 + 0x38);
          *(uint *)(iVar56 + 0x34) = uStack_284 ^ *(uint *)(iVar56 + 0x34);
          *(uint *)(iVar56 + 0x3c) = uStack_27c ^ *(uint *)(iVar56 + 0x3c);
          *(uint *)(iVar56 + 0x40) = *(uint *)(iVar56 + 0x40) ^ uStack_278;
        }
        else {
          do {
            puVar32 = (uint *)((int)puVar35 + 1);
            *(byte *)puVar37 = *(byte *)puVar37 ^ *(byte *)puVar35;
            puVar35 = puVar32;
            puVar37 = (uint *)((int)puVar37 + 1);
          } while (puVar32 != &uStack_274);
        }
      }
      iVar26 = iVar26 + 1;
      piVar44 = &iStack_2a8;
      iVar31 = ssl_get_handshake_digest(iVar26,&iStack_2ac);
    }
  }
  uVar24 = 0x30;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(&uStack_2a4);
  if (uStack_274 == *(uint *)puVar54) {
    return &DAT_00000030;
  }
  uVar28 = uStack_274;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppbVar25 = ppbVar42;
  iVar26 = (*(code *)PTR_CRYPTO_malloc_006a7008)(piVar44,&DAT_0064760c,0x4a2);
  if (iVar26 == 0) {
    pbVar23 = (byte *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
  }
  else {
    iVar27 = uStack_300 + 0x40;
    if (iStack_2f4 == 0) {
      iVar56 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar27,&DAT_0064760c,0x4b0);
      iVar55 = iVar27;
    }
    else {
      iVar55 = uStack_2f8 + 2 + iVar27;
      iVar56 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar55,&DAT_0064760c,0x4b0);
    }
    if (iVar56 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar26);
      return (byte *)0x0;
    }
    uVar45 = uStack_300;
    (*(code *)PTR_memcpy_006a9aec)(iVar56);
    puVar35 = (uint *)(iVar56 + uStack_300);
    iVar38 = *(int *)(uVar28 + 0x58);
    puVar30 = (uint *)(iVar56 + uStack_300 + 0x20);
    uVar53 = *(uint *)(iVar38 + 0xc0);
    uVar36 = iVar38 + 0xc4U & 3;
    uVar3 = iVar38 + 200U & 3;
    uVar4 = iVar38 + 0xccU & 3;
    uVar5 = iVar38 + 0xd0U & 3;
    uVar6 = iVar38 + 0xd4U & 3;
    uVar7 = iVar38 + 0xd8U & 3;
    iVar31 = *(int *)((iVar38 + 0xd8U) - uVar7);
    uVar8 = iVar38 + 0xdcU & 3;
    iVar9 = *(int *)((iVar38 + 0xdcU) - uVar8);
    uVar12 = iVar38 + 199U & 3;
    uVar52 = (*(int *)((iVar38 + 0xc4U) - uVar36) << uVar36 * 8 |
             in_t3 & 0xffffffffU >> (4 - uVar36) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)((iVar38 + 199U) - uVar12) >> (3 - uVar12) * 8;
    uVar36 = iVar38 + 0xcbU & 3;
    uVar51 = (*(int *)((iVar38 + 200U) - uVar3) << uVar3 * 8 |
             in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar36 + 1) * 8 |
             *(uint *)((iVar38 + 0xcbU) - uVar36) >> (3 - uVar36) * 8;
    uVar36 = iVar38 + 0xcfU & 3;
    uVar50 = (*(int *)((iVar38 + 0xccU) - uVar4) << uVar4 * 8 |
             in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar36 + 1) * 8 |
             *(uint *)((iVar38 + 0xcfU) - uVar36) >> (3 - uVar36) * 8;
    uVar36 = iVar38 + 0xd3U & 3;
    uVar49 = (*(int *)((iVar38 + 0xd0U) - uVar5) << uVar5 * 8 |
             in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar36 + 1) * 8 |
             *(uint *)((iVar38 + 0xd3U) - uVar36) >> (3 - uVar36) * 8;
    uVar36 = iVar38 + 0xd7U & 3;
    uVar48 = (*(int *)((iVar38 + 0xd4U) - uVar6) << uVar6 * 8 |
             (uint)ppbVar25 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar36 + 1) * 8 |
             *(uint *)((iVar38 + 0xd7U) - uVar36) >> (3 - uVar36) * 8;
    uVar36 = iVar38 + 0xdbU & 3;
    uVar4 = *(uint *)((iVar38 + 0xdbU) - uVar36);
    uVar3 = iVar38 + 0xdfU & 3;
    uVar5 = *(uint *)((iVar38 + 0xdfU) - uVar3);
    *puVar35 = uVar53;
    puVar35[1] = uVar52;
    puVar35[2] = uVar51;
    puVar35[3] = uVar50;
    puVar35[4] = uVar49;
    puVar35[5] = uVar48;
    puVar35[6] = (iVar31 << uVar7 * 8 | uVar45 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar36 + 1) * 8 | uVar4 >> (3 - uVar36) * 8;
    puVar35[7] = (iVar9 << uVar8 * 8 | (uint)ppbVar42 & 0xffffffffU >> (4 - uVar8) * 8) &
                 -1 << (uVar3 + 1) * 8 | uVar5 >> (3 - uVar3) * 8;
    iVar39 = *(int *)(uVar28 + 0x58);
    uVar36 = iVar39 + 0xa0U & 3;
    uVar3 = iVar39 + 0xa4U & 3;
    iVar31 = *(int *)((iVar39 + 0xa4U) - uVar3);
    uVar4 = iVar39 + 0xa8U & 3;
    iVar9 = *(int *)((iVar39 + 0xa8U) - uVar4);
    uVar5 = iVar39 + 0xacU & 3;
    iVar38 = *(int *)((iVar39 + 0xacU) - uVar5);
    uVar6 = iVar39 + 0xb0U & 3;
    iVar10 = *(int *)((iVar39 + 0xb0U) - uVar6);
    uVar7 = iVar39 + 0xb4U & 3;
    iVar11 = *(int *)((iVar39 + 0xb4U) - uVar7);
    uVar8 = iVar39 + 0xa3U & 3;
    uVar12 = iVar39 + 0xa7U & 3;
    uVar16 = *(uint *)((iVar39 + 0xa7U) - uVar12);
    uVar45 = iVar39 + 0xabU & 3;
    uVar17 = *(uint *)((iVar39 + 0xabU) - uVar45);
    uVar13 = iVar39 + 0xafU & 3;
    uVar18 = *(uint *)((iVar39 + 0xafU) - uVar13);
    uVar14 = iVar39 + 0xb3U & 3;
    uVar19 = *(uint *)((iVar39 + 0xb3U) - uVar14);
    uVar15 = iVar39 + 0xb7U & 3;
    uVar20 = *(uint *)((iVar39 + 0xb7U) - uVar15);
    uVar46 = *(uint *)(iVar39 + 0xb8);
    uVar41 = *(uint *)(iVar39 + 0xbc);
    *puVar30 = (*(int *)((iVar39 + 0xa0U) - uVar36) << uVar36 * 8 |
               uVar53 & 0xffffffffU >> (4 - uVar36) * 8) & -1 << (uVar8 + 1) * 8 |
               *(uint *)((iVar39 + 0xa3U) - uVar8) >> (3 - uVar8) * 8;
    puVar30[1] = (iVar31 << uVar3 * 8 | uVar52 & 0xffffffffU >> (4 - uVar3) * 8) &
                 -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
    puVar30[2] = (iVar9 << uVar4 * 8 | uVar51 & 0xffffffffU >> (4 - uVar4) * 8) &
                 -1 << (uVar45 + 1) * 8 | uVar17 >> (3 - uVar45) * 8;
    puVar30[3] = (iVar38 << uVar5 * 8 | uVar50 & 0xffffffffU >> (4 - uVar5) * 8) &
                 -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
    puVar30[4] = (iVar10 << uVar6 * 8 | uVar49 & 0xffffffffU >> (4 - uVar6) * 8) &
                 -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
    puVar30[5] = (iVar11 << uVar7 * 8 | uVar48 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar15 + 1) * 8 | uVar20 >> (3 - uVar15) * 8;
    puVar30[6] = uVar46;
    puVar30[7] = uVar41;
    if (iStack_2f4 != 0) {
      *(char *)(iVar56 + iVar27) = (char)((uint)uStack_2f8 >> 8);
      *(undefined *)((int)puVar35 + 0x41) = (undefined)uStack_2f8;
      if ((uStack_2f8 != 0) || (iStack_2fc != 0)) {
        (*(code *)PTR_memcpy_006a9aec)(iVar56 + uStack_300 + 0x42,iStack_2fc,uStack_2f8);
      }
    }
    iVar27 = (*(code *)PTR_memcmp_006a9ad0)(iVar56,"client finished",0xf);
    if (((iVar27 == 0) ||
        (iVar27 = (*(code *)PTR_memcmp_006a9ad0)(iVar56,"server finished",0xf), iVar27 == 0)) ||
       ((iVar27 = (*(code *)PTR_memcmp_006a9ad0)(iVar56,"master secret",0xd), iVar27 == 0 ||
        (iVar27 = (*(code *)PTR_memcmp_006a9ad0)(iVar56,"key expansion",0xd), iVar27 == 0)))) {
      pbVar23 = (byte *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x16f,&DAT_0064760c,0x4e8);
    }
    else {
      uVar33 = ssl_get_algorithm2(uVar28);
      pbVar23 = (byte *)tls1_PRF_constprop_1
                                  (uVar33,iVar56,iVar55,0,0,0,0,0,0,*(int *)(uVar28 + 0xc0) + 0x14,
                                   *(undefined4 *)(*(int *)(uVar28 + 0xc0) + 0x10),uVar24,iVar26,
                                   piVar44);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar56,iVar55);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar26,piVar44);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar26);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar56);
  }
  return pbVar23;
}

