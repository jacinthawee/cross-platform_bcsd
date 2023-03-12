
/* WARNING: Removing unreachable block (ram,0x005e689c) */
/* WARNING: Removing unreachable block (ram,0x005e61d0) */
/* WARNING: Removing unreachable block (ram,0x005e5f10) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

void DES_ecb3_encrypt(const_DES_cblock *input,DES_cblock *output,DES_key_schedule *ks1,
                     DES_key_schedule *ks2,DES_key_schedule *ks3,int enc)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  _union_771 *p_Var4;
  int iVar5;
  DES_key_schedule *pDVar6;
  uint uVar7;
  DES_key_schedule *pDVar8;
  DES_key_schedule *pDVar9;
  uint uVar10;
  uint *puVar11;
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
  DES_key_schedule *pDVar29;
  byte *pbVar30;
  DES_key_schedule **unaff_s8;
  uint uStack_2ac;
  uint uStack_2a8;
  byte abStack_2a4 [4];
  byte bStack_2a0;
  byte bStack_29f;
  byte bStack_29e;
  byte bStack_29d;
  int iStack_29c;
  uint uStack_298;
  uint *puStack_294;
  DES_key_schedule *pDStack_290;
  undefined4 uStack_28c;
  byte *pbStack_288;
  DES_key_schedule *pDStack_284;
  DES_key_schedule *pDStack_280;
  DES_key_schedule *pDStack_27c;
  uint *puStack_278;
  undefined4 uStack_274;
  byte *pbStack_260;
  uint *puStack_25c;
  DES_key_schedule *pDStack_254;
  uint *puStack_250;
  int *piStack_24c;
  uint uStack_244;
  uint uStack_240;
  byte abStack_23c [4];
  byte bStack_238;
  byte bStack_237;
  byte bStack_236;
  byte bStack_235;
  int iStack_234;
  DES_key_schedule *pDStack_230;
  uint *puStack_22c;
  DES_key_schedule *pDStack_228;
  DES_key_schedule *pDStack_224;
  DES_key_schedule *pDStack_220;
  DES_key_schedule *pDStack_21c;
  DES_key_schedule *pDStack_218;
  DES_key_schedule *pDStack_214;
  DES_key_schedule *pDStack_210;
  code *pcStack_20c;
  DES_key_schedule *pDStack_1f8;
  undefined4 uStack_1f4;
  byte *pbStack_1f0;
  uint *puStack_1ec;
  DES_key_schedule *pDStack_1e8;
  DES_key_schedule *pDStack_1e4;
  DES_key_schedule *pDStack_1e0;
  DES_key_schedule *pDStack_1dc;
  DES_key_schedule *pDStack_1d8;
  code **ppcStack_1d4;
  int *piStack_1d0;
  uint *puStack_1cc;
  DES_key_schedule *pDStack_1c8;
  DES_key_schedule *pDStack_1c4;
  DES_key_schedule *pDStack_1bc;
  DES_key_schedule *pDStack_1b8;
  undefined uStack_1b4;
  undefined uStack_1b3;
  byte abStack_1b2 [2];
  undefined4 uStack_1b0;
  byte abStack_1ac [8];
  int iStack_1a4;
  DES_key_schedule *pDStack_1a0;
  uint *puStack_19c;
  DES_key_schedule *pDStack_198;
  DES_key_schedule *pDStack_194;
  DES_key_schedule *pDStack_190;
  DES_key_schedule *pDStack_18c;
  DES_key_schedule *pDStack_188;
  DES_key_schedule *pDStack_184;
  DES_key_schedule *pDStack_180;
  undefined4 uStack_17c;
  uint *puStack_168;
  uint *puStack_164;
  int iStack_160;
  DES_key_schedule *pDStack_15c;
  undefined4 uStack_158;
  DES_key_schedule *pDStack_154;
  DES_key_schedule **ppDStack_150;
  DES_key_schedule **ppDStack_14c;
  undefined *puStack_148;
  int *piStack_144;
  int iStack_140;
  uint uStack_13c;
  undefined4 *puStack_138;
  DES_key_schedule *pDStack_134;
  DES_key_schedule *pDStack_130;
  undefined4 uStack_12c;
  DES_key_schedule *pDStack_124;
  DES_key_schedule *pDStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  byte bStack_114;
  undefined uStack_113;
  undefined uStack_112;
  undefined uStack_111;
  undefined uStack_110;
  undefined uStack_10f;
  undefined uStack_10e;
  undefined uStack_10d;
  int iStack_10c;
  DES_key_schedule *pDStack_108;
  uint *puStack_104;
  DES_key_schedule *pDStack_100;
  DES_key_schedule *pDStack_fc;
  DES_key_schedule *pDStack_f8;
  uint *puStack_f4;
  undefined *puStack_f0;
  DES_key_schedule *pDStack_ec;
  DES_key_schedule *pDStack_e8;
  code *pcStack_e4;
  DES_key_schedule *pDStack_d8;
  DES_key_schedule *pDStack_d0;
  undefined4 uStack_cc;
  DES_key_schedule *pDStack_c8;
  DES_key_schedule *pDStack_c4;
  int iStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  int iStack_b4;
  uint uStack_b0;
  undefined *puStack_ac;
  DES_key_schedule *pDStack_a8;
  DES_key_schedule *pDStack_a4;
  undefined *puStack_9c;
  DES_key_schedule *pDStack_98;
  uint *puStack_94;
  DES_key_schedule **ppDStack_90;
  undefined4 uStack_8c;
  DES_key_schedule *pDStack_78;
  DES_key_schedule *pDStack_74;
  uint *puStack_70;
  DES_key_schedule *pDStack_6c;
  uint uStack_68;
  int iStack_64;
  DES_cblock *pauStack_60;
  undefined *puStack_5c;
  uint *puStack_24;
  int iStack_20;
  uint local_1c;
  uint local_18;
  DES_key_schedule *local_14;
  
  puStack_5c = PTR___stack_chk_guard_006aabf0;
  local_14 = *(DES_key_schedule **)PTR___stack_chk_guard_006aabf0;
  local_18 = (uint)(*input)[7] << 0x18 |
             (uint)(*input)[5] << 8 | (uint)(*input)[6] << 0x10 | (uint)(*input)[4];
  local_1c = (uint)(*input)[3] << 0x18 |
             (uint)(*input)[1] << 8 | (uint)(*input)[2] << 0x10 | (uint)(*input)[0];
  if (enc == 0) {
    (*(code *)PTR_DES_decrypt3_006aa778)(&local_1c);
  }
  else {
    (*(code *)PTR_DES_encrypt3_006aa77c)(&local_1c,ks1,ks2);
  }
  (*output)[0] = (uchar)local_1c;
  (*output)[4] = (uchar)local_18;
  (*output)[1] = (uchar)(local_1c >> 8);
  pDStack_18c = (DES_key_schedule *)(local_18 >> 8);
  (*output)[2] = (uchar)(local_1c >> 0x10);
  puVar11 = (uint *)(local_18 >> 0x10);
  (*output)[3] = (uchar)(local_1c >> 0x18);
  (*output)[5] = (uchar)(local_18 >> 8);
  (*output)[6] = (uchar)(local_18 >> 0x10);
  (*output)[7] = (uchar)(local_18 >> 0x18);
  if (local_14 == *(DES_key_schedule **)puStack_5c) {
    return;
  }
  pDStack_e8 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_9c = PTR___stack_chk_guard_006aabf0;
  pDVar29 = (DES_key_schedule *)&_gp;
  pDStack_78 = (DES_key_schedule *)&_gp;
  iStack_64 = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_b0 = *puStack_24;
  pDStack_100 = ks3;
  pDStack_a8 = pDStack_18c;
  pDStack_98 = pDStack_e8;
  puStack_94 = puVar11;
  pauStack_60 = output;
  if (iStack_20 == 0) {
    unaff_s8 = &pDStack_6c;
    for (; pDStack_a8 != (DES_key_schedule *)0x0;
        pDStack_a8 = (DES_key_schedule *)((int)pDStack_a8[-1].ks + 0x7f)) {
      pDStack_18c = (DES_key_schedule *)0x1;
      if (uStack_b0 == 0) {
        uStack_68 = (uint)DAT_006afee7 << 0x18 |
                    (uint)DAT_006afee5 << 8 | (uint)DAT_006afee6 << 0x10 | (uint)DAT_006afee4;
        pDStack_100 = (DES_key_schedule *)
                      ((uint)DAT_006afee3 << 0x18 |
                      (uint)DAT_006afee1 << 8 | (uint)DAT_006afee2 << 0x10 | (uint)_gp);
        pDStack_6c = pDStack_100;
        (**(code **)((int)pDVar29 + -0x68f8))(unaff_s8,ks3);
        pDStack_18c = (DES_key_schedule *)((uint)pDStack_6c >> 0x10);
        _gp = (byte)pDStack_6c;
        puVar11 = (uint *)(uStack_68 >> 8);
        DAT_006afee4 = (byte)uStack_68;
        DAT_006afee1 = (byte)((uint)pDStack_6c >> 8);
        DAT_006afee2 = (byte)((uint)pDStack_6c >> 0x10);
        DAT_006afee5 = (byte)(uStack_68 >> 8);
        DAT_006afee3 = (byte)((uint)pDStack_6c >> 0x18);
        DAT_006afee6 = (byte)(uStack_68 >> 0x10);
        DAT_006afee7 = (byte)(uStack_68 >> 0x18);
        pDVar29 = pDStack_78;
      }
      bVar18 = pDStack_98->ks[0].cblock[0];
      bVar2 = (&_gp)[uStack_b0];
      pDStack_e8 = (DES_key_schedule *)(uint)bVar2;
      (&_gp)[uStack_b0] = bVar18;
      pDStack_98 = (DES_key_schedule *)((int)pDStack_98->ks + 1);
      uStack_b0 = uStack_b0 + 1 & 7;
      *(byte *)puStack_94 = bVar18 ^ bVar2;
      puStack_94 = (uint *)((int)puStack_94 + 1);
    }
  }
  else if (pDStack_18c != (DES_key_schedule *)0x0) {
    unaff_s8 = &pDStack_6c;
    pDVar15 = pDStack_e8;
    puVar13 = puVar11;
    do {
      if (uStack_b0 == 0) {
        uStack_68 = (uint)DAT_006afee7 << 0x18 |
                    (uint)DAT_006afee5 << 8 | (uint)DAT_006afee6 << 0x10 | (uint)DAT_006afee4;
        pDStack_100 = (DES_key_schedule *)
                      ((uint)DAT_006afee3 << 0x18 |
                      (uint)DAT_006afee1 << 8 | (uint)DAT_006afee2 << 0x10 | (uint)_gp);
        pDStack_6c = pDStack_100;
        (*(code *)pDStack_78[-0xd2].ks[1].deslong[0])(unaff_s8,ks3,1);
        pDStack_18c = (DES_key_schedule *)((uint)pDStack_6c >> 0x10);
        _gp = (byte)pDStack_6c;
        puVar11 = (uint *)(uStack_68 >> 8);
        DAT_006afee4 = (byte)uStack_68;
        DAT_006afee1 = (byte)((uint)pDStack_6c >> 8);
        DAT_006afee2 = (byte)((uint)pDStack_6c >> 0x10);
        DAT_006afee5 = (byte)(uStack_68 >> 8);
        DAT_006afee3 = (byte)((uint)pDStack_6c >> 0x18);
        DAT_006afee6 = (byte)(uStack_68 >> 0x10);
        DAT_006afee7 = (byte)(uStack_68 >> 0x18);
      }
      pbVar12 = &_gp + uStack_b0;
      puStack_94 = (uint *)((int)puVar13 + 1);
      bVar18 = *pbVar12;
      pDStack_e8 = (DES_key_schedule *)(uint)bVar18;
      pDStack_a8 = (DES_key_schedule *)((int)pDStack_a8[-1].ks + 0x7f);
      pDStack_98 = (DES_key_schedule *)((int)pDVar15->ks + 1);
      uStack_b0 = uStack_b0 + 1 & 7;
      bVar18 = pDVar15->ks[0].cblock[0] ^ bVar18;
      *(byte *)puVar13 = bVar18;
      *pbVar12 = bVar18;
      pDVar29 = pDStack_78;
      pDVar15 = pDStack_98;
      puVar13 = puStack_94;
    } while (pDStack_a8 != (DES_key_schedule *)0x0);
  }
  iVar5 = *(int *)puStack_9c;
  *puStack_24 = uStack_b0;
  if (iStack_64 == iVar5) {
    return;
  }
  uStack_8c = 0x5e5728;
  (*(code *)pDVar29[-0xa7].ks[0xb].deslong[0])();
  pDStack_224 = pDStack_78;
  pDStack_188 = (DES_key_schedule *)PTR___stack_chk_guard_006aabf0;
  pDVar29 = (DES_key_schedule *)&_gp;
  pDStack_c4 = pDStack_6c;
  puStack_ac = &_gp;
  pDStack_d0 = (DES_key_schedule *)&_gp;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_108 = (DES_key_schedule *)pDStack_6c->ks[0].deslong[0];
  pDVar15 = pDStack_100;
  puStack_f4 = puVar11;
  pDStack_184 = pDStack_18c;
  pDVar14 = pDStack_c8;
  pDStack_a4 = ks3;
  ppDStack_90 = unaff_s8;
  if (uStack_68 == 0) {
    pDVar17 = (DES_key_schedule *)&uStack_bc;
    for (; pDStack_c8 = pDVar17, pDStack_184 != (DES_key_schedule *)0x0;
        pDStack_184 = (DES_key_schedule *)((int)pDStack_184[-1].ks + 0x7f)) {
      pDVar15 = pDStack_74;
      pDVar17 = pDStack_c8;
      if (pDStack_108 == (DES_key_schedule *)0x0) {
        uStack_b8 = (uint)*(byte *)((int)puStack_70 + 7) << 0x18 |
                    (uint)*(byte *)((int)puStack_70 + 5) << 8 |
                    (uint)*(byte *)((int)puStack_70 + 6) << 0x10 | (uint)*(byte *)(puStack_70 + 1);
        uStack_bc = (uint)*(byte *)((int)puStack_70 + 3) << 0x18 |
                    (uint)*(byte *)((int)puStack_70 + 1) << 8 |
                    (uint)*(byte *)((int)puStack_70 + 2) << 0x10 | (uint)*(byte *)puStack_70;
        (**(code **)((int)pDVar29 + -0x5764))(pDStack_c8,pDStack_100,pDStack_224);
        pDVar15 = (DES_key_schedule *)(uStack_bc >> 0x10);
        *(byte *)puStack_70 = (byte)uStack_bc;
        pDStack_18c = (DES_key_schedule *)(uStack_b8 >> 8);
        *(byte *)(puStack_70 + 1) = (byte)uStack_b8;
        *(byte *)((int)puStack_70 + 1) = (byte)(uStack_bc >> 8);
        *(byte *)((int)puStack_70 + 2) = (byte)(uStack_bc >> 0x10);
        *(byte *)((int)puStack_70 + 5) = (byte)(uStack_b8 >> 8);
        *(byte *)((int)puStack_70 + 3) = (byte)(uStack_bc >> 0x18);
        *(byte *)((int)puStack_70 + 6) = (byte)(uStack_b8 >> 0x10);
        *(byte *)((int)puStack_70 + 7) = (byte)(uStack_b8 >> 0x18);
        pDVar17 = pDStack_c8;
        pDVar29 = pDStack_d0;
        pDVar14 = pDStack_c8;
      }
      pDStack_c8 = pDVar14;
      bVar18 = pDStack_e8->ks[0].cblock[0];
      bVar2 = *(byte *)((int)puStack_70 + (int)pDStack_108);
      puVar11 = (uint *)(uint)bVar2;
      *(byte *)((int)puStack_70 + (int)pDStack_108) = bVar18;
      pDStack_e8 = (DES_key_schedule *)((int)pDStack_e8->ks + 1);
      pDStack_108 = (DES_key_schedule *)((uint)((int)pDStack_108->ks + 1) & 7);
      *(byte *)puStack_f4 = bVar18 ^ bVar2;
      puStack_f4 = (uint *)((int)puStack_f4 + 1);
      pDVar14 = pDStack_c8;
    }
  }
  else if (pDStack_18c != (DES_key_schedule *)0x0) {
    pDVar17 = (DES_key_schedule *)&uStack_bc;
    puVar13 = puVar11;
    do {
      pDStack_c8 = pDVar17;
      pDVar17 = pDStack_c8;
      if (pDStack_108 == (DES_key_schedule *)0x0) {
        uStack_b8 = (uint)*(byte *)((int)puStack_70 + 7) << 0x18 |
                    (uint)*(byte *)((int)puStack_70 + 5) << 8 |
                    (uint)*(byte *)((int)puStack_70 + 6) << 0x10 | (uint)*(byte *)(puStack_70 + 1);
        uStack_bc = (uint)*(byte *)((int)puStack_70 + 3) << 0x18 |
                    (uint)*(byte *)((int)puStack_70 + 1) << 8 |
                    (uint)*(byte *)((int)puStack_70 + 2) << 0x10 | (uint)*(byte *)puStack_70;
        (*(code *)*(DES_key_schedule **)((int)pDStack_d0[-0xaf].ks + 0x1c))
                  (pDStack_c8,pDStack_100,pDStack_224,pDStack_74);
        pDVar15 = (DES_key_schedule *)(uStack_bc >> 0x10);
        *(byte *)puStack_70 = (byte)uStack_bc;
        pDStack_18c = (DES_key_schedule *)(uStack_b8 >> 8);
        *(byte *)(puStack_70 + 1) = (byte)uStack_b8;
        *(byte *)((int)puStack_70 + 1) = (byte)(uStack_bc >> 8);
        *(byte *)((int)puStack_70 + 2) = (byte)(uStack_bc >> 0x10);
        *(byte *)((int)puStack_70 + 5) = (byte)(uStack_b8 >> 8);
        *(byte *)((int)puStack_70 + 3) = (byte)(uStack_bc >> 0x18);
        *(byte *)((int)puStack_70 + 6) = (byte)(uStack_b8 >> 0x10);
        *(byte *)((int)puStack_70 + 7) = (byte)(uStack_b8 >> 0x18);
        pDVar14 = pDStack_c8;
        pDVar17 = pDStack_c8;
      }
      pDStack_c8 = pDVar14;
      pbVar12 = (byte *)((int)puStack_70 + (int)pDStack_108);
      p_Var4 = pDStack_e8->ks;
      puStack_f4 = (uint *)((int)puVar13 + 1);
      bVar18 = *pbVar12;
      puVar11 = (uint *)(uint)bVar18;
      pDStack_184 = (DES_key_schedule *)((int)pDStack_184[-1].ks + 0x7f);
      pDStack_e8 = (DES_key_schedule *)((int)pDStack_e8->ks + 1);
      pDStack_108 = (DES_key_schedule *)((uint)((int)pDStack_108->ks + 1) & 7);
      bVar18 = p_Var4->cblock[0] ^ bVar18;
      *(byte *)puVar13 = bVar18;
      *pbVar12 = bVar18;
      pDVar29 = pDStack_d0;
      pDVar14 = pDStack_c8;
      puVar13 = puStack_f4;
    } while (pDStack_184 != (DES_key_schedule *)0x0);
  }
  pDStack_c8 = pDVar14;
  iVar5 = *(int *)pDStack_188;
  pDStack_c4->ks[0].deslong[0] = (uint)pDStack_108;
  if (iStack_b4 == iVar5) {
    return;
  }
  pcStack_e4 = DES_ede3_cfb_encrypt;
  pDVar14 = pDStack_c4;
  (*(code *)pDVar29[-0xa7].ks[0xb].deslong[0])();
  uStack_158 = uStack_cc;
  piStack_144 = (int *)PTR___stack_chk_guard_006aabf0;
  puStack_f0 = (undefined *)pDStack_188;
  pDStack_154 = pDStack_c8;
  pDStack_f8 = pDStack_74;
  pDStack_fc = pDStack_224;
  puStack_104 = puStack_70;
  puStack_168 = (uint *)&_gp;
  iStack_10c = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_15c = pDStack_d0;
  pDStack_134 = pDStack_c4;
  pDStack_27c = pDStack_c4;
  pDVar29 = pDStack_d0;
  pDStack_1a0 = pDStack_108;
  pDStack_228 = pDStack_100;
  pDStack_210 = pDStack_e8;
  pDStack_ec = pDStack_184;
  if ((int)pDStack_18c < 0x41) {
    pDVar29 = (DES_key_schedule *)((int)pDStack_18c->ks + 7);
    pDVar27 = (DES_key_schedule *)((uint)pDVar29 >> 3);
    pDVar17 = (DES_key_schedule *)
              ((uint)pDStack_c4->ks[0].cblock[7] << 0x18 |
              (uint)pDStack_c4->ks[0].cblock[5] << 8 | (uint)pDStack_c4->ks[0].cblock[6] << 0x10 |
              (uint)pDStack_c4->ks[0].cblock[4]);
    pDVar8 = (DES_key_schedule *)
             ((uint)pDStack_c4->ks[0].cblock[1] << 8 | (uint)pDStack_c4->ks[0].cblock[2] << 0x10 |
              (uint)pDStack_c4->ks[0].cblock[0] | (uint)pDStack_c4->ks[0].cblock[3] << 0x18);
    pDStack_224 = pDVar27;
    puStack_70 = puVar11;
    if (iStack_c0 == 0) {
      if (pDVar27 <= pDVar15) {
        if (-1 < (int)pDStack_18c) {
          pDVar29 = pDStack_18c;
        }
        puStack_138 = &uStack_11c;
        uStack_13c = (uint)pDStack_18c & 7;
        iStack_140 = (int)puStack_138 + ((int)pDVar29 >> 3);
        pDStack_188 = (DES_key_schedule *)((uint)pDStack_18c & 0x80000007);
        if ((int)pDStack_188 < 0) {
          pDStack_188 = (DES_key_schedule *)
                        (((uint)((int)pDStack_188[-1].ks + 0x7f) | 0xfffffff8) + 1);
        }
        pDStack_228 = (DES_key_schedule *)(8 - (int)pDStack_188);
        ppDStack_150 = &pDStack_124;
        pDVar28 = (DES_key_schedule *)((int)pDVar15 - (int)pDVar27);
        ppDStack_14c = (DES_key_schedule **)(&PTR_LAB_00675524 + (int)pDVar27);
        puStack_148 = &UNK_0067556c + (int)pDVar27 * 4;
        pDStack_210 = (DES_key_schedule *)(uint)(pDVar27 < (DES_key_schedule *)&DAT_00000009);
        pDStack_1a0 = pDVar14;
        pDVar29 = pDVar17;
        pDVar14 = pDVar8;
        pDStack_d8 = pDStack_18c;
        do {
          pDStack_1a0 = (DES_key_schedule *)((int)pDStack_1a0->ks + (int)pDVar27 * 2);
          pDStack_124 = pDVar14;
          pDStack_120 = pDVar29;
          (*(code *)puStack_168[-0x15d9])(ppDStack_150,pDStack_15c,uStack_158,pDStack_154);
          if (pDStack_210 != (DES_key_schedule *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e5e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)*ppDStack_14c)();
            return;
          }
          pDVar17 = (DES_key_schedule *)0x0;
          pDVar15 = (DES_key_schedule *)0x0;
          if (pDStack_d8 == (DES_key_schedule *)&DAT_00000020) {
            pDVar17 = (DES_key_schedule *)0x0;
            pDVar8 = pDVar29;
          }
          else {
            pDVar8 = pDVar15;
            if (pDStack_d8 != (DES_key_schedule *)&DAT_00000040) {
              bStack_114 = 0;
              uStack_112 = 0;
              uStack_11c = CONCAT22(CONCAT11((char)pDVar14,(char)((uint)pDVar14 >> 8)),
                                    CONCAT11((char)((uint)pDVar14 >> 0x10),
                                             (char)((uint)pDVar14 >> 0x18)));
              uStack_113 = 0;
              uStack_10d = 0;
              uStack_118 = CONCAT31(CONCAT21(CONCAT11((char)pDVar29,(char)((uint)pDVar29 >> 8)),
                                             (char)((uint)pDVar29 >> 0x10)),
                                    (char)((uint)pDVar29 >> 0x18));
              uStack_111 = 0;
              uStack_110 = 0;
              uStack_10f = 0;
              uStack_10e = 0;
              if (uStack_13c == 0) {
                uStack_12c = 0;
                pDStack_130 = (DES_key_schedule *)0x0;
                (*(code *)puStack_168[-0x14b9])(puStack_138,iStack_140,8);
              }
              else {
                uStack_12c = 0;
                pDStack_130 = (DES_key_schedule *)0x0;
                (*(code *)puStack_168[-0x14b9])(puStack_138,iStack_140,9);
                uStack_11c = CONCAT31(CONCAT21(CONCAT11(uStack_11c._0_1_ <<
                                                        ((uint)pDStack_188 & 0x1f) |
                                                        (byte)((int)(uint)uStack_11c._1_1_ >>
                                                              ((uint)pDStack_228 & 0x1f)),
                                                        uStack_11c._1_1_ <<
                                                        ((uint)pDStack_188 & 0x1f) |
                                                        (byte)((int)(uint)uStack_11c._2_1_ >>
                                                              ((uint)pDStack_228 & 0x1f))),
                                               uStack_11c._2_1_ << ((uint)pDStack_188 & 0x1f) |
                                               (byte)((int)(uStack_11c & 0xff) >>
                                                     ((uint)pDStack_228 & 0x1f))),
                                      (char)uStack_11c << ((uint)pDStack_188 & 0x1f) |
                                      (byte)((int)(uint)uStack_118._0_1_ >>
                                            ((uint)pDStack_228 & 0x1f)));
                uStack_118 = CONCAT31(CONCAT21(CONCAT11(uStack_118._0_1_ <<
                                                        ((uint)pDStack_188 & 0x1f) |
                                                        (byte)((int)(uint)uStack_118._1_1_ >>
                                                              ((uint)pDStack_228 & 0x1f)),
                                                        uStack_118._1_1_ <<
                                                        ((uint)pDStack_188 & 0x1f) |
                                                        (byte)((int)(uint)uStack_118._2_1_ >>
                                                              ((uint)pDStack_228 & 0x1f))),
                                               uStack_118._2_1_ << ((uint)pDStack_188 & 0x1f) |
                                               (byte)((int)(uStack_118 & 0xff) >>
                                                     ((uint)pDStack_228 & 0x1f))),
                                      (byte)((int)(uint)bStack_114 >> ((uint)pDStack_228 & 0x1f)) |
                                      (char)uStack_118 << ((uint)pDStack_188 & 0x1f));
              }
              pDVar17 = (DES_key_schedule *)
                        ((((uStack_118 >> 0x10) << 0x18 | (uStack_118 >> 0x18) << 0x10) >> 0x10) +
                        ((uStack_118 & 0xff) << 8 | uStack_118 >> 8 & 0xff) * 0x10000);
              pDVar15 = pDStack_130;
              pDVar8 = (DES_key_schedule *)
                       ((((uStack_11c >> 0x10) << 0x18 | (uStack_11c >> 0x18) << 0x10) >> 0x10) +
                       ((uStack_11c & 0xff) << 8 | uStack_11c >> 8 & 0xff) * 0x10000);
            }
          }
          puVar11 = (uint *)((int)puVar11 + (int)pDVar27 * 2);
          pDVar15 = (DES_key_schedule *)((uint)pDVar15 ^ (uint)pDStack_124);
          bVar3 = pDVar27 <= pDVar28;
          pDVar28 = (DES_key_schedule *)((int)pDVar28 - (int)pDVar27);
          puStack_70 = puVar11;
          pDStack_224 = pDVar17;
          pDVar29 = pDVar17;
          pDStack_74 = pDVar27;
          pDStack_18c = pDVar28;
          pDStack_184 = pDVar8;
          pDVar14 = pDVar8;
        } while (bVar3);
      }
    }
    else if (pDVar27 <= pDVar15) {
      if (-1 < (int)pDStack_18c) {
        pDVar29 = pDStack_18c;
      }
      puStack_138 = &uStack_11c;
      uStack_13c = (uint)pDStack_18c & 7;
      iStack_140 = (int)puStack_138 + ((int)pDVar29 >> 3);
      pDStack_1a0 = (DES_key_schedule *)((uint)pDStack_18c & 0x80000007);
      if ((int)pDStack_1a0 < 0) {
        pDStack_1a0 = (DES_key_schedule *)
                      (((uint)((int)pDStack_1a0[-1].ks + 0x7f) | 0xfffffff8) + 1);
      }
      pDStack_188 = (DES_key_schedule *)(&DAT_00675500 + (int)pDVar27 * 4);
      puStack_148 = &UNK_00675548 + (int)pDVar27 * 4;
      ppDStack_14c = &pDStack_124;
      pDStack_224 = (DES_key_schedule *)((int)pDVar15 - (int)pDVar27);
      ppDStack_150 = (DES_key_schedule **)(uint)(pDVar27 < (DES_key_schedule *)&DAT_00000009);
      pDStack_228 = (DES_key_schedule *)(8 - (int)pDStack_1a0);
      pDVar29 = pDVar17;
      pDVar28 = pDVar8;
      pDStack_210 = pDVar14;
      pDStack_d8 = pDStack_18c;
      do {
        pDStack_210 = (DES_key_schedule *)((int)pDStack_210->ks + (int)pDVar27 * 2);
        pDVar15 = pDStack_154;
        pDStack_124 = pDVar28;
        pDStack_120 = pDVar29;
        (*(code *)puStack_168[-0x15d9])(ppDStack_14c,pDStack_15c,uStack_158);
        if (ppDStack_150 != (DES_key_schedule **)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e5bac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)pDStack_188->ks[0].deslong[0])();
          return;
        }
        puStack_70 = (uint *)((int)puStack_70 + (int)pDVar27 * 2);
        pDVar17 = pDStack_124;
        pDVar8 = pDVar29;
        if ((pDStack_d8 != (DES_key_schedule *)&DAT_00000020) &&
           (pDVar17 = pDStack_120, pDVar8 = pDStack_124,
           pDStack_d8 != (DES_key_schedule *)&DAT_00000040)) {
          bStack_114 = (byte)pDStack_124;
          uStack_11c = CONCAT31(CONCAT21(CONCAT11((char)pDVar28,(char)((uint)pDVar28 >> 8)),
                                         (char)((uint)pDVar28 >> 0x10)),
                                (char)((uint)pDVar28 >> 0x18));
          pDVar15 = (DES_key_schedule *)((uint)pDVar29 >> 8);
          uStack_113 = (undefined)((uint)pDStack_124 >> 8);
          uStack_112 = (undefined)((uint)pDStack_124 >> 0x10);
          uStack_111 = (undefined)((uint)pDStack_124 >> 0x18);
          uStack_118._0_1_ = (byte)pDVar29;
          uStack_118 = (uint)CONCAT12(uStack_118._0_1_,
                                      CONCAT11((char)((uint)pDVar29 >> 8),
                                               (char)((uint)pDVar29 >> 0x10))) << 8;
          uStack_118 = uStack_118 | (uint)pDVar29 >> 0x18;
          uStack_110 = SUB41(pDStack_120,0);
          uStack_10f = (undefined)((uint)pDStack_120 >> 8);
          uStack_10e = (undefined)((uint)pDStack_120 >> 0x10);
          uStack_10d = (undefined)((uint)pDStack_120 >> 0x18);
          if (uStack_13c == 0) {
            (*(code *)puStack_168[-0x14b9])(puStack_138,iStack_140,8);
          }
          else {
            (*(code *)puStack_168[-0x14b9])(puStack_138,iStack_140,9);
            pDVar15 = (DES_key_schedule *)
                      ((uStack_11c >> 0x18) << ((uint)pDStack_1a0 & 0x1f) |
                      (int)(uint)uStack_11c._1_1_ >> ((uint)pDStack_228 & 0x1f));
            uStack_11c._0_1_ = (char)pDVar15;
            uStack_11c = CONCAT31(CONCAT12(uStack_11c._0_1_,
                                           CONCAT11(uStack_11c._1_1_ << ((uint)pDStack_1a0 & 0x1f) |
                                                    (byte)((int)(uint)uStack_11c._2_1_ >>
                                                          ((uint)pDStack_228 & 0x1f)),
                                                    uStack_11c._2_1_ << ((uint)pDStack_1a0 & 0x1f) |
                                                    (byte)((int)(uStack_11c & 0xff) >>
                                                          ((uint)pDStack_228 & 0x1f)))),
                                  (char)uStack_11c << ((uint)pDStack_1a0 & 0x1f) |
                                  (byte)((int)(uint)uStack_118._0_1_ >> ((uint)pDStack_228 & 0x1f)))
            ;
            uStack_118 = CONCAT31(CONCAT21(CONCAT11(uStack_118._0_1_ << ((uint)pDStack_1a0 & 0x1f) |
                                                    (byte)((int)(uint)uStack_118._1_1_ >>
                                                          ((uint)pDStack_228 & 0x1f)),
                                                    uStack_118._1_1_ << ((uint)pDStack_1a0 & 0x1f) |
                                                    (byte)((int)(uint)uStack_118._2_1_ >>
                                                          ((uint)pDStack_228 & 0x1f))),
                                           uStack_118._2_1_ << ((uint)pDStack_1a0 & 0x1f) |
                                           (byte)((int)(uStack_118 & 0xff) >>
                                                 ((uint)pDStack_228 & 0x1f))),
                                  (byte)((int)(uint)bStack_114 >> ((uint)pDStack_228 & 0x1f)) |
                                  (char)uStack_118 << ((uint)pDStack_1a0 & 0x1f));
          }
          pDVar17 = (DES_key_schedule *)
                    ((((uStack_118 >> 0x10) << 0x18 | (uStack_118 >> 0x18) << 0x10) >> 0x10) +
                    ((uStack_118 & 0xff) << 8 | uStack_118 >> 8 & 0xff) * 0x10000);
          pDVar8 = (DES_key_schedule *)
                   ((((uStack_11c >> 0x10) << 0x18 | (uStack_11c >> 0x18) << 0x10) >> 0x10) +
                   ((uStack_11c & 0xff) << 8 | uStack_11c >> 8 & 0xff) * 0x10000);
        }
        bVar3 = pDVar27 <= pDStack_224;
        pDStack_224 = (DES_key_schedule *)((int)pDStack_224 - (int)pDVar27);
        pDVar29 = pDVar17;
        pDStack_74 = pDVar17;
        pDStack_18c = pDVar27;
        pDVar28 = pDVar8;
        pDStack_184 = pDVar8;
      } while (bVar3);
    }
    puVar11 = (uint *)((uint)pDVar8 >> 0x10);
    pDStack_27c = (DES_key_schedule *)((uint)pDVar17 >> 8);
    pDStack_134->ks[0].cblock[0] = (uchar)pDVar8;
    pDStack_134->ks[0].cblock[4] = (char)pDVar17;
    pDStack_134->ks[0].cblock[1] = (uchar)((uint)pDVar8 >> 8);
    pDStack_134->ks[0].cblock[2] = (uchar)((uint)pDVar8 >> 0x10);
    pDStack_134->ks[0].cblock[3] = (uchar)((uint)pDVar8 >> 0x18);
    pDStack_134->ks[0].cblock[5] = (uchar)((uint)pDVar17 >> 8);
    pDStack_134->ks[0].cblock[6] = (uchar)((uint)pDVar17 >> 0x10);
    pDStack_134->ks[0].cblock[7] = (uchar)((uint)pDVar17 >> 0x18);
    pDVar29 = pDStack_134;
  }
  if (iStack_10c == *piStack_144) {
    return;
  }
  uStack_17c = 0x5e637c;
  (*(code *)puStack_168[-0x14ca])();
  puStack_1ec = puStack_168;
  piStack_1d0 = (int *)PTR___stack_chk_guard_006aabf0;
  puStack_1cc = puStack_164;
  pDStack_1f8 = (DES_key_schedule *)&_gp;
  iStack_1a4 = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_278 = puVar11;
  pDVar14 = pDVar29;
  pDStack_254 = pDVar15;
  pDStack_230 = pDStack_1a0;
  pDStack_220 = pDStack_74;
  pDStack_284 = pDStack_18c;
  pDStack_280 = pDStack_188;
  pDStack_214 = pDStack_184;
  puStack_19c = puStack_70;
  pDStack_198 = pDStack_228;
  pDStack_194 = pDStack_224;
  pDStack_190 = pDStack_74;
  pDStack_180 = pDStack_210;
  if ((undefined *)((int)pDVar29[-1].ks + 0x7f) < &DAT_00000040) {
    pDStack_220 = (DES_key_schedule *)((int)pDVar29 >> 3);
    pDVar14 = (DES_key_schedule *)((uint)*(byte *)((int)puStack_164 + 7) << 0x18);
    pDVar8 = (DES_key_schedule *)
             ((uint)pDVar14 |
             (uint)*(byte *)((int)puStack_164 + 5) << 8 |
             (uint)*(byte *)((int)puStack_164 + 6) << 0x10 | (uint)*(byte *)(puStack_164 + 1));
    pDStack_284 = (DES_key_schedule *)((int)((int)pDVar29->ks + 7) >> 3);
    pDVar17 = (DES_key_schedule *)
              ((uint)*(byte *)((int)puStack_164 + 1) << 8 |
               (uint)*(byte *)((int)puStack_164 + 2) << 0x10 | (uint)*(byte *)puStack_164 |
              (uint)*(byte *)((int)puStack_164 + 3) << 0x18);
    if (iStack_160 == 0) {
      pDStack_230 = pDStack_27c;
      if (pDStack_284 <= pDVar15) {
        ppcStack_1d4 = (code **)(&PTR_LAB_006755b4 + (int)pDStack_284);
        pDStack_254 = (DES_key_schedule *)((int)pDVar15 - (int)pDStack_284);
        pDVar27 = (DES_key_schedule *)&pDStack_1bc;
        pDVar15 = (DES_key_schedule *)((int)pDStack_284[-1].ks + 0x7f);
        pDStack_214 = (DES_key_schedule *)&uStack_1b4;
        pDStack_280 = (DES_key_schedule *)(&PTR_LAB_006755d8 + (int)pDStack_284);
        pDStack_210 = (DES_key_schedule *)(uint)(pDStack_284 < (DES_key_schedule *)&DAT_00000009);
        pDStack_1e4 = (DES_key_schedule *)((uint)pDVar29 & 7);
        pDVar28 = pDVar17;
        do {
          pDVar17 = pDVar8;
          pDVar14 = (DES_key_schedule *)0x1;
          pDStack_1e8 = pDVar27;
          pDStack_1e0 = pDStack_254;
          pDStack_1dc = pDVar29;
          pDStack_1d8 = pDVar15;
          pDStack_1bc = pDVar28;
          pDStack_1b8 = pDVar17;
          (*(code *)pDStack_1f8[-0xd2].ks[1].deslong[0])(pDVar27,puStack_1ec);
          if (pDStack_210 != (DES_key_schedule *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e666c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**ppcStack_1d4)();
            return;
          }
          bVar18 = (pDStack_284->ks[0].cblock + (int)pDStack_27c->ks[0].cblock)[-1];
          pDVar8 = (DES_key_schedule *)(uint)bVar18;
          pDStack_27c = (DES_key_schedule *)
                        (pDStack_284->ks[0].cblock + (int)pDStack_27c->ks[0].cblock +
                        (int)pDStack_1d8);
          pDVar16 = pDStack_1e0;
          pDVar15 = pDStack_1d8;
          pDVar29 = pDStack_1dc;
          pDVar27 = pDStack_1e8;
          if (pDStack_1dc != (DES_key_schedule *)&DAT_00000020) {
            if (pDStack_1dc == (DES_key_schedule *)&DAT_00000040) {
              pDVar17 = pDVar8;
              pDVar8 = (DES_key_schedule *)0x0;
            }
            else {
              abStack_1ac[0] = bVar18;
              abStack_1ac[1] = 0;
              abStack_1ac[2] = 0;
              _uStack_1b4 = CONCAT31(CONCAT21(CONCAT11((char)pDVar28,(char)((uint)pDVar28 >> 8)),
                                              (char)((uint)pDVar28 >> 0x10)),
                                     (char)((uint)pDVar28 >> 0x18));
              uStack_1b0 = CONCAT31(CONCAT21(CONCAT11((char)pDVar17,(char)((uint)pDVar17 >> 8)),
                                             (char)((uint)pDVar17 >> 0x10)),
                                    (char)((uint)pDVar17 >> 0x18));
              abStack_1ac[3] = 0;
              abStack_1ac[4] = 0;
              abStack_1ac[5] = 0;
              abStack_1ac[6] = 0;
              abStack_1ac[7] = 0;
              if (pDStack_1e4 == (DES_key_schedule *)0x0) {
                pDVar14 = (DES_key_schedule *)&DAT_00000008;
                pDStack_1c4 = pDStack_1e8;
                pDStack_1c8 = pDStack_1d8;
                pDStack_1d8 = pDStack_1dc;
                pDStack_1dc = pDStack_1e0;
                pDStack_1e8 = (DES_key_schedule *)0x0;
                pDStack_1e0 = pDVar8;
                (*(code *)*(DES_key_schedule **)((int)pDStack_1f8[-0xa6].ks + 0x1c))
                          (pDStack_214,(undefined *)((int)pDStack_220->ks + (int)pDStack_214->ks));
                bVar18 = (byte)pDStack_1e0;
                pDVar16 = pDStack_1dc;
                pDVar15 = pDStack_1c8;
                pDVar29 = pDStack_1d8;
                pDVar27 = pDStack_1c4;
              }
              else {
                pDVar14 = (DES_key_schedule *)((int)&pDStack_1a0 + (int)pDStack_220);
                uVar10 = 8 - (int)pDStack_1e4;
                _uStack_1b3 = (uint3)(byte)(*(char *)((int)&uStack_1b4 +
                                                     (int)(pDStack_220->ks[0].cblock + 1)) <<
                                            ((uint)pDStack_1e4 & 0x1f) |
                                           (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                                      (int)(pDStack_220->ks[0].
                                                                            cblock + 2)) >>
                                                 (uVar10 & 0x1f))) << 0x10;
                _uStack_1b4 = (uint3)(((uint)(byte)(*(char *)((int)&uStack_1b4 + (int)pDStack_220)
                                                    << ((uint)pDStack_1e4 & 0x1f) |
                                                   (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                                              (int)(pDStack_220->ks
                                                                                    [0].cblock + 1))
                                                         >> (uVar10 & 0x1f))) << 0x18) >> 8) |
                              _uStack_1b3 >> 8 |
                              (uint3)(byte)(*(char *)((int)&uStack_1b4 +
                                                     (int)(pDStack_220->ks[0].cblock + 2)) <<
                                            ((uint)pDStack_1e4 & 0x1f) |
                                           (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                                      (int)(pDStack_220->ks[0].
                                                                            cblock + 3)) >>
                                                 (uVar10 & 0x1f)));
                _uStack_1b4 = CONCAT31(_uStack_1b4,
                                       *(char *)((int)&uStack_1b4 +
                                                (int)(pDStack_220->ks[0].cblock + 3)) <<
                                       ((uint)pDStack_1e4 & 0x1f) |
                                       (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                                  (int)(pDStack_220->ks[0].cblock +
                                                                       4)) >> (uVar10 & 0x1f)));
                uStack_1b0._1_3_ =
                     (uint3)(byte)(*(char *)((int)&uStack_1b4 + (int)(pDStack_220->ks[0].cblock + 5)
                                            ) << ((uint)pDStack_1e4 & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                             (int)(pDStack_220->ks[0].cblock + 6))
                                        >> (uVar10 & 0x1f))) << 0x10;
                uStack_1b0._0_3_ =
                     (uint3)(((uint)(byte)(*(char *)((int)&uStack_1b4 +
                                                    (int)(pDStack_220->ks[0].cblock + 4)) <<
                                           ((uint)pDStack_1e4 & 0x1f) |
                                          (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                                     (int)(pDStack_220->ks[0].cblock
                                                                          + 5)) >> (uVar10 & 0x1f)))
                             << 0x18) >> 8) | uStack_1b0._1_3_ >> 8 |
                     (uint3)(byte)(*(char *)((int)&uStack_1b4 + (int)(pDStack_220->ks[0].cblock + 6)
                                            ) << ((uint)pDStack_1e4 & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                             (int)(pDStack_220->ks[0].cblock + 7))
                                        >> (uVar10 & 0x1f)));
                uStack_1b0 = CONCAT31(uStack_1b0._0_3_,
                                      (byte)((int)(uint)abStack_1ac[(int)pDStack_220] >>
                                            (uVar10 & 0x1f)) |
                                      *(char *)((int)&uStack_1b4 +
                                               (int)(pDStack_220->ks[0].cblock + 7)) <<
                                      ((uint)pDStack_1e4 & 0x1f));
              }
              pDVar17 = (DES_key_schedule *)
                        ((((_uStack_1b4 >> 0x10) << 0x18 | (_uStack_1b4 >> 0x18) << 0x10) >> 0x10) +
                        ((_uStack_1b4 & 0xff) << 8 | _uStack_1b4 >> 8 & 0xff) * 0x10000);
              pDVar8 = (DES_key_schedule *)
                       ((((uStack_1b0 >> 0x10) << 0x18 | (uStack_1b0 >> 0x18) << 0x10) >> 0x10) +
                       ((uStack_1b0 & 0xff) << 8 | uStack_1b0 >> 8 & 0xff) * 0x10000);
            }
          }
          ((byte *)((int)puVar11 + (int)pDStack_284))[-1] = bVar18 ^ (byte)pDStack_1bc;
          pDStack_254 = (DES_key_schedule *)((int)pDVar16 - (int)pDStack_284);
          puVar11 = (uint *)((byte *)((int)puVar11 + (int)pDStack_284) + (int)pDVar15);
          pDStack_230 = pDStack_27c;
          pDVar28 = pDVar17;
        } while (pDStack_284 <= pDVar16);
      }
    }
    else {
      pDStack_214 = (DES_key_schedule *)(&switchD_005e64e8::switchdataD_00675590 + (int)pDStack_284)
      ;
      pDStack_280 = (DES_key_schedule *)(&PTR_LAB_006755fc + (int)pDStack_284);
      pDStack_254 = (DES_key_schedule *)&pDStack_1bc;
      pDVar27 = (DES_key_schedule *)((uint)pDVar29 & 7);
      pDVar28 = pDVar17;
      pDVar16 = pDVar8;
      while (pDVar8 = pDVar16, pDVar17 = pDVar28, pDStack_230 = pDStack_27c, pDStack_284 <= pDVar15)
      {
        pDVar14 = (DES_key_schedule *)0x1;
        pDStack_210 = (DES_key_schedule *)(uint)(pDStack_284 < (DES_key_schedule *)&DAT_00000009);
        puVar26 = pDStack_284->ks[0].cblock + (int)pDStack_27c->ks[0].cblock;
        pDStack_1e8 = pDStack_254;
        pDStack_1e4 = pDVar15;
        pDStack_1e0 = pDVar27;
        pDStack_1dc = pDVar29;
        pDStack_1bc = pDVar17;
        pDStack_1b8 = pDVar8;
        (*(code *)pDStack_1f8[-0xd2].ks[1].deslong[0])(pDStack_254,puStack_1ec);
        pDVar29 = pDStack_1dc;
        pDVar27 = pDStack_1e0;
        pDVar15 = (DES_key_schedule *)((int)pDStack_1e4 - (int)pDStack_284);
        if (pDStack_210 == (DES_key_schedule *)0x0) {
switchD_005e64e8_caseD_5e6bf4:
          uVar10 = 0;
          uVar7 = 0;
        }
        else {
          switch((uint)pDStack_214->ks[0].deslong[0] & 0xfffffffe) {
          case 0x5e6918:
            uVar10 = 0;
            break;
          case 0x5e6bb4:
            uVar10 = 0;
            goto LAB_005e6948;
          case 0x5e6bbc:
            uVar10 = 0;
            pDVar14 = (DES_key_schedule *)0x0;
            goto LAB_005e6954;
          case 0x5e6bc8:
            uVar10 = 0;
            uVar7 = 0;
            goto LAB_005e6964;
          case 0x5e6bdc:
            uVar10 = 0;
            goto LAB_005e692c;
          case 0x5e6be4:
            uVar10 = 0;
            goto LAB_005e693c;
          case 0x5e6bf4:
            goto switchD_005e64e8_caseD_5e6bf4;
          case 0x5e6c10:
            pbVar12 = puVar26 + -1;
            puVar26 = puVar26 + -1;
            uVar10 = (uint)*pbVar12 << 0x18;
          }
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar10 = (uint)*pbVar12 << 0x10 | uVar10;
LAB_005e692c:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar10 = (uint)*pbVar12 << 8 | uVar10;
LAB_005e693c:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar10 = *pbVar12 | uVar10;
LAB_005e6948:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          pDVar14 = (DES_key_schedule *)((uint)*pbVar12 << 0x18);
LAB_005e6954:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar7 = (uint)*pbVar12 << 0x10 | (uint)pDVar14;
LAB_005e6964:
          pbVar12 = puVar26 + -1;
          puVar26 = puVar26 + -1;
          uVar7 = (uint)*pbVar12 << 8 | uVar7;
        }
        puVar23 = (undefined *)((int)pDStack_284[-1].ks + 0x7f);
        pDStack_27c = (DES_key_schedule *)(puVar26 + (int)puVar23);
        pDVar6 = (DES_key_schedule *)((puVar26[-1] | uVar7) ^ (uint)pDStack_1bc);
        pDVar9 = (DES_key_schedule *)(uVar10 ^ (uint)pDStack_1b8);
        if (pDStack_210 != (DES_key_schedule *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e69a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)pDStack_280->ks[0].deslong[0])();
          return;
        }
        ((byte *)((int)puVar11 + (int)pDStack_284))[-1] = (byte)pDVar6;
        puVar11 = (uint *)((byte *)((int)puVar11 + (int)pDStack_284) + (int)puVar23);
        pDStack_254 = pDStack_1e8;
        pDVar28 = pDVar8;
        pDVar16 = pDVar6;
        if ((pDStack_1dc != (DES_key_schedule *)&DAT_00000020) &&
           (pDVar14 = (DES_key_schedule *)((uint)pDVar17 >> 0x10), pDVar28 = pDVar6,
           pDVar16 = pDVar9, pDStack_1dc != (DES_key_schedule *)&DAT_00000040)) {
          abStack_1ac[0] = (byte)pDVar6;
          abStack_1ac[1] = (char)((uint)pDVar6 >> 8);
          abStack_1ac[2] = (char)((uint)pDVar6 >> 0x10);
          _uStack_1b4 = CONCAT31(CONCAT21(CONCAT11((char)pDVar17,(char)((uint)pDVar17 >> 8)),
                                          (char)((uint)pDVar17 >> 0x10)),
                                 (char)((uint)pDVar17 >> 0x18));
          uStack_1b0 = CONCAT31(CONCAT21(CONCAT11((char)pDVar8,(char)((uint)pDVar8 >> 8)),
                                         (char)((uint)pDVar8 >> 0x10)),(char)((uint)pDVar8 >> 0x18))
          ;
          abStack_1ac[3] = (char)((uint)pDVar6 >> 0x18);
          abStack_1ac[4] = (char)pDVar9;
          abStack_1ac[5] = (char)((uint)pDVar9 >> 8);
          abStack_1ac[6] = (char)((uint)pDVar9 >> 0x10);
          abStack_1ac[7] = (char)((uint)pDVar9 >> 0x18);
          if (pDStack_1e0 == (DES_key_schedule *)0x0) {
            pDVar14 = (DES_key_schedule *)&DAT_00000008;
            pDStack_1dc = pDStack_1e8;
            pDStack_1e0 = pDVar29;
            pDStack_1e4 = pDVar27;
            pDStack_1e8 = pDVar15;
            (*(code *)*(DES_key_schedule **)((int)pDStack_1f8[-0xa6].ks + 0x1c))
                      (&uStack_1b4,(int)&uStack_1b4 + (int)pDStack_220);
            pDStack_254 = pDStack_1dc;
            pDVar27 = pDStack_1e4;
            pDVar15 = pDStack_1e8;
            pDVar29 = pDStack_1e0;
          }
          else {
            uVar10 = 8 - (int)pDStack_1e0;
            _uStack_1b3 = (uint3)(byte)(*(char *)((int)&uStack_1b4 +
                                                 (int)(pDStack_220->ks[0].cblock + 1)) <<
                                        ((uint)pDStack_1e0 & 0x1f) |
                                       (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                                  (int)(pDStack_220->ks[0].cblock +
                                                                       2)) >> (uVar10 & 0x1f))) <<
                          0x10;
            _uStack_1b4 = (uint3)(((uint)(byte)(*(char *)((int)&uStack_1b4 + (int)pDStack_220) <<
                                                ((uint)pDStack_1e0 & 0x1f) |
                                               (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                                          (int)(pDStack_220->ks[0].
                                                                                cblock + 1)) >>
                                                     (uVar10 & 0x1f))) << 0x18) >> 8) |
                          _uStack_1b3 >> 8 |
                          (uint3)(byte)(*(char *)((int)&uStack_1b4 +
                                                 (int)(pDStack_220->ks[0].cblock + 2)) <<
                                        ((uint)pDStack_1e0 & 0x1f) |
                                       (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                                  (int)(pDStack_220->ks[0].cblock +
                                                                       3)) >> (uVar10 & 0x1f)));
            _uStack_1b4 = CONCAT31(_uStack_1b4,
                                   *(char *)((int)&uStack_1b4 + (int)(pDStack_220->ks[0].cblock + 3)
                                            ) << ((uint)pDStack_1e0 & 0x1f) |
                                   (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                              (int)(pDStack_220->ks[0].cblock + 4))
                                         >> (uVar10 & 0x1f)));
            uStack_1b0._1_3_ =
                 (uint3)(byte)(*(char *)((int)&uStack_1b4 + (int)(pDStack_220->ks[0].cblock + 5)) <<
                               ((uint)pDStack_1e0 & 0x1f) |
                              (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                         (int)(pDStack_220->ks[0].cblock + 6)) >>
                                    (uVar10 & 0x1f))) << 0x10;
            pDVar14 = (DES_key_schedule *)
                      ((uint)*(byte *)((int)&uStack_1b4 + (int)(pDStack_220->ks[0].cblock + 6)) <<
                      ((uint)pDStack_1e0 & 0x1f));
            uStack_1b0._0_3_ =
                 (uint3)(((uint)(byte)(*(char *)((int)&uStack_1b4 +
                                                (int)(pDStack_220->ks[0].cblock + 4)) <<
                                       ((uint)pDStack_1e0 & 0x1f) |
                                      (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                                 (int)(pDStack_220->ks[0].cblock + 5
                                                                      )) >> (uVar10 & 0x1f))) <<
                         0x18) >> 8) | uStack_1b0._1_3_ >> 8 |
                 (uint3)(byte)((byte)pDVar14 |
                              (byte)((int)(uint)*(byte *)((int)&uStack_1b4 +
                                                         (int)(pDStack_220->ks[0].cblock + 7)) >>
                                    (uVar10 & 0x1f)));
            uStack_1b0 = CONCAT31(uStack_1b0._0_3_,
                                  (byte)((int)(uint)abStack_1ac[(int)pDStack_220] >> (uVar10 & 0x1f)
                                        ) | *(char *)((int)&uStack_1b4 +
                                                     (int)(pDStack_220->ks[0].cblock + 7)) <<
                                            ((uint)pDStack_1e0 & 0x1f));
          }
          pDVar28 = (DES_key_schedule *)
                    ((((_uStack_1b4 >> 0x10) << 0x18 | (_uStack_1b4 >> 0x18) << 0x10) >> 0x10) +
                    ((_uStack_1b4 & 0xff) << 8 | _uStack_1b4 >> 8 & 0xff) * 0x10000);
          pDVar16 = (DES_key_schedule *)
                    ((((uStack_1b0 >> 0x10) << 0x18 | (uStack_1b0 >> 0x18) << 0x10) >> 0x10) +
                    ((uStack_1b0 & 0xff) << 8 | uStack_1b0 >> 8 & 0xff) * 0x10000);
        }
      }
    }
    pDStack_27c = (DES_key_schedule *)((uint)pDVar17 >> 0x10);
    *(byte *)puStack_1cc = (byte)pDVar17;
    pDStack_228 = (DES_key_schedule *)((uint)pDVar17 >> 0x18);
    *(byte *)(puStack_1cc + 1) = (byte)pDVar8;
    *(byte *)((int)puStack_1cc + 1) = (byte)((uint)pDVar17 >> 8);
    pDStack_224 = (DES_key_schedule *)((uint)pDVar8 >> 0x18);
    *(byte *)((int)puStack_1cc + 2) = (byte)((uint)pDVar17 >> 0x10);
    *(byte *)((int)puStack_1cc + 3) = (byte)((uint)pDVar17 >> 0x18);
    *(byte *)((int)puStack_1cc + 5) = (byte)((uint)pDVar8 >> 8);
    *(byte *)((int)puStack_1cc + 6) = (byte)((uint)pDVar8 >> 0x10);
    *(byte *)((int)puStack_1cc + 7) = (byte)((uint)pDVar8 >> 0x18);
    puStack_278 = puStack_1cc;
    puStack_70 = puVar11;
  }
  if (iStack_1a4 == *piStack_1d0) {
    return;
  }
  pcStack_20c = DES_ede3_ofb64_encrypt;
  (*(code *)pDStack_1f8[-0xa7].ks[0xb].deslong[0])();
  pDStack_290 = pDStack_1f8;
  pbVar30 = &_gp;
  piStack_24c = (int *)PTR___stack_chk_guard_006aabf0;
  pDStack_218 = pDStack_280;
  pDStack_21c = pDStack_284;
  puStack_22c = puStack_70;
  pbStack_260 = &_gp;
  uVar20 = (uint)pbStack_1f0[3];
  uVar19 = (uint)pbStack_1f0[7];
  puStack_250 = puStack_1ec;
  uVar7 = uVar20 << 0x18 |
          (uint)pbStack_1f0[1] << 8 | (uint)pbStack_1f0[2] << 0x10 | (uint)*pbStack_1f0;
  uStack_298 = *puStack_1ec;
  uVar25 = uVar7 >> 8;
  iStack_234 = *(int *)PTR___stack_chk_guard_006aabf0;
  pbVar12 = (byte *)(uVar19 << 0x18);
  uStack_244 = uVar7;
  uVar10 = (uint)pbVar12 |
           (uint)pbStack_1f0[5] << 8 | (uint)pbStack_1f0[6] << 0x10 | (uint)pbStack_1f0[4];
  uVar24 = uVar7 >> 0x10;
  uStack_240 = uVar10;
  uVar22 = uVar10 >> 8;
  abStack_23c[0] = *pbStack_1f0;
  uVar21 = uVar10 >> 0x10;
  abStack_23c[1] = pbStack_1f0[1];
  abStack_23c[2] = pbStack_1f0[2];
  abStack_23c[3] = pbStack_1f0[3];
  bStack_238 = pbStack_1f0[4];
  bStack_237 = pbStack_1f0[5];
  bStack_236 = pbStack_1f0[6];
  bStack_235 = pbStack_1f0[7];
  if (pDVar14 != (DES_key_schedule *)0x0) {
    pDStack_284 = (DES_key_schedule *)0x0;
    puStack_70 = &uStack_244;
    pDStack_280 = pDVar14;
    puVar11 = puStack_278;
    do {
      if (uStack_298 == 0) {
        pDStack_284 = (DES_key_schedule *)((int)pDStack_284->ks + 1);
        pDVar14 = pDStack_290;
        (**(code **)(pbVar30 + -0x5764))(puStack_70,pDStack_254,pDStack_290,uStack_1f4);
        uVar25 = uStack_244 >> 8;
        uVar24 = uStack_244 >> 0x10;
        abStack_23c[0] = (byte)uStack_244;
        uVar20 = uStack_244 >> 0x18;
        bStack_238 = (byte)uStack_240;
        uVar22 = uStack_240 >> 8;
        abStack_23c[1] = (byte)(uStack_244 >> 8);
        uVar21 = uStack_240 >> 0x10;
        abStack_23c[2] = (byte)(uStack_244 >> 0x10);
        uVar19 = uStack_240 >> 0x18;
        abStack_23c[3] = (byte)(uStack_244 >> 0x18);
        bStack_237 = (byte)(uStack_240 >> 8);
        bStack_236 = (byte)(uStack_240 >> 0x10);
        bStack_235 = (byte)(uStack_240 >> 0x18);
        uVar10 = uStack_240;
        uVar7 = uStack_244;
        pbVar30 = pbStack_260;
      }
      puStack_278 = (uint *)((int)puVar11 + 1);
      p_Var4 = pDStack_27c->ks;
      pDStack_280 = (DES_key_schedule *)((int)pDStack_280[-1].ks + 0x7f);
      pbVar1 = abStack_23c + uStack_298;
      pbVar12 = (byte *)(uint)*pbVar1;
      pDStack_27c = (DES_key_schedule *)((int)pDStack_27c->ks + 1);
      uStack_298 = uStack_298 + 1 & 7;
      *(byte *)puVar11 = p_Var4->cblock[0] ^ *pbVar1;
      puVar11 = puStack_278;
    } while (pDStack_280 != (DES_key_schedule *)0x0);
    if (pDStack_284 != (DES_key_schedule *)0x0) {
      *pbStack_1f0 = (byte)uVar7;
      pbStack_1f0[1] = (byte)uVar25;
      pbStack_1f0[2] = (byte)uVar24;
      pbStack_1f0[3] = (byte)uVar20;
      pbStack_1f0[4] = (byte)uVar10;
      pbStack_1f0[5] = (byte)uVar22;
      pbStack_1f0[6] = (byte)uVar21;
      pbStack_1f0[7] = (byte)uVar19;
    }
  }
  iVar5 = *piStack_24c;
  *puStack_250 = uStack_298;
  if (iStack_234 != iVar5) {
    uStack_274 = 0x5e6f08;
    puVar11 = puStack_250;
    (**(code **)(pbVar30 + -0x5328))();
    pbVar30 = pbStack_260;
    puVar23 = PTR___stack_chk_guard_006aabf0;
    pbStack_288 = pbStack_1f0;
    uStack_28c = uStack_1f4;
    puStack_294 = puStack_70;
    uVar10 = (uint)pbStack_260[3];
    uVar7 = *puStack_25c;
    uStack_2ac = uVar10 << 0x18 |
                 (uint)pbStack_260[1] << 8 | (uint)pbStack_260[2] << 0x10 | (uint)*pbStack_260;
    iStack_29c = *(int *)PTR___stack_chk_guard_006aabf0;
    uStack_2a8 = (uint)pbStack_260[7] << 0x18 |
                 (uint)pbStack_260[5] << 8 | (uint)pbStack_260[6] << 0x10 | (uint)pbStack_260[4];
    abStack_2a4[0] = *pbStack_260;
    abStack_2a4[2] = pbStack_260[2];
    puVar13 = (uint *)(uStack_2a8 >> 8);
    abStack_2a4[1] = pbStack_260[1];
    abStack_2a4[3] = pbStack_260[3];
    bStack_2a0 = pbStack_260[4];
    bStack_29f = pbStack_260[5];
    bStack_29e = pbStack_260[6];
    bStack_29d = pbStack_260[7];
    if (pDVar14 != (DES_key_schedule *)0x0) {
      iVar5 = 0;
      pDVar29 = pDVar14;
      do {
        if (uVar7 == 0) {
          (*(code *)PTR_DES_encrypt1_006a95e8)(&uStack_2ac,uVar19,1);
          iVar5 = iVar5 + 1;
          pDVar14 = (DES_key_schedule *)(uStack_2ac >> 0x10);
          abStack_2a4[0] = (byte)uStack_2ac;
          puVar13 = (uint *)(uStack_2a8 >> 8);
          bStack_2a0 = (byte)uStack_2a8;
          abStack_2a4[1] = (byte)(uStack_2ac >> 8);
          abStack_2a4[2] = (byte)(uStack_2ac >> 0x10);
          bStack_29f = (byte)(uStack_2a8 >> 8);
          abStack_2a4[3] = (byte)(uStack_2ac >> 0x18);
          bStack_29e = (byte)(uStack_2a8 >> 0x10);
          bStack_29d = (byte)(uStack_2a8 >> 0x18);
        }
        bVar18 = *(byte *)puVar11;
        pDVar29 = (DES_key_schedule *)((int)pDVar29[-1].ks + 0x7f);
        pbVar1 = abStack_2a4 + uVar7;
        puVar11 = (uint *)((int)puVar11 + 1);
        uVar7 = uVar7 + 1 & 7;
        *pbVar12 = bVar18 ^ *pbVar1;
        pbVar12 = pbVar12 + 1;
      } while (pDVar29 != (DES_key_schedule *)0x0);
      if (iVar5 != 0) {
        pDVar14 = (DES_key_schedule *)(uStack_2ac >> 0x10);
        *pbVar30 = (byte)uStack_2ac;
        puVar13 = (uint *)(uStack_2a8 >> 8);
        pbVar30[4] = (byte)uStack_2a8;
        pbVar30[1] = (byte)(uStack_2ac >> 8);
        pbVar30[2] = (byte)(uStack_2ac >> 0x10);
        pbVar30[5] = (byte)(uStack_2a8 >> 8);
        pbVar30[3] = (byte)(uStack_2ac >> 0x18);
        pbVar30[6] = (byte)(uStack_2a8 >> 0x10);
        pbVar30[7] = (byte)(uStack_2a8 >> 0x18);
      }
    }
    iVar5 = *(int *)puVar23;
    *puStack_25c = uVar7;
    if (iStack_29c != iVar5) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      iVar5 = 0x19;
      uVar20 = 0;
      uVar19 = 0;
      uVar7 = 0;
      do {
        uVar21 = (uint)pDVar14 & (uVar19 ^ uVar20);
        uVar19 = uVar10 & (uVar19 ^ uVar20);
        uVar22 = uVar20 ^ *puVar13 ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar20 ^ puVar13[1] ^ uVar19;
        uVar19 = (uVar19 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar19 + uVar21 * 0x10000000;
        uVar7 = *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x100 >> 0x1a) + 0x140) * 4) ^ uVar7
        ;
        uVar19 = uVar7 >> 0x10 ^ uVar7;
        uVar21 = (uint)pDVar14 & uVar19;
        uVar19 = uVar10 & uVar19;
        uVar22 = uVar7 ^ puVar13[2] ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar7 ^ puVar13[3] ^ uVar19;
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
        uVar19 = uVar10 & uVar19;
        uVar21 = uVar22 ^ puVar13[4] ^ uVar20;
        uVar24 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar22 ^ puVar13[5] ^ uVar19;
        uVar19 = (uVar19 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar19 + uVar20 * 0x10000000;
        uVar21 = uVar7 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar21 >> 0x10 ^ uVar21;
        uVar19 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar20 = uVar21 ^ puVar13[6] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar20;
        uVar19 = uVar21 ^ puVar13[7] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar7 + uVar19 * 0x10000000;
        uVar20 = uVar22 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar20 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar20 ^ puVar13[8] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar20 ^ puVar13[9] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar7 + uVar19 * 0x10000000;
        uVar19 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        iVar5 = iVar5 + -1;
        uVar7 = uVar19 >> 0x10 ^ uVar19;
        uVar21 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar19 ^ puVar13[10] ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar19 ^ puVar13[0xb] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar7 + uVar21 * 0x10000000;
        uVar21 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar21 >> 0x10 ^ uVar21;
        uVar20 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar21 ^ puVar13[0xc] ^ uVar20;
        uVar24 = uVar20 << 0x10 ^ uVar22;
        uVar20 = uVar21 ^ puVar13[0xd] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar7 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar20 ^ puVar13[0xe] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar20 ^ puVar13[0xf] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar7 + uVar19 * 0x10000000;
        uVar19 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar19 >> 0x10 ^ uVar19;
        uVar21 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar19 ^ puVar13[0x10] ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar19 ^ puVar13[0x11] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar7 + uVar21 * 0x10000000;
        uVar21 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar21 >> 0x10 ^ uVar21;
        uVar20 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar21 ^ puVar13[0x12] ^ uVar20;
        uVar24 = uVar20 << 0x10 ^ uVar22;
        uVar20 = uVar21 ^ puVar13[0x13] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar7 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar20 ^ puVar13[0x14] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar20 ^ puVar13[0x15] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar7 + uVar19 * 0x10000000;
        uVar19 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar19 >> 0x10 ^ uVar19;
        uVar21 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar19 ^ puVar13[0x16] ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar22;
        uVar21 = uVar19 ^ puVar13[0x17] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar7 + uVar21 * 0x10000000;
        uVar21 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar21 >> 0x10 ^ uVar21;
        uVar20 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar21 ^ puVar13[0x18] ^ uVar20;
        uVar24 = uVar20 << 0x10 ^ uVar22;
        uVar20 = uVar21 ^ puVar13[0x19] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar7 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar20 ^ puVar13[0x1a] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar20 ^ puVar13[0x1b] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar7 + uVar19 * 0x10000000;
        uVar21 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar21 >> 0x10 ^ uVar21;
        uVar19 = (uint)pDVar14 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar22 = uVar21 ^ puVar13[0x1c] ^ uVar19;
        uVar24 = uVar19 << 0x10 ^ uVar22;
        uVar19 = uVar21 ^ puVar13[0x1d] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar7 + uVar19 * 0x10000000;
        uVar20 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar22 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar19 = uVar20 >> 0x10;
        uVar22 = (uint)pDVar14 & (uVar19 ^ uVar20);
        uVar7 = uVar10 & (uVar19 ^ uVar20);
        uVar24 = uVar20 ^ puVar13[0x1e] ^ uVar22;
        uVar25 = uVar22 << 0x10 ^ uVar24;
        uVar22 = uVar20 ^ puVar13[0x1f] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar22) >> 4;
        uVar22 = uVar7 + uVar22 * 0x10000000;
        uVar7 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar25 >> 0x1a) + 0x180) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar25 & 0xfc)) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 0x10) >> 0x1a) + 0x80) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar25 << 8) >> 0x1a) + 0x100) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar22 >> 0x1a) + 0x1c0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar22 & 0xfc) + 0x100) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
      } while (iVar5 != 0);
      uVar7 = (uVar7 >> 3) + uVar7 * 0x20000000;
      uVar19 = (uVar20 >> 3) + uVar20 * 0x20000000;
      uVar10 = (uVar7 >> 1 ^ uVar19) & 0x55555555;
      uVar19 = uVar19 ^ uVar10;
      uVar7 = uVar10 << 1 ^ uVar7;
      uVar10 = (uVar19 >> 8 ^ uVar7) & 0xff00ff;
      uVar7 = uVar7 ^ uVar10;
      uVar19 = uVar10 << 8 ^ uVar19;
      uVar10 = (uVar7 >> 2 ^ uVar19) & 0x33333333;
      uVar19 = uVar19 ^ uVar10;
      uVar7 = uVar10 << 2 ^ uVar7;
      uVar10 = (uVar19 >> 0x10 ^ uVar7) & 0xffff;
      uVar7 = uVar7 ^ uVar10;
      uVar19 = uVar10 << 0x10 ^ uVar19;
      uVar10 = (uVar7 >> 4 ^ uVar19) & 0xf0f0f0f;
      *puStack_25c = uVar19 ^ uVar10;
      puStack_25c[1] = uVar10 << 4 ^ uVar7;
      return;
    }
    return;
  }
  return;
}

