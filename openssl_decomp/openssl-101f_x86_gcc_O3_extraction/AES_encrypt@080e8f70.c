
void AES_encrypt(uchar *in,uchar *out,AES_KEY *key)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  AES_KEY *pAVar12;
  uint local_20;
  int local_18;
  
  local_20 = (uint)in[1] << 0x10 ^ (uint)*in << 0x18 ^ (uint)in[3] ^ (uint)in[2] << 8 ^
             key->rd_key[0];
  uVar10 = (uint)in[4] << 0x18 ^ (uint)in[5] << 0x10 ^ (uint)in[7] ^ (uint)in[6] << 8 ^
           key->rd_key[1];
  uVar9 = (uint)in[8] << 0x18 ^ (uint)in[9] << 0x10 ^ (uint)in[0xb] ^ (uint)in[10] << 8 ^
          key->rd_key[2];
  uVar8 = (uint)in[0xe] << 8 ^ (uint)in[0xf] ^ (uint)in[0xd] << 0x10 ^ (uint)in[0xc] << 0x18 ^
          key->rd_key[3];
  iVar11 = key->rounds >> 1;
  pAVar12 = key;
  local_18 = iVar11;
  while( true ) {
    uVar5 = *(uint *)(Te0 + (local_20 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar8 & 0xff) * 4) ^
            pAVar12->rd_key[4] ^ *(uint *)(Te1 + (uVar10 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Te2 + (uVar9 >> 8 & 0xff) * 4);
    uVar6 = *(uint *)(Te0 + (uVar10 >> 0x18) * 4) ^ *(uint *)(Te3 + (local_20 & 0xff) * 4) ^
            pAVar12->rd_key[5] ^ *(uint *)(Te1 + (uVar9 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Te2 + (uVar8 >> 8 & 0xff) * 4);
    uVar7 = *(uint *)(Te0 + (uVar9 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar10 & 0xff) * 4) ^
            pAVar12->rd_key[6] ^ *(uint *)(Te1 + (uVar8 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Te2 + (local_20 >> 8 & 0xff) * 4);
    uVar8 = *(uint *)(Te0 + (uVar8 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar9 & 0xff) * 4) ^
            pAVar12->rd_key[7] ^ *(uint *)(Te1 + (local_20 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Te2 + (uVar10 >> 8 & 0xff) * 4);
    local_18 = local_18 + -1;
    if (local_18 == 0) break;
    local_20 = *(uint *)(Te0 + (uVar5 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar8 & 0xff) * 4) ^
               ((AES_KEY *)(pAVar12->rd_key + 8))->rd_key[0] ^
               *(uint *)(Te1 + (uVar6 >> 0x10 & 0xff) * 4) ^
               *(uint *)(Te2 + (uVar7 >> 8 & 0xff) * 4);
    uVar10 = *(uint *)(Te0 + (uVar6 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar5 & 0xff) * 4) ^
             pAVar12->rd_key[9] ^ *(uint *)(Te1 + (uVar7 >> 0x10 & 0xff) * 4) ^
             *(uint *)(Te2 + (uVar8 >> 8 & 0xff) * 4);
    uVar9 = *(uint *)(Te0 + (uVar7 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar6 & 0xff) * 4) ^
            pAVar12->rd_key[10] ^ *(uint *)(Te1 + (uVar8 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Te2 + (uVar5 >> 8 & 0xff) * 4);
    uVar8 = *(uint *)(Te0 + (uVar8 >> 0x18) * 4) ^ *(uint *)(Te3 + (uVar7 & 0xff) * 4) ^
            pAVar12->rd_key[0xb] ^ *(uint *)(Te1 + (uVar5 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Te2 + (uVar6 >> 8 & 0xff) * 4);
    pAVar12 = (AES_KEY *)(pAVar12->rd_key + 8);
  }
  puVar4 = key->rd_key + iVar11 * 8;
  uVar9 = *puVar4;
  uVar10 = *(uint *)(Te2 + (uVar5 >> 0x18) * 4) & 0xff000000 ^ (uint)(byte)Te1[(uVar8 & 0xff) * 4] ^
           uVar9;
  uVar2 = *(undefined4 *)(Te3 + (uVar6 >> 0x10 & 0xff) * 4);
  uVar3 = *(undefined4 *)(Te0 + (uVar7 >> 8 & 0xff) * 4);
  *out = (uchar)(uVar10 >> 0x18);
  out[3] = (uchar)uVar10;
  out[1] = (byte)(uVar9 >> 0x10) ^ (byte)((uint)uVar2 >> 0x10);
  out[2] = (byte)(uVar9 >> 8) ^ (byte)((uint)uVar3 >> 8);
  uVar9 = puVar4[1];
  uVar10 = *(uint *)(Te2 + (uVar6 >> 0x18) * 4) & 0xff000000 ^ (uint)(byte)Te1[(uVar5 & 0xff) * 4] ^
           uVar9;
  uVar2 = *(undefined4 *)(Te3 + (uVar7 >> 0x10 & 0xff) * 4);
  uVar3 = *(undefined4 *)(Te0 + (uVar8 >> 8 & 0xff) * 4);
  out[4] = (uchar)(uVar10 >> 0x18);
  out[7] = (uchar)uVar10;
  out[5] = (byte)(uVar9 >> 0x10) ^ (byte)((uint)uVar2 >> 0x10);
  out[6] = (byte)(uVar9 >> 8) ^ (byte)((uint)uVar3 >> 8);
  uVar9 = puVar4[2];
  uVar10 = *(uint *)(Te2 + (uVar7 >> 0x18) * 4) & 0xff000000 ^ (uint)(byte)Te1[(uVar6 & 0xff) * 4] ^
           uVar9;
  uVar2 = *(undefined4 *)(Te3 + (uVar8 >> 0x10 & 0xff) * 4);
  uVar8 = *(uint *)(Te2 + (uVar8 >> 0x18) * 4);
  bVar1 = Te1[(uVar7 & 0xff) * 4];
  uVar3 = *(undefined4 *)(Te0 + (uVar5 >> 8 & 0xff) * 4);
  out[8] = (uchar)(uVar10 >> 0x18);
  out[0xb] = (uchar)uVar10;
  out[9] = (byte)(uVar9 >> 0x10) ^ (byte)((uint)uVar2 >> 0x10);
  out[10] = (byte)(uVar9 >> 8) ^ (byte)((uint)uVar3 >> 8);
  uVar9 = puVar4[3];
  uVar8 = (uint)bVar1 ^ uVar8 & 0xff000000 ^ uVar9;
  uVar2 = *(undefined4 *)(Te3 + (uVar5 >> 0x10 & 0xff) * 4);
  uVar3 = *(undefined4 *)(Te0 + (uVar6 >> 8 & 0xff) * 4);
  out[0xf] = (uchar)uVar8;
  out[0xc] = (uchar)(uVar8 >> 0x18);
  out[0xd] = (byte)(uVar9 >> 0x10) ^ (byte)((uint)uVar2 >> 0x10);
  out[0xe] = (byte)(uVar9 >> 8) ^ (byte)((uint)uVar3 >> 8);
  return;
}

