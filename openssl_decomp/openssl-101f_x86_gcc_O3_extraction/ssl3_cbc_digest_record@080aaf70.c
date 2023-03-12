
void ssl3_cbc_digest_record
               (EVP_MD_CTX *param_1,uchar *param_2,uint *param_3,undefined4 *param_4,
               undefined4 *param_5,int param_6,uint param_7,void *param_8,uint param_9,char param_10
               )

{
  byte bVar1;
  bool bVar2;
  byte bVar3;
  EVP_MD *md;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint *puVar15;
  int in_GS_OFFSET;
  byte bVar16;
  uint local_368;
  uint local_364;
  uint local_35c;
  uint local_348;
  uint local_33c;
  uint local_338;
  code *local_334;
  undefined *local_330;
  code *local_328;
  uint local_320;
  size_t local_318;
  uint local_314;
  uint local_310;
  uint local_308;
  uint *local_2fc;
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
  
  bVar16 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0xfffff < param_7) {
    OpenSSLDie("s3_cbc.c",0x1d7,"data_plus_mac_plus_padding_size < 1024*1024");
  }
  md = EVP_MD_CTX_md(param_1);
  iVar4 = EVP_MD_type(md);
  if (iVar4 == 0x2a0) {
    iVar10 = 0x33;
    iVar9 = 8;
    SHA256_Init((SHA256_CTX *)local_2cc);
    iVar4 = 0x27;
    iVar6 = 0x200;
    bVar2 = true;
    local_308 = 0x28;
    local_368 = 0x40;
    local_318 = 0x20;
    local_334 = SHA256_Transform;
    local_328 = tls1_sha256_final_raw;
LAB_080ab37a:
    if (param_10 == '\0') goto LAB_080ab090;
LAB_080ab385:
    local_364 = local_308 + 0xb + param_9;
    local_348 = param_7 + local_364;
    local_320 = (iVar4 + local_348) / local_368;
    uVar11 = (local_364 - local_318) + param_6;
    local_314 = uVar11 / local_368;
    local_35c = uVar11 % local_368;
    local_310 = (iVar9 + uVar11) / local_368;
    uVar5 = 2;
    if (local_320 < 4) goto LAB_080ab0f0;
LAB_080ab3e6:
    iVar4 = uVar11 << 3;
    local_33c = local_320 - uVar5;
    local_338 = local_368 * local_33c;
    if (param_10 == '\0') goto LAB_080ab112;
LAB_080ab40b:
    if (!bVar2) goto LAB_080ab1c2;
LAB_080ab416:
    __memset_chk(local_1f0,0,iVar9 + -4,0x10);
    *(char *)((int)local_1f0 + iVar9 + -4) = (char)((uint)iVar4 >> 0x18);
    *(char *)((int)local_1f0 + iVar9 + -3) = (char)((uint)iVar4 >> 0x10);
    *(char *)((int)local_1f0 + iVar9 + -2) = (char)((uint)iVar4 >> 8);
    *(char *)((int)local_1f0 + iVar9 + -1) = (char)iVar4;
    if (local_338 == 0) goto LAB_080ab228;
LAB_080ab46b:
    local_330 = local_2cc;
    if (param_10 == '\0') {
      local_a0[0] = *param_4;
      local_a0[1] = param_4[1];
      local_98 = param_4[2];
      uStack_97._3_1_ = *(undefined *)(param_4 + 3);
      local_93._0_4_ = *param_5;
      *(undefined4 *)((int)&stack0xffffff68 + iVar10 + 1) =
           *(undefined4 *)((int)param_5 + iVar10 + -4);
      puVar13 = (undefined4 *)((int)param_5 + 3);
      puVar14 = (undefined4 *)(local_93 + 3);
      for (uVar5 = iVar10 - 3U >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *puVar14 = *puVar13;
        puVar13 = puVar13 + (uint)bVar16 * -2 + 1;
        puVar14 = puVar14 + (uint)bVar16 * -2 + 1;
      }
      (*local_334)(local_330,local_a0);
      if (1 < local_338 / local_368) {
        iVar4 = (int)param_5 + -0xd;
        uVar5 = 1;
        do {
          iVar4 = iVar4 + local_368;
          uVar5 = uVar5 + 1;
          (*local_334)(local_330,iVar4);
        } while (local_338 / local_368 != uVar5);
      }
      puVar15 = &local_1e0;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + (uint)bVar16 * -2 + 1;
      }
      if (local_33c <= local_320) goto LAB_080ab529;
      EVP_MD_CTX_init(&local_2e4);
      EVP_DigestInit_ex(&local_2e4,param_1->digest,(ENGINE *)0x0);
      goto LAB_080ab27b;
    }
    iVar4 = local_364 - local_368;
    (*local_334)(local_330,param_4);
    __memcpy_chk(local_a0,(int)param_4 + local_368,iVar4,0x80);
    memcpy((void *)(iVar4 + (int)local_a0),param_5,local_368 - iVar4);
    (*local_334)(local_330,local_a0);
    uVar5 = local_338 / local_368 - 1;
    if (1 < uVar5) {
      iVar4 = (local_368 - iVar4) + (int)param_5;
      uVar11 = 1;
      do {
        uVar11 = uVar11 + 1;
        (*local_334)(local_330,iVar4);
        iVar4 = iVar4 + local_368;
      } while (uVar5 != uVar11);
    }
    puVar15 = &local_1e0;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + (uint)bVar16 * -2 + 1;
    }
    if (local_33c <= local_320) goto LAB_080ab529;
    EVP_MD_CTX_init(&local_2e4);
    EVP_DigestInit_ex(&local_2e4,param_1->digest,(ENGINE *)0x0);
LAB_080ab8e8:
    *(undefined4 *)((int)local_1a4 + local_308) = 0x5c5c5c5c;
    puVar15 = local_1a4 + 1;
    for (uVar5 = local_308 - 1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar15 = 0x5c5c5c5c;
      puVar15 = puVar15 + (uint)bVar16 * -2 + 1;
    }
    EVP_DigestUpdate(&local_2e4,param_8,param_9);
  }
  else {
    if (iVar4 < 0x2a1) {
      if (iVar4 == 4) {
        iVar10 = 0x33;
        iVar9 = 8;
        MD5_Init((MD5_CTX *)local_2cc);
        iVar4 = 0x37;
        iVar6 = 0x200;
        bVar2 = false;
        local_308 = 0x30;
        local_368 = 0x40;
        local_318 = 0x10;
        local_334 = MD5_Transform;
        local_328 = tls1_md5_final_raw;
      }
      else {
        if (iVar4 != 0x40) {
LAB_080ab63b:
          OpenSSLDie("s3_cbc.c",0x20d,"0");
          if (param_3 != (uint *)0x0) {
            *param_3 = 0xffffffff;
          }
          goto LAB_080ab303;
        }
        iVar10 = 0x33;
        iVar9 = 8;
        SHA1_Init((SHA_CTX *)local_2cc);
        iVar4 = 0x33;
        iVar6 = 0x200;
        bVar2 = true;
        local_308 = 0x28;
        local_368 = 0x40;
        local_318 = 0x14;
        local_334 = SHA1_Transform;
        local_328 = tls1_sha1_final_raw;
      }
      goto LAB_080ab37a;
    }
    if (iVar4 == 0x2a2) {
      iVar10 = 0x73;
      iVar9 = 0x10;
      SHA512_Init((SHA512_CTX *)local_2cc);
      iVar4 = 0x4f;
      iVar6 = 0x400;
      bVar2 = true;
      local_308 = 0x28;
      local_368 = 0x80;
      local_318 = 0x40;
      local_334 = SHA512_Transform;
      local_328 = tls1_sha512_final_raw;
      goto LAB_080ab37a;
    }
    if (iVar4 < 0x2a2) {
      iVar10 = 0x73;
      iVar9 = 0x10;
      SHA384_Init((SHA512_CTX *)local_2cc);
      iVar4 = 0x5f;
      iVar6 = 0x400;
      bVar2 = true;
      local_308 = 0x28;
      local_368 = 0x80;
      local_318 = 0x30;
      local_334 = SHA512_Transform;
      local_328 = tls1_sha512_final_raw;
      goto LAB_080ab37a;
    }
    if (iVar4 != 0x2a3) goto LAB_080ab63b;
    iVar10 = 0x33;
    iVar9 = 8;
    SHA224_Init((SHA256_CTX *)local_2cc);
    iVar4 = 0x2b;
    iVar6 = 0x200;
    bVar2 = true;
    local_308 = 0x28;
    local_368 = 0x40;
    local_318 = 0x1c;
    local_334 = SHA256_Transform;
    local_328 = tls1_sha256_final_raw;
    if (param_10 != '\0') goto LAB_080ab385;
LAB_080ab090:
    local_348 = param_7 + 0xd;
    local_364 = 0xd;
    local_320 = ((local_368 + 0xc + param_7 + iVar9) - local_318) / local_368;
    uVar11 = (param_6 + 0xd) - local_318;
    local_314 = uVar11 / local_368;
    local_35c = uVar11 % local_368;
    local_310 = (iVar9 + uVar11) / local_368;
    uVar5 = 6;
    if (6 < local_320) goto LAB_080ab3e6;
LAB_080ab0f0:
    iVar4 = uVar11 << 3;
    local_338 = 0;
    local_33c = 0;
    local_320 = uVar5;
    if (param_10 != '\0') goto LAB_080ab40b;
LAB_080ab112:
    local_330 = local_2cc;
    iVar4 = iVar4 + iVar6;
    *(undefined4 *)((int)local_1a4 + local_368) = 0;
    puVar15 = local_1a4 + 1;
    for (uVar5 = local_368 - 1 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar15 = 0;
      puVar15 = puVar15 + (uint)bVar16 * -2 + 1;
    }
    if (0x80 < param_9) {
      OpenSSLDie("s3_cbc.c",0x266,"mac_secret_length <= sizeof(hmac_pad)");
    }
    __memcpy_chk(local_1a4 + 1,param_8,param_9,0x80);
    uVar5 = 0;
    do {
      local_1a4[uVar5 + 1] = local_1a4[uVar5 + 1] ^ 0x36363636;
      uVar5 = uVar5 + 1;
    } while (uVar5 < (local_368 - 4 >> 2) + 1);
    (*local_334)(local_330,local_1a4 + 1);
    if (bVar2) goto LAB_080ab416;
LAB_080ab1c2:
    *(undefined4 *)((int)local_1f0 + iVar9 + -4) = 0;
    uVar5 = 0;
    do {
      *(undefined4 *)((int)local_1f0 + uVar5) = 0;
      uVar5 = uVar5 + 4;
    } while (uVar5 < iVar9 - 4U);
    auStack_1f7[iVar9 + 2] = (char)((uint)iVar4 >> 0x18);
    auStack_1f7[iVar9 + 1] = (char)((uint)iVar4 >> 0x10);
    auStack_1f7[iVar9] = (char)((uint)iVar4 >> 8);
    local_2cc[iVar9 + 0xd4] = (char)iVar4;
    if (local_338 != 0) goto LAB_080ab46b;
LAB_080ab228:
    puVar15 = &local_1e0;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar15 = local_338;
      puVar15 = puVar15 + (uint)bVar16 * -2 + 1;
    }
    if (local_33c <= local_320) {
LAB_080ab529:
      local_330 = local_2cc;
      uVar5 = local_318 - 4 >> 2;
      do {
        uVar12 = 0;
        iVar4 = (local_33c ^ local_310) - 1;
        bVar7 = (byte)(iVar4 >> 0x1f);
        bVar1 = (byte)((local_314 ^ local_33c) - 1 >> 0x18);
        uVar11 = local_338;
        do {
          if (uVar11 < local_364) {
            bVar8 = *(byte *)((int)param_4 + uVar12 + local_338);
            bVar3 = bVar8 + 0x80;
          }
          else if (uVar11 < local_348) {
            bVar8 = *(byte *)((int)param_5 + uVar12 + (local_338 - local_364));
            bVar3 = bVar8 + 0x80;
          }
          else {
            bVar3 = 0x80;
            bVar8 = 0;
          }
          uVar11 = uVar11 + 1;
          bVar3 = ~((char)((byte)(local_35c - uVar12 >> 0x18) & bVar1) >> 7) &
                  ((char)bVar1 >> 7 | ~bVar7) &
                  ((char)((byte)((local_35c - 1) - uVar12 >> 0x18) & bVar1) >> 7 & bVar3 ^ bVar8);
          if (local_368 - iVar9 <= uVar12) {
            bVar3 = bVar3 & ~bVar7 |
                    bVar7 & *(byte *)((int)local_1f0 + uVar12 + (iVar9 - local_368));
          }
          *(byte *)((int)&local_120 + uVar12) = bVar3;
          uVar12 = uVar12 + 1;
        } while (local_368 != uVar12);
        local_338 = local_338 + local_368;
        (*local_334)(local_330,&local_120);
        (*local_328)(local_330,&local_120);
        uVar11 = iVar4 >> 0x1f & 0xff;
        uVar11 = uVar11 << 0x18 | (uint)CONCAT11(bVar7,bVar7) | uVar11 << 0x10;
        local_1e0 = local_1e0 | local_120 & uVar11;
        local_1dc = local_1dc | local_11c & uVar11;
        local_1d8 = local_1d8 | local_118 & uVar11;
        local_1d4 = local_1d4 | local_114 & uVar11;
        if (((((uVar5 != 3) && (local_1d0 = local_1d0 | local_110 & uVar11, uVar5 != 4)) &&
             (local_1cc = local_1cc | local_10c & uVar11, uVar5 != 5)) &&
            ((((local_1c8 = local_1c8 | local_108 & uVar11, uVar5 != 6 &&
               (local_1c4 = local_1c4 | local_104 & uVar11, uVar5 != 7)) &&
              ((local_1c0 = local_1c0 | local_100 & uVar11, uVar5 != 8 &&
               ((local_1bc = local_1bc | local_fc & uVar11, uVar5 != 9 &&
                (local_1b8 = local_1b8 | local_f8 & uVar11, uVar5 != 10)))))) &&
             (local_1b4 = local_1b4 | local_f4 & uVar11, uVar5 != 0xb)))) &&
           (((local_1b0 = local_1b0 | local_f0 & uVar11, uVar5 != 0xc &&
             (local_1ac = local_1ac | local_ec & uVar11, uVar5 != 0xd)) &&
            (local_1a8 = local_1a8 | local_e8 & uVar11, uVar5 == 0xf)))) {
          local_1a4[0] = local_1a4[0] | local_e4 & uVar11;
        }
        local_33c = local_33c + 1;
      } while (local_33c <= local_320);
    }
    EVP_MD_CTX_init(&local_2e4);
    EVP_DigestInit_ex(&local_2e4,param_1->digest,(ENGINE *)0x0);
    if (param_10 != '\0') goto LAB_080ab8e8;
LAB_080ab27b:
    uVar5 = 0;
    do {
      local_1a4[uVar5 + 1] = local_1a4[uVar5 + 1] ^ 0x6a6a6a6a;
      uVar5 = uVar5 + 1;
      local_308 = local_368;
    } while (uVar5 < (local_368 - 4 >> 2) + 1);
  }
  local_2fc = &local_1e0;
  EVP_DigestUpdate(&local_2e4,local_1a4 + 1,local_308);
  EVP_DigestUpdate(&local_2e4,local_2fc,local_318);
  EVP_DigestFinal(&local_2e4,param_2,&local_2e8);
  if (param_3 != (uint *)0x0) {
    *param_3 = local_2e8;
  }
  EVP_MD_CTX_cleanup(&local_2e4);
LAB_080ab303:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

