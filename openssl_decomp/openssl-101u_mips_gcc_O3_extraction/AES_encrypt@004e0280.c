
void AES_encrypt(uchar *in,uchar *out,AES_KEY *key)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  AES_KEY *pAVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  int local_30;
  
  iVar6 = key->rounds >> 1;
  uVar9 = (uint)*in << 0x18 ^ (uint)in[1] << 0x10 ^ (uint)in[3] ^ (uint)in[2] << 8 ^ key->rd_key[0];
  uVar3 = (uint)in[4] << 0x18 ^ (uint)in[5] << 0x10 ^ (uint)in[7] ^ (uint)in[6] << 8 ^
          key->rd_key[1];
  uVar10 = (uint)in[8] << 0x18 ^ (uint)in[9] << 0x10 ^ (uint)in[0xb] ^ (uint)in[10] << 8 ^
           key->rd_key[2];
  uVar12 = (uint)in[0xc] << 0x18 ^ (uint)in[0xd] << 0x10 ^ (uint)in[0xf] ^ (uint)in[0xe] << 8 ^
           key->rd_key[3];
  pAVar8 = key;
  local_30 = iVar6;
  while( true ) {
    local_30 = local_30 + -1;
    uVar2 = *(uint *)(Te0 + (uVar9 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar12 & 0xff) * 4) ^
            pAVar8->rd_key[4] ^ *(uint *)(Te1 + ((uVar3 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar10 << 0x10) >> 0x18) * 4);
    uVar1 = *(uint *)(Te0 + (uVar3 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar9 & 0xff) * 4) ^
            pAVar8->rd_key[5] ^ *(uint *)(Te1 + ((uVar10 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar12 << 0x10) >> 0x18) * 4);
    uVar4 = *(uint *)(Te0 + (uVar10 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar3 & 0xff) * 4) ^
            pAVar8->rd_key[6] ^ *(uint *)(Te1 + ((uVar12 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar9 << 0x10) >> 0x18) * 4);
    uVar12 = *(uint *)(Te0 + (uVar12 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar10 & 0xff) * 4) ^
             pAVar8->rd_key[7] ^ *(uint *)(Te1 + ((uVar9 << 8) >> 0x18) * 4) ^
             *(uint *)(Te2 + ((uVar3 << 0x10) >> 0x18) * 4);
    if (local_30 == 0) break;
    uVar9 = *(uint *)(Te0 + (uVar2 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar12 & 0xff) * 4) ^
            ((AES_KEY *)(pAVar8->rd_key + 8))->rd_key[0] ^
            *(uint *)(Te1 + ((uVar1 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar4 << 0x10) >> 0x18) * 4);
    uVar10 = *(uint *)(Te0 + (uVar4 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar1 & 0xff) * 4) ^
             pAVar8->rd_key[10] ^ *(uint *)(Te1 + ((uVar12 << 8) >> 0x18) * 4) ^
             *(uint *)(Te2 + ((uVar2 << 0x10) >> 0x18) * 4);
    uVar3 = *(uint *)(Te0 + (uVar1 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar2 & 0xff) * 4) ^
            pAVar8->rd_key[9] ^ *(uint *)(Te1 + ((uVar4 << 8) >> 0x18) * 4) ^
            *(uint *)(Te2 + ((uVar12 << 0x10) >> 0x18) * 4);
    uVar12 = *(uint *)(Te0 + (uVar12 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar4 & 0xff) * 4) ^
             pAVar8->rd_key[0xb] ^ *(uint *)(Te1 + ((uVar2 << 8) >> 0x18) * 4) ^
             *(uint *)(Te2 + ((uVar1 << 0x10) >> 0x18) * 4);
    pAVar8 = (AES_KEY *)(pAVar8->rd_key + 8);
  }
  puVar5 = key->rd_key + iVar6 * 8;
  uVar10 = *puVar5;
  uVar11 = *(undefined4 *)(Te3 + ((uVar1 << 8) >> 0x18) * 4);
  uVar7 = *(undefined4 *)(Te0 + ((uVar4 << 0x10) >> 0x18) * 4);
  uVar3 = *(uint *)(Te2 + (uVar2 >> 0x18) * 4) & 0xff000000 ^
          (uint)(byte)Te1[(uVar12 & 0xff) * 4 + 3] ^ uVar10;
  out[3] = (uchar)uVar3;
  uVar9 = *(uint *)(Te2 + (uVar1 >> 0x18) * 4);
  *out = (uchar)(uVar3 >> 0x18);
  out[1] = (byte)(uVar10 >> 0x10) ^ (byte)((uint)uVar11 >> 0x10);
  out[2] = (byte)(uVar10 >> 8) ^ (byte)((uint)uVar7 >> 8);
  uVar10 = puVar5[1];
  uVar11 = *(undefined4 *)(Te3 + ((uVar4 << 8) >> 0x18) * 4);
  uVar7 = *(undefined4 *)(Te0 + ((uVar12 << 0x10) >> 0x18) * 4);
  uVar3 = uVar9 & 0xff000000 ^ (uint)(byte)Te1[(uVar2 & 0xff) * 4 + 3] ^ uVar10;
  out[7] = (uchar)uVar3;
  uVar9 = *(uint *)(Te2 + (uVar4 >> 0x18) * 4);
  out[4] = (uchar)(uVar3 >> 0x18);
  out[5] = (byte)(uVar10 >> 0x10) ^ (byte)((uint)uVar11 >> 0x10);
  out[6] = (byte)(uVar10 >> 8) ^ (byte)((uint)uVar7 >> 8);
  uVar10 = puVar5[2];
  uVar11 = *(undefined4 *)(Te3 + ((uVar12 << 8) >> 0x18) * 4);
  uVar7 = *(undefined4 *)(Te0 + ((uVar2 << 0x10) >> 0x18) * 4);
  uVar3 = uVar9 & 0xff000000 ^ (uint)(byte)Te1[(uVar1 & 0xff) * 4 + 3] ^ uVar10;
  out[0xb] = (uchar)uVar3;
  uVar9 = *(uint *)(Te2 + (uVar12 >> 0x18) * 4);
  out[8] = (uchar)(uVar3 >> 0x18);
  out[10] = (byte)(uVar10 >> 8) ^ (byte)((uint)uVar7 >> 8);
  out[9] = (byte)(uVar10 >> 0x10) ^ (byte)((uint)uVar11 >> 0x10);
  uVar3 = puVar5[3];
  uVar11 = *(undefined4 *)(Te3 + ((uVar2 << 8) >> 0x18) * 4);
  uVar7 = *(undefined4 *)(Te0 + ((uVar1 << 0x10) >> 0x18) * 4);
  uVar9 = uVar9 & 0xff000000 ^ (uint)(byte)Te1[(uVar4 & 0xff) * 4 + 3] ^ uVar3;
  out[0xf] = (uchar)uVar9;
  out[0xc] = (uchar)(uVar9 >> 0x18);
  out[0xd] = (byte)(uVar3 >> 0x10) ^ (byte)((uint)uVar11 >> 0x10);
  out[0xe] = (byte)(uVar3 >> 8) ^ (byte)((uint)uVar7 >> 8);
  return;
}

