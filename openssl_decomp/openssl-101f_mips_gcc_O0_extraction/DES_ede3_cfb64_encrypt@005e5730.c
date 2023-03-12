
/* WARNING: Removing unreachable block (ram,0x005e689c) */
/* WARNING: Removing unreachable block (ram,0x005e61d0) */
/* WARNING: Removing unreachable block (ram,0x005e5f10) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

void DES_ede3_cfb64_encrypt
               (uchar *in,uchar *out,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int *num,int enc)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  _union_771 *p_Var4;
  _union_771 *p_Var5;
  int iVar6;
  DES_key_schedule *pDVar7;
  uint uVar8;
  DES_key_schedule *pDVar9;
  DES_key_schedule *pDVar10;
  uint uVar11;
  byte *pbVar12;
  uint *puVar13;
  DES_key_schedule *pDVar14;
  DES_key_schedule *pDVar15;
  DES_key_schedule *pDVar16;
  DES_key_schedule *pDVar17;
  byte bVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  undefined *puVar23;
  uint uVar24;
  uint uVar25;
  uchar *puVar26;
  DES_key_schedule *pDVar27;
  DES_key_schedule *pDVar28;
  uint *puVar29;
  DES_key_schedule *pDVar30;
  byte *pbVar31;
  uint uStack_224;
  uint uStack_220;
  byte abStack_21c [4];
  byte bStack_218;
  byte bStack_217;
  byte bStack_216;
  byte bStack_215;
  int iStack_214;
  uint uStack_210;
  DES_cblock *pauStack_20c;
  DES_key_schedule *pDStack_208;
  undefined4 uStack_204;
  byte *pbStack_200;
  DES_key_schedule *pDStack_1fc;
  DES_key_schedule *pDStack_1f8;
  DES_key_schedule *pDStack_1f4;
  uchar *puStack_1f0;
  undefined4 uStack_1ec;
  byte *pbStack_1d8;
  uint *puStack_1d4;
  DES_key_schedule *pDStack_1cc;
  uint *puStack_1c8;
  int *piStack_1c4;
  uint uStack_1bc;
  uint uStack_1b8;
  byte abStack_1b4 [4];
  byte bStack_1b0;
  byte bStack_1af;
  byte bStack_1ae;
  byte bStack_1ad;
  int iStack_1ac;
  DES_key_schedule *pDStack_1a8;
  DES_cblock *pauStack_1a4;
  DES_key_schedule *pDStack_1a0;
  DES_key_schedule *pDStack_19c;
  DES_key_schedule *pDStack_198;
  DES_key_schedule *pDStack_194;
  DES_key_schedule *pDStack_190;
  DES_key_schedule *pDStack_18c;
  DES_key_schedule *pDStack_188;
  code *pcStack_184;
  DES_key_schedule *pDStack_170;
  undefined4 uStack_16c;
  byte *pbStack_168;
  uint *puStack_164;
  DES_key_schedule *pDStack_160;
  DES_key_schedule *pDStack_15c;
  DES_key_schedule *pDStack_158;
  DES_key_schedule *pDStack_154;
  DES_key_schedule *pDStack_150;
  code **ppcStack_14c;
  int *piStack_148;
  uchar *puStack_144;
  DES_key_schedule *pDStack_140;
  DES_key_schedule *pDStack_13c;
  DES_key_schedule *pDStack_134;
  DES_key_schedule *pDStack_130;
  undefined uStack_12c;
  undefined uStack_12b;
  byte abStack_12a [2];
  undefined4 uStack_128;
  byte abStack_124 [8];
  int iStack_11c;
  DES_key_schedule *pDStack_118;
  uchar *puStack_114;
  DES_key_schedule *pDStack_110;
  DES_key_schedule *pDStack_10c;
  DES_key_schedule *pDStack_108;
  DES_key_schedule *pDStack_104;
  DES_key_schedule *pDStack_100;
  DES_key_schedule *pDStack_fc;
  DES_key_schedule *pDStack_f8;
  undefined4 uStack_f4;
  uint *puStack_e0;
  uchar *puStack_dc;
  int iStack_d8;
  DES_key_schedule *pDStack_d4;
  undefined4 uStack_d0;
  DES_key_schedule *pDStack_cc;
  DES_key_schedule **ppDStack_c8;
  DES_key_schedule **ppDStack_c4;
  undefined *puStack_c0;
  int *piStack_bc;
  int iStack_b8;
  uint uStack_b4;
  undefined4 *puStack_b0;
  DES_key_schedule *pDStack_ac;
  DES_key_schedule *pDStack_a8;
  undefined4 uStack_a4;
  DES_key_schedule *pDStack_9c;
  DES_key_schedule *pDStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  byte bStack_8c;
  undefined uStack_8b;
  undefined uStack_8a;
  undefined uStack_89;
  undefined uStack_88;
  undefined uStack_87;
  undefined uStack_86;
  undefined uStack_85;
  int iStack_84;
  DES_key_schedule *pDStack_80;
  DES_cblock *pauStack_7c;
  DES_key_schedule *pDStack_78;
  DES_key_schedule *pDStack_74;
  DES_key_schedule *pDStack_70;
  byte *pbStack_6c;
  undefined *puStack_68;
  DES_key_schedule *pDStack_64;
  DES_key_schedule *pDStack_60;
  code *pcStack_5c;
  DES_key_schedule *pDStack_50;
  DES_key_schedule *local_48;
  undefined4 uStack_44;
  DES_key_schedule *local_40;
  DES_key_schedule *local_3c;
  int iStack_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  pDStack_100 = (DES_key_schedule *)PTR___stack_chk_guard_006aabf0;
  pDVar30 = (DES_key_schedule *)&_gp;
  local_3c = (DES_key_schedule *)num;
  local_48 = (DES_key_schedule *)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_80 = (DES_key_schedule *)*num;
  pDVar15 = ks1;
  pbStack_6c = out;
  pDStack_fc = (DES_key_schedule *)length;
  if (enc == 0) {
    pDVar14 = (DES_key_schedule *)&local_34;
    pbVar12 = out;
    if (length != 0) {
      do {
        pDVar15 = ks3;
        if (pDStack_80 == (DES_key_schedule *)0x0) {
          local_30 = (uint)(*ivec)[7] << 0x18 |
                     (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4];
          local_34 = (uint)(*ivec)[3] << 0x18 |
                     (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0];
          local_40 = pDVar14;
          (**(code **)((int)pDVar30 + -0x5764))(pDVar14,ks1,ks2);
          pDVar15 = (DES_key_schedule *)(local_34 >> 0x10);
          (*ivec)[0] = (uchar)local_34;
          length = local_30 >> 8;
          (*ivec)[4] = (uchar)local_30;
          (*ivec)[1] = (uchar)(local_34 >> 8);
          (*ivec)[2] = (uchar)(local_34 >> 0x10);
          (*ivec)[5] = (uchar)(local_30 >> 8);
          (*ivec)[3] = (uchar)(local_34 >> 0x18);
          (*ivec)[6] = (uchar)(local_30 >> 0x10);
          (*ivec)[7] = (uchar)(local_30 >> 0x18);
          pDVar14 = local_40;
          pDVar30 = local_48;
        }
        bVar18 = ((_union_771 *)in)->cblock[0];
        bVar2 = pDStack_80->ks[0].cblock[(int)*ivec];
        out = (uchar *)(uint)bVar2;
        pDStack_fc = (DES_key_schedule *)((int)pDStack_fc[-1].ks + 0x7f);
        pDStack_80->ks[0].cblock[(int)*ivec] = bVar18;
        in = (uchar *)((int)(_union_771 *)in + 1);
        pDStack_80 = (DES_key_schedule *)((uint)((int)pDStack_80->ks + 1) & 7);
        *pbVar12 = bVar18 ^ bVar2;
        pbStack_6c = pbVar12 + 1;
        pbVar12 = pbVar12 + 1;
      } while (pDStack_fc != (DES_key_schedule *)0x0);
    }
  }
  else if (length != 0) {
    pDVar17 = (DES_key_schedule *)&local_34;
    pbVar12 = out;
    pDVar14 = local_40;
    do {
      local_40 = pDVar17;
      pDVar17 = local_40;
      if (pDStack_80 == (DES_key_schedule *)0x0) {
        local_30 = (uint)(*ivec)[7] << 0x18 |
                   (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4];
        local_34 = (uint)(*ivec)[3] << 0x18 |
                   (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0];
        (**(code **)((int)local_48[-0xaf].ks + 0x1c))(local_40,ks1,ks2,ks3);
        pDVar15 = (DES_key_schedule *)(local_34 >> 0x10);
        (*ivec)[0] = (uchar)local_34;
        length = local_30 >> 8;
        (*ivec)[4] = (uchar)local_30;
        (*ivec)[1] = (uchar)(local_34 >> 8);
        (*ivec)[2] = (uchar)(local_34 >> 0x10);
        (*ivec)[5] = (uchar)(local_30 >> 8);
        (*ivec)[3] = (uchar)(local_34 >> 0x18);
        (*ivec)[6] = (uchar)(local_30 >> 0x10);
        (*ivec)[7] = (uchar)(local_30 >> 0x18);
        pDVar14 = local_40;
        pDVar17 = local_40;
      }
      local_40 = pDVar14;
      p_Var4 = pDStack_80->ks;
      p_Var5 = (_union_771 *)in;
      pbStack_6c = pbVar12 + 1;
      bVar18 = p_Var4->cblock[(int)*ivec];
      out = (uchar *)(uint)bVar18;
      pDStack_fc = (DES_key_schedule *)((int)pDStack_fc[-1].ks + 0x7f);
      in = (uchar *)((int)(_union_771 *)in + 1);
      pDStack_80 = (DES_key_schedule *)((uint)((int)pDStack_80->ks + 1) & 7);
      bVar18 = p_Var5->cblock[0] ^ bVar18;
      *pbVar12 = bVar18;
      p_Var4->cblock[(int)*ivec] = bVar18;
      pDVar30 = local_48;
      pbVar12 = pbStack_6c;
      pDVar14 = local_40;
    } while (pDStack_fc != (DES_key_schedule *)0x0);
  }
  iVar6 = *(int *)pDStack_100;
  local_3c->ks[0].deslong[0] = (uint)pDStack_80;
  if (local_2c == iVar6) {
    return;
  }
  pcStack_5c = DES_ede3_cfb_encrypt;
  pDVar14 = local_3c;
  (*(code *)pDVar30[-0xa7].ks[0xb].deslong[0])();
  uStack_d0 = uStack_44;
  piStack_bc = (int *)PTR___stack_chk_guard_006aabf0;
  puStack_68 = (undefined *)pDStack_100;
  pDStack_cc = local_40;
  pDStack_70 = ks3;
  pDStack_74 = ks2;
  pauStack_7c = ivec;
  puStack_e0 = (uint *)&_gp;
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_d4 = local_48;
  pDStack_ac = local_3c;
  pDStack_1f4 = local_3c;
  pDVar30 = local_48;
  pDStack_118 = pDStack_80;
  pDStack_1a0 = ks1;
  pDStack_188 = (DES_key_schedule *)in;
  pDStack_78 = ks1;
  pDStack_64 = pDStack_fc;
  pDStack_60 = (DES_key_schedule *)in;
  if (length < 0x41) {
    pDVar30 = (DES_key_schedule *)((int)(_union_771 *)length + 7);
    pDVar27 = (DES_key_schedule *)((uint)pDVar30 >> 3);
    pDVar17 = (DES_key_schedule *)
              ((uint)local_3c->ks[0].cblock[7] << 0x18 |
              (uint)local_3c->ks[0].cblock[5] << 8 | (uint)local_3c->ks[0].cblock[6] << 0x10 |
              (uint)local_3c->ks[0].cblock[4]);
    pDVar9 = (DES_key_schedule *)
             ((uint)local_3c->ks[0].cblock[1] << 8 | (uint)local_3c->ks[0].cblock[2] << 0x10 |
              (uint)local_3c->ks[0].cblock[0] | (uint)local_3c->ks[0].cblock[3] << 0x18);
    ivec = (DES_cblock *)out;
    ks2 = pDVar27;
    if (iStack_38 == 0) {
      if (pDVar27 <= pDVar15) {
        if (-1 < length) {
          pDVar30 = (DES_key_schedule *)length;
        }
        puStack_b0 = &uStack_94;
        uStack_b4 = length & 7;
        iStack_b8 = (int)puStack_b0 + ((int)pDVar30 >> 3);
        pDStack_100 = (DES_key_schedule *)(length & 0x80000007);
        if ((int)pDStack_100 < 0) {
          pDStack_100 = (DES_key_schedule *)
                        (((uint)((int)pDStack_100[-1].ks + 0x7f) | 0xfffffff8) + 1);
        }
        pDStack_1a0 = (DES_key_schedule *)(8 - (int)pDStack_100);
        ppDStack_c8 = &pDStack_9c;
        pDVar28 = (DES_key_schedule *)((int)pDVar15 - (int)pDVar27);
        ppDStack_c4 = (DES_key_schedule **)(&PTR_LAB_00675504 + (int)pDVar27);
        puStack_c0 = &UNK_0067554c + (int)pDVar27 * 4;
        pDStack_188 = (DES_key_schedule *)(uint)(pDVar27 < (DES_key_schedule *)&DAT_00000009);
        pDStack_118 = pDVar14;
        pDVar30 = pDVar17;
        pDVar14 = pDVar9;
        pDStack_50 = (DES_key_schedule *)length;
        do {
          pDStack_118 = (DES_key_schedule *)((int)pDStack_118->ks + (int)pDVar27 * 2);
          pDStack_9c = pDVar14;
          pDStack_98 = pDVar30;
          (*(code *)puStack_e0[-0x15d9])(ppDStack_c8,pDStack_d4,uStack_d0,pDStack_cc);
          if (pDStack_188 != (DES_key_schedule *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e5e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)*ppDStack_c4)();
            return;
          }
          pDVar17 = (DES_key_schedule *)0x0;
          pDVar15 = (DES_key_schedule *)0x0;
          if (pDStack_50 == (DES_key_schedule *)&DAT_00000020) {
            pDVar17 = (DES_key_schedule *)0x0;
            pDVar9 = pDVar30;
          }
          else {
            pDVar9 = pDVar15;
            if (pDStack_50 != (DES_key_schedule *)&DAT_00000040) {
              bStack_8c = 0;
              uStack_8a = 0;
              uStack_94 = CONCAT22(CONCAT11((char)pDVar14,(char)((uint)pDVar14 >> 8)),
                                   CONCAT11((char)((uint)pDVar14 >> 0x10),
                                            (char)((uint)pDVar14 >> 0x18)));
              uStack_8b = 0;
              uStack_85 = 0;
              uStack_90 = CONCAT31(CONCAT21(CONCAT11((char)pDVar30,(char)((uint)pDVar30 >> 8)),
                                            (char)((uint)pDVar30 >> 0x10)),
                                   (char)((uint)pDVar30 >> 0x18));
              uStack_89 = 0;
              uStack_88 = 0;
              uStack_87 = 0;
              uStack_86 = 0;
              if (uStack_b4 == 0) {
                uStack_a4 = 0;
                pDStack_a8 = (DES_key_schedule *)0x0;
                (*(code *)puStack_e0[-0x14b9])(puStack_b0,iStack_b8,8);
              }
              else {
                uStack_a4 = 0;
                pDStack_a8 = (DES_key_schedule *)0x0;
                (*(code *)puStack_e0[-0x14b9])(puStack_b0,iStack_b8,9);
                uStack_94 = CONCAT31(CONCAT21(CONCAT11(uStack_94._0_1_ << ((uint)pDStack_100 & 0x1f)
                                                       | (byte)((int)(uint)uStack_94._1_1_ >>
                                                               ((uint)pDStack_1a0 & 0x1f)),
                                                       uStack_94._1_1_ << ((uint)pDStack_100 & 0x1f)
                                                       | (byte)((int)(uint)uStack_94._2_1_ >>
                                                               ((uint)pDStack_1a0 & 0x1f))),
                                              uStack_94._2_1_ << ((uint)pDStack_100 & 0x1f) |
                                              (byte)((int)(uStack_94 & 0xff) >>
                                                    ((uint)pDStack_1a0 & 0x1f))),
                                     (char)uStack_94 << ((uint)pDStack_100 & 0x1f) |
                                     (byte)((int)(uint)uStack_90._0_1_ >> ((uint)pDStack_1a0 & 0x1f)
                                           ));
                uStack_90 = CONCAT31(CONCAT21(CONCAT11(uStack_90._0_1_ << ((uint)pDStack_100 & 0x1f)
                                                       | (byte)((int)(uint)uStack_90._1_1_ >>
                                                               ((uint)pDStack_1a0 & 0x1f)),
                                                       uStack_90._1_1_ << ((uint)pDStack_100 & 0x1f)
                                                       | (byte)((int)(uint)uStack_90._2_1_ >>
                                                               ((uint)pDStack_1a0 & 0x1f))),
                                              uStack_90._2_1_ << ((uint)pDStack_100 & 0x1f) |
                                              (byte)((int)(uStack_90 & 0xff) >>
                                                    ((uint)pDStack_1a0 & 0x1f))),
                                     (byte)((int)(uint)bStack_8c >> ((uint)pDStack_1a0 & 0x1f)) |
                                     (char)uStack_90 << ((uint)pDStack_100 & 0x1f));
              }
              pDVar17 = (DES_key_schedule *)
                        ((((uStack_90 >> 0x10) << 0x18 | (uStack_90 >> 0x18) << 0x10) >> 0x10) +
                        ((uStack_90 & 0xff) << 8 | uStack_90 >> 8 & 0xff) * 0x10000);
              pDVar15 = pDStack_a8;
              pDVar9 = (DES_key_schedule *)
                       ((((uStack_94 >> 0x10) << 0x18 | (uStack_94 >> 0x18) << 0x10) >> 0x10) +
                       ((uStack_94 & 0xff) << 8 | uStack_94 >> 8 & 0xff) * 0x10000);
            }
          }
          out = out + (int)pDVar27 * 2;
          pDVar15 = (DES_key_schedule *)((uint)pDVar15 ^ (uint)pDStack_9c);
          bVar3 = pDVar27 <= pDVar28;
          pDVar28 = (DES_key_schedule *)((int)pDVar28 - (int)pDVar27);
          ivec = (DES_cblock *)out;
          ks2 = pDVar17;
          pDVar30 = pDVar17;
          ks3 = pDVar27;
          length = (long)pDVar28;
          pDStack_fc = pDVar9;
          pDVar14 = pDVar9;
        } while (bVar3);
      }
    }
    else if (pDVar27 <= pDVar15) {
      if (-1 < length) {
        pDVar30 = (DES_key_schedule *)length;
      }
      puStack_b0 = &uStack_94;
      uStack_b4 = length & 7;
      iStack_b8 = (int)puStack_b0 + ((int)pDVar30 >> 3);
      pDStack_118 = (DES_key_schedule *)(length & 0x80000007);
      if ((int)pDStack_118 < 0) {
        pDStack_118 = (DES_key_schedule *)
                      (((uint)((int)pDStack_118[-1].ks + 0x7f) | 0xfffffff8) + 1);
      }
      pDStack_100 = (DES_key_schedule *)(&DAT_006754e0 + (int)pDVar27 * 4);
      puStack_c0 = &UNK_00675528 + (int)pDVar27 * 4;
      ppDStack_c4 = &pDStack_9c;
      ks2 = (DES_key_schedule *)((int)pDVar15 - (int)pDVar27);
      ppDStack_c8 = (DES_key_schedule **)(uint)(pDVar27 < (DES_key_schedule *)&DAT_00000009);
      pDStack_1a0 = (DES_key_schedule *)(8 - (int)pDStack_118);
      pDVar30 = pDVar17;
      pDVar28 = pDVar9;
      pDStack_188 = pDVar14;
      pDStack_50 = (DES_key_schedule *)length;
      do {
        pDStack_188 = (DES_key_schedule *)((int)pDStack_188->ks + (int)pDVar27 * 2);
        pDVar15 = pDStack_cc;
        pDStack_9c = pDVar28;
        pDStack_98 = pDVar30;
        (*(code *)puStack_e0[-0x15d9])(ppDStack_c4,pDStack_d4,uStack_d0);
        if (ppDStack_c8 != (DES_key_schedule **)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e5bac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)pDStack_100->ks[0].deslong[0])();
          return;
        }
        ivec = (DES_cblock *)((int)ivec + (int)pDVar27 * 2);
        pDVar17 = pDStack_9c;
        pDVar9 = pDVar30;
        if ((pDStack_50 != (DES_key_schedule *)&DAT_00000020) &&
           (pDVar17 = pDStack_98, pDVar9 = pDStack_9c,
           pDStack_50 != (DES_key_schedule *)&DAT_00000040)) {
          bStack_8c = (byte)pDStack_9c;
          uStack_94 = CONCAT31(CONCAT21(CONCAT11((char)pDVar28,(char)((uint)pDVar28 >> 8)),
                                        (char)((uint)pDVar28 >> 0x10)),(char)((uint)pDVar28 >> 0x18)
                              );
          pDVar15 = (DES_key_schedule *)((uint)pDVar30 >> 8);
          uStack_8b = (undefined)((uint)pDStack_9c >> 8);
          uStack_8a = (undefined)((uint)pDStack_9c >> 0x10);
          uStack_89 = (undefined)((uint)pDStack_9c >> 0x18);
          uStack_90._0_1_ = (byte)pDVar30;
          uStack_90 = (uint)CONCAT12(uStack_90._0_1_,
                                     CONCAT11((char)((uint)pDVar30 >> 8),
                                              (char)((uint)pDVar30 >> 0x10))) << 8;
          uStack_90 = uStack_90 | (uint)pDVar30 >> 0x18;
          uStack_88 = SUB41(pDStack_98,0);
          uStack_87 = (undefined)((uint)pDStack_98 >> 8);
          uStack_86 = (undefined)((uint)pDStack_98 >> 0x10);
          uStack_85 = (undefined)((uint)pDStack_98 >> 0x18);
          if (uStack_b4 == 0) {
            (*(code *)puStack_e0[-0x14b9])(puStack_b0,iStack_b8,8);
          }
          else {
            (*(code *)puStack_e0[-0x14b9])(puStack_b0,iStack_b8,9);
            pDVar15 = (DES_key_schedule *)
                      ((uStack_94 >> 0x18) << ((uint)pDStack_118 & 0x1f) |
                      (int)(uint)uStack_94._1_1_ >> ((uint)pDStack_1a0 & 0x1f));
            uStack_94._0_1_ = (char)pDVar15;
            uStack_94 = CONCAT31(CONCAT12(uStack_94._0_1_,
                                          CONCAT11(uStack_94._1_1_ << ((uint)pDStack_118 & 0x1f) |
                                                   (byte)((int)(uint)uStack_94._2_1_ >>
                                                         ((uint)pDStack_1a0 & 0x1f)),
                                                   uStack_94._2_1_ << ((uint)pDStack_118 & 0x1f) |
                                                   (byte)((int)(uStack_94 & 0xff) >>
                                                         ((uint)pDStack_1a0 & 0x1f)))),
                                 (char)uStack_94 << ((uint)pDStack_118 & 0x1f) |
                                 (byte)((int)(uint)uStack_90._0_1_ >> ((uint)pDStack_1a0 & 0x1f)));
            uStack_90 = CONCAT31(CONCAT21(CONCAT11(uStack_90._0_1_ << ((uint)pDStack_118 & 0x1f) |
                                                   (byte)((int)(uint)uStack_90._1_1_ >>
                                                         ((uint)pDStack_1a0 & 0x1f)),
                                                   uStack_90._1_1_ << ((uint)pDStack_118 & 0x1f) |
                                                   (byte)((int)(uint)uStack_90._2_1_ >>
                                                         ((uint)pDStack_1a0 & 0x1f))),
                                          uStack_90._2_1_ << ((uint)pDStack_118 & 0x1f) |
                                          (byte)((int)(uStack_90 & 0xff) >>
                                                ((uint)pDStack_1a0 & 0x1f))),
                                 (byte)((int)(uint)bStack_8c >> ((uint)pDStack_1a0 & 0x1f)) |
                                 (char)uStack_90 << ((uint)pDStack_118 & 0x1f));
          }
          pDVar17 = (DES_key_schedule *)
                    ((((uStack_90 >> 0x10) << 0x18 | (uStack_90 >> 0x18) << 0x10) >> 0x10) +
                    ((uStack_90 & 0xff) << 8 | uStack_90 >> 8 & 0xff) * 0x10000);
          pDVar9 = (DES_key_schedule *)
                   ((((uStack_94 >> 0x10) << 0x18 | (uStack_94 >> 0x18) << 0x10) >> 0x10) +
                   ((uStack_94 & 0xff) << 8 | uStack_94 >> 8 & 0xff) * 0x10000);
        }
        bVar3 = pDVar27 <= ks2;
        ks2 = (DES_key_schedule *)((int)ks2 - (int)pDVar27);
        pDVar30 = pDVar17;
        ks3 = pDVar17;
        length = (long)pDVar27;
        pDVar28 = pDVar9;
        pDStack_fc = pDVar9;
      } while (bVar3);
    }
    out = (uchar *)((uint)pDVar9 >> 0x10);
    pDStack_1f4 = (DES_key_schedule *)((uint)pDVar17 >> 8);
    pDStack_ac->ks[0].cblock[0] = (uchar)pDVar9;
    pDStack_ac->ks[0].cblock[4] = (char)pDVar17;
    pDStack_ac->ks[0].cblock[1] = (uchar)((uint)pDVar9 >> 8);
    pDStack_ac->ks[0].cblock[2] = (uchar)((uint)pDVar9 >> 0x10);
    pDStack_ac->ks[0].cblock[3] = (uchar)((uint)pDVar9 >> 0x18);
    pDStack_ac->ks[0].cblock[5] = (uchar)((uint)pDVar17 >> 8);
    pDStack_ac->ks[0].cblock[6] = (uchar)((uint)pDVar17 >> 0x10);
    pDStack_ac->ks[0].cblock[7] = (uchar)((uint)pDVar17 >> 0x18);
    pDVar30 = pDStack_ac;
  }
  if (iStack_84 == *piStack_bc) {
    return;
  }
  uStack_f4 = 0x5e637c;
  (*(code *)puStack_e0[-0x14ca])();
  puStack_164 = puStack_e0;
  piStack_148 = (int *)PTR___stack_chk_guard_006aabf0;
  puStack_144 = puStack_dc;
  pDStack_170 = (DES_key_schedule *)&_gp;
  iStack_11c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_1f0 = out;
  pDVar14 = pDVar30;
  pDStack_1cc = pDVar15;
  pDStack_1a8 = pDStack_118;
  pDStack_198 = ks3;
  pDStack_1fc = (DES_key_schedule *)length;
  pDStack_1f8 = pDStack_100;
  pDStack_18c = pDStack_fc;
  puStack_114 = (uchar *)ivec;
  pDStack_110 = pDStack_1a0;
  pDStack_10c = ks2;
  pDStack_108 = ks3;
  pDStack_104 = (DES_key_schedule *)length;
  pDStack_f8 = pDStack_188;
  if ((undefined *)((int)pDVar30[-1].ks + 0x7f) < &DAT_00000040) {
    pDStack_198 = (DES_key_schedule *)((int)pDVar30 >> 3);
    pDVar14 = (DES_key_schedule *)((uint)puStack_dc[7] << 0x18);
    pDVar9 = (DES_key_schedule *)
             ((uint)pDVar14 |
             (uint)puStack_dc[5] << 8 | (uint)puStack_dc[6] << 0x10 | (uint)puStack_dc[4]);
    pDStack_1fc = (DES_key_schedule *)((int)((int)pDVar30->ks + 7) >> 3);
    pDVar17 = (DES_key_schedule *)
              ((uint)puStack_dc[1] << 8 | (uint)puStack_dc[2] << 0x10 | (uint)*puStack_dc |
              (uint)puStack_dc[3] << 0x18);
    if (iStack_d8 == 0) {
      pDStack_1a8 = pDStack_1f4;
      if (pDStack_1fc <= pDVar15) {
        ppcStack_14c = (code **)(&PTR_LAB_00675594 + (int)pDStack_1fc);
        pDStack_1cc = (DES_key_schedule *)((int)pDVar15 - (int)pDStack_1fc);
        pDVar27 = (DES_key_schedule *)&pDStack_134;
        pDVar15 = (DES_key_schedule *)((int)pDStack_1fc[-1].ks + 0x7f);
        pDStack_18c = (DES_key_schedule *)&uStack_12c;
        pDStack_1f8 = (DES_key_schedule *)(&PTR_LAB_006755b8 + (int)pDStack_1fc);
        pDStack_188 = (DES_key_schedule *)(uint)(pDStack_1fc < (DES_key_schedule *)&DAT_00000009);
        pDStack_15c = (DES_key_schedule *)((uint)pDVar30 & 7);
        pDVar28 = pDVar17;
        do {
          pDVar17 = pDVar9;
          pDVar14 = (DES_key_schedule *)0x1;
          pDStack_160 = pDVar27;
          pDStack_158 = pDStack_1cc;
          pDStack_154 = pDVar30;
          pDStack_150 = pDVar15;
          pDStack_134 = pDVar28;
          pDStack_130 = pDVar17;
          (*(code *)pDStack_170[-0xd2].ks[1].deslong[0])(pDVar27,puStack_164);
          if (pDStack_188 != (DES_key_schedule *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e666c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**ppcStack_14c)();
            return;
          }
          bVar18 = (pDStack_1fc->ks[0].cblock + (int)pDStack_1f4->ks[0].cblock)[-1];
          pDVar9 = (DES_key_schedule *)(uint)bVar18;
          pDStack_1f4 = (DES_key_schedule *)
                        (pDStack_1fc->ks[0].cblock + (int)pDStack_1f4->ks[0].cblock +
                        (int)pDStack_150);
          pDVar16 = pDStack_158;
          pDVar15 = pDStack_150;
          pDVar30 = pDStack_154;
          pDVar27 = pDStack_160;
          if (pDStack_154 != (DES_key_schedule *)&DAT_00000020) {
            if (pDStack_154 == (DES_key_schedule *)&DAT_00000040) {
              pDVar17 = pDVar9;
              pDVar9 = (DES_key_schedule *)0x0;
            }
            else {
              abStack_124[0] = bVar18;
              abStack_124[1] = 0;
              abStack_124[2] = 0;
              _uStack_12c = CONCAT31(CONCAT21(CONCAT11((char)pDVar28,(char)((uint)pDVar28 >> 8)),
                                              (char)((uint)pDVar28 >> 0x10)),
                                     (char)((uint)pDVar28 >> 0x18));
              uStack_128 = CONCAT31(CONCAT21(CONCAT11((char)pDVar17,(char)((uint)pDVar17 >> 8)),
                                             (char)((uint)pDVar17 >> 0x10)),
                                    (char)((uint)pDVar17 >> 0x18));
              abStack_124[3] = 0;
              abStack_124[4] = 0;
              abStack_124[5] = 0;
              abStack_124[6] = 0;
              abStack_124[7] = 0;
              if (pDStack_15c == (DES_key_schedule *)0x0) {
                pDVar14 = (DES_key_schedule *)&DAT_00000008;
                pDStack_13c = pDStack_160;
                pDStack_140 = pDStack_150;
                pDStack_150 = pDStack_154;
                pDStack_154 = pDStack_158;
                pDStack_160 = (DES_key_schedule *)0x0;
                pDStack_158 = pDVar9;
                (**(code **)((int)pDStack_170[-0xa6].ks + 0x1c))
                          (pDStack_18c,(undefined *)((int)pDStack_198->ks + (int)pDStack_18c->ks));
                bVar18 = (byte)pDStack_158;
                pDVar16 = pDStack_154;
                pDVar15 = pDStack_140;
                pDVar30 = pDStack_150;
                pDVar27 = pDStack_13c;
              }
              else {
                pDVar14 = (DES_key_schedule *)((int)&pDStack_118 + (int)pDStack_198);
                uVar11 = 8 - (int)pDStack_15c;
                _uStack_12b = (uint3)(byte)(*(char *)((int)&uStack_12c +
                                                     (int)(pDStack_198->ks[0].cblock + 1)) <<
                                            ((uint)pDStack_15c & 0x1f) |
                                           (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                                      (int)(pDStack_198->ks[0].
                                                                            cblock + 2)) >>
                                                 (uVar11 & 0x1f))) << 0x10;
                _uStack_12c = (uint3)(((uint)(byte)(*(char *)((int)&uStack_12c + (int)pDStack_198)
                                                    << ((uint)pDStack_15c & 0x1f) |
                                                   (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                                              (int)(pDStack_198->ks
                                                                                    [0].cblock + 1))
                                                         >> (uVar11 & 0x1f))) << 0x18) >> 8) |
                              _uStack_12b >> 8 |
                              (uint3)(byte)(*(char *)((int)&uStack_12c +
                                                     (int)(pDStack_198->ks[0].cblock + 2)) <<
                                            ((uint)pDStack_15c & 0x1f) |
                                           (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                                      (int)(pDStack_198->ks[0].
                                                                            cblock + 3)) >>
                                                 (uVar11 & 0x1f)));
                _uStack_12c = CONCAT31(_uStack_12c,
                                       *(char *)((int)&uStack_12c +
                                                (int)(pDStack_198->ks[0].cblock + 3)) <<
                                       ((uint)pDStack_15c & 0x1f) |
                                       (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                                  (int)(pDStack_198->ks[0].cblock +
                                                                       4)) >> (uVar11 & 0x1f)));
                uStack_128._1_3_ =
                     (uint3)(byte)(*(char *)((int)&uStack_12c + (int)(pDStack_198->ks[0].cblock + 5)
                                            ) << ((uint)pDStack_15c & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                             (int)(pDStack_198->ks[0].cblock + 6))
                                        >> (uVar11 & 0x1f))) << 0x10;
                uStack_128._0_3_ =
                     (uint3)(((uint)(byte)(*(char *)((int)&uStack_12c +
                                                    (int)(pDStack_198->ks[0].cblock + 4)) <<
                                           ((uint)pDStack_15c & 0x1f) |
                                          (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                                     (int)(pDStack_198->ks[0].cblock
                                                                          + 5)) >> (uVar11 & 0x1f)))
                             << 0x18) >> 8) | uStack_128._1_3_ >> 8 |
                     (uint3)(byte)(*(char *)((int)&uStack_12c + (int)(pDStack_198->ks[0].cblock + 6)
                                            ) << ((uint)pDStack_15c & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                             (int)(pDStack_198->ks[0].cblock + 7))
                                        >> (uVar11 & 0x1f)));
                uStack_128 = CONCAT31(uStack_128._0_3_,
                                      (byte)((int)(uint)abStack_124[(int)pDStack_198] >>
                                            (uVar11 & 0x1f)) |
                                      *(char *)((int)&uStack_12c +
                                               (int)(pDStack_198->ks[0].cblock + 7)) <<
                                      ((uint)pDStack_15c & 0x1f));
              }
              pDVar17 = (DES_key_schedule *)
                        ((((_uStack_12c >> 0x10) << 0x18 | (_uStack_12c >> 0x18) << 0x10) >> 0x10) +
                        ((_uStack_12c & 0xff) << 8 | _uStack_12c >> 8 & 0xff) * 0x10000);
              pDVar9 = (DES_key_schedule *)
                       ((((uStack_128 >> 0x10) << 0x18 | (uStack_128 >> 0x18) << 0x10) >> 0x10) +
                       ((uStack_128 & 0xff) << 8 | uStack_128 >> 8 & 0xff) * 0x10000);
            }
          }
          (*(DES_cblock *)(out + (int)pDStack_1fc + -1))[0] = bVar18 ^ (byte)pDStack_134;
          pDStack_1cc = (DES_key_schedule *)((int)pDVar16 - (int)pDStack_1fc);
          out = out + (int)pDStack_1fc + (int)pDVar15;
          pDStack_1a8 = pDStack_1f4;
          pDVar28 = pDVar17;
        } while (pDStack_1fc <= pDVar16);
      }
    }
    else {
      pDStack_18c = (DES_key_schedule *)(&switchD_005e64e8::switchdataD_00675570 + (int)pDStack_1fc)
      ;
      pDStack_1f8 = (DES_key_schedule *)(&PTR_LAB_006755dc + (int)pDStack_1fc);
      pDStack_1cc = (DES_key_schedule *)&pDStack_134;
      pDVar27 = (DES_key_schedule *)((uint)pDVar30 & 7);
      pDVar28 = pDVar17;
      pDVar16 = pDVar9;
      while (pDVar9 = pDVar16, pDVar17 = pDVar28, pDStack_1a8 = pDStack_1f4, pDStack_1fc <= pDVar15)
      {
        pDVar14 = (DES_key_schedule *)0x1;
        pDStack_188 = (DES_key_schedule *)(uint)(pDStack_1fc < (DES_key_schedule *)&DAT_00000009);
        puVar26 = pDStack_1fc->ks[0].cblock + (int)pDStack_1f4->ks[0].cblock;
        pDStack_160 = pDStack_1cc;
        pDStack_15c = pDVar15;
        pDStack_158 = pDVar27;
        pDStack_154 = pDVar30;
        pDStack_134 = pDVar17;
        pDStack_130 = pDVar9;
        (*(code *)pDStack_170[-0xd2].ks[1].deslong[0])(pDStack_1cc,puStack_164);
        pDVar30 = pDStack_154;
        pDVar27 = pDStack_158;
        pDVar15 = (DES_key_schedule *)((int)pDStack_15c - (int)pDStack_1fc);
        if (pDStack_188 == (DES_key_schedule *)0x0) {
switchD_005e64e8_caseD_5e6bf4:
          uVar11 = 0;
          uVar8 = 0;
        }
        else {
          switch((uint)pDStack_18c->ks[0].deslong[0] & 0xfffffffe) {
          case 0x5e6918:
            uVar11 = 0;
            break;
          case 0x5e6bb4:
            uVar11 = 0;
            goto LAB_005e6948;
          case 0x5e6bbc:
            uVar11 = 0;
            pDVar14 = (DES_key_schedule *)0x0;
            goto LAB_005e6954;
          case 0x5e6bc8:
            uVar11 = 0;
            uVar8 = 0;
            goto LAB_005e6964;
          case 0x5e6bdc:
            uVar11 = 0;
            goto LAB_005e692c;
          case 0x5e6be4:
            uVar11 = 0;
            goto LAB_005e693c;
          case 0x5e6bf4:
            goto switchD_005e64e8_caseD_5e6bf4;
          case 0x5e6c10:
            pbVar12 = puVar26 + -1;
            puVar26 = puVar26 + -1;
            uVar11 = (uint)*pbVar12 << 0x18;
          }
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar11 = (uint)*pbVar12 << 0x10 | uVar11;
LAB_005e692c:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar11 = (uint)*pbVar12 << 8 | uVar11;
LAB_005e693c:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar11 = *pbVar12 | uVar11;
LAB_005e6948:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          pDVar14 = (DES_key_schedule *)((uint)*pbVar12 << 0x18);
LAB_005e6954:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar8 = (uint)*pbVar12 << 0x10 | (uint)pDVar14;
LAB_005e6964:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar8 = (uint)*pbVar12 << 8 | uVar8;
        }
        puVar23 = (undefined *)((int)pDStack_1fc[-1].ks + 0x7f);
        pDStack_1f4 = (DES_key_schedule *)(puVar26 + (int)puVar23);
        pDVar7 = (DES_key_schedule *)((puVar26[-1] | uVar8) ^ (uint)pDStack_134);
        pDVar10 = (DES_key_schedule *)(uVar11 ^ (uint)pDStack_130);
        if (pDStack_188 != (DES_key_schedule *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e69a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)pDStack_1f8->ks[0].deslong[0])();
          return;
        }
        (*(DES_cblock *)(out + (int)pDStack_1fc + -1))[0] = (byte)pDVar7;
        out = out + (int)pDStack_1fc + (int)puVar23;
        pDStack_1cc = pDStack_160;
        pDVar28 = pDVar9;
        pDVar16 = pDVar7;
        if ((pDStack_154 != (DES_key_schedule *)&DAT_00000020) &&
           (pDVar14 = (DES_key_schedule *)((uint)pDVar17 >> 0x10), pDVar28 = pDVar7,
           pDVar16 = pDVar10, pDStack_154 != (DES_key_schedule *)&DAT_00000040)) {
          abStack_124[0] = (byte)pDVar7;
          abStack_124[1] = (char)((uint)pDVar7 >> 8);
          abStack_124[2] = (char)((uint)pDVar7 >> 0x10);
          _uStack_12c = CONCAT31(CONCAT21(CONCAT11((char)pDVar17,(char)((uint)pDVar17 >> 8)),
                                          (char)((uint)pDVar17 >> 0x10)),
                                 (char)((uint)pDVar17 >> 0x18));
          uStack_128 = CONCAT31(CONCAT21(CONCAT11((char)pDVar9,(char)((uint)pDVar9 >> 8)),
                                         (char)((uint)pDVar9 >> 0x10)),(char)((uint)pDVar9 >> 0x18))
          ;
          abStack_124[3] = (char)((uint)pDVar7 >> 0x18);
          abStack_124[4] = (char)pDVar10;
          abStack_124[5] = (char)((uint)pDVar10 >> 8);
          abStack_124[6] = (char)((uint)pDVar10 >> 0x10);
          abStack_124[7] = (char)((uint)pDVar10 >> 0x18);
          if (pDStack_158 == (DES_key_schedule *)0x0) {
            pDVar14 = (DES_key_schedule *)&DAT_00000008;
            pDStack_154 = pDStack_160;
            pDStack_158 = pDVar30;
            pDStack_15c = pDVar27;
            pDStack_160 = pDVar15;
            (**(code **)((int)pDStack_170[-0xa6].ks + 0x1c))
                      (&uStack_12c,(int)&uStack_12c + (int)pDStack_198);
            pDStack_1cc = pDStack_154;
            pDVar27 = pDStack_15c;
            pDVar15 = pDStack_160;
            pDVar30 = pDStack_158;
          }
          else {
            uVar11 = 8 - (int)pDStack_158;
            _uStack_12b = (uint3)(byte)(*(char *)((int)&uStack_12c +
                                                 (int)(pDStack_198->ks[0].cblock + 1)) <<
                                        ((uint)pDStack_158 & 0x1f) |
                                       (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                                  (int)(pDStack_198->ks[0].cblock +
                                                                       2)) >> (uVar11 & 0x1f))) <<
                          0x10;
            _uStack_12c = (uint3)(((uint)(byte)(*(char *)((int)&uStack_12c + (int)pDStack_198) <<
                                                ((uint)pDStack_158 & 0x1f) |
                                               (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                                          (int)(pDStack_198->ks[0].
                                                                                cblock + 1)) >>
                                                     (uVar11 & 0x1f))) << 0x18) >> 8) |
                          _uStack_12b >> 8 |
                          (uint3)(byte)(*(char *)((int)&uStack_12c +
                                                 (int)(pDStack_198->ks[0].cblock + 2)) <<
                                        ((uint)pDStack_158 & 0x1f) |
                                       (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                                  (int)(pDStack_198->ks[0].cblock +
                                                                       3)) >> (uVar11 & 0x1f)));
            _uStack_12c = CONCAT31(_uStack_12c,
                                   *(char *)((int)&uStack_12c + (int)(pDStack_198->ks[0].cblock + 3)
                                            ) << ((uint)pDStack_158 & 0x1f) |
                                   (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                              (int)(pDStack_198->ks[0].cblock + 4))
                                         >> (uVar11 & 0x1f)));
            uStack_128._1_3_ =
                 (uint3)(byte)(*(char *)((int)&uStack_12c + (int)(pDStack_198->ks[0].cblock + 5)) <<
                               ((uint)pDStack_158 & 0x1f) |
                              (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                         (int)(pDStack_198->ks[0].cblock + 6)) >>
                                    (uVar11 & 0x1f))) << 0x10;
            pDVar14 = (DES_key_schedule *)
                      ((uint)*(byte *)((int)&uStack_12c + (int)(pDStack_198->ks[0].cblock + 6)) <<
                      ((uint)pDStack_158 & 0x1f));
            uStack_128._0_3_ =
                 (uint3)(((uint)(byte)(*(char *)((int)&uStack_12c +
                                                (int)(pDStack_198->ks[0].cblock + 4)) <<
                                       ((uint)pDStack_158 & 0x1f) |
                                      (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                                 (int)(pDStack_198->ks[0].cblock + 5
                                                                      )) >> (uVar11 & 0x1f))) <<
                         0x18) >> 8) | uStack_128._1_3_ >> 8 |
                 (uint3)(byte)((byte)pDVar14 |
                              (byte)((int)(uint)*(byte *)((int)&uStack_12c +
                                                         (int)(pDStack_198->ks[0].cblock + 7)) >>
                                    (uVar11 & 0x1f)));
            uStack_128 = CONCAT31(uStack_128._0_3_,
                                  (byte)((int)(uint)abStack_124[(int)pDStack_198] >> (uVar11 & 0x1f)
                                        ) | *(char *)((int)&uStack_12c +
                                                     (int)(pDStack_198->ks[0].cblock + 7)) <<
                                            ((uint)pDStack_158 & 0x1f));
          }
          pDVar28 = (DES_key_schedule *)
                    ((((_uStack_12c >> 0x10) << 0x18 | (_uStack_12c >> 0x18) << 0x10) >> 0x10) +
                    ((_uStack_12c & 0xff) << 8 | _uStack_12c >> 8 & 0xff) * 0x10000);
          pDVar16 = (DES_key_schedule *)
                    ((((uStack_128 >> 0x10) << 0x18 | (uStack_128 >> 0x18) << 0x10) >> 0x10) +
                    ((uStack_128 & 0xff) << 8 | uStack_128 >> 8 & 0xff) * 0x10000);
        }
      }
    }
    pDStack_1f4 = (DES_key_schedule *)((uint)pDVar17 >> 0x10);
    *puStack_144 = (byte)pDVar17;
    pDStack_1a0 = (DES_key_schedule *)((uint)pDVar17 >> 0x18);
    puStack_144[4] = (byte)pDVar9;
    puStack_144[1] = (byte)((uint)pDVar17 >> 8);
    ks2 = (DES_key_schedule *)((uint)pDVar9 >> 0x18);
    puStack_144[2] = (byte)((uint)pDVar17 >> 0x10);
    puStack_144[3] = (byte)((uint)pDVar17 >> 0x18);
    puStack_144[5] = (byte)((uint)pDVar9 >> 8);
    puStack_144[6] = (byte)((uint)pDVar9 >> 0x10);
    puStack_144[7] = (byte)((uint)pDVar9 >> 0x18);
    puStack_1f0 = puStack_144;
    ivec = (DES_cblock *)out;
  }
  if (iStack_11c == *piStack_148) {
    return;
  }
  pcStack_184 = DES_ede3_ofb64_encrypt;
  (*(code *)pDStack_170[-0xa7].ks[0xb].deslong[0])();
  pDStack_208 = pDStack_170;
  pbVar31 = &_gp;
  pDStack_19c = ks2;
  piStack_1c4 = (int *)PTR___stack_chk_guard_006aabf0;
  pDStack_190 = pDStack_1f8;
  pDStack_194 = pDStack_1fc;
  pauStack_1a4 = ivec;
  pbStack_1d8 = &_gp;
  uVar20 = (uint)pbStack_168[3];
  uVar19 = (uint)pbStack_168[7];
  puStack_1c8 = puStack_164;
  uVar8 = uVar20 << 0x18 |
          (uint)pbStack_168[1] << 8 | (uint)pbStack_168[2] << 0x10 | (uint)*pbStack_168;
  uStack_210 = *puStack_164;
  uVar25 = uVar8 >> 8;
  iStack_1ac = *(int *)PTR___stack_chk_guard_006aabf0;
  pbVar12 = (byte *)(uVar19 << 0x18);
  uStack_1bc = uVar8;
  uVar11 = (uint)pbVar12 |
           (uint)pbStack_168[5] << 8 | (uint)pbStack_168[6] << 0x10 | (uint)pbStack_168[4];
  uVar24 = uVar8 >> 0x10;
  uStack_1b8 = uVar11;
  uVar22 = uVar11 >> 8;
  abStack_1b4[0] = *pbStack_168;
  uVar21 = uVar11 >> 0x10;
  abStack_1b4[1] = pbStack_168[1];
  abStack_1b4[2] = pbStack_168[2];
  abStack_1b4[3] = pbStack_168[3];
  bStack_1b0 = pbStack_168[4];
  bStack_1af = pbStack_168[5];
  bStack_1ae = pbStack_168[6];
  bStack_1ad = pbStack_168[7];
  if (pDVar14 != (DES_key_schedule *)0x0) {
    pDStack_1fc = (DES_key_schedule *)0x0;
    ivec = (DES_cblock *)&uStack_1bc;
    pDStack_1f8 = pDVar14;
    puVar26 = puStack_1f0;
    do {
      if (uStack_210 == 0) {
        pDStack_1fc = (DES_key_schedule *)((int)pDStack_1fc->ks + 1);
        pDVar14 = pDStack_208;
        (**(code **)(pbVar31 + -0x5764))(ivec,pDStack_1cc,pDStack_208,uStack_16c);
        uVar25 = uStack_1bc >> 8;
        uVar24 = uStack_1bc >> 0x10;
        abStack_1b4[0] = (byte)uStack_1bc;
        uVar20 = uStack_1bc >> 0x18;
        bStack_1b0 = (byte)uStack_1b8;
        uVar22 = uStack_1b8 >> 8;
        abStack_1b4[1] = (byte)(uStack_1bc >> 8);
        uVar21 = uStack_1b8 >> 0x10;
        abStack_1b4[2] = (byte)(uStack_1bc >> 0x10);
        uVar19 = uStack_1b8 >> 0x18;
        abStack_1b4[3] = (byte)(uStack_1bc >> 0x18);
        bStack_1af = (byte)(uStack_1b8 >> 8);
        bStack_1ae = (byte)(uStack_1b8 >> 0x10);
        bStack_1ad = (byte)(uStack_1b8 >> 0x18);
        uVar11 = uStack_1b8;
        uVar8 = uStack_1bc;
        pbVar31 = pbStack_1d8;
      }
      puStack_1f0 = puVar26 + 1;
      p_Var4 = pDStack_1f4->ks;
      pDStack_1f8 = (DES_key_schedule *)((int)pDStack_1f8[-1].ks + 0x7f);
      pbVar1 = abStack_1b4 + uStack_210;
      pbVar12 = (byte *)(uint)*pbVar1;
      pDStack_1f4 = (DES_key_schedule *)((int)pDStack_1f4->ks + 1);
      uStack_210 = uStack_210 + 1 & 7;
      *puVar26 = p_Var4->cblock[0] ^ *pbVar1;
      puVar26 = puStack_1f0;
    } while (pDStack_1f8 != (DES_key_schedule *)0x0);
    if (pDStack_1fc != (DES_key_schedule *)0x0) {
      *pbStack_168 = (byte)uVar8;
      pbStack_168[1] = (byte)uVar25;
      pbStack_168[2] = (byte)uVar24;
      pbStack_168[3] = (byte)uVar20;
      pbStack_168[4] = (byte)uVar11;
      pbStack_168[5] = (byte)uVar22;
      pbStack_168[6] = (byte)uVar21;
      pbStack_168[7] = (byte)uVar19;
    }
  }
  iVar6 = *piStack_1c4;
  *puStack_1c8 = uStack_210;
  if (iStack_1ac != iVar6) {
    uStack_1ec = 0x5e6f08;
    puVar29 = puStack_1c8;
    (**(code **)(pbVar31 + -0x5328))();
    pbVar31 = pbStack_1d8;
    puVar23 = PTR___stack_chk_guard_006aabf0;
    pbStack_200 = pbStack_168;
    uStack_204 = uStack_16c;
    pauStack_20c = ivec;
    uVar11 = (uint)pbStack_1d8[3];
    uVar8 = *puStack_1d4;
    uStack_224 = uVar11 << 0x18 |
                 (uint)pbStack_1d8[1] << 8 | (uint)pbStack_1d8[2] << 0x10 | (uint)*pbStack_1d8;
    iStack_214 = *(int *)PTR___stack_chk_guard_006aabf0;
    uStack_220 = (uint)pbStack_1d8[7] << 0x18 |
                 (uint)pbStack_1d8[5] << 8 | (uint)pbStack_1d8[6] << 0x10 | (uint)pbStack_1d8[4];
    abStack_21c[0] = *pbStack_1d8;
    abStack_21c[2] = pbStack_1d8[2];
    puVar13 = (uint *)(uStack_220 >> 8);
    abStack_21c[1] = pbStack_1d8[1];
    abStack_21c[3] = pbStack_1d8[3];
    bStack_218 = pbStack_1d8[4];
    bStack_217 = pbStack_1d8[5];
    bStack_216 = pbStack_1d8[6];
    bStack_215 = pbStack_1d8[7];
    if (pDVar14 != (DES_key_schedule *)0x0) {
      iVar6 = 0;
      pDVar15 = pDVar14;
      do {
        if (uVar8 == 0) {
          (*(code *)PTR_DES_encrypt1_006a95e8)(&uStack_224,uVar19,1);
          iVar6 = iVar6 + 1;
          pDVar14 = (DES_key_schedule *)(uStack_224 >> 0x10);
          abStack_21c[0] = (byte)uStack_224;
          puVar13 = (uint *)(uStack_220 >> 8);
          bStack_218 = (byte)uStack_220;
          abStack_21c[1] = (byte)(uStack_224 >> 8);
          abStack_21c[2] = (byte)(uStack_224 >> 0x10);
          bStack_217 = (byte)(uStack_220 >> 8);
          abStack_21c[3] = (byte)(uStack_224 >> 0x18);
          bStack_216 = (byte)(uStack_220 >> 0x10);
          bStack_215 = (byte)(uStack_220 >> 0x18);
        }
        bVar18 = *(byte *)puVar29;
        pDVar15 = (DES_key_schedule *)((int)pDVar15[-1].ks + 0x7f);
        pbVar1 = abStack_21c + uVar8;
        puVar29 = (uint *)((int)puVar29 + 1);
        uVar8 = uVar8 + 1 & 7;
        *pbVar12 = bVar18 ^ *pbVar1;
        pbVar12 = pbVar12 + 1;
      } while (pDVar15 != (DES_key_schedule *)0x0);
      if (iVar6 != 0) {
        pDVar14 = (DES_key_schedule *)(uStack_224 >> 0x10);
        *pbVar31 = (byte)uStack_224;
        puVar13 = (uint *)(uStack_220 >> 8);
        pbVar31[4] = (byte)uStack_220;
        pbVar31[1] = (byte)(uStack_224 >> 8);
        pbVar31[2] = (byte)(uStack_224 >> 0x10);
        pbVar31[5] = (byte)(uStack_220 >> 8);
        pbVar31[3] = (byte)(uStack_224 >> 0x18);
        pbVar31[6] = (byte)(uStack_220 >> 0x10);
        pbVar31[7] = (byte)(uStack_220 >> 0x18);
      }
    }
    iVar6 = *(int *)puVar23;
    *puStack_1d4 = uVar8;
    if (iStack_214 != iVar6) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      iVar6 = 0x19;
      uVar20 = 0;
      uVar19 = 0;
      uVar8 = 0;
      do {
        uVar21 = (uint)pDVar14 & (uVar19 ^ uVar20);
        uVar19 = uVar11 & (uVar19 ^ uVar20);
        uVar22 = uVar20 ^ *puVar13 ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar20 ^ puVar13[1] ^ uVar19;
        uVar19 = (uVar19 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar19 + uVar21 * 0x10000000;
        uVar8 = *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x100 >> 0x1a) + 0x140) * 4) ^ uVar8
        ;
        uVar19 = uVar8 >> 0x10 ^ uVar8;
        uVar21 = (uint)pDVar14 & uVar19;
        uVar19 = uVar11 & uVar19;
        uVar22 = uVar8 ^ puVar13[2] ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar8 ^ puVar13[3] ^ uVar19;
        uVar19 = (uVar19 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar19 + uVar21 * 0x10000000;
        uVar22 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar19 = uVar22 >> 0x10 ^ uVar22;
        uVar20 = (uint)pDVar14 & uVar19;
        uVar19 = uVar11 & uVar19;
        uVar21 = uVar22 ^ puVar13[4] ^ uVar20;
        uVar24 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar22 ^ puVar13[5] ^ uVar19;
        uVar19 = (uVar19 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar19 + uVar20 * 0x10000000;
        uVar21 = uVar8 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar21 >> 0x10 ^ uVar21;
        uVar19 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar20 = uVar21 ^ puVar13[6] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar20;
        uVar19 = uVar21 ^ puVar13[7] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar8 + uVar19 * 0x10000000;
        uVar20 = uVar22 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar20 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar20 ^ puVar13[8] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar20 ^ puVar13[9] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar8 + uVar19 * 0x10000000;
        uVar19 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        iVar6 = iVar6 + -1;
        uVar8 = uVar19 >> 0x10 ^ uVar19;
        uVar21 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar19 ^ puVar13[10] ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar19 ^ puVar13[0xb] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar8 + uVar21 * 0x10000000;
        uVar21 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar21 >> 0x10 ^ uVar21;
        uVar20 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar21 ^ puVar13[0xc] ^ uVar20;
        uVar24 = uVar20 << 0x10 ^ uVar22;
        uVar20 = uVar21 ^ puVar13[0xd] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar8 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar20 ^ puVar13[0xe] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar20 ^ puVar13[0xf] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar8 + uVar19 * 0x10000000;
        uVar19 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar19 >> 0x10 ^ uVar19;
        uVar21 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar19 ^ puVar13[0x10] ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar19 ^ puVar13[0x11] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar8 + uVar21 * 0x10000000;
        uVar21 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar21 >> 0x10 ^ uVar21;
        uVar20 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar21 ^ puVar13[0x12] ^ uVar20;
        uVar24 = uVar20 << 0x10 ^ uVar22;
        uVar20 = uVar21 ^ puVar13[0x13] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar8 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar20 ^ puVar13[0x14] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar20 ^ puVar13[0x15] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar8 + uVar19 * 0x10000000;
        uVar19 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar19 >> 0x10 ^ uVar19;
        uVar21 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar19 ^ puVar13[0x16] ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar19 ^ puVar13[0x17] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar8 + uVar21 * 0x10000000;
        uVar21 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar21 >> 0x10 ^ uVar21;
        uVar20 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar21 ^ puVar13[0x18] ^ uVar20;
        uVar24 = uVar20 << 0x10 ^ uVar22;
        uVar20 = uVar21 ^ puVar13[0x19] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar8 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar20 ^ puVar13[0x1a] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar20 ^ puVar13[0x1b] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar8 + uVar19 * 0x10000000;
        uVar21 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar8 = uVar21 >> 0x10 ^ uVar21;
        uVar19 = (uint)pDVar14 & uVar8;
        uVar8 = uVar11 & uVar8;
        uVar22 = uVar21 ^ puVar13[0x1c] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar21 ^ puVar13[0x1d] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar8 + uVar19 * 0x10000000;
        uVar20 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar19 = uVar20 >> 0x10;
        uVar22 = (uint)pDVar14 & (uVar19 ^ uVar20);
        uVar8 = uVar11 & (uVar19 ^ uVar20);
        uVar24 = uVar20 ^ puVar13[0x1e] ^ uVar22;
        uVar25 = uVar22 << 0x10 ^ uVar24;
        uVar22 = uVar20 ^ puVar13[0x1f] ^ uVar8;
        uVar8 = (uVar8 << 0x10 ^ uVar22) >> 4;
        uVar22 = uVar8 + uVar22 * 0x10000000;
        uVar8 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar25 >> 0x1a) + 0x180) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar25 & 0xfc)) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 0x10) >> 0x1a) + 0x80) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar25 << 8) >> 0x1a) + 0x100) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar22 >> 0x1a) + 0x1c0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar22 & 0xfc) + 0x100) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar8 * 0x100 >> 0x1a) + 0x140) * 4);
      } while (iVar6 != 0);
      uVar8 = (uVar8 >> 3) + uVar8 * 0x20000000;
      uVar19 = (uVar20 >> 3) + uVar20 * 0x20000000;
      uVar11 = (uVar8 >> 1 ^ uVar19) & 0x55555555;
      uVar19 = uVar19 ^ uVar11;
      uVar8 = uVar11 << 1 ^ uVar8;
      uVar11 = (uVar19 >> 8 ^ uVar8) & 0xff00ff;
      uVar8 = uVar8 ^ uVar11;
      uVar19 = uVar11 << 8 ^ uVar19;
      uVar11 = (uVar8 >> 2 ^ uVar19) & 0x33333333;
      uVar19 = uVar19 ^ uVar11;
      uVar8 = uVar11 << 2 ^ uVar8;
      uVar11 = (uVar19 >> 0x10 ^ uVar8) & 0xffff;
      uVar8 = uVar8 ^ uVar11;
      uVar19 = uVar11 << 0x10 ^ uVar19;
      uVar11 = (uVar8 >> 4 ^ uVar19) & 0xf0f0f0f;
      *puStack_1d4 = uVar19 ^ uVar11;
      puStack_1d4[1] = uVar11 << 4 ^ uVar8;
      return;
    }
    return;
  }
  return;
}

