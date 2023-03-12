
/* WARNING: Heritage AFTER dead removal. Example location: r0x00195d50 : 0x0007e086 */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffb4 : 0x0007dd94 */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void AES_bi_ige_encrypt(uchar *in,uchar *out,size_t length,AES_KEY *key,AES_KEY *key2,uchar *ivec,
                       int enc)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  ushort uVar12;
  byte *pbVar13;
  byte *out_00;
  byte *pbVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 *in_00;
  byte bVar17;
  undefined4 *puVar18;
  byte *pbVar19;
  undefined4 *puVar20;
  byte bVar21;
  size_t sVar22;
  byte bVar23;
  byte bVar24;
  undefined4 *puVar25;
  byte bVar26;
  uint local_a0;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int local_2c;
  
  local_2c = __TMC_END__;
  if ((out == (uchar *)0x0 || in == (uchar *)0x0) || (ivec == (uchar *)0x0 || key == (AES_KEY *)0x0)
     ) {
    OpenSSLDie("aes_ige.c",0xe3,"in && out && key && ivec");
  }
  if (1 < (uint)enc) {
    OpenSSLDie("aes_ige.c",0xe4,"(AES_ENCRYPT == enc)||(AES_DECRYPT == enc)");
  }
  if ((length & 0xf) != 0) {
    OpenSSLDie("aes_ige.c",0xe5,"(length%AES_BLOCK_SIZE) == 0");
  }
  if (enc == 1) {
    local_5c._0_3_ = CONCAT12(local_5c._2_1_,CONCAT11(local_5c._1_1_,(byte)local_5c));
    local_58._0_3_ = CONCAT12(local_58._2_1_,CONCAT11(local_58._1_1_,(byte)local_58));
    local_54._0_3_ = CONCAT12(local_54._2_1_,CONCAT11(local_54._1_1_,(byte)local_54));
    local_50._0_3_ = CONCAT12(local_50._2_1_,CONCAT11(local_50._1_1_,(byte)local_50));
    if (0xf < length) {
      bVar23 = *ivec;
      pbVar13 = ivec;
      pbVar14 = out;
      sVar22 = length;
      puVar16 = (undefined4 *)(ivec + 0x10);
      do {
        sVar22 = sVar22 - 0x10;
        *pbVar14 = bVar23 ^ *in;
        pbVar14[1] = pbVar13[1] ^ *(byte *)((int)in + 1);
        pbVar14[2] = pbVar13[2] ^ *(byte *)((int)in + 2);
        pbVar14[3] = pbVar13[3] ^ *(byte *)((int)in + 3);
        pbVar14[4] = pbVar13[4] ^ *(byte *)((int)in + 4);
        pbVar14[5] = pbVar13[5] ^ *(byte *)((int)in + 5);
        pbVar14[6] = pbVar13[6] ^ *(byte *)((int)in + 6);
        pbVar14[7] = pbVar13[7] ^ *(byte *)((int)in + 7);
        pbVar14[8] = pbVar13[8] ^ *(byte *)((int)in + 8);
        pbVar14[9] = pbVar13[9] ^ *(byte *)((int)in + 9);
        pbVar14[10] = pbVar13[10] ^ *(byte *)((int)in + 10);
        pbVar14[0xb] = pbVar13[0xb] ^ *(byte *)((int)in + 0xb);
        pbVar14[0xc] = pbVar13[0xc] ^ *(byte *)((int)in + 0xc);
        pbVar14[0xd] = pbVar13[0xd] ^ *(byte *)((int)in + 0xd);
        pbVar14[0xe] = pbVar13[0xe] ^ *(byte *)((int)in + 0xe);
        pbVar14[0xf] = *(byte *)((int)in + 0xf) ^ pbVar13[0xf];
        AES_encrypt(pbVar14,pbVar14,key);
        bVar23 = *(byte *)puVar16 ^ *pbVar14;
        *pbVar14 = bVar23;
        pbVar14[1] = pbVar14[1] ^ *(byte *)((int)puVar16 + 1);
        pbVar14[2] = pbVar14[2] ^ *(byte *)((int)puVar16 + 2);
        pbVar14[3] = pbVar14[3] ^ *(byte *)((int)puVar16 + 3);
        pbVar14[4] = pbVar14[4] ^ *(byte *)(puVar16 + 1);
        pbVar14[5] = pbVar14[5] ^ *(byte *)((int)puVar16 + 5);
        pbVar14[6] = pbVar14[6] ^ *(byte *)((int)puVar16 + 6);
        pbVar14[7] = pbVar14[7] ^ *(byte *)((int)puVar16 + 7);
        pbVar14[8] = pbVar14[8] ^ *(byte *)(puVar16 + 2);
        pbVar14[9] = pbVar14[9] ^ *(byte *)((int)puVar16 + 9);
        pbVar14[10] = pbVar14[10] ^ *(byte *)((int)puVar16 + 10);
        pbVar14[0xb] = pbVar14[0xb] ^ *(byte *)((int)puVar16 + 0xb);
        pbVar14[0xc] = pbVar14[0xc] ^ *(byte *)(puVar16 + 3);
        pbVar14[0xd] = pbVar14[0xd] ^ *(byte *)((int)puVar16 + 0xd);
        pbVar14[0xe] = pbVar14[0xe] ^ *(byte *)((int)puVar16 + 0xe);
        pbVar14[0xf] = pbVar14[0xf] ^ *(byte *)((int)puVar16 + 0xf);
        local_3c = *(undefined4 *)in;
        uStack_38 = *(undefined4 *)((int)in + 4);
        uStack_34 = *(undefined4 *)((int)in + 8);
        uStack_30 = *(undefined4 *)((int)in + 0xc);
        pbVar13 = pbVar14;
        pbVar14 = pbVar14 + 0x10;
        in = (uchar *)((int)in + 0x10);
        puVar16 = &local_3c;
      } while (0xf < sVar22);
      puVar15 = (undefined4 *)(out + (length - 0x10 & 0xfffffff0) + 0x10);
      puVar16 = puVar15;
      puVar18 = (undefined4 *)(ivec + 0x30);
      puVar20 = (undefined4 *)(ivec + 0x20);
      puVar25 = puVar15;
      do {
        local_5c = puVar25[-4];
        in_00 = puVar16 + -4;
        local_58 = puVar25[-3];
        local_54 = puVar25[-2];
        local_50 = puVar25[-1];
        *(byte *)(puVar25 + -4) = *(byte *)(puVar25 + -4) ^ *(byte *)puVar20;
        *(byte *)((int)puVar16 + -0xf) =
             *(byte *)((int)puVar20 + 1) ^ *(byte *)((int)puVar16 + -0xf);
        *(byte *)((int)puVar16 + -0xe) =
             *(byte *)((int)puVar20 + 2) ^ *(byte *)((int)puVar16 + -0xe);
        *(byte *)((int)puVar16 + -0xd) =
             *(byte *)((int)puVar20 + 3) ^ *(byte *)((int)puVar16 + -0xd);
        *(byte *)(puVar16 + -3) = *(byte *)(puVar20 + 1) ^ *(byte *)(puVar16 + -3);
        *(byte *)((int)puVar16 + -0xb) =
             *(byte *)((int)puVar20 + 5) ^ *(byte *)((int)puVar16 + -0xb);
        *(byte *)((int)puVar16 + -10) = *(byte *)((int)puVar20 + 6) ^ *(byte *)((int)puVar16 + -10);
        *(byte *)((int)puVar16 + -9) = *(byte *)((int)puVar20 + 7) ^ *(byte *)((int)puVar16 + -9);
        *(byte *)(puVar16 + -2) = *(byte *)(puVar20 + 2) ^ *(byte *)(puVar16 + -2);
        *(byte *)((int)puVar16 + -7) = *(byte *)((int)puVar20 + 9) ^ *(byte *)((int)puVar16 + -7);
        *(byte *)((int)puVar16 + -6) = *(byte *)((int)puVar20 + 10) ^ *(byte *)((int)puVar16 + -6);
        *(byte *)((int)puVar16 + -5) = *(byte *)((int)puVar20 + 0xb) ^ *(byte *)((int)puVar16 + -5);
        *(byte *)(puVar16 + -1) = *(byte *)(puVar20 + 3) ^ *(byte *)(puVar16 + -1);
        *(byte *)((int)puVar16 + -3) = *(byte *)((int)puVar20 + 0xd) ^ *(byte *)((int)puVar16 + -3);
        *(byte *)((int)puVar16 + -2) = *(byte *)((int)puVar20 + 0xe) ^ *(byte *)((int)puVar16 + -2);
        *(byte *)((int)puVar16 + -1) = *(byte *)((int)puVar16 + -1) ^ *(byte *)((int)puVar20 + 0xf);
        AES_encrypt((uchar *)in_00,(uchar *)in_00,key);
        *(byte *)(puVar25 + -4) = *(byte *)puVar18 ^ *(byte *)(puVar25 + -4);
        *(byte *)((int)puVar16 + -0xf) =
             *(byte *)((int)puVar16 + -0xf) ^ *(byte *)((int)puVar18 + 1);
        *(byte *)((int)puVar16 + -0xe) =
             *(byte *)((int)puVar16 + -0xe) ^ *(byte *)((int)puVar18 + 2);
        *(byte *)((int)puVar16 + -0xd) =
             *(byte *)((int)puVar16 + -0xd) ^ *(byte *)((int)puVar18 + 3);
        *(byte *)(puVar16 + -3) = *(byte *)(puVar16 + -3) ^ *(byte *)(puVar18 + 1);
        *(byte *)((int)puVar16 + -0xb) =
             *(byte *)((int)puVar16 + -0xb) ^ *(byte *)((int)puVar18 + 5);
        *(byte *)((int)puVar16 + -10) = *(byte *)((int)puVar16 + -10) ^ *(byte *)((int)puVar18 + 6);
        *(byte *)((int)puVar16 + -9) = *(byte *)((int)puVar16 + -9) ^ *(byte *)((int)puVar18 + 7);
        *(byte *)(puVar16 + -2) = *(byte *)(puVar16 + -2) ^ *(byte *)(puVar18 + 2);
        *(byte *)((int)puVar16 + -7) = *(byte *)((int)puVar16 + -7) ^ *(byte *)((int)puVar18 + 9);
        *(byte *)((int)puVar16 + -6) = *(byte *)((int)puVar16 + -6) ^ *(byte *)((int)puVar18 + 10);
        *(byte *)((int)puVar16 + -5) = *(byte *)((int)puVar16 + -5) ^ *(byte *)((int)puVar18 + 0xb);
        *(byte *)(puVar16 + -1) = *(byte *)(puVar16 + -1) ^ *(byte *)(puVar18 + 3);
        *(byte *)((int)puVar16 + -3) = *(byte *)((int)puVar18 + 0xd) ^ *(byte *)((int)puVar16 + -3);
        *(byte *)((int)puVar16 + -2) = *(byte *)((int)puVar18 + 0xe) ^ *(byte *)((int)puVar16 + -2);
        *(byte *)((int)puVar16 + -1) = *(byte *)((int)puVar18 + 0xf) ^ *(byte *)((int)puVar16 + -1);
        puVar16 = in_00;
        puVar18 = &local_3c;
        puVar20 = in_00;
        puVar25 = puVar25 + -4;
        local_3c = local_5c;
        uStack_38 = local_58;
        uStack_34 = local_54;
        uStack_30 = local_50;
      } while ((byte *)0xf < (byte *)((int)in_00 + (length - (int)puVar15)));
    }
  }
  else {
    local_5c._0_3_ = CONCAT12(local_5c._2_1_,CONCAT11(local_5c._1_1_,(byte)local_5c));
    local_58._0_3_ = CONCAT12(local_58._2_1_,CONCAT11(local_58._1_1_,(byte)local_58));
    local_54._0_3_ = CONCAT12(local_54._2_1_,CONCAT11(local_54._1_1_,(byte)local_54));
    local_50._0_3_ = CONCAT12(local_50._2_1_,CONCAT11(local_50._1_1_,(byte)local_50));
    pbVar13 = out + length;
    if (0xf < length) {
      bVar23 = ivec[0x3f];
      pbVar14 = pbVar13;
      puVar16 = (undefined4 *)(ivec + 0x20);
      pbVar19 = ivec + 0x30;
      puVar18 = (undefined4 *)(in + length);
      do {
        local_4c = puVar18[-4];
        bVar1 = *pbVar19;
        out_00 = pbVar14 + -0x10;
        uStack_48 = puVar18[-3];
        uStack_44 = puVar18[-2];
        uStack_40 = puVar18[-1];
        local_50._3_1_ = (byte)((uint)uStack_40 >> 0x18);
        local_50._2_1_ = (byte)((uint)uStack_40 >> 0x10);
        local_50._1_1_ = (byte)((uint)uStack_40 >> 8);
        local_50._0_1_ = (byte)uStack_40;
        local_54._3_1_ = (byte)((uint)uStack_44 >> 0x18);
        local_54._2_1_ = (byte)((uint)uStack_44 >> 0x10);
        local_54._1_1_ = (byte)((uint)uStack_44 >> 8);
        local_54._0_1_ = (byte)uStack_44;
        local_58._3_1_ = (byte)((uint)uStack_48 >> 0x18);
        local_58._2_1_ = (byte)((uint)uStack_48 >> 0x10);
        local_58._1_1_ = (byte)((uint)uStack_48 >> 8);
        local_58._0_1_ = (byte)uStack_48;
        local_5c._3_1_ = (byte)((uint)local_4c >> 0x18);
        local_5c._2_1_ = (byte)((uint)local_4c >> 0x10);
        local_5c._1_1_ = (byte)((uint)local_4c >> 8);
        local_5c._0_1_ = (byte)local_4c;
        bVar17 = pbVar19[2];
        bVar2 = pbVar19[4];
        uVar12 = CONCAT11(pbVar19[3] ^ local_5c._3_1_,bVar17 ^ local_5c._2_1_);
        bVar3 = pbVar19[5];
        bVar21 = pbVar19[6];
        bVar4 = pbVar19[7];
        local_5c._0_2_ = CONCAT11(pbVar19[1] ^ local_5c._1_1_,bVar1 ^ (byte)local_5c);
        local_5c = CONCAT22(uVar12,(ushort)local_5c);
        local_58._0_3_ =
             CONCAT12(bVar21 ^ local_58._2_1_,
                      CONCAT11(bVar3 ^ local_58._1_1_,bVar2 ^ (byte)local_58));
        bVar5 = pbVar19[8];
        local_58 = CONCAT13(bVar4 ^ local_58._3_1_,(undefined3)local_58);
        bVar6 = pbVar19[9];
        bVar7 = pbVar19[10];
        local_54._0_2_ = CONCAT11(bVar6 ^ local_54._1_1_,bVar5 ^ (byte)local_54);
        bVar8 = pbVar19[0xb];
        local_54._0_3_ = CONCAT12(bVar7 ^ local_54._2_1_,(undefined2)local_54);
        bVar9 = pbVar19[0xc];
        local_54 = CONCAT13(bVar8 ^ local_54._3_1_,(undefined3)local_54);
        local_50._0_2_ = CONCAT11(pbVar19[0xd] ^ local_50._1_1_,bVar9 ^ (byte)local_50);
        local_50._0_3_ = CONCAT12(pbVar19[0xe] ^ local_50._2_1_,(undefined2)local_50);
        local_50 = CONCAT13(bVar23 ^ local_50._3_1_,(uint3)local_50);
        AES_decrypt((uchar *)&local_5c,out_00,key);
        local_50._3_1_ = bVar23 ^ local_50._3_1_;
        local_50._2_1_ = (byte)((uint)(uint3)local_50 >> 0x10);
        local_50._1_1_ = (byte)((uint)(uint3)local_50 >> 8);
        local_50._0_1_ = bVar9 ^ (byte)local_50;
        local_54._3_1_ = bVar8 ^ local_54._3_1_;
        local_54._2_1_ = bVar7 ^ local_54._2_1_;
        local_54._1_1_ = bVar6 ^ local_54._1_1_;
        local_54._0_1_ = bVar5 ^ (byte)local_54;
        local_58._3_1_ = bVar4 ^ local_58._3_1_;
        local_58._2_1_ = bVar21 ^ local_58._2_1_;
        local_58._1_1_ = bVar3 ^ local_58._1_1_;
        local_58._0_1_ = bVar2 ^ (byte)local_58;
        local_5c._3_1_ = (byte)((uint)uVar12 >> 8);
        local_5c._2_1_ = bVar17 ^ local_5c._2_1_;
        local_5c._1_1_ = (byte)((uint)(ushort)local_5c >> 8);
        local_5c._0_1_ = bVar1 ^ (byte)local_5c;
        *out_00 = *out_00 ^ *(byte *)puVar16;
        pbVar14[-0xf] = pbVar14[-0xf] ^ *(byte *)((int)puVar16 + 1);
        pbVar14[-0xe] = pbVar14[-0xe] ^ *(byte *)((int)puVar16 + 2);
        pbVar14[-0xd] = pbVar14[-0xd] ^ *(byte *)((int)puVar16 + 3);
        pbVar14[-0xc] = pbVar14[-0xc] ^ *(byte *)(puVar16 + 1);
        pbVar14[-0xb] = pbVar14[-0xb] ^ *(byte *)((int)puVar16 + 5);
        pbVar14[-10] = pbVar14[-10] ^ *(byte *)((int)puVar16 + 6);
        pbVar14[-9] = pbVar14[-9] ^ *(byte *)((int)puVar16 + 7);
        pbVar14[-8] = pbVar14[-8] ^ *(byte *)(puVar16 + 2);
        pbVar14[-7] = pbVar14[-7] ^ *(byte *)((int)puVar16 + 9);
        pbVar14[-6] = pbVar14[-6] ^ *(byte *)((int)puVar16 + 10);
        pbVar14[-5] = pbVar14[-5] ^ *(byte *)((int)puVar16 + 0xb);
        pbVar14[-4] = pbVar14[-4] ^ *(byte *)(puVar16 + 3);
        pbVar14[-3] = *(byte *)((int)puVar16 + 0xd) ^ pbVar14[-3];
        pbVar14[-2] = *(byte *)((int)puVar16 + 0xe) ^ pbVar14[-2];
        bVar23 = *(byte *)((int)puVar16 + 0xf) ^ pbVar14[-1];
        pbVar14[-1] = bVar23;
        pbVar14 = out_00;
        puVar16 = &local_3c;
        pbVar19 = out_00;
        puVar18 = puVar18 + -4;
      } while ((byte *)0xf < out_00 + (length - (int)pbVar13));
      bVar23 = ivec[0x16];
      local_a0 = length - 0x10;
      bVar1 = ivec[0x17];
      bVar17 = ivec[0x14];
      bVar2 = ivec[0x18];
      bVar3 = ivec[0x19];
      bVar21 = ivec[0x15];
      bVar4 = ivec[0x1a];
      bVar5 = ivec[0x1b];
      bVar6 = ivec[0x1c];
      bVar7 = ivec[0x1d];
      bVar8 = ivec[0x10];
      bVar9 = ivec[0x1e];
      bVar10 = ivec[0x1f];
      bVar24 = ivec[0x11];
      bVar11 = ivec[0x12];
      bVar26 = ivec[0x13];
      puVar16 = (undefined4 *)(pbVar13 + ~(local_a0 & 0xfffffff0 ^ 0xf));
      while( true ) {
        local_4c = *puVar16;
        uStack_48 = puVar16[1];
        uStack_44 = puVar16[2];
        uStack_40 = puVar16[3];
        local_5c._0_2_ = CONCAT11(bVar24 ^ local_5c._1_1_,bVar8 ^ (byte)local_5c);
        local_58 = CONCAT31(CONCAT12(local_58._3_1_ ^ bVar1,
                                     CONCAT11(local_58._2_1_ ^ bVar23,bVar21 ^ local_58._1_1_)),
                            bVar17 ^ (byte)local_58);
        local_54._0_2_ = CONCAT11(local_54._1_1_ ^ bVar3,(byte)local_54 ^ bVar2);
        local_5c._0_3_ = CONCAT12(bVar11 ^ local_5c._2_1_,(ushort)local_5c);
        local_5c = CONCAT13(bVar26 ^ local_5c._3_1_,(undefined3)local_5c);
        local_54._0_3_ = CONCAT12(bVar4 ^ local_54._2_1_,(undefined2)local_54);
        local_54 = CONCAT13(local_54._3_1_ ^ bVar5,(undefined3)local_54);
        local_50._0_2_ = CONCAT11(local_50._1_1_ ^ bVar7,(byte)local_50 ^ bVar6);
        local_50._0_3_ = CONCAT12(local_50._2_1_ ^ bVar9,(undefined2)local_50);
        local_50 = CONCAT13(local_50._3_1_ ^ bVar10,(uint3)local_50);
        AES_decrypt((uchar *)&local_5c,(uchar *)puVar16,key);
        local_50._3_1_ = local_50._3_1_ ^ bVar10;
        local_50._2_1_ = local_50._2_1_ ^ bVar9;
        local_50._1_1_ = local_50._1_1_ ^ bVar7;
        local_50._0_1_ = (byte)local_50 ^ bVar6;
        local_54._3_1_ = local_54._3_1_ ^ bVar5;
        local_54._2_1_ = bVar4 ^ local_54._2_1_;
        local_54._1_1_ = local_54._1_1_ ^ bVar3;
        local_54._0_1_ = (byte)local_54 ^ bVar2;
        local_58._3_1_ = local_58._3_1_ ^ bVar1;
        local_58._2_1_ = local_58._2_1_ ^ bVar23;
        local_58._1_1_ = bVar21 ^ local_58._1_1_;
        local_58._0_1_ = bVar17 ^ (byte)local_58;
        local_5c._3_1_ = bVar26 ^ local_5c._3_1_;
        local_5c._2_1_ = bVar11 ^ local_5c._2_1_;
        local_5c._1_1_ = bVar24 ^ local_5c._1_1_;
        local_5c._0_1_ = bVar8 ^ (byte)local_5c;
        bVar8 = *(byte *)puVar16 ^ *ivec;
        *(byte *)puVar16 = bVar8;
        bVar24 = *(byte *)((int)ivec + 1) ^ *(byte *)((int)puVar16 + 1);
        *(byte *)((int)puVar16 + 1) = bVar24;
        bVar11 = *(byte *)((int)ivec + 2) ^ *(byte *)((int)puVar16 + 2);
        *(byte *)((int)puVar16 + 2) = bVar11;
        bVar26 = *(byte *)((int)ivec + 3) ^ *(byte *)((int)puVar16 + 3);
        *(byte *)((int)puVar16 + 3) = bVar26;
        bVar17 = *(byte *)(puVar16 + 1) ^ *(byte *)((int)ivec + 4);
        *(byte *)(puVar16 + 1) = bVar17;
        bVar21 = *(byte *)((int)puVar16 + 5) ^ *(byte *)((int)ivec + 5);
        *(byte *)((int)puVar16 + 5) = bVar21;
        bVar23 = *(byte *)((int)puVar16 + 6) ^ *(byte *)((int)ivec + 6);
        *(byte *)((int)puVar16 + 6) = bVar23;
        bVar1 = *(byte *)((int)puVar16 + 7) ^ *(byte *)((int)ivec + 7);
        *(byte *)((int)puVar16 + 7) = bVar1;
        bVar2 = *(byte *)(puVar16 + 2) ^ *(byte *)((int)ivec + 8);
        *(byte *)(puVar16 + 2) = bVar2;
        bVar3 = *(byte *)((int)ivec + 9) ^ *(byte *)((int)puVar16 + 9);
        *(byte *)((int)puVar16 + 9) = bVar3;
        bVar4 = *(byte *)((int)ivec + 10) ^ *(byte *)((int)puVar16 + 10);
        *(byte *)((int)puVar16 + 10) = bVar4;
        bVar5 = *(byte *)((int)ivec + 0xb) ^ *(byte *)((int)puVar16 + 0xb);
        *(byte *)((int)puVar16 + 0xb) = bVar5;
        bVar6 = *(byte *)((int)ivec + 0xc) ^ *(byte *)(puVar16 + 3);
        *(byte *)(puVar16 + 3) = bVar6;
        bVar7 = *(byte *)((int)ivec + 0xd) ^ *(byte *)((int)puVar16 + 0xd);
        *(byte *)((int)puVar16 + 0xd) = bVar7;
        bVar9 = *(byte *)((int)ivec + 0xe) ^ *(byte *)((int)puVar16 + 0xe);
        *(byte *)((int)puVar16 + 0xe) = bVar9;
        bVar10 = *(byte *)((int)ivec + 0xf) ^ *(byte *)((int)puVar16 + 0xf);
        *(byte *)((int)puVar16 + 0xf) = bVar10;
        local_3c = local_4c;
        uStack_38 = uStack_48;
        uStack_34 = uStack_44;
        uStack_30 = uStack_40;
        if (local_a0 < 0x10) break;
        local_a0 = local_a0 - 0x10;
        puVar16 = puVar16 + 4;
        ivec = (uchar *)&local_3c;
      }
    }
  }
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

