
void AES_decrypt(uchar *in,uchar *out,AES_KEY *key)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  AES_KEY *pAVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int local_30;
  
  iVar9 = key->rounds >> 1;
  uVar11 = (uint)*in << 0x18 ^ (uint)in[1] << 0x10 ^ (uint)in[3] ^ (uint)in[2] << 8 ^ key->rd_key[0]
  ;
  uVar6 = (uint)in[4] << 0x18 ^ (uint)in[5] << 0x10 ^ (uint)in[7] ^ (uint)in[6] << 8 ^
          key->rd_key[1];
  uVar12 = (uint)in[8] << 0x18 ^ (uint)in[9] << 0x10 ^ (uint)in[0xb] ^ (uint)in[10] << 8 ^
           key->rd_key[2];
  uVar13 = (uint)in[0xc] << 0x18 ^ (uint)in[0xd] << 0x10 ^ (uint)in[0xf] ^ (uint)in[0xe] << 8 ^
           key->rd_key[3];
  pAVar10 = key;
  local_30 = iVar9;
  while( true ) {
    local_30 = local_30 + -1;
    uVar5 = *(uint *)(Td0 + (uVar11 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar6 & 0xff) * 4) ^
            pAVar10->rd_key[4] ^ *(uint *)(Td1 + ((uVar13 << 8) >> 0x18) * 4) ^
            *(uint *)(Td2 + ((uVar12 << 0x10) >> 0x18) * 4);
    uVar4 = *(uint *)(Td0 + (uVar6 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar12 & 0xff) * 4) ^
            pAVar10->rd_key[5] ^ *(uint *)(Td1 + ((uVar11 << 8) >> 0x18) * 4) ^
            *(uint *)(Td2 + ((uVar13 << 0x10) >> 0x18) * 4);
    uVar7 = *(uint *)(Td0 + (uVar12 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar13 & 0xff) * 4) ^
            pAVar10->rd_key[6] ^ *(uint *)(Td1 + ((uVar6 << 8) >> 0x18) * 4) ^
            *(uint *)(Td2 + ((uVar11 << 0x10) >> 0x18) * 4);
    uVar13 = *(uint *)(Td0 + (uVar13 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar11 & 0xff) * 4) ^
             pAVar10->rd_key[7] ^ *(uint *)(Td1 + ((uVar12 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar6 << 0x10) >> 0x18) * 4);
    if (local_30 == 0) break;
    uVar11 = *(uint *)(Td0 + (uVar5 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar4 & 0xff) * 4) ^
             ((AES_KEY *)(pAVar10->rd_key + 8))->rd_key[0] ^
             *(uint *)(Td1 + ((uVar13 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar7 << 0x10) >> 0x18) * 4);
    uVar12 = *(uint *)(Td0 + (uVar7 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar13 & 0xff) * 4) ^
             pAVar10->rd_key[10] ^ *(uint *)(Td1 + ((uVar4 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar5 << 0x10) >> 0x18) * 4);
    uVar6 = *(uint *)(Td0 + (uVar4 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar7 & 0xff) * 4) ^
            pAVar10->rd_key[9] ^ *(uint *)(Td1 + ((uVar5 << 8) >> 0x18) * 4) ^
            *(uint *)(Td2 + ((uVar13 << 0x10) >> 0x18) * 4);
    uVar13 = *(uint *)(Td0 + (uVar13 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar5 & 0xff) * 4) ^
             pAVar10->rd_key[0xb] ^ *(uint *)(Td1 + ((uVar7 << 8) >> 0x18) * 4) ^
             *(uint *)(Td2 + ((uVar4 << 0x10) >> 0x18) * 4);
    pAVar10 = (AES_KEY *)(pAVar10->rd_key + 8);
  }
  puVar8 = key->rd_key + iVar9 * 8;
  bVar1 = Td4[uVar5 >> 0x18];
  uVar6 = *puVar8;
  bVar2 = Td4[(uVar13 << 8) >> 0x18];
  bVar3 = Td4[(uVar7 << 0x10) >> 0x18];
  out[3] = Td4[uVar4 & 0xff] ^ (byte)uVar6;
  *out = (byte)(uVar6 >> 0x18) ^ bVar1;
  out[1] = (byte)(uVar6 >> 0x10) ^ bVar2;
  out[2] = (byte)(uVar6 >> 8) ^ bVar3;
  bVar1 = Td4[uVar4 >> 0x18];
  uVar6 = puVar8[1];
  bVar2 = Td4[(uVar5 << 8) >> 0x18];
  bVar3 = Td4[(uVar13 << 0x10) >> 0x18];
  out[7] = Td4[uVar7 & 0xff] ^ (byte)uVar6;
  out[4] = (byte)(uVar6 >> 0x18) ^ bVar1;
  out[5] = (byte)(uVar6 >> 0x10) ^ bVar2;
  bVar1 = Td4[uVar7 >> 0x18];
  out[6] = (byte)(uVar6 >> 8) ^ bVar3;
  uVar6 = puVar8[2];
  bVar2 = Td4[(uVar4 << 8) >> 0x18];
  bVar3 = Td4[(uVar5 << 0x10) >> 0x18];
  out[0xb] = Td4[uVar13 & 0xff] ^ (byte)uVar6;
  out[8] = (byte)(uVar6 >> 0x18) ^ bVar1;
  out[9] = (byte)(uVar6 >> 0x10) ^ bVar2;
  out[10] = (byte)(uVar6 >> 8) ^ bVar3;
  bVar1 = Td4[uVar13 >> 0x18];
  uVar6 = puVar8[3];
  bVar2 = Td4[(uVar7 << 8) >> 0x18];
  bVar3 = Td4[(uVar4 << 0x10) >> 0x18];
  out[0xf] = Td4[uVar5 & 0xff] ^ (byte)uVar6;
  out[0xc] = (byte)(uVar6 >> 0x18) ^ bVar1;
  out[0xd] = (byte)(uVar6 >> 0x10) ^ bVar2;
  out[0xe] = (byte)(uVar6 >> 8) ^ bVar3;
  return;
}

