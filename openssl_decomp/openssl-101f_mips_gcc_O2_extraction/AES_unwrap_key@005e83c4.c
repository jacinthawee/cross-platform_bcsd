
/* WARNING: Could not reconcile some variable overlaps */

int AES_unwrap_key(AES_KEY *key,uchar *iv,uchar *out,uchar *in,uint inlen)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  undefined8 *puVar8;
  uint uVar9;
  byte *pbVar10;
  uint *puVar11;
  uchar *puVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint uVar15;
  uint in_t1;
  uint *unaff_s0;
  uint uVar16;
  uchar *unaff_s3;
  AES_KEY *unaff_s4;
  undefined8 *unaff_s5;
  uint *unaff_s6;
  uint *unaff_s7;
  byte *pbVar17;
  uint *puVar18;
  undefined4 *puVar19;
  uint *unaff_s8;
  undefined4 uStack_1dc;
  uint uStack_1d8;
  byte abStack_1d4 [4];
  undefined uStack_1d0;
  undefined uStack_1cf;
  undefined uStack_1ce;
  undefined uStack_1cd;
  int iStack_1cc;
  uint uStack_1c8;
  uint *puStack_1c4;
  byte *pbStack_1c0;
  uint *puStack_1bc;
  undefined *puStack_1b8;
  byte *pbStack_1b4;
  uint *puStack_1b0;
  byte *pbStack_1ac;
  uint *puStack_1a8;
  code *pcStack_1a4;
  undefined4 *puStack_190;
  uint *puStack_18c;
  uint uStack_184;
  uint uStack_180;
  int iStack_17c;
  uint uStack_178;
  byte *pbStack_174;
  uint *puStack_170;
  uint *puStack_16c;
  undefined *puStack_168;
  byte *pbStack_164;
  uint *puStack_160;
  byte *pbStack_15c;
  uint *puStack_158;
  undefined4 uStack_154;
  uint *puStack_140;
  uint *puStack_13c;
  int iStack_138;
  uint *puStack_134;
  uint uStack_12c;
  uint uStack_128;
  byte abStack_124 [4];
  byte bStack_120;
  byte bStack_11f;
  byte bStack_11e;
  byte bStack_11d;
  int iStack_11c;
  uint uStack_118;
  byte *pbStack_114;
  byte *pbStack_110;
  uint *puStack_10c;
  uint *puStack_108;
  undefined *puStack_104;
  byte *pbStack_100;
  uint *puStack_fc;
  uint *puStack_f8;
  code *pcStack_f4;
  byte *pbStack_e0;
  uint *puStack_dc;
  uint uStack_d4;
  uint uStack_d0;
  int iStack_cc;
  undefined8 *puStack_c8;
  undefined *puStack_c4;
  uint uStack_c0;
  uchar *puStack_bc;
  AES_KEY *pAStack_b8;
  undefined8 *puStack_b4;
  uint *puStack_b0;
  uint *puStack_ac;
  uint *puStack_a8;
  undefined4 uStack_a4;
  byte *pbStack_90;
  uint *puStack_8c;
  int iStack_88;
  uint uStack_84;
  uint uStack_80;
  byte *pbStack_7c;
  uint *puStack_74;
  undefined8 *puStack_70;
  undefined4 uStack_6c;
  undefined *local_58;
  int local_4c;
  undefined8 *local_48;
  byte **local_44;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  byte *local_2c;
  
  local_44 = (byte **)PTR___stack_chk_guard_006aabf0;
  puStack_70 = (undefined8 *)(inlen - 8);
  local_58 = &_gp;
  local_2c = *(byte **)PTR___stack_chk_guard_006aabf0;
  puVar8 = (undefined8 *)0xffffffff;
  puVar12 = out;
  puStack_bc = unaff_s3;
  pAStack_b8 = unaff_s4;
  local_48 = (undefined8 *)iv;
  if (((uint)puStack_70 & 7) == 0) {
    if (puStack_70 < &DAT_00000008) {
      puVar8 = (undefined8 *)0xffffffff;
    }
    else {
      uVar15 = (uint)in & 3;
      uVar16 = (uint)(in + 4) & 3;
      unaff_s7 = &local_3c;
      uVar4 = (uint)(in + 3) & 3;
      local_3c = (*(int *)(in + -uVar15) << uVar15 * 8 | in_t1 & 0xffffffffU >> (4 - uVar15) * 8) &
                 -1 << (uVar4 + 1) * 8 | *(uint *)(in + 3 + -uVar4) >> (3 - uVar4) * 8;
      uVar15 = (uint)(in + 7) & 3;
      local_38 = (*(int *)(in + 4 + -uVar16) << uVar16 * 8 |
                 (uint)local_2c & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar15 + 1) * 8 |
                 *(uint *)(in + 7 + -uVar15) >> (3 - uVar15) * 8;
      unaff_s8 = (uint *)(((uint)puStack_70 & 0xfffffff8) + ((uint)puStack_70 >> 3) * -2);
      (*(code *)PTR_memcpy_006aabf4)(out,in + 8,puStack_70);
      inlen = inlen - 0x10;
      unaff_s6 = &local_34;
      local_4c = 6;
      do {
        unaff_s5 = (undefined8 *)0x0;
        do {
          uVar4 = local_38;
          uVar6 = (uint)(unaff_s8 < (uint *)0x100);
          unaff_s0 = (uint *)(out + (inlen - (int)unaff_s5));
          uVar9 = (uint)unaff_s8 ^ local_38 & 0xff;
          uVar15 = local_38 & 0xffffff00;
          uVar16 = uVar9 & 0xff;
          local_38 = uVar15 | uVar16;
          if (uVar6 == 0) {
            local_38._2_1_ = (byte)(uVar15 >> 8);
            uVar15 = (uint)unaff_s8 ^ uVar4 & 0xff0000;
            uVar9 = uVar15 >> 0x10;
            uVar4 = (uint)unaff_s8 ^ uVar4;
            uVar6 = uVar4 >> 0x18;
            local_38._1_3_ =
                 CONCAT12((char)(uVar15 >> 0x10),
                          CONCAT11((byte)((uint)unaff_s8 >> 8) ^ local_38._2_1_,(char)uVar16));
            local_38 = uVar4 & 0xff000000 | (uint)local_38._1_3_;
          }
          uVar15 = (uint)unaff_s0 & 3;
          uVar16 = (uint)(unaff_s0 + 1) & 3;
          unaff_s5 = unaff_s5 + 1;
          uVar4 = (int)unaff_s0 + 3U & 3;
          local_34 = (*(int *)((int)unaff_s0 - uVar15) << uVar15 * 8 |
                     uVar6 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar4 + 1) * 8 |
                     *(uint *)(((int)unaff_s0 + 3U) - uVar4) >> (3 - uVar4) * 8;
          unaff_s8 = (uint *)((int)unaff_s8 + -1);
          uVar15 = (int)unaff_s0 + 7U & 3;
          local_30 = (*(int *)((int)(unaff_s0 + 1) - uVar16) << uVar16 * 8 |
                     uVar9 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar15 + 1) * 8 |
                     *(uint *)(((int)unaff_s0 + 7U) - uVar15) >> (3 - uVar15) * 8;
          (**(code **)(local_58 + -0x68e8))(unaff_s7,unaff_s7,key);
          *unaff_s0 = local_34;
          unaff_s0[1] = local_30;
        } while (unaff_s5 < puStack_70);
        local_4c = local_4c + -1;
      } while (local_4c != 0);
      if (local_48 == (undefined8 *)0x0) {
        unaff_s6 = (uint *)0x670000;
        local_48 = &default_iv;
      }
      puVar12 = &DAT_00000008;
      iv = (uchar *)local_48;
      iVar7 = (**(code **)(local_58 + -0x5308))(unaff_s7,local_48,8);
      puVar8 = puStack_70;
      puStack_bc = out;
      pAStack_b8 = key;
      if (iVar7 != 0) {
        iv = (uchar *)puStack_70;
        (**(code **)(local_58 + -0x7d6c))(out);
        puVar8 = (undefined8 *)0x0;
      }
    }
  }
  if (local_2c == *local_44) {
    return (int)puVar8;
  }
  uStack_6c = 0x5e85ec;
  pbVar13 = local_2c;
  (**(code **)(local_58 + -0x5328))();
  puStack_c4 = PTR___stack_chk_guard_006aabf0;
  pbStack_90 = &_gp;
  pbStack_7c = *(byte **)PTR___stack_chk_guard_006aabf0;
  uStack_84 = (uint)pbVar13[3] << 0x18 |
              (uint)pbVar13[1] << 8 | (uint)pbVar13[2] << 0x10 | (uint)*pbVar13;
  uStack_80 = (uint)pbVar13[7] << 0x18 |
              (uint)pbVar13[5] << 8 | (uint)pbVar13[6] << 0x10 | (uint)pbVar13[4];
  puStack_74 = unaff_s0;
  if ((uint *)in == (uint *)0x0) {
    (*(code *)PTR_RC2_decrypt_006aa784)(&uStack_84);
  }
  else {
    (*(code *)PTR_RC2_encrypt_006aa788)(&uStack_84,puVar12);
  }
  *iv = (char)uStack_84;
  *(char *)((int)iv + 4) = (char)uStack_80;
  *(char *)((int)iv + 1) = (char)(uStack_84 >> 8);
  pbVar13 = (byte *)(uStack_80 >> 8);
  *(char *)((int)iv + 2) = (char)(uStack_84 >> 0x10);
  puStack_160 = (uint *)(uStack_80 >> 0x10);
  *(char *)((int)iv + 3) = (char)(uStack_84 >> 0x18);
  *(char *)((int)iv + 5) = (char)(uStack_80 >> 8);
  *(char *)((int)iv + 6) = (char)(uStack_80 >> 0x10);
  *(char *)((int)iv + 7) = (char)(uStack_80 >> 0x18);
  if (pbStack_7c == *(byte **)puStack_c4) {
    return (int)*(byte **)puStack_c4;
  }
  uStack_a4 = 0x5e870c;
  pbStack_164 = pbStack_7c;
  (**(code **)(pbStack_90 + -0x5328))();
  pbStack_174 = pbStack_90;
  puStack_104 = PTR___stack_chk_guard_006aabf0;
  pbVar17 = &_gp;
  pbStack_e0 = &_gp;
  iStack_cc = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_118 = *puStack_8c;
  puStack_170 = (uint *)in;
  pbStack_110 = pbVar13;
  pbStack_100 = pbStack_164;
  puStack_fc = puStack_160;
  puStack_c8 = (undefined8 *)iv;
  uStack_c0 = inlen;
  puStack_b4 = unaff_s5;
  puStack_b0 = unaff_s6;
  puStack_ac = unaff_s7;
  puStack_a8 = unaff_s8;
  if (iStack_88 == 0) {
    for (; puStack_158 = &uStack_d4, pbStack_110 != (byte *)0x0; pbStack_110 = pbStack_110 + -1) {
      puStack_160 = (uint *)in;
      if (uStack_118 == 0) {
        puStack_170 = (uint *)((uint)pbStack_174[1] << 8 | (uint)pbStack_174[2] << 0x10);
        uStack_d4 = (uint)pbStack_174[3] << 0x18 | (uint)puStack_170 | (uint)*pbStack_174;
        uStack_d0 = (uint)pbStack_174[7] << 0x18 |
                    (uint)pbStack_174[5] << 8 | (uint)pbStack_174[6] << 0x10 | (uint)pbStack_174[4];
        (**(code **)(pbVar17 + -0x5758))(&uStack_d4);
        pbVar13 = (byte *)(uStack_d4 >> 0x10);
        *pbStack_174 = (byte)uStack_d4;
        puStack_160 = (uint *)(uStack_d0 >> 8);
        pbStack_174[4] = (byte)uStack_d0;
        pbStack_174[1] = (byte)(uStack_d4 >> 8);
        pbStack_174[2] = (byte)(uStack_d4 >> 0x10);
        pbStack_174[5] = (byte)(uStack_d0 >> 8);
        pbStack_174[3] = (byte)(uStack_d4 >> 0x18);
        pbStack_174[6] = (byte)(uStack_d0 >> 0x10);
        pbStack_174[7] = (byte)(uStack_d0 >> 0x18);
        pbVar17 = pbStack_e0;
      }
      bVar2 = *pbStack_100;
      bVar3 = pbStack_174[uStack_118];
      pbStack_164 = (byte *)(uint)bVar3;
      pbStack_174[uStack_118] = bVar2;
      pbStack_100 = pbStack_100 + 1;
      uStack_118 = uStack_118 + 1 & 7;
      *(byte *)puStack_fc = bVar2 ^ bVar3;
      puStack_fc = (uint *)((int)puStack_fc + 1);
    }
  }
  else {
    puStack_158 = unaff_s8;
    if (pbVar13 != (byte *)0x0) {
      puStack_158 = &uStack_d4;
      puVar18 = puStack_160;
      do {
        if (uStack_118 == 0) {
          puStack_170 = (uint *)((uint)pbStack_174[1] << 8 | (uint)pbStack_174[2] << 0x10);
          uStack_d4 = (uint)pbStack_174[3] << 0x18 | (uint)puStack_170 | (uint)*pbStack_174;
          uStack_d0 = (uint)pbStack_174[7] << 0x18 |
                      (uint)pbStack_174[5] << 8 | (uint)pbStack_174[6] << 0x10 |
                      (uint)pbStack_174[4];
          (**(code **)(pbStack_e0 + -0x5758))(puStack_158,in);
          pbVar13 = (byte *)(uStack_d4 >> 0x10);
          *pbStack_174 = (byte)uStack_d4;
          puStack_160 = (uint *)(uStack_d0 >> 8);
          pbStack_174[4] = (byte)uStack_d0;
          pbStack_174[1] = (byte)(uStack_d4 >> 8);
          pbStack_174[2] = (byte)(uStack_d4 >> 0x10);
          pbStack_174[5] = (byte)(uStack_d0 >> 8);
          pbStack_174[3] = (byte)(uStack_d4 >> 0x18);
          pbStack_174[6] = (byte)(uStack_d0 >> 0x10);
          pbStack_174[7] = (byte)(uStack_d0 >> 0x18);
        }
        pbVar17 = pbStack_174 + uStack_118;
        bVar2 = *pbStack_100;
        puStack_fc = (uint *)((int)puVar18 + 1);
        bVar3 = *pbVar17;
        pbStack_164 = (byte *)(uint)bVar3;
        pbStack_110 = pbStack_110 + -1;
        pbStack_100 = pbStack_100 + 1;
        uStack_118 = uStack_118 + 1 & 7;
        bVar2 = bVar2 ^ bVar3;
        *(byte *)puVar18 = bVar2;
        *pbVar17 = bVar2;
        pbVar17 = pbStack_e0;
        puVar18 = puStack_fc;
      } while (pbStack_110 != (byte *)0x0);
    }
  }
  iVar7 = *(int *)puStack_104;
  *puStack_8c = uStack_118;
  if (iStack_cc == iVar7) {
    return iVar7;
  }
  pcStack_f4 = RC2_ofb64_encrypt;
  (**(code **)(pbVar17 + -0x5328))();
  pbStack_15c = pbStack_e0;
  puStack_168 = PTR___stack_chk_guard_006aabf0;
  puVar18 = (uint *)&_gp;
  puStack_108 = puStack_8c;
  puStack_f8 = puStack_158;
  puStack_10c = (uint *)in;
  pbStack_114 = pbStack_174;
  puStack_140 = (uint *)&_gp;
  pbStack_1c0 = (byte *)(uint)pbStack_e0[3];
  puStack_134 = puStack_dc;
  uStack_178 = *puStack_dc;
  iStack_11c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_12c = (int)pbStack_1c0 << 0x18 |
               (uint)pbStack_e0[1] << 8 | (uint)pbStack_e0[2] << 0x10 | (uint)*pbStack_e0;
  uStack_128 = (uint)pbStack_e0[7] << 0x18 |
               (uint)pbStack_e0[5] << 8 | (uint)pbStack_e0[6] << 0x10 | (uint)pbStack_e0[4];
  abStack_124[0] = *pbStack_e0;
  abStack_124[2] = pbStack_e0[2];
  pbVar17 = (byte *)(uStack_128 >> 8);
  abStack_124[1] = pbStack_e0[1];
  abStack_124[3] = pbStack_e0[3];
  bStack_120 = pbStack_e0[4];
  bStack_11f = pbStack_e0[5];
  bStack_11e = pbStack_e0[6];
  bStack_11d = pbStack_e0[7];
  if (pbVar13 != (byte *)0x0) {
    puStack_158 = (uint *)0x0;
    in = (uchar *)&uStack_12c;
    pbStack_174 = pbVar13;
    puVar11 = puStack_160;
    do {
      if (uStack_178 == 0) {
        puStack_158 = (uint *)((int)puStack_158 + 1);
        (**(code **)((int)puVar18 + -0x5758))(in,puStack_170);
        pbVar13 = (byte *)(uStack_12c >> 0x10);
        abStack_124[0] = (byte)uStack_12c;
        pbVar17 = (byte *)(uStack_128 >> 8);
        bStack_120 = (byte)uStack_128;
        abStack_124[1] = (byte)(uStack_12c >> 8);
        abStack_124[2] = (byte)(uStack_12c >> 0x10);
        bStack_11f = (byte)(uStack_128 >> 8);
        abStack_124[3] = (byte)(uStack_12c >> 0x18);
        bStack_11e = (byte)(uStack_128 >> 0x10);
        bStack_11d = (byte)(uStack_128 >> 0x18);
        puVar18 = puStack_140;
      }
      puStack_160 = (uint *)((int)puVar11 + 1);
      bVar2 = *pbStack_164;
      pbStack_174 = pbStack_174 + -1;
      pbVar14 = abStack_124 + uStack_178;
      pbStack_164 = pbStack_164 + 1;
      uStack_178 = uStack_178 + 1 & 7;
      *(byte *)puVar11 = bVar2 ^ *pbVar14;
      puVar11 = puStack_160;
    } while (pbStack_174 != (byte *)0x0);
    if (puStack_158 != (uint *)0x0) {
      pbVar13 = (byte *)(uStack_12c >> 0x10);
      *pbStack_15c = (byte)uStack_12c;
      pbVar17 = (byte *)(uStack_128 >> 8);
      pbStack_15c[4] = (byte)uStack_128;
      pbStack_15c[1] = (byte)(uStack_12c >> 8);
      pbStack_15c[2] = (byte)(uStack_12c >> 0x10);
      pbStack_15c[5] = (byte)(uStack_128 >> 8);
      pbStack_15c[3] = (byte)(uStack_12c >> 0x18);
      pbStack_15c[6] = (byte)(uStack_128 >> 0x10);
      pbStack_15c[7] = (byte)(uStack_128 >> 0x18);
    }
  }
  iVar7 = *(int *)puStack_168;
  *puStack_134 = uStack_178;
  if (iStack_11c == iVar7) {
    return iVar7;
  }
  uStack_154 = 0x5e8bd8;
  puVar11 = puStack_134;
  (**(code **)((int)puVar18 + -0x5328))();
  puStack_1c4 = puStack_140;
  puStack_1b8 = PTR___stack_chk_guard_006aabf0;
  puVar19 = (undefined4 *)&_gp;
  puStack_190 = (undefined4 *)&_gp;
  iStack_17c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_1c8 = *puStack_13c;
  pbVar14 = pbStack_1c0;
  pbStack_1b4 = pbVar13;
  puStack_1b0 = puVar11;
  pbStack_1ac = pbVar17;
  puStack_16c = (uint *)in;
  if (iStack_138 == 0) {
    for (; puStack_1a8 = &uStack_184, pbStack_1b4 != (byte *)0x0; pbStack_1b4 = pbStack_1b4 + -1) {
      pbVar17 = pbStack_1c0;
      if (uStack_1c8 == 0) {
        uStack_184 = *puStack_1c4;
        uStack_180 = puStack_1c4[1];
        (**(code **)((int)puVar19 + -0x68d8))(&uStack_184);
        pbVar13 = (byte *)(uStack_184 >> 0x10);
        *(char *)((int)puStack_1c4 + 3) = (char)uStack_184;
        pbVar17 = (byte *)(uStack_180 >> 0x18);
        *(char *)((int)puStack_1c4 + 7) = (char)uStack_180;
        *(char *)puStack_1c4 = (char)(uStack_184 >> 0x18);
        *(char *)((int)puStack_1c4 + 1) = (char)(uStack_184 >> 0x10);
        *(char *)(puStack_1c4 + 1) = (char)(uStack_180 >> 0x18);
        *(char *)((int)puStack_1c4 + 2) = (char)(uStack_184 >> 8);
        *(char *)((int)puStack_1c4 + 5) = (char)(uStack_180 >> 0x10);
        *(char *)((int)puStack_1c4 + 6) = (char)(uStack_180 >> 8);
        puVar19 = puStack_190;
      }
      bVar2 = *(byte *)puStack_1b0;
      bVar3 = *(byte *)((int)puStack_1c4 + uStack_1c8);
      puVar11 = (uint *)(uint)bVar3;
      *(byte *)((int)puStack_1c4 + uStack_1c8) = bVar2;
      puStack_1b0 = (uint *)((int)puStack_1b0 + 1);
      uStack_1c8 = uStack_1c8 + 1 & 7;
      *pbStack_1ac = bVar2 ^ bVar3;
      pbStack_1ac = pbStack_1ac + 1;
    }
  }
  else {
    puStack_1a8 = puStack_158;
    if (pbVar13 != (byte *)0x0) {
      puStack_1a8 = &uStack_184;
      pbVar1 = pbVar17;
      do {
        if (uStack_1c8 == 0) {
          uStack_184 = *puStack_1c4;
          uStack_180 = puStack_1c4[1];
          (*(code *)puStack_190[-0x1a36])(puStack_1a8,pbStack_1c0);
          pbVar13 = (byte *)(uStack_184 >> 0x10);
          *(char *)((int)puStack_1c4 + 3) = (char)uStack_184;
          pbVar17 = (byte *)(uStack_180 >> 0x18);
          *(char *)((int)puStack_1c4 + 7) = (char)uStack_180;
          *(char *)puStack_1c4 = (char)(uStack_184 >> 0x18);
          *(char *)((int)puStack_1c4 + 1) = (char)(uStack_184 >> 0x10);
          *(char *)(puStack_1c4 + 1) = (char)(uStack_180 >> 0x18);
          *(char *)((int)puStack_1c4 + 2) = (char)(uStack_184 >> 8);
          *(char *)((int)puStack_1c4 + 5) = (char)(uStack_180 >> 0x10);
          *(char *)((int)puStack_1c4 + 6) = (char)(uStack_180 >> 8);
        }
        pbVar10 = (byte *)((int)puStack_1c4 + uStack_1c8);
        bVar2 = *(byte *)puStack_1b0;
        pbStack_1ac = pbVar1 + 1;
        bVar3 = *pbVar10;
        puVar11 = (uint *)(uint)bVar3;
        pbStack_1b4 = pbStack_1b4 + -1;
        puStack_1b0 = (uint *)((int)puStack_1b0 + 1);
        uStack_1c8 = uStack_1c8 + 1 & 7;
        bVar2 = bVar2 ^ bVar3;
        *pbVar1 = bVar2;
        *pbVar10 = bVar2;
        puVar19 = puStack_190;
        pbVar1 = pbStack_1ac;
      } while (pbStack_1b4 != (byte *)0x0);
    }
  }
  iVar7 = *(int *)puStack_1b8;
  *puStack_13c = uStack_1c8;
  if (iStack_17c != iVar7) {
    pcStack_1a4 = idea_ofb64_encrypt;
    (*(code *)puVar19[-0x14ca])();
    puVar19 = puStack_190;
    puVar5 = PTR___stack_chk_guard_006aabf0;
    puStack_1bc = puStack_13c;
    uStack_1dc = *puStack_190;
    uStack_1d8 = puStack_190[1];
    uVar16 = *puStack_18c;
    iStack_1cc = *(int *)PTR___stack_chk_guard_006aabf0;
    abStack_1d4[3] = (char)uStack_1dc;
    abStack_1d4[0] = (byte)((uint)uStack_1dc >> 0x18);
    uVar15 = uStack_1d8 >> 0x18;
    abStack_1d4[1] = (char)((uint)uStack_1dc >> 0x10);
    abStack_1d4[2] = (char)((uint)uStack_1dc >> 8);
    uStack_1d0 = (char)(uStack_1d8 >> 0x18);
    uStack_1cf = (char)(uStack_1d8 >> 0x10);
    uStack_1ce = (char)(uStack_1d8 >> 8);
    uStack_1cd = (char)uStack_1d8;
    if (pbVar13 != (byte *)0x0) {
      iVar7 = 0;
      do {
        if (uVar16 == 0) {
          iVar7 = iVar7 + 1;
          (*(code *)PTR_idea_encrypt_006a9608)(&uStack_1dc,pbVar14);
          abStack_1d4[3] = (char)uStack_1dc;
          uStack_1cd = (char)uStack_1d8;
          abStack_1d4[0] = (byte)((uint)uStack_1dc >> 0x18);
          abStack_1d4[1] = (char)((uint)uStack_1dc >> 0x10);
          uStack_1d0 = (char)(uStack_1d8 >> 0x18);
          abStack_1d4[2] = (char)((uint)uStack_1dc >> 8);
          uStack_1cf = (char)(uStack_1d8 >> 0x10);
          uStack_1ce = (char)(uStack_1d8 >> 8);
        }
        bVar2 = *(byte *)puVar11;
        pbVar13 = pbVar13 + -1;
        pbVar1 = abStack_1d4 + uVar16;
        puVar11 = (uint *)((int)puVar11 + 1);
        uVar16 = uVar16 + 1 & 7;
        *pbVar17 = bVar2 ^ *pbVar1;
        pbVar17 = pbVar17 + 1;
      } while (pbVar13 != (byte *)0x0);
      if (iVar7 != 0) {
        *(char *)((int)puVar19 + 3) = (char)uStack_1dc;
        *(char *)((int)puVar19 + 7) = (char)uStack_1d8;
        *(char *)puVar19 = (char)((uint)uStack_1dc >> 0x18);
        *(char *)((int)puVar19 + 1) = (char)((uint)uStack_1dc >> 0x10);
        *(char *)(puVar19 + 1) = (char)(uStack_1d8 >> 0x18);
        *(char *)((int)puVar19 + 2) = (char)((uint)uStack_1dc >> 8);
        *(char *)((int)puVar19 + 5) = (char)(uStack_1d8 >> 0x10);
        *(char *)((int)puVar19 + 6) = (char)(uStack_1d8 >> 8);
      }
    }
    iVar7 = *(int *)puVar5;
    *puStack_18c = uVar16;
    if (iStack_1cc == iVar7) {
      return iVar7;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (uVar15 != 1) {
                    /* WARNING: Could not recover jumptable at 0x005e9004. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar7 = (*(code *)PTR_Camellia_decrypt_006a9634)();
      return iVar7;
    }
                    /* WARNING: Could not recover jumptable at 0x005e9010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar7 = (*(code *)PTR_Camellia_encrypt_006a9638)();
    return iVar7;
  }
  return iVar7;
}

