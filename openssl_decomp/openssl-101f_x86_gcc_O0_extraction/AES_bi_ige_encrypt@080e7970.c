
/* WARNING: Could not reconcile some variable overlaps */

void AES_bi_ige_encrypt(uchar *in,uchar *out,size_t length,AES_KEY *key,AES_KEY *key2,uchar *ivec,
                       int enc)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  byte bVar12;
  byte bVar13;
  byte *out_00;
  byte *pbVar14;
  undefined4 *puVar15;
  size_t sVar16;
  undefined4 *puVar17;
  int in_GS_OFFSET;
  byte local_69;
  byte local_5c;
  byte local_5b;
  byte local_5a;
  byte local_59;
  byte local_58;
  byte local_57;
  byte local_56;
  byte local_55;
  uint local_50;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  int local_20;
  undefined4 *in_00;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((in == (uchar *)0x0) || (out == (uchar *)0x0)) || (key == (AES_KEY *)0x0)) ||
     (ivec == (uchar *)0x0)) {
    OpenSSLDie("aes_ige.c",0xe3,"in && out && key && ivec");
  }
  if (1 < (uint)enc) {
    OpenSSLDie("aes_ige.c",0xe4,"(AES_ENCRYPT == enc)||(AES_DECRYPT == enc)");
  }
  if ((length & 0xf) != 0) {
    OpenSSLDie("aes_ige.c",0xe5,"(length%AES_BLOCK_SIZE) == 0");
  }
  if (enc == 1) {
    if (0xf < length) {
      bVar13 = *ivec;
      pbVar10 = ivec;
      pbVar14 = out;
      sVar16 = length;
      puVar11 = (undefined4 *)(ivec + 0x10);
      do {
        *pbVar14 = bVar13 ^ *in;
        pbVar14[1] = *(byte *)((int)in + 1) ^ pbVar10[1];
        pbVar14[2] = *(byte *)((int)in + 2) ^ pbVar10[2];
        pbVar14[3] = *(byte *)((int)in + 3) ^ pbVar10[3];
        pbVar14[4] = *(byte *)((int)in + 4) ^ pbVar10[4];
        pbVar14[5] = *(byte *)((int)in + 5) ^ pbVar10[5];
        pbVar14[6] = *(byte *)((int)in + 6) ^ pbVar10[6];
        pbVar14[7] = *(byte *)((int)in + 7) ^ pbVar10[7];
        pbVar14[8] = *(byte *)((int)in + 8) ^ pbVar10[8];
        pbVar14[9] = *(byte *)((int)in + 9) ^ pbVar10[9];
        pbVar14[10] = *(byte *)((int)in + 10) ^ pbVar10[10];
        pbVar14[0xb] = *(byte *)((int)in + 0xb) ^ pbVar10[0xb];
        pbVar14[0xc] = *(byte *)((int)in + 0xc) ^ pbVar10[0xc];
        pbVar14[0xd] = *(byte *)((int)in + 0xd) ^ pbVar10[0xd];
        pbVar14[0xe] = *(byte *)((int)in + 0xe) ^ pbVar10[0xe];
        pbVar14[0xf] = *(byte *)((int)in + 0xf) ^ pbVar10[0xf];
        AES_encrypt(pbVar14,pbVar14,key);
        bVar13 = *pbVar14 ^ *(byte *)puVar11;
        *pbVar14 = bVar13;
        pbVar14[1] = pbVar14[1] ^ *(byte *)((int)puVar11 + 1);
        pbVar14[2] = pbVar14[2] ^ *(byte *)((int)puVar11 + 2);
        pbVar14[3] = pbVar14[3] ^ *(byte *)((int)puVar11 + 3);
        pbVar14[4] = pbVar14[4] ^ *(byte *)(puVar11 + 1);
        pbVar14[5] = pbVar14[5] ^ *(byte *)((int)puVar11 + 5);
        pbVar14[6] = pbVar14[6] ^ *(byte *)((int)puVar11 + 6);
        pbVar14[7] = pbVar14[7] ^ *(byte *)((int)puVar11 + 7);
        pbVar14[8] = pbVar14[8] ^ *(byte *)(puVar11 + 2);
        pbVar14[9] = pbVar14[9] ^ *(byte *)((int)puVar11 + 9);
        pbVar14[10] = pbVar14[10] ^ *(byte *)((int)puVar11 + 10);
        pbVar14[0xb] = pbVar14[0xb] ^ *(byte *)((int)puVar11 + 0xb);
        pbVar14[0xc] = pbVar14[0xc] ^ *(byte *)(puVar11 + 3);
        pbVar14[0xd] = pbVar14[0xd] ^ *(byte *)((int)puVar11 + 0xd);
        pbVar14[0xe] = pbVar14[0xe] ^ *(byte *)((int)puVar11 + 0xe);
        sVar16 = sVar16 - 0x10;
        pbVar14[0xf] = pbVar14[0xf] ^ *(byte *)((int)puVar11 + 0xf);
        local_30 = *(undefined4 *)in;
        local_2c = *(undefined4 *)((int)in + 4);
        local_28 = *(undefined4 *)((int)in + 8);
        local_24 = *(uint *)((int)in + 0xc);
        pbVar10 = pbVar14;
        pbVar14 = pbVar14 + 0x10;
        puVar11 = &local_30;
        in = (uchar *)((int)in + 0x10);
      } while (0xf < sVar16);
      puVar11 = (undefined4 *)(ivec + 0x20);
      puVar15 = (undefined4 *)(ivec + 0x30);
      puVar17 = (undefined4 *)(out + (length - 0x10 & 0xfffffff0) + 0x10);
      do {
        in_00 = puVar17 + -4;
        local_40 = *in_00;
        local_3c = puVar17[-3];
        local_38 = puVar17[-2];
        local_34 = puVar17[-1];
        *(byte *)in_00 = *(byte *)in_00 ^ *(byte *)puVar11;
        *(byte *)((int)puVar17 + -0xf) =
             *(byte *)((int)puVar17 + -0xf) ^ *(byte *)((int)puVar11 + 1);
        *(byte *)((int)puVar17 + -0xe) =
             *(byte *)((int)puVar17 + -0xe) ^ *(byte *)((int)puVar11 + 2);
        *(byte *)((int)puVar17 + -0xd) =
             *(byte *)((int)puVar17 + -0xd) ^ *(byte *)((int)puVar11 + 3);
        *(byte *)(puVar17 + -3) = *(byte *)(puVar17 + -3) ^ *(byte *)(puVar11 + 1);
        *(byte *)((int)puVar17 + -0xb) =
             *(byte *)((int)puVar17 + -0xb) ^ *(byte *)((int)puVar11 + 5);
        *(byte *)((int)puVar17 + -10) = *(byte *)((int)puVar17 + -10) ^ *(byte *)((int)puVar11 + 6);
        *(byte *)((int)puVar17 + -9) = *(byte *)((int)puVar17 + -9) ^ *(byte *)((int)puVar11 + 7);
        *(byte *)(puVar17 + -2) = *(byte *)(puVar17 + -2) ^ *(byte *)(puVar11 + 2);
        *(byte *)((int)puVar17 + -7) = *(byte *)((int)puVar17 + -7) ^ *(byte *)((int)puVar11 + 9);
        *(byte *)((int)puVar17 + -6) = *(byte *)((int)puVar17 + -6) ^ *(byte *)((int)puVar11 + 10);
        *(byte *)((int)puVar17 + -5) = *(byte *)((int)puVar17 + -5) ^ *(byte *)((int)puVar11 + 0xb);
        *(byte *)(puVar17 + -1) = *(byte *)(puVar17 + -1) ^ *(byte *)(puVar11 + 3);
        *(byte *)((int)puVar17 + -3) = *(byte *)((int)puVar17 + -3) ^ *(byte *)((int)puVar11 + 0xd);
        *(byte *)((int)puVar17 + -2) = *(byte *)((int)puVar17 + -2) ^ *(byte *)((int)puVar11 + 0xe);
        *(byte *)((int)puVar17 + -1) = *(byte *)((int)puVar17 + -1) ^ *(byte *)((int)puVar11 + 0xf);
        AES_encrypt((uchar *)in_00,(uchar *)in_00,key);
        *(byte *)in_00 = *(byte *)in_00 ^ *(byte *)puVar15;
        *(byte *)((int)puVar17 + -0xf) =
             *(byte *)((int)puVar17 + -0xf) ^ *(byte *)((int)puVar15 + 1);
        *(byte *)((int)puVar17 + -0xe) =
             *(byte *)((int)puVar17 + -0xe) ^ *(byte *)((int)puVar15 + 2);
        *(byte *)((int)puVar17 + -0xd) =
             *(byte *)((int)puVar17 + -0xd) ^ *(byte *)((int)puVar15 + 3);
        *(byte *)(puVar17 + -3) = *(byte *)(puVar17 + -3) ^ *(byte *)(puVar15 + 1);
        *(byte *)((int)puVar17 + -0xb) =
             *(byte *)((int)puVar17 + -0xb) ^ *(byte *)((int)puVar15 + 5);
        *(byte *)((int)puVar17 + -10) = *(byte *)((int)puVar17 + -10) ^ *(byte *)((int)puVar15 + 6);
        *(byte *)((int)puVar17 + -9) = *(byte *)((int)puVar17 + -9) ^ *(byte *)((int)puVar15 + 7);
        *(byte *)(puVar17 + -2) = *(byte *)(puVar17 + -2) ^ *(byte *)(puVar15 + 2);
        *(byte *)((int)puVar17 + -7) = *(byte *)((int)puVar17 + -7) ^ *(byte *)((int)puVar15 + 9);
        *(byte *)((int)puVar17 + -6) = *(byte *)((int)puVar17 + -6) ^ *(byte *)((int)puVar15 + 10);
        *(byte *)((int)puVar17 + -5) = *(byte *)((int)puVar17 + -5) ^ *(byte *)((int)puVar15 + 0xb);
        *(byte *)(puVar17 + -1) = *(byte *)(puVar17 + -1) ^ *(byte *)(puVar15 + 3);
        *(byte *)((int)puVar17 + -3) = *(byte *)((int)puVar17 + -3) ^ *(byte *)((int)puVar15 + 0xd);
        *(byte *)((int)puVar17 + -2) = *(byte *)((int)puVar17 + -2) ^ *(byte *)((int)puVar15 + 0xe);
        *(byte *)((int)puVar17 + -1) = *(byte *)((int)puVar17 + -1) ^ *(byte *)((int)puVar15 + 0xf);
        local_30 = local_40;
        local_2c = local_3c;
        local_28 = local_38;
        local_24 = local_34;
        puVar11 = in_00;
        puVar15 = &local_30;
        puVar17 = in_00;
      } while (&DAT_0000000f <
               (byte *)((int)in_00 + (length - (int)(out + (length - 0x10 & 0xfffffff0) + 0x10))));
    }
  }
  else if (0xf < length) {
    local_69 = ivec[0x3f];
    pbVar10 = ivec + 0x30;
    pbVar14 = out + length;
    sVar16 = length;
    puVar11 = (undefined4 *)(ivec + 0x20);
    do {
      uVar1 = *(undefined4 *)(in + (sVar16 - 0x10));
      uVar2 = *(undefined4 *)(in + (sVar16 - 8));
      out_00 = pbVar14 + -0x10;
      uVar3 = *(undefined4 *)(in + (sVar16 - 0xc));
      uVar4 = *(uint *)(in + (sVar16 - 4));
      local_40._0_1_ = (byte)uVar1;
      local_40._0_2_ = CONCAT11((byte)((uint)uVar1 >> 8) ^ pbVar10[1],(byte)local_40 ^ *pbVar10);
      local_40._0_3_ = CONCAT12((byte)((uint)uVar1 >> 0x10) ^ pbVar10[2],(undefined2)local_40);
      local_40 = CONCAT13((byte)((uint)uVar1 >> 0x18) ^ pbVar10[3],(undefined3)local_40);
      local_3c._0_1_ = (byte)uVar3;
      local_3c._0_2_ = CONCAT11((byte)((uint)uVar3 >> 8) ^ pbVar10[5],(byte)local_3c ^ pbVar10[4]);
      local_3c._0_3_ = CONCAT12((byte)((uint)uVar3 >> 0x10) ^ pbVar10[6],(undefined2)local_3c);
      local_3c = CONCAT13((byte)((uint)uVar3 >> 0x18) ^ pbVar10[7],(undefined3)local_3c);
      local_38._0_1_ = (byte)uVar2;
      local_38._0_2_ = CONCAT11((byte)((uint)uVar2 >> 8) ^ pbVar10[9],(byte)local_38 ^ pbVar10[8]);
      local_38._0_3_ = CONCAT12((byte)((uint)uVar2 >> 0x10) ^ pbVar10[10],(undefined2)local_38);
      local_38 = CONCAT13((byte)((uint)uVar2 >> 0x18) ^ pbVar10[0xb],(undefined3)local_38);
      local_34._0_1_ = (byte)uVar4;
      local_34._0_2_ = CONCAT11((byte)(uVar4 >> 8) ^ pbVar10[0xd],(byte)local_34 ^ pbVar10[0xc]);
      local_34._0_3_ = CONCAT12((byte)(uVar4 >> 0x10) ^ pbVar10[0xe],(ushort)local_34);
      local_34 = CONCAT13((byte)(uVar4 >> 0x18) ^ local_69,(uint3)local_34);
      AES_decrypt((uchar *)&local_40,out_00,key);
      *out_00 = *out_00 ^ *(byte *)puVar11;
      pbVar14[-0xf] = pbVar14[-0xf] ^ *(byte *)((int)puVar11 + 1);
      pbVar14[-0xe] = pbVar14[-0xe] ^ *(byte *)((int)puVar11 + 2);
      pbVar14[-0xd] = pbVar14[-0xd] ^ *(byte *)((int)puVar11 + 3);
      pbVar14[-0xc] = pbVar14[-0xc] ^ *(byte *)(puVar11 + 1);
      pbVar14[-0xb] = pbVar14[-0xb] ^ *(byte *)((int)puVar11 + 5);
      pbVar14[-10] = pbVar14[-10] ^ *(byte *)((int)puVar11 + 6);
      pbVar14[-9] = pbVar14[-9] ^ *(byte *)((int)puVar11 + 7);
      pbVar14[-8] = pbVar14[-8] ^ *(byte *)(puVar11 + 2);
      pbVar14[-7] = pbVar14[-7] ^ *(byte *)((int)puVar11 + 9);
      pbVar14[-6] = pbVar14[-6] ^ *(byte *)((int)puVar11 + 10);
      pbVar14[-5] = pbVar14[-5] ^ *(byte *)((int)puVar11 + 0xb);
      pbVar14[-4] = pbVar14[-4] ^ *(byte *)(puVar11 + 3);
      pbVar14[-3] = pbVar14[-3] ^ *(byte *)((int)puVar11 + 0xd);
      sVar16 = sVar16 - 0x10;
      pbVar14[-2] = pbVar14[-2] ^ *(byte *)((int)puVar11 + 0xe);
      local_69 = pbVar14[-1] ^ *(byte *)((int)puVar11 + 0xf);
      pbVar14[-1] = local_69;
      pbVar10 = out_00;
      pbVar14 = out_00;
      puVar11 = &local_30;
      local_30 = uVar1;
      local_2c = uVar3;
      local_28 = uVar2;
      local_24 = uVar4;
    } while (0xf < sVar16);
    local_50 = length - 0x10;
    bVar13 = ivec[0x1c];
    bVar12 = ivec[0x1d];
    local_5a = ivec[0x10];
    local_55 = ivec[0x1e];
    local_59 = ivec[0x11];
    bVar5 = ivec[0x12];
    local_57 = ivec[0x13];
    local_58 = ivec[0x14];
    local_5b = ivec[0x15];
    bVar6 = ivec[0x16];
    local_69 = ivec[0x17];
    bVar7 = ivec[0x18];
    bVar8 = ivec[0x19];
    local_5c = ivec[0x1a];
    bVar9 = ivec[0x1b];
    local_56 = ivec[0x1f];
    puVar11 = (undefined4 *)(out + length + (~local_50 & 0xfffffff0));
    while( true ) {
      uVar1 = *puVar11;
      uVar2 = puVar11[1];
      uVar4 = puVar11[3];
      uVar3 = puVar11[2];
      local_40._0_1_ = (byte)uVar1;
      local_40._0_2_ = CONCAT11((byte)((uint)uVar1 >> 8) ^ local_59,(byte)local_40 ^ local_5a);
      local_40._0_3_ = CONCAT12((byte)((uint)uVar1 >> 0x10) ^ bVar5,(undefined2)local_40);
      local_40 = CONCAT13((byte)((uint)uVar1 >> 0x18) ^ local_57,(undefined3)local_40);
      local_3c._0_1_ = (byte)uVar2;
      local_3c._0_2_ = CONCAT11((byte)((uint)uVar2 >> 8) ^ local_5b,(byte)local_3c ^ local_58);
      local_3c._0_3_ = CONCAT12((byte)((uint)uVar2 >> 0x10) ^ bVar6,(undefined2)local_3c);
      local_3c = CONCAT13((byte)((uint)uVar2 >> 0x18) ^ local_69,(undefined3)local_3c);
      local_34._0_1_ = (byte)uVar4;
      local_38._0_1_ = (byte)uVar3;
      local_38._0_2_ = CONCAT11((byte)((uint)uVar3 >> 8) ^ bVar8,(byte)local_38 ^ bVar7);
      local_38._0_3_ = CONCAT12((byte)((uint)uVar3 >> 0x10) ^ local_5c,(undefined2)local_38);
      local_38 = CONCAT13((byte)((uint)uVar3 >> 0x18) ^ bVar9,(undefined3)local_38);
      local_34._2_1_ = (byte)((uVar4 & 0xffffff00) >> 0x10);
      local_34._0_3_ = CONCAT12(local_34._2_1_ ^ local_55,(short)(uVar4 & 0xffffff00));
      local_34._1_1_ = (byte)((uint)(uint3)local_34 >> 8);
      local_34._0_2_ = CONCAT11(local_34._1_1_ ^ bVar12,(byte)local_34 ^ bVar13);
      local_34 = (uint3)local_34 & 0xff0000 | (uint)(ushort)local_34 |
                 (uint)(byte)((byte)(uVar4 >> 0x18) ^ local_56) << 0x18;
      AES_decrypt((uchar *)&local_40,(uchar *)puVar11,key);
      local_5a = *(byte *)puVar11 ^ *ivec;
      *(byte *)puVar11 = local_5a;
      local_59 = *(byte *)((int)puVar11 + 1) ^ *(byte *)((int)ivec + 1);
      *(byte *)((int)puVar11 + 1) = local_59;
      bVar5 = *(byte *)((int)puVar11 + 2) ^ *(byte *)((int)ivec + 2);
      *(byte *)((int)puVar11 + 2) = bVar5;
      local_57 = *(byte *)((int)puVar11 + 3) ^ *(byte *)((int)ivec + 3);
      *(byte *)((int)puVar11 + 3) = local_57;
      local_58 = *(byte *)(puVar11 + 1) ^ *(byte *)((int)ivec + 4);
      *(byte *)(puVar11 + 1) = local_58;
      local_5b = *(byte *)((int)puVar11 + 5) ^ *(byte *)((int)ivec + 5);
      *(byte *)((int)puVar11 + 5) = local_5b;
      bVar6 = *(byte *)((int)puVar11 + 6) ^ *(byte *)((int)ivec + 6);
      *(byte *)((int)puVar11 + 6) = bVar6;
      local_69 = *(byte *)((int)puVar11 + 7) ^ *(byte *)((int)ivec + 7);
      *(byte *)((int)puVar11 + 7) = local_69;
      bVar7 = *(byte *)(puVar11 + 2) ^ *(byte *)((int)ivec + 8);
      *(byte *)(puVar11 + 2) = bVar7;
      bVar8 = *(byte *)((int)puVar11 + 9) ^ *(byte *)((int)ivec + 9);
      *(byte *)((int)puVar11 + 9) = bVar8;
      local_5c = *(byte *)((int)puVar11 + 10) ^ *(byte *)((int)ivec + 10);
      *(byte *)((int)puVar11 + 10) = local_5c;
      bVar9 = *(byte *)((int)puVar11 + 0xb) ^ *(byte *)((int)ivec + 0xb);
      *(byte *)((int)puVar11 + 0xb) = bVar9;
      bVar13 = *(byte *)(puVar11 + 3) ^ *(byte *)((int)ivec + 0xc);
      *(byte *)(puVar11 + 3) = bVar13;
      bVar12 = *(byte *)((int)puVar11 + 0xd) ^ *(byte *)((int)ivec + 0xd);
      *(byte *)((int)puVar11 + 0xd) = bVar12;
      local_55 = *(byte *)((int)puVar11 + 0xe) ^ *(byte *)((int)ivec + 0xe);
      *(byte *)((int)puVar11 + 0xe) = local_55;
      local_56 = *(byte *)((int)puVar11 + 0xf) ^ *(byte *)((int)ivec + 0xf);
      *(byte *)((int)puVar11 + 0xf) = local_56;
      local_30 = uVar1;
      local_2c = uVar2;
      local_28 = uVar3;
      local_24 = uVar4;
      if (local_50 < 0x10) break;
      local_50 = local_50 - 0x10;
      puVar11 = puVar11 + 4;
      ivec = (uchar *)&local_30;
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

