
/* WARNING: Could not reconcile some variable overlaps */

int tls1_cert_verify_mac(int param_1,int *param_2,int *param_3,int *param_4)

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
  int iVar22;
  undefined4 uVar23;
  int *piVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  char cVar31;
  uint *puVar28;
  int iVar29;
  uint *puVar30;
  uint *puVar32;
  undefined uVar37;
  uint uVar33;
  uint *puVar34;
  int iVar35;
  int iVar36;
  uint uVar38;
  int *piVar39;
  uint uVar40;
  uint uVar41;
  undefined4 *puVar42;
  undefined4 *puVar43;
  uint uVar44;
  uint in_t0;
  uint uVar45;
  uint in_t1;
  uint uVar46;
  uint in_t2;
  uint uVar47;
  uint in_t3;
  uint uVar48;
  uint uVar49;
  int *unaff_s0;
  char *pcVar50;
  int *unaff_s2;
  undefined *puVar51;
  int unaff_s7;
  undefined *unaff_s8;
  int iVar52;
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
  undefined4 *puStack_270;
  int *piStack_26c;
  uint *puStack_268;
  undefined *puStack_264;
  uint uStack_260;
  undefined *puStack_25c;
  int *piStack_258;
  uint uStack_254;
  int *piStack_250;
  code *pcStack_24c;
  uint uStack_238;
  int iStack_234;
  int iStack_230;
  int iStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined *puStack_220;
  uint uStack_214;
  int iStack_210;
  undefined4 *puStack_20c;
  int iStack_208;
  undefined auStack_204 [24];
  undefined auStack_1ec [4];
  undefined auStack_1e8 [4];
  undefined4 uStack_1e4;
  undefined4 uStack_1e0;
  undefined uStack_1dc;
  undefined uStack_1db;
  undefined uStack_1da;
  undefined uStack_1d9;
  undefined uStack_1d8;
  int iStack_1d4;
  int *piStack_1d0;
  int iStack_1cc;
  int *piStack_1c8;
  int *piStack_1c4;
  int *piStack_1c0;
  int *piStack_1bc;
  int *piStack_1b8;
  int iStack_1b4;
  undefined *puStack_1b0;
  code *pcStack_1ac;
  int *piStack_198;
  undefined *puStack_194;
  int iStack_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined4 uStack_180;
  int *piStack_17c;
  undefined4 uStack_178;
  undefined *puStack_170;
  int iStack_168;
  int *piStack_164;
  int *piStack_160;
  int iStack_15c;
  int **ppiStack_158;
  undefined *puStack_154;
  undefined *puStack_150;
  int iStack_14c;
  int iStack_144;
  uint uStack_140;
  undefined4 uStack_13c;
  int iStack_138;
  int iStack_134;
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
  undefined auStack_10c [128];
  int *piStack_8c;
  int *piStack_88;
  int iStack_84;
  int *piStack_80;
  int *piStack_7c;
  undefined *puStack_78;
  int *piStack_74;
  int local_40;
  int aiStack_3c [6];
  int *local_24;
  
  piStack_1c0 = (int *)PTR___stack_chk_guard_006aabf0;
  iVar22 = *(int *)(param_1 + 0x58);
  piStack_164 = *(int **)PTR___stack_chk_guard_006aabf0;
  local_24 = piStack_164;
  if (*(int *)(iVar22 + 0x178) == 0) {
LAB_0049ab00:
    unaff_s0 = (int *)0x0;
    unaff_s2 = (int *)&DAT_00000018;
LAB_0049ab10:
    if (*(int *)(*(int *)(iVar22 + 0x17c) + (int)unaff_s0) == 0) {
LAB_0049ab44:
      unaff_s0 = unaff_s0 + 1;
      if (unaff_s0 == (int *)&DAT_00000018) goto LAB_0049ab50;
      iVar22 = *(int *)(param_1 + 0x58);
      goto LAB_0049ab10;
    }
    uVar23 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)();
    piVar24 = (int *)(*(code *)PTR_EVP_MD_type_006a84cc)(uVar23);
    if (piVar24 != param_2) goto LAB_0049ab44;
    unaff_s0 = (int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x17c) + (int)unaff_s0);
    param_1 = *unaff_s0;
    if (param_1 != 0) {
      unaff_s0 = aiStack_3c;
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(unaff_s0);
      (*(code *)PTR_EVP_MD_CTX_copy_ex_006a922c)(unaff_s0,param_1);
      piVar24 = &local_40;
      piStack_164 = param_3;
      (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(unaff_s0);
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(unaff_s0);
      iVar22 = local_40;
      goto LAB_0049ab7c;
    }
LAB_0049ab50:
    piVar24 = (int *)0x144;
    param_4 = (int *)&DAT_00647bcc;
    piStack_164 = (int *)0x11e;
    (*(code *)PTR_ERR_put_error_006a9030)(0x14);
    iVar22 = 0;
  }
  else {
    piVar24 = param_3;
    iVar22 = ssl3_digest_cached_records();
    if (iVar22 != 0) {
      iVar22 = *(int *)(param_1 + 0x58);
      goto LAB_0049ab00;
    }
  }
LAB_0049ab7c:
  if (local_24 == (int *)*piStack_1c0) {
    return iVar22;
  }
  piVar39 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  ppiStack_158 = (int **)PTR___stack_chk_guard_006aabf0;
  piStack_258 = *(int **)PTR___stack_chk_guard_006aabf0;
  puStack_78 = (undefined *)piStack_1c0;
  puStack_170 = &_gp;
  piStack_8c = piStack_258;
  piStack_88 = unaff_s0;
  iStack_84 = param_1;
  piStack_80 = unaff_s2;
  piStack_7c = param_2;
  piStack_74 = param_3;
  if ((*(int *)(piVar39[0x16] + 0x178) == 0) ||
     (piStack_250 = piVar24, iVar22 = ssl3_digest_cached_records(), piStack_1b8 = param_4,
     iVar22 != 0)) {
    puStack_154 = auStack_130;
    puVar51 = auStack_10c;
    puStack_150 = puVar51;
    (**(code **)(puStack_170 + -0x7fc4))(puStack_154);
    iVar22 = 0;
    iStack_15c = 0;
    iStack_168 = 0;
    while (iVar25 = ssl_get_handshake_digest(iVar22,&uStack_140,&uStack_13c), iVar25 != 0) {
      uVar26 = ssl_get_algorithm2(piVar39);
      if ((uVar26 & uStack_140) == 0) {
        iVar22 = iVar22 + 1;
      }
      else {
        iVar25 = (**(code **)(puStack_170 + -0x6fb4))(uStack_13c);
        if (((*(int *)(*(int *)(piVar39[0x16] + 0x17c) + iVar22 * 4) == 0) || (iVar25 < 0)) ||
           (0x80 - iStack_168 < iVar25)) {
          iVar22 = iVar22 + 1;
          iStack_15c = 1;
        }
        else {
          iVar27 = (**(code **)(puStack_170 + -0x6cb4))(puStack_154);
          if (((iVar27 == 0) ||
              (iVar27 = (**(code **)(puStack_170 + -0x7868))(puStack_154,puVar51,&iStack_144),
              iVar27 == 0)) || (iVar27 = iStack_144, iStack_144 != iVar25)) {
            iStack_15c = 1;
            iVar27 = iVar25;
          }
          puVar51 = puVar51 + iVar27;
          iVar22 = iVar22 + 1;
          iStack_168 = (int)puVar51 - (int)puStack_150;
        }
      }
    }
    param_2 = &iStack_134;
    unaff_s0 = (int *)ssl_get_algorithm2(piVar39);
    piStack_1c0 = &iStack_138;
    iVar25 = 0;
    unaff_s2 = (int *)(piVar39[0x30] + 0x14);
    uVar26 = *(uint *)(piVar39[0x30] + 0x10);
    iVar22 = 0;
    while (iStack_14c = ssl_get_handshake_digest(iVar25,piStack_1c0,param_2), unaff_s8 = puStack_150
          , iStack_14c != 0) {
      iVar25 = iVar25 + 1;
      if ((iStack_138 << 10 & (uint)unaff_s0) != 0) {
        iVar22 = iVar22 + 1;
      }
    }
    if (iVar22 == 0) {
      trap(7);
    }
    unaff_s7 = (int)uVar26 / iVar22;
    *(byte *)param_4 = 0;
    if (iVar22 == 1) {
      uVar26 = 0;
    }
    piStack_1b8 = (int *)&bStack_118;
    iVar22 = 0;
    *(byte *)((int)param_4 + 1) = 0;
    *(byte *)((int)param_4 + 2) = 0;
    *(byte *)((int)param_4 + 3) = 0;
    *(byte *)(param_4 + 1) = 0;
    *(byte *)((int)param_4 + 5) = 0;
    *(byte *)((int)param_4 + 6) = 0;
    *(byte *)((int)param_4 + 7) = 0;
    *(byte *)(param_4 + 2) = 0;
    *(byte *)((int)param_4 + 9) = 0;
    *(byte *)((int)param_4 + 10) = 0;
    *(byte *)((int)param_4 + 0xb) = 0;
    piStack_160 = (int *)((uVar26 & 1) + unaff_s7);
    piStack_258 = piStack_1c0;
    piStack_250 = param_2;
    iVar25 = ssl_get_handshake_digest(0);
    piVar39 = piStack_160;
    iStack_1cc = iStack_14c;
    while (piStack_160 = piVar39, iStack_14c = iStack_1cc, iVar25 != 0) {
      if ((iStack_138 << 10 & (uint)unaff_s0) != 0) {
        if (iStack_134 == 0) {
          piStack_250 = (int *)0x146;
          piStack_198 = (int *)0x114;
          piStack_258 = (int *)0x11c;
          (**(code **)(puStack_170 + -0x6eb0))(0x14,0x11c,0x146,&DAT_00647bcc);
        }
        else {
          uStack_178 = 0xc;
          uStack_180 = 0;
          uStack_184 = 0;
          uStack_188 = 0;
          uStack_18c = 0;
          puStack_194 = unaff_s8;
          piStack_258 = unaff_s2;
          piStack_198 = piVar24;
          iStack_190 = iStack_168;
          piStack_17c = piStack_1b8;
          iVar25 = tls1_P_hash_constprop_2();
          piStack_250 = piVar39;
          iStack_1cc = iStack_14c;
          if (iVar25 != 0) {
            unaff_s2 = (int *)((int)unaff_s2 + unaff_s7);
            bVar1 = *(byte *)((int)param_4 + 3) ^ bStack_115;
            in_t3 = (uint)bVar1;
            in_t2 = (uint)(*(byte *)(param_4 + 1) ^ bStack_114);
            bVar21 = *(byte *)((int)param_4 + 5) ^ bStack_113;
            in_t1 = (uint)bVar21;
            *(byte *)param_4 = *(byte *)param_4 ^ bStack_118;
            *(byte *)((int)param_4 + 1) = *(byte *)((int)param_4 + 1) ^ bStack_117;
            *(byte *)((int)param_4 + 9) = *(byte *)((int)param_4 + 9) ^ bStack_10f;
            *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) ^ bStack_116;
            *(byte *)((int)param_4 + 3) = bVar1;
            *(byte *)(param_4 + 1) = *(byte *)(param_4 + 1) ^ bStack_114;
            *(byte *)((int)param_4 + 5) = bVar21;
            *(byte *)((int)param_4 + 6) = *(byte *)((int)param_4 + 6) ^ bStack_112;
            *(byte *)((int)param_4 + 7) = *(byte *)((int)param_4 + 7) ^ bStack_111;
            *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) ^ bStack_110;
            *(byte *)((int)param_4 + 10) = *(byte *)((int)param_4 + 10) ^ bStack_10e;
            *(byte *)((int)param_4 + 0xb) = *(byte *)((int)param_4 + 0xb) ^ bStack_10d;
            goto LAB_0049af98;
          }
        }
        (**(code **)(puStack_170 + -0x7fac))(puStack_154);
        goto LAB_0049afd0;
      }
LAB_0049af98:
      iVar22 = iVar22 + 1;
      piStack_258 = piStack_1c0;
      piStack_250 = param_2;
      iVar25 = ssl_get_handshake_digest(iVar22);
      piVar39 = piStack_160;
      iStack_1cc = iStack_14c;
    }
    (**(code **)(puStack_170 + -0x7fac))(puStack_154);
    param_3 = param_4;
    if (iStack_15c == 0) {
      iStack_1cc = 0xc;
      goto LAB_0049afd0;
    }
  }
  iStack_1cc = 0;
  param_4 = param_3;
LAB_0049afd0:
  if (piStack_8c == *ppiStack_158) {
    return iStack_1cc;
  }
  pcStack_1ac = tls1_mac;
  piStack_26c = piStack_8c;
  (**(code **)(puStack_170 + -0x5328))();
  puStack_25c = PTR___stack_chk_guard_006aabf0;
  puStack_220 = &_gp;
  iStack_1d4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar22 = piStack_26c[0x16];
  puStack_268 = (uint *)(iVar22 + 0x10c);
  if (piStack_250 == (int *)0x0) {
    puVar51 = (undefined *)piStack_26c[0x21];
    puStack_270 = (undefined4 *)(iVar22 + 8);
    uStack_260 = piStack_26c[0x1f] & 1;
  }
  else {
    puVar51 = (undefined *)piStack_26c[0x24];
    puStack_268 = (uint *)(iVar22 + 0x130);
    puStack_270 = (undefined4 *)(iVar22 + 0x54);
    uStack_260 = piStack_26c[0x1f] & 2;
  }
  piStack_1d0 = unaff_s0;
  piStack_1c8 = unaff_s2;
  piStack_1c4 = param_2;
  piStack_1bc = param_4;
  iStack_1b4 = unaff_s7;
  puStack_1b0 = unaff_s8;
  uVar23 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(puVar51);
  iStack_208 = (**(code **)(puStack_220 + -0x6fb4))(uVar23);
  if (iStack_208 < 0) {
    uStack_214 = iStack_208;
    (**(code **)(puStack_220 + -0x7194))(&DAT_00647bcc,0x3d3,"t >= 0");
    iStack_208 = uStack_214;
  }
  puStack_264 = puVar51;
  if (uStack_260 == 0) {
    puStack_264 = auStack_204;
    (**(code **)(puStack_220 + -0x6e2c))(puStack_264,puVar51);
  }
  iVar22 = *piStack_26c;
  if ((iVar22 == 0xfeff) || (iVar22 == 0x100)) {
    if (piStack_250 == (int *)0x0) {
      uVar2 = *(undefined2 *)(piStack_26c[0x17] + 0x208);
      uVar37 = (undefined)((ushort)uVar2 >> 8);
    }
    else {
      uVar2 = *(undefined2 *)(piStack_26c[0x17] + 0x20a);
      uVar37 = (undefined)((ushort)uVar2 >> 8);
    }
    auStack_1ec = (undefined  [4])CONCAT13(uVar37,CONCAT12((char)uVar2,SUB42(auStack_1ec,0)));
    bVar1 = *(byte *)((int)puStack_270 + 6);
    in_t0 = (uint)bVar1;
    uVar33 = *(uint *)((int)puStack_270 + 2);
    cVar31 = *(char *)((int)puStack_270 + 7);
    puVar51 = auStack_1ec + 2;
    uVar26 = (uint)puVar51 & 3;
    *(uint *)(puVar51 + -uVar26) =
         *(uint *)(puVar51 + -uVar26) & -1 << (4 - uVar26) * 8 | uVar33 >> uVar26 * 8;
    puVar51 = auStack_1e8 + 1;
    uVar26 = (uint)puVar51 & 3;
    *(uint *)(puVar51 + -uVar26) =
         *(uint *)(puVar51 + -uVar26) & 0xffffffffU >> (uVar26 + 1) * 8 | uVar33 << (3 - uVar26) * 8
    ;
    auStack_1e8 = (undefined  [4])CONCAT31(CONCAT21(auStack_1e8._0_2_,bVar1),cVar31);
    uStack_1e0 = auStack_1e8;
    uStack_1e4 = auStack_1ec;
  }
  else {
    uStack_1e4 = *puStack_270;
    uStack_1e0 = puStack_270[1];
  }
  uStack_214 = puStack_268[1];
  uStack_254 = *puStack_268;
  iStack_210 = iStack_208;
  puVar42 = (undefined4 *)(uStack_254 & 0xff);
  *puStack_268 = (uint)puVar42;
  uStack_1dc = (undefined)uStack_254;
  uStack_1db = (undefined)((uint)iVar22 >> 8);
  uStack_1da = (undefined)iVar22;
  uStack_1d9 = (undefined)(uStack_214 >> 8);
  uStack_1d8 = (undefined)uStack_214;
  puVar43 = &uStack_1e4;
  if (((piStack_250 == (int *)0x0) &&
      (puStack_20c = &uStack_1e4, uVar26 = (**(code **)(puStack_220 + -0x6cb0))(piStack_26c[0x20]),
      puVar43 = puStack_20c, (uVar26 & 0xf0007) == 2)) &&
     (iVar22 = ssl3_cbc_record_digest_supported(puStack_264,puStack_20c), puVar43 = puStack_20c,
     iVar22 != 0)) {
    uStack_224 = 0;
    iStack_22c = piStack_26c[0x16] + 0x14;
    uStack_228 = *(undefined4 *)(piStack_26c[0x16] + 0x10);
    pcVar50 = (char *)&iStack_208;
    iStack_230 = uStack_214 + iStack_210 + (uStack_254 >> 8);
    iStack_234 = puStack_268[1] + iStack_208;
    uStack_238 = puStack_268[4];
    puVar42 = puStack_20c;
    ssl3_cbc_digest_record(puStack_264,piStack_258);
  }
  else {
    (**(code **)(puStack_220 + -0x786c))(puStack_264,puVar43,0xd);
    (**(code **)(puStack_220 + -0x786c))(puStack_264,puStack_268[4],puStack_268[1]);
    pcVar50 = (char *)&iStack_208;
    iVar22 = (**(code **)(puStack_220 + -0x7914))(puStack_264,piStack_258);
    if (iVar22 < 1) {
      pcVar50 = "t > 0";
      (**(code **)(puStack_220 + -0x7194))(&DAT_00647bcc,0x40d);
    }
  }
  if (uStack_260 == 0) {
    (**(code **)(puStack_220 + -0x7fac))(auStack_204);
  }
  if (((*piStack_26c != 0xfeff) && (*piStack_26c != 0x100)) &&
     ((((cVar31 = *(char *)((int)puStack_270 + 7) + '\x01', *(char *)((int)puStack_270 + 7) = cVar31
        , cVar31 == '\0' &&
        ((cVar31 = *(char *)((int)puStack_270 + 6) + '\x01',
         *(char *)((int)puStack_270 + 6) = cVar31, cVar31 == '\0' &&
         (cVar31 = *(char *)((int)puStack_270 + 5) + '\x01',
         *(char *)((int)puStack_270 + 5) = cVar31, cVar31 == '\0')))) &&
       (cVar31 = *(char *)(puStack_270 + 1), *(char *)(puStack_270 + 1) = cVar31 + '\x01',
       (char)(cVar31 + '\x01') == '\0')) &&
      (((cVar31 = *(char *)((int)puStack_270 + 3) + '\x01', *(char *)((int)puStack_270 + 3) = cVar31
        , cVar31 == '\0' &&
        (cVar31 = *(char *)((int)puStack_270 + 2) + '\x01', *(char *)((int)puStack_270 + 2) = cVar31
        , cVar31 == '\0')) &&
       (cVar31 = *(char *)((int)puStack_270 + 1) + '\x01', *(char *)((int)puStack_270 + 1) = cVar31,
       cVar31 == '\0')))))) {
    *(char *)puStack_270 = *(char *)puStack_270 + '\x01';
  }
  if (iStack_1d4 == *(int *)puStack_25c) {
    return iStack_208;
  }
  pcStack_24c = tls1_generate_master_secret;
  iVar22 = iStack_1d4;
  (**(code **)(puStack_220 + -0x5328))();
  puVar51 = PTR___stack_chk_guard_006aabf0;
  uStack_274 = *(uint *)PTR___stack_chk_guard_006aabf0;
  puVar43 = puVar42;
  uVar26 = ssl_get_algorithm2();
  iVar52 = *(int *)(iVar22 + 0xc0);
  iVar27 = 0;
  iVar25 = *(int *)(iVar22 + 0x58) + 0xc0;
  puVar28 = (uint *)(iVar52 + 0x14);
  iVar22 = 0;
  while (iVar29 = ssl_get_handshake_digest(iVar27,&iStack_2ac,&iStack_2a8), iVar29 != 0) {
    iVar27 = iVar27 + 1;
    if ((iStack_2ac << 10 & uVar26) != 0) {
      iVar22 = iVar22 + 1;
    }
  }
  if (iVar22 == 0) {
    trap(7);
  }
  iVar27 = (int)puVar42 / iVar22;
  if (iVar22 == 1) {
    puVar42 = (undefined4 *)0x0;
  }
  (*(code *)PTR_memset_006aab00)(puVar28,0,0x30);
  iVar22 = 0;
  pcStack_2c0 = "master secret";
  piVar24 = &iStack_2ac;
  piVar39 = &iStack_2a8;
  iVar29 = ssl_get_handshake_digest(0);
  do {
    if (iVar29 == 0) {
LAB_0049b79c:
      if (uStack_274 == *(uint *)puVar51) {
        return 0x30;
      }
      uVar26 = uStack_274;
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      puVar42 = puVar43;
      iVar22 = (*(code *)PTR_CRYPTO_malloc_006a8108)(piVar39,&DAT_00647bcc,0x471);
      if (iVar22 == 0) {
        iVar25 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
      }
      else {
        iVar25 = uStack_300 + 0x40;
        if (iStack_2f4 == 0) {
          iVar52 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar25,&DAT_00647bcc,0x47f);
          iVar27 = iVar25;
        }
        else {
          iVar27 = uStack_2f8 + 2 + iVar25;
          iVar52 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar27,&DAT_00647bcc,0x47f);
        }
        if (iVar52 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
          (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
          return 0;
        }
        uVar40 = uStack_300;
        (*(code *)PTR_memcpy_006aabf4)(iVar52);
        puVar32 = (uint *)(iVar52 + uStack_300);
        iVar35 = *(int *)(uVar26 + 0x58);
        puVar28 = (uint *)(iVar52 + uStack_300 + 0x20);
        uVar49 = *(uint *)(iVar35 + 0xc0);
        uVar33 = iVar35 + 0xc4U & 3;
        uVar3 = iVar35 + 200U & 3;
        uVar4 = iVar35 + 0xccU & 3;
        uVar5 = iVar35 + 0xd0U & 3;
        uVar6 = iVar35 + 0xd4U & 3;
        uVar7 = iVar35 + 0xd8U & 3;
        iVar29 = *(int *)((iVar35 + 0xd8U) - uVar7);
        uVar8 = iVar35 + 0xdcU & 3;
        iVar9 = *(int *)((iVar35 + 0xdcU) - uVar8);
        uVar12 = iVar35 + 199U & 3;
        uVar48 = (*(int *)((iVar35 + 0xc4U) - uVar33) << uVar33 * 8 |
                 in_t3 & 0xffffffffU >> (4 - uVar33) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)((iVar35 + 199U) - uVar12) >> (3 - uVar12) * 8;
        uVar33 = iVar35 + 0xcbU & 3;
        uVar47 = (*(int *)((iVar35 + 200U) - uVar3) << uVar3 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar33 + 1) * 8 |
                 *(uint *)((iVar35 + 0xcbU) - uVar33) >> (3 - uVar33) * 8;
        uVar33 = iVar35 + 0xcfU & 3;
        uVar46 = (*(int *)((iVar35 + 0xccU) - uVar4) << uVar4 * 8 |
                 in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar33 + 1) * 8 |
                 *(uint *)((iVar35 + 0xcfU) - uVar33) >> (3 - uVar33) * 8;
        uVar33 = iVar35 + 0xd3U & 3;
        uVar45 = (*(int *)((iVar35 + 0xd0U) - uVar5) << uVar5 * 8 |
                 in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar33 + 1) * 8 |
                 *(uint *)((iVar35 + 0xd3U) - uVar33) >> (3 - uVar33) * 8;
        uVar33 = iVar35 + 0xd7U & 3;
        uVar44 = (*(int *)((iVar35 + 0xd4U) - uVar6) << uVar6 * 8 |
                 (uint)puVar42 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar33 + 1) * 8 |
                 *(uint *)((iVar35 + 0xd7U) - uVar33) >> (3 - uVar33) * 8;
        uVar33 = iVar35 + 0xdbU & 3;
        uVar4 = *(uint *)((iVar35 + 0xdbU) - uVar33);
        uVar3 = iVar35 + 0xdfU & 3;
        uVar5 = *(uint *)((iVar35 + 0xdfU) - uVar3);
        *puVar32 = uVar49;
        puVar32[1] = uVar48;
        puVar32[2] = uVar47;
        puVar32[3] = uVar46;
        puVar32[4] = uVar45;
        puVar32[5] = uVar44;
        puVar32[6] = (iVar29 << uVar7 * 8 | uVar40 & 0xffffffffU >> (4 - uVar7) * 8) &
                     -1 << (uVar33 + 1) * 8 | uVar4 >> (3 - uVar33) * 8;
        puVar32[7] = (iVar9 << uVar8 * 8 | (uint)puVar43 & 0xffffffffU >> (4 - uVar8) * 8) &
                     -1 << (uVar3 + 1) * 8 | uVar5 >> (3 - uVar3) * 8;
        iVar36 = *(int *)(uVar26 + 0x58);
        uVar33 = iVar36 + 0xa0U & 3;
        uVar3 = iVar36 + 0xa4U & 3;
        iVar29 = *(int *)((iVar36 + 0xa4U) - uVar3);
        uVar4 = iVar36 + 0xa8U & 3;
        iVar9 = *(int *)((iVar36 + 0xa8U) - uVar4);
        uVar5 = iVar36 + 0xacU & 3;
        iVar35 = *(int *)((iVar36 + 0xacU) - uVar5);
        uVar6 = iVar36 + 0xb0U & 3;
        iVar10 = *(int *)((iVar36 + 0xb0U) - uVar6);
        uVar7 = iVar36 + 0xb4U & 3;
        iVar11 = *(int *)((iVar36 + 0xb4U) - uVar7);
        uVar8 = iVar36 + 0xa3U & 3;
        uVar12 = iVar36 + 0xa7U & 3;
        uVar16 = *(uint *)((iVar36 + 0xa7U) - uVar12);
        uVar40 = iVar36 + 0xabU & 3;
        uVar17 = *(uint *)((iVar36 + 0xabU) - uVar40);
        uVar13 = iVar36 + 0xafU & 3;
        uVar18 = *(uint *)((iVar36 + 0xafU) - uVar13);
        uVar14 = iVar36 + 0xb3U & 3;
        uVar19 = *(uint *)((iVar36 + 0xb3U) - uVar14);
        uVar15 = iVar36 + 0xb7U & 3;
        uVar20 = *(uint *)((iVar36 + 0xb7U) - uVar15);
        uVar41 = *(uint *)(iVar36 + 0xb8);
        uVar38 = *(uint *)(iVar36 + 0xbc);
        *puVar28 = (*(int *)((iVar36 + 0xa0U) - uVar33) << uVar33 * 8 |
                   uVar49 & 0xffffffffU >> (4 - uVar33) * 8) & -1 << (uVar8 + 1) * 8 |
                   *(uint *)((iVar36 + 0xa3U) - uVar8) >> (3 - uVar8) * 8;
        puVar28[1] = (iVar29 << uVar3 * 8 | uVar48 & 0xffffffffU >> (4 - uVar3) * 8) &
                     -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
        puVar28[2] = (iVar9 << uVar4 * 8 | uVar47 & 0xffffffffU >> (4 - uVar4) * 8) &
                     -1 << (uVar40 + 1) * 8 | uVar17 >> (3 - uVar40) * 8;
        puVar28[3] = (iVar35 << uVar5 * 8 | uVar46 & 0xffffffffU >> (4 - uVar5) * 8) &
                     -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
        puVar28[4] = (iVar10 << uVar6 * 8 | uVar45 & 0xffffffffU >> (4 - uVar6) * 8) &
                     -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
        puVar28[5] = (iVar11 << uVar7 * 8 | uVar44 & 0xffffffffU >> (4 - uVar7) * 8) &
                     -1 << (uVar15 + 1) * 8 | uVar20 >> (3 - uVar15) * 8;
        puVar28[6] = uVar41;
        puVar28[7] = uVar38;
        if (iStack_2f4 != 0) {
          *(char *)(iVar52 + iVar25) = (char)((uint)uStack_2f8 >> 8);
          *(undefined *)((int)puVar32 + 0x41) = (undefined)uStack_2f8;
          if ((uStack_2f8 != 0) || (iStack_2fc != 0)) {
            (*(code *)PTR_memcpy_006aabf4)(iVar52 + uStack_300 + 0x42,iStack_2fc,uStack_2f8);
          }
        }
        iVar25 = (*(code *)PTR_memcmp_006aabd8)(iVar52,"client finished",0xf);
        if (((iVar25 == 0) ||
            (iVar25 = (*(code *)PTR_memcmp_006aabd8)(iVar52,"server finished",0xf), iVar25 == 0)) ||
           ((iVar25 = (*(code *)PTR_memcmp_006aabd8)(iVar52,"master secret",0xd), iVar25 == 0 ||
            (iVar25 = (*(code *)PTR_memcmp_006aabd8)(iVar52,"key expansion",0xd), iVar25 == 0)))) {
          iVar25 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x16f,&DAT_00647bcc,0x4b1);
        }
        else {
          iVar25 = tls1_PRF_constprop_1
                             (*(undefined4 *)(*(int *)(*(int *)(uVar26 + 0x58) + 0x344) + 0x24),
                              iVar52,iVar27,0,0,0,0,0,0,*(int *)(uVar26 + 0xc0) + 0x14,
                              *(undefined4 *)(*(int *)(uVar26 + 0xc0) + 0x10),piVar24,iVar22,piVar39
                             );
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar52);
      }
      return iVar25;
    }
    if ((iStack_2ac << 10 & uVar26) != 0) {
      if (iStack_2a8 == 0) {
        piVar39 = (int *)0x146;
        puVar43 = (undefined4 *)&DAT_00647bcc;
        uStack_300 = 0x114;
        piVar24 = (int *)0x11c;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14);
        goto LAB_0049b79c;
      }
      uStack_2f8 = 0x20;
      iStack_2f4 = 0;
      uStack_300 = 0xd;
      piVar24 = (int *)pcVar50;
      piVar39 = (int *)(((uint)puVar42 & 1) + iVar27);
      puVar43 = (undefined4 *)pcStack_2c0;
      iVar29 = tls1_P_hash_constprop_2();
      iStack_2fc = iVar25;
      if (iVar29 == 0) goto LAB_0049b79c;
      pcVar50 = (char *)((int)pcVar50 + iVar27);
      puVar32 = &uStack_2a4;
      puVar34 = puVar28;
      if (((uint)puVar28 & 3) == 0 &&
          ((uint *)(iVar52 + 0x18) <= &uStack_2a4 || &uStack_2a0 <= puVar28)) {
        *(uint *)(iVar52 + 0x14) = *(uint *)(iVar52 + 0x14) ^ uStack_2a4;
        *(uint *)(iVar52 + 0x18) = uStack_2a0 ^ *(uint *)(iVar52 + 0x18);
        puVar43 = (undefined4 *)(uStack_28c ^ *(uint *)(iVar52 + 0x2c));
        in_t3 = uStack_290 ^ *(uint *)(iVar52 + 0x28);
        *(uint *)(iVar52 + 0x1c) = uStack_29c ^ *(uint *)(iVar52 + 0x1c);
        *(uint *)(iVar52 + 0x20) = uStack_298 ^ *(uint *)(iVar52 + 0x20);
        *(uint *)(iVar52 + 0x24) = uStack_294 ^ *(uint *)(iVar52 + 0x24);
        *(uint *)(iVar52 + 0x28) = in_t3;
        *(undefined4 **)(iVar52 + 0x2c) = puVar43;
        *(uint *)(iVar52 + 0x30) = uStack_288 ^ *(uint *)(iVar52 + 0x30);
        *(uint *)(iVar52 + 0x38) = uStack_280 ^ *(uint *)(iVar52 + 0x38);
        *(uint *)(iVar52 + 0x34) = uStack_284 ^ *(uint *)(iVar52 + 0x34);
        *(uint *)(iVar52 + 0x3c) = uStack_27c ^ *(uint *)(iVar52 + 0x3c);
        *(uint *)(iVar52 + 0x40) = *(uint *)(iVar52 + 0x40) ^ uStack_278;
      }
      else {
        do {
          puVar30 = (uint *)((int)puVar32 + 1);
          *(byte *)puVar34 = *(byte *)puVar34 ^ *(byte *)puVar32;
          puVar32 = puVar30;
          puVar34 = (uint *)((int)puVar34 + 1);
        } while (puVar30 != &uStack_274);
      }
    }
    iVar22 = iVar22 + 1;
    piVar24 = &iStack_2ac;
    piVar39 = &iStack_2a8;
    iVar29 = ssl_get_handshake_digest(iVar22);
  } while( true );
}

