
void AES_decrypt(uchar *in,uchar *out,AES_KEY *key)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  AES_KEY *pAVar11;
  uint local_1c;
  int local_18;
  
  local_1c = (uint)*in << 0x18 ^ (uint)in[1] << 0x10 ^ (uint)in[3] ^ (uint)in[2] << 8 ^
             key->rd_key[0];
  uVar8 = (uint)in[4] << 0x18 ^ (uint)in[5] << 0x10 ^ (uint)in[7] ^ (uint)in[6] << 8 ^
          key->rd_key[1];
  uVar7 = (uint)in[9] << 0x10 ^ (uint)in[8] << 0x18 ^ (uint)in[0xb] ^ (uint)in[10] << 8 ^
          key->rd_key[2];
  uVar6 = (uint)in[0xe] << 8 ^ (uint)in[0xf] ^ (uint)in[0xd] << 0x10 ^ (uint)in[0xc] << 0x18 ^
          key->rd_key[3];
  iVar3 = key->rounds >> 1;
  pAVar11 = key;
  local_18 = iVar3;
  while( true ) {
    uVar10 = *(uint *)(Td0 + (local_1c >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar8 & 0xff) * 4) ^
             pAVar11->rd_key[4] ^ *(uint *)(Td1 + (uVar6 >> 0x10 & 0xff) * 4) ^
             *(uint *)(Td2 + (uVar7 >> 8 & 0xff) * 4);
    uVar4 = *(uint *)(Td0 + (uVar8 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar7 & 0xff) * 4) ^
            pAVar11->rd_key[5] ^ *(uint *)(Td1 + (local_1c >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (uVar6 >> 8 & 0xff) * 4);
    uVar5 = *(uint *)(Td0 + (uVar7 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar6 & 0xff) * 4) ^
            pAVar11->rd_key[6] ^ *(uint *)(Td1 + (uVar8 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (local_1c >> 8 & 0xff) * 4);
    uVar6 = *(uint *)(Td0 + (uVar6 >> 0x18) * 4) ^ *(uint *)(Td3 + (local_1c & 0xff) * 4) ^
            pAVar11->rd_key[7] ^ *(uint *)(Td1 + (uVar7 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (uVar8 >> 8 & 0xff) * 4);
    local_18 = local_18 + -1;
    if (local_18 == 0) break;
    local_1c = *(uint *)(Td0 + (uVar10 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar4 & 0xff) * 4) ^
               ((AES_KEY *)(pAVar11->rd_key + 8))->rd_key[0] ^
               *(uint *)(Td1 + (uVar6 >> 0x10 & 0xff) * 4) ^
               *(uint *)(Td2 + (uVar5 >> 8 & 0xff) * 4);
    uVar8 = *(uint *)(Td0 + (uVar4 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar5 & 0xff) * 4) ^
            pAVar11->rd_key[9] ^ *(uint *)(Td1 + (uVar10 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (uVar6 >> 8 & 0xff) * 4);
    uVar7 = *(uint *)(Td0 + (uVar5 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar6 & 0xff) * 4) ^
            pAVar11->rd_key[10] ^ *(uint *)(Td1 + (uVar4 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (uVar10 >> 8 & 0xff) * 4);
    uVar6 = *(uint *)(Td0 + (uVar6 >> 0x18) * 4) ^ *(uint *)(Td3 + (uVar10 & 0xff) * 4) ^
            pAVar11->rd_key[0xb] ^ *(uint *)(Td1 + (uVar5 >> 0x10 & 0xff) * 4) ^
            *(uint *)(Td2 + (uVar4 >> 8 & 0xff) * 4);
    pAVar11 = (AES_KEY *)(pAVar11->rd_key + 8);
  }
  puVar9 = key->rd_key + iVar3 * 8;
  uVar7 = (uint)(byte)Td4[uVar4 & 0xff] ^ (uint)(byte)Td4[uVar10 >> 0x18] << 0x18 ^
          (uint)(byte)Td4[uVar6 >> 0x10 & 0xff] << 0x10 ^ (uint)(byte)Td4[uVar5 >> 8 & 0xff] << 8 ^
          *puVar9;
  out[3] = (uchar)uVar7;
  *out = (uchar)(uVar7 >> 0x18);
  out[1] = (uchar)(uVar7 >> 0x10);
  bVar1 = Td4[uVar4 >> 0x18];
  bVar2 = Td4[uVar5 & 0xff];
  out[2] = (uchar)(uVar7 >> 8);
  uVar7 = (uint)bVar2 ^ (uint)bVar1 << 0x18 ^ (uint)(byte)Td4[uVar10 >> 0x10 & 0xff] << 0x10 ^
          (uint)(byte)Td4[uVar6 >> 8 & 0xff] << 8 ^ puVar9[1];
  out[7] = (uchar)uVar7;
  out[4] = (uchar)(uVar7 >> 0x18);
  out[5] = (uchar)(uVar7 >> 0x10);
  out[6] = (uchar)(uVar7 >> 8);
  uVar7 = (uint)(byte)Td4[uVar6 & 0xff] ^ (uint)(byte)Td4[uVar5 >> 0x18] << 0x18 ^
          (uint)(byte)Td4[uVar4 >> 0x10 & 0xff] << 0x10 ^ (uint)(byte)Td4[uVar10 >> 8 & 0xff] << 8 ^
          puVar9[2];
  bVar1 = Td4[uVar5 >> 0x10 & 0xff];
  out[0xb] = (uchar)uVar7;
  out[8] = (uchar)(uVar7 >> 0x18);
  bVar2 = Td4[uVar10 & 0xff];
  out[9] = (uchar)(uVar7 >> 0x10);
  out[10] = (uchar)(uVar7 >> 8);
  uVar6 = (uint)bVar2 ^ (uint)(byte)Td4[uVar6 >> 0x18] << 0x18 ^ (uint)bVar1 << 0x10 ^
          (uint)(byte)Td4[uVar4 >> 8 & 0xff] << 8 ^ puVar9[3];
  out[0xf] = (uchar)uVar6;
  out[0xc] = (uchar)(uVar6 >> 0x18);
  out[0xd] = (uchar)(uVar6 >> 0x10);
  out[0xe] = (uchar)(uVar6 >> 8);
  return;
}

