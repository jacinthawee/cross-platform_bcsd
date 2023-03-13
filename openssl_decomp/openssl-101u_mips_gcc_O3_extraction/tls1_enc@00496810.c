
/* WARNING: Could not reconcile some variable overlaps */

uint * tls1_enc(int *param_1,uint **param_2,char *param_3,uint **param_4)

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
  undefined4 uVar24;
  uint *puVar25;
  uint **ppuVar26;
  int iVar27;
  uint uVar28;
  uint **ppuVar29;
  int iVar30;
  uint *puVar31;
  undefined4 uVar32;
  char cVar34;
  uint *puVar33;
  undefined uVar39;
  uint uVar35;
  uint *puVar36;
  int iVar37;
  int iVar38;
  uint uVar40;
  char *pcVar41;
  int *piVar42;
  uint uVar43;
  uint uVar44;
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
  int iVar51;
  uint **unaff_s5;
  undefined *puVar52;
  int unaff_s6;
  uint *unaff_s7;
  code *pcVar53;
  uint **unaff_s8;
  uint **ppuVar54;
  int iVar55;
  uint uStack_368;
  int iStack_364;
  undefined4 uStack_360;
  int iStack_35c;
  char *pcStack_328;
  int iStack_314;
  int iStack_310;
  uint uStack_30c;
  uint uStack_308;
  uint uStack_304;
  uint uStack_300;
  uint uStack_2fc;
  uint uStack_2f8;
  uint uStack_2f4;
  uint uStack_2f0;
  uint uStack_2ec;
  uint uStack_2e8;
  uint uStack_2e4;
  uint uStack_2e0;
  uint uStack_2dc;
  uint **ppuStack_2d8;
  int *piStack_2d4;
  uint **ppuStack_2d0;
  uint uStack_2cc;
  undefined *puStack_2c8;
  undefined *puStack_2c4;
  int *piStack_2c0;
  uint *puStack_2bc;
  uint **ppuStack_2b8;
  code *pcStack_2b4;
  uint *puStack_2a0;
  int iStack_29c;
  uint *puStack_298;
  int iStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  undefined *puStack_288;
  uint *puStack_27c;
  uint *puStack_278;
  uint **ppuStack_274;
  uint *puStack_270;
  undefined auStack_26c [24];
  undefined auStack_254 [4];
  undefined auStack_250 [4];
  uint *puStack_24c;
  uint *puStack_248;
  undefined uStack_244;
  undefined uStack_243;
  undefined uStack_242;
  undefined uStack_241;
  undefined uStack_240;
  int iStack_23c;
  uint *puStack_238;
  uint **ppuStack_234;
  uint *puStack_230;
  uint **ppuStack_22c;
  int *piStack_228;
  uint **ppuStack_224;
  uint **ppuStack_220;
  uint *puStack_21c;
  uint **ppuStack_218;
  code *pcStack_214;
  uint **ppuStack_200;
  undefined *puStack_1fc;
  int iStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  uint **ppuStack_1e4;
  undefined4 uStack_1e0;
  undefined *puStack_1d8;
  int iStack_1d0;
  undefined *puStack_1cc;
  uint **ppuStack_1c8;
  int iStack_1c4;
  int iStack_1c0;
  int **ppiStack_1bc;
  undefined *puStack_1b8;
  uint *puStack_1b4;
  uint **ppuStack_1ac;
  uint uStack_1a8;
  undefined4 uStack_1a4;
  int iStack_1a0;
  uint *puStack_19c;
  undefined auStack_198 [24];
  byte bStack_180;
  byte bStack_17f;
  byte bStack_17e;
  byte bStack_17d;
  byte bStack_17c;
  byte bStack_17b;
  byte bStack_17a;
  byte bStack_179;
  byte bStack_178;
  byte bStack_177;
  byte bStack_176;
  byte bStack_175;
  undefined auStack_174 [128];
  int *piStack_f4;
  uint **ppuStack_f0;
  uint **ppuStack_ec;
  uint *puStack_e8;
  uint **ppuStack_e4;
  undefined *puStack_e0;
  uint **ppuStack_dc;
  int iStack_d8;
  uint *puStack_d4;
  uint **ppuStack_d0;
  code *pcStack_cc;
  uint **ppuStack_c0;
  undefined4 uStack_b8;
  undefined *puStack_b0;
  uint *puStack_a8;
  uint *apuStack_a4 [6];
  uint **ppuStack_8c;
  uint **ppuStack_84;
  int *piStack_80;
  uint *puStack_7c;
  uint **ppuStack_78;
  undefined *puStack_74;
  uint **ppuStack_70;
  code *pcStack_6c;
  undefined4 local_58;
  undefined *local_50;
  undefined local_48 [4];
  undefined local_44 [8];
  uint *local_3c;
  uint *local_38;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  uint **local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_50 = &_gp;
  local_2c = *(uint ***)PTR___stack_chk_guard_006a9ae8;
  ppuStack_22c = param_2;
  if (param_2 == (uint **)0x0) {
    iVar23 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1[0x21]);
    if (iVar23 != 0) {
      uVar24 = (**(code **)(local_50 + -0x78e0))(param_1[0x21]);
      iVar23 = (**(code **)(local_50 + -0x6fa4))(uVar24);
      if (iVar23 < 0) {
        param_3 = "n >= 0";
        ppuStack_22c = (uint **)0x307;
        (**(code **)(local_50 + -0x7184))(&DAT_0064760c);
      }
    }
    puStack_230 = (uint *)param_1[0x20];
    ppuStack_f0 = (uint **)(param_1[0x16] + 0x10c);
    if (puStack_230 != (uint *)0x0) {
      unaff_s6 = (**(code **)(local_50 + -0x6cf4))(puStack_230);
      goto LAB_00496990;
    }
LAB_004968d8:
    pcVar53 = *(code **)(local_50 + -0x52ec);
LAB_004968dc:
    param_3 = (char *)ppuStack_f0[1];
    ppuStack_22c = (uint **)ppuStack_f0[4];
    (*pcVar53)(ppuStack_f0[3]);
    puVar25 = (uint *)0x1;
    ppuStack_f0[4] = ppuStack_f0[3];
  }
  else {
    iVar23 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(param_1[0x24]);
    if (iVar23 != 0) {
      uVar24 = (**(code **)(local_50 + -0x78e0))(param_1[0x24]);
      iVar23 = (**(code **)(local_50 + -0x6fa4))(uVar24);
      if (iVar23 < 0) {
        param_3 = "n >= 0";
        ppuStack_22c = (uint **)0x2e8;
        (**(code **)(local_50 + -0x7184))(&DAT_0064760c);
      }
    }
    unaff_s5 = (uint **)param_1[0x16];
    puStack_230 = (uint *)param_1[0x23];
    ppuStack_f0 = unaff_s5 + 0x4c;
    if (puStack_230 == (uint *)0x0) goto LAB_004968d8;
    unaff_s6 = (**(code **)(local_50 + -0x6cf4))(puStack_230);
    if ((0x301 < *param_1) &&
       (uVar28 = (**(code **)(local_50 + -0x789c))(unaff_s6), (uVar28 & 0xf0007) == 2)) {
      ppuStack_22c = (uint **)(**(code **)(local_50 + -0x7890))(unaff_s6);
      if (1 < (int)ppuStack_22c) {
        if (unaff_s5[0x4f] != unaff_s5[0x50]) {
          local_58 = 0x2ff;
          param_4 = (uint **)&DAT_0064760c;
          param_3 = "%s:%d: rec->data != rec->input\n";
          ppuStack_22c = (uint **)0x1;
          (**(code **)(local_50 + -0x5460))(**(undefined4 **)(local_50 + -0x52e8));
          goto LAB_00496990;
        }
        iVar23 = (**(code **)(local_50 + -0x786c))();
        if (0 < iVar23) goto LAB_00496990;
LAB_00496e58:
        puVar25 = (uint *)0xffffffff;
        goto LAB_004968fc;
      }
LAB_00496990:
      pcVar53 = *(code **)(local_50 + -0x52ec);
      if (param_1[0x30] != 0) goto LAB_0049699c;
      goto LAB_004968dc;
    }
    if (param_1[0x30] == 0) goto LAB_004968d8;
LAB_0049699c:
    if (unaff_s6 == 0) goto LAB_004968d8;
    unaff_s8 = (uint **)ppuStack_f0[1];
    unaff_s5 = (uint **)(**(code **)(local_50 + -0x6cf0))(*puStack_230);
    iVar23 = (**(code **)(local_50 + -0x789c))(*puStack_230);
    if (iVar23 << 10 < 0) {
      iVar23 = *param_1;
      if (param_2 == (uint **)0x0) {
        ppuVar26 = (uint **)(param_1[0x16] + 8);
        if ((iVar23 == 0xfeff) || (iVar23 == 0x100)) {
          uVar2 = *(undefined2 *)(param_1[0x17] + 0x208);
          uVar39 = (undefined)((ushort)uVar2 >> 8);
          goto LAB_004969f8;
        }
LAB_00496c60:
        local_3c = *ppuVar26;
        local_38 = ppuVar26[1];
        cVar34 = *(char *)((int)ppuVar26 + 7) + '\x01';
        *(char *)((int)ppuVar26 + 7) = cVar34;
        if ((cVar34 == '\0') &&
           (((((cVar34 = *(char *)((int)ppuVar26 + 6) + '\x01',
               *(char *)((int)ppuVar26 + 6) = cVar34, cVar34 == '\0' &&
               (cVar34 = *(char *)((int)ppuVar26 + 5) + '\x01',
               *(char *)((int)ppuVar26 + 5) = cVar34, cVar34 == '\0')) &&
              (cVar34 = *(char *)(ppuVar26 + 1), *(char *)(ppuVar26 + 1) = cVar34 + '\x01',
              (char)(cVar34 + '\x01') == '\0')) &&
             ((cVar34 = *(char *)((int)ppuVar26 + 3) + '\x01', *(char *)((int)ppuVar26 + 3) = cVar34
              , cVar34 == '\0' &&
              (cVar34 = *(char *)((int)ppuVar26 + 2) + '\x01', *(char *)((int)ppuVar26 + 2) = cVar34
              , cVar34 == '\0')))) &&
            (cVar34 = *(char *)((int)ppuVar26 + 1) + '\x01', *(char *)((int)ppuVar26 + 1) = cVar34,
            cVar34 == '\0')))) {
          *(char *)ppuVar26 = *(char *)ppuVar26 + '\x01';
        }
        iVar23 = *param_1;
      }
      else {
        ppuVar26 = (uint **)(param_1[0x16] + 0x54);
        if ((iVar23 != 0xfeff) && (iVar23 != 0x100)) goto LAB_00496c60;
        uVar2 = *(undefined2 *)(param_1[0x17] + 0x20a);
        uVar39 = (undefined)((ushort)uVar2 >> 8);
LAB_004969f8:
        bVar1 = *(byte *)((int)ppuVar26 + 6);
        in_t0 = (uint)bVar1;
        cVar34 = *(char *)((int)ppuVar26 + 7);
        uVar35 = *(uint *)((int)ppuVar26 + 2);
        local_3c = (uint *)CONCAT13(uVar39,CONCAT12((char)uVar2,SUB42(local_48,0)));
        local_48 = (undefined  [4])local_3c;
        puVar52 = local_48 + 2;
        uVar28 = (uint)puVar52 & 3;
        *(uint *)(puVar52 + -uVar28) =
             *(uint *)(puVar52 + -uVar28) & -1 << (4 - uVar28) * 8 | uVar35 >> uVar28 * 8;
        puVar52 = local_44 + 1;
        uVar28 = (uint)puVar52 & 3;
        *(uint *)(puVar52 + -uVar28) =
             *(uint *)(puVar52 + -uVar28) & 0xffffffffU >> (uVar28 + 1) * 8 |
             uVar35 << (3 - uVar28) * 8;
        local_44._0_4_ = (uint *)CONCAT31(CONCAT21(local_44._0_2_,bVar1),cVar34);
        local_38 = local_44._0_4_;
      }
      param_4 = &local_3c;
      local_32 = (undefined)iVar23;
      param_3 = &DAT_0000000d;
      ppuStack_22c = (uint **)&DAT_00000016;
      local_33 = (undefined)((uint)iVar23 >> 8);
      local_34 = SUB41(*ppuStack_f0,0);
      local_30 = SUB41(ppuStack_f0[1],0);
      local_31 = (undefined)((uint)ppuStack_f0[1] >> 8);
      unaff_s7 = (uint *)(**(code **)(local_50 + -0x6bec))(puStack_230);
      if ((int)unaff_s7 < 1) goto LAB_00496e58;
      if (param_2 != (uint **)0x0) {
        ppuVar26 = (uint **)((int)unaff_s8 + (int)unaff_s7);
        ppuStack_f0[1] = (uint *)((int)ppuStack_f0[1] + (int)unaff_s7);
        unaff_s8 = ppuVar26;
        if (param_2 != (uint **)0x0) goto LAB_00496ab8;
      }
LAB_00496a9c:
      puVar25 = (uint *)0x0;
      ppuVar26 = unaff_s8;
      if (unaff_s8 != (uint **)0x0) {
LAB_00496aa4:
        if (unaff_s5 == (uint **)0x0) {
          trap(7);
        }
        puVar25 = (uint *)0x0;
        unaff_s8 = ppuVar26;
        if ((uint)ppuVar26 % (uint)unaff_s5 == 0) {
LAB_00496ab8:
          pcVar53 = *(code **)(local_50 + -0x6cec);
          unaff_s8 = ppuVar26;
          goto LAB_00496abc;
        }
      }
    }
    else if (unaff_s5 == (uint **)0x1) {
      unaff_s7 = (uint *)0x0;
      if (param_2 == (uint **)0x0) goto LAB_00496a9c;
      pcVar53 = *(code **)(local_50 + -0x6cec);
LAB_00496abc:
      param_3 = (char *)ppuStack_f0[4];
      ppuStack_22c = (uint **)ppuStack_f0[3];
      param_4 = unaff_s8;
      uVar28 = (*pcVar53)(puStack_230);
      iVar23 = (**(code **)(local_50 + -0x789c))(*puStack_230);
      if (iVar23 << 0xb < 0) {
        puStack_230 = (uint *)(uVar28 >> 0x1f);
      }
      else {
        puStack_230 = (uint *)(uint)(uVar28 == 0);
      }
      if (puStack_230 != (uint *)0x0) goto LAB_00496e58;
      uVar28 = (**(code **)(local_50 + -0x789c))(unaff_s6);
      if ((uVar28 & 0xf0007) == 6) {
        pcVar53 = *(code **)(local_50 + -0x78e0);
        if (param_2 == (uint **)0x0) {
          ppuStack_f0[3] = ppuStack_f0[3] + 2;
          ppuStack_f0[4] = ppuStack_f0[4] + 2;
          ppuStack_f0[1] = ppuStack_f0[1] + -2;
        }
      }
      else {
        pcVar53 = *(code **)(local_50 + -0x78e0);
      }
      iVar23 = (*pcVar53)(param_1[0x21]);
      if (iVar23 == 0) {
        ppuVar26 = (uint **)0x0;
      }
      else {
        uVar24 = (**(code **)(local_50 + -0x78e0))(param_1[0x21]);
        ppuVar26 = (uint **)(**(code **)(local_50 + -0x6fa4))(uVar24);
      }
      if (unaff_s5 == (uint **)0x1) {
        if (unaff_s7 == (uint *)0x0) goto LAB_00496b64;
        puVar25 = (uint *)0x1;
        if (param_2 == (uint **)0x0) goto LAB_00496c3c;
      }
      else if (param_2 == (uint **)0x0) {
        ppuStack_22c = ppuStack_f0;
        param_3 = (char *)unaff_s5;
        puVar25 = (uint *)tls1_cbc_remove_padding(param_1);
        param_4 = ppuVar26;
        if (unaff_s7 != (uint *)0x0) {
LAB_00496c3c:
          unaff_s7 = (uint *)((int)ppuStack_f0[1] - (int)unaff_s7);
          ppuStack_f0[1] = unaff_s7;
        }
      }
      else {
LAB_00496b64:
        puVar25 = (uint *)0x1;
      }
    }
    else {
      if (param_2 != (uint **)0x0) {
        if (unaff_s5 == (uint **)0x0) {
          trap(7);
        }
        iVar27 = (int)unaff_s5 - (int)unaff_s8 % (int)unaff_s5;
        iVar23 = iVar27 + -1;
        if (((param_1[0x40] & 0x200U) != 0) && ((*(uint *)param_1[0x16] & 8) != 0)) {
          iVar23 = iVar27;
        }
        ppuVar26 = (uint **)((int)unaff_s8 + iVar27);
        if ((int)unaff_s8 < (int)ppuVar26) {
          do {
            puVar52 = (undefined *)((int)ppuStack_f0[4] + (int)unaff_s8);
            unaff_s8 = (uint **)((int)unaff_s8 + 1);
            *puVar52 = (char)iVar23;
          } while (ppuVar26 != unaff_s8);
        }
        unaff_s7 = (uint *)0x0;
        ppuStack_f0[1] = (uint *)((int)ppuStack_f0[1] + iVar27);
        goto LAB_00496ab8;
      }
      unaff_s7 = (uint *)0x0;
      ppuVar26 = unaff_s8;
      if (unaff_s8 != (uint **)0x0) goto LAB_00496aa4;
      puVar25 = (uint *)0x0;
    }
  }
LAB_004968fc:
  if (local_2c == *(uint ***)puStack_74) {
    return puVar25;
  }
  pcStack_6c = tls1_cert_verify_mac;
  ppuStack_ec = local_2c;
  (**(code **)(local_50 + -0x5330))();
  piStack_228 = (int *)PTR___stack_chk_guard_006a9ae8;
  puVar25 = ppuStack_ec[0x16];
  puStack_b0 = &_gp;
  ppuStack_1c8 = *(uint ***)PTR___stack_chk_guard_006a9ae8;
  ppuStack_2b8 = (uint **)param_3;
  ppuStack_8c = ppuStack_1c8;
  ppuStack_84 = ppuStack_f0;
  piStack_80 = param_1;
  puStack_7c = puStack_230;
  ppuStack_78 = param_2;
  ppuStack_70 = unaff_s5;
  if (puVar25[0x5e] == 0) {
LAB_00496ed4:
    ppuStack_f0 = (uint **)0x0;
    puStack_230 = (uint *)&DAT_00000018;
    puVar52 = puStack_b0;
LAB_00496ee4:
    if (*(int *)(puVar25[0x5f] + (int)ppuStack_f0) == 0) {
LAB_00496f18:
      ppuStack_f0 = ppuStack_f0 + 1;
      if (ppuStack_f0 == (uint **)&DAT_00000018) goto LAB_00496f24;
      puVar25 = ppuStack_ec[0x16];
      goto LAB_00496ee4;
    }
    uVar24 = (**(code **)(puVar52 + -0x78e0))();
    ppuVar26 = (uint **)(**(code **)(puStack_b0 + -0x7a14))(uVar24);
    puVar52 = puStack_b0;
    if (ppuVar26 != ppuStack_22c) goto LAB_00496f18;
    ppuStack_f0 = (uint **)(ppuStack_ec[0x16][0x5f] + (int)ppuStack_f0);
    ppuStack_ec = (uint **)*ppuStack_f0;
    if (ppuStack_ec != (uint **)0x0) {
      ppuStack_f0 = apuStack_a4;
      (**(code **)(puStack_b0 + -0x7fc4))(ppuStack_f0);
      ppuStack_1c8 = ppuStack_ec;
      iVar23 = (**(code **)(puStack_b0 + -0x6cdc))(ppuStack_f0);
      if (iVar23 < 1) {
LAB_00496ff4:
        puStack_a8 = (uint *)0x0;
      }
      else {
        ppuStack_2b8 = &puStack_a8;
        ppuStack_1c8 = (uint **)param_3;
        iVar23 = (**(code **)(puStack_b0 + -0x785c))(ppuStack_f0);
        if (iVar23 < 1) goto LAB_00496ff4;
      }
      (**(code **)(puStack_b0 + -0x7fac))(ppuStack_f0);
      puVar25 = puStack_a8;
      goto LAB_00496f50;
    }
LAB_00496f24:
    ppuStack_2b8 = (uint **)0x144;
    param_4 = (uint **)&DAT_0064760c;
    uStack_b8 = 0x399;
    ppuStack_1c8 = (uint **)0x11e;
    (**(code **)(puVar52 + -0x6eac))(0x14);
    puVar25 = (uint *)0x0;
  }
  else {
    puVar25 = (uint *)ssl3_digest_cached_records();
    if (puVar25 != (uint *)0x0) {
      puVar25 = ppuStack_ec[0x16];
      goto LAB_00496ed4;
    }
  }
LAB_00496f50:
  if (ppuStack_8c == (uint **)*piStack_228) {
    return puVar25;
  }
  pcStack_cc = tls1_final_finish_mac;
  ppuVar54 = ppuStack_8c;
  (**(code **)(puStack_b0 + -0x5330))();
  ppiStack_1bc = (int **)PTR___stack_chk_guard_006a9ae8;
  piStack_2c0 = *(int **)PTR___stack_chk_guard_006a9ae8;
  puStack_e0 = (undefined *)piStack_228;
  puStack_1d8 = &_gp;
  ppuVar26 = param_4;
  piStack_f4 = piStack_2c0;
  puStack_e8 = puStack_230;
  ppuStack_e4 = ppuStack_22c;
  ppuStack_dc = (uint **)param_3;
  iStack_d8 = unaff_s6;
  puStack_d4 = unaff_s7;
  ppuStack_d0 = unaff_s8;
  ppuStack_c0 = ppuStack_2b8;
  ppuStack_220 = param_4;
  if ((ppuVar54[0x16][0x5e] == 0) ||
     (iVar23 = ssl3_digest_cached_records(), ppuStack_234 = ppuVar54, iVar23 != 0)) {
    puStack_1b8 = auStack_198;
    puVar52 = auStack_174;
    puStack_1cc = puVar52;
    (**(code **)(puStack_1d8 + -0x7fc4))(puStack_1b8);
    iVar23 = 0;
    iStack_1c0 = 0;
    iStack_1d0 = 0;
    while (iVar27 = ssl_get_handshake_digest(iVar23,&uStack_1a8,&uStack_1a4), iVar27 != 0) {
      uVar28 = ssl_get_algorithm2(ppuVar54);
      if ((uVar28 & uStack_1a8) == 0) {
        iVar23 = iVar23 + 1;
      }
      else {
        ppuVar29 = (uint **)(**(code **)(puStack_1d8 + -0x6fa4))(uStack_1a4);
        if (((*(int *)(ppuVar54[0x16][0x5f] + iVar23 * 4) == 0) || ((int)ppuVar29 < 0)) ||
           (0x80 - iStack_1d0 < (int)ppuVar29)) {
          iVar23 = iVar23 + 1;
          iStack_1c0 = 1;
        }
        else {
          iVar27 = (**(code **)(puStack_1d8 + -0x6cdc))(puStack_1b8);
          if (((iVar27 == 0) ||
              (iVar27 = (**(code **)(puStack_1d8 + -0x785c))(puStack_1b8,puVar52,&ppuStack_1ac),
              iVar27 == 0)) || (ppuVar26 = ppuStack_1ac, ppuStack_1ac != ppuVar29)) {
            iStack_1c0 = 1;
            ppuVar26 = ppuVar29;
          }
          puVar52 = puVar52 + (int)ppuVar26;
          iVar23 = iVar23 + 1;
          iStack_1d0 = (int)puVar52 - (int)puStack_1cc;
        }
      }
    }
    ppuStack_22c = &puStack_19c;
    ppuStack_234 = (uint **)ssl_get_algorithm2(ppuVar54);
    piStack_228 = &iStack_1a0;
    unaff_s7 = (uint *)0x0;
    puStack_230 = ppuVar54[0x30] + 5;
    ppuVar54 = (uint **)ppuVar54[0x30][4];
    iVar23 = 0;
    while (puStack_238 = (uint *)ssl_get_handshake_digest(unaff_s7,piStack_228,ppuStack_22c),
          unaff_s8 = ppuStack_c0, puStack_238 != (uint *)0x0) {
      unaff_s7 = (uint *)((int)unaff_s7 + 1);
      if ((iStack_1a0 << 10 & (uint)ppuStack_234) != 0) {
        iVar23 = iVar23 + 1;
      }
    }
    if (iVar23 == 0) {
      ppuStack_2b8 = (uint **)0x44;
      ppuVar29 = (uint **)&DAT_0064760c;
      ppuStack_200 = (uint **)0x10a;
      (**(code **)(puStack_1d8 + -0x6eac))(0x14,0x11c);
      unaff_s8 = ppuVar54;
LAB_0049748c:
      param_3 = (char *)&bStack_180;
      (**(code **)(puStack_1d8 + -0x7fac))(puStack_1b8);
      (**(code **)(puStack_1d8 + -0x7d6c))(puStack_1cc,iStack_1d0);
      piStack_2c0 = (int *)&SUB_0000000c;
      (**(code **)(puStack_1d8 + -0x7d6c))(param_3);
    }
    else {
      if (iVar23 == 0) {
        trap(7);
      }
      iStack_1c4 = (int)ppuVar54 / iVar23;
      *(undefined *)param_4 = 0;
      if (iVar23 == 1) {
        ppuVar54 = (uint **)0x0;
      }
      unaff_s7 = (uint *)0x0;
      *(undefined *)((int)param_4 + 1) = 0;
      *(undefined *)((int)param_4 + 2) = 0;
      *(undefined *)((int)param_4 + 3) = 0;
      *(undefined *)(param_4 + 1) = 0;
      param_3 = (char *)&bStack_180;
      *(undefined *)((int)param_4 + 5) = 0;
      *(undefined *)((int)param_4 + 6) = 0;
      *(undefined *)((int)param_4 + 7) = 0;
      *(undefined *)(param_4 + 2) = 0;
      *(undefined *)((int)param_4 + 9) = 0;
      *(undefined *)((int)param_4 + 10) = 0;
      *(undefined *)((int)param_4 + 0xb) = 0;
      ppuStack_220 = (uint **)(((uint)ppuVar54 & 1) + iStack_1c4);
      ppuStack_2b8 = ppuStack_22c;
      puStack_1b4 = puStack_238;
      iVar23 = ssl_get_handshake_digest(0,piStack_228);
      ppuVar29 = ppuStack_1c8;
      puStack_238 = puStack_1b4;
      while (ppuStack_1c8 = ppuVar29, puStack_1b4 = puStack_238, iVar23 != 0) {
        if ((iStack_1a0 << 10 & (uint)ppuStack_234) != 0) {
          if (puStack_19c == (uint *)0x0) {
            ppuStack_2b8 = (uint **)0x146;
            ppuVar29 = (uint **)&DAT_0064760c;
            ppuStack_200 = (uint **)0x115;
            (**(code **)(puStack_1d8 + -0x6eac))(0x14,0x11c);
            goto LAB_0049748c;
          }
          uStack_1e8 = 0;
          uStack_1e0 = 0xc;
          uStack_1ec = 0;
          uStack_1f0 = 0;
          uStack_1f4 = 0;
          ppuStack_200 = unaff_s8;
          ppuStack_2b8 = ppuStack_220;
          puStack_1fc = puStack_1cc;
          iStack_1f8 = iStack_1d0;
          ppuStack_1e4 = (uint **)param_3;
          iVar23 = tls1_P_hash_constprop_2(puStack_19c,puStack_230);
          puStack_238 = puStack_1b4;
          if (iVar23 == 0) goto LAB_0049748c;
          puStack_230 = (uint *)((int)puStack_230 + iStack_1c4);
          bVar1 = *(byte *)((int)param_4 + 3) ^ bStack_17d;
          in_t3 = (uint)bVar1;
          bVar21 = *(byte *)((int)param_4 + 6) ^ bStack_17a;
          ppuVar26 = (uint **)(uint)bVar21;
          in_t2 = (uint)(*(byte *)(param_4 + 1) ^ bStack_17c);
          bVar22 = *(byte *)((int)param_4 + 5) ^ bStack_17b;
          in_t1 = (uint)bVar22;
          *(byte *)param_4 = *(byte *)param_4 ^ bStack_180;
          *(byte *)((int)param_4 + 1) = *(byte *)((int)param_4 + 1) ^ bStack_17f;
          *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) ^ bStack_17e;
          *(byte *)((int)param_4 + 3) = bVar1;
          *(byte *)(param_4 + 1) = *(byte *)(param_4 + 1) ^ bStack_17c;
          *(byte *)((int)param_4 + 5) = bVar22;
          *(byte *)((int)param_4 + 6) = bVar21;
          *(byte *)((int)param_4 + 7) = *(byte *)((int)param_4 + 7) ^ bStack_179;
          *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) ^ bStack_178;
          *(byte *)((int)param_4 + 9) = *(byte *)((int)param_4 + 9) ^ bStack_177;
          *(byte *)((int)param_4 + 10) = *(byte *)((int)param_4 + 10) ^ bStack_176;
          *(byte *)((int)param_4 + 0xb) = *(byte *)((int)param_4 + 0xb) ^ bStack_175;
        }
        unaff_s7 = (uint *)((int)unaff_s7 + 1);
        ppuStack_2b8 = ppuStack_22c;
        iVar23 = ssl_get_handshake_digest(unaff_s7,piStack_228);
        ppuVar29 = ppuStack_1c8;
        puStack_238 = puStack_1b4;
      }
      (**(code **)(puStack_1d8 + -0x7fac))(puStack_1b8);
      (**(code **)(puStack_1d8 + -0x7d6c))(puStack_1cc,iStack_1d0);
      piStack_2c0 = (int *)&SUB_0000000c;
      (**(code **)(puStack_1d8 + -0x7d6c))(param_3);
      if (iStack_1c0 != 0) goto LAB_00497418;
      puStack_238 = (uint *)0xc;
      ppuVar29 = ppuVar26;
    }
  }
  else {
LAB_00497418:
    puStack_238 = (uint *)0x0;
    ppuVar29 = ppuVar26;
  }
  if (piStack_f4 == *ppiStack_1bc) {
    return puStack_238;
  }
  pcStack_214 = tls1_mac;
  piStack_2d4 = piStack_f4;
  (**(code **)(puStack_1d8 + -0x5330))();
  puStack_2c4 = PTR___stack_chk_guard_006a9ae8;
  puStack_288 = &_gp;
  iStack_23c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar23 = piStack_2d4[0x16];
  ppuStack_2d0 = (uint **)(iVar23 + 0x10c);
  if (ppuStack_2b8 == (uint **)0x0) {
    puVar52 = (undefined *)piStack_2d4[0x21];
    ppuStack_2d8 = (uint **)(iVar23 + 8);
    uStack_2cc = piStack_2d4[0x1f] & 1;
  }
  else {
    puVar52 = (undefined *)piStack_2d4[0x24];
    ppuStack_2d0 = (uint **)(iVar23 + 0x130);
    ppuStack_2d8 = (uint **)(iVar23 + 0x54);
    uStack_2cc = piStack_2d4[0x1f] & 2;
  }
  pcVar41 = (char *)ppuStack_2b8;
  ppuStack_224 = (uint **)param_3;
  puStack_21c = unaff_s7;
  ppuStack_218 = unaff_s8;
  uVar24 = (*(code *)PTR_EVP_MD_CTX_md_006a7500)(puVar52);
  puStack_270 = (uint *)(**(code **)(puStack_288 + -0x6fa4))(uVar24);
  if ((int)puStack_270 < 0) {
    pcVar41 = "t >= 0";
    puStack_27c = puStack_270;
    (**(code **)(puStack_288 + -0x7184))(&DAT_0064760c,0x3f4);
    puStack_270 = puStack_27c;
  }
  puStack_2c8 = puVar52;
  if (uStack_2cc == 0) {
    puStack_2c8 = auStack_26c;
    iVar23 = (**(code **)(puStack_288 + -0x6be0))(puStack_2c8,puVar52);
    if (iVar23 == 0) {
      puVar25 = (uint *)0xffffffff;
      goto LAB_0049788c;
    }
  }
  iVar23 = *piStack_2d4;
  if ((iVar23 == 0xfeff) || (iVar23 == 0x100)) {
    if (ppuStack_2b8 == (uint **)0x0) {
      uVar2 = *(undefined2 *)(piStack_2d4[0x17] + 0x208);
      uVar39 = (undefined)((ushort)uVar2 >> 8);
    }
    else {
      uVar2 = *(undefined2 *)(piStack_2d4[0x17] + 0x20a);
      uVar39 = (undefined)((ushort)uVar2 >> 8);
    }
    auStack_254 = (undefined  [4])CONCAT13(uVar39,CONCAT12((char)uVar2,SUB42(auStack_254,0)));
    bVar1 = *(byte *)((int)ppuStack_2d8 + 6);
    in_t0 = (uint)bVar1;
    uVar35 = *(uint *)((int)ppuStack_2d8 + 2);
    cVar34 = *(char *)((int)ppuStack_2d8 + 7);
    puVar52 = auStack_254 + 2;
    uVar28 = (uint)puVar52 & 3;
    *(uint *)(puVar52 + -uVar28) =
         *(uint *)(puVar52 + -uVar28) & -1 << (4 - uVar28) * 8 | uVar35 >> uVar28 * 8;
    puVar52 = auStack_250 + 1;
    uVar28 = (uint)puVar52 & 3;
    *(uint *)(puVar52 + -uVar28) =
         *(uint *)(puVar52 + -uVar28) & 0xffffffffU >> (uVar28 + 1) * 8 | uVar35 << (3 - uVar28) * 8
    ;
    auStack_250 = (undefined  [4])CONCAT31(CONCAT21(auStack_250._0_2_,bVar1),cVar34);
    puStack_248 = (uint *)auStack_250;
    puStack_24c = (uint *)auStack_254;
  }
  else {
    puStack_24c = *ppuStack_2d8;
    puStack_248 = ppuStack_2d8[1];
  }
  puStack_27c = ppuStack_2d0[1];
  unaff_s7 = *ppuStack_2d0;
  puStack_278 = puStack_270;
  ppuVar29 = (uint **)((uint)unaff_s7 & 0xff);
  *ppuStack_2d0 = (uint *)ppuVar29;
  uStack_244 = SUB41(unaff_s7,0);
  uStack_243 = (undefined)((uint)iVar23 >> 8);
  uStack_242 = (undefined)iVar23;
  uStack_241 = (undefined)((uint)puStack_27c >> 8);
  uStack_240 = SUB41(puStack_27c,0);
  if (((ppuStack_2b8 == (uint **)0x0) &&
      (ppuStack_274 = &puStack_24c, uVar28 = (**(code **)(puStack_288 + -0x6cd8))(piStack_2d4[0x20])
      , (uVar28 & 0xf0007) == 2)) &&
     (iVar23 = ssl3_cbc_record_digest_supported(puStack_2c8,ppuStack_274), iVar23 != 0)) {
    in_t0 = (uint)unaff_s7 >> 8;
    uStack_28c = 0;
    iStack_294 = piStack_2d4[0x16] + 0x14;
    uStack_290 = *(undefined4 *)(piStack_2d4[0x16] + 0x10);
    unaff_s7 = (uint *)((int)puStack_27c + (int)puStack_278 + in_t0);
    pcVar41 = (char *)&puStack_270;
    iStack_29c = (int)ppuStack_2d0[1] + (int)puStack_270;
    puStack_2a0 = ppuStack_2d0[4];
    ppuVar29 = ppuStack_274;
    puStack_298 = unaff_s7;
    iVar23 = ssl3_cbc_digest_record(puStack_2c8,piStack_2c0);
joined_r0x004976bc:
    if (0 < iVar23) {
      if (uStack_2cc == 0) {
        (**(code **)(puStack_288 + -0x7fac))(auStack_26c);
      }
      puVar25 = puStack_270;
      if (((*piStack_2d4 != 0xfeff) && (*piStack_2d4 != 0x100)) &&
         ((((cVar34 = *(char *)((int)ppuStack_2d8 + 7) + '\x01',
            *(char *)((int)ppuStack_2d8 + 7) = cVar34, cVar34 == '\0' &&
            ((cVar34 = *(char *)((int)ppuStack_2d8 + 6) + '\x01',
             *(char *)((int)ppuStack_2d8 + 6) = cVar34, cVar34 == '\0' &&
             (cVar34 = *(char *)((int)ppuStack_2d8 + 5) + '\x01',
             *(char *)((int)ppuStack_2d8 + 5) = cVar34, cVar34 == '\0')))) &&
           (cVar34 = *(char *)(ppuStack_2d8 + 1), *(char *)(ppuStack_2d8 + 1) = cVar34 + '\x01',
           (char)(cVar34 + '\x01') == '\0')) &&
          (((cVar34 = *(char *)((int)ppuStack_2d8 + 3) + '\x01',
            *(char *)((int)ppuStack_2d8 + 3) = cVar34, cVar34 == '\0' &&
            (cVar34 = *(char *)((int)ppuStack_2d8 + 2) + '\x01',
            *(char *)((int)ppuStack_2d8 + 2) = cVar34, cVar34 == '\0')) &&
           (cVar34 = *(char *)((int)ppuStack_2d8 + 1) + '\x01',
           *(char *)((int)ppuStack_2d8 + 1) = cVar34, cVar34 == '\0')))))) {
        *(char *)ppuStack_2d8 = *(char *)ppuStack_2d8 + '\x01';
      }
      goto LAB_0049788c;
    }
  }
  else {
    pcVar41 = &DAT_0000000d;
    iVar23 = (**(code **)(puStack_288 + -0x7860))(puStack_2c8);
    if (0 < iVar23) {
      pcVar41 = (char *)ppuStack_2d0[1];
      iVar23 = (**(code **)(puStack_288 + -0x7860))(puStack_2c8,ppuStack_2d0[4]);
      if (0 < iVar23) {
        pcVar41 = (char *)&puStack_270;
        iVar23 = (**(code **)(puStack_288 + -0x7910))(puStack_2c8,piStack_2c0);
        goto joined_r0x004976bc;
      }
    }
  }
  if (uStack_2cc == 0) {
    (**(code **)(puStack_288 + -0x7fac))(auStack_26c);
  }
  puVar25 = (uint *)0xffffffff;
LAB_0049788c:
  if (iStack_23c == *(int *)puStack_2c4) {
    return puVar25;
  }
  pcStack_2b4 = tls1_generate_master_secret;
  iVar23 = iStack_23c;
  (**(code **)(puStack_288 + -0x5330))();
  puVar52 = PTR___stack_chk_guard_006a9ae8;
  uStack_2dc = *(uint *)PTR___stack_chk_guard_006a9ae8;
  ppuVar26 = ppuVar29;
  puStack_2bc = unaff_s7;
  uVar28 = ssl_get_algorithm2();
  iVar55 = *(int *)(iVar23 + 0xc0);
  iVar51 = 0;
  iVar27 = *(int *)(iVar23 + 0x58) + 0xc0;
  puVar25 = (uint *)(iVar55 + 0x14);
  iVar23 = 0;
  while (iVar30 = ssl_get_handshake_digest(iVar51,&iStack_314,&iStack_310), iVar30 != 0) {
    iVar51 = iVar51 + 1;
    if ((iStack_314 << 10 & uVar28) != 0) {
      iVar23 = iVar23 + 1;
    }
  }
  if (iVar23 == 0) {
    piVar42 = (int *)0x44;
    ppuVar26 = (uint **)&DAT_0064760c;
    uStack_368 = 0x10a;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11c);
  }
  else {
    if (iVar23 == 0) {
      trap(7);
    }
    iVar51 = (int)ppuVar29 / iVar23;
    if (iVar23 == 1) {
      ppuVar29 = (uint **)0x0;
    }
    (*(code *)PTR_memset_006a99f4)(puVar25,0,0x30);
    iVar23 = 0;
    pcStack_328 = "master secret";
    piVar42 = &iStack_310;
    iVar30 = ssl_get_handshake_digest(0,&iStack_314);
    while (iVar30 != 0) {
      if ((iStack_314 << 10 & uVar28) != 0) {
        if (iStack_310 == 0) {
          piVar42 = (int *)0x146;
          ppuVar26 = (uint **)&DAT_0064760c;
          uStack_368 = 0x115;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x11c);
          break;
        }
        uStack_360 = 0x20;
        iStack_35c = 0;
        uStack_368 = 0xd;
        piVar42 = (int *)(((uint)ppuVar29 & 1) + iVar51);
        ppuVar26 = (uint **)pcStack_328;
        iVar30 = tls1_P_hash_constprop_2(iStack_310,pcVar41);
        iStack_364 = iVar27;
        if (iVar30 == 0) break;
        pcVar41 = (char *)((int)pcVar41 + iVar51);
        puVar33 = &uStack_30c;
        puVar36 = puVar25;
        if (((uint)puVar25 & 3) == 0 &&
            ((uint *)(iVar55 + 0x18) <= &uStack_30c || &uStack_308 <= puVar25)) {
          *(uint *)(iVar55 + 0x14) = *(uint *)(iVar55 + 0x14) ^ uStack_30c;
          *(uint *)(iVar55 + 0x18) = uStack_308 ^ *(uint *)(iVar55 + 0x18);
          ppuVar26 = (uint **)(uStack_2f4 ^ *(uint *)(iVar55 + 0x2c));
          in_t3 = uStack_2f8 ^ *(uint *)(iVar55 + 0x28);
          *(uint *)(iVar55 + 0x1c) = uStack_304 ^ *(uint *)(iVar55 + 0x1c);
          *(uint *)(iVar55 + 0x20) = uStack_300 ^ *(uint *)(iVar55 + 0x20);
          *(uint *)(iVar55 + 0x24) = uStack_2fc ^ *(uint *)(iVar55 + 0x24);
          *(uint *)(iVar55 + 0x28) = in_t3;
          *(uint ***)(iVar55 + 0x2c) = ppuVar26;
          *(uint *)(iVar55 + 0x30) = uStack_2f0 ^ *(uint *)(iVar55 + 0x30);
          *(uint *)(iVar55 + 0x38) = uStack_2e8 ^ *(uint *)(iVar55 + 0x38);
          *(uint *)(iVar55 + 0x34) = uStack_2ec ^ *(uint *)(iVar55 + 0x34);
          *(uint *)(iVar55 + 0x3c) = uStack_2e4 ^ *(uint *)(iVar55 + 0x3c);
          *(uint *)(iVar55 + 0x40) = *(uint *)(iVar55 + 0x40) ^ uStack_2e0;
        }
        else {
          do {
            puVar31 = (uint *)((int)puVar33 + 1);
            *(byte *)puVar36 = *(byte *)puVar36 ^ *(byte *)puVar33;
            puVar33 = puVar31;
            puVar36 = (uint *)((int)puVar36 + 1);
          } while (puVar31 != &uStack_2dc);
        }
      }
      iVar23 = iVar23 + 1;
      piVar42 = &iStack_310;
      iVar30 = ssl_get_handshake_digest(iVar23,&iStack_314);
    }
  }
  uVar24 = 0x30;
  (*(code *)PTR_OPENSSL_cleanse_006a7074)(&uStack_30c);
  if (uStack_2dc == *(uint *)puVar52) {
    return (uint *)0x30;
  }
  uVar28 = uStack_2dc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppuVar54 = ppuVar26;
  iVar23 = (*(code *)PTR_CRYPTO_malloc_006a7008)(piVar42,&DAT_0064760c,0x4a2);
  if (iVar23 == 0) {
    puVar25 = (uint *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
  }
  else {
    iVar27 = uStack_368 + 0x40;
    if (iStack_35c == 0) {
      iVar55 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar27,&DAT_0064760c,0x4b0);
      iVar51 = iVar27;
    }
    else {
      iVar51 = uStack_360 + 2 + iVar27;
      iVar55 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar51,&DAT_0064760c,0x4b0);
    }
    if (iVar55 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x41,&DAT_0064760c,0x4ec);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar23);
      return (uint *)0x0;
    }
    uVar43 = uStack_368;
    (*(code *)PTR_memcpy_006a9aec)(iVar55);
    puVar33 = (uint *)(iVar55 + uStack_368);
    iVar37 = *(int *)(uVar28 + 0x58);
    puVar25 = (uint *)(iVar55 + uStack_368 + 0x20);
    uVar50 = *(uint *)(iVar37 + 0xc0);
    uVar35 = iVar37 + 0xc4U & 3;
    uVar3 = iVar37 + 200U & 3;
    uVar4 = iVar37 + 0xccU & 3;
    uVar5 = iVar37 + 0xd0U & 3;
    uVar6 = iVar37 + 0xd4U & 3;
    uVar7 = iVar37 + 0xd8U & 3;
    iVar30 = *(int *)((iVar37 + 0xd8U) - uVar7);
    uVar8 = iVar37 + 0xdcU & 3;
    iVar9 = *(int *)((iVar37 + 0xdcU) - uVar8);
    uVar12 = iVar37 + 199U & 3;
    uVar49 = (*(int *)((iVar37 + 0xc4U) - uVar35) << uVar35 * 8 |
             in_t3 & 0xffffffffU >> (4 - uVar35) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)((iVar37 + 199U) - uVar12) >> (3 - uVar12) * 8;
    uVar35 = iVar37 + 0xcbU & 3;
    uVar48 = (*(int *)((iVar37 + 200U) - uVar3) << uVar3 * 8 |
             in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar35 + 1) * 8 |
             *(uint *)((iVar37 + 0xcbU) - uVar35) >> (3 - uVar35) * 8;
    uVar35 = iVar37 + 0xcfU & 3;
    uVar47 = (*(int *)((iVar37 + 0xccU) - uVar4) << uVar4 * 8 |
             in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar35 + 1) * 8 |
             *(uint *)((iVar37 + 0xcfU) - uVar35) >> (3 - uVar35) * 8;
    uVar35 = iVar37 + 0xd3U & 3;
    uVar46 = (*(int *)((iVar37 + 0xd0U) - uVar5) << uVar5 * 8 |
             in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar35 + 1) * 8 |
             *(uint *)((iVar37 + 0xd3U) - uVar35) >> (3 - uVar35) * 8;
    uVar35 = iVar37 + 0xd7U & 3;
    uVar45 = (*(int *)((iVar37 + 0xd4U) - uVar6) << uVar6 * 8 |
             (uint)ppuVar54 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar35 + 1) * 8 |
             *(uint *)((iVar37 + 0xd7U) - uVar35) >> (3 - uVar35) * 8;
    uVar35 = iVar37 + 0xdbU & 3;
    uVar4 = *(uint *)((iVar37 + 0xdbU) - uVar35);
    uVar3 = iVar37 + 0xdfU & 3;
    uVar5 = *(uint *)((iVar37 + 0xdfU) - uVar3);
    *puVar33 = uVar50;
    puVar33[1] = uVar49;
    puVar33[2] = uVar48;
    puVar33[3] = uVar47;
    puVar33[4] = uVar46;
    puVar33[5] = uVar45;
    puVar33[6] = (iVar30 << uVar7 * 8 | uVar43 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar35 + 1) * 8 | uVar4 >> (3 - uVar35) * 8;
    puVar33[7] = (iVar9 << uVar8 * 8 | (uint)ppuVar26 & 0xffffffffU >> (4 - uVar8) * 8) &
                 -1 << (uVar3 + 1) * 8 | uVar5 >> (3 - uVar3) * 8;
    iVar38 = *(int *)(uVar28 + 0x58);
    uVar35 = iVar38 + 0xa0U & 3;
    uVar3 = iVar38 + 0xa4U & 3;
    iVar30 = *(int *)((iVar38 + 0xa4U) - uVar3);
    uVar4 = iVar38 + 0xa8U & 3;
    iVar9 = *(int *)((iVar38 + 0xa8U) - uVar4);
    uVar5 = iVar38 + 0xacU & 3;
    iVar37 = *(int *)((iVar38 + 0xacU) - uVar5);
    uVar6 = iVar38 + 0xb0U & 3;
    iVar10 = *(int *)((iVar38 + 0xb0U) - uVar6);
    uVar7 = iVar38 + 0xb4U & 3;
    iVar11 = *(int *)((iVar38 + 0xb4U) - uVar7);
    uVar8 = iVar38 + 0xa3U & 3;
    uVar12 = iVar38 + 0xa7U & 3;
    uVar16 = *(uint *)((iVar38 + 0xa7U) - uVar12);
    uVar43 = iVar38 + 0xabU & 3;
    uVar17 = *(uint *)((iVar38 + 0xabU) - uVar43);
    uVar13 = iVar38 + 0xafU & 3;
    uVar18 = *(uint *)((iVar38 + 0xafU) - uVar13);
    uVar14 = iVar38 + 0xb3U & 3;
    uVar19 = *(uint *)((iVar38 + 0xb3U) - uVar14);
    uVar15 = iVar38 + 0xb7U & 3;
    uVar20 = *(uint *)((iVar38 + 0xb7U) - uVar15);
    uVar44 = *(uint *)(iVar38 + 0xb8);
    uVar40 = *(uint *)(iVar38 + 0xbc);
    *puVar25 = (*(int *)((iVar38 + 0xa0U) - uVar35) << uVar35 * 8 |
               uVar50 & 0xffffffffU >> (4 - uVar35) * 8) & -1 << (uVar8 + 1) * 8 |
               *(uint *)((iVar38 + 0xa3U) - uVar8) >> (3 - uVar8) * 8;
    puVar25[1] = (iVar30 << uVar3 * 8 | uVar49 & 0xffffffffU >> (4 - uVar3) * 8) &
                 -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
    puVar25[2] = (iVar9 << uVar4 * 8 | uVar48 & 0xffffffffU >> (4 - uVar4) * 8) &
                 -1 << (uVar43 + 1) * 8 | uVar17 >> (3 - uVar43) * 8;
    puVar25[3] = (iVar37 << uVar5 * 8 | uVar47 & 0xffffffffU >> (4 - uVar5) * 8) &
                 -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
    puVar25[4] = (iVar10 << uVar6 * 8 | uVar46 & 0xffffffffU >> (4 - uVar6) * 8) &
                 -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
    puVar25[5] = (iVar11 << uVar7 * 8 | uVar45 & 0xffffffffU >> (4 - uVar7) * 8) &
                 -1 << (uVar15 + 1) * 8 | uVar20 >> (3 - uVar15) * 8;
    puVar25[6] = uVar44;
    puVar25[7] = uVar40;
    if (iStack_35c != 0) {
      *(char *)(iVar55 + iVar27) = (char)((uint)uStack_360 >> 8);
      *(undefined *)((int)puVar33 + 0x41) = (undefined)uStack_360;
      if ((uStack_360 != 0) || (iStack_364 != 0)) {
        (*(code *)PTR_memcpy_006a9aec)(iVar55 + uStack_368 + 0x42,iStack_364,uStack_360);
      }
    }
    iVar27 = (*(code *)PTR_memcmp_006a9ad0)(iVar55,"client finished",0xf);
    if (((iVar27 == 0) ||
        (iVar27 = (*(code *)PTR_memcmp_006a9ad0)(iVar55,"server finished",0xf), iVar27 == 0)) ||
       ((iVar27 = (*(code *)PTR_memcmp_006a9ad0)(iVar55,"master secret",0xd), iVar27 == 0 ||
        (iVar27 = (*(code *)PTR_memcmp_006a9ad0)(iVar55,"key expansion",0xd), iVar27 == 0)))) {
      puVar25 = (uint *)0x0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13a,0x16f,&DAT_0064760c,0x4e8);
    }
    else {
      uVar32 = ssl_get_algorithm2(uVar28);
      puVar25 = (uint *)tls1_PRF_constprop_1
                                  (uVar32,iVar55,iVar51,0,0,0,0,0,0,*(int *)(uVar28 + 0xc0) + 0x14,
                                   *(undefined4 *)(*(int *)(uVar28 + 0xc0) + 0x10),uVar24,iVar23,
                                   piVar42);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar55,iVar51);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar23,piVar42);
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar23);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar55);
  }
  return puVar25;
}

