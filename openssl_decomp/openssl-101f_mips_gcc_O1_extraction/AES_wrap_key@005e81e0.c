
/* WARNING: Could not reconcile some variable overlaps */

int AES_wrap_key(AES_KEY *key,uchar *iv,uchar *out,uchar *in,uint inlen)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  undefined8 *puVar8;
  uint extraout_v1;
  uint uVar9;
  byte *pbVar10;
  AES_KEY *pAVar11;
  uint *puVar12;
  AES_KEY *pAVar13;
  AES_KEY *pAVar14;
  byte *pbVar15;
  byte *pbVar16;
  uint uVar17;
  uint in_t1;
  uint *unaff_s0;
  uint uVar18;
  uint unaff_s1;
  uint *unaff_s2;
  AES_KEY *unaff_s4;
  undefined8 *unaff_s5;
  uint *unaff_s6;
  uint *unaff_s7;
  byte *pbVar19;
  uint *puVar20;
  undefined4 *puVar21;
  undefined8 *unaff_s8;
  undefined4 uStack_23c;
  uint uStack_238;
  byte abStack_234 [4];
  undefined uStack_230;
  undefined uStack_22f;
  undefined uStack_22e;
  undefined uStack_22d;
  int iStack_22c;
  uint uStack_228;
  uint *puStack_224;
  byte *pbStack_220;
  uint *puStack_21c;
  undefined *puStack_218;
  byte *pbStack_214;
  uint *puStack_210;
  byte *pbStack_20c;
  undefined8 *puStack_208;
  code *pcStack_204;
  undefined4 *puStack_1f0;
  uint *puStack_1ec;
  uint uStack_1e4;
  uint uStack_1e0;
  int iStack_1dc;
  uint uStack_1d8;
  byte *pbStack_1d4;
  uint *puStack_1d0;
  uint *puStack_1cc;
  undefined *puStack_1c8;
  byte *pbStack_1c4;
  uint *puStack_1c0;
  byte *pbStack_1bc;
  undefined8 *puStack_1b8;
  undefined4 uStack_1b4;
  uint *puStack_1a0;
  uint *puStack_19c;
  int iStack_198;
  uint *puStack_194;
  uint uStack_18c;
  uint uStack_188;
  byte abStack_184 [4];
  byte bStack_180;
  byte bStack_17f;
  byte bStack_17e;
  byte bStack_17d;
  int iStack_17c;
  uint uStack_178;
  byte *pbStack_174;
  byte *pbStack_170;
  uint *puStack_16c;
  uint *puStack_168;
  undefined *puStack_164;
  byte *pbStack_160;
  uint *puStack_15c;
  undefined8 *puStack_158;
  code *pcStack_154;
  byte *pbStack_140;
  uint *puStack_13c;
  uint uStack_134;
  uint uStack_130;
  int iStack_12c;
  undefined8 *puStack_128;
  undefined *puStack_124;
  undefined *puStack_120;
  AES_KEY *pAStack_11c;
  AES_KEY *pAStack_118;
  undefined8 *puStack_114;
  uint *puStack_110;
  uint *puStack_10c;
  undefined8 *puStack_108;
  undefined4 uStack_104;
  byte *pbStack_f0;
  uint *puStack_ec;
  int iStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  byte *pbStack_dc;
  uint *puStack_d4;
  undefined8 *puStack_d0;
  undefined4 uStack_cc;
  undefined *puStack_b8;
  int iStack_ac;
  undefined8 *puStack_a8;
  byte **ppbStack_a4;
  uint uStack_9c;
  undefined4 uStack_98;
  uint uStack_94;
  uint uStack_90;
  byte *pbStack_8c;
  uint *puStack_88;
  uint uStack_84;
  uint *puStack_80;
  uint uStack_7c;
  AES_KEY *pAStack_78;
  undefined8 *puStack_74;
  uint *puStack_70;
  uint *puStack_6c;
  undefined8 *puStack_68;
  code *pcStack_64;
  undefined *local_50;
  uint *local_48;
  AES_KEY **local_44;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  AES_KEY *local_2c;
  
  local_44 = (AES_KEY **)PTR___stack_chk_guard_006aabf0;
  local_50 = &_gp;
  local_2c = *(AES_KEY **)PTR___stack_chk_guard_006aabf0;
  iVar6 = -1;
  pAVar13 = (AES_KEY *)out;
  if ((inlen & 7) == 0) {
    if (inlen < 8) {
      iVar6 = -1;
    }
    else {
      local_48 = (uint *)(out + 8);
      (*(code *)PTR_memcpy_006aabf4)(local_48,in,inlen);
      if (iv == (uchar *)0x0) {
        iv = (uchar *)&default_iv;
      }
      uVar17 = (uint)iv & 3;
      unaff_s8 = (undefined8 *)&local_3c;
      local_38 = *(uint *)((int)iv + 4);
      unaff_s5 = (undefined8 *)&DAT_00000006;
      unaff_s1 = 1;
      unaff_s2 = &local_34;
      uVar18 = (int)iv + 3U & 3;
      local_34 = (*(int *)((int)iv - uVar17) << uVar17 * 8 |
                 extraout_v1 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar18 + 1) * 8 |
                 *(uint *)(((int)iv + 3U) - uVar18) >> (3 - uVar18) * 8;
      local_3c = local_34;
      do {
        unaff_s7 = (uint *)0x0;
        unaff_s0 = local_48;
        do {
          uVar17 = (uint)unaff_s0 & 3;
          local_30 = unaff_s0[1];
          uVar18 = (uint)(undefined *)((int)unaff_s0 + 3) & 3;
          local_34 = (*(int *)((int)unaff_s0 - uVar17) << uVar17 * 8 |
                     local_34 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar18 + 1) * 8 |
                     *(uint *)((undefined *)((int)unaff_s0 + 3) + -uVar18) >> (3 - uVar18) * 8;
          iv = (uchar *)unaff_s8;
          pAVar13 = key;
          (**(code **)(local_50 + -0x7350))(unaff_s8);
          local_38._3_1_ = (byte)unaff_s1 ^ (byte)local_38;
          uVar17 = local_38 & 0xffffff00;
          local_38 = uVar17 | (byte)local_38;
          if (0xff < unaff_s1) {
            local_38._2_1_ = (byte)(uVar17 >> 8);
            in_t1 = (uint)local_38._2_1_;
            local_38._1_1_ = (byte)(uVar17 >> 0x10);
            pAVar13 = (AES_KEY *)(uint)local_38._1_1_;
            local_38._0_1_ = (byte)(uVar17 >> 0x18);
            iv = (uchar *)(uint)local_38._0_1_;
            local_38 = CONCAT13((byte)(unaff_s1 >> 0x18) ^ local_38._0_1_,
                                CONCAT12((byte)(unaff_s1 >> 0x10) ^ local_38._1_1_,
                                         CONCAT11((byte)(unaff_s1 >> 8) ^ local_38._2_1_,
                                                  (byte)local_38)));
          }
          unaff_s7 = unaff_s7 + 2;
          unaff_s1 = unaff_s1 + 1;
          *unaff_s0 = local_34;
          unaff_s0[1] = local_30;
          unaff_s0 = unaff_s0 + 2;
        } while (unaff_s7 < inlen);
        unaff_s5 = (undefined8 *)((int)unaff_s5 + -1);
        iVar6 = inlen + 8;
      } while (unaff_s5 != (undefined8 *)0x0);
      *(uint *)out = local_3c;
      *(uint *)(out + 4) = local_38;
      unaff_s4 = key;
      unaff_s6 = (uint *)out;
    }
  }
  if (local_2c == *local_44) {
    return iVar6;
  }
  pcStack_64 = AES_unwrap_key;
  pAVar11 = local_2c;
  (**(code **)(local_50 + -0x5328))();
  puStack_120 = local_50;
  ppbStack_a4 = (byte **)PTR___stack_chk_guard_006aabf0;
  puStack_d0 = (undefined8 *)(local_50 + -8);
  uStack_7c = inlen;
  puStack_b8 = &_gp;
  pbStack_8c = *(byte **)PTR___stack_chk_guard_006aabf0;
  puVar8 = (undefined8 *)0xffffffff;
  pAVar14 = pAVar13;
  pAStack_11c = (AES_KEY *)inlen;
  pAStack_118 = unaff_s4;
  puStack_10c = unaff_s7;
  puStack_108 = unaff_s8;
  puStack_a8 = (undefined8 *)iv;
  puStack_88 = unaff_s0;
  uStack_84 = unaff_s1;
  puStack_80 = unaff_s2;
  pAStack_78 = unaff_s4;
  puStack_74 = unaff_s5;
  puStack_70 = unaff_s6;
  puStack_6c = unaff_s7;
  puStack_68 = unaff_s8;
  if (((uint)puStack_d0 & 7) == 0) {
    if (puStack_d0 < &DAT_00000008) {
      puVar8 = (undefined8 *)0xffffffff;
    }
    else {
      uVar17 = (uint)in & 3;
      uVar18 = (uint)(uint *)((int)in + 4) & 3;
      puStack_10c = &uStack_9c;
      uVar4 = (uint)(byte *)((int)in + 3U) & 3;
      uStack_9c = (*(int *)((int)in - uVar17) << uVar17 * 8 |
                  in_t1 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar4 + 1) * 8 |
                  *(uint *)((byte *)((int)in + 3U) + -uVar4) >> (3 - uVar4) * 8;
      uVar17 = (uint)(byte *)((int)in + 7U) & 3;
      uStack_98 = (*(int *)((int)(uint *)((int)in + 4) - uVar18) << uVar18 * 8 |
                  (uint)pbStack_8c & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar17 + 1) * 8 |
                  *(uint *)((byte *)((int)in + 7U) + -uVar17) >> (3 - uVar17) * 8;
      puStack_108 = (undefined8 *)(((uint)puStack_d0 & 0xfffffff8) + ((uint)puStack_d0 >> 3) * -2);
      (*(code *)PTR_memcpy_006aabf4)(pAVar13,(uint *)((int)in + 8),puStack_d0);
      puStack_120 = puStack_120 + -0x10;
      unaff_s6 = &uStack_94;
      iStack_ac = 6;
      do {
        unaff_s5 = (undefined8 *)0x0;
        do {
          uVar4 = uStack_98;
          uVar7 = (uint)(puStack_108 < (undefined8 *)0x100);
          unaff_s0 = (uint *)((int)pAVar13 + ((int)puStack_120 - (int)unaff_s5));
          uVar9 = (uint)puStack_108 ^ uStack_98 & 0xff;
          uVar17 = uStack_98 & 0xffffff00;
          uVar18 = uVar9 & 0xff;
          uStack_98 = uVar17 | uVar18;
          if (uVar7 == 0) {
            uStack_98._2_1_ = (byte)(uVar17 >> 8);
            uVar17 = (uint)puStack_108 ^ uVar4 & 0xff0000;
            uVar9 = uVar17 >> 0x10;
            uVar4 = (uint)puStack_108 ^ uVar4;
            uVar7 = uVar4 >> 0x18;
            uStack_98._1_3_ =
                 CONCAT12((char)(uVar17 >> 0x10),
                          CONCAT11((byte)((uint)puStack_108 >> 8) ^ uStack_98._2_1_,(char)uVar18));
            uStack_98 = uVar4 & 0xff000000 | (uint)uStack_98._1_3_;
          }
          uVar17 = (uint)unaff_s0 & 3;
          uVar18 = (uint)(unaff_s0 + 1) & 3;
          unaff_s5 = unaff_s5 + 1;
          uVar4 = (uint)(undefined *)((int)unaff_s0 + 3) & 3;
          uStack_94 = (*(int *)((int)unaff_s0 - uVar17) << uVar17 * 8 |
                      uVar7 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar4 + 1) * 8 |
                      *(uint *)((undefined *)((int)unaff_s0 + 3) + -uVar4) >> (3 - uVar4) * 8;
          puStack_108 = (undefined8 *)((int)puStack_108 + -1);
          uVar17 = (uint)(undefined *)((int)unaff_s0 + 7) & 3;
          uStack_90 = (*(int *)((int)(unaff_s0 + 1) - uVar18) << uVar18 * 8 |
                      uVar9 & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar17 + 1) * 8 |
                      *(uint *)((undefined *)((int)unaff_s0 + 7) + -uVar17) >> (3 - uVar17) * 8;
          (**(code **)(puStack_b8 + -0x68e8))(puStack_10c,puStack_10c,pAVar11);
          *unaff_s0 = uStack_94;
          unaff_s0[1] = uStack_90;
        } while (unaff_s5 < puStack_d0);
        iStack_ac = iStack_ac + -1;
      } while (iStack_ac != 0);
      if (puStack_a8 == (undefined8 *)0x0) {
        unaff_s6 = (uint *)0x670000;
        puStack_a8 = &default_iv;
      }
      pAVar14 = (AES_KEY *)&DAT_00000008;
      iv = (uchar *)puStack_a8;
      iVar6 = (**(code **)(puStack_b8 + -0x5308))(puStack_10c,puStack_a8,8);
      puVar8 = puStack_d0;
      pAStack_11c = pAVar13;
      pAStack_118 = pAVar11;
      if (iVar6 != 0) {
        iv = (uchar *)puStack_d0;
        (**(code **)(puStack_b8 + -0x7d6c))(pAVar13);
        puVar8 = (undefined8 *)0x0;
      }
    }
  }
  if (pbStack_8c == *ppbStack_a4) {
    return (int)puVar8;
  }
  uStack_cc = 0x5e85ec;
  pbVar15 = pbStack_8c;
  (**(code **)(puStack_b8 + -0x5328))();
  puStack_124 = PTR___stack_chk_guard_006aabf0;
  pbStack_f0 = &_gp;
  pbStack_dc = *(byte **)PTR___stack_chk_guard_006aabf0;
  uStack_e4 = (uint)pbVar15[3] << 0x18 |
              (uint)pbVar15[1] << 8 | (uint)pbVar15[2] << 0x10 | (uint)*pbVar15;
  uStack_e0 = (uint)pbVar15[7] << 0x18 |
              (uint)pbVar15[5] << 8 | (uint)pbVar15[6] << 0x10 | (uint)pbVar15[4];
  puStack_d4 = unaff_s0;
  if ((uint *)in == (uint *)0x0) {
    (*(code *)PTR_RC2_decrypt_006aa784)(&uStack_e4);
  }
  else {
    (*(code *)PTR_RC2_encrypt_006aa788)(&uStack_e4,pAVar14);
  }
  *iv = (char)uStack_e4;
  *(char *)((int)iv + 4) = (char)uStack_e0;
  *(char *)((int)iv + 1) = (char)(uStack_e4 >> 8);
  pbVar15 = (byte *)(uStack_e0 >> 8);
  *(char *)((int)iv + 2) = (char)(uStack_e4 >> 0x10);
  puStack_1c0 = (uint *)(uStack_e0 >> 0x10);
  *(char *)((int)iv + 3) = (char)(uStack_e4 >> 0x18);
  *(char *)((int)iv + 5) = (char)(uStack_e0 >> 8);
  *(char *)((int)iv + 6) = (char)(uStack_e0 >> 0x10);
  *(char *)((int)iv + 7) = (char)(uStack_e0 >> 0x18);
  if (pbStack_dc == *(byte **)puStack_124) {
    return (int)*(byte **)puStack_124;
  }
  uStack_104 = 0x5e870c;
  pbStack_1c4 = pbStack_dc;
  (**(code **)(pbStack_f0 + -0x5328))();
  pbStack_1d4 = pbStack_f0;
  puStack_164 = PTR___stack_chk_guard_006aabf0;
  pbVar19 = &_gp;
  pbStack_140 = &_gp;
  iStack_12c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_178 = *puStack_ec;
  puStack_1d0 = (uint *)in;
  pbStack_170 = pbVar15;
  pbStack_160 = pbStack_1c4;
  puStack_15c = puStack_1c0;
  puStack_128 = (undefined8 *)iv;
  puStack_114 = unaff_s5;
  puStack_110 = unaff_s6;
  if (iStack_e8 == 0) {
    for (; puStack_1b8 = (undefined8 *)&uStack_134, pbStack_170 != (byte *)0x0;
        pbStack_170 = pbStack_170 + -1) {
      puStack_1c0 = (uint *)in;
      if (uStack_178 == 0) {
        puStack_1d0 = (uint *)((uint)pbStack_1d4[1] << 8 | (uint)pbStack_1d4[2] << 0x10);
        uStack_134 = (uint)pbStack_1d4[3] << 0x18 | (uint)puStack_1d0 | (uint)*pbStack_1d4;
        uStack_130 = (uint)pbStack_1d4[7] << 0x18 |
                     (uint)pbStack_1d4[5] << 8 | (uint)pbStack_1d4[6] << 0x10 | (uint)pbStack_1d4[4]
        ;
        (**(code **)(pbVar19 + -0x5758))(&uStack_134);
        pbVar15 = (byte *)(uStack_134 >> 0x10);
        *pbStack_1d4 = (byte)uStack_134;
        puStack_1c0 = (uint *)(uStack_130 >> 8);
        pbStack_1d4[4] = (byte)uStack_130;
        pbStack_1d4[1] = (byte)(uStack_134 >> 8);
        pbStack_1d4[2] = (byte)(uStack_134 >> 0x10);
        pbStack_1d4[5] = (byte)(uStack_130 >> 8);
        pbStack_1d4[3] = (byte)(uStack_134 >> 0x18);
        pbStack_1d4[6] = (byte)(uStack_130 >> 0x10);
        pbStack_1d4[7] = (byte)(uStack_130 >> 0x18);
        pbVar19 = pbStack_140;
      }
      bVar2 = *pbStack_160;
      bVar3 = pbStack_1d4[uStack_178];
      pbStack_1c4 = (byte *)(uint)bVar3;
      pbStack_1d4[uStack_178] = bVar2;
      pbStack_160 = pbStack_160 + 1;
      uStack_178 = uStack_178 + 1 & 7;
      *(byte *)puStack_15c = bVar2 ^ bVar3;
      puStack_15c = (uint *)((int)puStack_15c + 1);
    }
  }
  else {
    puStack_1b8 = puStack_108;
    if (pbVar15 != (byte *)0x0) {
      puStack_1b8 = (undefined8 *)&uStack_134;
      puVar20 = puStack_1c0;
      do {
        if (uStack_178 == 0) {
          puStack_1d0 = (uint *)((uint)pbStack_1d4[1] << 8 | (uint)pbStack_1d4[2] << 0x10);
          uStack_134 = (uint)pbStack_1d4[3] << 0x18 | (uint)puStack_1d0 | (uint)*pbStack_1d4;
          uStack_130 = (uint)pbStack_1d4[7] << 0x18 |
                       (uint)pbStack_1d4[5] << 8 | (uint)pbStack_1d4[6] << 0x10 |
                       (uint)pbStack_1d4[4];
          (**(code **)(pbStack_140 + -0x5758))(puStack_1b8,in);
          pbVar15 = (byte *)(uStack_134 >> 0x10);
          *pbStack_1d4 = (byte)uStack_134;
          puStack_1c0 = (uint *)(uStack_130 >> 8);
          pbStack_1d4[4] = (byte)uStack_130;
          pbStack_1d4[1] = (byte)(uStack_134 >> 8);
          pbStack_1d4[2] = (byte)(uStack_134 >> 0x10);
          pbStack_1d4[5] = (byte)(uStack_130 >> 8);
          pbStack_1d4[3] = (byte)(uStack_134 >> 0x18);
          pbStack_1d4[6] = (byte)(uStack_130 >> 0x10);
          pbStack_1d4[7] = (byte)(uStack_130 >> 0x18);
        }
        pbVar19 = pbStack_1d4 + uStack_178;
        bVar2 = *pbStack_160;
        puStack_15c = (uint *)((int)puVar20 + 1);
        bVar3 = *pbVar19;
        pbStack_1c4 = (byte *)(uint)bVar3;
        pbStack_170 = pbStack_170 + -1;
        pbStack_160 = pbStack_160 + 1;
        uStack_178 = uStack_178 + 1 & 7;
        bVar2 = bVar2 ^ bVar3;
        *(byte *)puVar20 = bVar2;
        *pbVar19 = bVar2;
        pbVar19 = pbStack_140;
        puVar20 = puStack_15c;
      } while (pbStack_170 != (byte *)0x0);
    }
  }
  iVar6 = *(int *)puStack_164;
  *puStack_ec = uStack_178;
  if (iStack_12c == iVar6) {
    return iVar6;
  }
  pcStack_154 = RC2_ofb64_encrypt;
  (**(code **)(pbVar19 + -0x5328))();
  pbStack_1bc = pbStack_140;
  puStack_1c8 = PTR___stack_chk_guard_006aabf0;
  puVar20 = (uint *)&_gp;
  puStack_168 = puStack_ec;
  puStack_158 = puStack_1b8;
  puStack_16c = (uint *)in;
  pbStack_174 = pbStack_1d4;
  puStack_1a0 = (uint *)&_gp;
  pbStack_220 = (byte *)(uint)pbStack_140[3];
  puStack_194 = puStack_13c;
  uStack_1d8 = *puStack_13c;
  iStack_17c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_18c = (int)pbStack_220 << 0x18 |
               (uint)pbStack_140[1] << 8 | (uint)pbStack_140[2] << 0x10 | (uint)*pbStack_140;
  uStack_188 = (uint)pbStack_140[7] << 0x18 |
               (uint)pbStack_140[5] << 8 | (uint)pbStack_140[6] << 0x10 | (uint)pbStack_140[4];
  abStack_184[0] = *pbStack_140;
  abStack_184[2] = pbStack_140[2];
  pbVar19 = (byte *)(uStack_188 >> 8);
  abStack_184[1] = pbStack_140[1];
  abStack_184[3] = pbStack_140[3];
  bStack_180 = pbStack_140[4];
  bStack_17f = pbStack_140[5];
  bStack_17e = pbStack_140[6];
  bStack_17d = pbStack_140[7];
  if (pbVar15 != (byte *)0x0) {
    puStack_1b8 = (undefined8 *)0x0;
    in = (uchar *)&uStack_18c;
    pbStack_1d4 = pbVar15;
    puVar12 = puStack_1c0;
    do {
      if (uStack_1d8 == 0) {
        puStack_1b8 = (undefined8 *)((int)puStack_1b8 + 1);
        (**(code **)((int)puVar20 + -0x5758))(in,puStack_1d0);
        pbVar15 = (byte *)(uStack_18c >> 0x10);
        abStack_184[0] = (byte)uStack_18c;
        pbVar19 = (byte *)(uStack_188 >> 8);
        bStack_180 = (byte)uStack_188;
        abStack_184[1] = (byte)(uStack_18c >> 8);
        abStack_184[2] = (byte)(uStack_18c >> 0x10);
        bStack_17f = (byte)(uStack_188 >> 8);
        abStack_184[3] = (byte)(uStack_18c >> 0x18);
        bStack_17e = (byte)(uStack_188 >> 0x10);
        bStack_17d = (byte)(uStack_188 >> 0x18);
        puVar20 = puStack_1a0;
      }
      puStack_1c0 = (uint *)((int)puVar12 + 1);
      bVar2 = *pbStack_1c4;
      pbStack_1d4 = pbStack_1d4 + -1;
      pbVar16 = abStack_184 + uStack_1d8;
      pbStack_1c4 = pbStack_1c4 + 1;
      uStack_1d8 = uStack_1d8 + 1 & 7;
      *(byte *)puVar12 = bVar2 ^ *pbVar16;
      puVar12 = puStack_1c0;
    } while (pbStack_1d4 != (byte *)0x0);
    if (puStack_1b8 != (undefined8 *)0x0) {
      pbVar15 = (byte *)(uStack_18c >> 0x10);
      *pbStack_1bc = (byte)uStack_18c;
      pbVar19 = (byte *)(uStack_188 >> 8);
      pbStack_1bc[4] = (byte)uStack_188;
      pbStack_1bc[1] = (byte)(uStack_18c >> 8);
      pbStack_1bc[2] = (byte)(uStack_18c >> 0x10);
      pbStack_1bc[5] = (byte)(uStack_188 >> 8);
      pbStack_1bc[3] = (byte)(uStack_18c >> 0x18);
      pbStack_1bc[6] = (byte)(uStack_188 >> 0x10);
      pbStack_1bc[7] = (byte)(uStack_188 >> 0x18);
    }
  }
  iVar6 = *(int *)puStack_1c8;
  *puStack_194 = uStack_1d8;
  if (iStack_17c == iVar6) {
    return iVar6;
  }
  uStack_1b4 = 0x5e8bd8;
  puVar12 = puStack_194;
  (**(code **)((int)puVar20 + -0x5328))();
  puStack_224 = puStack_1a0;
  puStack_218 = PTR___stack_chk_guard_006aabf0;
  puVar21 = (undefined4 *)&_gp;
  puStack_1f0 = (undefined4 *)&_gp;
  iStack_1dc = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_228 = *puStack_19c;
  pbVar16 = pbStack_220;
  pbStack_214 = pbVar15;
  puStack_210 = puVar12;
  pbStack_20c = pbVar19;
  puStack_1cc = (uint *)in;
  if (iStack_198 == 0) {
    for (; puStack_208 = (undefined8 *)&uStack_1e4, pbStack_214 != (byte *)0x0;
        pbStack_214 = pbStack_214 + -1) {
      pbVar19 = pbStack_220;
      if (uStack_228 == 0) {
        uStack_1e4 = *puStack_224;
        uStack_1e0 = puStack_224[1];
        (**(code **)((int)puVar21 + -0x68d8))(&uStack_1e4);
        pbVar15 = (byte *)(uStack_1e4 >> 0x10);
        *(char *)((int)puStack_224 + 3) = (char)uStack_1e4;
        pbVar19 = (byte *)(uStack_1e0 >> 0x18);
        *(char *)((int)puStack_224 + 7) = (char)uStack_1e0;
        *(char *)puStack_224 = (char)(uStack_1e4 >> 0x18);
        *(char *)((int)puStack_224 + 1) = (char)(uStack_1e4 >> 0x10);
        *(char *)(puStack_224 + 1) = (char)(uStack_1e0 >> 0x18);
        *(char *)((int)puStack_224 + 2) = (char)(uStack_1e4 >> 8);
        *(char *)((int)puStack_224 + 5) = (char)(uStack_1e0 >> 0x10);
        *(char *)((int)puStack_224 + 6) = (char)(uStack_1e0 >> 8);
        puVar21 = puStack_1f0;
      }
      bVar2 = *(byte *)puStack_210;
      bVar3 = *(byte *)((int)puStack_224 + uStack_228);
      puVar12 = (uint *)(uint)bVar3;
      *(byte *)((int)puStack_224 + uStack_228) = bVar2;
      puStack_210 = (uint *)((int)puStack_210 + 1);
      uStack_228 = uStack_228 + 1 & 7;
      *pbStack_20c = bVar2 ^ bVar3;
      pbStack_20c = pbStack_20c + 1;
    }
  }
  else {
    puStack_208 = puStack_1b8;
    if (pbVar15 != (byte *)0x0) {
      puStack_208 = (undefined8 *)&uStack_1e4;
      pbVar1 = pbVar19;
      do {
        if (uStack_228 == 0) {
          uStack_1e4 = *puStack_224;
          uStack_1e0 = puStack_224[1];
          (*(code *)puStack_1f0[-0x1a36])(puStack_208,pbStack_220);
          pbVar15 = (byte *)(uStack_1e4 >> 0x10);
          *(char *)((int)puStack_224 + 3) = (char)uStack_1e4;
          pbVar19 = (byte *)(uStack_1e0 >> 0x18);
          *(char *)((int)puStack_224 + 7) = (char)uStack_1e0;
          *(char *)puStack_224 = (char)(uStack_1e4 >> 0x18);
          *(char *)((int)puStack_224 + 1) = (char)(uStack_1e4 >> 0x10);
          *(char *)(puStack_224 + 1) = (char)(uStack_1e0 >> 0x18);
          *(char *)((int)puStack_224 + 2) = (char)(uStack_1e4 >> 8);
          *(char *)((int)puStack_224 + 5) = (char)(uStack_1e0 >> 0x10);
          *(char *)((int)puStack_224 + 6) = (char)(uStack_1e0 >> 8);
        }
        pbVar10 = (byte *)((int)puStack_224 + uStack_228);
        bVar2 = *(byte *)puStack_210;
        pbStack_20c = pbVar1 + 1;
        bVar3 = *pbVar10;
        puVar12 = (uint *)(uint)bVar3;
        pbStack_214 = pbStack_214 + -1;
        puStack_210 = (uint *)((int)puStack_210 + 1);
        uStack_228 = uStack_228 + 1 & 7;
        bVar2 = bVar2 ^ bVar3;
        *pbVar1 = bVar2;
        *pbVar10 = bVar2;
        puVar21 = puStack_1f0;
        pbVar1 = pbStack_20c;
      } while (pbStack_214 != (byte *)0x0);
    }
  }
  iVar6 = *(int *)puStack_218;
  *puStack_19c = uStack_228;
  if (iStack_1dc == iVar6) {
    return iVar6;
  }
  pcStack_204 = idea_ofb64_encrypt;
  (*(code *)puVar21[-0x14ca])();
  puVar21 = puStack_1f0;
  puVar5 = PTR___stack_chk_guard_006aabf0;
  puStack_21c = puStack_19c;
  uStack_23c = *puStack_1f0;
  uStack_238 = puStack_1f0[1];
  uVar18 = *puStack_1ec;
  iStack_22c = *(int *)PTR___stack_chk_guard_006aabf0;
  abStack_234[3] = (char)uStack_23c;
  abStack_234[0] = (byte)((uint)uStack_23c >> 0x18);
  uVar17 = uStack_238 >> 0x18;
  abStack_234[1] = (char)((uint)uStack_23c >> 0x10);
  abStack_234[2] = (char)((uint)uStack_23c >> 8);
  uStack_230 = (char)(uStack_238 >> 0x18);
  uStack_22f = (char)(uStack_238 >> 0x10);
  uStack_22e = (char)(uStack_238 >> 8);
  uStack_22d = (char)uStack_238;
  if (pbVar15 != (byte *)0x0) {
    iVar6 = 0;
    do {
      if (uVar18 == 0) {
        iVar6 = iVar6 + 1;
        (*(code *)PTR_idea_encrypt_006a9608)(&uStack_23c,pbVar16);
        abStack_234[3] = (char)uStack_23c;
        uStack_22d = (char)uStack_238;
        abStack_234[0] = (byte)((uint)uStack_23c >> 0x18);
        abStack_234[1] = (char)((uint)uStack_23c >> 0x10);
        uStack_230 = (char)(uStack_238 >> 0x18);
        abStack_234[2] = (char)((uint)uStack_23c >> 8);
        uStack_22f = (char)(uStack_238 >> 0x10);
        uStack_22e = (char)(uStack_238 >> 8);
      }
      bVar2 = *(byte *)puVar12;
      pbVar15 = pbVar15 + -1;
      pbVar1 = abStack_234 + uVar18;
      puVar12 = (uint *)((int)puVar12 + 1);
      uVar18 = uVar18 + 1 & 7;
      *pbVar19 = bVar2 ^ *pbVar1;
      pbVar19 = pbVar19 + 1;
    } while (pbVar15 != (byte *)0x0);
    if (iVar6 != 0) {
      *(char *)((int)puVar21 + 3) = (char)uStack_23c;
      *(char *)((int)puVar21 + 7) = (char)uStack_238;
      *(char *)puVar21 = (char)((uint)uStack_23c >> 0x18);
      *(char *)((int)puVar21 + 1) = (char)((uint)uStack_23c >> 0x10);
      *(char *)(puVar21 + 1) = (char)(uStack_238 >> 0x18);
      *(char *)((int)puVar21 + 2) = (char)((uint)uStack_23c >> 8);
      *(char *)((int)puVar21 + 5) = (char)(uStack_238 >> 0x10);
      *(char *)((int)puVar21 + 6) = (char)(uStack_238 >> 8);
    }
  }
  iVar6 = *(int *)puVar5;
  *puStack_1ec = uVar18;
  if (iStack_22c == iVar6) {
    return iVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (uVar17 != 1) {
                    /* WARNING: Could not recover jumptable at 0x005e9004. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar6 = (*(code *)PTR_Camellia_decrypt_006a9634)();
    return iVar6;
  }
                    /* WARNING: Could not recover jumptable at 0x005e9010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar6 = (*(code *)PTR_Camellia_encrypt_006a9638)();
  return iVar6;
}

