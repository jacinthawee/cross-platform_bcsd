
void AES_decrypt(uchar *in,uchar *out,AES_KEY *key)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  AES_KEY *pAVar13;
  uint local_1c;
  int local_18;
  
  local_1c = (uint)*in << 0x18 ^ (uint)in[1] << 0x10 ^ (uint)in[3] ^ (uint)in[2] << 8 ^
             key->rd_key[0];
  uVar11 = (uint)in[4] << 0x18 ^ (uint)in[5] << 0x10 ^ (uint)in[7] ^ (uint)in[6] << 8 ^
           key->rd_key[1];
  uVar9 = (uint)in[9] << 0x10 ^ (uint)in[8] << 0x18 ^ (uint)in[0xb] ^ (uint)in[10] << 8 ^
          key->rd_key[2];
  uVar8 = (uint)in[0xe] << 8 ^ (uint)in[0xf] ^ (uint)in[0xd] << 0x10 ^ (uint)in[0xc] << 0x18 ^
          key->rd_key[3];
  iVar5 = key->rounds >> 1;
  pAVar13 = key;
  local_18 = iVar5;
  while( true ) {
    uVar12 = *(uint *)(Td0 + (local_1c >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar11 & 0xff) * 4) ^
             pAVar13->rd_key[4] ^ *(uint *)(Td1 + (uVar8 >> 0x10 & 0xff) * 4) ^
             *(uint *)(Td2 + (uVar9 >> 8 & 0xff) * 4);
    uVar6 = *(uint *)(Td0 + (uVar11 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar9 & 0xff) * 4) ^
            pAVar13->rd_key[5] ^ *(uint *)(Td1 + (local_1c >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (uVar8 >> 8 & 0xff) * 4);
    uVar7 = *(uint *)(Td0 + (uVar9 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar8 & 0xff) * 4) ^
            pAVar13->rd_key[6] ^ *(uint *)(Td1 + (uVar11 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (local_1c >> 8 & 0xff) * 4);
    uVar8 = *(uint *)(Td0 + (uVar8 >> 0x18) * 4) ^ *(uint *)(Td3 + (local_1c & 0xff) * 4) ^
            pAVar13->rd_key[7] ^ *(uint *)(Td1 + (uVar9 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (uVar11 >> 8 & 0xff) * 4);
    local_18 = local_18 + -1;
    if (local_18 == 0) break;
    local_1c = *(uint *)(Td0 + (uVar12 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar6 & 0xff) * 4) ^
               ((AES_KEY *)(pAVar13->rd_key + 8))->rd_key[0] ^
               *(uint *)(Td1 + (uVar8 >> 0x10 & 0xff) * 4) ^
               *(uint *)(Td2 + (uVar7 >> 8 & 0xff) * 4);
    uVar11 = *(uint *)(Td0 + (uVar6 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar7 & 0xff) * 4) ^
             pAVar13->rd_key[9] ^ *(uint *)(Td1 + (uVar12 >> 0x10 & 0xff) * 4) ^
             *(uint *)(Td2 + (uVar8 >> 8 & 0xff) * 4);
    uVar9 = *(uint *)(Td0 + (uVar7 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar8 & 0xff) * 4) ^
            pAVar13->rd_key[10] ^ *(uint *)(Td1 + (uVar6 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (uVar12 >> 8 & 0xff) * 4);
    uVar8 = *(uint *)(Td0 + (uVar8 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar12 & 0xff) * 4) ^
            pAVar13->rd_key[0xb] ^ *(uint *)(Td1 + (uVar7 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (uVar6 >> 8 & 0xff) * 4);
    pAVar13 = (AES_KEY *)(pAVar13->rd_key + 8);
  }
  puVar10 = key->rd_key + iVar5 * 8;
  bVar1 = Td4[uVar6 & 0xff];
  uVar9 = *puVar10;
  bVar2 = Td4[uVar8 >> 0x10 & 0xff];
  bVar3 = Td4[uVar7 >> 8 & 0xff];
  *out = (byte)(uVar9 >> 0x18) ^ Td4[uVar12 >> 0x18];
  out[3] = bVar1 ^ (byte)uVar9;
  out[1] = (byte)(uVar9 >> 0x10) ^ bVar2;
  out[2] = (byte)(uVar9 >> 8) ^ bVar3;
  uVar9 = puVar10[1];
  bVar1 = Td4[uVar6 >> 0x18];
  bVar2 = Td4[uVar12 >> 0x10 & 0xff];
  bVar3 = Td4[uVar8 >> 8 & 0xff];
  out[7] = Td4[uVar7 & 0xff] ^ (byte)uVar9;
  out[4] = (byte)(uVar9 >> 0x18) ^ bVar1;
  out[5] = (byte)(uVar9 >> 0x10) ^ bVar2;
  out[6] = (byte)(uVar9 >> 8) ^ bVar3;
  bVar1 = Td4[uVar8 & 0xff];
  uVar9 = puVar10[2];
  bVar2 = Td4[uVar6 >> 0x10 & 0xff];
  bVar3 = Td4[uVar12 >> 8 & 0xff];
  out[8] = (byte)(uVar9 >> 0x18) ^ Td4[uVar7 >> 0x18];
  out[0xb] = bVar1 ^ (byte)uVar9;
  bVar1 = Td4[uVar12 & 0xff];
  out[9] = (byte)(uVar9 >> 0x10) ^ bVar2;
  out[10] = (byte)(uVar9 >> 8) ^ bVar3;
  uVar9 = puVar10[3];
  bVar2 = Td4[uVar8 >> 0x18];
  bVar3 = Td4[uVar7 >> 0x10 & 0xff];
  bVar4 = Td4[uVar6 >> 8 & 0xff];
  out[0xf] = (byte)uVar9 ^ bVar1;
  out[0xc] = (byte)(uVar9 >> 0x18) ^ bVar2;
  out[0xd] = (byte)(uVar9 >> 0x10) ^ bVar3;
  out[0xe] = (byte)(uVar9 >> 8) ^ bVar4;
  return;
}

