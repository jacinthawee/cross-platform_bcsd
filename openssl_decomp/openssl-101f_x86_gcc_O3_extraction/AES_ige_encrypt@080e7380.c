
void AES_ige_encrypt(uchar *in,uchar *out,size_t length,AES_KEY *key,uchar *ivec,int enc)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  uint *puVar17;
  uint *puVar18;
  uint *puVar19;
  int in_GS_OFFSET;
  uint local_84;
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
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((((in == (uchar *)0x0) || (out == (uchar *)0x0)) || (key == (AES_KEY *)0x0)) ||
     (ivec == (uchar *)0x0)) {
    OpenSSLDie("aes_ige.c",0x56,"in && out && key && ivec");
  }
  if (1 < (uint)enc) {
    OpenSSLDie("aes_ige.c",0x57,"(AES_ENCRYPT == enc)||(AES_DECRYPT == enc)");
  }
  if ((length & 0xf) != 0) {
    OpenSSLDie("aes_ige.c",0x58,"(length%AES_BLOCK_SIZE) == 0");
  }
  uVar16 = length >> 4;
  local_84 = uVar16;
  if (enc == 1) {
    if (in == out) {
      local_40 = *(uint *)ivec;
      local_3c = *(uint *)(ivec + 4);
      local_38 = *(uint *)(ivec + 8);
      local_34 = *(uint *)(ivec + 0xc);
      uVar12 = *(uint *)(ivec + 0x10);
      uVar9 = *(uint *)(ivec + 0x14);
      uVar13 = *(uint *)(ivec + 0x1c);
      uVar10 = *(uint *)(ivec + 0x18);
      for (; local_30 = uVar12, local_2c = uVar9, local_28 = uVar10, local_24 = uVar13, uVar16 != 0;
          uVar16 = uVar16 - 1) {
        uVar4 = *(uint *)in;
        uVar5 = *(uint *)((int)in + 4);
        uVar6 = *(uint *)((int)in + 8);
        uVar7 = *(uint *)((int)in + 0xc);
        local_50 = local_40 ^ uVar4;
        local_4c = local_3c ^ uVar5;
        local_48 = uVar6 ^ local_38;
        local_44 = uVar7 ^ local_34;
        AES_encrypt((uchar *)&local_50,(uchar *)&local_50,key);
        local_3c = local_4c ^ uVar9;
        local_40 = local_50 ^ uVar12;
        local_38 = local_48 ^ uVar10;
        local_34 = local_44 ^ uVar13;
        *(uint *)((int)in + 4) = local_3c;
        *(uint *)in = local_40;
        *(uint *)((int)in + 8) = local_38;
        *(uint *)((int)in + 0xc) = local_34;
        uVar12 = uVar4;
        uVar9 = uVar5;
        uVar13 = uVar7;
        uVar10 = uVar6;
        in = (uchar *)((int)in + 0x10);
        local_50 = local_40;
        local_4c = local_3c;
        local_48 = local_38;
        local_44 = local_34;
      }
      *(uint *)ivec = local_40;
      *(uint *)(ivec + 4) = local_3c;
      *(uint *)(ivec + 8) = local_38;
      *(uint *)(ivec + 0xc) = local_34;
      *(uint *)(ivec + 0x10) = uVar12;
      *(uint *)(ivec + 0x14) = uVar9;
      *(uint *)(ivec + 0x18) = uVar10;
      *(uint *)(ivec + 0x1c) = uVar13;
    }
    else {
      puVar19 = (uint *)(ivec + 0x10);
      puVar11 = (undefined4 *)ivec;
      if (uVar16 != 0) {
        uVar12 = *(uint *)(ivec + 4);
        uVar9 = *(uint *)ivec;
        uVar13 = *(uint *)(ivec + 8);
        uVar10 = *(uint *)(ivec + 0xc);
        puVar15 = (uint *)out;
        puVar18 = (uint *)in;
        do {
          puVar17 = puVar18;
          *puVar15 = uVar9 ^ *puVar17;
          puVar15[1] = uVar12 ^ puVar17[1];
          puVar15[2] = uVar13 ^ puVar17[2];
          puVar15[3] = uVar10 ^ puVar17[3];
          AES_encrypt((uchar *)puVar15,(uchar *)puVar15,key);
          uVar9 = *puVar15 ^ *puVar19;
          *puVar15 = uVar9;
          uVar12 = puVar15[1] ^ puVar19[1];
          puVar15[1] = uVar12;
          uVar13 = puVar15[2] ^ puVar19[2];
          puVar15[2] = uVar13;
          uVar10 = puVar15[3] ^ puVar19[3];
          puVar15[3] = uVar10;
          local_84 = local_84 - 1;
          puVar15 = puVar15 + 4;
          puVar18 = puVar17 + 4;
          puVar19 = puVar17;
        } while (local_84 != 0);
        iVar14 = (uVar16 + 0xfffffff) * 0x10;
        puVar19 = (uint *)(in + iVar14);
        puVar11 = (undefined4 *)(out + iVar14);
      }
      uVar1 = puVar11[1];
      uVar2 = puVar11[2];
      uVar3 = puVar11[3];
      *(undefined4 *)ivec = *puVar11;
      *(undefined4 *)(ivec + 4) = uVar1;
      *(undefined4 *)(ivec + 8) = uVar2;
      *(undefined4 *)(ivec + 0xc) = uVar3;
      uVar16 = puVar19[1];
      uVar12 = puVar19[2];
      uVar9 = puVar19[3];
      *(uint *)(ivec + 0x10) = *puVar19;
      *(uint *)(ivec + 0x14) = uVar16;
      *(uint *)(ivec + 0x18) = uVar12;
      *(uint *)(ivec + 0x1c) = uVar9;
    }
  }
  else if (in == out) {
    local_40 = *(uint *)ivec;
    local_3c = *(uint *)(ivec + 4);
    local_38 = *(uint *)(ivec + 8);
    local_34 = *(uint *)(ivec + 0xc);
    local_30 = *(uint *)(ivec + 0x10);
    local_2c = *(uint *)(ivec + 0x14);
    local_28 = *(uint *)(ivec + 0x18);
    local_24 = *(uint *)(ivec + 0x1c);
    for (; uVar16 != 0; uVar16 = uVar16 - 1) {
      local_50 = *(uint *)in;
      local_4c = *(uint *)((int)in + 4);
      local_48 = *(uint *)((int)in + 8);
      local_44 = *(uint *)((int)in + 0xc);
      local_60 = local_50 ^ local_30;
      local_5c = local_4c ^ local_2c;
      local_58 = local_48 ^ local_28;
      local_54 = local_44 ^ local_24;
      AES_decrypt((uchar *)&local_60,(uchar *)&local_60,key);
      local_30 = local_60 ^ local_40;
      local_2c = local_5c ^ local_3c;
      local_28 = local_58 ^ local_38;
      local_24 = local_54 ^ local_34;
      *(uint *)in = local_30;
      *(uint *)((int)in + 4) = local_2c;
      *(uint *)((int)in + 8) = local_28;
      *(uint *)((int)in + 0xc) = local_24;
      local_40 = local_50;
      local_3c = local_4c;
      local_38 = local_48;
      local_34 = local_44;
      in = (uchar *)((int)in + 0x10);
      local_60 = local_30;
      local_5c = local_2c;
      local_58 = local_28;
      local_54 = local_24;
    }
    *(uint *)ivec = local_40;
    *(uint *)(ivec + 4) = local_3c;
    *(uint *)(ivec + 8) = local_38;
    *(uint *)(ivec + 0xc) = local_34;
    *(uint *)(ivec + 0x10) = local_30;
    *(uint *)(ivec + 0x14) = local_2c;
    *(uint *)(ivec + 0x18) = local_28;
    *(uint *)(ivec + 0x1c) = local_24;
  }
  else {
    puVar8 = (undefined4 *)(ivec + 0x10);
    puVar11 = (undefined4 *)ivec;
    if (uVar16 != 0) {
      uVar12 = *(uint *)(ivec + 0x14);
      uVar9 = *(uint *)(ivec + 0x10);
      uVar13 = *(uint *)(ivec + 0x18);
      uVar10 = *(uint *)(ivec + 0x1c);
      puVar19 = (uint *)out;
      puVar15 = (uint *)in;
      puVar18 = (uint *)ivec;
      do {
        puVar17 = puVar15;
        local_30 = uVar9 ^ *puVar17;
        local_2c = uVar12 ^ puVar17[1];
        local_28 = uVar13 ^ puVar17[2];
        local_24 = uVar10 ^ puVar17[3];
        AES_decrypt((uchar *)&local_30,(uchar *)puVar19,key);
        uVar9 = *puVar19 ^ *puVar18;
        *puVar19 = uVar9;
        uVar12 = puVar19[1] ^ puVar18[1];
        puVar19[1] = uVar12;
        uVar13 = puVar19[2] ^ puVar18[2];
        puVar19[2] = uVar13;
        uVar10 = puVar19[3] ^ puVar18[3];
        puVar19[3] = uVar10;
        local_84 = local_84 - 1;
        puVar19 = puVar19 + 4;
        puVar15 = puVar17 + 4;
        puVar18 = puVar17;
      } while (local_84 != 0);
      iVar14 = (uVar16 + 0xfffffff) * 0x10;
      puVar8 = (undefined4 *)(out + iVar14);
      puVar11 = (undefined4 *)(in + iVar14);
    }
    uVar1 = puVar11[2];
    uVar2 = *puVar11;
    uVar3 = puVar11[3];
    *(undefined4 *)(ivec + 4) = puVar11[1];
    *(undefined4 *)(ivec + 8) = uVar1;
    *(undefined4 *)ivec = uVar2;
    *(undefined4 *)(ivec + 0xc) = uVar3;
    uVar1 = puVar8[1];
    uVar2 = puVar8[2];
    uVar3 = puVar8[3];
    *(undefined4 *)(ivec + 0x10) = *puVar8;
    *(undefined4 *)(ivec + 0x14) = uVar1;
    *(undefined4 *)(ivec + 0x18) = uVar2;
    *(undefined4 *)(ivec + 0x1c) = uVar3;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

