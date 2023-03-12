
void AES_decrypt(uchar *in,uchar *out,AES_KEY *key)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  AES_KEY *pAVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int local_30;
  
  iVar13 = key->rounds >> 1;
  uVar15 = (uint)*in << 0x18 ^ (uint)in[1] << 0x10 ^ (uint)in[3] ^ (uint)in[2] << 8 ^ key->rd_key[0]
  ;
  uVar10 = (uint)in[4] << 0x18 ^ (uint)in[5] << 0x10 ^ (uint)in[7] ^ (uint)in[6] << 8 ^
           key->rd_key[1];
  uVar16 = (uint)in[8] << 0x18 ^ (uint)in[9] << 0x10 ^ (uint)in[0xb] ^ (uint)in[10] << 8 ^
           key->rd_key[2];
  uVar17 = (uint)in[0xc] << 0x18 ^ (uint)in[0xd] << 0x10 ^ (uint)in[0xf] ^ (uint)in[0xe] << 8 ^
           key->rd_key[3];
  pAVar14 = key;
  local_30 = iVar13;
  while( true ) {
    local_30 = local_30 + -1;
    uVar9 = *(uint *)(Td0 + (uVar15 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar10 & 0xff) * 4) ^
            pAVar14->rd_key[4] ^ *(uint *)(Td1 + ((uVar17 << 8) >> 0x18) * 4) ^
            *(uint *)(Td2 + ((uVar16 << 0x10) >> 0x18) * 4);
    uVar8 = *(uint *)(Td0 + (uVar10 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar16 & 0xff) * 4) ^
            pAVar14->rd_key[5] ^ *(uint *)(Td1 + ((uVar15 << 8) >> 0x18) * 4) ^
            *(uint *)(Td2 + ((uVar17 << 0x10) >> 0x18) * 4);
    uVar11 = *(uint *)(Td0 + (uVar16 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar17 & 0xff) * 4) ^
             pAVar14->rd_key[6] ^ *(uint *)(Td1 + ((uVar10 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar15 << 0x10) >> 0x18) * 4);
    uVar17 = *(uint *)(Td0 + (uVar17 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar15 & 0xff) * 4) ^
             pAVar14->rd_key[7] ^ *(uint *)(Td1 + ((uVar16 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar10 << 0x10) >> 0x18) * 4);
    if (local_30 == 0) break;
    uVar15 = *(uint *)(Td0 + (uVar9 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar8 & 0xff) * 4) ^
             ((AES_KEY *)(pAVar14->rd_key + 8))->rd_key[0] ^
             *(uint *)(Td1 + ((uVar17 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar11 << 0x10) >> 0x18) * 4);
    uVar16 = *(uint *)(Td0 + (uVar11 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar17 & 0xff) * 4) ^
             pAVar14->rd_key[10] ^ *(uint *)(Td1 + ((uVar8 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar9 << 0x10) >> 0x18) * 4);
    uVar10 = *(uint *)(Td0 + (uVar8 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar11 & 0xff) * 4) ^
             pAVar14->rd_key[9] ^ *(uint *)(Td1 + ((uVar9 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar17 << 0x10) >> 0x18) * 4);
    uVar17 = *(uint *)(Td0 + (uVar17 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar9 & 0xff) * 4) ^
             pAVar14->rd_key[0xb] ^ *(uint *)(Td1 + ((uVar11 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar8 << 0x10) >> 0x18) * 4);
    pAVar14 = (AES_KEY *)(pAVar14->rd_key + 8);
  }
  puVar12 = key->rd_key + iVar13 * 8;
  bVar1 = Td4[uVar8 >> 0x18];
  bVar2 = Td4[(uVar17 << 0x10) >> 0x18];
  uVar10 = (uint)(byte)Td4[uVar9 >> 0x18] << 0x18 ^ (uint)(byte)Td4[uVar8 & 0xff] ^
           (uint)(byte)Td4[(uVar17 << 8) >> 0x18] << 0x10 ^
           (uint)(byte)Td4[(uVar11 << 0x10) >> 0x18] << 8 ^ *puVar12;
  bVar3 = Td4[(uVar9 << 8) >> 0x18];
  bVar4 = Td4[uVar11 & 0xff];
  out[3] = (uchar)uVar10;
  *out = (uchar)(uVar10 >> 0x18);
  out[1] = (uchar)(uVar10 >> 0x10);
  out[2] = (uchar)(uVar10 >> 8);
  bVar5 = Td4[uVar11 >> 0x18];
  bVar6 = Td4[(uVar8 << 8) >> 0x18];
  bVar7 = Td4[uVar17 & 0xff];
  uVar10 = (uint)bVar1 << 0x18 ^ (uint)bVar4 ^ (uint)bVar3 << 0x10 ^ (uint)bVar2 << 8 ^ puVar12[1];
  bVar1 = Td4[(uVar9 << 0x10) >> 0x18];
  out[7] = (uchar)uVar10;
  out[4] = (uchar)(uVar10 >> 0x18);
  out[5] = (uchar)(uVar10 >> 0x10);
  out[6] = (uchar)(uVar10 >> 8);
  bVar2 = Td4[(uVar11 << 8) >> 0x18];
  bVar3 = Td4[uVar17 >> 0x18];
  uVar10 = (uint)bVar5 << 0x18 ^ (uint)bVar7 ^ (uint)bVar6 << 0x10 ^ (uint)bVar1 << 8 ^ puVar12[2];
  bVar1 = Td4[uVar9 & 0xff];
  bVar4 = Td4[(uVar8 << 0x10) >> 0x18];
  out[0xb] = (uchar)uVar10;
  out[8] = (uchar)(uVar10 >> 0x18);
  out[9] = (uchar)(uVar10 >> 0x10);
  out[10] = (uchar)(uVar10 >> 8);
  uVar10 = (uint)bVar3 << 0x18 ^ (uint)bVar1 ^ (uint)bVar2 << 0x10 ^ (uint)bVar4 << 8 ^ puVar12[3];
  out[0xf] = (uchar)uVar10;
  out[0xc] = (uchar)(uVar10 >> 0x18);
  out[0xd] = (uchar)(uVar10 >> 0x10);
  out[0xe] = (uchar)(uVar10 >> 8);
  return;
}

