
undefined4
ssl3_cbc_digest_record
          (EVP_MD_CTX *param_1,uchar *param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5,
          int param_6,uint param_7,void *param_8,uint param_9,char param_10)

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  EVP_MD *md;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  byte bVar14;
  int iVar15;
  undefined4 *puVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  undefined4 *puVar20;
  uint *puVar21;
  int in_GS_OFFSET;
  byte bVar22;
  int local_368;
  uint local_364;
  uint local_360;
  uint local_35c;
  uint local_344;
  uint local_338;
  code *local_334;
  uint local_330;
  undefined *local_32c;
  code *local_320;
  size_t local_31c;
  uint local_318;
  uint local_314;
  uint local_304;
  uint local_2e8;
  EVP_MD_CTX local_2e4;
  undefined local_2cc [213];
  undefined auStack_1f7 [3];
  undefined4 uStack_1f4;
  undefined4 local_1f0 [4];
  uint local_1e0;
  uint local_1dc;
  uint local_1d8;
  uint local_1d4;
  uint local_1d0;
  uint local_1cc;
  uint local_1c8;
  uint local_1c4;
  uint local_1c0;
  uint local_1bc;
  uint local_1b8;
  uint local_1b4;
  uint local_1b0;
  uint local_1ac;
  uint local_1a8;
  uint local_1a4 [33];
  uint local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  uint local_10c;
  uint local_108;
  uint local_104;
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  uint local_ec;
  uint local_e8;
  uint local_e4;
  undefined4 local_a0 [2];
  undefined4 local_98;
  undefined4 uStack_97;
  undefined local_93 [115];
  int local_20;
  
  bVar22 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0xfffff < param_7) {
    OpenSSLDie("s3_cbc.c",0x1c7,"data_plus_mac_plus_padding_size < 1024 * 1024");
  }
  md = EVP_MD_CTX_md(param_1);
  iVar4 = EVP_MD_type(md);
  if (iVar4 == 0x2a0) {
    iVar4 = SHA256_Init((SHA256_CTX *)local_2cc);
    if (0 < iVar4) {
      iVar4 = 0x27;
      local_368 = 0x33;
      iVar15 = 0x200;
      bVar2 = true;
      iVar12 = 8;
      local_304 = 0x28;
      local_360 = 0x40;
      local_31c = 0x20;
      local_334 = SHA256_Transform;
      local_320 = tls1_sha256_final_raw;
      goto LAB_080a7b6a;
    }
  }
  else if (iVar4 < 0x2a1) {
    if (iVar4 == 4) {
      iVar4 = MD5_Init((MD5_CTX *)local_2cc);
      if (0 < iVar4) {
        iVar4 = 0x37;
        local_368 = 0x33;
        iVar15 = 0x200;
        bVar2 = false;
        iVar12 = 8;
        local_304 = 0x30;
        local_360 = 0x40;
        local_31c = 0x10;
        local_334 = MD5_Transform;
        local_320 = tls1_md5_final_raw;
        goto LAB_080a7b6a;
      }
    }
    else if (iVar4 == 0x40) {
      iVar4 = SHA1_Init((SHA_CTX *)local_2cc);
      if (0 < iVar4) {
        iVar4 = 0x33;
        local_368 = 0x33;
        iVar15 = 0x200;
        bVar2 = true;
        iVar12 = 8;
        local_304 = 0x28;
        local_360 = 0x40;
        local_31c = 0x14;
        local_334 = SHA1_Transform;
        local_320 = tls1_sha1_final_raw;
        goto LAB_080a7b6a;
      }
    }
    else {
LAB_080a7f17:
      OpenSSLDie("s3_cbc.c",0x209,"0");
      if (param_3 != (uint *)0x0) {
        *param_3 = 0xffffffff;
        uVar5 = 0;
        goto LAB_080a7c73;
      }
    }
  }
  else if (iVar4 == 0x2a2) {
    iVar4 = SHA512_Init((SHA512_CTX *)local_2cc);
    if (0 < iVar4) {
      iVar4 = 0x4f;
      local_368 = 0x73;
      iVar15 = 0x400;
      bVar2 = true;
      iVar12 = 0x10;
      local_304 = 0x28;
      local_360 = 0x80;
      local_31c = 0x40;
      local_334 = SHA512_Transform;
      local_320 = tls1_sha512_final_raw;
LAB_080a7b6a:
      if (param_10 == '\0') goto LAB_080a797a;
LAB_080a7b75:
      local_364 = 2;
      local_35c = local_304 + 0xb + param_9;
      local_344 = param_7 + local_35c;
      uVar7 = (local_35c - local_31c) + param_6;
      local_338 = (iVar4 + local_344) / local_360;
      local_318 = uVar7 / local_360;
      uVar10 = uVar7 % local_360;
      local_314 = (iVar12 + uVar7) / local_360;
      if (local_338 < 4) goto LAB_080a79db;
LAB_080a7bd3:
      local_338 = local_338 - local_364;
      iVar4 = uVar7 * 8;
      local_330 = local_360 * local_338;
      if (param_10 == '\0') goto LAB_080a79fd;
LAB_080a7bf8:
      if (!bVar2) goto LAB_080a7a99;
LAB_080a7c02:
      __memset_chk(local_1f0,0,iVar12 + -4,0x10);
      *(char *)((int)local_1f0 + iVar12 + -1) = (char)iVar4;
      *(char *)((int)local_1f0 + iVar12 + -4) = (char)((uint)iVar4 >> 0x18);
      *(char *)((int)local_1f0 + iVar12 + -3) = (char)((uint)iVar4 >> 0x10);
      *(char *)((int)local_1f0 + iVar12 + -2) = (char)((uint)iVar4 >> 8);
      goto LAB_080a7c50;
    }
  }
  else if (iVar4 < 0x2a2) {
    iVar4 = SHA384_Init((SHA512_CTX *)local_2cc);
    if (0 < iVar4) {
      iVar4 = 0x5f;
      local_368 = 0x73;
      iVar15 = 0x400;
      bVar2 = true;
      iVar12 = 0x10;
      local_304 = 0x28;
      local_360 = 0x80;
      local_31c = 0x30;
      local_334 = SHA512_Transform;
      local_320 = tls1_sha512_final_raw;
      goto LAB_080a7b6a;
    }
  }
  else {
    if (iVar4 != 0x2a3) goto LAB_080a7f17;
    iVar4 = SHA224_Init((SHA256_CTX *)local_2cc);
    if (iVar4 < 1) goto LAB_080a7c71;
    iVar4 = 0x2b;
    local_368 = 0x33;
    iVar15 = 0x200;
    bVar2 = true;
    iVar12 = 8;
    local_304 = 0x28;
    local_360 = 0x40;
    local_31c = 0x1c;
    local_334 = SHA256_Transform;
    local_320 = tls1_sha256_final_raw;
    if (param_10 != '\0') goto LAB_080a7b75;
LAB_080a797a:
    local_344 = param_7 + 0xd;
    local_364 = 6;
    local_35c = 0xd;
    local_338 = ((local_360 + 0xc + param_7 + iVar12) - local_31c) / local_360;
    uVar7 = (param_6 + 0xd) - local_31c;
    local_318 = uVar7 / local_360;
    uVar10 = uVar7 % local_360;
    local_314 = (iVar12 + uVar7) / local_360;
    if (6 < local_338) goto LAB_080a7bd3;
LAB_080a79db:
    local_330 = 0;
    iVar4 = uVar7 * 8;
    local_338 = 0;
    if (param_10 != '\0') goto LAB_080a7bf8;
LAB_080a79fd:
    local_32c = local_2cc;
    iVar4 = iVar4 + iVar15;
    puVar21 = local_1a4 + 1;
    *(undefined4 *)((int)local_1a4 + local_360) = 0;
    puVar17 = puVar21;
    for (uVar7 = local_360 - 1 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *puVar17 = 0;
      puVar17 = puVar17 + (uint)bVar22 * -2 + 1;
    }
    if (0x80 < param_9) {
      OpenSSLDie("s3_cbc.c",0x271,"mac_secret_length <= sizeof(hmac_pad)");
    }
    __memcpy_chk(puVar21,param_8,param_9,0x80);
    uVar7 = 0;
    do {
      puVar21[uVar7] = puVar21[uVar7] ^ 0x36363636;
      uVar7 = uVar7 + 1;
    } while (uVar7 < (local_360 - 4 >> 2) + 1);
    (*local_334)(local_32c,puVar21);
    if (bVar2) goto LAB_080a7c02;
LAB_080a7a99:
    *(undefined4 *)((int)local_1f0 + iVar12 + -4) = 0;
    uVar7 = 0;
    do {
      *(undefined4 *)((int)local_1f0 + uVar7) = 0;
      uVar7 = uVar7 + 4;
    } while (uVar7 < iVar12 - 4U);
    local_2cc[iVar12 + 0xd4] = (char)iVar4;
    auStack_1f7[iVar12 + 2] = (char)((uint)iVar4 >> 0x18);
    auStack_1f7[iVar12 + 1] = (char)((uint)iVar4 >> 0x10);
    auStack_1f7[iVar12] = (char)((uint)iVar4 >> 8);
LAB_080a7c50:
    local_32c = local_2cc;
    if (local_330 != 0) {
      if (param_10 == '\0') {
        local_a0[0] = *param_4;
        local_a0[1] = param_4[1];
        local_98 = param_4[2];
        uStack_97._3_1_ = *(undefined *)(param_4 + 3);
        local_93._0_4_ = *param_5;
        *(undefined4 *)((int)&stack0xffffff68 + local_368 + 1) =
             *(undefined4 *)((int)param_5 + local_368 + -4);
        puVar16 = (undefined4 *)((int)param_5 + 3);
        puVar20 = (undefined4 *)(local_93 + 3);
        for (uVar7 = local_368 - 3U >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar20 = *puVar16;
          puVar16 = puVar16 + (uint)bVar22 * -2 + 1;
          puVar20 = puVar20 + (uint)bVar22 * -2 + 1;
        }
        (*local_334)(local_32c,local_a0);
        if (1 < local_330 / local_360) {
          iVar4 = (int)param_5 + -0xd;
          uVar7 = 1;
          do {
            iVar4 = iVar4 + local_360;
            uVar7 = uVar7 + 1;
            (*local_334)(local_32c,iVar4);
          } while (local_330 / local_360 != uVar7);
        }
      }
      else {
        if (local_35c <= local_360) goto LAB_080a7c71;
        iVar4 = local_35c - local_360;
        (*local_334)(local_32c,param_4);
        __memcpy_chk(local_a0,(int)param_4 + local_360,iVar4,0x80);
        memcpy((void *)(iVar4 + (int)local_a0),param_5,local_360 - iVar4);
        (*local_334)(local_32c,local_a0);
        uVar7 = local_330 / local_360 - 1;
        if (1 < uVar7) {
          uVar18 = 1;
          iVar4 = (int)param_5 + (local_360 - iVar4);
          do {
            uVar18 = uVar18 + 1;
            (*local_334)(local_32c,iVar4);
            iVar4 = iVar4 + local_360;
          } while (uVar7 != uVar18);
        }
      }
    }
    puVar21 = &local_1e0;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar21 = 0;
      puVar21 = puVar21 + (uint)bVar22 * -2 + 1;
    }
    uVar7 = local_364 + local_338;
    if (!CARRY4(local_364,local_338)) {
      uVar18 = local_31c - 4 >> 2;
      do {
        uVar19 = 0;
        bVar3 = (char)((byte)((local_318 ^ local_338) - 1 >> 0x18) &
                      ~(byte)((local_318 ^ local_338) >> 0x18)) >> 7;
        uVar6 = (local_314 ^ local_338) - 1 & ~(local_314 ^ local_338);
        bVar8 = (byte)((int)uVar6 >> 0x1f);
        uVar11 = ~uVar10;
        uVar13 = local_330;
        do {
          if (uVar13 < local_35c) {
            bVar14 = *(byte *)((int)param_4 + uVar13);
            bVar9 = bVar14 + 0x80;
          }
          else if (uVar13 < local_344) {
            bVar14 = *(byte *)((int)param_5 + (uVar13 - local_35c));
            bVar9 = bVar14 + 0x80;
          }
          else {
            bVar9 = 0x80;
            bVar14 = 0;
          }
          uVar13 = uVar13 + 1;
          bVar1 = (byte)(uVar19 >> 0x18);
          bVar9 = ~(~((char)((bVar1 | (byte)(uVar11 >> 0x18)) ^ bVar1) >> 7) & bVar3) &
                  (~bVar8 | bVar3) &
                  (bVar14 ^ bVar9 & ~((char)(((byte)(uVar11 + 1 >> 0x18) | bVar1) ^ bVar1) >> 7) &
                                    bVar3);
          if (local_360 - iVar12 <= uVar19) {
            bVar9 = bVar9 ^ (bVar9 ^ *(byte *)((int)local_1f0 + uVar19 + (iVar12 - local_360))) &
                            bVar8;
          }
          *(byte *)((int)&local_120 + uVar19) = bVar9;
          uVar19 = uVar19 + 1;
          uVar11 = uVar11 + 1;
        } while (local_360 != uVar19);
        local_330 = local_330 + local_360;
        (*local_334)(local_32c,&local_120);
        (*local_320)(local_32c,&local_120);
        uVar11 = (int)uVar6 >> 0x1f & 0xff;
        uVar11 = uVar11 << 0x18 | (uint)CONCAT11(bVar8,bVar8) | uVar11 << 0x10;
        local_1e0 = local_1e0 | local_120 & uVar11;
        local_1dc = local_1dc | local_11c & uVar11;
        local_1d8 = local_1d8 | local_118 & uVar11;
        local_1d4 = local_1d4 | local_114 & uVar11;
        if ((((((uVar18 != 3) && (local_1d0 = local_1d0 | local_110 & uVar11, uVar18 != 4)) &&
              (local_1cc = local_1cc | local_10c & uVar11, uVar18 != 5)) &&
             (((local_1c8 = local_1c8 | local_108 & uVar11, uVar18 != 6 &&
               (local_1c4 = local_1c4 | local_104 & uVar11, uVar18 != 7)) &&
              ((local_1c0 = local_1c0 | local_100 & uVar11, uVar18 != 8 &&
               ((local_1bc = local_1bc | local_fc & uVar11, uVar18 != 9 &&
                (local_1b8 = local_1b8 | local_f8 & uVar11, uVar18 != 10)))))))) &&
            (local_1b4 = local_1b4 | local_f4 & uVar11, uVar18 != 0xb)) &&
           (((local_1b0 = local_1b0 | local_f0 & uVar11, uVar18 != 0xc &&
             (local_1ac = local_1ac | local_ec & uVar11, uVar18 != 0xd)) &&
            (local_1a8 = local_1a8 | local_e8 & uVar11, uVar18 == 0xf)))) {
          local_1a4[0] = local_1a4[0] | local_e4 & uVar11;
        }
        local_338 = local_338 + 1;
      } while (local_338 <= uVar7);
    }
    EVP_MD_CTX_init(&local_2e4);
    iVar4 = EVP_DigestInit_ex(&local_2e4,param_1->digest,(ENGINE *)0x0);
    if (0 < iVar4) {
      if (param_10 == '\0') {
        uVar7 = 0;
        do {
          local_1a4[uVar7 + 1] = local_1a4[uVar7 + 1] ^ 0x6a6a6a6a;
          uVar7 = uVar7 + 1;
          local_304 = local_360;
        } while (uVar7 < (local_360 - 4 >> 2) + 1);
      }
      else {
        *(undefined4 *)((int)local_1a4 + local_304) = 0x5c5c5c5c;
        puVar21 = local_1a4 + 1;
        for (uVar7 = local_304 - 1 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *puVar21 = 0x5c5c5c5c;
          puVar21 = puVar21 + (uint)bVar22 * -2 + 1;
        }
        iVar4 = EVP_DigestUpdate(&local_2e4,param_8,param_9);
        if (iVar4 < 1) goto LAB_080a81f5;
      }
      iVar4 = EVP_DigestUpdate(&local_2e4,local_1a4 + 1,local_304);
      if ((0 < iVar4) && (iVar4 = EVP_DigestUpdate(&local_2e4,&local_1e0,local_31c), 0 < iVar4)) {
        EVP_DigestFinal(&local_2e4,param_2,&local_2e8);
        if (param_3 != (uint *)0x0) {
          *param_3 = local_2e8;
        }
        EVP_MD_CTX_cleanup(&local_2e4);
        uVar5 = 1;
        goto LAB_080a7c73;
      }
    }
LAB_080a81f5:
    EVP_MD_CTX_cleanup(&local_2e4);
  }
LAB_080a7c71:
  uVar5 = 0;
LAB_080a7c73:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}

