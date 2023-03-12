
/* WARNING: Could not reconcile some variable overlaps */

void AES_ige_encrypt(uchar *in,uchar *out,size_t length,AES_KEY *key,uchar *ivec,int enc)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  undefined *puVar5;
  byte ********ppppppppbVar6;
  byte *******pppppppbVar7;
  int iVar8;
  byte ********ppppppppbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte bVar14;
  byte ******ppppppbVar13;
  uint in_v1;
  uint extraout_v1;
  byte *******pppppppbVar15;
  uint extraout_v1_00;
  uint extraout_v1_01;
  uint uVar16;
  byte ********ppppppppbVar17;
  uint uVar18;
  byte bVar20;
  byte ******ppppppbVar19;
  char *pcVar21;
  byte *******pppppppbVar22;
  byte ********ppppppppbVar23;
  byte ******ppppppbVar24;
  uchar *puVar25;
  byte ********ppppppppbVar26;
  byte ******ppppppbVar27;
  char *pcVar28;
  AES_KEY *pAVar29;
  uint uVar30;
  AES_KEY *pAVar31;
  uint uVar32;
  byte ******ppppppbVar33;
  byte ********in_t0;
  uint uVar34;
  uint uVar35;
  byte ********in_t1;
  byte ******ppppppbVar36;
  byte ********in_t2;
  byte ********in_t3;
  byte ******ppppppbVar37;
  AES_KEY *pAVar38;
  uint *puVar39;
  byte bVar40;
  byte bVar41;
  byte bVar42;
  byte *pbVar43;
  byte bVar45;
  byte bVar46;
  byte bVar48;
  byte ********ppppppppbVar47;
  byte ********unaff_s5;
  byte bVar49;
  byte ********unaff_s7;
  byte bVar51;
  byte ******ppppppbVar50;
  byte ********unaff_s8;
  byte bVar52;
  byte bStack_149;
  AES_KEY *pAStack_144;
  byte bStack_139;
  undefined4 uStack_130;
  byte ********ppppppppbStack_104;
  byte *******pppppppbStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  byte *******pppppppbStack_e4;
  byte *******pppppppbStack_e0;
  byte ********ppppppppbStack_dc;
  byte ********ppppppppbStack_d8;
  byte *******pppppppbStack_d4;
  byte *******pppppppbStack_d0;
  byte ********ppppppppbStack_cc;
  byte ********ppppppppbStack_c8;
  int iStack_c4;
  byte ********ppppppppbStack_c0;
  byte ********ppppppppbStack_bc;
  byte ********ppppppppbStack_b8;
  uchar *puStack_b4;
  byte ********ppppppppbStack_b0;
  byte ********ppppppppbStack_ac;
  AES_KEY *pAStack_a8;
  byte ********ppppppppbStack_a4;
  byte ********ppppppppbStack_a0;
  code *pcStack_9c;
  byte ********ppppppppbStack_90;
  undefined *local_88;
  byte ********ppppppppbStack_84;
  uint uStack_80;
  byte ********local_7c;
  int *local_78;
  byte ********local_74;
  byte ********local_6c;
  byte ********local_68;
  byte ********local_64;
  byte *******local_60;
  byte ********local_5c;
  byte ********local_58;
  byte ********local_54;
  byte ********local_50;
  byte ********local_4c;
  byte ********local_48;
  byte ********local_44;
  byte ********local_40;
  byte ********local_3c;
  byte ********local_38;
  byte ********local_34;
  byte *******local_30;
  int local_2c;
  byte *pbVar44;
  
  local_78 = (int *)PTR___stack_chk_guard_006aabf0;
  local_88 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar29 = key;
  if ((((in == (uchar *)0x0) || (out == (uchar *)0x0)) || (key == (AES_KEY *)0x0)) ||
     (pcVar21 = (char *)in, puVar25 = out, ivec == (uchar *)0x0)) {
    puVar25 = (uchar *)0x56;
    pcVar21 = "aes_ige.c";
    (*(code *)PTR_OpenSSLDie_006a8d4c)("aes_ige.c",0x56,"in && out && key && ivec");
    in_v1 = extraout_v1_00;
  }
  pcVar28 = (char *)0x660000;
  if (1 < (uint)enc) {
    pcVar28 = "(AES_ENCRYPT == enc)||(AES_DECRYPT == enc)";
    puVar25 = (uchar *)0x57;
    pcVar21 = "aes_ige.c";
    (**(code **)(local_88 + -0x7194))();
    in_v1 = extraout_v1;
  }
  if ((length & 0xf) == 0) {
    if (enc == 1) goto LAB_004e1090;
LAB_004e0c5c:
    ppppppppbStack_b0 = (byte ********)(length >> 4);
    if ((in == out) ||
       (ppppppppbVar6 = (byte ********)(ivec + 0x10), (((uint)in | (uint)out | (uint)ivec) & 3) != 0
       )) {
      uVar12 = (uint)ivec & 3;
      uVar10 = (uint)(ivec + 4) & 3;
      uVar18 = (uint)(ivec + 8) & 3;
      local_40 = *(byte *********)(ivec + 0xc);
      enc = (int)&local_6c;
      uVar11 = (uint)(ivec + 3) & 3;
      in_t1 = (byte ********)
              ((*(int *)(ivec + -uVar12) << uVar12 * 8 |
               (uint)in_t1 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar11 + 1) * 8 |
              *(uint *)(ivec + 3 + -uVar11) >> (3 - uVar11) * 8);
      uVar12 = (uint)(ivec + 7) & 3;
      in_t0 = (byte ********)
              ((*(int *)(ivec + 4 + -uVar10) << uVar10 * 8 |
               (uint)in_t0 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar12 + 1) * 8 |
              *(uint *)(ivec + 7 + -uVar12) >> (3 - uVar12) * 8);
      uVar12 = (uint)(ivec + 0xb) & 3;
      local_44 = (byte ********)
                 ((*(int *)(ivec + 8 + -uVar18) << uVar18 * 8 |
                  (uint)pcVar28 & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)(ivec + 0xb + -uVar12) >> (3 - uVar12) * 8);
      uVar12 = (uint)(ivec + 0x10) & 3;
      uVar10 = (uint)(ivec + 0x14) & 3;
      uVar18 = (uint)(ivec + 0x18) & 3;
      uVar11 = (uint)(ivec + 0x13) & 3;
      local_3c = (byte ********)
                 ((*(int *)(ivec + 0x10 + -uVar12) << uVar12 * 8 |
                  (uint)puVar25 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar11 + 1) * 8 |
                 *(uint *)(ivec + 0x13 + -uVar11) >> (3 - uVar11) * 8);
      uVar12 = (uint)(ivec + 0x17) & 3;
      local_38 = (byte ********)
                 ((*(int *)(ivec + 0x14 + -uVar10) << uVar10 * 8 |
                  (uint)pcVar21 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)(ivec + 0x17 + -uVar12) >> (3 - uVar12) * 8);
      uVar12 = (uint)(ivec + 0x1b) & 3;
      local_34 = (byte ********)
                 ((*(int *)(ivec + 0x18 + -uVar18) << uVar18 * 8 |
                  in_v1 & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)(ivec + 0x1b + -uVar12) >> (3 - uVar12) * 8);
      local_30 = *(byte ********)(ivec + 0x1c);
      local_4c = in_t1;
      local_48 = in_t0;
      for (; ppppppppbStack_b0 != (byte ********)0x0;
          ppppppppbStack_b0 = (byte ********)((int)ppppppppbStack_b0 + -1)) {
        uVar12 = (uint)in & 3;
        uVar10 = (uint)(byte ********)((int)in + 4) & 3;
        uVar18 = (uint)(byte ********)((int)in + 8) & 3;
        local_50 = *(byte *********)((int)in + 0xc);
        uVar11 = (int)in + 3U & 3;
        in_t3 = (byte ********)
                ((*(int *)((int)in - uVar12) << uVar12 * 8 |
                 (uint)in_t1 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar11 + 1) * 8 |
                *(uint *)(((int)in + 3U) - uVar11) >> (3 - uVar11) * 8);
        uVar12 = (int)in + 7U & 3;
        local_58 = (byte ********)
                   ((*(int *)((int)(byte ********)((int)in + 4) - uVar10) << uVar10 * 8 |
                    (uint)in_t0 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar12 + 1) * 8 |
                   *(uint *)(((int)in + 7U) - uVar12) >> (3 - uVar12) * 8);
        uVar12 = (int)in + 0xbU & 3;
        local_54 = (byte ********)
                   ((*(int *)((int)(byte ********)((int)in + 8) - uVar18) << uVar18 * 8 |
                    (uint)local_34 & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar12 + 1) * 8 |
                   *(uint *)(((int)in + 0xbU) - uVar12) >> (3 - uVar12) * 8);
        in = (uchar *)((int)in + 0x10);
        local_6c = (byte ********)((uint)in_t3 ^ (uint)local_3c);
        local_68 = (byte ********)((uint)local_58 ^ (uint)local_38);
        local_64 = (byte ********)((uint)local_54 ^ (uint)local_34);
        local_60 = (byte *******)((uint)local_50 ^ (uint)local_30);
        local_5c = in_t3;
        AES_decrypt((uchar *)enc,(uchar *)enc,key);
        local_3c = (byte ********)((uint)local_6c ^ (uint)local_4c);
        in_t1 = (byte ********)((uint)local_68 ^ (uint)local_48);
        in_t0 = (byte ********)((uint)local_64 ^ (uint)local_44);
        local_30 = (byte *******)((uint)local_60 ^ (uint)local_40);
        *(byte *********)out = local_3c;
        *(byte *********)((int)out + 4) = in_t1;
        *(byte *********)((int)out + 8) = in_t0;
        *(byte ********)((int)out + 0xc) = local_30;
        out = (uchar *)((int)out + 0x10);
        local_40 = local_50;
        local_4c = local_5c;
        local_48 = local_58;
        local_44 = local_54;
        local_38 = in_t1;
        local_34 = in_t0;
        in_t2 = local_3c;
        local_6c = local_3c;
        local_68 = in_t1;
        local_64 = in_t0;
        local_60 = local_30;
      }
      goto LAB_004e0fa4;
    }
    ppppppppbVar9 = (byte ********)ivec;
    local_74 = ppppppppbVar6;
    if (ppppppppbStack_b0 != (byte ********)0x0) {
      in_t2 = *(byte *********)(ivec + 0x10);
      in_t0 = *(byte *********)(ivec + 0x14);
      pppppppbVar15 = *(byte ********)(ivec + 0x18);
      pppppppbVar7 = *(byte ********)(ivec + 0x1c);
      unaff_s7 = (byte ********)&local_3c;
      ppppppppbVar6 = (byte ********)ivec;
      ppppppppbVar9 = (byte ********)out;
      ppppppppbVar23 = (byte ********)in;
      do {
        in_t1 = ppppppppbVar23;
        in_t3 = (byte ********)in_t1[3];
        local_3c = (byte ********)((uint)*in_t1 ^ (uint)in_t2);
        local_38 = (byte ********)((uint)in_t1[1] ^ (uint)in_t0);
        local_34 = (byte ********)((uint)in_t1[2] ^ (uint)pppppppbVar15);
        local_30 = (byte *******)((uint)in_t3 ^ (uint)pppppppbVar7);
        enc = (int)(ppppppppbVar9 + 4);
        ppppppppbStack_b0 = (byte ********)((int)ppppppppbStack_b0 + -1);
        local_7c = ppppppppbVar6;
        AES_decrypt((uchar *)unaff_s7,(uchar *)ppppppppbVar9,key);
        in_t2 = (byte ********)((uint)*ppppppppbVar9 ^ (uint)*local_7c);
        *ppppppppbVar9 = (byte *******)in_t2;
        in_t0 = (byte ********)((uint)ppppppppbVar9[1] ^ (uint)local_7c[1]);
        ppppppppbVar9[1] = (byte *******)in_t0;
        pppppppbVar15 = (byte *******)((uint)ppppppppbVar9[2] ^ (uint)local_7c[2]);
        ppppppppbVar9[2] = pppppppbVar15;
        pppppppbVar7 = (byte *******)((uint)ppppppppbVar9[3] ^ (uint)local_7c[3]);
        ppppppppbVar9[3] = pppppppbVar7;
        ppppppppbVar6 = in_t1;
        ppppppppbVar9 = (byte ********)enc;
        ppppppppbVar23 = in_t1 + 4;
      } while (ppppppppbStack_b0 != (byte ********)0x0);
      iVar8 = (length & 0xfffffff0) - 0x10;
      ppppppppbVar6 = (byte ********)(out + iVar8);
      ppppppppbVar9 = (byte ********)(in + iVar8);
      unaff_s5 = in_t1;
      unaff_s8 = ppppppppbStack_b0;
    }
    pppppppbVar22 = ppppppppbVar9[1];
    pppppppbVar15 = ppppppppbVar9[2];
    pppppppbVar7 = ppppppppbVar9[3];
    *(byte ********)ivec = *ppppppppbVar9;
    *(byte ********)(ivec + 4) = pppppppbVar22;
    *(byte ********)(ivec + 8) = pppppppbVar15;
    *(byte ********)(ivec + 0xc) = pppppppbVar7;
    ppppppppbVar26 = (byte ********)*ppppppppbVar6;
    ppppppppbVar23 = (byte ********)ppppppppbVar6[1];
    pppppppbVar15 = ppppppppbVar6[2];
    pppppppbVar7 = ppppppppbVar6[3];
    ppppppppbStack_90 = local_74;
  }
  else {
    pcVar28 = "(length%AES_BLOCK_SIZE) == 0";
    puVar25 = (uchar *)0x58;
    pcVar21 = "aes_ige.c";
    (**(code **)(local_88 + -0x7194))();
    in_v1 = extraout_v1_01;
    if (enc != 1) goto LAB_004e0c5c;
LAB_004e1090:
    ppppppppbStack_b0 = (byte ********)(length >> 4);
    if ((in == out) ||
       (ppppppppbVar9 = (byte ********)(ivec + 0x10), (((uint)in | (uint)out | (uint)ivec) & 3) != 0
       )) {
      uVar12 = (uint)ivec & 3;
      uVar10 = (uint)(ivec + 4) & 3;
      local_44 = *(byte *********)(ivec + 8);
      local_40 = *(byte *********)(ivec + 0xc);
      uVar18 = (uint)(ivec + 3) & 3;
      in_t1 = (byte ********)
              ((*(int *)(ivec + -uVar12) << uVar12 * 8 |
               (uint)in_t1 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar18 + 1) * 8 |
              *(uint *)(ivec + 3 + -uVar18) >> (3 - uVar18) * 8);
      uVar12 = (uint)(ivec + 7) & 3;
      in_t0 = (byte ********)
              ((*(int *)(ivec + 4 + -uVar10) << uVar10 * 8 |
               (uint)in_t0 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar12 + 1) * 8 |
              *(uint *)(ivec + 7 + -uVar12) >> (3 - uVar12) * 8);
      uVar12 = (uint)(ivec + 0x10) & 3;
      uVar10 = (uint)(ivec + 0x14) & 3;
      uVar18 = (uint)(ivec + 0x18) & 3;
      uVar11 = (uint)(ivec + 0x13) & 3;
      local_3c = (byte ********)
                 ((*(int *)(ivec + 0x10 + -uVar12) << uVar12 * 8 |
                  (uint)puVar25 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar11 + 1) * 8 |
                 *(uint *)(ivec + 0x13 + -uVar11) >> (3 - uVar11) * 8);
      uVar12 = (uint)(ivec + 0x17) & 3;
      local_38 = (byte ********)
                 ((*(int *)(ivec + 0x14 + -uVar10) << uVar10 * 8 |
                  (uint)pcVar21 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)(ivec + 0x17 + -uVar12) >> (3 - uVar12) * 8);
      uVar12 = (uint)(ivec + 0x1b) & 3;
      ppppppppbVar6 =
           (byte ********)
           ((*(int *)(ivec + 0x18 + -uVar18) << uVar18 * 8 | in_v1 & 0xffffffffU >> (4 - uVar18) * 8
            ) & -1 << (uVar12 + 1) * 8 | *(uint *)(ivec + 0x1b + -uVar12) >> (3 - uVar12) * 8);
      local_30 = *(byte ********)(ivec + 0x1c);
      local_4c = in_t1;
      local_48 = in_t0;
      local_34 = ppppppppbVar6;
      if (ppppppppbStack_b0 != (byte ********)0x0) {
        enc = (int)&local_6c;
        local_7c = (byte ********)&local_5c;
        do {
          uVar12 = (uint)in & 3;
          uVar10 = (uint)(byte ********)((int)in + 4) & 3;
          uVar18 = (uint)(byte ********)((int)in + 8) & 3;
          local_60 = *(byte ********)((int)in + 0xc);
          ppppppppbStack_b0 = (byte ********)((int)ppppppppbStack_b0 + -1);
          uVar11 = (int)in + 3U & 3;
          local_6c = (byte ********)
                     ((*(int *)((int)in - uVar12) << uVar12 * 8 |
                      (uint)in_t2 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar11 + 1) * 8 |
                     *(uint *)(((int)in + 3U) - uVar11) >> (3 - uVar11) * 8);
          uVar12 = (int)in + 7U & 3;
          local_68 = (byte ********)
                     ((*(int *)((int)(byte ********)((int)in + 4) - uVar10) << uVar10 * 8 |
                      (uint)in_t1 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar12 + 1) * 8 |
                     *(uint *)(((int)in + 7U) - uVar12) >> (3 - uVar12) * 8);
          uVar12 = (int)in + 0xbU & 3;
          local_64 = (byte ********)
                     ((*(int *)((int)(byte ********)((int)in + 8) - uVar18) << uVar18 * 8 |
                      (uint)ppppppppbVar6 & 0xffffffffU >> (4 - uVar18) * 8) &
                      -1 << (uVar12 + 1) * 8 |
                     *(uint *)(((int)in + 0xbU) - uVar12) >> (3 - uVar12) * 8);
          in = (uchar *)((int)in + 0x10);
          local_5c = (byte ********)((uint)local_6c ^ (uint)local_4c);
          in_t1 = (byte ********)((uint)local_68 ^ (uint)local_48);
          local_54 = (byte ********)((uint)local_64 ^ (uint)local_44);
          local_50 = (byte ********)((uint)local_60 ^ (uint)local_40);
          local_58 = in_t1;
          AES_encrypt((uchar *)local_7c,(uchar *)local_7c,key);
          local_5c = (byte ********)((uint)local_5c ^ (uint)local_3c);
          local_58 = (byte ********)((uint)local_58 ^ (uint)local_38);
          *(byte *********)out = local_5c;
          ppppppppbVar6 = (byte ********)((uint)local_54 ^ (uint)local_34);
          *(byte *********)((int)out + 4) = local_58;
          *(byte *********)((int)out + 8) = ppppppppbVar6;
          local_50 = (byte ********)((uint)local_50 ^ (uint)local_30);
          *(byte *********)((int)out + 0xc) = local_50;
          out = (uchar *)((int)out + 0x10);
          local_3c = local_6c;
          local_38 = local_68;
          local_34 = local_64;
          local_30 = local_60;
          in_t0 = local_7c;
          in_t2 = local_40;
          local_54 = ppppppppbVar6;
          local_4c = local_5c;
          local_48 = local_58;
          local_44 = ppppppppbVar6;
          local_40 = local_50;
        } while (ppppppppbStack_b0 != (byte ********)0x0);
      }
LAB_004e0fa4:
      unaff_s7 = (byte ********)&local_3c;
      unaff_s5 = (byte ********)&local_4c;
      unaff_s8 = (byte ********)(ivec + 0x10);
      *(byte *********)ivec = local_4c;
      *(byte *********)(ivec + 4) = local_48;
      *(byte *********)(ivec + 8) = local_44;
      *(byte *********)(ivec + 0xc) = local_40;
      *unaff_s8 = (byte *******)local_3c;
      *(byte *********)(ivec + 0x14) = local_38;
      *(byte *********)(ivec + 0x18) = local_34;
      *(byte ********)(ivec + 0x1c) = local_30;
      ppppppppbVar23 = local_38;
      ppppppppbVar26 = local_3c;
      ppppppppbStack_90 = local_4c;
      goto LAB_004e1000;
    }
    ppppppppbVar6 = (byte ********)ivec;
    local_7c = ppppppppbVar9;
    if (ppppppppbStack_b0 != (byte ********)0x0) {
      in_t1 = *(byte *********)ivec;
      pAVar29 = *(AES_KEY **)(ivec + 4);
      pppppppbVar15 = *(byte ********)(ivec + 8);
      pppppppbVar7 = *(byte ********)(ivec + 0xc);
      ppppppppbVar6 = (byte ********)out;
      ppppppppbVar9 = (byte ********)in;
      ppppppppbVar23 = (byte ********)(ivec + 0x10);
      do {
        unaff_s5 = ppppppppbVar9;
        in_t3 = (byte ********)*unaff_s5;
        enc = (int)(ppppppppbVar6 + 4);
        *ppppppppbVar6 = (byte *******)((uint)in_t3 ^ (uint)in_t1);
        ppppppppbStack_b0 = (byte ********)((int)ppppppppbStack_b0 + -1);
        ppppppppbVar6[1] = (byte *******)((uint)unaff_s5[1] ^ (uint)pAVar29);
        ppppppppbVar6[2] = (byte *******)((uint)unaff_s5[2] ^ (uint)pppppppbVar15);
        ppppppppbVar6[3] = (byte *******)((uint)unaff_s5[3] ^ (uint)pppppppbVar7);
        AES_encrypt((uchar *)ppppppppbVar6,(uchar *)ppppppppbVar6,key);
        in_t1 = (byte ********)((uint)*ppppppppbVar6 ^ (uint)*ppppppppbVar23);
        *ppppppppbVar6 = (byte *******)in_t1;
        pAVar29 = (AES_KEY *)((uint)ppppppppbVar6[1] ^ (uint)ppppppppbVar23[1]);
        ppppppppbVar6[1] = (byte *******)pAVar29;
        pppppppbVar15 = (byte *******)((uint)ppppppppbVar6[2] ^ (uint)ppppppppbVar23[2]);
        ppppppppbVar6[2] = pppppppbVar15;
        pppppppbVar7 = (byte *******)((uint)ppppppppbVar6[3] ^ (uint)ppppppppbVar23[3]);
        ppppppppbVar6[3] = pppppppbVar7;
        ppppppppbVar6 = (byte ********)enc;
        ppppppppbVar9 = unaff_s5 + 4;
        ppppppppbVar23 = unaff_s5;
      } while (ppppppppbStack_b0 != (byte ********)0x0);
      iVar8 = (length & 0xfffffff0) - 0x10;
      ppppppppbVar9 = (byte ********)(in + iVar8);
      ppppppppbVar6 = (byte ********)(out + iVar8);
      unaff_s7 = ppppppppbStack_b0;
      unaff_s8 = unaff_s5;
    }
    pppppppbVar22 = ppppppppbVar6[1];
    pppppppbVar15 = ppppppppbVar6[2];
    pppppppbVar7 = ppppppppbVar6[3];
    *(byte ********)ivec = *ppppppppbVar6;
    *(byte ********)(ivec + 4) = pppppppbVar22;
    *(byte ********)(ivec + 8) = pppppppbVar15;
    *(byte ********)(ivec + 0xc) = pppppppbVar7;
    ppppppppbVar26 = (byte ********)*ppppppppbVar9;
    ppppppppbVar23 = (byte ********)ppppppppbVar9[1];
    pppppppbVar15 = ppppppppbVar9[2];
    pppppppbVar7 = ppppppppbVar9[3];
    ppppppppbStack_90 = local_7c;
  }
  ppppppppbStack_b0 = (byte ********)(length >> 4);
  *ppppppppbStack_90 = (byte *******)ppppppppbVar26;
  ppppppppbStack_90[1] = (byte *******)ppppppppbVar23;
  ppppppppbStack_90[2] = pppppppbVar15;
  ppppppppbStack_90[3] = pppppppbVar7;
  out = (uchar *)ppppppppbVar6;
  in = (uchar *)ppppppppbVar9;
LAB_004e1000:
  if (local_2c == *local_78) {
    return;
  }
  pcStack_9c = AES_bi_ige_encrypt;
  (**(code **)(local_88 + -0x5328))();
  puVar5 = PTR___stack_chk_guard_006aabf0;
  puStack_b4 = ivec;
  iStack_c4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar31 = pAVar29;
  ppppppppbStack_c0 = (byte ********)out;
  ppppppppbStack_bc = (byte ********)in;
  ppppppppbStack_b8 = (byte ********)enc;
  ppppppppbStack_ac = unaff_s5;
  pAStack_a8 = key;
  ppppppppbStack_a4 = unaff_s7;
  ppppppppbStack_a0 = unaff_s8;
  if ((((ppppppppbVar23 == (byte ********)0x0) || (ppppppppbVar26 == (byte ********)0x0)) ||
      (pAVar29 == (AES_KEY *)0x0)) ||
     (pcVar21 = (char *)ppppppppbVar23, ppppppppbVar6 = ppppppppbVar26,
     ppppppppbStack_84 == (byte ********)0x0)) {
    ppppppppbVar6 = (byte ********)0xe3;
    pcVar21 = "aes_ige.c";
    (*(code *)PTR_OpenSSLDie_006a8d4c)("aes_ige.c",0xe3,"in && out && key && ivec");
  }
  if (1 < uStack_80) {
    ppppppppbVar6 = (byte ********)0xe4;
    pcVar21 = "aes_ige.c";
    (*(code *)PTR_OpenSSLDie_006a8d4c)
              ("aes_ige.c",0xe4,"(AES_ENCRYPT == enc)||(AES_DECRYPT == enc)");
  }
  pcVar28 = CAST_S_table6 + 0x370;
  if (((uint)ppppppppbStack_90 & 0xf) != 0) {
    pcVar28 = "(length%AES_BLOCK_SIZE) == 0";
    ppppppppbVar6 = (byte ********)0xe5;
    pcVar21 = "aes_ige.c";
    (*(code *)PTR_OpenSSLDie_006a8d4c)();
  }
  if (uStack_80 == 1) {
    if (&SUB_00000010 <= ppppppppbStack_90) {
      bVar20 = *(byte *)ppppppppbStack_84;
      ppppppppbVar6 = ppppppppbStack_84;
      ppppppppbVar9 = ppppppppbVar26;
      ppppppppbVar17 = ppppppppbStack_84 + 4;
      ppppppppbVar47 = ppppppppbStack_90;
      do {
        ppppppppbVar47 = ppppppppbVar47 + -4;
        *(byte *)ppppppppbVar9 = bVar20 ^ *(byte *)ppppppppbVar23;
        *(byte *)((int)ppppppppbVar9 + 1) =
             *(byte *)((int)ppppppppbVar23 + 1) ^ *(byte *)((int)ppppppppbVar6 + 1);
        *(byte *)((int)ppppppppbVar9 + 2) =
             *(byte *)((int)ppppppppbVar23 + 2) ^ *(byte *)((int)ppppppppbVar6 + 2);
        *(byte *)((int)ppppppppbVar9 + 3) =
             *(byte *)((int)ppppppppbVar23 + 3) ^ *(byte *)((int)ppppppppbVar6 + 3);
        *(byte *)(ppppppppbVar9 + 1) = *(byte *)(ppppppppbVar23 + 1) ^ *(byte *)(ppppppppbVar6 + 1);
        *(byte *)((int)ppppppppbVar9 + 5) =
             *(byte *)((int)ppppppppbVar23 + 5) ^ *(byte *)((int)ppppppppbVar6 + 5);
        *(byte *)((int)ppppppppbVar9 + 6) =
             *(byte *)((int)ppppppppbVar23 + 6) ^ *(byte *)((int)ppppppppbVar6 + 6);
        *(byte *)((int)ppppppppbVar9 + 7) =
             *(byte *)((int)ppppppppbVar23 + 7) ^ *(byte *)((int)ppppppppbVar6 + 7);
        *(byte *)(ppppppppbVar9 + 2) = *(byte *)(ppppppppbVar23 + 2) ^ *(byte *)(ppppppppbVar6 + 2);
        *(byte *)((int)ppppppppbVar9 + 9) =
             *(byte *)((int)ppppppppbVar23 + 9) ^ *(byte *)((int)ppppppppbVar6 + 9);
        *(byte *)((int)ppppppppbVar9 + 10) =
             *(byte *)((int)ppppppppbVar23 + 10) ^ *(byte *)((int)ppppppppbVar6 + 10);
        *(byte *)((int)ppppppppbVar9 + 0xb) =
             *(byte *)((int)ppppppppbVar23 + 0xb) ^ *(byte *)((int)ppppppppbVar6 + 0xb);
        *(byte *)(ppppppppbVar9 + 3) = *(byte *)(ppppppppbVar23 + 3) ^ *(byte *)(ppppppppbVar6 + 3);
        *(byte *)((int)ppppppppbVar9 + 0xd) =
             *(byte *)((int)ppppppppbVar23 + 0xd) ^ *(byte *)((int)ppppppppbVar6 + 0xd);
        *(byte *)((int)ppppppppbVar9 + 0xe) =
             *(byte *)((int)ppppppppbVar23 + 0xe) ^ *(byte *)((int)ppppppppbVar6 + 0xe);
        *(byte *)((int)ppppppppbVar9 + 0xf) =
             *(byte *)((int)ppppppppbVar23 + 0xf) ^ *(byte *)((int)ppppppppbVar6 + 0xf);
        AES_encrypt((uchar *)ppppppppbVar9,(uchar *)ppppppppbVar9,pAVar29);
        bVar20 = *(byte *)ppppppppbVar9 ^ *(byte *)ppppppppbVar17;
        *(byte *)ppppppppbVar9 = bVar20;
        *(byte *)((int)ppppppppbVar9 + 1) =
             *(byte *)((int)ppppppppbVar9 + 1) ^ *(byte *)((int)ppppppppbVar17 + 1);
        *(byte *)((int)ppppppppbVar9 + 2) =
             *(byte *)((int)ppppppppbVar9 + 2) ^ *(byte *)((int)ppppppppbVar17 + 2);
        *(byte *)((int)ppppppppbVar9 + 3) =
             *(byte *)((int)ppppppppbVar9 + 3) ^ *(byte *)((int)ppppppppbVar17 + 3);
        *(byte *)(ppppppppbVar9 + 1) = *(byte *)(ppppppppbVar9 + 1) ^ *(byte *)(ppppppppbVar17 + 1);
        bVar1 = *(byte *)((int)ppppppppbVar17 + 5);
        *(byte *)((int)ppppppppbVar9 + 5) = *(byte *)((int)ppppppppbVar9 + 5) ^ bVar1;
        *(byte *)((int)ppppppppbVar9 + 6) =
             *(byte *)((int)ppppppppbVar9 + 6) ^ *(byte *)((int)ppppppppbVar17 + 6);
        *(byte *)((int)ppppppppbVar9 + 7) =
             *(byte *)((int)ppppppppbVar9 + 7) ^ *(byte *)((int)ppppppppbVar17 + 7);
        *(byte *)(ppppppppbVar9 + 2) = *(byte *)(ppppppppbVar9 + 2) ^ *(byte *)(ppppppppbVar17 + 2);
        *(byte *)((int)ppppppppbVar9 + 9) =
             *(byte *)((int)ppppppppbVar9 + 9) ^ *(byte *)((int)ppppppppbVar17 + 9);
        *(byte *)((int)ppppppppbVar9 + 10) =
             *(byte *)((int)ppppppppbVar9 + 10) ^ *(byte *)((int)ppppppppbVar17 + 10);
        *(byte *)((int)ppppppppbVar9 + 0xb) =
             *(byte *)((int)ppppppppbVar9 + 0xb) ^ *(byte *)((int)ppppppppbVar17 + 0xb);
        *(byte *)(ppppppppbVar9 + 3) = *(byte *)(ppppppppbVar9 + 3) ^ *(byte *)(ppppppppbVar17 + 3);
        *(byte *)((int)ppppppppbVar9 + 0xd) =
             *(byte *)((int)ppppppppbVar9 + 0xd) ^ *(byte *)((int)ppppppppbVar17 + 0xd);
        *(byte *)((int)ppppppppbVar9 + 0xe) =
             *(byte *)((int)ppppppppbVar9 + 0xe) ^ *(byte *)((int)ppppppppbVar17 + 0xe);
        *(byte *)((int)ppppppppbVar9 + 0xf) =
             *(byte *)((int)ppppppppbVar9 + 0xf) ^ *(byte *)((int)ppppppppbVar17 + 0xf);
        pppppppbStack_d4 = *ppppppppbVar23;
        pppppppbStack_d0 = ppppppppbVar23[1];
        ppppppppbStack_cc = (byte ********)ppppppppbVar23[2];
        ppppppppbStack_c8 = (byte ********)ppppppppbVar23[3];
        ppppppppbVar23 = ppppppppbVar23 + 4;
        ppppppppbVar6 = ppppppppbVar9;
        ppppppppbVar9 = ppppppppbVar9 + 4;
        ppppppppbVar17 = &pppppppbStack_d4;
      } while (&SUB_00000010 <= ppppppppbVar47);
      iVar8 = (int)ppppppppbStack_90 -
              (int)(ppppppppbVar26 + (((uint)(ppppppppbStack_90 + -4) >> 4) + 1) * 4);
      ppppppppbVar9 = ppppppppbStack_84 + 8;
      ppppppppbVar23 = ppppppppbVar26 + (((uint)(ppppppppbStack_90 + -4) >> 4) + 1) * 4;
      ppppppppbVar26 = ppppppppbStack_84 + 0xc;
      do {
        ppppppppbVar17 = ppppppppbVar23 + -4;
        uVar12 = (uint)ppppppppbVar17 & 3;
        uStack_f0 = ppppppppbVar23[-3];
        uStack_ec = (byte ********)ppppppppbVar23[-2];
        uStack_e8 = (byte ********)ppppppppbVar23[-1];
        uVar10 = (uint)(byte *)((int)ppppppppbVar23 + -0xd) & 3;
        pppppppbStack_f4 =
             (byte *******)
             ((*(int *)((int)ppppppppbVar17 - uVar12) << uVar12 * 8 |
              (uint)bVar1 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar10 + 1) * 8 |
             *(uint *)((byte *)((int)ppppppppbVar23 + -0xd) + -uVar10) >> (3 - uVar10) * 8);
        *(byte *)ppppppppbVar17 = *(byte *)ppppppppbVar17 ^ *(byte *)ppppppppbVar9;
        *(byte *)((int)ppppppppbVar23 + -0xf) =
             *(byte *)((int)ppppppppbVar23 + -0xf) ^ *(byte *)((int)ppppppppbVar9 + 1);
        *(byte *)((int)ppppppppbVar23 + -0xe) =
             *(byte *)((int)ppppppppbVar23 + -0xe) ^ *(byte *)((int)ppppppppbVar9 + 2);
        *(byte *)((int)ppppppppbVar23 + -0xd) =
             *(byte *)((int)ppppppppbVar23 + -0xd) ^ *(byte *)((int)ppppppppbVar9 + 3);
        *(byte *)(ppppppppbVar23 + -3) =
             *(byte *)(ppppppppbVar23 + -3) ^ *(byte *)(ppppppppbVar9 + 1);
        *(byte *)((int)ppppppppbVar23 + -0xb) =
             *(byte *)((int)ppppppppbVar23 + -0xb) ^ *(byte *)((int)ppppppppbVar9 + 5);
        *(byte *)((int)ppppppppbVar23 + -10) =
             *(byte *)((int)ppppppppbVar23 + -10) ^ *(byte *)((int)ppppppppbVar9 + 6);
        *(byte *)((int)ppppppppbVar23 + -9) =
             *(byte *)((int)ppppppppbVar23 + -9) ^ *(byte *)((int)ppppppppbVar9 + 7);
        *(byte *)(ppppppppbVar23 + -2) =
             *(byte *)(ppppppppbVar23 + -2) ^ *(byte *)(ppppppppbVar9 + 2);
        *(byte *)((int)ppppppppbVar23 + -7) =
             *(byte *)((int)ppppppppbVar23 + -7) ^ *(byte *)((int)ppppppppbVar9 + 9);
        *(byte *)((int)ppppppppbVar23 + -6) =
             *(byte *)((int)ppppppppbVar23 + -6) ^ *(byte *)((int)ppppppppbVar9 + 10);
        *(byte *)((int)ppppppppbVar23 + -5) =
             *(byte *)((int)ppppppppbVar23 + -5) ^ *(byte *)((int)ppppppppbVar9 + 0xb);
        *(byte *)(ppppppppbVar23 + -1) =
             *(byte *)(ppppppppbVar23 + -1) ^ *(byte *)(ppppppppbVar9 + 3);
        *(byte *)((int)ppppppppbVar23 + -3) =
             *(byte *)((int)ppppppppbVar23 + -3) ^ *(byte *)((int)ppppppppbVar9 + 0xd);
        *(byte *)((int)ppppppppbVar23 + -2) =
             *(byte *)((int)ppppppppbVar23 + -2) ^ *(byte *)((int)ppppppppbVar9 + 0xe);
        *(byte *)((int)ppppppppbVar23 + -1) =
             *(byte *)((int)ppppppppbVar23 + -1) ^ *(byte *)((int)ppppppppbVar9 + 0xf);
        AES_encrypt((uchar *)ppppppppbVar17,(uchar *)ppppppppbVar17,pAVar29);
        *(byte *)ppppppppbVar17 = *(byte *)ppppppppbVar17 ^ *(byte *)ppppppppbVar26;
        *(byte *)((int)ppppppppbVar23 + -0xf) =
             *(byte *)((int)ppppppppbVar23 + -0xf) ^ *(byte *)((int)ppppppppbVar26 + 1);
        *(byte *)((int)ppppppppbVar23 + -0xe) =
             *(byte *)((int)ppppppppbVar23 + -0xe) ^ *(byte *)((int)ppppppppbVar26 + 2);
        bVar1 = *(byte *)((int)ppppppppbVar26 + 3);
        *(byte *)((int)ppppppppbVar23 + -0xd) = *(byte *)((int)ppppppppbVar23 + -0xd) ^ bVar1;
        *(byte *)(ppppppppbVar23 + -3) =
             *(byte *)(ppppppppbVar23 + -3) ^ *(byte *)(ppppppppbVar26 + 1);
        *(byte *)((int)ppppppppbVar23 + -0xb) =
             *(byte *)((int)ppppppppbVar23 + -0xb) ^ *(byte *)((int)ppppppppbVar26 + 5);
        *(byte *)((int)ppppppppbVar23 + -10) =
             *(byte *)((int)ppppppppbVar23 + -10) ^ *(byte *)((int)ppppppppbVar26 + 6);
        *(byte *)((int)ppppppppbVar23 + -9) =
             *(byte *)((int)ppppppppbVar23 + -9) ^ *(byte *)((int)ppppppppbVar26 + 7);
        *(byte *)(ppppppppbVar23 + -2) =
             *(byte *)(ppppppppbVar23 + -2) ^ *(byte *)(ppppppppbVar26 + 2);
        *(byte *)((int)ppppppppbVar23 + -7) =
             *(byte *)((int)ppppppppbVar23 + -7) ^ *(byte *)((int)ppppppppbVar26 + 9);
        *(byte *)((int)ppppppppbVar23 + -6) =
             *(byte *)((int)ppppppppbVar23 + -6) ^ *(byte *)((int)ppppppppbVar26 + 10);
        *(byte *)((int)ppppppppbVar23 + -5) =
             *(byte *)((int)ppppppppbVar23 + -5) ^ *(byte *)((int)ppppppppbVar26 + 0xb);
        *(byte *)(ppppppppbVar23 + -1) =
             *(byte *)(ppppppppbVar23 + -1) ^ *(byte *)(ppppppppbVar26 + 3);
        *(byte *)((int)ppppppppbVar23 + -3) =
             *(byte *)((int)ppppppppbVar23 + -3) ^ *(byte *)((int)ppppppppbVar26 + 0xd);
        pppppppbStack_d4 = pppppppbStack_f4;
        *(byte *)((int)ppppppppbVar23 + -2) =
             *(byte *)((int)ppppppppbVar23 + -2) ^ *(byte *)((int)ppppppppbVar26 + 0xe);
        pppppppbStack_d0 = uStack_f0;
        bVar20 = *(byte *)((int)ppppppppbVar23 + -1) ^ *(byte *)((int)ppppppppbVar26 + 0xf);
        ppppppppbStack_cc = uStack_ec;
        *(byte *)((int)ppppppppbVar23 + -1) = bVar20;
        ppppppppbStack_c8 = uStack_e8;
        ppppppppbVar9 = ppppppppbVar17;
        pcVar21 = (char *)(uint)bVar20;
        ppppppppbVar6 = uStack_e8;
        pcVar28 = (char *)uStack_f0;
        ppppppppbVar23 = ppppppppbVar17;
        ppppppppbVar26 = &pppppppbStack_d4;
      } while (&DAT_0000000f < (byte *)((int)ppppppppbVar17 + iVar8));
    }
  }
  else {
    ppppppppbVar26 = (byte ********)((int)ppppppppbVar26 + (int)ppppppppbStack_90);
    if (&DAT_0000000f < ppppppppbStack_90) {
      bVar20 = *(byte *)((int)ppppppppbStack_84 + 0x3f);
      uVar10 = (int)ppppppppbStack_90 - (int)(byte *)((int)ppppppppbVar23 + (int)ppppppppbStack_90);
      uVar12 = uVar10;
      ppppppppbStack_d8 = ppppppppbVar26;
      ppppppppbVar6 = ppppppppbVar26;
      pbVar44 = (byte *)((int)ppppppppbVar23 + (int)ppppppppbStack_90);
      ppppppppbVar9 = ppppppppbStack_84 + 8;
      ppppppppbVar23 = ppppppppbStack_84 + 0xc;
      do {
        pbVar43 = pbVar44 + -0x10;
        ppppppppbVar17 = ppppppppbVar6 + -4;
        pppppppbStack_e0 = *(byte ********)(pbVar44 + -0xc);
        uVar18 = (uint)pbVar43 & 3;
        uVar11 = (uint)pbVar43 & 3;
        uVar16 = (uint)(pbVar44 + -0xc) & 3;
        uVar34 = (uint)(pbVar44 + -8) & 3;
        uVar32 = (uint)(pbVar44 + -4) & 3;
        uVar35 = (uint)(pbVar44 + -4) & 3;
        uVar3 = (uint)(pbVar44 + -8) & 3;
        uVar30 = (uint)(pbVar44 + -0xd) & 3;
        uVar30 = (*(int *)(pbVar43 + -uVar11) << uVar11 * 8 |
                 (uint)pAVar31 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar30 + 1) * 8 |
                 *(uint *)(pbVar44 + -0xd + -uVar30) >> (3 - uVar30) * 8;
        uVar11 = (uint)(pbVar44 + -9) & 3;
        uVar16 = (*(int *)(pbVar44 + -0xc + -uVar16) << uVar16 * 8 |
                 (uint)ppppppppbStack_d8 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar11 + 1) * 8
                 | *(uint *)(pbVar44 + -9 + -uVar11) >> (3 - uVar11) * 8;
        uVar11 = (uint)(pbVar44 + -5) & 3;
        uVar11 = (*(int *)(pbVar44 + -8 + -uVar34) << uVar34 * 8 |
                 uVar12 & 0xffffffffU >> (4 - uVar34) * 8) & -1 << (uVar11 + 1) * 8 |
                 *(uint *)(pbVar44 + -5 + -uVar11) >> (3 - uVar11) * 8;
        uVar12 = (uint)(pbVar44 + -1) & 3;
        uVar34 = (*(int *)(pbVar44 + -4 + -uVar32) << uVar32 * 8 |
                 (uint)in_t0 & 0xffffffffU >> (4 - uVar32) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)(pbVar44 + -1 + -uVar12) >> (3 - uVar12) * 8;
        uVar12 = (uint)(pbVar44 + -0xd) & 3;
        pppppppbStack_e4 =
             (byte *******)
             ((*(int *)(pbVar43 + -uVar18) << uVar18 * 8 |
              (uint)in_t1 & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)(pbVar44 + -0xd + -uVar12) >> (3 - uVar12) * 8);
        uVar12 = (uint)(pbVar44 + -5) & 3;
        ppppppppbStack_dc =
             (byte ********)
             ((*(int *)(pbVar44 + -8 + -uVar3) << uVar3 * 8 |
              (uint)in_t3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)(pbVar44 + -5 + -uVar12) >> (3 - uVar12) * 8);
        uVar12 = (uint)(pbVar44 + -1) & 3;
        ppppppppbStack_d8 =
             (byte ********)
             ((*(int *)(pbVar44 + -4 + -uVar35) << uVar35 * 8 |
              (uint)in_t2 & 0xffffffffU >> (4 - uVar35) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)(pbVar44 + -1 + -uVar12) >> (3 - uVar12) * 8);
        bStack_149 = (byte)(uVar11 >> 0x18);
        bVar4 = (byte)(uVar11 >> 8) ^ *(byte *)((int)ppppppppbVar23 + 10);
        pppppppbStack_f4 =
             (byte *******)
             CONCAT31(CONCAT21(CONCAT11((byte)(uVar30 >> 0x18) ^ *(byte *)ppppppppbVar23,
                                        (byte)(uVar30 >> 0x10) ^ *(byte *)((int)ppppppppbVar23 + 1))
                               ,(byte)(uVar30 >> 8) ^ *(byte *)((int)ppppppppbVar23 + 2)),
                      (byte)uVar30 ^ *(byte *)((int)ppppppppbVar23 + 3));
        uStack_130._3_1_ = (byte)(uVar34 >> 0x18);
        uStack_f0 = (byte *******)
                    CONCAT31(CONCAT21(CONCAT11((byte)(uVar16 >> 0x18) ^
                                               *(byte *)(ppppppppbVar23 + 1),
                                               (byte)(uVar16 >> 0x10) ^
                                               *(byte *)((int)ppppppppbVar23 + 5)),
                                      (byte)(uVar16 >> 8) ^ *(byte *)((int)ppppppppbVar23 + 6)),
                             (byte)uVar16 ^ *(byte *)((int)ppppppppbVar23 + 7));
        uStack_e8._2_2_ =
             ((ushort)bVar20 ^ (ushort)uVar34) & 0xff |
             (ushort)(byte)((byte)(uVar34 >> 8) ^ *(byte *)((int)ppppppppbVar23 + 0xe)) << 8;
        uStack_ec = (byte ********)
                    CONCAT22(CONCAT11(bStack_149 ^ *(byte *)(ppppppppbVar23 + 2),
                                      (byte)(uVar11 >> 0x10) ^ *(byte *)((int)ppppppppbVar23 + 9)),
                             CONCAT11(bVar4,(byte)uVar11 ^ *(byte *)((int)ppppppppbVar23 + 0xb)));
        uStack_e8._1_3_ =
             CONCAT12((byte)(uVar34 >> 0x10) ^ *(byte *)((int)ppppppppbVar23 + 0xd),uStack_e8._2_2_)
        ;
        uStack_e8 = (byte ********)
                    CONCAT13((byte)uStack_130 ^ *(byte *)(ppppppppbVar23 + 3),uStack_e8._1_3_);
        (*(code *)PTR_AES_decrypt_006a95f8)(&pppppppbStack_f4,ppppppppbVar17,pAVar29);
        *(byte *)ppppppppbVar17 = *(byte *)ppppppppbVar17 ^ *(byte *)ppppppppbVar9;
        *(byte *)((int)ppppppppbVar6 + -0xf) =
             *(byte *)((int)ppppppppbVar6 + -0xf) ^ *(byte *)((int)ppppppppbVar9 + 1);
        bVar1 = *(byte *)((int)ppppppppbVar9 + 2);
        *(byte *)((int)ppppppppbVar6 + -0xe) = *(byte *)((int)ppppppppbVar6 + -0xe) ^ bVar1;
        in_t3 = (byte ********)(uint)*(byte *)((int)ppppppppbVar9 + 3);
        uVar12 = (uint)(pbVar43 + uVar10 < &SUB_00000010);
        *(byte *)((int)ppppppppbVar6 + -0xd) =
             *(byte *)((int)ppppppppbVar6 + -0xd) ^ *(byte *)((int)ppppppppbVar9 + 3);
        in_t2 = (byte ********)(uint)*(byte *)(ppppppppbVar9 + 1);
        *(byte *)(ppppppppbVar6 + -3) = *(byte *)(ppppppppbVar6 + -3) ^ *(byte *)(ppppppppbVar9 + 1)
        ;
        in_t1 = (byte ********)(uint)*(byte *)((int)ppppppppbVar9 + 5);
        *(byte *)((int)ppppppppbVar6 + -0xb) =
             *(byte *)((int)ppppppppbVar6 + -0xb) ^ *(byte *)((int)ppppppppbVar9 + 5);
        in_t0 = (byte ********)(uint)*(byte *)((int)ppppppppbVar9 + 6);
        *(byte *)((int)ppppppppbVar6 + -10) =
             *(byte *)((int)ppppppppbVar6 + -10) ^ *(byte *)((int)ppppppppbVar9 + 6);
        *(byte *)((int)ppppppppbVar6 + -9) =
             *(byte *)((int)ppppppppbVar6 + -9) ^ *(byte *)((int)ppppppppbVar9 + 7);
        *(byte *)(ppppppppbVar6 + -2) = *(byte *)(ppppppppbVar6 + -2) ^ *(byte *)(ppppppppbVar9 + 2)
        ;
        *(byte *)((int)ppppppppbVar6 + -7) =
             *(byte *)((int)ppppppppbVar6 + -7) ^ *(byte *)((int)ppppppppbVar9 + 9);
        *(byte *)((int)ppppppppbVar6 + -6) =
             *(byte *)((int)ppppppppbVar6 + -6) ^ *(byte *)((int)ppppppppbVar9 + 10);
        *(byte *)((int)ppppppppbVar6 + -5) =
             *(byte *)((int)ppppppppbVar6 + -5) ^ *(byte *)((int)ppppppppbVar9 + 0xb);
        pAVar31 = (AES_KEY *)(uint)*(byte *)(ppppppppbVar9 + 3);
        *(byte *)(ppppppppbVar6 + -1) = *(byte *)(ppppppppbVar6 + -1) ^ *(byte *)(ppppppppbVar9 + 3)
        ;
        *(byte *)((int)ppppppppbVar6 + -3) =
             *(byte *)((int)ppppppppbVar6 + -3) ^ *(byte *)((int)ppppppppbVar9 + 0xd);
        *(byte *)((int)ppppppppbVar6 + -2) =
             *(byte *)((int)ppppppppbVar6 + -2) ^ *(byte *)((int)ppppppppbVar9 + 0xe);
        pppppppbStack_d4 = pppppppbStack_e4;
        bVar20 = *(byte *)((int)ppppppppbVar6 + -1) ^ *(byte *)((int)ppppppppbVar9 + 0xf);
        ppppppppbStack_cc = ppppppppbStack_dc;
        *(byte *)((int)ppppppppbVar6 + -1) = bVar20;
        pppppppbStack_d0 = pppppppbStack_e0;
        ppppppppbStack_c8 = ppppppppbStack_d8;
        ppppppppbVar6 = ppppppppbVar17;
        pbVar44 = pbVar43;
        ppppppppbVar9 = &pppppppbStack_d4;
        ppppppppbVar23 = ppppppppbVar17;
      } while (uVar12 == 0);
      bVar20 = *(byte *)((int)ppppppppbStack_84 + 0x1b);
      bVar46 = *(byte *)(ppppppppbStack_84 + 6);
      bVar2 = *(byte *)((int)ppppppppbStack_84 + 0x13);
      bVar48 = *(byte *)((int)ppppppppbStack_84 + 0x1f);
      bVar49 = *(byte *)(ppppppppbStack_84 + 4);
      bVar52 = *(byte *)((int)ppppppppbStack_84 + 0x12);
      bVar42 = *(byte *)((int)ppppppppbStack_84 + 0x17);
      bVar45 = *(byte *)(ppppppppbStack_84 + 5);
      bVar51 = *(byte *)((int)ppppppppbStack_84 + 0x16);
      bVar41 = *(byte *)((int)ppppppppbStack_84 + 0x19);
      bVar40 = *(byte *)((int)ppppppppbStack_84 + 0x1a);
      uStack_130 = (byte ********)(uint)*(byte *)((int)ppppppppbStack_84 + 0x1d);
      ppppppppbVar17 = (byte ********)(uint)*(byte *)((int)ppppppppbStack_84 + 0x15);
      bVar14 = *(byte *)((int)ppppppppbStack_84 + 0x11);
      pAVar38 = (AES_KEY *)(uint)bVar1;
      ppppppppbVar6 = (byte ********)(uint)*(byte *)((int)ppppppppbStack_84 + 0x1e);
      ppppppppbVar9 = ppppppppbVar26 + ~((uint)(ppppppppbStack_90 + -4) >> 4) * 4;
      ppppppppbVar23 = (byte ********)(uint)bVar4;
      ppppppppbVar26 = ppppppppbVar17;
      pAStack_144 = (AES_KEY *)(uint)*(byte *)(ppppppppbStack_84 + 7);
      ppppppppbStack_104 = ppppppppbStack_90 + -4;
      while( true ) {
        pppppppbVar7 = *ppppppppbVar9;
        uVar12 = (uint)(ppppppppbVar9 + 2) & 3;
        uVar10 = (uint)(ppppppppbVar9 + 1) & 3;
        uVar18 = (uint)(ppppppppbVar9 + 2) & 3;
        uVar11 = (uint)(ppppppppbVar9 + 3) & 3;
        uVar16 = (uint)(ppppppppbVar9 + 1) & 3;
        uVar34 = (uint)(ppppppppbVar9 + 3) & 3;
        uVar32 = (uint)(byte *)((int)ppppppppbVar9 + 0xb) & 3;
        ppppppppbStack_dc =
             (byte ********)
             ((*(int *)((int)(ppppppppbVar9 + 2) - uVar12) << uVar12 * 8 |
              (uint)in_t2 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar32 + 1) * 8 |
             *(uint *)((byte *)((int)ppppppppbVar9 + 0xb) + -uVar32) >> (3 - uVar32) * 8);
        uVar12 = (uint)(byte *)((int)ppppppppbVar9 + 7) & 3;
        uVar35 = (*(int *)((int)(ppppppppbVar9 + 1) - uVar10) << uVar10 * 8 |
                 (uint)in_t0 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)((byte *)((int)ppppppppbVar9 + 7) + -uVar12) >> (3 - uVar12) * 8;
        uVar12 = (uint)(byte *)((int)ppppppppbVar9 + 0xb) & 3;
        uVar32 = (*(int *)((int)(ppppppppbVar9 + 2) - uVar18) << uVar18 * 8 |
                 (uint)pAVar31 & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)((byte *)((int)ppppppppbVar9 + 0xb) + -uVar12) >> (3 - uVar12) * 8;
        uVar12 = (uint)(byte *)((int)ppppppppbVar9 + 0xf) & 3;
        uVar18 = (*(int *)((int)(ppppppppbVar9 + 3) - uVar11) << uVar11 * 8 |
                 (uint)ppppppppbVar17 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar12 + 1) * 8 |
                 *(uint *)((byte *)((int)ppppppppbVar9 + 0xf) + -uVar12) >> (3 - uVar12) * 8;
        uVar12 = (uint)(byte *)((int)ppppppppbVar9 + 7) & 3;
        pppppppbStack_e0 =
             (byte *******)
             ((*(int *)((int)(ppppppppbVar9 + 1) - uVar16) << uVar16 * 8 |
              (uint)in_t3 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar12 + 1) * 8 |
             *(uint *)((byte *)((int)ppppppppbVar9 + 7) + -uVar12) >> (3 - uVar12) * 8);
        uVar12 = (uint)ppppppppbVar9 & 3;
        uVar10 = (uint)(byte *)((int)ppppppppbVar9 + 0xf) & 3;
        ppppppppbStack_d8 =
             (byte ********)
             ((*(int *)((int)(ppppppppbVar9 + 3) - uVar34) << uVar34 * 8 |
              (uint)ppppppppbVar23 & 0xffffffffU >> (4 - uVar34) * 8) & -1 << (uVar10 + 1) * 8 |
             *(uint *)((byte *)((int)ppppppppbVar9 + 0xf) + -uVar10) >> (3 - uVar10) * 8);
        uVar10 = (uint)(byte *)((int)ppppppppbVar9 + 3) & 3;
        pppppppbStack_e4 =
             (byte *******)
             ((*(int *)((int)ppppppppbVar9 - uVar12) << uVar12 * 8 |
              (uint)pAVar38 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar10 + 1) * 8 |
             *(uint *)((byte *)((int)ppppppppbVar9 + 3) + -uVar10) >> (3 - uVar10) * 8);
        bStack_139 = (byte)((uint)pppppppbVar7 >> 0x18);
        uStack_f0._1_3_ = (uint3)(byte)(bVar51 ^ (byte)(uVar35 >> 8)) << 8;
        pppppppbStack_f4 =
             (byte *******)
             CONCAT31(CONCAT21(CONCAT11(bVar49 ^ bStack_139,
                                        bVar14 ^ (byte)((uint)pppppppbVar7 >> 0x10)),
                               bVar52 ^ (byte)((uint)pppppppbVar7 >> 8)),bVar2 ^ (byte)pppppppbVar7)
        ;
        uStack_f0._1_3_ =
             uStack_f0._1_3_ | (uint3)(byte)((byte)ppppppppbVar26 ^ (byte)(uVar35 >> 0x10)) << 0x10;
        uStack_f0 = (byte *******)CONCAT13(bVar45 ^ (byte)(uVar35 >> 0x18),uStack_f0._1_3_);
        uStack_f0 = (byte *******)((uint)uStack_f0 | (uint)(byte)(bVar42 ^ (byte)uVar35));
        uStack_ec = (byte ********)
                    CONCAT31(CONCAT21(CONCAT11(bVar46 ^ (byte)(uVar32 >> 0x18),
                                               bVar41 ^ (byte)(uVar32 >> 0x10)),
                                      bVar40 ^ (byte)(uVar32 >> 8)),bVar20 ^ (byte)uVar32);
        uStack_e8._2_2_ = CONCAT11((byte)ppppppppbVar6 ^ (byte)(uVar18 >> 8),bVar48 ^ (byte)uVar18);
        uStack_e8._1_3_ = CONCAT12((byte)uStack_130 ^ (byte)(uVar18 >> 0x10),uStack_e8._2_2_);
        uStack_e8 = (byte ********)
                    CONCAT13((byte)pAStack_144 ^ (byte)(uVar18 >> 0x18),uStack_e8._1_3_);
        (*(code *)PTR_AES_decrypt_006a95f8)(&pppppppbStack_f4,ppppppppbVar9,pAVar29);
        bVar49 = *(byte *)ppppppppbVar9 ^ *(byte *)ppppppppbStack_84;
        *(byte *)ppppppppbVar9 = bVar49;
        bVar14 = *(byte *)((int)ppppppppbVar9 + 1) ^ *(byte *)((int)ppppppppbStack_84 + 1);
        *(byte *)((int)ppppppppbVar9 + 1) = bVar14;
        bVar52 = *(byte *)((int)ppppppppbVar9 + 2) ^ *(byte *)((int)ppppppppbStack_84 + 2);
        *(byte *)((int)ppppppppbVar9 + 2) = bVar52;
        bVar2 = *(byte *)((int)ppppppppbVar9 + 3) ^ *(byte *)((int)ppppppppbStack_84 + 3);
        *(byte *)((int)ppppppppbVar9 + 3) = bVar2;
        bVar45 = *(byte *)(ppppppppbVar9 + 1) ^ *(byte *)(ppppppppbStack_84 + 1);
        *(byte *)(ppppppppbVar9 + 1) = bVar45;
        bVar20 = *(byte *)((int)ppppppppbVar9 + 5) ^ *(byte *)((int)ppppppppbStack_84 + 5);
        ppppppppbVar26 = (byte ********)(uint)bVar20;
        *(byte *)((int)ppppppppbVar9 + 5) = bVar20;
        bVar51 = *(byte *)((int)ppppppppbVar9 + 6) ^ *(byte *)((int)ppppppppbStack_84 + 6);
        *(byte *)((int)ppppppppbVar9 + 6) = bVar51;
        bVar42 = *(byte *)((int)ppppppppbVar9 + 7) ^ *(byte *)((int)ppppppppbStack_84 + 7);
        *(byte *)((int)ppppppppbVar9 + 7) = bVar42;
        bVar46 = *(byte *)(ppppppppbVar9 + 2) ^ *(byte *)(ppppppppbStack_84 + 2);
        *(byte *)(ppppppppbVar9 + 2) = bVar46;
        in_t0 = (byte ********)(uint)*(byte *)(ppppppppbVar9 + 3);
        bVar41 = *(byte *)((int)ppppppppbVar9 + 9) ^ *(byte *)((int)ppppppppbStack_84 + 9);
        *(byte *)((int)ppppppppbVar9 + 9) = bVar41;
        bVar40 = *(byte *)((int)ppppppppbVar9 + 10) ^ *(byte *)((int)ppppppppbStack_84 + 10);
        *(byte *)((int)ppppppppbVar9 + 10) = bVar40;
        bVar20 = *(byte *)((int)ppppppppbVar9 + 0xb) ^ *(byte *)((int)ppppppppbStack_84 + 0xb);
        *(byte *)((int)ppppppppbVar9 + 0xb) = bVar20;
        bVar1 = *(byte *)(ppppppppbVar9 + 3) ^ *(byte *)(ppppppppbStack_84 + 3);
        pAVar31 = (AES_KEY *)(uint)bVar1;
        *(byte *)(ppppppppbVar9 + 3) = bVar1;
        bVar1 = *(byte *)((int)ppppppppbVar9 + 0xd) ^ *(byte *)((int)ppppppppbStack_84 + 0xd);
        in_t3 = (byte ********)(uint)bVar1;
        *(byte *)((int)ppppppppbVar9 + 0xd) = bVar1;
        pppppppbStack_d4 = pppppppbStack_e4;
        bVar1 = *(byte *)((int)ppppppppbVar9 + 0xe) ^ *(byte *)((int)ppppppppbStack_84 + 0xe);
        in_t2 = (byte ********)(uint)bVar1;
        *(byte *)((int)ppppppppbVar9 + 0xe) = bVar1;
        bVar48 = *(byte *)((int)ppppppppbVar9 + 0xf) ^ *(byte *)((int)ppppppppbStack_84 + 0xf);
        pppppppbStack_d0 = pppppppbStack_e0;
        ppppppppbStack_cc = ppppppppbStack_dc;
        ppppppppbStack_c8 = ppppppppbStack_d8;
        *(byte *)((int)ppppppppbVar9 + 0xf) = bVar48;
        pcVar21 = (char *)ppppppppbStack_d8;
        ppppppppbVar6 = ppppppppbStack_dc;
        pcVar28 = (char *)pppppppbStack_e0;
        if (ppppppppbStack_104 < &SUB_00000010) break;
        ppppppppbVar17 = ppppppppbStack_104 + -4;
        pAVar38 = pAVar31;
        ppppppppbVar6 = in_t2;
        ppppppppbVar9 = ppppppppbVar9 + 4;
        ppppppppbStack_84 = &pppppppbStack_d4;
        ppppppppbVar23 = ppppppppbStack_104;
        pAStack_144 = pAVar31;
        uStack_130 = in_t3;
        ppppppppbStack_104 = ppppppppbVar17;
      }
    }
  }
  if (iStack_c4 != *(int *)puVar5) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (((byte ********)pcVar21 != (byte ********)0x0) &&
       ((byte *******)pcVar28 != (byte *******)0x0)) {
      if (ppppppppbVar6 == (byte ********)&DAT_00000080) {
        *(byte *******)((int)pcVar28 + 0xf0) = (byte ******)0xa;
      }
      else if (ppppppppbVar6 == (byte ********)&DAT_000000c0) {
        *(byte *******)((int)pcVar28 + 0xf0) = (byte ******)0xc;
      }
      else {
        if (ppppppppbVar6 != (byte ********)0x100) {
          return;
        }
        *(byte *******)((int)pcVar28 + 0xf0) = (byte ******)0xe;
      }
      ppppppbVar19 = (byte ******)
                     ((uint)(byte)*pcVar21 << 0x18 ^ (uint)*(byte *)((int)pcVar21 + 1) << 0x10 ^
                      (uint)*(byte *)((int)pcVar21 + 3) ^ (uint)*(byte *)((int)pcVar21 + 2) << 8);
      *(byte *******)pcVar28 = ppppppbVar19;
      ppppppbVar37 = (byte ******)
                     ((uint)*(byte *)((int)pcVar21 + 4) << 0x18 ^
                      (uint)*(byte *)((int)pcVar21 + 5) << 0x10 ^ (uint)*(byte *)((int)pcVar21 + 7)
                     ^ (uint)*(byte *)((int)pcVar21 + 6) << 8);
      *(byte *******)((int)pcVar28 + 4) = ppppppbVar37;
      ppppppbVar36 = (byte ******)
                     ((uint)*(byte *)((int)pcVar21 + 8) << 0x18 ^
                      (uint)*(byte *)((int)pcVar21 + 9) << 0x10 ^
                      (uint)*(byte *)((int)pcVar21 + 0xb) ^ (uint)*(byte *)((int)pcVar21 + 10) << 8)
      ;
      *(byte *******)((int)pcVar28 + 8) = ppppppbVar36;
      bVar20 = *(byte *)((int)pcVar21 + 0xc);
      ppppppbVar13 = (byte ******)
                     ((uint)bVar20 << 0x18 ^ (uint)*(byte *)((int)pcVar21 + 0xd) << 0x10 ^
                      (uint)*(byte *)((int)pcVar21 + 0xf) ^ (uint)*(byte *)((int)pcVar21 + 0xe) << 8
                     );
      *(byte *******)((int)pcVar28 + 0xc) = ppppppbVar13;
      if (ppppppppbVar6 == (byte ********)&DAT_00000080) {
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x1000000 ^ (uint)(byte)Te1[(uint)bVar20 * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar19 ^ (uint)ppppppbVar37);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 0x10) = ppppppbVar19;
        ppppppbVar13 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar13);
        *(byte *******)((int)pcVar28 + 0x14) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0x18) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0x1c) = ppppppbVar13;
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x2000000 ^
                        (uint)(byte)Te1[((uint)ppppppbVar13 >> 0x18) * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar19 ^ (uint)ppppppbVar37);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 0x20) = ppppppbVar19;
        ppppppbVar13 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar13);
        *(byte *******)((int)pcVar28 + 0x24) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0x28) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0x2c) = ppppppbVar13;
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x4000000 ^
                        (uint)(byte)Te1[((uint)ppppppbVar13 >> 0x18) * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar19 ^ (uint)ppppppbVar37);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 0x30) = ppppppbVar19;
        ppppppbVar13 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar13);
        *(byte *******)((int)pcVar28 + 0x34) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0x38) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0x3c) = ppppppbVar13;
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x8000000 ^
                        (uint)(byte)Te1[((uint)ppppppbVar13 >> 0x18) * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar19 ^ (uint)ppppppbVar37);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 0x40) = ppppppbVar19;
        ppppppbVar13 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar13);
        *(byte *******)((int)pcVar28 + 0x44) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0x48) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0x4c) = ppppppbVar13;
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x10000000 ^
                        (uint)(byte)Te1[((uint)ppppppbVar13 >> 0x18) * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar19 ^ (uint)ppppppbVar37);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 0x50) = ppppppbVar19;
        ppppppbVar13 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar13);
        *(byte *******)((int)pcVar28 + 0x54) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0x58) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0x5c) = ppppppbVar13;
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x20000000 ^
                        (uint)(byte)Te1[((uint)ppppppbVar13 >> 0x18) * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
        *(byte *******)((int)pcVar28 + 0x60) = ppppppbVar19;
        ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 100) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0x68) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0x6c) = ppppppbVar13;
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x40000000 ^
                        (uint)(byte)Te1[((uint)ppppppbVar13 >> 0x18) * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
        *(byte *******)((int)pcVar28 + 0x70) = ppppppbVar19;
        ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 0x74) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0x78) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0x7c) = ppppppbVar13;
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x80000000 ^
                        (uint)(byte)Te1[((uint)ppppppbVar13 >> 0x18) * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
        *(byte *******)((int)pcVar28 + 0x80) = ppppppbVar19;
        ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 0x84) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0x88) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0x8c) = ppppppbVar13;
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x1b000000 ^
                        (uint)(byte)Te1[((uint)ppppppbVar13 >> 0x18) * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
        *(byte *******)((int)pcVar28 + 0x90) = ppppppbVar19;
        ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 0x94) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0x98) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0x9c) = ppppppbVar13;
        ppppppbVar19 = (byte ******)
                       (*(uint *)(Te0 + ((uint)ppppppbVar13 & 0xff) * 4) & 0xff00 ^
                        (uint)ppppppbVar19 ^ 0x36000000 ^
                        (uint)(byte)Te1[((uint)ppppppbVar13 >> 0x18) * 4 + 3] ^
                        *(uint *)(Te2 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) & 0xff000000 ^
                       *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) & 0xff0000);
        ppppppbVar37 = (byte ******)((uint)ppppppbVar19 ^ (uint)ppppppbVar37);
        ppppppbVar36 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar36);
        *(byte *******)((int)pcVar28 + 0xa0) = ppppppbVar19;
        *(byte *******)((int)pcVar28 + 0xa4) = ppppppbVar37;
        *(byte *******)((int)pcVar28 + 0xa8) = ppppppbVar36;
        *(byte *******)((int)pcVar28 + 0xac) =
             (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar13);
      }
      else {
        ppppppbVar50 = (byte ******)
                       ((uint)*(byte *)((int)pcVar21 + 0x10) << 0x18 ^
                        (uint)*(byte *)((int)pcVar21 + 0x11) << 0x10 ^
                        (uint)*(byte *)((int)pcVar21 + 0x13) ^
                       (uint)*(byte *)((int)pcVar21 + 0x12) << 8);
        *(byte *******)((int)pcVar28 + 0x10) = ppppppbVar50;
        bVar20 = *(byte *)((int)pcVar21 + 0x14);
        ppppppbVar33 = (byte ******)
                       ((uint)bVar20 << 0x18 ^ (uint)*(byte *)((int)pcVar21 + 0x15) << 0x10 ^
                        (uint)*(byte *)((int)pcVar21 + 0x17) ^
                       (uint)*(byte *)((int)pcVar21 + 0x16) << 8);
        *(byte *******)((int)pcVar28 + 0x14) = ppppppbVar33;
        if (ppppppppbVar6 == (byte ********)&DAT_000000c0) {
          ppppppbVar19 = (byte ******)
                         (*(uint *)(Te0 + ((uint)ppppppbVar33 & 0xff) * 4) & 0xff00 ^
                          (uint)ppppppbVar19 ^ 0x1000000 ^ (uint)(byte)Te1[(uint)bVar20 * 4 + 3] ^
                          *(uint *)(Te2 + ((uint)((int)ppppppbVar33 << 8) >> 0x18) * 4) & 0xff000000
                         ^ *(uint *)(Te3 + ((uint)((int)ppppppbVar33 << 0x10) >> 0x18) * 4) &
                           0xff0000);
          ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
          ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
          *(byte *******)((int)pcVar28 + 0x18) = ppppppbVar19;
          ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
          *(byte *******)((int)pcVar28 + 0x1c) = ppppppbVar37;
          ppppppbVar50 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x20) = ppppppbVar36;
          ppppppbVar33 = (byte ******)((uint)ppppppbVar33 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x24) = ppppppbVar13;
          *(byte *******)((int)pcVar28 + 0x28) = ppppppbVar50;
          *(byte *******)((int)pcVar28 + 0x2c) = ppppppbVar33;
          ppppppbVar19 = (byte ******)
                         (*(uint *)(Te0 + ((uint)ppppppbVar33 & 0xff) * 4) & 0xff00 ^
                          (uint)(byte)Te1[((uint)ppppppbVar33 >> 0x18) * 4 + 3] ^ 0x2000000 ^
                          *(uint *)(Te2 + ((uint)((int)ppppppbVar33 << 8) >> 0x18) * 4) & 0xff000000
                          ^ *(uint *)(Te3 + ((uint)((int)ppppppbVar33 << 0x10) >> 0x18) * 4) &
                            0xff0000 ^ (uint)ppppppbVar19);
          ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
          ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
          *(byte *******)((int)pcVar28 + 0x30) = ppppppbVar19;
          ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
          *(byte *******)((int)pcVar28 + 0x34) = ppppppbVar37;
          ppppppbVar50 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x38) = ppppppbVar36;
          ppppppbVar33 = (byte ******)((uint)ppppppbVar33 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x3c) = ppppppbVar13;
          *(byte *******)((int)pcVar28 + 0x40) = ppppppbVar50;
          *(byte *******)((int)pcVar28 + 0x44) = ppppppbVar33;
          ppppppbVar19 = (byte ******)
                         (*(uint *)(Te0 + ((uint)ppppppbVar33 & 0xff) * 4) & 0xff00 ^
                          (uint)(byte)Te1[((uint)ppppppbVar33 >> 0x18) * 4 + 3] ^ 0x4000000 ^
                          *(uint *)(Te2 + ((uint)((int)ppppppbVar33 << 8) >> 0x18) * 4) & 0xff000000
                          ^ *(uint *)(Te3 + ((uint)((int)ppppppbVar33 << 0x10) >> 0x18) * 4) &
                            0xff0000 ^ (uint)ppppppbVar19);
          ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
          ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
          *(byte *******)((int)pcVar28 + 0x48) = ppppppbVar19;
          ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
          *(byte *******)((int)pcVar28 + 0x4c) = ppppppbVar37;
          ppppppbVar50 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x50) = ppppppbVar36;
          ppppppbVar33 = (byte ******)((uint)ppppppbVar33 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x54) = ppppppbVar13;
          *(byte *******)((int)pcVar28 + 0x58) = ppppppbVar50;
          *(byte *******)((int)pcVar28 + 0x5c) = ppppppbVar33;
          ppppppbVar19 = (byte ******)
                         (*(uint *)(Te0 + ((uint)ppppppbVar33 & 0xff) * 4) & 0xff00 ^
                          (uint)(byte)Te1[((uint)ppppppbVar33 >> 0x18) * 4 + 3] ^ 0x8000000 ^
                          *(uint *)(Te2 + ((uint)((int)ppppppbVar33 << 8) >> 0x18) * 4) & 0xff000000
                          ^ *(uint *)(Te3 + ((uint)((int)ppppppbVar33 << 0x10) >> 0x18) * 4) &
                            0xff0000 ^ (uint)ppppppbVar19);
          ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
          ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
          *(byte *******)((int)pcVar28 + 0x60) = ppppppbVar19;
          ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
          *(byte *******)((int)pcVar28 + 100) = ppppppbVar37;
          ppppppbVar50 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x68) = ppppppbVar36;
          ppppppbVar33 = (byte ******)((uint)ppppppbVar33 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x6c) = ppppppbVar13;
          *(byte *******)((int)pcVar28 + 0x70) = ppppppbVar50;
          *(byte *******)((int)pcVar28 + 0x74) = ppppppbVar33;
          ppppppbVar19 = (byte ******)
                         (*(uint *)(Te0 + ((uint)ppppppbVar33 & 0xff) * 4) & 0xff00 ^
                          (uint)(byte)Te1[((uint)ppppppbVar33 >> 0x18) * 4 + 3] ^ 0x10000000 ^
                          *(uint *)(Te2 + ((uint)((int)ppppppbVar33 << 8) >> 0x18) * 4) & 0xff000000
                          ^ *(uint *)(Te3 + ((uint)((int)ppppppbVar33 << 0x10) >> 0x18) * 4) &
                            0xff0000 ^ (uint)ppppppbVar19);
          ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
          ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
          *(byte *******)((int)pcVar28 + 0x78) = ppppppbVar19;
          ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
          *(byte *******)((int)pcVar28 + 0x7c) = ppppppbVar37;
          ppppppbVar50 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x80) = ppppppbVar36;
          ppppppbVar33 = (byte ******)((uint)ppppppbVar33 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x84) = ppppppbVar13;
          *(byte *******)((int)pcVar28 + 0x88) = ppppppbVar50;
          *(byte *******)((int)pcVar28 + 0x8c) = ppppppbVar33;
          ppppppbVar19 = (byte ******)
                         (*(uint *)(Te0 + ((uint)ppppppbVar33 & 0xff) * 4) & 0xff00 ^
                          (uint)(byte)Te1[((uint)ppppppbVar33 >> 0x18) * 4 + 3] ^ 0x20000000 ^
                          *(uint *)(Te2 + ((uint)((int)ppppppbVar33 << 8) >> 0x18) * 4) & 0xff000000
                          ^ *(uint *)(Te3 + ((uint)((int)ppppppbVar33 << 0x10) >> 0x18) * 4) &
                            0xff0000 ^ (uint)ppppppbVar19);
          ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
          ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
          *(byte *******)((int)pcVar28 + 0x90) = ppppppbVar19;
          ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
          *(byte *******)((int)pcVar28 + 0x94) = ppppppbVar37;
          ppppppbVar50 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x98) = ppppppbVar36;
          ppppppbVar33 = (byte ******)((uint)ppppppbVar33 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0x9c) = ppppppbVar13;
          *(byte *******)((int)pcVar28 + 0xa0) = ppppppbVar50;
          *(byte *******)((int)pcVar28 + 0xa4) = ppppppbVar33;
          ppppppbVar19 = (byte ******)
                         (*(uint *)(Te0 + ((uint)ppppppbVar33 & 0xff) * 4) & 0xff00 ^
                          (uint)(byte)Te1[((uint)ppppppbVar33 >> 0x18) * 4 + 3] ^ 0x40000000 ^
                          *(uint *)(Te2 + ((uint)((int)ppppppbVar33 << 8) >> 0x18) * 4) & 0xff000000
                          ^ *(uint *)(Te3 + ((uint)((int)ppppppbVar33 << 0x10) >> 0x18) * 4) &
                            0xff0000 ^ (uint)ppppppbVar19);
          ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
          ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
          *(byte *******)((int)pcVar28 + 0xa8) = ppppppbVar19;
          ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
          *(byte *******)((int)pcVar28 + 0xac) = ppppppbVar37;
          *(byte *******)((int)pcVar28 + 0xb0) = ppppppbVar36;
          ppppppbVar33 = (byte ******)
                         ((uint)ppppppbVar33 ^
                         (uint)(byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar50));
          *(byte *******)((int)pcVar28 + 0xb4) = ppppppbVar13;
          *(byte *******)((int)pcVar28 + 0xb8) =
               (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar50);
          *(byte *******)((int)pcVar28 + 0xbc) = ppppppbVar33;
          ppppppbVar19 = (byte ******)
                         (*(uint *)(Te0 + ((uint)ppppppbVar33 & 0xff) * 4) & 0xff00 ^
                          (uint)(byte)Te1[((uint)ppppppbVar33 >> 0x18) * 4 + 3] ^ 0x80000000 ^
                          *(uint *)(Te2 + ((uint)((int)ppppppbVar33 << 8) >> 0x18) * 4) & 0xff000000
                          ^ *(uint *)(Te3 + ((uint)((int)ppppppbVar33 << 0x10) >> 0x18) * 4) &
                            0xff0000 ^ (uint)ppppppbVar19);
          ppppppbVar37 = (byte ******)((uint)ppppppbVar19 ^ (uint)ppppppbVar37);
          ppppppbVar36 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar36);
          *(byte *******)((int)pcVar28 + 0xc0) = ppppppbVar19;
          *(byte *******)((int)pcVar28 + 0xc4) = ppppppbVar37;
          *(byte *******)((int)pcVar28 + 200) = ppppppbVar36;
          *(byte *******)((int)pcVar28 + 0xcc) =
               (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar13);
        }
        else {
          *(byte *******)((int)pcVar28 + 0x18) =
               (byte ******)
               ((uint)*(byte *)((int)pcVar21 + 0x18) << 0x18 ^
                (uint)*(byte *)((int)pcVar21 + 0x19) << 0x10 ^ (uint)*(byte *)((int)pcVar21 + 0x1b)
               ^ (uint)*(byte *)((int)pcVar21 + 0x1a) << 8);
          *(byte *******)((int)pcVar28 + 0x1c) =
               (byte ******)
               ((uint)*(byte *)((int)pcVar21 + 0x1c) << 0x18 ^
                (uint)*(byte *)((int)pcVar21 + 0x1d) << 0x10 ^ (uint)*(byte *)((int)pcVar21 + 0x1f)
               ^ (uint)*(byte *)((int)pcVar21 + 0x1e) << 8);
          if (ppppppppbVar6 == (byte ********)0x100) {
            pppppppbVar7 = (byte *******)pcVar28;
            puVar39 = (uint *)rcon;
            while( true ) {
              ppppppbVar33 = pppppppbVar7[7];
              ppppppbVar19 = (byte ******)
                             (*(uint *)(Te0 + ((uint)ppppppbVar33 & 0xff) * 4) & 0xff00 ^
                              (uint)ppppppbVar19 ^ *puVar39 ^
                              (uint)(byte)Te1[((uint)ppppppbVar33 >> 0x18) * 4 + 3] ^
                              *(uint *)(Te2 + ((uint)((int)ppppppbVar33 << 8) >> 0x18) * 4) &
                              0xff000000 ^
                             *(uint *)(Te3 + ((uint)((int)ppppppbVar33 << 0x10) >> 0x18) * 4) &
                             0xff0000);
              ppppppbVar37 = (byte ******)((uint)ppppppbVar37 ^ (uint)ppppppbVar19);
              ppppppbVar36 = (byte ******)((uint)ppppppbVar36 ^ (uint)ppppppbVar37);
              pppppppbVar7[8] = ppppppbVar19;
              ppppppbVar13 = (byte ******)((uint)ppppppbVar13 ^ (uint)ppppppbVar36);
              pppppppbVar7[9] = ppppppbVar37;
              pppppppbVar7[10] = ppppppbVar36;
              pppppppbVar7[0xb] = ppppppbVar13;
              if (pppppppbVar7 == (byte *******)((int)pcVar28 + 0xc0)) break;
              ppppppbVar27 = (byte ******)
                             (*(uint *)(Te2 + ((uint)ppppppbVar13 >> 0x18) * 4) & 0xff000000 ^
                              (uint)(byte)Te1[((uint)ppppppbVar13 & 0xff) * 4 + 3] ^
                              (uint)pppppppbVar7[4] ^
                              *(uint *)(Te3 + ((uint)((int)ppppppbVar13 << 8) >> 0x18) * 4) &
                              0xff0000 ^
                             *(uint *)(Te0 + ((uint)((int)ppppppbVar13 << 0x10) >> 0x18) * 4) &
                             0xff00);
              ppppppbVar24 = (byte ******)((uint)ppppppbVar27 ^ (uint)pppppppbVar7[5]);
              ppppppbVar50 = (byte ******)((uint)ppppppbVar24 ^ (uint)pppppppbVar7[6]);
              pppppppbVar7[0xc] = ppppppbVar27;
              pppppppbVar7[0xd] = ppppppbVar24;
              pppppppbVar7[0xe] = ppppppbVar50;
              pppppppbVar7[0xf] = (byte ******)((uint)ppppppbVar33 ^ (uint)ppppppbVar50);
              pppppppbVar7 = pppppppbVar7 + 8;
              puVar39 = puVar39 + 1;
            }
          }
        }
      }
    }
    return;
  }
  return;
}

