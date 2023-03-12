
/* WARNING: Could not reconcile some variable overlaps */

int tls1_enc(int *param_1,int *param_2,char *param_3,int *param_4)

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
  uint *puVar28;
  int iVar29;
  uint *puVar30;
  byte *pbVar31;
  char cVar33;
  uint *puVar32;
  undefined uVar38;
  uint uVar34;
  uint *puVar35;
  int iVar36;
  int iVar37;
  uint uVar39;
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
  char *pcVar50;
  undefined *puVar51;
  int *unaff_s5;
  int *piVar52;
  int unaff_s6;
  int unaff_s7;
  code *pcVar53;
  int *unaff_s8;
  int iVar54;
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
  undefined4 *puStack_2d8;
  int *piStack_2d4;
  uint *puStack_2d0;
  undefined *puStack_2cc;
  uint uStack_2c8;
  undefined *puStack_2c4;
  int *piStack_2c0;
  uint uStack_2bc;
  int *piStack_2b8;
  code *pcStack_2b4;
  uint uStack_2a0;
  int iStack_29c;
  int iStack_298;
  int iStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  undefined *puStack_288;
  uint uStack_27c;
  int iStack_278;
  undefined4 *puStack_274;
  int iStack_270;
  undefined auStack_26c [24];
  undefined auStack_254 [4];
  undefined auStack_250 [4];
  undefined4 uStack_24c;
  undefined4 uStack_248;
  undefined uStack_244;
  undefined uStack_243;
  undefined uStack_242;
  undefined uStack_241;
  undefined uStack_240;
  int iStack_23c;
  int *piStack_238;
  int iStack_234;
  int *piStack_230;
  int *piStack_22c;
  int *piStack_228;
  int *piStack_224;
  int *piStack_220;
  int iStack_21c;
  int *piStack_218;
  code *pcStack_214;
  int *piStack_200;
  int *piStack_1fc;
  int iStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  int *piStack_1e4;
  undefined4 uStack_1e0;
  undefined *puStack_1d8;
  int iStack_1d0;
  int *piStack_1cc;
  int *piStack_1c8;
  int iStack_1c4;
  int **ppiStack_1c0;
  undefined *puStack_1bc;
  int *piStack_1b8;
  int iStack_1b4;
  int iStack_1ac;
  uint uStack_1a8;
  undefined4 uStack_1a4;
  int iStack_1a0;
  int iStack_19c;
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
  int aiStack_174 [32];
  int *piStack_f4;
  int *piStack_f0;
  int iStack_ec;
  int *piStack_e8;
  int *piStack_e4;
  undefined *puStack_e0;
  int *piStack_dc;
  int iStack_d8;
  int iStack_d4;
  int *piStack_d0;
  code *pcStack_cc;
  int *piStack_c0;
  undefined4 uStack_b8;
  undefined *puStack_b0;
  int iStack_a8;
  int aiStack_a4 [6];
  int *piStack_8c;
  int *piStack_84;
  int *piStack_80;
  int *piStack_7c;
  int *piStack_78;
  undefined *puStack_74;
  int *piStack_70;
  code *pcStack_6c;
  undefined4 local_58;
  undefined *local_50;
  undefined local_48 [4];
  undefined local_44 [8];
  int local_3c;
  int local_38;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  int local_2c;
  
  puStack_74 = PTR___stack_chk_guard_006aabf0;
  local_50 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  piStack_22c = param_2;
  if (param_2 == (int *)0x0) {
    iVar22 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x21]);
    if (iVar22 != 0) {
      uVar23 = (**(code **)(local_50 + -0x78e4))(param_1[0x21]);
      iVar22 = (**(code **)(local_50 + -0x6fb4))(uVar23);
      if (iVar22 < 0) {
        param_3 = "n >= 0";
        piStack_22c = (int *)0x2dc;
        (**(code **)(local_50 + -0x7194))(&DAT_00647bcc);
      }
    }
    piVar24 = (int *)param_1[0x20];
    piStack_238 = (int *)(param_1[0x16] + 0x10c);
    if (piVar24 != (int *)0x0) {
      unaff_s6 = (**(code **)(local_50 + -0x6cc8))(piVar24);
      goto LAB_0049a5c4;
    }
LAB_0049a50c:
    pcVar53 = *(code **)(local_50 + -0x52e4);
LAB_0049a510:
    param_3 = (char *)piStack_238[1];
    piStack_22c = (int *)piStack_238[4];
    (*pcVar53)(piStack_238[3]);
    iVar22 = 1;
    piStack_238[4] = piStack_238[3];
    piStack_230 = piVar24;
  }
  else {
    iVar22 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1[0x24]);
    if (iVar22 != 0) {
      uVar23 = (**(code **)(local_50 + -0x78e4))(param_1[0x24]);
      iVar22 = (**(code **)(local_50 + -0x6fb4))(uVar23);
      if (iVar22 < 0) {
        param_3 = "n >= 0";
        piStack_22c = (int *)0x2b9;
        (**(code **)(local_50 + -0x7194))(&DAT_00647bcc);
      }
    }
    unaff_s5 = (int *)param_1[0x16];
    piStack_230 = (int *)param_1[0x23];
    piStack_238 = unaff_s5 + 0x4c;
    piVar24 = piStack_230;
    if (piStack_230 == (int *)0x0) goto LAB_0049a50c;
    unaff_s6 = (**(code **)(local_50 + -0x6cc8))(piStack_230);
    if ((0x301 < *param_1) &&
       (uVar26 = (**(code **)(local_50 + -0x6c70))(unaff_s6), (uVar26 & 0xf0007) == 2)) {
      piStack_22c = (int *)(**(code **)(local_50 + -0x7884))(unaff_s6);
      if (1 < (int)piStack_22c) {
        if (unaff_s5[0x4f] != unaff_s5[0x50]) {
          local_58 = 0x2d1;
          param_4 = (int *)&DAT_00647bcc;
          param_3 = "%s:%d: rec->data != rec->input\n";
          piStack_22c = (int *)0x1;
          (**(code **)(local_50 + -0x5454))(**(undefined4 **)(local_50 + -0x52e0));
          goto LAB_0049a5c4;
        }
        iVar22 = (**(code **)(local_50 + -0x719c))();
        if (0 < iVar22) goto LAB_0049a5c4;
LAB_0049aa84:
        iVar22 = -1;
        goto LAB_0049a530;
      }
LAB_0049a5c4:
      pcVar53 = *(code **)(local_50 + -0x52e4);
      if (param_1[0x30] != 0) goto LAB_0049a5d0;
      goto LAB_0049a510;
    }
    if (param_1[0x30] == 0) goto LAB_0049a50c;
LAB_0049a5d0:
    if (unaff_s6 == 0) goto LAB_0049a50c;
    unaff_s8 = (int *)piStack_238[1];
    unaff_s5 = (int *)(**(code **)(local_50 + -0x6cc4))(*piVar24);
    iVar22 = (**(code **)(local_50 + -0x6c70))(*piVar24);
    piStack_230 = piVar24;
    if (iVar22 << 10 < 0) {
      iVar22 = *param_1;
      if (param_2 == (int *)0x0) {
        piVar52 = (int *)(param_1[0x16] + 8);
        if ((iVar22 == 0xfeff) || (iVar22 == 0x100)) {
          uVar2 = *(undefined2 *)(param_1[0x17] + 0x208);
          uVar38 = (undefined)((ushort)uVar2 >> 8);
          goto LAB_0049a62c;
        }
LAB_0049a88c:
        local_3c = *piVar52;
        local_38 = piVar52[1];
        cVar33 = *(char *)((int)piVar52 + 7) + '\x01';
        *(char *)((int)piVar52 + 7) = cVar33;
        if ((cVar33 == '\0') &&
           (((((cVar33 = *(char *)((int)piVar52 + 6) + '\x01', *(char *)((int)piVar52 + 6) = cVar33,
               cVar33 == '\0' &&
               (cVar33 = *(char *)((int)piVar52 + 5) + '\x01', *(char *)((int)piVar52 + 5) = cVar33,
               cVar33 == '\0')) &&
              (cVar33 = *(char *)(piVar52 + 1), *(char *)(piVar52 + 1) = cVar33 + '\x01',
              (char)(cVar33 + '\x01') == '\0')) &&
             ((cVar33 = *(char *)((int)piVar52 + 3) + '\x01', *(char *)((int)piVar52 + 3) = cVar33,
              cVar33 == '\0' &&
              (cVar33 = *(char *)((int)piVar52 + 2) + '\x01', *(char *)((int)piVar52 + 2) = cVar33,
              cVar33 == '\0')))) &&
            (cVar33 = *(char *)((int)piVar52 + 1) + '\x01', *(char *)((int)piVar52 + 1) = cVar33,
            cVar33 == '\0')))) {
          *(char *)piVar52 = *(char *)piVar52 + '\x01';
        }
        iVar22 = *param_1;
      }
      else {
        piVar52 = (int *)(param_1[0x16] + 0x54);
        if ((iVar22 != 0xfeff) && (iVar22 != 0x100)) goto LAB_0049a88c;
        uVar2 = *(undefined2 *)(param_1[0x17] + 0x20a);
        uVar38 = (undefined)((ushort)uVar2 >> 8);
LAB_0049a62c:
        bVar1 = *(byte *)((int)piVar52 + 6);
        in_t0 = (uint)bVar1;
        cVar33 = *(char *)((int)piVar52 + 7);
        uVar34 = *(uint *)((int)piVar52 + 2);
        local_3c = CONCAT13(uVar38,CONCAT12((char)uVar2,SUB42(local_48,0)));
        local_48 = (undefined  [4])local_3c;
        puVar51 = local_48 + 2;
        uVar26 = (uint)puVar51 & 3;
        *(uint *)(puVar51 + -uVar26) =
             *(uint *)(puVar51 + -uVar26) & -1 << (4 - uVar26) * 8 | uVar34 >> uVar26 * 8;
        puVar51 = local_44 + 1;
        uVar26 = (uint)puVar51 & 3;
        *(uint *)(puVar51 + -uVar26) =
             *(uint *)(puVar51 + -uVar26) & 0xffffffffU >> (uVar26 + 1) * 8 |
             uVar34 << (3 - uVar26) * 8;
        local_44._0_4_ = CONCAT31(CONCAT21(local_44._0_2_,bVar1),cVar33);
        local_38 = local_44._0_4_;
      }
      param_4 = &local_3c;
      local_32 = (undefined)iVar22;
      param_3 = &DAT_0000000d;
      piStack_22c = (int *)&DAT_00000016;
      local_33 = (undefined)((uint)iVar22 >> 8);
      local_34 = (undefined)*piStack_238;
      local_30 = (undefined)piStack_238[1];
      local_31 = (undefined)((uint)piStack_238[1] >> 8);
      unaff_s7 = (**(code **)(local_50 + -0x6bc0))(piVar24);
      if (param_2 != (int *)0x0) {
        piVar52 = (int *)((int)unaff_s8 + unaff_s7);
        piStack_238[1] = piStack_238[1] + unaff_s7;
        unaff_s8 = piVar52;
        if (param_2 != (int *)0x0) goto LAB_0049a6e4;
      }
LAB_0049a6c8:
      iVar22 = 0;
      piVar52 = unaff_s8;
      if (unaff_s8 != (int *)0x0) {
LAB_0049a6d0:
        if (unaff_s5 == (int *)0x0) {
          trap(7);
        }
        iVar22 = 0;
        unaff_s8 = piVar52;
        if ((uint)piVar52 % (uint)unaff_s5 == 0) {
LAB_0049a6e4:
          pcVar53 = *(code **)(local_50 + -0x6e30);
          unaff_s8 = piVar52;
          goto LAB_0049a6e8;
        }
      }
    }
    else if (unaff_s5 == (int *)0x1) {
      unaff_s7 = 0;
      if (param_2 == (int *)0x0) goto LAB_0049a6c8;
      pcVar53 = *(code **)(local_50 + -0x6e30);
LAB_0049a6e8:
      param_3 = (char *)piStack_238[4];
      piStack_22c = (int *)piStack_238[3];
      param_4 = unaff_s8;
      piStack_230 = (int *)(*pcVar53)(piVar24);
      iVar22 = (**(code **)(local_50 + -0x6c70))(*piVar24);
      if (iVar22 << 0xb < 0) {
        uVar26 = (uint)piStack_230 >> 0x1f;
      }
      else {
        uVar26 = (uint)(piStack_230 == (int *)0x0);
      }
      if (uVar26 != 0) goto LAB_0049aa84;
      uVar26 = (**(code **)(local_50 + -0x6c70))(unaff_s6);
      if ((uVar26 & 0xf0007) == 6) {
        pcVar53 = *(code **)(local_50 + -0x78e4);
        if (param_2 == (int *)0x0) {
          piStack_238[3] = piStack_238[3] + 8;
          piStack_238[4] = piStack_238[4] + 8;
          piStack_238[1] = piStack_238[1] + -8;
        }
      }
      else {
        pcVar53 = *(code **)(local_50 + -0x78e4);
      }
      iVar22 = (*pcVar53)(param_1[0x21]);
      if (iVar22 == 0) {
        piVar24 = (int *)0x0;
      }
      else {
        uVar23 = (**(code **)(local_50 + -0x78e4))(param_1[0x21]);
        piVar24 = (int *)(**(code **)(local_50 + -0x6fb4))(uVar23);
      }
      if (unaff_s5 == (int *)0x1) {
        if (unaff_s7 == 0) goto LAB_0049a790;
        iVar22 = 1;
        if (param_2 == (int *)0x0) goto LAB_0049a868;
      }
      else if (param_2 == (int *)0x0) {
        piStack_22c = piStack_238;
        param_3 = (char *)unaff_s5;
        iVar22 = tls1_cbc_remove_padding(param_1);
        param_4 = piVar24;
        if (unaff_s7 != 0) {
LAB_0049a868:
          unaff_s7 = piStack_238[1] - unaff_s7;
          piStack_238[1] = unaff_s7;
        }
      }
      else {
LAB_0049a790:
        iVar22 = 1;
      }
    }
    else {
      if (param_2 != (int *)0x0) {
        if (unaff_s5 == (int *)0x0) {
          trap(7);
        }
        iVar25 = (int)unaff_s5 - (int)unaff_s8 % (int)unaff_s5;
        iVar22 = iVar25 + -1;
        if (((param_1[0x40] & 0x200U) != 0) && ((*(uint *)param_1[0x16] & 8) != 0)) {
          iVar22 = iVar25;
        }
        piVar52 = (int *)((int)unaff_s8 + iVar25);
        if ((int)unaff_s8 < (int)piVar52) {
          do {
            pbVar31 = (byte *)(piStack_238[4] + (int)unaff_s8);
            unaff_s8 = (int *)((int)unaff_s8 + 1);
            *pbVar31 = (byte)iVar22;
          } while (piVar52 != unaff_s8);
        }
        unaff_s7 = 0;
        piStack_238[1] = piStack_238[1] + iVar25;
        goto LAB_0049a6e4;
      }
      unaff_s7 = 0;
      piVar52 = unaff_s8;
      if (unaff_s8 != (int *)0x0) goto LAB_0049a6d0;
      iVar22 = 0;
    }
  }
LAB_0049a530:
  if (local_2c == *(int *)puStack_74) {
    return iVar22;
  }
  pcStack_6c = tls1_cert_verify_mac;
  iStack_ec = local_2c;
  (**(code **)(local_50 + -0x5328))();
  piStack_228 = (int *)PTR___stack_chk_guard_006aabf0;
  iVar22 = *(int *)(iStack_ec + 0x58);
  puStack_b0 = &_gp;
  piStack_1cc = *(int **)PTR___stack_chk_guard_006aabf0;
  piStack_8c = piStack_1cc;
  piStack_84 = piStack_238;
  piStack_80 = param_1;
  piStack_7c = piStack_230;
  piStack_78 = param_2;
  piStack_70 = unaff_s5;
  if (*(int *)(iVar22 + 0x178) == 0) {
LAB_0049ab00:
    piStack_238 = (int *)0x0;
    piStack_230 = (int *)&DAT_00000018;
    puVar51 = puStack_b0;
LAB_0049ab10:
    if (*(int *)(*(int *)(iVar22 + 0x17c) + (int)piStack_238) == 0) {
LAB_0049ab44:
      piStack_238 = piStack_238 + 1;
      if (piStack_238 == (int *)&DAT_00000018) goto LAB_0049ab50;
      iVar22 = *(int *)(iStack_ec + 0x58);
      goto LAB_0049ab10;
    }
    uVar23 = (**(code **)(puVar51 + -0x78e4))();
    piVar24 = (int *)(**(code **)(puStack_b0 + -0x7a14))(uVar23);
    puVar51 = puStack_b0;
    if (piVar24 != piStack_22c) goto LAB_0049ab44;
    piStack_238 = (int *)(*(int *)(*(int *)(iStack_ec + 0x58) + 0x17c) + (int)piStack_238);
    iStack_ec = *piStack_238;
    if (iStack_ec != 0) {
      piStack_238 = aiStack_a4;
      (**(code **)(puStack_b0 + -0x7fc4))(piStack_238);
      (**(code **)(puStack_b0 + -0x6cb4))(piStack_238,iStack_ec);
      piStack_2b8 = &iStack_a8;
      piStack_1cc = (int *)param_3;
      (**(code **)(puStack_b0 + -0x7868))(piStack_238);
      (**(code **)(puStack_b0 + -0x7fac))(piStack_238);
      iVar22 = iStack_a8;
      goto LAB_0049ab7c;
    }
LAB_0049ab50:
    piStack_2b8 = (int *)0x144;
    param_4 = (int *)&DAT_00647bcc;
    uStack_b8 = 0x377;
    piStack_1cc = (int *)0x11e;
    (**(code **)(puVar51 + -0x6eb0))(0x14);
    iVar22 = 0;
  }
  else {
    piStack_2b8 = (int *)param_3;
    iVar22 = ssl3_digest_cached_records();
    if (iVar22 != 0) {
      iVar22 = *(int *)(iStack_ec + 0x58);
      goto LAB_0049ab00;
    }
  }
LAB_0049ab7c:
  if (piStack_8c == (int *)*piStack_228) {
    return iVar22;
  }
  pcStack_cc = tls1_final_finish_mac;
  piVar24 = piStack_8c;
  (**(code **)(puStack_b0 + -0x5328))();
  ppiStack_1c0 = (int **)PTR___stack_chk_guard_006aabf0;
  piStack_2c0 = *(int **)PTR___stack_chk_guard_006aabf0;
  puStack_e0 = (undefined *)piStack_228;
  puStack_1d8 = &_gp;
  piStack_f4 = piStack_2c0;
  piStack_f0 = piStack_238;
  piStack_e8 = piStack_230;
  piStack_e4 = piStack_22c;
  piStack_dc = (int *)param_3;
  iStack_d8 = unaff_s6;
  iStack_d4 = unaff_s7;
  piStack_d0 = unaff_s8;
  piStack_c0 = piStack_2b8;
  if ((*(int *)(piVar24[0x16] + 0x178) == 0) ||
     (iVar22 = ssl3_digest_cached_records(), piStack_220 = param_4, iVar22 != 0)) {
    puStack_1bc = auStack_198;
    piVar52 = aiStack_174;
    piStack_1b8 = piVar52;
    (**(code **)(puStack_1d8 + -0x7fc4))(puStack_1bc);
    iVar22 = 0;
    iStack_1c4 = 0;
    iStack_1d0 = 0;
    while (iVar25 = ssl_get_handshake_digest(iVar22,&uStack_1a8,&uStack_1a4), iVar25 != 0) {
      uVar26 = ssl_get_algorithm2(piVar24);
      if ((uVar26 & uStack_1a8) == 0) {
        iVar22 = iVar22 + 1;
      }
      else {
        iVar25 = (**(code **)(puStack_1d8 + -0x6fb4))(uStack_1a4);
        if (((*(int *)(*(int *)(piVar24[0x16] + 0x17c) + iVar22 * 4) == 0) || (iVar25 < 0)) ||
           (0x80 - iStack_1d0 < iVar25)) {
          iVar22 = iVar22 + 1;
          iStack_1c4 = 1;
        }
        else {
          iVar27 = (**(code **)(puStack_1d8 + -0x6cb4))(puStack_1bc);
          if (((iVar27 == 0) ||
              (iVar27 = (**(code **)(puStack_1d8 + -0x7868))(puStack_1bc,piVar52,&iStack_1ac),
              iVar27 == 0)) || (iVar27 = iStack_1ac, iStack_1ac != iVar25)) {
            iStack_1c4 = 1;
            iVar27 = iVar25;
          }
          piVar52 = (int *)((int)piVar52 + iVar27);
          iVar22 = iVar22 + 1;
          iStack_1d0 = (int)piVar52 - (int)piStack_1b8;
        }
      }
    }
    piStack_22c = &iStack_19c;
    piStack_238 = (int *)ssl_get_algorithm2(piVar24);
    piStack_228 = &iStack_1a0;
    iVar25 = 0;
    piStack_230 = (int *)(piVar24[0x30] + 0x14);
    uVar26 = *(uint *)(piVar24[0x30] + 0x10);
    iVar22 = 0;
    while (iStack_1b4 = ssl_get_handshake_digest(iVar25,piStack_228,piStack_22c),
          unaff_s8 = piStack_1b8, iStack_1b4 != 0) {
      iVar25 = iVar25 + 1;
      if ((iStack_1a0 << 10 & (uint)piStack_238) != 0) {
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
    piStack_220 = (int *)&bStack_180;
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
    piStack_1c8 = (int *)((uVar26 & 1) + unaff_s7);
    piStack_2c0 = piStack_228;
    piStack_2b8 = piStack_22c;
    iVar25 = ssl_get_handshake_digest(0);
    piVar24 = piStack_1c8;
    iStack_234 = iStack_1b4;
    while (piStack_1c8 = piVar24, iStack_1b4 = iStack_234, iVar25 != 0) {
      if ((iStack_1a0 << 10 & (uint)piStack_238) != 0) {
        if (iStack_19c == 0) {
          piStack_2b8 = (int *)0x146;
          piStack_200 = (int *)0x114;
          piStack_2c0 = (int *)0x11c;
          (**(code **)(puStack_1d8 + -0x6eb0))(0x14,0x11c,0x146,&DAT_00647bcc);
        }
        else {
          uStack_1e0 = 0xc;
          uStack_1e8 = 0;
          uStack_1ec = 0;
          uStack_1f0 = 0;
          uStack_1f4 = 0;
          piStack_1fc = unaff_s8;
          piStack_2c0 = piStack_230;
          piStack_200 = piStack_c0;
          iStack_1f8 = iStack_1d0;
          piStack_1e4 = piStack_220;
          iVar25 = tls1_P_hash_constprop_2();
          piStack_2b8 = piVar24;
          iStack_234 = iStack_1b4;
          if (iVar25 != 0) {
            piStack_230 = (int *)((int)piStack_230 + unaff_s7);
            bVar1 = *(byte *)((int)param_4 + 3) ^ bStack_17d;
            in_t3 = (uint)bVar1;
            in_t2 = (uint)(*(byte *)(param_4 + 1) ^ bStack_17c);
            bVar21 = *(byte *)((int)param_4 + 5) ^ bStack_17b;
            in_t1 = (uint)bVar21;
            *(byte *)param_4 = *(byte *)param_4 ^ bStack_180;
            *(byte *)((int)param_4 + 1) = *(byte *)((int)param_4 + 1) ^ bStack_17f;
            *(byte *)((int)param_4 + 9) = *(byte *)((int)param_4 + 9) ^ bStack_177;
            *(byte *)((int)param_4 + 2) = *(byte *)((int)param_4 + 2) ^ bStack_17e;
            *(byte *)((int)param_4 + 3) = bVar1;
            *(byte *)(param_4 + 1) = *(byte *)(param_4 + 1) ^ bStack_17c;
            *(byte *)((int)param_4 + 5) = bVar21;
            *(byte *)((int)param_4 + 6) = *(byte *)((int)param_4 + 6) ^ bStack_17a;
            *(byte *)((int)param_4 + 7) = *(byte *)((int)param_4 + 7) ^ bStack_179;
            *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) ^ bStack_178;
            *(byte *)((int)param_4 + 10) = *(byte *)((int)param_4 + 10) ^ bStack_176;
            *(byte *)((int)param_4 + 0xb) = *(byte *)((int)param_4 + 0xb) ^ bStack_175;
            goto LAB_0049af98;
          }
        }
        (**(code **)(puStack_1d8 + -0x7fac))(puStack_1bc);
        goto LAB_0049afd0;
      }
LAB_0049af98:
      iVar22 = iVar22 + 1;
      piStack_2c0 = piStack_228;
      piStack_2b8 = piStack_22c;
      iVar25 = ssl_get_handshake_digest(iVar22);
      piVar24 = piStack_1c8;
      iStack_234 = iStack_1b4;
    }
    (**(code **)(puStack_1d8 + -0x7fac))(puStack_1bc);
    param_3 = (char *)param_4;
    if (iStack_1c4 == 0) {
      iStack_234 = 0xc;
      goto LAB_0049afd0;
    }
  }
  iStack_234 = 0;
  param_4 = (int *)param_3;
LAB_0049afd0:
  if (piStack_f4 == *ppiStack_1c0) {
    return iStack_234;
  }
  pcStack_214 = tls1_mac;
  piStack_2d4 = piStack_f4;
  (**(code **)(puStack_1d8 + -0x5328))();
  puStack_2c4 = PTR___stack_chk_guard_006aabf0;
  puStack_288 = &_gp;
  iStack_23c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar22 = piStack_2d4[0x16];
  puStack_2d0 = (uint *)(iVar22 + 0x10c);
  if (piStack_2b8 == (int *)0x0) {
    puVar51 = (undefined *)piStack_2d4[0x21];
    puStack_2d8 = (undefined4 *)(iVar22 + 8);
    uStack_2c8 = piStack_2d4[0x1f] & 1;
  }
  else {
    puVar51 = (undefined *)piStack_2d4[0x24];
    puStack_2d0 = (uint *)(iVar22 + 0x130);
    puStack_2d8 = (undefined4 *)(iVar22 + 0x54);
    uStack_2c8 = piStack_2d4[0x1f] & 2;
  }
  piStack_224 = param_4;
  iStack_21c = unaff_s7;
  piStack_218 = unaff_s8;
  uVar23 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(puVar51);
  iStack_270 = (**(code **)(puStack_288 + -0x6fb4))(uVar23);
  if (iStack_270 < 0) {
    uStack_27c = iStack_270;
    (**(code **)(puStack_288 + -0x7194))(&DAT_00647bcc,0x3d3,"t >= 0");
    iStack_270 = uStack_27c;
  }
  puStack_2cc = puVar51;
  if (uStack_2c8 == 0) {
    puStack_2cc = auStack_26c;
    (**(code **)(puStack_288 + -0x6e2c))(puStack_2cc,puVar51);
  }
  iVar22 = *piStack_2d4;
  if ((iVar22 == 0xfeff) || (iVar22 == 0x100)) {
    if (piStack_2b8 == (int *)0x0) {
      uVar2 = *(undefined2 *)(piStack_2d4[0x17] + 0x208);
      uVar38 = (undefined)((ushort)uVar2 >> 8);
    }
    else {
      uVar2 = *(undefined2 *)(piStack_2d4[0x17] + 0x20a);
      uVar38 = (undefined)((ushort)uVar2 >> 8);
    }
    auStack_254 = (undefined  [4])CONCAT13(uVar38,CONCAT12((char)uVar2,SUB42(auStack_254,0)));
    bVar1 = *(byte *)((int)puStack_2d8 + 6);
    in_t0 = (uint)bVar1;
    uVar34 = *(uint *)((int)puStack_2d8 + 2);
    cVar33 = *(char *)((int)puStack_2d8 + 7);
    puVar51 = auStack_254 + 2;
    uVar26 = (uint)puVar51 & 3;
    *(uint *)(puVar51 + -uVar26) =
         *(uint *)(puVar51 + -uVar26) & -1 << (4 - uVar26) * 8 | uVar34 >> uVar26 * 8;
    puVar51 = auStack_250 + 1;
    uVar26 = (uint)puVar51 & 3;
    *(uint *)(puVar51 + -uVar26) =
         *(uint *)(puVar51 + -uVar26) & 0xffffffffU >> (uVar26 + 1) * 8 | uVar34 << (3 - uVar26) * 8
    ;
    auStack_250 = (undefined  [4])CONCAT31(CONCAT21(auStack_250._0_2_,bVar1),cVar33);
    uStack_248 = auStack_250;
    uStack_24c = auStack_254;
  }
  else {
    uStack_24c = *puStack_2d8;
    uStack_248 = puStack_2d8[1];
  }
  uStack_27c = puStack_2d0[1];
  uStack_2bc = *puStack_2d0;
  iStack_278 = iStack_270;
  puVar42 = (undefined4 *)(uStack_2bc & 0xff);
  *puStack_2d0 = (uint)puVar42;
  uStack_244 = (undefined)uStack_2bc;
  uStack_243 = (undefined)((uint)iVar22 >> 8);
  uStack_242 = (undefined)iVar22;
  uStack_241 = (undefined)(uStack_27c >> 8);
  uStack_240 = (undefined)uStack_27c;
  puVar43 = &uStack_24c;
  if (((piStack_2b8 == (int *)0x0) &&
      (puStack_274 = &uStack_24c, uVar26 = (**(code **)(puStack_288 + -0x6cb0))(piStack_2d4[0x20]),
      puVar43 = puStack_274, (uVar26 & 0xf0007) == 2)) &&
     (iVar22 = ssl3_cbc_record_digest_supported(puStack_2cc,puStack_274), puVar43 = puStack_274,
     iVar22 != 0)) {
    uStack_28c = 0;
    iStack_294 = piStack_2d4[0x16] + 0x14;
    uStack_290 = *(undefined4 *)(piStack_2d4[0x16] + 0x10);
    pcVar50 = (char *)&iStack_270;
    iStack_298 = uStack_27c + iStack_278 + (uStack_2bc >> 8);
    iStack_29c = puStack_2d0[1] + iStack_270;
    uStack_2a0 = puStack_2d0[4];
    puVar42 = puStack_274;
    ssl3_cbc_digest_record(puStack_2cc,piStack_2c0);
  }
  else {
    (**(code **)(puStack_288 + -0x786c))(puStack_2cc,puVar43,0xd);
    (**(code **)(puStack_288 + -0x786c))(puStack_2cc,puStack_2d0[4],puStack_2d0[1]);
    pcVar50 = (char *)&iStack_270;
    iVar22 = (**(code **)(puStack_288 + -0x7914))(puStack_2cc,piStack_2c0);
    if (iVar22 < 1) {
      pcVar50 = "t > 0";
      (**(code **)(puStack_288 + -0x7194))(&DAT_00647bcc,0x40d);
    }
  }
  if (uStack_2c8 == 0) {
    (**(code **)(puStack_288 + -0x7fac))(auStack_26c);
  }
  if (((*piStack_2d4 != 0xfeff) && (*piStack_2d4 != 0x100)) &&
     ((((cVar33 = *(char *)((int)puStack_2d8 + 7) + '\x01', *(char *)((int)puStack_2d8 + 7) = cVar33
        , cVar33 == '\0' &&
        ((cVar33 = *(char *)((int)puStack_2d8 + 6) + '\x01',
         *(char *)((int)puStack_2d8 + 6) = cVar33, cVar33 == '\0' &&
         (cVar33 = *(char *)((int)puStack_2d8 + 5) + '\x01',
         *(char *)((int)puStack_2d8 + 5) = cVar33, cVar33 == '\0')))) &&
       (cVar33 = *(char *)(puStack_2d8 + 1), *(char *)(puStack_2d8 + 1) = cVar33 + '\x01',
       (char)(cVar33 + '\x01') == '\0')) &&
      (((cVar33 = *(char *)((int)puStack_2d8 + 3) + '\x01', *(char *)((int)puStack_2d8 + 3) = cVar33
        , cVar33 == '\0' &&
        (cVar33 = *(char *)((int)puStack_2d8 + 2) + '\x01', *(char *)((int)puStack_2d8 + 2) = cVar33
        , cVar33 == '\0')) &&
       (cVar33 = *(char *)((int)puStack_2d8 + 1) + '\x01', *(char *)((int)puStack_2d8 + 1) = cVar33,
       cVar33 == '\0')))))) {
    *(char *)puStack_2d8 = *(char *)puStack_2d8 + '\x01';
  }
  if (iStack_23c == *(int *)puStack_2c4) {
    return iStack_270;
  }
  pcStack_2b4 = tls1_generate_master_secret;
  iVar22 = iStack_23c;
  (**(code **)(puStack_288 + -0x5328))();
  puVar51 = PTR___stack_chk_guard_006aabf0;
  uStack_2dc = *(uint *)PTR___stack_chk_guard_006aabf0;
  puVar43 = puVar42;
  uVar26 = ssl_get_algorithm2();
  iVar54 = *(int *)(iVar22 + 0xc0);
  iVar27 = 0;
  iVar25 = *(int *)(iVar22 + 0x58) + 0xc0;
  puVar28 = (uint *)(iVar54 + 0x14);
  iVar22 = 0;
  while (iVar29 = ssl_get_handshake_digest(iVar27,&iStack_314,&iStack_310), iVar29 != 0) {
    iVar27 = iVar27 + 1;
    if ((iStack_314 << 10 & uVar26) != 0) {
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
  pcStack_328 = "master secret";
  piVar24 = &iStack_314;
  piVar52 = &iStack_310;
  iVar29 = ssl_get_handshake_digest(0);
  do {
    if (iVar29 == 0) {
LAB_0049b79c:
      if (uStack_2dc == *(uint *)puVar51) {
        return 0x30;
      }
      uVar26 = uStack_2dc;
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      puVar42 = puVar43;
      iVar22 = (*(code *)PTR_CRYPTO_malloc_006a8108)(piVar52,&DAT_00647bcc,0x471);
      if (iVar22 == 0) {
        iVar25 = 0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
      }
      else {
        iVar25 = uStack_368 + 0x40;
        if (iStack_35c == 0) {
          iVar54 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar25,&DAT_00647bcc,0x47f);
          iVar27 = iVar25;
        }
        else {
          iVar27 = uStack_360 + 2 + iVar25;
          iVar54 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar27,&DAT_00647bcc,0x47f);
        }
        if (iVar54 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x41,&DAT_00647bcc,0x4b5);
          (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
          return 0;
        }
        uVar40 = uStack_368;
        (*(code *)PTR_memcpy_006aabf4)(iVar54);
        puVar32 = (uint *)(iVar54 + uStack_368);
        iVar36 = *(int *)(uVar26 + 0x58);
        puVar28 = (uint *)(iVar54 + uStack_368 + 0x20);
        uVar49 = *(uint *)(iVar36 + 0xc0);
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
        uVar48 = (*(int *)((iVar36 + 0xc4U) - uVar34) << uVar34 * 8 |
                 in_t3 & 0xffffffffU >> (4 - uVar34) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)((iVar36 + 199U) - uVar12) >> (3 - uVar12) * 8;
        uVar34 = iVar36 + 0xcbU & 3;
        uVar47 = (*(int *)((iVar36 + 200U) - uVar3) << uVar3 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar34 + 1) * 8 |
                 *(uint *)((iVar36 + 0xcbU) - uVar34) >> (3 - uVar34) * 8;
        uVar34 = iVar36 + 0xcfU & 3;
        uVar46 = (*(int *)((iVar36 + 0xccU) - uVar4) << uVar4 * 8 |
                 in_t1 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar34 + 1) * 8 |
                 *(uint *)((iVar36 + 0xcfU) - uVar34) >> (3 - uVar34) * 8;
        uVar34 = iVar36 + 0xd3U & 3;
        uVar45 = (*(int *)((iVar36 + 0xd0U) - uVar5) << uVar5 * 8 |
                 in_t0 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar34 + 1) * 8 |
                 *(uint *)((iVar36 + 0xd3U) - uVar34) >> (3 - uVar34) * 8;
        uVar34 = iVar36 + 0xd7U & 3;
        uVar44 = (*(int *)((iVar36 + 0xd4U) - uVar6) << uVar6 * 8 |
                 (uint)puVar42 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar34 + 1) * 8 |
                 *(uint *)((iVar36 + 0xd7U) - uVar34) >> (3 - uVar34) * 8;
        uVar34 = iVar36 + 0xdbU & 3;
        uVar4 = *(uint *)((iVar36 + 0xdbU) - uVar34);
        uVar3 = iVar36 + 0xdfU & 3;
        uVar5 = *(uint *)((iVar36 + 0xdfU) - uVar3);
        *puVar32 = uVar49;
        puVar32[1] = uVar48;
        puVar32[2] = uVar47;
        puVar32[3] = uVar46;
        puVar32[4] = uVar45;
        puVar32[5] = uVar44;
        puVar32[6] = (iVar29 << uVar7 * 8 | uVar40 & 0xffffffffU >> (4 - uVar7) * 8) &
                     -1 << (uVar34 + 1) * 8 | uVar4 >> (3 - uVar34) * 8;
        puVar32[7] = (iVar9 << uVar8 * 8 | (uint)puVar43 & 0xffffffffU >> (4 - uVar8) * 8) &
                     -1 << (uVar3 + 1) * 8 | uVar5 >> (3 - uVar3) * 8;
        iVar37 = *(int *)(uVar26 + 0x58);
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
        uVar40 = iVar37 + 0xabU & 3;
        uVar17 = *(uint *)((iVar37 + 0xabU) - uVar40);
        uVar13 = iVar37 + 0xafU & 3;
        uVar18 = *(uint *)((iVar37 + 0xafU) - uVar13);
        uVar14 = iVar37 + 0xb3U & 3;
        uVar19 = *(uint *)((iVar37 + 0xb3U) - uVar14);
        uVar15 = iVar37 + 0xb7U & 3;
        uVar20 = *(uint *)((iVar37 + 0xb7U) - uVar15);
        uVar41 = *(uint *)(iVar37 + 0xb8);
        uVar39 = *(uint *)(iVar37 + 0xbc);
        *puVar28 = (*(int *)((iVar37 + 0xa0U) - uVar34) << uVar34 * 8 |
                   uVar49 & 0xffffffffU >> (4 - uVar34) * 8) & -1 << (uVar8 + 1) * 8 |
                   *(uint *)((iVar37 + 0xa3U) - uVar8) >> (3 - uVar8) * 8;
        puVar28[1] = (iVar29 << uVar3 * 8 | uVar48 & 0xffffffffU >> (4 - uVar3) * 8) &
                     -1 << (uVar12 + 1) * 8 | uVar16 >> (3 - uVar12) * 8;
        puVar28[2] = (iVar9 << uVar4 * 8 | uVar47 & 0xffffffffU >> (4 - uVar4) * 8) &
                     -1 << (uVar40 + 1) * 8 | uVar17 >> (3 - uVar40) * 8;
        puVar28[3] = (iVar36 << uVar5 * 8 | uVar46 & 0xffffffffU >> (4 - uVar5) * 8) &
                     -1 << (uVar13 + 1) * 8 | uVar18 >> (3 - uVar13) * 8;
        puVar28[4] = (iVar10 << uVar6 * 8 | uVar45 & 0xffffffffU >> (4 - uVar6) * 8) &
                     -1 << (uVar14 + 1) * 8 | uVar19 >> (3 - uVar14) * 8;
        puVar28[5] = (iVar11 << uVar7 * 8 | uVar44 & 0xffffffffU >> (4 - uVar7) * 8) &
                     -1 << (uVar15 + 1) * 8 | uVar20 >> (3 - uVar15) * 8;
        puVar28[6] = uVar41;
        puVar28[7] = uVar39;
        if (iStack_35c != 0) {
          *(char *)(iVar54 + iVar25) = (char)((uint)uStack_360 >> 8);
          *(undefined *)((int)puVar32 + 0x41) = (undefined)uStack_360;
          if ((uStack_360 != 0) || (iStack_364 != 0)) {
            (*(code *)PTR_memcpy_006aabf4)(iVar54 + uStack_368 + 0x42,iStack_364,uStack_360);
          }
        }
        iVar25 = (*(code *)PTR_memcmp_006aabd8)(iVar54,"client finished",0xf);
        if (((iVar25 == 0) ||
            (iVar25 = (*(code *)PTR_memcmp_006aabd8)(iVar54,"server finished",0xf), iVar25 == 0)) ||
           ((iVar25 = (*(code *)PTR_memcmp_006aabd8)(iVar54,"master secret",0xd), iVar25 == 0 ||
            (iVar25 = (*(code *)PTR_memcmp_006aabd8)(iVar54,"key expansion",0xd), iVar25 == 0)))) {
          iVar25 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13a,0x16f,&DAT_00647bcc,0x4b1);
        }
        else {
          iVar25 = tls1_PRF_constprop_1
                             (*(undefined4 *)(*(int *)(*(int *)(uVar26 + 0x58) + 0x344) + 0x24),
                              iVar54,iVar27,0,0,0,0,0,0,*(int *)(uVar26 + 0xc0) + 0x14,
                              *(undefined4 *)(*(int *)(uVar26 + 0xc0) + 0x10),piVar24,iVar22,piVar52
                             );
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar22);
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar54);
      }
      return iVar25;
    }
    if ((iStack_314 << 10 & uVar26) != 0) {
      if (iStack_310 == 0) {
        piVar52 = (int *)0x146;
        puVar43 = (undefined4 *)&DAT_00647bcc;
        uStack_368 = 0x114;
        piVar24 = (int *)0x11c;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14);
        goto LAB_0049b79c;
      }
      uStack_360 = 0x20;
      iStack_35c = 0;
      uStack_368 = 0xd;
      piVar24 = (int *)pcVar50;
      piVar52 = (int *)(((uint)puVar42 & 1) + iVar27);
      puVar43 = (undefined4 *)pcStack_328;
      iVar29 = tls1_P_hash_constprop_2();
      iStack_364 = iVar25;
      if (iVar29 == 0) goto LAB_0049b79c;
      pcVar50 = (char *)((int)pcVar50 + iVar27);
      puVar32 = &uStack_30c;
      puVar35 = puVar28;
      if (((uint)puVar28 & 3) == 0 &&
          ((uint *)(iVar54 + 0x18) <= &uStack_30c || &uStack_308 <= puVar28)) {
        *(uint *)(iVar54 + 0x14) = *(uint *)(iVar54 + 0x14) ^ uStack_30c;
        *(uint *)(iVar54 + 0x18) = uStack_308 ^ *(uint *)(iVar54 + 0x18);
        puVar43 = (undefined4 *)(uStack_2f4 ^ *(uint *)(iVar54 + 0x2c));
        in_t3 = uStack_2f8 ^ *(uint *)(iVar54 + 0x28);
        *(uint *)(iVar54 + 0x1c) = uStack_304 ^ *(uint *)(iVar54 + 0x1c);
        *(uint *)(iVar54 + 0x20) = uStack_300 ^ *(uint *)(iVar54 + 0x20);
        *(uint *)(iVar54 + 0x24) = uStack_2fc ^ *(uint *)(iVar54 + 0x24);
        *(uint *)(iVar54 + 0x28) = in_t3;
        *(undefined4 **)(iVar54 + 0x2c) = puVar43;
        *(uint *)(iVar54 + 0x30) = uStack_2f0 ^ *(uint *)(iVar54 + 0x30);
        *(uint *)(iVar54 + 0x38) = uStack_2e8 ^ *(uint *)(iVar54 + 0x38);
        *(uint *)(iVar54 + 0x34) = uStack_2ec ^ *(uint *)(iVar54 + 0x34);
        *(uint *)(iVar54 + 0x3c) = uStack_2e4 ^ *(uint *)(iVar54 + 0x3c);
        *(uint *)(iVar54 + 0x40) = *(uint *)(iVar54 + 0x40) ^ uStack_2e0;
      }
      else {
        do {
          puVar30 = (uint *)((int)puVar32 + 1);
          *(byte *)puVar35 = *(byte *)puVar35 ^ *(byte *)puVar32;
          puVar32 = puVar30;
          puVar35 = (uint *)((int)puVar35 + 1);
        } while (puVar30 != &uStack_2dc);
      }
    }
    iVar22 = iVar22 + 1;
    piVar24 = &iStack_314;
    piVar52 = &iStack_310;
    iVar29 = ssl_get_handshake_digest(iVar22);
  } while( true );
}

