
/* WARNING: Removing unreachable block (ram,0x005e451c) */
/* WARNING: Could not reconcile some variable overlaps */

void DES_cfb_encrypt(uchar *in,uchar *out,int numbits,long length,DES_key_schedule *schedule,
                    DES_cblock *ivec,int enc)

{
  byte *pbVar1;
  _union_771 *p_Var2;
  undefined *puVar3;
  undefined4 ****ppppuVar4;
  uint uVar5;
  int iVar6;
  undefined4 ****ppppuVar7;
  uint uVar8;
  DES_key_schedule *pDVar9;
  byte *pbVar10;
  uint *puVar11;
  code **ppcVar12;
  undefined4 ****ppppuVar13;
  byte bVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined4 ****ppppuVar19;
  uint uVar20;
  undefined4 ****ppppuVar21;
  uint uVar22;
  uchar *unaff_s0;
  uchar *puVar23;
  uint *unaff_s1;
  code **ppcVar24;
  uint unaff_s2;
  undefined4 ****ppppuVar25;
  undefined4 ****ppppuVar26;
  uint unaff_s3;
  undefined4 ****ppppuVar27;
  int unaff_s4;
  undefined4 ****unaff_s5;
  code **unaff_s6;
  undefined **unaff_s7;
  byte *pbVar28;
  uint unaff_s8;
  uint uStack_134;
  uint uStack_130;
  byte abStack_12c [4];
  byte bStack_128;
  byte bStack_127;
  byte bStack_126;
  byte bStack_125;
  int iStack_124;
  uint uStack_120;
  uint *puStack_11c;
  code **ppcStack_118;
  undefined4 uStack_114;
  byte *pbStack_110;
  undefined4 ****ppppuStack_10c;
  code **ppcStack_108;
  byte *pbStack_104;
  uchar *puStack_100;
  undefined4 uStack_fc;
  byte *pbStack_e8;
  uint *puStack_e4;
  undefined4 ****ppppuStack_dc;
  DES_key_schedule *pDStack_d8;
  int *piStack_d4;
  uint uStack_cc;
  uint uStack_c8;
  byte abStack_c4 [4];
  byte bStack_c0;
  byte bStack_bf;
  byte bStack_be;
  byte bStack_bd;
  int iStack_bc;
  uchar *puStack_b8;
  uint *puStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  int iStack_a8;
  undefined4 ****ppppuStack_a4;
  code **ppcStack_a0;
  undefined **ppuStack_9c;
  uint uStack_98;
  code *pcStack_94;
  code **local_80;
  undefined4 uStack_7c;
  byte *pbStack_78;
  DES_key_schedule *local_74;
  undefined4 ****local_70;
  undefined4 ****local_6c;
  undefined4 ****local_68;
  undefined4 ****local_64;
  undefined4 ****local_60;
  code **local_5c;
  int *local_58;
  uchar *local_54;
  undefined4 ****local_50;
  undefined4 ****local_4c;
  undefined4 ****local_44;
  undefined4 ****local_40;
  undefined4 local_3c;
  undefined4 local_38;
  byte local_34 [8];
  int local_2c;
  
  local_74 = schedule;
  local_58 = (int *)PTR___stack_chk_guard_006a9ae8;
  local_54 = (uchar *)ivec;
  local_80 = (code **)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppcVar12 = (code **)numbits;
  ppppuStack_dc = (undefined4 ****)length;
  if (numbits - 1U < 0x40) {
    unaff_s4 = numbits >> 3;
    ppcVar12 = (code **)((uint)(*ivec)[7] << 0x18);
    ppppuVar27 = (undefined4 ****)
                 ((uint)ppcVar12 |
                 (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4]);
    unaff_s5 = (undefined4 ****)(numbits + 7 >> 3);
    ppppuVar25 = (undefined4 ****)
                 ((uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0] |
                 (uint)(*ivec)[3] << 0x18);
    if (enc == 0) {
      unaff_s0 = in;
      unaff_s1 = (uint *)out;
      if (unaff_s5 <= (uint)length) {
        local_5c = (code **)(&PTR_LAB_00674ca4 + (int)unaff_s5);
        ppppuStack_dc = (undefined4 ****)(length - (int)unaff_s5);
        ppppuVar21 = &local_44;
        ppppuVar19 = (undefined4 ****)((int)unaff_s5 + -1);
        unaff_s7 = (undefined **)&local_3c;
        unaff_s6 = (code **)(&PTR_LAB_00674cc8 + (int)unaff_s5);
        unaff_s8 = (uint)(unaff_s5 < &DAT_00000009);
        local_6c = (undefined4 ****)(numbits & 7U);
        ppppuVar26 = ppppuVar25;
        do {
          ppppuVar25 = ppppuVar27;
          ppcVar12 = (code **)0x1;
          local_70 = ppppuVar21;
          local_68 = ppppuStack_dc;
          local_64 = (undefined4 ****)numbits;
          local_60 = ppppuVar19;
          local_44 = ppppuVar26;
          local_40 = ppppuVar25;
          (*local_80[-0x1a46])(ppppuVar21,local_74);
          if (unaff_s8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005e42ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**local_5c)();
            return;
          }
          bVar14 = (in + (int)unaff_s5)[-1];
          ppppuVar27 = (undefined4 ****)(uint)bVar14;
          in = in + (int)unaff_s5 + (int)local_60;
          ppppuVar13 = local_68;
          ppppuVar19 = local_60;
          numbits = (int)local_64;
          ppppuVar21 = local_70;
          if (local_64 != (undefined4 ****)&DAT_00000020) {
            if (local_64 == (undefined4 ****)&DAT_00000040) {
              ppppuVar25 = ppppuVar27;
              ppppuVar27 = (undefined4 ****)0x0;
            }
            else {
              local_34[0] = bVar14;
              local_34[1] = 0;
              local_34[2] = 0;
              local_3c = (undefined *)
                         CONCAT31(CONCAT21(CONCAT11((char)ppppuVar26,(char)((uint)ppppuVar26 >> 8)),
                                           (char)((uint)ppppuVar26 >> 0x10)),
                                  (char)((uint)ppppuVar26 >> 0x18));
              local_38 = CONCAT31(CONCAT21(CONCAT11((char)ppppuVar25,(char)((uint)ppppuVar25 >> 8)),
                                           (char)((uint)ppppuVar25 >> 0x10)),
                                  (char)((uint)ppppuVar25 >> 0x18));
              local_34[3] = 0;
              local_34[4] = 0;
              local_34[5] = 0;
              local_34[6] = 0;
              local_34[7] = 0;
              if (local_6c == (undefined4 ****)0x0) {
                ppcVar12 = (code **)&DAT_00000008;
                local_4c = local_70;
                local_50 = local_60;
                local_60 = local_64;
                local_64 = local_68;
                local_70 = (undefined4 ****)0x0;
                local_68 = ppppuVar27;
                (*local_80[-0x14bb])(unaff_s7,(int)unaff_s7 + unaff_s4);
                bVar14 = (byte)local_68;
                ppppuVar13 = local_64;
                ppppuVar19 = local_50;
                numbits = (int)local_60;
                ppppuVar21 = local_4c;
              }
              else {
                ppcVar12 = (code **)(&stack0xffffffd8 + unaff_s4);
                uVar8 = 8 - (int)local_6c;
                local_3c._1_3_ =
                     (uint3)(byte)(*(char *)((int)&local_3c + unaff_s4 + 1) <<
                                   ((uint)local_6c & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&local_3c + unaff_s4 + 2) >>
                                        (uVar8 & 0x1f))) << 0x10;
                local_3c._0_3_ =
                     (uint3)(((uint)(byte)(*(char *)((int)&local_3c + unaff_s4) <<
                                           ((uint)local_6c & 0x1f) |
                                          (byte)((int)(uint)*(byte *)((int)&local_3c + unaff_s4 + 1)
                                                >> (uVar8 & 0x1f))) << 0x18) >> 8) |
                     local_3c._1_3_ >> 8 |
                     (uint3)(byte)(*(char *)((int)&local_3c + unaff_s4 + 2) <<
                                   ((uint)local_6c & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&local_3c + unaff_s4 + 3) >>
                                        (uVar8 & 0x1f)));
                local_3c = (undefined *)
                           CONCAT31(local_3c._0_3_,
                                    *(char *)((int)&local_3c + unaff_s4 + 3) <<
                                    ((uint)local_6c & 0x1f) |
                                    (byte)((int)(uint)local_34[unaff_s4 + -4] >> (uVar8 & 0x1f)));
                local_38._1_3_ =
                     (uint3)(byte)(local_34[unaff_s4 + -3] << ((uint)local_6c & 0x1f) |
                                  (byte)((int)(uint)local_34[unaff_s4 + -2] >> (uVar8 & 0x1f))) <<
                     0x10;
                local_38._0_3_ =
                     (uint3)(((uint)(byte)(local_34[unaff_s4 + -4] << ((uint)local_6c & 0x1f) |
                                          (byte)((int)(uint)local_34[unaff_s4 + -3] >>
                                                (uVar8 & 0x1f))) << 0x18) >> 8) |
                     local_38._1_3_ >> 8 |
                     (uint3)(byte)(local_34[unaff_s4 + -2] << ((uint)local_6c & 0x1f) |
                                  (byte)((int)(uint)local_34[unaff_s4 + -1] >> (uVar8 & 0x1f)));
                local_38 = CONCAT31(local_38._0_3_,
                                    (byte)((int)(uint)local_34[unaff_s4] >> (uVar8 & 0x1f)) |
                                    local_34[unaff_s4 + -1] << ((uint)local_6c & 0x1f));
              }
              ppppuVar25 = (undefined4 ****)
                           (((((uint)local_3c >> 0x10) << 0x18 | ((uint)local_3c >> 0x18) << 0x10)
                            >> 0x10) +
                           (((uint)local_3c & 0xff) << 8 | (uint)local_3c >> 8 & 0xff) * 0x10000);
              ppppuVar27 = (undefined4 ****)
                           ((((local_38 >> 0x10) << 0x18 | (local_38 >> 0x18) << 0x10) >> 0x10) +
                           ((local_38 & 0xff) << 8 | local_38 >> 8 & 0xff) * 0x10000);
            }
          }
          ((uchar *)((int)out + (int)unaff_s5))[-1] = bVar14 ^ (byte)local_44;
          ppppuStack_dc = (undefined4 ****)((int)ppppuVar13 - (int)unaff_s5);
          out = (uchar *)((int)out + (int)unaff_s5) + (int)ppppuVar19;
          unaff_s0 = in;
          unaff_s1 = (uint *)out;
          ppppuVar26 = ppppuVar25;
        } while (unaff_s5 <= ppppuVar13);
      }
    }
    else {
      unaff_s7 = &switchD_005e4168::switchdataD_00674c80 + (int)unaff_s5;
      unaff_s6 = (code **)(&PTR_LAB_00674cec + (int)unaff_s5);
      ppppuStack_dc = &local_44;
      ppppuVar19 = (undefined4 ****)(numbits & 7U);
      ppppuVar21 = ppppuVar25;
      ppppuVar26 = ppppuVar27;
      while (ppppuVar27 = ppppuVar26, ppppuVar25 = ppppuVar21, unaff_s0 = in, unaff_s1 = (uint *)out
            , unaff_s5 <= (uint)length) {
        ppcVar12 = (code **)0x1;
        unaff_s8 = (uint)(unaff_s5 < &DAT_00000009);
        puVar23 = in + (int)unaff_s5;
        local_70 = ppppuStack_dc;
        local_6c = (undefined4 ****)length;
        local_68 = ppppuVar19;
        local_64 = (undefined4 ****)numbits;
        local_44 = ppppuVar25;
        local_40 = ppppuVar27;
        (*local_80[-0x1a46])(ppppuStack_dc,local_74);
        ppppuVar13 = local_64;
        ppppuVar19 = local_68;
        length = (int)local_6c - (int)unaff_s5;
        if (unaff_s8 == 0) {
switchD_005e4168_caseD_5e4874:
          uVar8 = 0;
          uVar5 = 0;
        }
        else {
          switch((uint)*unaff_s7 & 0xfffffffe) {
          case 0x5e4598:
            uVar8 = 0;
            break;
          case 0x5e4834:
            uVar8 = 0;
            goto LAB_005e45c8;
          case 0x5e483c:
            uVar8 = 0;
            ppcVar12 = (code **)0x0;
            goto LAB_005e45d4;
          case 0x5e4848:
            uVar8 = 0;
            uVar5 = 0;
            goto LAB_005e45e4;
          case 0x5e485c:
            uVar8 = 0;
            goto LAB_005e45ac;
          case 0x5e4864:
            uVar8 = 0;
            goto LAB_005e45bc;
          case 0x5e4874:
            goto switchD_005e4168_caseD_5e4874;
          case 0x5e4890:
            pbVar10 = puVar23 + -1;
            puVar23 = puVar23 + -1;
            uVar8 = (uint)*pbVar10 << 0x18;
          }
          pbVar10 = puVar23 + -1;
          puVar23 = puVar23 + -1;
          uVar8 = (uint)*pbVar10 << 0x10 | uVar8;
LAB_005e45ac:
          pbVar10 = puVar23 + -1;
          puVar23 = puVar23 + -1;
          uVar8 = (uint)*pbVar10 << 8 | uVar8;
LAB_005e45bc:
          pbVar10 = puVar23 + -1;
          puVar23 = puVar23 + -1;
          uVar8 = *pbVar10 | uVar8;
LAB_005e45c8:
          pbVar10 = puVar23 + -1;
          puVar23 = puVar23 + -1;
          ppcVar12 = (code **)((uint)*pbVar10 << 0x18);
LAB_005e45d4:
          pbVar10 = puVar23 + -1;
          puVar23 = puVar23 + -1;
          uVar5 = (uint)*pbVar10 << 0x10 | (uint)ppcVar12;
LAB_005e45e4:
          pbVar10 = puVar23 + -1;
          puVar23 = puVar23 + -1;
          uVar5 = (uint)*pbVar10 << 8 | uVar5;
        }
        in = puVar23 + (int)(undefined *)((int)unaff_s5 + -1);
        ppppuVar4 = (undefined4 ****)((puVar23[-1] | uVar5) ^ (uint)local_44);
        ppppuVar7 = (undefined4 ****)(uVar8 ^ (uint)local_40);
        if (unaff_s8 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005e4620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (**unaff_s6)();
          return;
        }
        ((uchar *)((int)out + (int)unaff_s5))[-1] = (byte)ppppuVar4;
        out = (uchar *)((int)out + (int)unaff_s5) + (int)(undefined *)((int)unaff_s5 + -1);
        ppppuStack_dc = local_70;
        numbits = (int)local_64;
        ppppuVar21 = ppppuVar27;
        ppppuVar26 = ppppuVar4;
        if ((local_64 != (undefined4 ****)&DAT_00000020) &&
           (ppcVar12 = (code **)((uint)ppppuVar25 >> 0x10), ppppuVar21 = ppppuVar4,
           ppppuVar26 = ppppuVar7, local_64 != (undefined4 ****)&DAT_00000040)) {
          local_34[0] = (byte)ppppuVar4;
          local_34[1] = (char)((uint)ppppuVar4 >> 8);
          local_34[2] = (char)((uint)ppppuVar4 >> 0x10);
          local_3c = (undefined *)
                     CONCAT31(CONCAT21(CONCAT11((char)ppppuVar25,(char)((uint)ppppuVar25 >> 8)),
                                       (char)((uint)ppppuVar25 >> 0x10)),
                              (char)((uint)ppppuVar25 >> 0x18));
          local_38 = CONCAT31(CONCAT21(CONCAT11((char)ppppuVar27,(char)((uint)ppppuVar27 >> 8)),
                                       (char)((uint)ppppuVar27 >> 0x10)),
                              (char)((uint)ppppuVar27 >> 0x18));
          local_34[3] = (char)((uint)ppppuVar4 >> 0x18);
          local_34[4] = (char)ppppuVar7;
          local_34[5] = (char)((uint)ppppuVar7 >> 8);
          local_34[6] = (char)((uint)ppppuVar7 >> 0x10);
          local_34[7] = (char)((uint)ppppuVar7 >> 0x18);
          if (local_68 == (undefined4 ****)0x0) {
            ppcVar12 = (code **)&DAT_00000008;
            local_64 = local_70;
            local_68 = ppppuVar13;
            local_6c = ppppuVar19;
            local_70 = (undefined4 ****)length;
            (*local_80[-0x14bb])(&local_3c,(int)&local_3c + unaff_s4);
            ppppuStack_dc = local_64;
            ppppuVar19 = local_6c;
            length = (long)local_70;
            numbits = (int)local_68;
          }
          else {
            uVar8 = 8 - (int)local_68;
            local_3c._1_3_ =
                 (uint3)(byte)(*(char *)((int)&local_3c + unaff_s4 + 1) << ((uint)local_68 & 0x1f) |
                              (byte)((int)(uint)*(byte *)((int)&local_3c + unaff_s4 + 2) >>
                                    (uVar8 & 0x1f))) << 0x10;
            local_3c._0_3_ =
                 (uint3)(((uint)(byte)(*(char *)((int)&local_3c + unaff_s4) <<
                                       ((uint)local_68 & 0x1f) |
                                      (byte)((int)(uint)*(byte *)((int)&local_3c + unaff_s4 + 1) >>
                                            (uVar8 & 0x1f))) << 0x18) >> 8) | local_3c._1_3_ >> 8 |
                 (uint3)(byte)(*(char *)((int)&local_3c + unaff_s4 + 2) << ((uint)local_68 & 0x1f) |
                              (byte)((int)(uint)*(byte *)((int)&local_3c + unaff_s4 + 3) >>
                                    (uVar8 & 0x1f)));
            local_3c = (undefined *)
                       CONCAT31(local_3c._0_3_,
                                *(char *)((int)&local_3c + unaff_s4 + 3) << ((uint)local_68 & 0x1f)
                                | (byte)((int)(uint)local_34[unaff_s4 + -4] >> (uVar8 & 0x1f)));
            local_38._1_3_ =
                 (uint3)(byte)(local_34[unaff_s4 + -3] << ((uint)local_68 & 0x1f) |
                              (byte)((int)(uint)local_34[unaff_s4 + -2] >> (uVar8 & 0x1f))) << 0x10;
            ppcVar12 = (code **)((uint)local_34[unaff_s4 + -2] << ((uint)local_68 & 0x1f));
            local_38._0_3_ =
                 (uint3)(((uint)(byte)(local_34[unaff_s4 + -4] << ((uint)local_68 & 0x1f) |
                                      (byte)((int)(uint)local_34[unaff_s4 + -3] >> (uVar8 & 0x1f)))
                         << 0x18) >> 8) | local_38._1_3_ >> 8 |
                 (uint3)(byte)((byte)ppcVar12 |
                              (byte)((int)(uint)local_34[unaff_s4 + -1] >> (uVar8 & 0x1f)));
            local_38 = CONCAT31(local_38._0_3_,
                                (byte)((int)(uint)local_34[unaff_s4] >> (uVar8 & 0x1f)) |
                                local_34[unaff_s4 + -1] << ((uint)local_68 & 0x1f));
          }
          ppppuVar21 = (undefined4 ****)
                       (((((uint)local_3c >> 0x10) << 0x18 | ((uint)local_3c >> 0x18) << 0x10) >>
                        0x10) + (((uint)local_3c & 0xff) << 8 | (uint)local_3c >> 8 & 0xff) *
                                0x10000);
          ppppuVar26 = (undefined4 ****)
                       ((((local_38 >> 0x10) << 0x18 | (local_38 >> 0x18) << 0x10) >> 0x10) +
                       ((local_38 & 0xff) << 8 | local_38 >> 8 & 0xff) * 0x10000);
        }
      }
    }
    in = (uchar *)((uint)ppppuVar25 >> 0x10);
    *local_54 = (byte)ppppuVar25;
    unaff_s2 = (uint)ppppuVar25 >> 0x18;
    local_54[4] = (byte)ppppuVar27;
    local_54[1] = (byte)((uint)ppppuVar25 >> 8);
    unaff_s3 = (uint)ppppuVar27 >> 0x18;
    local_54[2] = (byte)((uint)ppppuVar25 >> 0x10);
    local_54[3] = (byte)((uint)ppppuVar25 >> 0x18);
    local_54[5] = (byte)((uint)ppppuVar27 >> 8);
    local_54[6] = (byte)((uint)ppppuVar27 >> 0x10);
    local_54[7] = (byte)((uint)ppppuVar27 >> 0x18);
    out = local_54;
  }
  if (local_2c == *local_58) {
    return;
  }
  pcStack_94 = DES_ede3_ofb64_encrypt;
  (*local_80[-0x14cc])();
  ppcStack_118 = local_80;
  pbVar28 = &_gp;
  iStack_a8 = unaff_s4;
  uStack_98 = unaff_s8;
  ppuStack_9c = unaff_s7;
  uStack_ac = unaff_s3;
  piStack_d4 = (int *)PTR___stack_chk_guard_006a9ae8;
  uStack_b0 = unaff_s2;
  puStack_b8 = unaff_s0;
  ppcStack_a0 = unaff_s6;
  ppppuStack_a4 = unaff_s5;
  puStack_b4 = unaff_s1;
  pbStack_e8 = &_gp;
  uVar16 = (uint)pbStack_78[3];
  uVar15 = (uint)pbStack_78[7];
  pDStack_d8 = local_74;
  uVar5 = uVar16 << 0x18 |
          (uint)pbStack_78[1] << 8 | (uint)pbStack_78[2] << 0x10 | (uint)*pbStack_78;
  uStack_120 = local_74->ks[0].deslong[0];
  uVar22 = uVar5 >> 8;
  iStack_bc = *(int *)PTR___stack_chk_guard_006a9ae8;
  pbVar10 = (byte *)(uVar15 << 0x18);
  uStack_cc = uVar5;
  uVar8 = (uint)pbVar10 |
          (uint)pbStack_78[5] << 8 | (uint)pbStack_78[6] << 0x10 | (uint)pbStack_78[4];
  uVar20 = uVar5 >> 0x10;
  uStack_c8 = uVar8;
  uVar18 = uVar8 >> 8;
  abStack_c4[0] = *pbStack_78;
  uVar17 = uVar8 >> 0x10;
  abStack_c4[1] = pbStack_78[1];
  abStack_c4[2] = pbStack_78[2];
  abStack_c4[3] = pbStack_78[3];
  bStack_c0 = pbStack_78[4];
  bStack_bf = pbStack_78[5];
  bStack_be = pbStack_78[6];
  bStack_bd = pbStack_78[7];
  if (ppcVar12 != (code **)0x0) {
    unaff_s5 = (undefined4 ****)0x0;
    unaff_s1 = &uStack_cc;
    unaff_s6 = ppcVar12;
    puVar23 = out;
    do {
      if (uStack_120 == 0) {
        unaff_s5 = (undefined4 ****)((int)unaff_s5 + 1);
        ppcVar12 = ppcStack_118;
        (**(code **)(pbVar28 + -0x5770))(unaff_s1,ppppuStack_dc,ppcStack_118,uStack_7c);
        uVar22 = uStack_cc >> 8;
        uVar20 = uStack_cc >> 0x10;
        abStack_c4[0] = (byte)uStack_cc;
        uVar16 = uStack_cc >> 0x18;
        bStack_c0 = (byte)uStack_c8;
        uVar18 = uStack_c8 >> 8;
        abStack_c4[1] = (byte)(uStack_cc >> 8);
        uVar17 = uStack_c8 >> 0x10;
        abStack_c4[2] = (byte)(uStack_cc >> 0x10);
        uVar15 = uStack_c8 >> 0x18;
        abStack_c4[3] = (byte)(uStack_cc >> 0x18);
        bStack_bf = (byte)(uStack_c8 >> 8);
        bStack_be = (byte)(uStack_c8 >> 0x10);
        bStack_bd = (byte)(uStack_c8 >> 0x18);
        uVar8 = uStack_c8;
        uVar5 = uStack_cc;
        pbVar28 = pbStack_e8;
      }
      out = puVar23 + 1;
      bVar14 = *in;
      unaff_s6 = (code **)((int)unaff_s6 + -1);
      pbVar1 = abStack_c4 + uStack_120;
      pbVar10 = (byte *)(uint)*pbVar1;
      in = in + 1;
      uStack_120 = uStack_120 + 1 & 7;
      *puVar23 = bVar14 ^ *pbVar1;
      puVar23 = out;
    } while (unaff_s6 != (code **)0x0);
    if (unaff_s5 != (undefined4 ****)0x0) {
      *pbStack_78 = (byte)uVar5;
      pbStack_78[1] = (byte)uVar22;
      pbStack_78[2] = (byte)uVar20;
      pbStack_78[3] = (byte)uVar16;
      pbStack_78[4] = (byte)uVar8;
      pbStack_78[5] = (byte)uVar18;
      pbStack_78[6] = (byte)uVar17;
      pbStack_78[7] = (byte)uVar15;
    }
  }
  iVar6 = *piStack_d4;
  pDStack_d8->ks[0].deslong[0] = uStack_120;
  if (iStack_bc != iVar6) {
    uStack_fc = 0x5e4b88;
    pDVar9 = pDStack_d8;
    (**(code **)(pbVar28 + -0x5330))();
    pbVar28 = pbStack_e8;
    puVar3 = PTR___stack_chk_guard_006a9ae8;
    pbStack_104 = in;
    ppcStack_108 = unaff_s6;
    ppppuStack_10c = unaff_s5;
    pbStack_110 = pbStack_78;
    puStack_100 = out;
    uStack_114 = uStack_7c;
    puStack_11c = unaff_s1;
    uVar8 = (uint)pbStack_e8[3];
    uVar5 = *puStack_e4;
    uStack_134 = uVar8 << 0x18 |
                 (uint)pbStack_e8[1] << 8 | (uint)pbStack_e8[2] << 0x10 | (uint)*pbStack_e8;
    iStack_124 = *(int *)PTR___stack_chk_guard_006a9ae8;
    uStack_130 = (uint)pbStack_e8[7] << 0x18 |
                 (uint)pbStack_e8[5] << 8 | (uint)pbStack_e8[6] << 0x10 | (uint)pbStack_e8[4];
    abStack_12c[0] = *pbStack_e8;
    abStack_12c[2] = pbStack_e8[2];
    puVar11 = (uint *)(uStack_130 >> 8);
    abStack_12c[1] = pbStack_e8[1];
    abStack_12c[3] = pbStack_e8[3];
    bStack_128 = pbStack_e8[4];
    bStack_127 = pbStack_e8[5];
    bStack_126 = pbStack_e8[6];
    bStack_125 = pbStack_e8[7];
    if (ppcVar12 != (code **)0x0) {
      iVar6 = 0;
      ppcVar24 = ppcVar12;
      do {
        if (uVar5 == 0) {
          (*(code *)PTR_DES_encrypt1_006a84c8)(&uStack_134,uVar15,1);
          iVar6 = iVar6 + 1;
          ppcVar12 = (code **)(uStack_134 >> 0x10);
          abStack_12c[0] = (byte)uStack_134;
          puVar11 = (uint *)(uStack_130 >> 8);
          bStack_128 = (byte)uStack_130;
          abStack_12c[1] = (byte)(uStack_134 >> 8);
          abStack_12c[2] = (byte)(uStack_134 >> 0x10);
          bStack_127 = (byte)(uStack_130 >> 8);
          abStack_12c[3] = (byte)(uStack_134 >> 0x18);
          bStack_126 = (byte)(uStack_130 >> 0x10);
          bStack_125 = (byte)(uStack_130 >> 0x18);
        }
        p_Var2 = pDVar9->ks;
        ppcVar24 = (code **)((int)ppcVar24 + -1);
        pbVar1 = abStack_12c + uVar5;
        pDVar9 = (DES_key_schedule *)((int)pDVar9->ks + 1);
        uVar5 = uVar5 + 1 & 7;
        *pbVar10 = p_Var2->cblock[0] ^ *pbVar1;
        pbVar10 = pbVar10 + 1;
      } while (ppcVar24 != (code **)0x0);
      if (iVar6 != 0) {
        ppcVar12 = (code **)(uStack_134 >> 0x10);
        *pbVar28 = (byte)uStack_134;
        puVar11 = (uint *)(uStack_130 >> 8);
        pbVar28[4] = (byte)uStack_130;
        pbVar28[1] = (byte)(uStack_134 >> 8);
        pbVar28[2] = (byte)(uStack_134 >> 0x10);
        pbVar28[5] = (byte)(uStack_130 >> 8);
        pbVar28[3] = (byte)(uStack_134 >> 0x18);
        pbVar28[6] = (byte)(uStack_130 >> 0x10);
        pbVar28[7] = (byte)(uStack_130 >> 0x18);
      }
    }
    iVar6 = *(int *)puVar3;
    *puStack_e4 = uVar5;
    if (iStack_124 == iVar6) {
      return;
    }
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    iVar6 = 0x19;
    uVar16 = 0;
    uVar15 = 0;
    uVar5 = 0;
    do {
      uVar17 = (uint)ppcVar12 & (uVar15 ^ uVar16);
      uVar15 = uVar8 & (uVar15 ^ uVar16);
      uVar18 = uVar16 ^ *puVar11 ^ uVar17;
      uVar20 = uVar17 << 0x10 ^ uVar18;
      uVar17 = uVar16 ^ puVar11[1] ^ uVar15;
      uVar15 = (uVar15 << 0x10 ^ uVar17) >> 4;
      uVar17 = uVar15 + uVar17 * 0x10000000;
      uVar5 = *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 * 0x100 >> 0x1a) + 0x140) * 4) ^ uVar5;
      uVar15 = uVar5 >> 0x10 ^ uVar5;
      uVar17 = (uint)ppcVar12 & uVar15;
      uVar15 = uVar8 & uVar15;
      uVar18 = uVar5 ^ puVar11[2] ^ uVar17;
      uVar20 = uVar17 << 0x10 ^ uVar18;
      uVar17 = uVar5 ^ puVar11[3] ^ uVar15;
      uVar15 = (uVar15 << 0x10 ^ uVar17) >> 4;
      uVar17 = uVar15 + uVar17 * 0x10000000;
      uVar18 = uVar16 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar15 = uVar18 >> 0x10 ^ uVar18;
      uVar16 = (uint)ppcVar12 & uVar15;
      uVar15 = uVar8 & uVar15;
      uVar17 = uVar18 ^ puVar11[4] ^ uVar16;
      uVar20 = uVar16 << 0x10 ^ uVar17;
      uVar16 = uVar18 ^ puVar11[5] ^ uVar15;
      uVar15 = (uVar15 << 0x10 ^ uVar16) >> 4;
      uVar16 = uVar15 + uVar16 * 0x10000000;
      uVar17 = uVar5 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar17 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar16 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar16 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar17 >> 0x10 ^ uVar17;
      uVar15 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar16 = uVar17 ^ puVar11[6] ^ uVar15;
      uVar20 = uVar15 << 0x10 ^ uVar16;
      uVar15 = uVar17 ^ puVar11[7] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar15) >> 4;
      uVar15 = uVar5 + uVar15 * 0x10000000;
      uVar16 = uVar18 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar16 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar15 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar16 >> 0x10 ^ uVar16;
      uVar15 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar16 ^ puVar11[8] ^ uVar15;
      uVar20 = uVar15 << 0x10 ^ uVar18;
      uVar15 = uVar16 ^ puVar11[9] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar15) >> 4;
      uVar15 = uVar5 + uVar15 * 0x10000000;
      uVar15 = uVar17 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar15 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      iVar6 = iVar6 + -1;
      uVar5 = uVar15 >> 0x10 ^ uVar15;
      uVar17 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar15 ^ puVar11[10] ^ uVar17;
      uVar20 = uVar17 << 0x10 ^ uVar18;
      uVar17 = uVar15 ^ puVar11[0xb] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar17) >> 4;
      uVar17 = uVar5 + uVar17 * 0x10000000;
      uVar17 = uVar16 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar17 >> 0x10 ^ uVar17;
      uVar16 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar17 ^ puVar11[0xc] ^ uVar16;
      uVar20 = uVar16 << 0x10 ^ uVar18;
      uVar16 = uVar17 ^ puVar11[0xd] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar16) >> 4;
      uVar16 = uVar5 + uVar16 * 0x10000000;
      uVar16 = uVar15 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar16 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar16 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar16 >> 0x10 ^ uVar16;
      uVar15 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar16 ^ puVar11[0xe] ^ uVar15;
      uVar20 = uVar15 << 0x10 ^ uVar18;
      uVar15 = uVar16 ^ puVar11[0xf] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar15) >> 4;
      uVar15 = uVar5 + uVar15 * 0x10000000;
      uVar15 = uVar17 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar15 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar15 >> 0x10 ^ uVar15;
      uVar17 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar15 ^ puVar11[0x10] ^ uVar17;
      uVar20 = uVar17 << 0x10 ^ uVar18;
      uVar17 = uVar15 ^ puVar11[0x11] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar17) >> 4;
      uVar17 = uVar5 + uVar17 * 0x10000000;
      uVar17 = uVar16 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar17 >> 0x10 ^ uVar17;
      uVar16 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar17 ^ puVar11[0x12] ^ uVar16;
      uVar20 = uVar16 << 0x10 ^ uVar18;
      uVar16 = uVar17 ^ puVar11[0x13] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar16) >> 4;
      uVar16 = uVar5 + uVar16 * 0x10000000;
      uVar16 = uVar15 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar16 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar16 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar16 >> 0x10 ^ uVar16;
      uVar15 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar16 ^ puVar11[0x14] ^ uVar15;
      uVar20 = uVar15 << 0x10 ^ uVar18;
      uVar15 = uVar16 ^ puVar11[0x15] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar15) >> 4;
      uVar15 = uVar5 + uVar15 * 0x10000000;
      uVar15 = uVar17 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar15 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar15 >> 0x10 ^ uVar15;
      uVar17 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar15 ^ puVar11[0x16] ^ uVar17;
      uVar20 = uVar17 << 0x10 ^ uVar18;
      uVar17 = uVar15 ^ puVar11[0x17] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar17) >> 4;
      uVar17 = uVar5 + uVar17 * 0x10000000;
      uVar17 = uVar16 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar17 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar17 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar17 >> 0x10 ^ uVar17;
      uVar16 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar17 ^ puVar11[0x18] ^ uVar16;
      uVar20 = uVar16 << 0x10 ^ uVar18;
      uVar16 = uVar17 ^ puVar11[0x19] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar16) >> 4;
      uVar16 = uVar5 + uVar16 * 0x10000000;
      uVar16 = uVar15 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar16 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar16 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar16 >> 0x10 ^ uVar16;
      uVar15 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar16 ^ puVar11[0x1a] ^ uVar15;
      uVar20 = uVar15 << 0x10 ^ uVar18;
      uVar15 = uVar16 ^ puVar11[0x1b] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar15) >> 4;
      uVar15 = uVar5 + uVar15 * 0x10000000;
      uVar17 = uVar17 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar15 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar5 = uVar17 >> 0x10 ^ uVar17;
      uVar15 = (uint)ppcVar12 & uVar5;
      uVar5 = uVar8 & uVar5;
      uVar18 = uVar17 ^ puVar11[0x1c] ^ uVar15;
      uVar20 = uVar15 << 0x10 ^ uVar18;
      uVar15 = uVar17 ^ puVar11[0x1d] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar15) >> 4;
      uVar15 = uVar5 + uVar15 * 0x10000000;
      uVar16 = uVar16 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar20 >> 0x1a) + 0x180) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar20 & 0xfc)) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar18 << 0x10) >> 0x1a) + 0x80) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 8) >> 0x1a) + 0x100) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar15 >> 0x1a) + 0x1c0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar15 & 0xfc) + 0x100) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
               *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
      uVar15 = uVar16 >> 0x10;
      uVar18 = (uint)ppcVar12 & (uVar15 ^ uVar16);
      uVar5 = uVar8 & (uVar15 ^ uVar16);
      uVar20 = uVar16 ^ puVar11[0x1e] ^ uVar18;
      uVar22 = uVar18 << 0x10 ^ uVar20;
      uVar18 = uVar16 ^ puVar11[0x1f] ^ uVar5;
      uVar5 = (uVar5 << 0x10 ^ uVar18) >> 4;
      uVar18 = uVar5 + uVar18 * 0x10000000;
      uVar5 = uVar17 ^ *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar22 >> 0x1a) + 0x180) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar22 & 0xfc)) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar20 << 0x10) >> 0x1a) + 0x80) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + (((uVar22 << 8) >> 0x1a) + 0x100) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar18 >> 0x1a) + 0x1c0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + (uVar18 & 0xfc) + 0x100) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
              *(uint *)(PTR_DES_SPtrans_006a9674 + ((uVar5 * 0x100 >> 0x1a) + 0x140) * 4);
    } while (iVar6 != 0);
    uVar5 = (uVar5 >> 3) + uVar5 * 0x20000000;
    uVar15 = (uVar16 >> 3) + uVar16 * 0x20000000;
    uVar8 = (uVar5 >> 1 ^ uVar15) & 0x55555555;
    uVar15 = uVar15 ^ uVar8;
    uVar5 = uVar8 << 1 ^ uVar5;
    uVar8 = (uVar15 >> 8 ^ uVar5) & 0xff00ff;
    uVar5 = uVar5 ^ uVar8;
    uVar15 = uVar8 << 8 ^ uVar15;
    uVar8 = (uVar5 >> 2 ^ uVar15) & 0x33333333;
    uVar15 = uVar15 ^ uVar8;
    uVar5 = uVar8 << 2 ^ uVar5;
    uVar8 = (uVar15 >> 0x10 ^ uVar5) & 0xffff;
    uVar5 = uVar5 ^ uVar8;
    uVar15 = uVar8 << 0x10 ^ uVar15;
    uVar8 = (uVar5 >> 4 ^ uVar15) & 0xf0f0f0f;
    *puStack_e4 = uVar15 ^ uVar8;
    puStack_e4[1] = uVar8 << 4 ^ uVar5;
    return;
  }
  return;
}

