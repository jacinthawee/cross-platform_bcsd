
/* WARNING: Could not reconcile some variable overlaps */

void AES_bi_ige_encrypt(uchar *in,uchar *out,size_t length,AES_KEY *key,AES_KEY *key2,uchar *ivec,
                       int enc)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte bVar9;
  byte *pbVar10;
  uint uVar11;
  byte bVar12;
  char *pcVar13;
  byte *pbVar14;
  uint uVar15;
  char *pcVar16;
  uint uVar17;
  AES_KEY *pAVar18;
  uint uVar19;
  uint in_t0;
  uint uVar20;
  uint uVar21;
  uint in_t1;
  undefined4 uVar22;
  uint in_t2;
  uint *puVar23;
  uint in_t3;
  AES_KEY *pAVar24;
  uint *puVar25;
  byte bVar26;
  byte bVar27;
  byte *pbVar28;
  byte bVar30;
  byte *pbVar29;
  uchar *puVar31;
  undefined4 *puVar33;
  byte bVar34;
  byte bVar35;
  byte bVar37;
  size_t sVar36;
  byte bVar38;
  byte bVar39;
  uint uVar40;
  byte bVar41;
  byte bStack_b1;
  AES_KEY *local_ac;
  byte bStack_a1;
  undefined4 local_98;
  uint local_6c;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  uint local_4c;
  uint *local_48;
  byte *local_44;
  byte *local_40;
  uint local_3c;
  uint *local_38;
  byte *local_34;
  byte *local_30;
  int local_2c;
  uchar *puVar32;
  
  puVar5 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAVar18 = key;
  if ((((in == (uchar *)0x0) || (out == (uchar *)0x0)) || (key == (AES_KEY *)0x0)) ||
     (pcVar13 = (char *)in, pbVar14 = out, ivec == (uchar *)0x0)) {
    pbVar14 = (byte *)0xe3;
    pcVar13 = "aes_ige.c";
    (*(code *)PTR_OpenSSLDie_006a8d4c)("aes_ige.c",0xe3,"in && out && key && ivec");
  }
  if (1 < (uint)enc) {
    pbVar14 = (byte *)0xe4;
    pcVar13 = "aes_ige.c";
    (*(code *)PTR_OpenSSLDie_006a8d4c)
              ("aes_ige.c",0xe4,"(AES_ENCRYPT == enc)||(AES_DECRYPT == enc)");
  }
  pcVar16 = CAST_S_table6 + 0x370;
  if ((length & 0xf) != 0) {
    pcVar16 = "(length%AES_BLOCK_SIZE) == 0";
    pbVar14 = (byte *)0xe5;
    pcVar13 = "aes_ige.c";
    (*(code *)PTR_OpenSSLDie_006a8d4c)();
  }
  if (enc == 1) {
    if (0xf < length) {
      bVar12 = *ivec;
      pbVar14 = ivec;
      pbVar10 = out;
      puVar23 = (uint *)(ivec + 0x10);
      sVar36 = length;
      do {
        sVar36 = sVar36 - 0x10;
        *pbVar10 = bVar12 ^ *in;
        pbVar10[1] = *(byte *)((int)in + 1) ^ pbVar14[1];
        pbVar10[2] = *(byte *)((int)in + 2) ^ pbVar14[2];
        pbVar10[3] = *(byte *)((int)in + 3) ^ pbVar14[3];
        pbVar10[4] = *(byte *)((int)in + 4) ^ pbVar14[4];
        pbVar10[5] = *(byte *)((int)in + 5) ^ pbVar14[5];
        pbVar10[6] = *(byte *)((int)in + 6) ^ pbVar14[6];
        pbVar10[7] = *(byte *)((int)in + 7) ^ pbVar14[7];
        pbVar10[8] = *(byte *)((int)in + 8) ^ pbVar14[8];
        pbVar10[9] = *(byte *)((int)in + 9) ^ pbVar14[9];
        pbVar10[10] = *(byte *)((int)in + 10) ^ pbVar14[10];
        pbVar10[0xb] = *(byte *)((int)in + 0xb) ^ pbVar14[0xb];
        pbVar10[0xc] = *(byte *)((int)in + 0xc) ^ pbVar14[0xc];
        pbVar10[0xd] = *(byte *)((int)in + 0xd) ^ pbVar14[0xd];
        pbVar10[0xe] = *(byte *)((int)in + 0xe) ^ pbVar14[0xe];
        pbVar10[0xf] = *(byte *)((int)in + 0xf) ^ pbVar14[0xf];
        AES_encrypt(pbVar10,pbVar10,key);
        bVar12 = *pbVar10 ^ *(byte *)puVar23;
        *pbVar10 = bVar12;
        pbVar10[1] = pbVar10[1] ^ *(byte *)((int)puVar23 + 1);
        pbVar10[2] = pbVar10[2] ^ *(byte *)((int)puVar23 + 2);
        pbVar10[3] = pbVar10[3] ^ *(byte *)((int)puVar23 + 3);
        pbVar10[4] = pbVar10[4] ^ *(byte *)(puVar23 + 1);
        bVar1 = *(byte *)((int)puVar23 + 5);
        pbVar10[5] = pbVar10[5] ^ bVar1;
        pbVar10[6] = pbVar10[6] ^ *(byte *)((int)puVar23 + 6);
        pbVar10[7] = pbVar10[7] ^ *(byte *)((int)puVar23 + 7);
        pbVar10[8] = pbVar10[8] ^ *(byte *)(puVar23 + 2);
        pbVar10[9] = pbVar10[9] ^ *(byte *)((int)puVar23 + 9);
        pbVar10[10] = pbVar10[10] ^ *(byte *)((int)puVar23 + 10);
        pbVar10[0xb] = pbVar10[0xb] ^ *(byte *)((int)puVar23 + 0xb);
        pbVar10[0xc] = pbVar10[0xc] ^ *(byte *)(puVar23 + 3);
        pbVar10[0xd] = pbVar10[0xd] ^ *(byte *)((int)puVar23 + 0xd);
        pbVar10[0xe] = pbVar10[0xe] ^ *(byte *)((int)puVar23 + 0xe);
        pbVar10[0xf] = pbVar10[0xf] ^ *(byte *)((int)puVar23 + 0xf);
        local_3c = *(uint *)in;
        local_38 = *(uint **)((int)in + 4);
        local_34 = *(byte **)((int)in + 8);
        local_30 = *(byte **)((int)in + 0xc);
        in = (uchar *)((int)in + 0x10);
        pbVar14 = pbVar10;
        pbVar10 = pbVar10 + 0x10;
        puVar23 = &local_3c;
      } while (0xf < sVar36);
      pbVar10 = ivec + 0x20;
      pbVar29 = out + ((length - 0x10 >> 4) + 1) * 0x10;
      puVar23 = (uint *)(ivec + 0x30);
      do {
        pbVar28 = pbVar29 + -0x10;
        uVar8 = (uint)pbVar28 & 3;
        local_58 = *(uint **)(pbVar29 + -0xc);
        local_54 = *(byte **)(pbVar29 + -8);
        local_50 = *(byte **)(pbVar29 + -4);
        uVar6 = (uint)(pbVar29 + -0xd) & 3;
        local_5c = (*(int *)(pbVar28 + -uVar8) << uVar8 * 8 |
                   (uint)bVar1 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar6 + 1) * 8 |
                   *(uint *)(pbVar29 + -0xd + -uVar6) >> (3 - uVar6) * 8;
        *pbVar28 = *pbVar28 ^ *pbVar10;
        pbVar29[-0xf] = pbVar29[-0xf] ^ pbVar10[1];
        pbVar29[-0xe] = pbVar29[-0xe] ^ pbVar10[2];
        pbVar29[-0xd] = pbVar29[-0xd] ^ pbVar10[3];
        pbVar29[-0xc] = pbVar29[-0xc] ^ pbVar10[4];
        pbVar29[-0xb] = pbVar29[-0xb] ^ pbVar10[5];
        pbVar29[-10] = pbVar29[-10] ^ pbVar10[6];
        pbVar29[-9] = pbVar29[-9] ^ pbVar10[7];
        pbVar29[-8] = pbVar29[-8] ^ pbVar10[8];
        pbVar29[-7] = pbVar29[-7] ^ pbVar10[9];
        pbVar29[-6] = pbVar29[-6] ^ pbVar10[10];
        pbVar29[-5] = pbVar29[-5] ^ pbVar10[0xb];
        pbVar29[-4] = pbVar29[-4] ^ pbVar10[0xc];
        pbVar29[-3] = pbVar29[-3] ^ pbVar10[0xd];
        pbVar29[-2] = pbVar29[-2] ^ pbVar10[0xe];
        pbVar29[-1] = pbVar29[-1] ^ pbVar10[0xf];
        AES_encrypt(pbVar28,pbVar28,key);
        *pbVar28 = *pbVar28 ^ *(byte *)puVar23;
        pbVar29[-0xf] = pbVar29[-0xf] ^ *(byte *)((int)puVar23 + 1);
        pbVar29[-0xe] = pbVar29[-0xe] ^ *(byte *)((int)puVar23 + 2);
        bVar1 = *(byte *)((int)puVar23 + 3);
        pbVar29[-0xd] = pbVar29[-0xd] ^ bVar1;
        pbVar29[-0xc] = pbVar29[-0xc] ^ *(byte *)(puVar23 + 1);
        pbVar29[-0xb] = pbVar29[-0xb] ^ *(byte *)((int)puVar23 + 5);
        pbVar29[-10] = pbVar29[-10] ^ *(byte *)((int)puVar23 + 6);
        pbVar29[-9] = pbVar29[-9] ^ *(byte *)((int)puVar23 + 7);
        pbVar29[-8] = pbVar29[-8] ^ *(byte *)(puVar23 + 2);
        pbVar29[-7] = pbVar29[-7] ^ *(byte *)((int)puVar23 + 9);
        pbVar29[-6] = pbVar29[-6] ^ *(byte *)((int)puVar23 + 10);
        pbVar29[-5] = pbVar29[-5] ^ *(byte *)((int)puVar23 + 0xb);
        pbVar29[-4] = pbVar29[-4] ^ *(byte *)(puVar23 + 3);
        pbVar29[-3] = pbVar29[-3] ^ *(byte *)((int)puVar23 + 0xd);
        local_3c = local_5c;
        pbVar29[-2] = pbVar29[-2] ^ *(byte *)((int)puVar23 + 0xe);
        local_38 = local_58;
        bVar12 = pbVar29[-1] ^ *(byte *)((int)puVar23 + 0xf);
        local_34 = local_54;
        pbVar29[-1] = bVar12;
        local_30 = local_50;
        pbVar10 = pbVar28;
        pcVar13 = (char *)(uint)bVar12;
        pbVar14 = local_50;
        pcVar16 = (char *)local_58;
        pbVar29 = pbVar28;
        puVar23 = &local_3c;
      } while (&DAT_0000000f < pbVar28 + (length - (int)(out + ((length - 0x10 >> 4) + 1) * 0x10)));
    }
  }
  else {
    pbVar10 = out + length;
    if (0xf < length) {
      bVar12 = ivec[0x3f];
      uVar6 = length - (int)(in + length);
      uVar8 = uVar6;
      local_40 = pbVar10;
      pbVar14 = pbVar10;
      puVar32 = in + length;
      puVar23 = (uint *)(ivec + 0x20);
      pbVar29 = ivec + 0x30;
      do {
        puVar31 = puVar32 + -0x10;
        pbVar28 = pbVar14 + -0x10;
        local_48 = *(uint **)(puVar32 + -0xc);
        uVar40 = (uint)puVar31 & 3;
        uVar7 = (uint)puVar31 & 3;
        uVar11 = (uint)(puVar32 + -0xc) & 3;
        uVar20 = (uint)(puVar32 + -8) & 3;
        uVar19 = (uint)(puVar32 + -4) & 3;
        uVar15 = (uint)(puVar32 + -4) & 3;
        uVar3 = (uint)(puVar32 + -8) & 3;
        uVar17 = (uint)(puVar32 + -0xd) & 3;
        uVar17 = (*(int *)(puVar31 + -uVar7) << uVar7 * 8 |
                 (uint)pAVar18 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar17 + 1) * 8 |
                 *(uint *)(puVar32 + -0xd + -uVar17) >> (3 - uVar17) * 8;
        uVar7 = (uint)(puVar32 + -9) & 3;
        uVar11 = (*(int *)(puVar32 + -0xc + -uVar11) << uVar11 * 8 |
                 (uint)local_40 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar7 + 1) * 8 |
                 *(uint *)(puVar32 + -9 + -uVar7) >> (3 - uVar7) * 8;
        uVar7 = (uint)(puVar32 + -5) & 3;
        uVar7 = (*(int *)(puVar32 + -8 + -uVar20) << uVar20 * 8 |
                uVar8 & 0xffffffffU >> (4 - uVar20) * 8) & -1 << (uVar7 + 1) * 8 |
                *(uint *)(puVar32 + -5 + -uVar7) >> (3 - uVar7) * 8;
        uVar8 = (uint)(puVar32 + -1) & 3;
        uVar20 = (*(int *)(puVar32 + -4 + -uVar19) << uVar19 * 8 |
                 in_t0 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar8 + 1) * 8 |
                 *(uint *)(puVar32 + -1 + -uVar8) >> (3 - uVar8) * 8;
        uVar8 = (uint)(puVar32 + -0xd) & 3;
        local_4c = (*(int *)(puVar31 + -uVar40) << uVar40 * 8 |
                   in_t1 & 0xffffffffU >> (4 - uVar40) * 8) & -1 << (uVar8 + 1) * 8 |
                   *(uint *)(puVar32 + -0xd + -uVar8) >> (3 - uVar8) * 8;
        uVar8 = (uint)(puVar32 + -5) & 3;
        local_44 = (byte *)((*(int *)(puVar32 + -8 + -uVar3) << uVar3 * 8 |
                            in_t3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar8 + 1) * 8 |
                           *(uint *)(puVar32 + -5 + -uVar8) >> (3 - uVar8) * 8);
        uVar8 = (uint)(puVar32 + -1) & 3;
        local_40 = (byte *)((*(int *)(puVar32 + -4 + -uVar15) << uVar15 * 8 |
                            in_t2 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar8 + 1) * 8 |
                           *(uint *)(puVar32 + -1 + -uVar8) >> (3 - uVar8) * 8);
        bStack_b1 = (byte)(uVar7 >> 0x18);
        bVar4 = (byte)(uVar7 >> 8) ^ pbVar29[10];
        local_5c = CONCAT31(CONCAT21(CONCAT11((byte)(uVar17 >> 0x18) ^ *pbVar29,
                                              (byte)(uVar17 >> 0x10) ^ pbVar29[1]),
                                     (byte)(uVar17 >> 8) ^ pbVar29[2]),(byte)uVar17 ^ pbVar29[3]);
        local_98._3_1_ = (byte)(uVar20 >> 0x18);
        local_58 = (uint *)CONCAT31(CONCAT21(CONCAT11((byte)(uVar11 >> 0x18) ^ pbVar29[4],
                                                      (byte)(uVar11 >> 0x10) ^ pbVar29[5]),
                                             (byte)(uVar11 >> 8) ^ pbVar29[6]),
                                    (byte)uVar11 ^ pbVar29[7]);
        local_50._2_2_ =
             ((ushort)bVar12 ^ (ushort)uVar20) & 0xff |
             (ushort)(byte)((byte)(uVar20 >> 8) ^ pbVar29[0xe]) << 8;
        local_54 = (byte *)CONCAT22(CONCAT11(bStack_b1 ^ pbVar29[8],
                                             (byte)(uVar7 >> 0x10) ^ pbVar29[9]),
                                    CONCAT11(bVar4,(byte)uVar7 ^ pbVar29[0xb]));
        local_50._1_3_ = CONCAT12((byte)(uVar20 >> 0x10) ^ pbVar29[0xd],local_50._2_2_);
        local_50 = (byte *)CONCAT13((byte)local_98 ^ pbVar29[0xc],local_50._1_3_);
        (*(code *)PTR_AES_decrypt_006a95f8)(&local_5c,pbVar28,key);
        *pbVar28 = *pbVar28 ^ *(byte *)puVar23;
        pbVar14[-0xf] = pbVar14[-0xf] ^ *(byte *)((int)puVar23 + 1);
        bVar1 = *(byte *)((int)puVar23 + 2);
        pbVar14[-0xe] = pbVar14[-0xe] ^ bVar1;
        in_t3 = (uint)*(byte *)((int)puVar23 + 3);
        uVar8 = (uint)(puVar31 + uVar6 < &SUB_00000010);
        pbVar14[-0xd] = pbVar14[-0xd] ^ *(byte *)((int)puVar23 + 3);
        in_t2 = (uint)*(byte *)(puVar23 + 1);
        pbVar14[-0xc] = pbVar14[-0xc] ^ *(byte *)(puVar23 + 1);
        in_t1 = (uint)*(byte *)((int)puVar23 + 5);
        pbVar14[-0xb] = pbVar14[-0xb] ^ *(byte *)((int)puVar23 + 5);
        in_t0 = (uint)*(byte *)((int)puVar23 + 6);
        pbVar14[-10] = pbVar14[-10] ^ *(byte *)((int)puVar23 + 6);
        pbVar14[-9] = pbVar14[-9] ^ *(byte *)((int)puVar23 + 7);
        pbVar14[-8] = pbVar14[-8] ^ *(byte *)(puVar23 + 2);
        pbVar14[-7] = pbVar14[-7] ^ *(byte *)((int)puVar23 + 9);
        pbVar14[-6] = pbVar14[-6] ^ *(byte *)((int)puVar23 + 10);
        pbVar14[-5] = pbVar14[-5] ^ *(byte *)((int)puVar23 + 0xb);
        pAVar18 = (AES_KEY *)(uint)*(byte *)(puVar23 + 3);
        pbVar14[-4] = pbVar14[-4] ^ *(byte *)(puVar23 + 3);
        pbVar14[-3] = pbVar14[-3] ^ *(byte *)((int)puVar23 + 0xd);
        pbVar14[-2] = pbVar14[-2] ^ *(byte *)((int)puVar23 + 0xe);
        local_3c = local_4c;
        bVar12 = pbVar14[-1] ^ *(byte *)((int)puVar23 + 0xf);
        local_34 = local_44;
        pbVar14[-1] = bVar12;
        local_38 = local_48;
        local_30 = local_40;
        pbVar14 = pbVar28;
        puVar32 = puVar31;
        puVar23 = &local_3c;
        pbVar29 = pbVar28;
      } while (uVar8 == 0);
      bVar12 = ivec[0x1b];
      bVar35 = ivec[0x18];
      bVar2 = ivec[0x13];
      bVar37 = ivec[0x1f];
      bVar38 = ivec[0x10];
      bVar41 = ivec[0x12];
      bVar30 = ivec[0x17];
      bVar34 = ivec[0x14];
      bVar39 = ivec[0x16];
      bVar27 = ivec[0x19];
      bVar26 = ivec[0x1a];
      local_98 = (uint)ivec[0x1d];
      uVar7 = (uint)ivec[0x15];
      bVar9 = ivec[0x11];
      pAVar24 = (AES_KEY *)(uint)bVar1;
      uVar8 = (uint)ivec[0x1e];
      puVar33 = (undefined4 *)(pbVar10 + ~(length - 0x10 >> 4) * 0x10);
      uVar6 = (uint)bVar4;
      uVar40 = uVar7;
      local_ac = (AES_KEY *)(uint)ivec[0x1c];
      local_6c = length - 0x10;
      while( true ) {
        uVar22 = *puVar33;
        uVar11 = (uint)(puVar33 + 2) & 3;
        uVar20 = (uint)(puVar33 + 1) & 3;
        uVar19 = (uint)(puVar33 + 2) & 3;
        uVar15 = (uint)(puVar33 + 3) & 3;
        uVar3 = (uint)(puVar33 + 1) & 3;
        uVar17 = (uint)(puVar33 + 3) & 3;
        uVar21 = (uint)(byte *)((int)puVar33 + 0xb) & 3;
        local_44 = (byte *)((*(int *)((int)(puVar33 + 2) - uVar11) << uVar11 * 8 |
                            in_t2 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar21 + 1) * 8 |
                           *(uint *)((byte *)((int)puVar33 + 0xb) + -uVar21) >> (3 - uVar21) * 8);
        uVar11 = (uint)(byte *)((int)puVar33 + 7) & 3;
        uVar21 = (*(int *)((int)(puVar33 + 1) - uVar20) << uVar20 * 8 |
                 in_t0 & 0xffffffffU >> (4 - uVar20) * 8) & -1 << (uVar11 + 1) * 8 |
                 *(uint *)((byte *)((int)puVar33 + 7) + -uVar11) >> (3 - uVar11) * 8;
        uVar11 = (uint)(byte *)((int)puVar33 + 0xb) & 3;
        uVar19 = (*(int *)((int)(puVar33 + 2) - uVar19) << uVar19 * 8 |
                 (uint)pAVar18 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar11 + 1) * 8 |
                 *(uint *)((byte *)((int)puVar33 + 0xb) + -uVar11) >> (3 - uVar11) * 8;
        uVar11 = (uint)(byte *)((int)puVar33 + 0xf) & 3;
        uVar20 = (*(int *)((int)(puVar33 + 3) - uVar15) << uVar15 * 8 |
                 uVar7 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar11 + 1) * 8 |
                 *(uint *)((byte *)((int)puVar33 + 0xf) + -uVar11) >> (3 - uVar11) * 8;
        uVar7 = (uint)(byte *)((int)puVar33 + 7) & 3;
        local_48 = (uint *)((*(int *)((int)(puVar33 + 1) - uVar3) << uVar3 * 8 |
                            in_t3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar7 + 1) * 8 |
                           *(uint *)((byte *)((int)puVar33 + 7) + -uVar7) >> (3 - uVar7) * 8);
        uVar7 = (uint)puVar33 & 3;
        uVar11 = (uint)(byte *)((int)puVar33 + 0xf) & 3;
        local_40 = (byte *)((*(int *)((int)(puVar33 + 3) - uVar17) << uVar17 * 8 |
                            uVar6 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar11 + 1) * 8 |
                           *(uint *)((byte *)((int)puVar33 + 0xf) + -uVar11) >> (3 - uVar11) * 8);
        uVar6 = (uint)(byte *)((int)puVar33 + 3) & 3;
        local_4c = (*(int *)((int)puVar33 - uVar7) << uVar7 * 8 |
                   (uint)pAVar24 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar6 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar33 + 3) + -uVar6) >> (3 - uVar6) * 8;
        bStack_a1 = (byte)((uint)uVar22 >> 0x18);
        local_58._1_3_ = (uint3)(byte)(bVar39 ^ (byte)(uVar21 >> 8)) << 8;
        local_5c = CONCAT31(CONCAT21(CONCAT11(bVar38 ^ bStack_a1,
                                              bVar9 ^ (byte)((uint)uVar22 >> 0x10)),
                                     bVar41 ^ (byte)((uint)uVar22 >> 8)),bVar2 ^ (byte)uVar22);
        local_58._1_3_ =
             local_58._1_3_ | (uint3)(byte)((byte)uVar40 ^ (byte)(uVar21 >> 0x10)) << 0x10;
        local_58 = (uint *)CONCAT13(bVar34 ^ (byte)(uVar21 >> 0x18),local_58._1_3_);
        local_58 = (uint *)((uint)local_58 | (uint)(byte)(bVar30 ^ (byte)uVar21));
        local_54 = (byte *)CONCAT31(CONCAT21(CONCAT11(bVar35 ^ (byte)(uVar19 >> 0x18),
                                                      bVar27 ^ (byte)(uVar19 >> 0x10)),
                                             bVar26 ^ (byte)(uVar19 >> 8)),bVar12 ^ (byte)uVar19);
        local_50._2_2_ = CONCAT11((byte)uVar8 ^ (byte)(uVar20 >> 8),bVar37 ^ (byte)uVar20);
        local_50._1_3_ = CONCAT12((byte)local_98 ^ (byte)(uVar20 >> 0x10),local_50._2_2_);
        local_50 = (byte *)CONCAT13((byte)local_ac ^ (byte)(uVar20 >> 0x18),local_50._1_3_);
        (*(code *)PTR_AES_decrypt_006a95f8)(&local_5c,puVar33,key);
        bVar38 = *(byte *)puVar33 ^ *ivec;
        *(byte *)puVar33 = bVar38;
        bVar9 = *(byte *)((int)puVar33 + 1) ^ *(byte *)((int)ivec + 1);
        *(byte *)((int)puVar33 + 1) = bVar9;
        bVar41 = *(byte *)((int)puVar33 + 2) ^ *(byte *)((int)ivec + 2);
        *(byte *)((int)puVar33 + 2) = bVar41;
        bVar2 = *(byte *)((int)puVar33 + 3) ^ *(byte *)((int)ivec + 3);
        *(byte *)((int)puVar33 + 3) = bVar2;
        bVar34 = *(byte *)(puVar33 + 1) ^ *(byte *)((int)ivec + 4);
        *(byte *)(puVar33 + 1) = bVar34;
        bVar12 = *(byte *)((int)puVar33 + 5) ^ *(byte *)((int)ivec + 5);
        uVar40 = (uint)bVar12;
        *(byte *)((int)puVar33 + 5) = bVar12;
        bVar39 = *(byte *)((int)puVar33 + 6) ^ *(byte *)((int)ivec + 6);
        *(byte *)((int)puVar33 + 6) = bVar39;
        bVar30 = *(byte *)((int)puVar33 + 7) ^ *(byte *)((int)ivec + 7);
        *(byte *)((int)puVar33 + 7) = bVar30;
        bVar35 = *(byte *)(puVar33 + 2) ^ *(byte *)((int)ivec + 8);
        *(byte *)(puVar33 + 2) = bVar35;
        in_t0 = (uint)*(byte *)(puVar33 + 3);
        bVar27 = *(byte *)((int)puVar33 + 9) ^ *(byte *)((int)ivec + 9);
        *(byte *)((int)puVar33 + 9) = bVar27;
        bVar26 = *(byte *)((int)puVar33 + 10) ^ *(byte *)((int)ivec + 10);
        *(byte *)((int)puVar33 + 10) = bVar26;
        bVar12 = *(byte *)((int)puVar33 + 0xb) ^ *(byte *)((int)ivec + 0xb);
        *(byte *)((int)puVar33 + 0xb) = bVar12;
        bVar1 = *(byte *)(puVar33 + 3) ^ *(byte *)((int)ivec + 0xc);
        pAVar18 = (AES_KEY *)(uint)bVar1;
        *(byte *)(puVar33 + 3) = bVar1;
        bVar1 = *(byte *)((int)puVar33 + 0xd) ^ *(byte *)((int)ivec + 0xd);
        in_t3 = (uint)bVar1;
        *(byte *)((int)puVar33 + 0xd) = bVar1;
        local_3c = local_4c;
        bVar1 = *(byte *)((int)puVar33 + 0xe) ^ *(byte *)((int)ivec + 0xe);
        in_t2 = (uint)bVar1;
        *(byte *)((int)puVar33 + 0xe) = bVar1;
        bVar37 = *(byte *)((int)puVar33 + 0xf) ^ *(byte *)((int)ivec + 0xf);
        local_38 = local_48;
        local_34 = local_44;
        local_30 = local_40;
        *(byte *)((int)puVar33 + 0xf) = bVar37;
        pcVar13 = (char *)local_40;
        pbVar14 = local_44;
        pcVar16 = (char *)local_48;
        if (local_6c < 0x10) break;
        uVar7 = local_6c - 0x10;
        pAVar24 = pAVar18;
        uVar8 = in_t2;
        puVar33 = puVar33 + 4;
        ivec = (uchar *)&local_3c;
        uVar6 = local_6c;
        local_ac = pAVar18;
        local_98 = in_t3;
        local_6c = uVar7;
      }
    }
  }
  if (local_2c != *(int *)puVar5) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    if (((byte *)pcVar13 != (byte *)0x0) && ((uint *)pcVar16 != (uint *)0x0)) {
      if (pbVar14 == &DAT_00000080) {
        *(uint *)((int)pcVar16 + 0xf0) = 10;
      }
      else if (pbVar14 == &DAT_000000c0) {
        *(uint *)((int)pcVar16 + 0xf0) = 0xc;
      }
      else {
        if (pbVar14 != (byte *)0x100) {
          return;
        }
        *(uint *)((int)pcVar16 + 0xf0) = 0xe;
      }
      uVar6 = (uint)(byte)*pcVar13 << 0x18 ^ (uint)((byte *)pcVar13)[1] << 0x10 ^
              (uint)((byte *)pcVar13)[3] ^ (uint)((byte *)pcVar13)[2] << 8;
      *(uint *)pcVar16 = uVar6;
      uVar7 = (uint)((byte *)pcVar13)[4] << 0x18 ^ (uint)((byte *)pcVar13)[5] << 0x10 ^
              (uint)((byte *)pcVar13)[7] ^ (uint)((byte *)pcVar13)[6] << 8;
      *(uint *)((int)pcVar16 + 4) = uVar7;
      uVar40 = (uint)((byte *)pcVar13)[8] << 0x18 ^ (uint)((byte *)pcVar13)[9] << 0x10 ^
               (uint)((byte *)pcVar13)[0xb] ^ (uint)((byte *)pcVar13)[10] << 8;
      *(uint *)((int)pcVar16 + 8) = uVar40;
      bVar12 = ((byte *)pcVar13)[0xc];
      uVar8 = (uint)bVar12 << 0x18 ^ (uint)((byte *)pcVar13)[0xd] << 0x10 ^
              (uint)((byte *)pcVar13)[0xf] ^ (uint)((byte *)pcVar13)[0xe] << 8;
      *(uint *)((int)pcVar16 + 0xc) = uVar8;
      if (pbVar14 == &DAT_00000080) {
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x1000000 ^
                (uint)(byte)Te1[(uint)bVar12 * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar6 ^ uVar7;
        uVar40 = uVar7 ^ uVar40;
        *(uint *)((int)pcVar16 + 0x10) = uVar6;
        uVar8 = uVar40 ^ uVar8;
        *(uint *)((int)pcVar16 + 0x14) = uVar7;
        *(uint *)((int)pcVar16 + 0x18) = uVar40;
        *(uint *)((int)pcVar16 + 0x1c) = uVar8;
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x2000000 ^
                (uint)(byte)Te1[(uVar8 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar6 ^ uVar7;
        uVar40 = uVar7 ^ uVar40;
        *(uint *)((int)pcVar16 + 0x20) = uVar6;
        uVar8 = uVar40 ^ uVar8;
        *(uint *)((int)pcVar16 + 0x24) = uVar7;
        *(uint *)((int)pcVar16 + 0x28) = uVar40;
        *(uint *)((int)pcVar16 + 0x2c) = uVar8;
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x4000000 ^
                (uint)(byte)Te1[(uVar8 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar6 ^ uVar7;
        uVar40 = uVar7 ^ uVar40;
        *(uint *)((int)pcVar16 + 0x30) = uVar6;
        uVar8 = uVar40 ^ uVar8;
        *(uint *)((int)pcVar16 + 0x34) = uVar7;
        *(uint *)((int)pcVar16 + 0x38) = uVar40;
        *(uint *)((int)pcVar16 + 0x3c) = uVar8;
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x8000000 ^
                (uint)(byte)Te1[(uVar8 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar6 ^ uVar7;
        uVar40 = uVar7 ^ uVar40;
        *(uint *)((int)pcVar16 + 0x40) = uVar6;
        uVar8 = uVar40 ^ uVar8;
        *(uint *)((int)pcVar16 + 0x44) = uVar7;
        *(uint *)((int)pcVar16 + 0x48) = uVar40;
        *(uint *)((int)pcVar16 + 0x4c) = uVar8;
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x10000000 ^
                (uint)(byte)Te1[(uVar8 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar6 ^ uVar7;
        uVar40 = uVar7 ^ uVar40;
        *(uint *)((int)pcVar16 + 0x50) = uVar6;
        uVar8 = uVar40 ^ uVar8;
        *(uint *)((int)pcVar16 + 0x54) = uVar7;
        *(uint *)((int)pcVar16 + 0x58) = uVar40;
        *(uint *)((int)pcVar16 + 0x5c) = uVar8;
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x20000000 ^
                (uint)(byte)Te1[(uVar8 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar7 ^ uVar6;
        uVar40 = uVar40 ^ uVar7;
        *(uint *)((int)pcVar16 + 0x60) = uVar6;
        uVar8 = uVar8 ^ uVar40;
        *(uint *)((int)pcVar16 + 100) = uVar7;
        *(uint *)((int)pcVar16 + 0x68) = uVar40;
        *(uint *)((int)pcVar16 + 0x6c) = uVar8;
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x40000000 ^
                (uint)(byte)Te1[(uVar8 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar7 ^ uVar6;
        uVar40 = uVar40 ^ uVar7;
        *(uint *)((int)pcVar16 + 0x70) = uVar6;
        uVar8 = uVar8 ^ uVar40;
        *(uint *)((int)pcVar16 + 0x74) = uVar7;
        *(uint *)((int)pcVar16 + 0x78) = uVar40;
        *(uint *)((int)pcVar16 + 0x7c) = uVar8;
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x80000000 ^
                (uint)(byte)Te1[(uVar8 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar7 ^ uVar6;
        uVar40 = uVar40 ^ uVar7;
        *(uint *)((int)pcVar16 + 0x80) = uVar6;
        uVar8 = uVar8 ^ uVar40;
        *(uint *)((int)pcVar16 + 0x84) = uVar7;
        *(uint *)((int)pcVar16 + 0x88) = uVar40;
        *(uint *)((int)pcVar16 + 0x8c) = uVar8;
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x1b000000 ^
                (uint)(byte)Te1[(uVar8 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar7 ^ uVar6;
        uVar40 = uVar40 ^ uVar7;
        *(uint *)((int)pcVar16 + 0x90) = uVar6;
        uVar8 = uVar8 ^ uVar40;
        *(uint *)((int)pcVar16 + 0x94) = uVar7;
        *(uint *)((int)pcVar16 + 0x98) = uVar40;
        *(uint *)((int)pcVar16 + 0x9c) = uVar8;
        uVar6 = *(uint *)(Te0 + (uVar8 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x36000000 ^
                (uint)(byte)Te1[(uVar8 >> 0x18) * 4 + 3] ^
                *(uint *)(Te2 + ((uVar8 << 8) >> 0x18) * 4) & 0xff000000 ^
                *(uint *)(Te3 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff0000;
        uVar7 = uVar6 ^ uVar7;
        uVar40 = uVar7 ^ uVar40;
        *(uint *)((int)pcVar16 + 0xa0) = uVar6;
        *(uint *)((int)pcVar16 + 0xa4) = uVar7;
        *(uint *)((int)pcVar16 + 0xa8) = uVar40;
        *(uint *)((int)pcVar16 + 0xac) = uVar40 ^ uVar8;
      }
      else {
        uVar20 = (uint)((byte *)pcVar13)[0x10] << 0x18 ^ (uint)((byte *)pcVar13)[0x11] << 0x10 ^
                 (uint)((byte *)pcVar13)[0x13] ^ (uint)((byte *)pcVar13)[0x12] << 8;
        *(uint *)((int)pcVar16 + 0x10) = uVar20;
        bVar12 = ((byte *)pcVar13)[0x14];
        uVar11 = (uint)bVar12 << 0x18 ^ (uint)((byte *)pcVar13)[0x15] << 0x10 ^
                 (uint)((byte *)pcVar13)[0x17] ^ (uint)((byte *)pcVar13)[0x16] << 8;
        *(uint *)((int)pcVar16 + 0x14) = uVar11;
        if (pbVar14 == &DAT_000000c0) {
          uVar6 = *(uint *)(Te0 + (uVar11 & 0xff) * 4) & 0xff00 ^ uVar6 ^ 0x1000000 ^
                  (uint)(byte)Te1[(uint)bVar12 * 4 + 3] ^
                  *(uint *)(Te2 + ((uVar11 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar11 << 0x10) >> 0x18) * 4) & 0xff0000;
          uVar7 = uVar7 ^ uVar6;
          uVar40 = uVar40 ^ uVar7;
          *(uint *)((int)pcVar16 + 0x18) = uVar6;
          uVar8 = uVar8 ^ uVar40;
          *(uint *)((int)pcVar16 + 0x1c) = uVar7;
          uVar20 = uVar8 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x20) = uVar40;
          uVar11 = uVar11 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x24) = uVar8;
          *(uint *)((int)pcVar16 + 0x28) = uVar20;
          *(uint *)((int)pcVar16 + 0x2c) = uVar11;
          uVar6 = *(uint *)(Te0 + (uVar11 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar11 >> 0x18) * 4 + 3] ^ 0x2000000 ^
                  *(uint *)(Te2 + ((uVar11 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar11 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
          uVar7 = uVar7 ^ uVar6;
          uVar40 = uVar40 ^ uVar7;
          *(uint *)((int)pcVar16 + 0x30) = uVar6;
          uVar8 = uVar8 ^ uVar40;
          *(uint *)((int)pcVar16 + 0x34) = uVar7;
          uVar20 = uVar8 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x38) = uVar40;
          uVar11 = uVar11 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x3c) = uVar8;
          *(uint *)((int)pcVar16 + 0x40) = uVar20;
          *(uint *)((int)pcVar16 + 0x44) = uVar11;
          uVar6 = *(uint *)(Te0 + (uVar11 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar11 >> 0x18) * 4 + 3] ^ 0x4000000 ^
                  *(uint *)(Te2 + ((uVar11 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar11 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
          uVar7 = uVar7 ^ uVar6;
          uVar40 = uVar40 ^ uVar7;
          *(uint *)((int)pcVar16 + 0x48) = uVar6;
          uVar8 = uVar8 ^ uVar40;
          *(uint *)((int)pcVar16 + 0x4c) = uVar7;
          uVar20 = uVar8 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x50) = uVar40;
          uVar11 = uVar11 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x54) = uVar8;
          *(uint *)((int)pcVar16 + 0x58) = uVar20;
          *(uint *)((int)pcVar16 + 0x5c) = uVar11;
          uVar6 = *(uint *)(Te0 + (uVar11 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar11 >> 0x18) * 4 + 3] ^ 0x8000000 ^
                  *(uint *)(Te2 + ((uVar11 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar11 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
          uVar7 = uVar7 ^ uVar6;
          uVar40 = uVar40 ^ uVar7;
          *(uint *)((int)pcVar16 + 0x60) = uVar6;
          uVar8 = uVar8 ^ uVar40;
          *(uint *)((int)pcVar16 + 100) = uVar7;
          uVar20 = uVar8 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x68) = uVar40;
          uVar11 = uVar11 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x6c) = uVar8;
          *(uint *)((int)pcVar16 + 0x70) = uVar20;
          *(uint *)((int)pcVar16 + 0x74) = uVar11;
          uVar6 = *(uint *)(Te0 + (uVar11 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar11 >> 0x18) * 4 + 3] ^ 0x10000000 ^
                  *(uint *)(Te2 + ((uVar11 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar11 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
          uVar7 = uVar7 ^ uVar6;
          uVar40 = uVar40 ^ uVar7;
          *(uint *)((int)pcVar16 + 0x78) = uVar6;
          uVar8 = uVar8 ^ uVar40;
          *(uint *)((int)pcVar16 + 0x7c) = uVar7;
          uVar20 = uVar8 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x80) = uVar40;
          uVar11 = uVar11 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x84) = uVar8;
          *(uint *)((int)pcVar16 + 0x88) = uVar20;
          *(uint *)((int)pcVar16 + 0x8c) = uVar11;
          uVar6 = *(uint *)(Te0 + (uVar11 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar11 >> 0x18) * 4 + 3] ^ 0x20000000 ^
                  *(uint *)(Te2 + ((uVar11 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar11 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
          uVar7 = uVar7 ^ uVar6;
          uVar40 = uVar40 ^ uVar7;
          *(uint *)((int)pcVar16 + 0x90) = uVar6;
          uVar8 = uVar8 ^ uVar40;
          *(uint *)((int)pcVar16 + 0x94) = uVar7;
          uVar20 = uVar8 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x98) = uVar40;
          uVar11 = uVar11 ^ uVar20;
          *(uint *)((int)pcVar16 + 0x9c) = uVar8;
          *(uint *)((int)pcVar16 + 0xa0) = uVar20;
          *(uint *)((int)pcVar16 + 0xa4) = uVar11;
          uVar6 = *(uint *)(Te0 + (uVar11 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar11 >> 0x18) * 4 + 3] ^ 0x40000000 ^
                  *(uint *)(Te2 + ((uVar11 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar11 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
          uVar7 = uVar7 ^ uVar6;
          uVar40 = uVar40 ^ uVar7;
          *(uint *)((int)pcVar16 + 0xa8) = uVar6;
          uVar8 = uVar8 ^ uVar40;
          *(uint *)((int)pcVar16 + 0xac) = uVar7;
          *(uint *)((int)pcVar16 + 0xb0) = uVar40;
          uVar11 = uVar11 ^ uVar8 ^ uVar20;
          *(uint *)((int)pcVar16 + 0xb4) = uVar8;
          *(uint *)((int)pcVar16 + 0xb8) = uVar8 ^ uVar20;
          *(uint *)((int)pcVar16 + 0xbc) = uVar11;
          uVar6 = *(uint *)(Te0 + (uVar11 & 0xff) * 4) & 0xff00 ^
                  (uint)(byte)Te1[(uVar11 >> 0x18) * 4 + 3] ^ 0x80000000 ^
                  *(uint *)(Te2 + ((uVar11 << 8) >> 0x18) * 4) & 0xff000000 ^
                  *(uint *)(Te3 + ((uVar11 << 0x10) >> 0x18) * 4) & 0xff0000 ^ uVar6;
          uVar7 = uVar6 ^ uVar7;
          uVar40 = uVar7 ^ uVar40;
          *(uint *)((int)pcVar16 + 0xc0) = uVar6;
          *(uint *)((int)pcVar16 + 0xc4) = uVar7;
          *(uint *)((int)pcVar16 + 200) = uVar40;
          *(uint *)((int)pcVar16 + 0xcc) = uVar40 ^ uVar8;
        }
        else {
          *(uint *)((int)pcVar16 + 0x18) =
               (uint)((byte *)pcVar13)[0x18] << 0x18 ^ (uint)((byte *)pcVar13)[0x19] << 0x10 ^
               (uint)((byte *)pcVar13)[0x1b] ^ (uint)((byte *)pcVar13)[0x1a] << 8;
          *(uint *)((int)pcVar16 + 0x1c) =
               (uint)((byte *)pcVar13)[0x1c] << 0x18 ^ (uint)((byte *)pcVar13)[0x1d] << 0x10 ^
               (uint)((byte *)pcVar13)[0x1f] ^ (uint)((byte *)pcVar13)[0x1e] << 8;
          if (pbVar14 == (byte *)0x100) {
            puVar23 = (uint *)pcVar16;
            puVar25 = (uint *)rcon;
            while( true ) {
              uVar11 = puVar23[7];
              uVar6 = *(uint *)(Te0 + (uVar11 & 0xff) * 4) & 0xff00 ^ uVar6 ^ *puVar25 ^
                      (uint)(byte)Te1[(uVar11 >> 0x18) * 4 + 3] ^
                      *(uint *)(Te2 + ((uVar11 << 8) >> 0x18) * 4) & 0xff000000 ^
                      *(uint *)(Te3 + ((uVar11 << 0x10) >> 0x18) * 4) & 0xff0000;
              uVar7 = uVar7 ^ uVar6;
              uVar40 = uVar40 ^ uVar7;
              puVar23[8] = uVar6;
              uVar8 = uVar8 ^ uVar40;
              puVar23[9] = uVar7;
              puVar23[10] = uVar40;
              puVar23[0xb] = uVar8;
              if (puVar23 == (uint *)((int)pcVar16 + 0xc0)) break;
              uVar15 = *(uint *)(Te2 + (uVar8 >> 0x18) * 4) & 0xff000000 ^
                       (uint)(byte)Te1[(uVar8 & 0xff) * 4 + 3] ^ puVar23[4] ^
                       *(uint *)(Te3 + ((uVar8 << 8) >> 0x18) * 4) & 0xff0000 ^
                       *(uint *)(Te0 + ((uVar8 << 0x10) >> 0x18) * 4) & 0xff00;
              uVar19 = uVar15 ^ puVar23[5];
              uVar20 = uVar19 ^ puVar23[6];
              puVar23[0xc] = uVar15;
              puVar23[0xd] = uVar19;
              puVar23[0xe] = uVar20;
              puVar23[0xf] = uVar11 ^ uVar20;
              puVar23 = puVar23 + 8;
              puVar25 = puVar25 + 1;
            }
          }
        }
      }
    }
    return;
  }
  return;
}

