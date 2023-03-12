
void AES_ige_encrypt(uchar *in,uchar *out,size_t length,AES_KEY *key,uchar *ivec,int enc)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *puVar7;
  uchar *puVar8;
  undefined4 *puVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  if ((out == (uchar *)0x0 || in == (uchar *)0x0) || (ivec == (uchar *)0x0 || key == (AES_KEY *)0x0)
     ) {
    OpenSSLDie("aes_ige.c",0x56,"in && out && key && ivec");
  }
  if (1 < (uint)enc) {
    OpenSSLDie("aes_ige.c",0x57,"(AES_ENCRYPT == enc) || (AES_DECRYPT == enc)");
  }
  if ((length & 0xf) != 0) {
    OpenSSLDie("aes_ige.c",0x58,"(length % AES_BLOCK_SIZE) == 0");
  }
  if (enc != 1) {
    uVar14 = length >> 4;
    if ((in != out) && ((((uint)ivec | (uint)out | (uint)in) & 3) == 0)) {
      puVar6 = (undefined4 *)(ivec + 0x10);
      puVar9 = (undefined4 *)ivec;
      if (uVar14 != 0) {
        local_38 = *(uint *)(ivec + 0x10);
        local_2c = *(uint *)(ivec + 0x1c);
        local_34 = *(uint *)(ivec + 0x14);
        local_30 = *(uint *)(ivec + 0x18);
        puVar8 = out + 0x10;
        puVar7 = (uint *)in;
        puVar12 = (uint *)ivec;
        uVar13 = uVar14;
        do {
          puVar10 = puVar7;
          local_38 = local_38 ^ *puVar10;
          local_34 = puVar10[1] ^ local_34;
          local_30 = puVar10[2] ^ local_30;
          local_2c = puVar10[3] ^ local_2c;
          AES_decrypt((uchar *)&local_38,puVar8 + -0x10,key);
          uVar13 = uVar13 - 1;
          local_38 = *puVar12 ^ *(uint *)(puVar8 + -0x10);
          *(uint *)(puVar8 + -0x10) = local_38;
          local_34 = puVar12[1] ^ *(uint *)(puVar8 + -0xc);
          *(uint *)(puVar8 + -0xc) = local_34;
          local_30 = puVar12[2] ^ *(uint *)(puVar8 + -8);
          *(uint *)(puVar8 + -8) = local_30;
          local_2c = puVar12[3] ^ *(uint *)(puVar8 + -4);
          *(uint *)(puVar8 + -4) = local_2c;
          puVar8 = puVar8 + 0x10;
          puVar7 = puVar10 + 4;
          puVar12 = puVar10;
        } while (uVar13 != 0);
        iVar15 = (uVar14 + 0xfffffff) * 0x10;
        puVar6 = (undefined4 *)(out + iVar15);
        puVar9 = (undefined4 *)(in + iVar15);
      }
      uVar1 = puVar9[1];
      uVar3 = puVar9[2];
      uVar4 = puVar9[3];
      *(undefined4 *)ivec = *puVar9;
      *(undefined4 *)(ivec + 4) = uVar1;
      *(undefined4 *)(ivec + 8) = uVar3;
      *(undefined4 *)(ivec + 0xc) = uVar4;
      uVar1 = puVar6[1];
      uVar3 = puVar6[2];
      uVar4 = puVar6[3];
      *(undefined4 *)(ivec + 0x10) = *puVar6;
      *(undefined4 *)(ivec + 0x14) = uVar1;
      *(undefined4 *)(ivec + 0x18) = uVar3;
      *(undefined4 *)(ivec + 0x1c) = uVar4;
      return;
    }
    local_48 = *(uint *)ivec;
    local_3c = *(uint *)(ivec + 0xc);
    local_44 = *(uint *)(ivec + 4);
    local_40 = *(uint *)(ivec + 8);
    local_38 = *(uint *)(ivec + 0x10);
    local_34 = *(uint *)(ivec + 0x14);
    local_30 = *(uint *)(ivec + 0x18);
    local_2c = *(uint *)(ivec + 0x1c);
    for (; uVar14 != 0; uVar14 = uVar14 - 1) {
      local_58 = *(uint *)in;
      local_54 = *(uint *)((int)in + 4);
      local_50 = *(uint *)((int)in + 8);
      local_4c = *(uint *)((int)in + 0xc);
      local_68 = local_58 ^ local_38;
      local_60 = local_50 ^ local_30;
      local_64 = local_34 ^ local_54;
      local_5c = local_2c ^ local_4c;
      AES_decrypt((uchar *)&local_68,(uchar *)&local_68,key);
      local_38 = local_48 ^ local_68;
      local_34 = local_44 ^ local_64;
      local_30 = local_40 ^ local_60;
      local_2c = local_3c ^ local_5c;
      *(uint *)out = local_38;
      *(uint *)((int)out + 4) = local_34;
      *(uint *)((int)out + 8) = local_30;
      *(uint *)((int)out + 0xc) = local_2c;
      local_48 = local_58;
      local_3c = local_4c;
      local_44 = local_54;
      local_40 = local_50;
      in = (uchar *)((int)in + 0x10);
      out = (uchar *)((int)out + 0x10);
    }
    *(uint *)ivec = local_48;
    *(uint *)(ivec + 4) = local_44;
    *(uint *)(ivec + 8) = local_40;
    *(uint *)(ivec + 0xc) = local_3c;
    *(uint *)(ivec + 0x10) = local_38;
    *(uint *)(ivec + 0x14) = local_34;
    *(uint *)(ivec + 0x18) = local_30;
    *(uint *)(ivec + 0x1c) = local_2c;
    return;
  }
  uVar14 = length >> 4;
  if ((in != out) && ((((uint)ivec | (uint)out | (uint)in) & 3) == 0)) {
    puVar7 = (uint *)(ivec + 0x10);
    puVar9 = (undefined4 *)ivec;
    if (uVar14 != 0) {
      uVar16 = *(uint *)(ivec + 0xc);
      uVar2 = *(uint *)ivec;
      uVar5 = *(uint *)(ivec + 8);
      uVar11 = *(uint *)(ivec + 4);
      puVar8 = out + 0x10;
      puVar12 = (uint *)in;
      uVar13 = uVar14;
      do {
        puVar10 = puVar12;
        *(uint *)(puVar8 + -0x10) = uVar2 ^ *puVar10;
        *(uint *)(puVar8 + -0xc) = puVar10[1] ^ uVar11;
        *(uint *)(puVar8 + -8) = puVar10[2] ^ uVar5;
        *(uint *)(puVar8 + -4) = puVar10[3] ^ uVar16;
        AES_encrypt(puVar8 + -0x10,puVar8 + -0x10,key);
        uVar13 = uVar13 - 1;
        uVar2 = *(uint *)(puVar8 + -0x10) ^ *puVar7;
        *(uint *)(puVar8 + -0x10) = uVar2;
        uVar11 = puVar7[1] ^ *(uint *)(puVar8 + -0xc);
        *(uint *)(puVar8 + -0xc) = uVar11;
        uVar5 = puVar7[2] ^ *(uint *)(puVar8 + -8);
        *(uint *)(puVar8 + -8) = uVar5;
        uVar16 = *(uint *)(puVar8 + -4) ^ puVar7[3];
        *(uint *)(puVar8 + -4) = uVar16;
        puVar8 = puVar8 + 0x10;
        puVar12 = puVar10 + 4;
        puVar7 = puVar10;
      } while (uVar13 != 0);
      iVar15 = (uVar14 + 0xfffffff) * 0x10;
      puVar7 = (uint *)(in + iVar15);
      puVar9 = (undefined4 *)(out + iVar15);
    }
    uVar1 = puVar9[1];
    uVar3 = puVar9[2];
    uVar4 = puVar9[3];
    *(undefined4 *)ivec = *puVar9;
    *(undefined4 *)(ivec + 4) = uVar1;
    *(undefined4 *)(ivec + 8) = uVar3;
    *(undefined4 *)(ivec + 0xc) = uVar4;
    uVar14 = puVar7[1];
    uVar13 = puVar7[2];
    uVar2 = puVar7[3];
    *(uint *)(ivec + 0x10) = *puVar7;
    *(uint *)(ivec + 0x14) = uVar14;
    *(uint *)(ivec + 0x18) = uVar13;
    *(uint *)(ivec + 0x1c) = uVar2;
    return;
  }
  local_48 = *(uint *)ivec;
  local_44 = *(uint *)(ivec + 4);
  local_40 = *(uint *)(ivec + 8);
  local_3c = *(uint *)(ivec + 0xc);
  local_38 = *(uint *)(ivec + 0x10);
  local_34 = *(uint *)(ivec + 0x14);
  local_30 = *(uint *)(ivec + 0x18);
  local_2c = *(uint *)(ivec + 0x1c);
  if (uVar14 != 0) {
    do {
      local_68 = *(uint *)in;
      local_64 = *(uint *)((int)in + 4);
      local_60 = *(uint *)((int)in + 8);
      local_5c = *(uint *)((int)in + 0xc);
      local_58 = local_68 ^ local_48;
      local_54 = local_44 ^ local_64;
      local_50 = local_40 ^ local_60;
      local_4c = local_3c ^ local_5c;
      AES_encrypt((uchar *)&local_58,(uchar *)&local_58,key);
      local_48 = local_58 ^ local_38;
      local_44 = local_34 ^ local_54;
      local_40 = local_50 ^ local_30;
      local_3c = local_4c ^ local_2c;
      *(uint *)out = local_48;
      *(uint *)((int)out + 4) = local_44;
      *(uint *)((int)out + 8) = local_40;
      *(uint *)((int)out + 0xc) = local_3c;
      uVar14 = uVar14 - 1;
      local_38 = local_68;
      local_34 = local_64;
      local_30 = local_60;
      local_2c = local_5c;
      in = (uchar *)((int)in + 0x10);
      out = (uchar *)((int)out + 0x10);
    } while (uVar14 != 0);
  }
  *(uint *)ivec = local_48;
  *(uint *)(ivec + 4) = local_44;
  *(uint *)(ivec + 8) = local_40;
  *(uint *)(ivec + 0xc) = local_3c;
  *(uint *)(ivec + 0x10) = local_38;
  *(uint *)(ivec + 0x14) = local_34;
  *(uint *)(ivec + 0x18) = local_30;
  *(uint *)(ivec + 0x1c) = local_2c;
  return;
}

