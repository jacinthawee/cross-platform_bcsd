
/* WARNING: Removing unreachable block (ram,0x005e689c) */
/* WARNING: Removing unreachable block (ram,0x005e61d0) */
/* WARNING: Removing unreachable block (ram,0x005e5f10) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Could not reconcile some variable overlaps */

void DES_cfb64_encrypt(uchar *in,uchar *out,long length,DES_key_schedule *schedule,DES_cblock *ivec,
                      int *num,int enc)

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
  byte *pbVar11;
  uint *puVar12;
  DES_key_schedule *pDVar13;
  DES_key_schedule *pDVar14;
  DES_key_schedule *pDVar15;
  DES_key_schedule *pDVar16;
  byte bVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  undefined *puVar22;
  uint uVar23;
  uint uVar24;
  uchar *puVar25;
  DES_key_schedule *pDVar26;
  DES_key_schedule *pDVar27;
  uint *puVar28;
  DES_key_schedule *pDVar29;
  byte *pbVar30;
  DES_key_schedule **unaff_s8;
  uint uStack_274;
  uint uStack_270;
  byte abStack_26c [4];
  byte bStack_268;
  byte bStack_267;
  byte bStack_266;
  byte bStack_265;
  int iStack_264;
  uint uStack_260;
  uint *puStack_25c;
  DES_key_schedule *pDStack_258;
  undefined4 uStack_254;
  byte *pbStack_250;
  DES_key_schedule *pDStack_24c;
  DES_key_schedule *pDStack_248;
  DES_key_schedule *pDStack_244;
  uint *puStack_240;
  undefined4 uStack_23c;
  byte *pbStack_228;
  uint *puStack_224;
  DES_key_schedule *pDStack_21c;
  uint *puStack_218;
  int *piStack_214;
  uint uStack_20c;
  uint uStack_208;
  byte abStack_204 [4];
  byte bStack_200;
  byte bStack_1ff;
  byte bStack_1fe;
  byte bStack_1fd;
  int iStack_1fc;
  DES_key_schedule *pDStack_1f8;
  uint *puStack_1f4;
  DES_key_schedule *pDStack_1f0;
  DES_key_schedule *pDStack_1ec;
  DES_key_schedule *pDStack_1e8;
  DES_key_schedule *pDStack_1e4;
  DES_key_schedule *pDStack_1e0;
  DES_key_schedule *pDStack_1dc;
  DES_key_schedule *pDStack_1d8;
  code *pcStack_1d4;
  DES_key_schedule *pDStack_1c0;
  undefined4 uStack_1bc;
  byte *pbStack_1b8;
  uint *puStack_1b4;
  DES_key_schedule *pDStack_1b0;
  DES_key_schedule *pDStack_1ac;
  DES_key_schedule *pDStack_1a8;
  DES_key_schedule *pDStack_1a4;
  DES_key_schedule *pDStack_1a0;
  code **ppcStack_19c;
  int *piStack_198;
  uint *puStack_194;
  DES_key_schedule *pDStack_190;
  DES_key_schedule *pDStack_18c;
  DES_key_schedule *pDStack_184;
  DES_key_schedule *pDStack_180;
  undefined uStack_17c;
  undefined uStack_17b;
  byte abStack_17a [2];
  undefined4 uStack_178;
  byte abStack_174 [8];
  int iStack_16c;
  DES_key_schedule *pDStack_168;
  uint *puStack_164;
  DES_key_schedule *pDStack_160;
  DES_key_schedule *pDStack_15c;
  DES_key_schedule *pDStack_158;
  DES_key_schedule *pDStack_154;
  DES_key_schedule *pDStack_150;
  DES_key_schedule *pDStack_14c;
  DES_key_schedule *pDStack_148;
  undefined4 uStack_144;
  uint *puStack_130;
  uint *puStack_12c;
  int iStack_128;
  DES_key_schedule *pDStack_124;
  undefined4 uStack_120;
  DES_key_schedule *pDStack_11c;
  DES_key_schedule **ppDStack_118;
  DES_key_schedule **ppDStack_114;
  undefined *puStack_110;
  int *piStack_10c;
  int iStack_108;
  uint uStack_104;
  undefined4 *puStack_100;
  DES_key_schedule *pDStack_fc;
  DES_key_schedule *pDStack_f8;
  undefined4 uStack_f4;
  DES_key_schedule *pDStack_ec;
  DES_key_schedule *pDStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  byte bStack_dc;
  undefined uStack_db;
  undefined uStack_da;
  undefined uStack_d9;
  undefined uStack_d8;
  undefined uStack_d7;
  undefined uStack_d6;
  undefined uStack_d5;
  int iStack_d4;
  DES_key_schedule *pDStack_d0;
  uint *puStack_cc;
  DES_key_schedule *pDStack_c8;
  DES_key_schedule *pDStack_c4;
  DES_key_schedule *pDStack_c0;
  uint *puStack_bc;
  undefined *puStack_b8;
  DES_key_schedule *pDStack_b4;
  DES_key_schedule *pDStack_b0;
  code *pcStack_ac;
  DES_key_schedule *pDStack_a0;
  DES_key_schedule *pDStack_98;
  undefined4 uStack_94;
  DES_key_schedule *pDStack_90;
  DES_key_schedule *pDStack_8c;
  int iStack_88;
  uint uStack_84;
  uint uStack_80;
  int iStack_7c;
  uint uStack_78;
  DES_cblock *pauStack_74;
  long lStack_70;
  DES_key_schedule *pDStack_6c;
  int *piStack_68;
  undefined *puStack_64;
  byte *pbStack_60;
  byte *pbStack_5c;
  DES_key_schedule **ppDStack_58;
  undefined4 uStack_54;
  DES_key_schedule *local_40;
  DES_key_schedule *pDStack_3c;
  uint *puStack_38;
  DES_key_schedule *local_34;
  uint local_30;
  int local_2c;
  
  puStack_64 = PTR___stack_chk_guard_006aabf0;
  pDVar29 = (DES_key_schedule *)&_gp;
  local_40 = (DES_key_schedule *)&_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_78 = *num;
  pDStack_c8 = schedule;
  lStack_70 = length;
  pbStack_60 = in;
  pbStack_5c = out;
  if (enc == 0) {
    unaff_s8 = &local_34;
    pbVar11 = out;
    if (length != 0) {
      do {
        length = 1;
        if (uStack_78 == 0) {
          local_30 = (uint)(*ivec)[7] << 0x18 |
                     (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4];
          pDStack_c8 = (DES_key_schedule *)
                       ((uint)(*ivec)[3] << 0x18 |
                       (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0]);
          local_34 = pDStack_c8;
          (**(code **)((int)pDVar29 + -0x68f8))(unaff_s8,schedule);
          length = (uint)local_34 >> 0x10;
          (*ivec)[0] = (uchar)local_34;
          out = (uchar *)(local_30 >> 8);
          (*ivec)[4] = (uchar)local_30;
          (*ivec)[1] = (uchar)((uint)local_34 >> 8);
          (*ivec)[2] = (uchar)((uint)local_34 >> 0x10);
          (*ivec)[5] = (uchar)(local_30 >> 8);
          (*ivec)[3] = (uchar)((uint)local_34 >> 0x18);
          (*ivec)[6] = (uchar)(local_30 >> 0x10);
          (*ivec)[7] = (uchar)(local_30 >> 0x18);
          pDVar29 = local_40;
        }
        bVar17 = *pbStack_60;
        bVar2 = (*ivec)[uStack_78];
        in = (uchar *)(uint)bVar2;
        lStack_70 = lStack_70 + -1;
        (*ivec)[uStack_78] = bVar17;
        pbStack_60 = pbStack_60 + 1;
        uStack_78 = uStack_78 + 1 & 7;
        *pbVar11 = bVar17 ^ bVar2;
        pbStack_5c = pbVar11 + 1;
        pbVar11 = pbVar11 + 1;
      } while (lStack_70 != 0);
    }
  }
  else if (length != 0) {
    unaff_s8 = &local_34;
    pbVar11 = in;
    pbVar30 = out;
    do {
      if (uStack_78 == 0) {
        local_30 = (uint)(*ivec)[7] << 0x18 |
                   (uint)(*ivec)[5] << 8 | (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[4];
        pDStack_c8 = (DES_key_schedule *)
                     ((uint)(*ivec)[3] << 0x18 |
                     (uint)(*ivec)[1] << 8 | (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[0]);
        local_34 = pDStack_c8;
        (*(code *)local_40[-0xd2].ks[1].deslong[0])(unaff_s8,schedule,1);
        length = (uint)local_34 >> 0x10;
        (*ivec)[0] = (uchar)local_34;
        out = (uchar *)(local_30 >> 8);
        (*ivec)[4] = (uchar)local_30;
        (*ivec)[1] = (uchar)((uint)local_34 >> 8);
        (*ivec)[2] = (uchar)((uint)local_34 >> 0x10);
        (*ivec)[5] = (uchar)(local_30 >> 8);
        (*ivec)[3] = (uchar)((uint)local_34 >> 0x18);
        (*ivec)[6] = (uchar)(local_30 >> 0x10);
        (*ivec)[7] = (uchar)(local_30 >> 0x18);
      }
      puVar25 = *ivec + uStack_78;
      pbStack_5c = pbVar30 + 1;
      bVar17 = *puVar25;
      in = (uchar *)(uint)bVar17;
      lStack_70 = lStack_70 + -1;
      pbStack_60 = pbVar11 + 1;
      uStack_78 = uStack_78 + 1 & 7;
      bVar17 = *pbVar11 ^ bVar17;
      *pbVar30 = bVar17;
      *puVar25 = bVar17;
      pDVar29 = local_40;
      pbVar11 = pbStack_60;
      pbVar30 = pbStack_5c;
    } while (lStack_70 != 0);
  }
  iVar5 = *(int *)puStack_64;
  *num = uStack_78;
  if (local_2c == iVar5) {
    return;
  }
  uStack_54 = 0x5e5728;
  (*(code *)pDVar29[-0xa7].ks[0xb].deslong[0])();
  pDStack_1ec = local_40;
  pDStack_150 = (DES_key_schedule *)PTR___stack_chk_guard_006aabf0;
  pDVar29 = (DES_key_schedule *)&_gp;
  piStack_68 = num;
  pDStack_8c = local_34;
  pauStack_74 = ivec;
  pDStack_98 = (DES_key_schedule *)&_gp;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_d0 = (DES_key_schedule *)local_34->ks[0].deslong[0];
  pDVar14 = pDStack_c8;
  puStack_bc = (uint *)out;
  pDStack_14c = (DES_key_schedule *)length;
  pDVar13 = pDStack_90;
  pDStack_6c = schedule;
  ppDStack_58 = unaff_s8;
  if (local_30 == 0) {
    pDVar16 = (DES_key_schedule *)&uStack_84;
    for (; pDStack_90 = pDVar16, pDStack_14c != (DES_key_schedule *)0x0;
        pDStack_14c = (DES_key_schedule *)((int)pDStack_14c[-1].ks + 0x7f)) {
      pDVar14 = pDStack_3c;
      pDVar16 = pDStack_90;
      if (pDStack_d0 == (DES_key_schedule *)0x0) {
        uStack_80 = (uint)*(byte *)((int)puStack_38 + 7) << 0x18 |
                    (uint)*(byte *)((int)puStack_38 + 5) << 8 |
                    (uint)*(byte *)((int)puStack_38 + 6) << 0x10 | (uint)*(byte *)(puStack_38 + 1);
        uStack_84 = (uint)*(byte *)((int)puStack_38 + 3) << 0x18 |
                    (uint)*(byte *)((int)puStack_38 + 1) << 8 |
                    (uint)*(byte *)((int)puStack_38 + 2) << 0x10 | (uint)*(byte *)puStack_38;
        (**(code **)((int)pDVar29 + -0x5764))(pDStack_90,pDStack_c8,pDStack_1ec);
        pDVar14 = (DES_key_schedule *)(uStack_84 >> 0x10);
        *(byte *)puStack_38 = (byte)uStack_84;
        length = uStack_80 >> 8;
        *(byte *)(puStack_38 + 1) = (byte)uStack_80;
        *(byte *)((int)puStack_38 + 1) = (byte)(uStack_84 >> 8);
        *(byte *)((int)puStack_38 + 2) = (byte)(uStack_84 >> 0x10);
        *(byte *)((int)puStack_38 + 5) = (byte)(uStack_80 >> 8);
        *(byte *)((int)puStack_38 + 3) = (byte)(uStack_84 >> 0x18);
        *(byte *)((int)puStack_38 + 6) = (byte)(uStack_80 >> 0x10);
        *(byte *)((int)puStack_38 + 7) = (byte)(uStack_80 >> 0x18);
        pDVar16 = pDStack_90;
        pDVar29 = pDStack_98;
        pDVar13 = pDStack_90;
      }
      pDStack_90 = pDVar13;
      bVar17 = ((_union_771 *)in)->cblock[0];
      bVar2 = *(byte *)((int)puStack_38 + (int)pDStack_d0);
      out = (uchar *)(uint)bVar2;
      *(byte *)((int)puStack_38 + (int)pDStack_d0) = bVar17;
      in = (uchar *)((int)(_union_771 *)in + 1);
      pDStack_d0 = (DES_key_schedule *)((uint)((int)pDStack_d0->ks + 1) & 7);
      *(byte *)puStack_bc = bVar17 ^ bVar2;
      puStack_bc = (uint *)((int)puStack_bc + 1);
      pDVar13 = pDStack_90;
    }
  }
  else if ((DES_key_schedule *)length != (DES_key_schedule *)0x0) {
    pDVar16 = (DES_key_schedule *)&uStack_84;
    puVar28 = (uint *)out;
    do {
      pDStack_90 = pDVar16;
      pDVar16 = pDStack_90;
      if (pDStack_d0 == (DES_key_schedule *)0x0) {
        uStack_80 = (uint)*(byte *)((int)puStack_38 + 7) << 0x18 |
                    (uint)*(byte *)((int)puStack_38 + 5) << 8 |
                    (uint)*(byte *)((int)puStack_38 + 6) << 0x10 | (uint)*(byte *)(puStack_38 + 1);
        uStack_84 = (uint)*(byte *)((int)puStack_38 + 3) << 0x18 |
                    (uint)*(byte *)((int)puStack_38 + 1) << 8 |
                    (uint)*(byte *)((int)puStack_38 + 2) << 0x10 | (uint)*(byte *)puStack_38;
        (**(code **)((int)pDStack_98[-0xaf].ks + 0x1c))
                  (pDStack_90,pDStack_c8,pDStack_1ec,pDStack_3c);
        pDVar14 = (DES_key_schedule *)(uStack_84 >> 0x10);
        *(byte *)puStack_38 = (byte)uStack_84;
        length = uStack_80 >> 8;
        *(byte *)(puStack_38 + 1) = (byte)uStack_80;
        *(byte *)((int)puStack_38 + 1) = (byte)(uStack_84 >> 8);
        *(byte *)((int)puStack_38 + 2) = (byte)(uStack_84 >> 0x10);
        *(byte *)((int)puStack_38 + 5) = (byte)(uStack_80 >> 8);
        *(byte *)((int)puStack_38 + 3) = (byte)(uStack_84 >> 0x18);
        *(byte *)((int)puStack_38 + 6) = (byte)(uStack_80 >> 0x10);
        *(byte *)((int)puStack_38 + 7) = (byte)(uStack_80 >> 0x18);
        pDVar13 = pDStack_90;
        pDVar16 = pDStack_90;
      }
      pDStack_90 = pDVar13;
      pbVar11 = (byte *)((int)puStack_38 + (int)pDStack_d0);
      p_Var4 = (_union_771 *)in;
      puStack_bc = (uint *)((int)puVar28 + 1);
      bVar17 = *pbVar11;
      out = (uchar *)(uint)bVar17;
      pDStack_14c = (DES_key_schedule *)((int)pDStack_14c[-1].ks + 0x7f);
      in = (uchar *)((int)(_union_771 *)in + 1);
      pDStack_d0 = (DES_key_schedule *)((uint)((int)pDStack_d0->ks + 1) & 7);
      bVar17 = p_Var4->cblock[0] ^ bVar17;
      *(byte *)puVar28 = bVar17;
      *pbVar11 = bVar17;
      pDVar29 = pDStack_98;
      pDVar13 = pDStack_90;
      puVar28 = puStack_bc;
    } while (pDStack_14c != (DES_key_schedule *)0x0);
  }
  pDStack_90 = pDVar13;
  iVar5 = *(int *)pDStack_150;
  pDStack_8c->ks[0].deslong[0] = (uint)pDStack_d0;
  if (iStack_7c == iVar5) {
    return;
  }
  pcStack_ac = DES_ede3_cfb_encrypt;
  pDVar13 = pDStack_8c;
  (*(code *)pDVar29[-0xa7].ks[0xb].deslong[0])();
  uStack_120 = uStack_94;
  piStack_10c = (int *)PTR___stack_chk_guard_006aabf0;
  puStack_b8 = (undefined *)pDStack_150;
  pDStack_11c = pDStack_90;
  pDStack_c0 = pDStack_3c;
  pDStack_c4 = pDStack_1ec;
  puStack_cc = puStack_38;
  puStack_130 = (uint *)&_gp;
  iStack_d4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pDStack_124 = pDStack_98;
  pDStack_fc = pDStack_8c;
  pDStack_244 = pDStack_8c;
  pDVar29 = pDStack_98;
  pDStack_168 = pDStack_d0;
  pDStack_1f0 = pDStack_c8;
  pDStack_1d8 = (DES_key_schedule *)in;
  pDStack_b4 = pDStack_14c;
  pDStack_b0 = (DES_key_schedule *)in;
  if (length < 0x41) {
    pDVar29 = (DES_key_schedule *)((int)(_union_771 *)length + 7);
    pDVar26 = (DES_key_schedule *)((uint)pDVar29 >> 3);
    pDVar16 = (DES_key_schedule *)
              ((uint)pDStack_8c->ks[0].cblock[7] << 0x18 |
              (uint)pDStack_8c->ks[0].cblock[5] << 8 | (uint)pDStack_8c->ks[0].cblock[6] << 0x10 |
              (uint)pDStack_8c->ks[0].cblock[4]);
    pDVar8 = (DES_key_schedule *)
             ((uint)pDStack_8c->ks[0].cblock[1] << 8 | (uint)pDStack_8c->ks[0].cblock[2] << 0x10 |
              (uint)pDStack_8c->ks[0].cblock[0] | (uint)pDStack_8c->ks[0].cblock[3] << 0x18);
    pDStack_1ec = pDVar26;
    puStack_38 = (uint *)out;
    if (iStack_88 == 0) {
      if (pDVar26 <= pDVar14) {
        if (-1 < length) {
          pDVar29 = (DES_key_schedule *)length;
        }
        puStack_100 = &uStack_e4;
        uStack_104 = length & 7;
        iStack_108 = (int)puStack_100 + ((int)pDVar29 >> 3);
        pDStack_150 = (DES_key_schedule *)(length & 0x80000007);
        if ((int)pDStack_150 < 0) {
          pDStack_150 = (DES_key_schedule *)
                        (((uint)((int)pDStack_150[-1].ks + 0x7f) | 0xfffffff8) + 1);
        }
        pDStack_1f0 = (DES_key_schedule *)(8 - (int)pDStack_150);
        ppDStack_118 = &pDStack_ec;
        pDVar27 = (DES_key_schedule *)((int)pDVar14 - (int)pDVar26);
        ppDStack_114 = (DES_key_schedule **)(&PTR_LAB_00675524 + (int)pDVar26);
        puStack_110 = &UNK_0067556c + (int)pDVar26 * 4;
        pDStack_1d8 = (DES_key_schedule *)(uint)(pDVar26 < (DES_key_schedule *)&DAT_00000009);
        pDStack_168 = pDVar13;
        pDVar29 = pDVar16;
        pDVar13 = pDVar8;
        pDStack_a0 = (DES_key_schedule *)length;
        do {
          pDStack_168 = (DES_key_schedule *)((int)pDStack_168->ks + (int)pDVar26 * 2);
          pDStack_ec = pDVar13;
          pDStack_e8 = pDVar29;
          (*(code *)puStack_130[-0x15d9])(ppDStack_118,pDStack_124,uStack_120,pDStack_11c);
          if (pDStack_1d8 != (DES_key_schedule *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e5e80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)*ppDStack_114)();
            return;
          }
          pDVar16 = (DES_key_schedule *)0x0;
          pDVar14 = (DES_key_schedule *)0x0;
          if (pDStack_a0 == (DES_key_schedule *)&DAT_00000020) {
            pDVar16 = (DES_key_schedule *)0x0;
            pDVar8 = pDVar29;
          }
          else {
            pDVar8 = pDVar14;
            if (pDStack_a0 != (DES_key_schedule *)&DAT_00000040) {
              bStack_dc = 0;
              uStack_da = 0;
              uStack_e4 = CONCAT22(CONCAT11((char)pDVar13,(char)((uint)pDVar13 >> 8)),
                                   CONCAT11((char)((uint)pDVar13 >> 0x10),
                                            (char)((uint)pDVar13 >> 0x18)));
              uStack_db = 0;
              uStack_d5 = 0;
              uStack_e0 = CONCAT31(CONCAT21(CONCAT11((char)pDVar29,(char)((uint)pDVar29 >> 8)),
                                            (char)((uint)pDVar29 >> 0x10)),
                                   (char)((uint)pDVar29 >> 0x18));
              uStack_d9 = 0;
              uStack_d8 = 0;
              uStack_d7 = 0;
              uStack_d6 = 0;
              if (uStack_104 == 0) {
                uStack_f4 = 0;
                pDStack_f8 = (DES_key_schedule *)0x0;
                (*(code *)puStack_130[-0x14b9])(puStack_100,iStack_108,8);
              }
              else {
                uStack_f4 = 0;
                pDStack_f8 = (DES_key_schedule *)0x0;
                (*(code *)puStack_130[-0x14b9])(puStack_100,iStack_108,9);
                uStack_e4 = CONCAT31(CONCAT21(CONCAT11(uStack_e4._0_1_ << ((uint)pDStack_150 & 0x1f)
                                                       | (byte)((int)(uint)uStack_e4._1_1_ >>
                                                               ((uint)pDStack_1f0 & 0x1f)),
                                                       uStack_e4._1_1_ << ((uint)pDStack_150 & 0x1f)
                                                       | (byte)((int)(uint)uStack_e4._2_1_ >>
                                                               ((uint)pDStack_1f0 & 0x1f))),
                                              uStack_e4._2_1_ << ((uint)pDStack_150 & 0x1f) |
                                              (byte)((int)(uStack_e4 & 0xff) >>
                                                    ((uint)pDStack_1f0 & 0x1f))),
                                     (char)uStack_e4 << ((uint)pDStack_150 & 0x1f) |
                                     (byte)((int)(uint)uStack_e0._0_1_ >> ((uint)pDStack_1f0 & 0x1f)
                                           ));
                uStack_e0 = CONCAT31(CONCAT21(CONCAT11(uStack_e0._0_1_ << ((uint)pDStack_150 & 0x1f)
                                                       | (byte)((int)(uint)uStack_e0._1_1_ >>
                                                               ((uint)pDStack_1f0 & 0x1f)),
                                                       uStack_e0._1_1_ << ((uint)pDStack_150 & 0x1f)
                                                       | (byte)((int)(uint)uStack_e0._2_1_ >>
                                                               ((uint)pDStack_1f0 & 0x1f))),
                                              uStack_e0._2_1_ << ((uint)pDStack_150 & 0x1f) |
                                              (byte)((int)(uStack_e0 & 0xff) >>
                                                    ((uint)pDStack_1f0 & 0x1f))),
                                     (byte)((int)(uint)bStack_dc >> ((uint)pDStack_1f0 & 0x1f)) |
                                     (char)uStack_e0 << ((uint)pDStack_150 & 0x1f));
              }
              pDVar16 = (DES_key_schedule *)
                        ((((uStack_e0 >> 0x10) << 0x18 | (uStack_e0 >> 0x18) << 0x10) >> 0x10) +
                        ((uStack_e0 & 0xff) << 8 | uStack_e0 >> 8 & 0xff) * 0x10000);
              pDVar14 = pDStack_f8;
              pDVar8 = (DES_key_schedule *)
                       ((((uStack_e4 >> 0x10) << 0x18 | (uStack_e4 >> 0x18) << 0x10) >> 0x10) +
                       ((uStack_e4 & 0xff) << 8 | uStack_e4 >> 8 & 0xff) * 0x10000);
            }
          }
          out = (uchar *)((int)out + (int)pDVar26 * 2);
          pDVar14 = (DES_key_schedule *)((uint)pDVar14 ^ (uint)pDStack_ec);
          bVar3 = pDVar26 <= pDVar27;
          pDVar27 = (DES_key_schedule *)((int)pDVar27 - (int)pDVar26);
          puStack_38 = (uint *)out;
          pDStack_1ec = pDVar16;
          pDVar29 = pDVar16;
          pDStack_3c = pDVar26;
          length = (long)pDVar27;
          pDStack_14c = pDVar8;
          pDVar13 = pDVar8;
        } while (bVar3);
      }
    }
    else if (pDVar26 <= pDVar14) {
      if (-1 < length) {
        pDVar29 = (DES_key_schedule *)length;
      }
      puStack_100 = &uStack_e4;
      uStack_104 = length & 7;
      iStack_108 = (int)puStack_100 + ((int)pDVar29 >> 3);
      pDStack_168 = (DES_key_schedule *)(length & 0x80000007);
      if ((int)pDStack_168 < 0) {
        pDStack_168 = (DES_key_schedule *)
                      (((uint)((int)pDStack_168[-1].ks + 0x7f) | 0xfffffff8) + 1);
      }
      pDStack_150 = (DES_key_schedule *)(&DAT_00675500 + (int)pDVar26 * 4);
      puStack_110 = &UNK_00675548 + (int)pDVar26 * 4;
      ppDStack_114 = &pDStack_ec;
      pDStack_1ec = (DES_key_schedule *)((int)pDVar14 - (int)pDVar26);
      ppDStack_118 = (DES_key_schedule **)(uint)(pDVar26 < (DES_key_schedule *)&DAT_00000009);
      pDStack_1f0 = (DES_key_schedule *)(8 - (int)pDStack_168);
      pDVar29 = pDVar16;
      pDVar27 = pDVar8;
      pDStack_1d8 = pDVar13;
      pDStack_a0 = (DES_key_schedule *)length;
      do {
        pDStack_1d8 = (DES_key_schedule *)((int)pDStack_1d8->ks + (int)pDVar26 * 2);
        pDVar14 = pDStack_11c;
        pDStack_ec = pDVar27;
        pDStack_e8 = pDVar29;
        (*(code *)puStack_130[-0x15d9])(ppDStack_114,pDStack_124,uStack_120);
        if (ppDStack_118 != (DES_key_schedule **)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e5bac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)pDStack_150->ks[0].deslong[0])();
          return;
        }
        puStack_38 = (uint *)((int)puStack_38 + (int)pDVar26 * 2);
        pDVar16 = pDStack_ec;
        pDVar8 = pDVar29;
        if ((pDStack_a0 != (DES_key_schedule *)&DAT_00000020) &&
           (pDVar16 = pDStack_e8, pDVar8 = pDStack_ec,
           pDStack_a0 != (DES_key_schedule *)&DAT_00000040)) {
          bStack_dc = (byte)pDStack_ec;
          uStack_e4 = CONCAT31(CONCAT21(CONCAT11((char)pDVar27,(char)((uint)pDVar27 >> 8)),
                                        (char)((uint)pDVar27 >> 0x10)),(char)((uint)pDVar27 >> 0x18)
                              );
          pDVar14 = (DES_key_schedule *)((uint)pDVar29 >> 8);
          uStack_db = (undefined)((uint)pDStack_ec >> 8);
          uStack_da = (undefined)((uint)pDStack_ec >> 0x10);
          uStack_d9 = (undefined)((uint)pDStack_ec >> 0x18);
          uStack_e0._0_1_ = (byte)pDVar29;
          uStack_e0 = (uint)CONCAT12(uStack_e0._0_1_,
                                     CONCAT11((char)((uint)pDVar29 >> 8),
                                              (char)((uint)pDVar29 >> 0x10))) << 8;
          uStack_e0 = uStack_e0 | (uint)pDVar29 >> 0x18;
          uStack_d8 = SUB41(pDStack_e8,0);
          uStack_d7 = (undefined)((uint)pDStack_e8 >> 8);
          uStack_d6 = (undefined)((uint)pDStack_e8 >> 0x10);
          uStack_d5 = (undefined)((uint)pDStack_e8 >> 0x18);
          if (uStack_104 == 0) {
            (*(code *)puStack_130[-0x14b9])(puStack_100,iStack_108,8);
          }
          else {
            (*(code *)puStack_130[-0x14b9])(puStack_100,iStack_108,9);
            pDVar14 = (DES_key_schedule *)
                      ((uStack_e4 >> 0x18) << ((uint)pDStack_168 & 0x1f) |
                      (int)(uint)uStack_e4._1_1_ >> ((uint)pDStack_1f0 & 0x1f));
            uStack_e4._0_1_ = (char)pDVar14;
            uStack_e4 = CONCAT31(CONCAT12(uStack_e4._0_1_,
                                          CONCAT11(uStack_e4._1_1_ << ((uint)pDStack_168 & 0x1f) |
                                                   (byte)((int)(uint)uStack_e4._2_1_ >>
                                                         ((uint)pDStack_1f0 & 0x1f)),
                                                   uStack_e4._2_1_ << ((uint)pDStack_168 & 0x1f) |
                                                   (byte)((int)(uStack_e4 & 0xff) >>
                                                         ((uint)pDStack_1f0 & 0x1f)))),
                                 (char)uStack_e4 << ((uint)pDStack_168 & 0x1f) |
                                 (byte)((int)(uint)uStack_e0._0_1_ >> ((uint)pDStack_1f0 & 0x1f)));
            uStack_e0 = CONCAT31(CONCAT21(CONCAT11(uStack_e0._0_1_ << ((uint)pDStack_168 & 0x1f) |
                                                   (byte)((int)(uint)uStack_e0._1_1_ >>
                                                         ((uint)pDStack_1f0 & 0x1f)),
                                                   uStack_e0._1_1_ << ((uint)pDStack_168 & 0x1f) |
                                                   (byte)((int)(uint)uStack_e0._2_1_ >>
                                                         ((uint)pDStack_1f0 & 0x1f))),
                                          uStack_e0._2_1_ << ((uint)pDStack_168 & 0x1f) |
                                          (byte)((int)(uStack_e0 & 0xff) >>
                                                ((uint)pDStack_1f0 & 0x1f))),
                                 (byte)((int)(uint)bStack_dc >> ((uint)pDStack_1f0 & 0x1f)) |
                                 (char)uStack_e0 << ((uint)pDStack_168 & 0x1f));
          }
          pDVar16 = (DES_key_schedule *)
                    ((((uStack_e0 >> 0x10) << 0x18 | (uStack_e0 >> 0x18) << 0x10) >> 0x10) +
                    ((uStack_e0 & 0xff) << 8 | uStack_e0 >> 8 & 0xff) * 0x10000);
          pDVar8 = (DES_key_schedule *)
                   ((((uStack_e4 >> 0x10) << 0x18 | (uStack_e4 >> 0x18) << 0x10) >> 0x10) +
                   ((uStack_e4 & 0xff) << 8 | uStack_e4 >> 8 & 0xff) * 0x10000);
        }
        bVar3 = pDVar26 <= pDStack_1ec;
        pDStack_1ec = (DES_key_schedule *)((int)pDStack_1ec - (int)pDVar26);
        pDVar29 = pDVar16;
        pDStack_3c = pDVar16;
        length = (long)pDVar26;
        pDVar27 = pDVar8;
        pDStack_14c = pDVar8;
      } while (bVar3);
    }
    out = (uchar *)((uint)pDVar8 >> 0x10);
    pDStack_244 = (DES_key_schedule *)((uint)pDVar16 >> 8);
    pDStack_fc->ks[0].cblock[0] = (uchar)pDVar8;
    pDStack_fc->ks[0].cblock[4] = (char)pDVar16;
    pDStack_fc->ks[0].cblock[1] = (uchar)((uint)pDVar8 >> 8);
    pDStack_fc->ks[0].cblock[2] = (uchar)((uint)pDVar8 >> 0x10);
    pDStack_fc->ks[0].cblock[3] = (uchar)((uint)pDVar8 >> 0x18);
    pDStack_fc->ks[0].cblock[5] = (uchar)((uint)pDVar16 >> 8);
    pDStack_fc->ks[0].cblock[6] = (uchar)((uint)pDVar16 >> 0x10);
    pDStack_fc->ks[0].cblock[7] = (uchar)((uint)pDVar16 >> 0x18);
    pDVar29 = pDStack_fc;
  }
  if (iStack_d4 == *piStack_10c) {
    return;
  }
  uStack_144 = 0x5e637c;
  (*(code *)puStack_130[-0x14ca])();
  puStack_1b4 = puStack_130;
  piStack_198 = (int *)PTR___stack_chk_guard_006aabf0;
  puStack_194 = puStack_12c;
  pDStack_1c0 = (DES_key_schedule *)&_gp;
  iStack_16c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_240 = (uint *)out;
  pDVar13 = pDVar29;
  pDStack_21c = pDVar14;
  pDStack_1f8 = pDStack_168;
  pDStack_1e8 = pDStack_3c;
  pDStack_24c = (DES_key_schedule *)length;
  pDStack_248 = pDStack_150;
  pDStack_1dc = pDStack_14c;
  puStack_164 = puStack_38;
  pDStack_160 = pDStack_1f0;
  pDStack_15c = pDStack_1ec;
  pDStack_158 = pDStack_3c;
  pDStack_154 = (DES_key_schedule *)length;
  pDStack_148 = pDStack_1d8;
  if ((undefined *)((int)pDVar29[-1].ks + 0x7f) < &DAT_00000040) {
    pDStack_1e8 = (DES_key_schedule *)((int)pDVar29 >> 3);
    pDVar13 = (DES_key_schedule *)((uint)*(byte *)((int)puStack_12c + 7) << 0x18);
    pDVar8 = (DES_key_schedule *)
             ((uint)pDVar13 |
             (uint)*(byte *)((int)puStack_12c + 5) << 8 |
             (uint)*(byte *)((int)puStack_12c + 6) << 0x10 | (uint)*(byte *)(puStack_12c + 1));
    pDStack_24c = (DES_key_schedule *)((int)((int)pDVar29->ks + 7) >> 3);
    pDVar16 = (DES_key_schedule *)
              ((uint)*(byte *)((int)puStack_12c + 1) << 8 |
               (uint)*(byte *)((int)puStack_12c + 2) << 0x10 | (uint)*(byte *)puStack_12c |
              (uint)*(byte *)((int)puStack_12c + 3) << 0x18);
    if (iStack_128 == 0) {
      pDStack_1f8 = pDStack_244;
      if (pDStack_24c <= pDVar14) {
        ppcStack_19c = (code **)(&PTR_LAB_006755b4 + (int)pDStack_24c);
        pDStack_21c = (DES_key_schedule *)((int)pDVar14 - (int)pDStack_24c);
        pDVar26 = (DES_key_schedule *)&pDStack_184;
        pDVar14 = (DES_key_schedule *)((int)pDStack_24c[-1].ks + 0x7f);
        pDStack_1dc = (DES_key_schedule *)&uStack_17c;
        pDStack_248 = (DES_key_schedule *)(&PTR_LAB_006755d8 + (int)pDStack_24c);
        pDStack_1d8 = (DES_key_schedule *)(uint)(pDStack_24c < (DES_key_schedule *)&DAT_00000009);
        pDStack_1ac = (DES_key_schedule *)((uint)pDVar29 & 7);
        pDVar27 = pDVar16;
        do {
          pDVar16 = pDVar8;
          pDVar13 = (DES_key_schedule *)0x1;
          pDStack_1b0 = pDVar26;
          pDStack_1a8 = pDStack_21c;
          pDStack_1a4 = pDVar29;
          pDStack_1a0 = pDVar14;
          pDStack_184 = pDVar27;
          pDStack_180 = pDVar16;
          (*(code *)pDStack_1c0[-0xd2].ks[1].deslong[0])(pDVar26,puStack_1b4);
          if (pDStack_1d8 != (DES_key_schedule *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e666c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**ppcStack_19c)();
            return;
          }
          bVar17 = (pDStack_24c->ks[0].cblock + (int)pDStack_244->ks[0].cblock)[-1];
          pDVar8 = (DES_key_schedule *)(uint)bVar17;
          pDStack_244 = (DES_key_schedule *)
                        (pDStack_24c->ks[0].cblock + (int)pDStack_244->ks[0].cblock +
                        (int)pDStack_1a0);
          pDVar15 = pDStack_1a8;
          pDVar14 = pDStack_1a0;
          pDVar29 = pDStack_1a4;
          pDVar26 = pDStack_1b0;
          if (pDStack_1a4 != (DES_key_schedule *)&DAT_00000020) {
            if (pDStack_1a4 == (DES_key_schedule *)&DAT_00000040) {
              pDVar16 = pDVar8;
              pDVar8 = (DES_key_schedule *)0x0;
            }
            else {
              abStack_174[0] = bVar17;
              abStack_174[1] = 0;
              abStack_174[2] = 0;
              _uStack_17c = CONCAT31(CONCAT21(CONCAT11((char)pDVar27,(char)((uint)pDVar27 >> 8)),
                                              (char)((uint)pDVar27 >> 0x10)),
                                     (char)((uint)pDVar27 >> 0x18));
              uStack_178 = CONCAT31(CONCAT21(CONCAT11((char)pDVar16,(char)((uint)pDVar16 >> 8)),
                                             (char)((uint)pDVar16 >> 0x10)),
                                    (char)((uint)pDVar16 >> 0x18));
              abStack_174[3] = 0;
              abStack_174[4] = 0;
              abStack_174[5] = 0;
              abStack_174[6] = 0;
              abStack_174[7] = 0;
              if (pDStack_1ac == (DES_key_schedule *)0x0) {
                pDVar13 = (DES_key_schedule *)&DAT_00000008;
                pDStack_18c = pDStack_1b0;
                pDStack_190 = pDStack_1a0;
                pDStack_1a0 = pDStack_1a4;
                pDStack_1a4 = pDStack_1a8;
                pDStack_1b0 = (DES_key_schedule *)0x0;
                pDStack_1a8 = pDVar8;
                (**(code **)((int)pDStack_1c0[-0xa6].ks + 0x1c))
                          (pDStack_1dc,(undefined *)((int)pDStack_1e8->ks + (int)pDStack_1dc->ks));
                bVar17 = (byte)pDStack_1a8;
                pDVar15 = pDStack_1a4;
                pDVar14 = pDStack_190;
                pDVar29 = pDStack_1a0;
                pDVar26 = pDStack_18c;
              }
              else {
                pDVar13 = (DES_key_schedule *)((int)&pDStack_168 + (int)pDStack_1e8);
                uVar10 = 8 - (int)pDStack_1ac;
                _uStack_17b = (uint3)(byte)(*(char *)((int)&uStack_17c +
                                                     (int)(pDStack_1e8->ks[0].cblock + 1)) <<
                                            ((uint)pDStack_1ac & 0x1f) |
                                           (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                                      (int)(pDStack_1e8->ks[0].
                                                                            cblock + 2)) >>
                                                 (uVar10 & 0x1f))) << 0x10;
                _uStack_17c = (uint3)(((uint)(byte)(*(char *)((int)&uStack_17c + (int)pDStack_1e8)
                                                    << ((uint)pDStack_1ac & 0x1f) |
                                                   (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                                              (int)(pDStack_1e8->ks
                                                                                    [0].cblock + 1))
                                                         >> (uVar10 & 0x1f))) << 0x18) >> 8) |
                              _uStack_17b >> 8 |
                              (uint3)(byte)(*(char *)((int)&uStack_17c +
                                                     (int)(pDStack_1e8->ks[0].cblock + 2)) <<
                                            ((uint)pDStack_1ac & 0x1f) |
                                           (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                                      (int)(pDStack_1e8->ks[0].
                                                                            cblock + 3)) >>
                                                 (uVar10 & 0x1f)));
                _uStack_17c = CONCAT31(_uStack_17c,
                                       *(char *)((int)&uStack_17c +
                                                (int)(pDStack_1e8->ks[0].cblock + 3)) <<
                                       ((uint)pDStack_1ac & 0x1f) |
                                       (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                                  (int)(pDStack_1e8->ks[0].cblock +
                                                                       4)) >> (uVar10 & 0x1f)));
                uStack_178._1_3_ =
                     (uint3)(byte)(*(char *)((int)&uStack_17c + (int)(pDStack_1e8->ks[0].cblock + 5)
                                            ) << ((uint)pDStack_1ac & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                             (int)(pDStack_1e8->ks[0].cblock + 6))
                                        >> (uVar10 & 0x1f))) << 0x10;
                uStack_178._0_3_ =
                     (uint3)(((uint)(byte)(*(char *)((int)&uStack_17c +
                                                    (int)(pDStack_1e8->ks[0].cblock + 4)) <<
                                           ((uint)pDStack_1ac & 0x1f) |
                                          (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                                     (int)(pDStack_1e8->ks[0].cblock
                                                                          + 5)) >> (uVar10 & 0x1f)))
                             << 0x18) >> 8) | uStack_178._1_3_ >> 8 |
                     (uint3)(byte)(*(char *)((int)&uStack_17c + (int)(pDStack_1e8->ks[0].cblock + 6)
                                            ) << ((uint)pDStack_1ac & 0x1f) |
                                  (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                             (int)(pDStack_1e8->ks[0].cblock + 7))
                                        >> (uVar10 & 0x1f)));
                uStack_178 = CONCAT31(uStack_178._0_3_,
                                      (byte)((int)(uint)abStack_174[(int)pDStack_1e8] >>
                                            (uVar10 & 0x1f)) |
                                      *(char *)((int)&uStack_17c +
                                               (int)(pDStack_1e8->ks[0].cblock + 7)) <<
                                      ((uint)pDStack_1ac & 0x1f));
              }
              pDVar16 = (DES_key_schedule *)
                        ((((_uStack_17c >> 0x10) << 0x18 | (_uStack_17c >> 0x18) << 0x10) >> 0x10) +
                        ((_uStack_17c & 0xff) << 8 | _uStack_17c >> 8 & 0xff) * 0x10000);
              pDVar8 = (DES_key_schedule *)
                       ((((uStack_178 >> 0x10) << 0x18 | (uStack_178 >> 0x18) << 0x10) >> 0x10) +
                       ((uStack_178 & 0xff) << 8 | uStack_178 >> 8 & 0xff) * 0x10000);
            }
          }
          ((byte *)((int)out + (int)pDStack_24c))[-1] = bVar17 ^ (byte)pDStack_184;
          pDStack_21c = (DES_key_schedule *)((int)pDVar15 - (int)pDStack_24c);
          out = (byte *)((int)out + (int)pDStack_24c) + (int)pDVar14;
          pDStack_1f8 = pDStack_244;
          pDVar27 = pDVar16;
        } while (pDStack_24c <= pDVar15);
      }
    }
    else {
      pDStack_1dc = (DES_key_schedule *)(&switchD_005e64e8::switchdataD_00675590 + (int)pDStack_24c)
      ;
      pDStack_248 = (DES_key_schedule *)(&PTR_LAB_006755fc + (int)pDStack_24c);
      pDStack_21c = (DES_key_schedule *)&pDStack_184;
      pDVar26 = (DES_key_schedule *)((uint)pDVar29 & 7);
      pDVar27 = pDVar16;
      pDVar15 = pDVar8;
      while (pDVar8 = pDVar15, pDVar16 = pDVar27, pDStack_1f8 = pDStack_244, pDStack_24c <= pDVar14)
      {
        pDVar13 = (DES_key_schedule *)0x1;
        pDStack_1d8 = (DES_key_schedule *)(uint)(pDStack_24c < (DES_key_schedule *)&DAT_00000009);
        puVar25 = pDStack_24c->ks[0].cblock + (int)pDStack_244->ks[0].cblock;
        pDStack_1b0 = pDStack_21c;
        pDStack_1ac = pDVar14;
        pDStack_1a8 = pDVar26;
        pDStack_1a4 = pDVar29;
        pDStack_184 = pDVar16;
        pDStack_180 = pDVar8;
        (*(code *)pDStack_1c0[-0xd2].ks[1].deslong[0])(pDStack_21c,puStack_1b4);
        pDVar29 = pDStack_1a4;
        pDVar26 = pDStack_1a8;
        pDVar14 = (DES_key_schedule *)((int)pDStack_1ac - (int)pDStack_24c);
        if (pDStack_1d8 == (DES_key_schedule *)0x0) {
switchD_005e64e8_caseD_5e6bf4:
          uVar10 = 0;
          uVar7 = 0;
        }
        else {
          switch((uint)pDStack_1dc->ks[0].deslong[0] & 0xfffffffe) {
          case 0x5e6918:
            uVar10 = 0;
            break;
          case 0x5e6bb4:
            uVar10 = 0;
            goto LAB_005e6948;
          case 0x5e6bbc:
            uVar10 = 0;
            pDVar13 = (DES_key_schedule *)0x0;
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
            pbVar11 = puVar25 + -1;
            puVar25 = puVar25 + -1;
            uVar10 = (uint)*pbVar11 << 0x18;
          }
          pbVar11 = puVar25 + -1;
          puVar25 = puVar25 + -1;
          uVar10 = (uint)*pbVar11 << 0x10 | uVar10;
LAB_005e692c:
          pbVar11 = puVar25 + -1;
          puVar25 = puVar25 + -1;
          uVar10 = (uint)*pbVar11 << 8 | uVar10;
LAB_005e693c:
          pbVar11 = puVar25 + -1;
          puVar25 = puVar25 + -1;
          uVar10 = *pbVar11 | uVar10;
LAB_005e6948:
          pbVar11 = puVar25 + -1;
          puVar25 = puVar25 + -1;
          pDVar13 = (DES_key_schedule *)((uint)*pbVar11 << 0x18);
LAB_005e6954:
          pbVar11 = puVar25 + -1;
          puVar25 = puVar25 + -1;
          uVar7 = (uint)*pbVar11 << 0x10 | (uint)pDVar13;
LAB_005e6964:
          pbVar11 = puVar25 + -1;
          puVar25 = puVar25 + -1;
          uVar7 = (uint)*pbVar11 << 8 | uVar7;
        }
        puVar22 = (undefined *)((int)pDStack_24c[-1].ks + 0x7f);
        pDStack_244 = (DES_key_schedule *)(puVar25 + (int)puVar22);
        pDVar6 = (DES_key_schedule *)((puVar25[-1] | uVar7) ^ (uint)pDStack_184);
        pDVar9 = (DES_key_schedule *)(uVar10 ^ (uint)pDStack_180);
        if (pDStack_1d8 != (DES_key_schedule *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e69a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)pDStack_248->ks[0].deslong[0])();
          return;
        }
        ((byte *)((int)out + (int)pDStack_24c))[-1] = (byte)pDVar6;
        out = (byte *)((int)out + (int)pDStack_24c) + (int)puVar22;
        pDStack_21c = pDStack_1b0;
        pDVar27 = pDVar8;
        pDVar15 = pDVar6;
        if ((pDStack_1a4 != (DES_key_schedule *)&DAT_00000020) &&
           (pDVar13 = (DES_key_schedule *)((uint)pDVar16 >> 0x10), pDVar27 = pDVar6,
           pDVar15 = pDVar9, pDStack_1a4 != (DES_key_schedule *)&DAT_00000040)) {
          abStack_174[0] = (byte)pDVar6;
          abStack_174[1] = (char)((uint)pDVar6 >> 8);
          abStack_174[2] = (char)((uint)pDVar6 >> 0x10);
          _uStack_17c = CONCAT31(CONCAT21(CONCAT11((char)pDVar16,(char)((uint)pDVar16 >> 8)),
                                          (char)((uint)pDVar16 >> 0x10)),
                                 (char)((uint)pDVar16 >> 0x18));
          uStack_178 = CONCAT31(CONCAT21(CONCAT11((char)pDVar8,(char)((uint)pDVar8 >> 8)),
                                         (char)((uint)pDVar8 >> 0x10)),(char)((uint)pDVar8 >> 0x18))
          ;
          abStack_174[3] = (char)((uint)pDVar6 >> 0x18);
          abStack_174[4] = (char)pDVar9;
          abStack_174[5] = (char)((uint)pDVar9 >> 8);
          abStack_174[6] = (char)((uint)pDVar9 >> 0x10);
          abStack_174[7] = (char)((uint)pDVar9 >> 0x18);
          if (pDStack_1a8 == (DES_key_schedule *)0x0) {
            pDVar13 = (DES_key_schedule *)&DAT_00000008;
            pDStack_1a4 = pDStack_1b0;
            pDStack_1a8 = pDVar29;
            pDStack_1ac = pDVar26;
            pDStack_1b0 = pDVar14;
            (**(code **)((int)pDStack_1c0[-0xa6].ks + 0x1c))
                      (&uStack_17c,(int)&uStack_17c + (int)pDStack_1e8);
            pDStack_21c = pDStack_1a4;
            pDVar26 = pDStack_1ac;
            pDVar14 = pDStack_1b0;
            pDVar29 = pDStack_1a8;
          }
          else {
            uVar10 = 8 - (int)pDStack_1a8;
            _uStack_17b = (uint3)(byte)(*(char *)((int)&uStack_17c +
                                                 (int)(pDStack_1e8->ks[0].cblock + 1)) <<
                                        ((uint)pDStack_1a8 & 0x1f) |
                                       (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                                  (int)(pDStack_1e8->ks[0].cblock +
                                                                       2)) >> (uVar10 & 0x1f))) <<
                          0x10;
            _uStack_17c = (uint3)(((uint)(byte)(*(char *)((int)&uStack_17c + (int)pDStack_1e8) <<
                                                ((uint)pDStack_1a8 & 0x1f) |
                                               (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                                          (int)(pDStack_1e8->ks[0].
                                                                                cblock + 1)) >>
                                                     (uVar10 & 0x1f))) << 0x18) >> 8) |
                          _uStack_17b >> 8 |
                          (uint3)(byte)(*(char *)((int)&uStack_17c +
                                                 (int)(pDStack_1e8->ks[0].cblock + 2)) <<
                                        ((uint)pDStack_1a8 & 0x1f) |
                                       (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                                  (int)(pDStack_1e8->ks[0].cblock +
                                                                       3)) >> (uVar10 & 0x1f)));
            _uStack_17c = CONCAT31(_uStack_17c,
                                   *(char *)((int)&uStack_17c + (int)(pDStack_1e8->ks[0].cblock + 3)
                                            ) << ((uint)pDStack_1a8 & 0x1f) |
                                   (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                              (int)(pDStack_1e8->ks[0].cblock + 4))
                                         >> (uVar10 & 0x1f)));
            uStack_178._1_3_ =
                 (uint3)(byte)(*(char *)((int)&uStack_17c + (int)(pDStack_1e8->ks[0].cblock + 5)) <<
                               ((uint)pDStack_1a8 & 0x1f) |
                              (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                         (int)(pDStack_1e8->ks[0].cblock + 6)) >>
                                    (uVar10 & 0x1f))) << 0x10;
            pDVar13 = (DES_key_schedule *)
                      ((uint)*(byte *)((int)&uStack_17c + (int)(pDStack_1e8->ks[0].cblock + 6)) <<
                      ((uint)pDStack_1a8 & 0x1f));
            uStack_178._0_3_ =
                 (uint3)(((uint)(byte)(*(char *)((int)&uStack_17c +
                                                (int)(pDStack_1e8->ks[0].cblock + 4)) <<
                                       ((uint)pDStack_1a8 & 0x1f) |
                                      (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                                 (int)(pDStack_1e8->ks[0].cblock + 5
                                                                      )) >> (uVar10 & 0x1f))) <<
                         0x18) >> 8) | uStack_178._1_3_ >> 8 |
                 (uint3)(byte)((byte)pDVar13 |
                              (byte)((int)(uint)*(byte *)((int)&uStack_17c +
                                                         (int)(pDStack_1e8->ks[0].cblock + 7)) >>
                                    (uVar10 & 0x1f)));
            uStack_178 = CONCAT31(uStack_178._0_3_,
                                  (byte)((int)(uint)abStack_174[(int)pDStack_1e8] >> (uVar10 & 0x1f)
                                        ) | *(char *)((int)&uStack_17c +
                                                     (int)(pDStack_1e8->ks[0].cblock + 7)) <<
                                            ((uint)pDStack_1a8 & 0x1f));
          }
          pDVar27 = (DES_key_schedule *)
                    ((((_uStack_17c >> 0x10) << 0x18 | (_uStack_17c >> 0x18) << 0x10) >> 0x10) +
                    ((_uStack_17c & 0xff) << 8 | _uStack_17c >> 8 & 0xff) * 0x10000);
          pDVar15 = (DES_key_schedule *)
                    ((((uStack_178 >> 0x10) << 0x18 | (uStack_178 >> 0x18) << 0x10) >> 0x10) +
                    ((uStack_178 & 0xff) << 8 | uStack_178 >> 8 & 0xff) * 0x10000);
        }
      }
    }
    pDStack_244 = (DES_key_schedule *)((uint)pDVar16 >> 0x10);
    *(byte *)puStack_194 = (byte)pDVar16;
    pDStack_1f0 = (DES_key_schedule *)((uint)pDVar16 >> 0x18);
    *(byte *)(puStack_194 + 1) = (byte)pDVar8;
    *(byte *)((int)puStack_194 + 1) = (byte)((uint)pDVar16 >> 8);
    pDStack_1ec = (DES_key_schedule *)((uint)pDVar8 >> 0x18);
    *(byte *)((int)puStack_194 + 2) = (byte)((uint)pDVar16 >> 0x10);
    *(byte *)((int)puStack_194 + 3) = (byte)((uint)pDVar16 >> 0x18);
    *(byte *)((int)puStack_194 + 5) = (byte)((uint)pDVar8 >> 8);
    *(byte *)((int)puStack_194 + 6) = (byte)((uint)pDVar8 >> 0x10);
    *(byte *)((int)puStack_194 + 7) = (byte)((uint)pDVar8 >> 0x18);
    puStack_240 = puStack_194;
    puStack_38 = (uint *)out;
  }
  if (iStack_16c == *piStack_198) {
    return;
  }
  pcStack_1d4 = DES_ede3_ofb64_encrypt;
  (*(code *)pDStack_1c0[-0xa7].ks[0xb].deslong[0])();
  pDStack_258 = pDStack_1c0;
  pbVar30 = &_gp;
  piStack_214 = (int *)PTR___stack_chk_guard_006aabf0;
  pDStack_1e0 = pDStack_248;
  pDStack_1e4 = pDStack_24c;
  puStack_1f4 = puStack_38;
  pbStack_228 = &_gp;
  uVar19 = (uint)pbStack_1b8[3];
  uVar18 = (uint)pbStack_1b8[7];
  puStack_218 = puStack_1b4;
  uVar7 = uVar19 << 0x18 |
          (uint)pbStack_1b8[1] << 8 | (uint)pbStack_1b8[2] << 0x10 | (uint)*pbStack_1b8;
  uStack_260 = *puStack_1b4;
  uVar24 = uVar7 >> 8;
  iStack_1fc = *(int *)PTR___stack_chk_guard_006aabf0;
  pbVar11 = (byte *)(uVar18 << 0x18);
  uStack_20c = uVar7;
  uVar10 = (uint)pbVar11 |
           (uint)pbStack_1b8[5] << 8 | (uint)pbStack_1b8[6] << 0x10 | (uint)pbStack_1b8[4];
  uVar23 = uVar7 >> 0x10;
  uStack_208 = uVar10;
  uVar21 = uVar10 >> 8;
  abStack_204[0] = *pbStack_1b8;
  uVar20 = uVar10 >> 0x10;
  abStack_204[1] = pbStack_1b8[1];
  abStack_204[2] = pbStack_1b8[2];
  abStack_204[3] = pbStack_1b8[3];
  bStack_200 = pbStack_1b8[4];
  bStack_1ff = pbStack_1b8[5];
  bStack_1fe = pbStack_1b8[6];
  bStack_1fd = pbStack_1b8[7];
  if (pDVar13 != (DES_key_schedule *)0x0) {
    pDStack_24c = (DES_key_schedule *)0x0;
    puStack_38 = &uStack_20c;
    pDStack_248 = pDVar13;
    puVar28 = puStack_240;
    do {
      if (uStack_260 == 0) {
        pDStack_24c = (DES_key_schedule *)((int)pDStack_24c->ks + 1);
        pDVar13 = pDStack_258;
        (**(code **)(pbVar30 + -0x5764))(puStack_38,pDStack_21c,pDStack_258,uStack_1bc);
        uVar24 = uStack_20c >> 8;
        uVar23 = uStack_20c >> 0x10;
        abStack_204[0] = (byte)uStack_20c;
        uVar19 = uStack_20c >> 0x18;
        bStack_200 = (byte)uStack_208;
        uVar21 = uStack_208 >> 8;
        abStack_204[1] = (byte)(uStack_20c >> 8);
        uVar20 = uStack_208 >> 0x10;
        abStack_204[2] = (byte)(uStack_20c >> 0x10);
        uVar18 = uStack_208 >> 0x18;
        abStack_204[3] = (byte)(uStack_20c >> 0x18);
        bStack_1ff = (byte)(uStack_208 >> 8);
        bStack_1fe = (byte)(uStack_208 >> 0x10);
        bStack_1fd = (byte)(uStack_208 >> 0x18);
        uVar10 = uStack_208;
        uVar7 = uStack_20c;
        pbVar30 = pbStack_228;
      }
      puStack_240 = (uint *)((int)puVar28 + 1);
      p_Var4 = pDStack_244->ks;
      pDStack_248 = (DES_key_schedule *)((int)pDStack_248[-1].ks + 0x7f);
      pbVar1 = abStack_204 + uStack_260;
      pbVar11 = (byte *)(uint)*pbVar1;
      pDStack_244 = (DES_key_schedule *)((int)pDStack_244->ks + 1);
      uStack_260 = uStack_260 + 1 & 7;
      *(byte *)puVar28 = p_Var4->cblock[0] ^ *pbVar1;
      puVar28 = puStack_240;
    } while (pDStack_248 != (DES_key_schedule *)0x0);
    if (pDStack_24c != (DES_key_schedule *)0x0) {
      *pbStack_1b8 = (byte)uVar7;
      pbStack_1b8[1] = (byte)uVar24;
      pbStack_1b8[2] = (byte)uVar23;
      pbStack_1b8[3] = (byte)uVar19;
      pbStack_1b8[4] = (byte)uVar10;
      pbStack_1b8[5] = (byte)uVar21;
      pbStack_1b8[6] = (byte)uVar20;
      pbStack_1b8[7] = (byte)uVar18;
    }
  }
  iVar5 = *piStack_214;
  *puStack_218 = uStack_260;
  if (iStack_1fc != iVar5) {
    uStack_23c = 0x5e6f08;
    puVar28 = puStack_218;
    (**(code **)(pbVar30 + -0x5328))();
    pbVar30 = pbStack_228;
    puVar22 = PTR___stack_chk_guard_006aabf0;
    pbStack_250 = pbStack_1b8;
    uStack_254 = uStack_1bc;
    puStack_25c = puStack_38;
    uVar10 = (uint)pbStack_228[3];
    uVar7 = *puStack_224;
    uStack_274 = uVar10 << 0x18 |
                 (uint)pbStack_228[1] << 8 | (uint)pbStack_228[2] << 0x10 | (uint)*pbStack_228;
    iStack_264 = *(int *)PTR___stack_chk_guard_006aabf0;
    uStack_270 = (uint)pbStack_228[7] << 0x18 |
                 (uint)pbStack_228[5] << 8 | (uint)pbStack_228[6] << 0x10 | (uint)pbStack_228[4];
    abStack_26c[0] = *pbStack_228;
    abStack_26c[2] = pbStack_228[2];
    puVar12 = (uint *)(uStack_270 >> 8);
    abStack_26c[1] = pbStack_228[1];
    abStack_26c[3] = pbStack_228[3];
    bStack_268 = pbStack_228[4];
    bStack_267 = pbStack_228[5];
    bStack_266 = pbStack_228[6];
    bStack_265 = pbStack_228[7];
    if (pDVar13 != (DES_key_schedule *)0x0) {
      iVar5 = 0;
      pDVar29 = pDVar13;
      do {
        if (uVar7 == 0) {
          (*(code *)PTR_DES_encrypt1_006a95e8)(&uStack_274,uVar18,1);
          iVar5 = iVar5 + 1;
          pDVar13 = (DES_key_schedule *)(uStack_274 >> 0x10);
          abStack_26c[0] = (byte)uStack_274;
          puVar12 = (uint *)(uStack_270 >> 8);
          bStack_268 = (byte)uStack_270;
          abStack_26c[1] = (byte)(uStack_274 >> 8);
          abStack_26c[2] = (byte)(uStack_274 >> 0x10);
          bStack_267 = (byte)(uStack_270 >> 8);
          abStack_26c[3] = (byte)(uStack_274 >> 0x18);
          bStack_266 = (byte)(uStack_270 >> 0x10);
          bStack_265 = (byte)(uStack_270 >> 0x18);
        }
        bVar17 = *(byte *)puVar28;
        pDVar29 = (DES_key_schedule *)((int)pDVar29[-1].ks + 0x7f);
        pbVar1 = abStack_26c + uVar7;
        puVar28 = (uint *)((int)puVar28 + 1);
        uVar7 = uVar7 + 1 & 7;
        *pbVar11 = bVar17 ^ *pbVar1;
        pbVar11 = pbVar11 + 1;
      } while (pDVar29 != (DES_key_schedule *)0x0);
      if (iVar5 != 0) {
        pDVar13 = (DES_key_schedule *)(uStack_274 >> 0x10);
        *pbVar30 = (byte)uStack_274;
        puVar12 = (uint *)(uStack_270 >> 8);
        pbVar30[4] = (byte)uStack_270;
        pbVar30[1] = (byte)(uStack_274 >> 8);
        pbVar30[2] = (byte)(uStack_274 >> 0x10);
        pbVar30[5] = (byte)(uStack_270 >> 8);
        pbVar30[3] = (byte)(uStack_274 >> 0x18);
        pbVar30[6] = (byte)(uStack_270 >> 0x10);
        pbVar30[7] = (byte)(uStack_270 >> 0x18);
      }
    }
    iVar5 = *(int *)puVar22;
    *puStack_224 = uVar7;
    if (iStack_264 != iVar5) {
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      iVar5 = 0x19;
      uVar19 = 0;
      uVar18 = 0;
      uVar7 = 0;
      do {
        uVar20 = (uint)pDVar13 & (uVar18 ^ uVar19);
        uVar18 = uVar10 & (uVar18 ^ uVar19);
        uVar21 = uVar19 ^ *puVar12 ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar19 ^ puVar12[1] ^ uVar18;
        uVar18 = (uVar18 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar18 + uVar20 * 0x10000000;
        uVar7 = *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 * 0x100 >> 0x1a) + 0x140) * 4) ^ uVar7
        ;
        uVar18 = uVar7 >> 0x10 ^ uVar7;
        uVar20 = (uint)pDVar13 & uVar18;
        uVar18 = uVar10 & uVar18;
        uVar21 = uVar7 ^ puVar12[2] ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar7 ^ puVar12[3] ^ uVar18;
        uVar18 = (uVar18 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar18 + uVar20 * 0x10000000;
        uVar21 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar18 = uVar21 >> 0x10 ^ uVar21;
        uVar19 = (uint)pDVar13 & uVar18;
        uVar18 = uVar10 & uVar18;
        uVar20 = uVar21 ^ puVar12[4] ^ uVar19;
        uVar23 = uVar19 << 0x10 ^ uVar20;
        uVar19 = uVar21 ^ puVar12[5] ^ uVar18;
        uVar18 = (uVar18 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar18 + uVar19 * 0x10000000;
        uVar20 = uVar7 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar20 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar20 >> 0x10 ^ uVar20;
        uVar18 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar19 = uVar20 ^ puVar12[6] ^ uVar18;
        uVar23 = uVar18 << 0x10 ^ uVar19;
        uVar18 = uVar20 ^ puVar12[7] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar18) >> 4;
        uVar18 = uVar7 + uVar18 * 0x10000000;
        uVar19 = uVar21 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar19 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar18 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar19 >> 0x10 ^ uVar19;
        uVar18 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar19 ^ puVar12[8] ^ uVar18;
        uVar23 = uVar18 << 0x10 ^ uVar21;
        uVar18 = uVar19 ^ puVar12[9] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar18) >> 4;
        uVar18 = uVar7 + uVar18 * 0x10000000;
        uVar18 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar18 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        iVar5 = iVar5 + -1;
        uVar7 = uVar18 >> 0x10 ^ uVar18;
        uVar20 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar18 ^ puVar12[10] ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar18 ^ puVar12[0xb] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar7 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar20 ^ puVar12[0xc] ^ uVar19;
        uVar23 = uVar19 << 0x10 ^ uVar21;
        uVar19 = uVar20 ^ puVar12[0xd] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar7 + uVar19 * 0x10000000;
        uVar19 = uVar18 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar19 >> 0x10 ^ uVar19;
        uVar18 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar19 ^ puVar12[0xe] ^ uVar18;
        uVar23 = uVar18 << 0x10 ^ uVar21;
        uVar18 = uVar19 ^ puVar12[0xf] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar18) >> 4;
        uVar18 = uVar7 + uVar18 * 0x10000000;
        uVar18 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar18 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar18 >> 0x10 ^ uVar18;
        uVar20 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar18 ^ puVar12[0x10] ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar18 ^ puVar12[0x11] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar7 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar20 ^ puVar12[0x12] ^ uVar19;
        uVar23 = uVar19 << 0x10 ^ uVar21;
        uVar19 = uVar20 ^ puVar12[0x13] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar7 + uVar19 * 0x10000000;
        uVar19 = uVar18 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar19 >> 0x10 ^ uVar19;
        uVar18 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar19 ^ puVar12[0x14] ^ uVar18;
        uVar23 = uVar18 << 0x10 ^ uVar21;
        uVar18 = uVar19 ^ puVar12[0x15] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar18) >> 4;
        uVar18 = uVar7 + uVar18 * 0x10000000;
        uVar18 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar18 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar18 >> 0x10 ^ uVar18;
        uVar20 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar18 ^ puVar12[0x16] ^ uVar20;
        uVar23 = uVar20 << 0x10 ^ uVar21;
        uVar20 = uVar18 ^ puVar12[0x17] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar20) >> 4;
        uVar20 = uVar7 + uVar20 * 0x10000000;
        uVar20 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar20 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar20 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar20 >> 0x10 ^ uVar20;
        uVar19 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar20 ^ puVar12[0x18] ^ uVar19;
        uVar23 = uVar19 << 0x10 ^ uVar21;
        uVar19 = uVar20 ^ puVar12[0x19] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar19) >> 4;
        uVar19 = uVar7 + uVar19 * 0x10000000;
        uVar19 = uVar18 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar19 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar19 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar19 >> 0x10 ^ uVar19;
        uVar18 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar19 ^ puVar12[0x1a] ^ uVar18;
        uVar23 = uVar18 << 0x10 ^ uVar21;
        uVar18 = uVar19 ^ puVar12[0x1b] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar18) >> 4;
        uVar18 = uVar7 + uVar18 * 0x10000000;
        uVar20 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar18 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar7 = uVar20 >> 0x10 ^ uVar20;
        uVar18 = (uint)pDVar13 & uVar7;
        uVar7 = uVar10 & uVar7;
        uVar21 = uVar20 ^ puVar12[0x1c] ^ uVar18;
        uVar23 = uVar18 << 0x10 ^ uVar21;
        uVar18 = uVar20 ^ puVar12[0x1d] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar18) >> 4;
        uVar18 = uVar7 + uVar18 * 0x10000000;
        uVar19 = uVar19 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar23 >> 0x1a) + 0x180) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar23 & 0xfc)) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar21 << 0x10) >> 0x1a) + 0x80) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 8) >> 0x1a) + 0x100) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar18 >> 0x1a) + 0x1c0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar18 & 0xfc) + 0x100) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                 *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
        uVar18 = uVar19 >> 0x10;
        uVar21 = (uint)pDVar13 & (uVar18 ^ uVar19);
        uVar7 = uVar10 & (uVar18 ^ uVar19);
        uVar23 = uVar19 ^ puVar12[0x1e] ^ uVar21;
        uVar24 = uVar21 << 0x10 ^ uVar23;
        uVar21 = uVar19 ^ puVar12[0x1f] ^ uVar7;
        uVar7 = (uVar7 << 0x10 ^ uVar21) >> 4;
        uVar21 = uVar7 + uVar21 * 0x10000000;
        uVar7 = uVar20 ^ *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar24 >> 0x1a) + 0x180) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar24 & 0xfc)) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar23 << 0x10) >> 0x1a) + 0x80) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (((uVar24 << 8) >> 0x1a) + 0x100) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar21 >> 0x1a) + 0x1c0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + (uVar21 & 0xfc) + 0x100) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x10000 >> 0x1a) + 0xc0) * 4) ^
                *(uint *)(PTR_DES_SPtrans_006aa780 + ((uVar7 * 0x100 >> 0x1a) + 0x140) * 4);
      } while (iVar5 != 0);
      uVar7 = (uVar7 >> 3) + uVar7 * 0x20000000;
      uVar18 = (uVar19 >> 3) + uVar19 * 0x20000000;
      uVar10 = (uVar7 >> 1 ^ uVar18) & 0x55555555;
      uVar18 = uVar18 ^ uVar10;
      uVar7 = uVar10 << 1 ^ uVar7;
      uVar10 = (uVar18 >> 8 ^ uVar7) & 0xff00ff;
      uVar7 = uVar7 ^ uVar10;
      uVar18 = uVar10 << 8 ^ uVar18;
      uVar10 = (uVar7 >> 2 ^ uVar18) & 0x33333333;
      uVar18 = uVar18 ^ uVar10;
      uVar7 = uVar10 << 2 ^ uVar7;
      uVar10 = (uVar18 >> 0x10 ^ uVar7) & 0xffff;
      uVar7 = uVar7 ^ uVar10;
      uVar18 = uVar10 << 0x10 ^ uVar18;
      uVar10 = (uVar7 >> 4 ^ uVar18) & 0xf0f0f0f;
      *puStack_224 = uVar18 ^ uVar10;
      puStack_224[1] = uVar10 << 4 ^ uVar7;
      return;
    }
    return;
  }
  return;
}

