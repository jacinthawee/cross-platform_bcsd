
void ssl3_cbc_digest_record
               (EVP_MD_CTX *param_1,uchar *param_2,uint *param_3,undefined4 *param_4,void *param_5,
               int param_6,uint param_7,void *param_8,uint param_9,byte param_10)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  EVP_MD *md;
  uint __n;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int extraout_r1;
  int extraout_r1_00;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  byte bVar15;
  uint uVar16;
  uint uVar17;
  size_t __n_00;
  int iVar18;
  size_t __n_01;
  uint uVar19;
  byte bVar20;
  int local_37c;
  uint local_374;
  uint local_368;
  uint local_364;
  SHA512_CTX *local_360;
  code *local_35c;
  code *local_350;
  uint local_34c;
  undefined4 *local_340;
  uint local_330;
  uint local_32c;
  size_t local_320;
  uint local_2f4;
  undefined auStack_2f0 [17];
  byte abStack_2df [19];
  uint uStack_2cc;
  undefined4 local_2c8;
  uint uStack_28c;
  undefined4 local_288;
  undefined4 local_208;
  undefined4 uStack_204;
  undefined4 uStack_200;
  undefined local_1fc;
  undefined auStack_1fb [111];
  uint uStack_18c;
  undefined4 local_188;
  SHA512_CTX SStack_108;
  int local_2c;
  
  uVar16 = (uint)param_10;
  local_2c = __TMC_END__;
  if (0xfffff < param_7) {
    OpenSSLDie("s3_cbc.c",0x1d7,"data_plus_mac_plus_padding_size < 1024*1024");
  }
  md = EVP_MD_CTX_md(param_1);
  __n = EVP_MD_type(md);
  if (__n == 0x2a0) {
    local_35c = SHA256_Transform + 1;
    local_350 = tls1_sha256_final_raw + 1;
    SHA256_Init((SHA256_CTX *)&SStack_108);
    __n_01 = 0x33;
    local_320 = 0x28;
    iVar5 = 0x27;
    iVar18 = 0x200;
    bVar14 = true;
    __n_00 = 8;
    __n = 0x40;
    local_34c = 0x20;
LAB_000535d2:
    if (uVar16 == 0) goto LAB_0005354a;
LAB_000535d8:
    uVar19 = local_320 + param_9 + 0xb;
    local_374 = param_7 + uVar19;
    uVar6 = __udivsi3(iVar5 + local_374,__n);
    param_6 = (uVar19 - local_34c) + param_6;
    __aeabi_uidivmod(param_6,__n);
    local_330 = __udivsi3(param_6,__n);
    local_32c = __udivsi3(param_6 + __n_00,__n);
    uVar9 = 3;
    uVar12 = 2;
    local_37c = extraout_r1_00;
  }
  else {
    if ((int)__n < 0x2a1) {
      if (__n == 4) {
        local_35c = MD5_Transform + 1;
        local_350 = tls1_md5_final_raw + 1;
        __n_01 = 0x33;
        MD5_Init((MD5_CTX *)&SStack_108);
        iVar5 = 0x37;
        local_320 = 0x30;
        iVar18 = 0x200;
        bVar14 = false;
        __n_00 = 8;
        __n = 0x40;
        local_34c = 0x10;
      }
      else {
        if (__n != 0x40) {
LAB_00053832:
          OpenSSLDie("s3_cbc.c",0x20d,"0");
          if (param_3 != (uint *)0x0) {
            *param_3 = 0xffffffff;
          }
          goto LAB_00053854;
        }
        local_35c = SHA1_Transform + 1;
        SHA1_Init((SHA_CTX *)&SStack_108);
        iVar5 = 0x33;
        local_350 = tls1_sha1_final_raw + 1;
        __n_01 = 0x33;
        local_320 = 0x28;
        iVar18 = 0x200;
        bVar14 = true;
        __n_00 = 8;
        local_34c = 0x14;
      }
      goto LAB_000535d2;
    }
    if (__n == 0x2a2) {
      local_35c = SHA512_Transform + 1;
      local_350 = tls1_sha512_final_raw + 1;
      __n_01 = 0x73;
      SHA512_Init(&SStack_108);
      iVar18 = 0x400;
      iVar5 = 0x4f;
      bVar14 = true;
      __n_00 = 0x10;
      __n = 0x80;
      local_320 = 0x28;
      local_34c = 0x40;
      goto LAB_000535d2;
    }
    if ((int)__n < 0x2a2) {
      local_35c = SHA512_Transform + 1;
      local_350 = tls1_sha512_final_raw + 1;
      SHA384_Init(&SStack_108);
      __n_01 = 0x73;
      local_320 = 0x28;
      iVar5 = 0x5f;
      iVar18 = 0x400;
      bVar14 = true;
      __n_00 = 0x10;
      __n = 0x80;
      local_34c = 0x30;
      goto LAB_000535d2;
    }
    if (__n != 0x2a3) goto LAB_00053832;
    local_35c = SHA256_Transform + 1;
    local_350 = tls1_sha256_final_raw + 1;
    SHA224_Init((SHA256_CTX *)&SStack_108);
    local_320 = 0x28;
    local_34c = 0x1c;
    __n_01 = 0x33;
    iVar5 = 0x2b;
    iVar18 = 0x200;
    bVar14 = true;
    __n_00 = 8;
    __n = 0x40;
    if (uVar16 != 0) goto LAB_000535d8;
LAB_0005354a:
    local_374 = param_7 + 0xd;
    uVar6 = __udivsi3((param_7 + 0xc + __n + __n_00) - local_34c,__n);
    param_6 = (param_6 + 0xd) - local_34c;
    __aeabi_uidivmod(param_6,__n);
    local_330 = __udivsi3(param_6,__n);
    local_32c = __udivsi3(param_6 + __n_00,__n);
    uVar9 = 6;
    uVar12 = 6;
    uVar19 = 0xd;
    local_37c = extraout_r1;
  }
  local_360 = &SStack_108;
  if (uVar9 < uVar6) {
    local_364 = uVar6 - uVar12;
    local_368 = __n * local_364;
  }
  else {
    local_364 = 0;
    local_368 = 0;
    uVar6 = uVar12;
  }
  param_6 = param_6 * 8;
  if (uVar16 == 0) {
    memset(&local_288,0,__n);
    param_6 = param_6 + iVar18;
    if (0x80 < param_9) {
      OpenSSLDie("s3_cbc.c",0x266,"mac_secret_length <= sizeof(hmac_pad)");
    }
    uVar9 = __n;
    if (__n == 0) {
      uVar9 = 1;
    }
    __memcpy_chk(&local_288,param_8,param_9,0x80);
    if (uVar9 >> 2 == 0) {
      uVar12 = 1;
      local_288._0_1_ = (byte)local_288 ^ 0x36;
LAB_00053ac2:
      uVar9 = uVar12 + 1;
      *(byte *)((int)&local_288 + uVar12) = *(byte *)((int)&local_288 + uVar12) ^ 0x36;
      if (uVar9 < __n) {
        *(byte *)((int)&local_288 + uVar9) = *(byte *)((int)&local_288 + uVar9) ^ 0x36;
      }
    }
    else {
      puVar8 = &uStack_28c;
      uVar12 = 0;
      do {
        uVar12 = uVar12 + 1;
        puVar7 = puVar8 + 1;
        puVar8 = puVar8 + 1;
        *puVar8 = *puVar7 ^ 0x36363636;
      } while (uVar12 < uVar9 >> 2);
      if ((uVar9 & 0xfffffffc) != uVar9) {
        uVar12 = (uVar9 & 0xfffffffc) + 1;
        *(byte *)((int)&local_288 + (uVar9 & 0xfffffffc)) =
             *(byte *)((int)&local_288 + (uVar9 & 0xfffffffc)) ^ 0x36;
        if (uVar12 < __n) goto LAB_00053ac2;
      }
    }
    (*local_35c)(local_360,&local_288);
  }
  local_340 = &local_288;
  bVar3 = (byte)((uint)param_6 >> 8);
  bVar2 = (byte)((uint)param_6 >> 0x10);
  bVar20 = (byte)((uint)param_6 >> 0x18);
  if (bVar14) {
    __memset_chk(abStack_2df + 7,0,__n_00 - 4,0x10);
    (abStack_2df + 7)[__n_00 - 4] = bVar20;
    abStack_2df[__n_00 + 6] = (byte)param_6;
    abStack_2df[__n_00 + 4] = bVar2;
    abStack_2df[__n_00 + 5] = bVar3;
  }
  else {
    memset(abStack_2df + 7,0,__n_00);
    auStack_2f0[__n_00 + 0x10] = (byte)param_6;
    abStack_2df[__n_00 + 2] = bVar20;
    abStack_2df[__n_00 + 1] = bVar2;
    abStack_2df[__n_00] = bVar3;
  }
  if (local_368 != 0) {
    if (uVar16 == 0) {
      local_208 = *param_4;
      uStack_204 = param_4[1];
      uStack_200 = param_4[2];
      local_1fc = *(undefined *)(param_4 + 3);
      memcpy(auStack_1fb,param_5,__n_01);
      (*local_35c)(local_360,&local_208);
      uVar9 = __udivsi3(local_368,__n);
      if (1 < uVar9) {
        iVar18 = (__n - 0xd) + (int)param_5;
        uVar12 = 1;
        do {
          uVar12 = uVar12 + 1;
          (*local_35c)(local_360,iVar18);
          iVar18 = iVar18 + __n;
        } while (uVar12 != uVar9);
      }
    }
    else {
      iVar5 = uVar19 - __n;
      (*local_35c)(local_360,param_4);
      __memcpy_chk(&local_208,(int)param_4 + __n,iVar5,0x80);
      memcpy((void *)((int)&local_208 + iVar5),param_5,__n - iVar5);
      (*local_35c)(local_360,&local_208);
      iVar18 = __udivsi3(local_368,__n);
      if (1 < iVar18 - 1U) {
        iVar5 = (__n - iVar5) + (int)param_5;
        uVar9 = 1;
        do {
          uVar9 = uVar9 + 1;
          (*local_35c)(local_360,iVar5);
          iVar5 = iVar5 + __n;
        } while (uVar9 != iVar18 - 1U);
      }
    }
  }
  memset(&local_2c8,0,0x40);
  if (local_364 <= uVar6) {
    uVar9 = local_34c;
    if (local_34c == 0) {
      uVar9 = 1;
    }
    uVar10 = count_leading_zeroes(uVar9 >> 2);
    uVar10 = uVar10 >> 5;
    uVar12 = uVar9 & 0xfffffffc;
    if (uVar10 != 0) {
      uVar12 = 0;
    }
    uVar17 = __n;
    if (__n == 0) {
      uVar17 = 1;
    }
    do {
      iVar18 = (local_364 ^ local_330) - 1;
      bVar2 = (byte)((int)((local_364 ^ local_32c) - 1) >> 0x1f);
      bVar3 = (byte)((uint)iVar18 >> 0x18);
      bVar20 = ~bVar2;
      if (iVar18 < 0) {
        bVar20 = 0xff;
      }
      uVar13 = 0;
      uVar11 = local_368;
      iVar18 = local_37c;
      do {
        iVar18 = iVar18 + -1;
        bVar4 = (byte)((uint)iVar18 >> 0x18);
        if (uVar11 < uVar19) {
          bVar15 = *(byte *)((int)param_4 + uVar13 + local_368) & ~((char)(bVar3 & bVar4) >> 7);
        }
        else if (uVar11 < local_374) {
          bVar15 = *(byte *)((int)param_5 + uVar13 + (local_368 - uVar19)) &
                   ~((char)(bVar3 & bVar4) >> 7);
        }
        else {
          bVar15 = 0;
        }
        uVar11 = uVar11 + 1;
        bVar4 = bVar20 & ~((char)(bVar3 & (byte)(local_37c - uVar13 >> 0x18)) >> 7) &
                (bVar15 | (char)(bVar3 & bVar4) >> 7 & 0x80U);
        if (__n - __n_00 <= uVar13) {
          bVar4 = bVar4 & ~bVar2 | abStack_2df[uVar13 + (__n_00 - __n) + 7] & bVar2;
        }
        *(byte *)((int)&local_188 + uVar13) = bVar4;
        uVar13 = uVar13 + 1;
      } while (uVar13 < __n);
      (*local_35c)(local_360,&local_188);
      (*local_350)(local_360,&local_188);
      if (uVar10 == 0) {
        puVar8 = &uStack_18c;
        puVar7 = &uStack_2cc;
        uVar11 = uVar10;
        do {
          puVar8 = puVar8 + 1;
          uVar11 = uVar11 + 1;
          puVar1 = puVar7 + 1;
          puVar7 = puVar7 + 1;
          *puVar7 = *puVar1 | *puVar8 & CONCAT13(bVar2,CONCAT12(bVar2,CONCAT11(bVar2,bVar2)));
        } while (uVar11 < uVar9 >> 2);
        if ((uVar9 & 0xfffffffc) != uVar9) goto LAB_000538b4;
      }
      else {
LAB_000538b4:
        *(byte *)((int)&local_2c8 + uVar12) =
             *(byte *)((int)&local_2c8 + uVar12) | *(byte *)((int)&local_188 + uVar12) & bVar2;
        if ((uVar12 + 1 < local_34c) &&
           (*(byte *)((int)&local_2c8 + uVar12 + 1) =
                 *(byte *)((int)&local_2c8 + uVar12 + 1) |
                 *(byte *)((int)&local_188 + uVar12 + 1) & bVar2, uVar12 + 2 < local_34c)) {
          *(byte *)((int)&local_2c8 + uVar12 + 2) =
               *(byte *)((int)&local_2c8 + uVar12 + 2) |
               *(byte *)((int)&local_188 + uVar12 + 2) & bVar2;
        }
      }
      local_364 = local_364 + 1;
      local_368 = local_368 + uVar17;
    } while (local_364 <= uVar6);
  }
  EVP_MD_CTX_init((EVP_MD_CTX *)auStack_2f0);
  EVP_DigestInit_ex((EVP_MD_CTX *)auStack_2f0,param_1->digest,(ENGINE *)0x0);
  if (uVar16 == 0) {
    uVar6 = __n;
    if (__n == 0) {
      uVar6 = 1;
    }
    if (uVar6 >> 2 == 0) {
      uVar16 = 1;
      local_288._0_1_ = (byte)local_288 ^ 0x6a;
LAB_00053966:
      uVar6 = uVar16 + 1;
      *(byte *)((int)local_340 + uVar16) = *(byte *)((int)local_340 + uVar16) ^ 0x6a;
      if (uVar6 < __n) {
        *(byte *)((int)local_340 + uVar6) = *(byte *)((int)local_340 + uVar6) ^ 0x6a;
      }
    }
    else {
      puVar8 = &uStack_28c;
      do {
        uVar16 = uVar16 + 1;
        puVar7 = puVar8 + 1;
        puVar8 = puVar8 + 1;
        *puVar8 = *puVar7 ^ 0x6a6a6a6a;
      } while (uVar16 < uVar6 >> 2);
      if ((uVar6 & 0xfffffffc) != uVar6) {
        uVar16 = (uVar6 & 0xfffffffc) + 1;
        *(byte *)((int)local_340 + (uVar6 & 0xfffffffc)) =
             *(byte *)((int)local_340 + (uVar6 & 0xfffffffc)) ^ 0x6a;
        if (uVar16 < __n) goto LAB_00053966;
      }
    }
  }
  else {
    memset(local_340,0x5c,local_320);
    EVP_DigestUpdate((EVP_MD_CTX *)auStack_2f0,param_8,param_9);
    __n = local_320;
  }
  EVP_DigestUpdate((EVP_MD_CTX *)auStack_2f0,local_340,__n);
  EVP_DigestUpdate((EVP_MD_CTX *)auStack_2f0,&local_2c8,local_34c);
  EVP_DigestFinal((EVP_MD_CTX *)auStack_2f0,param_2,&local_2f4);
  if (param_3 != (uint *)0x0) {
    *param_3 = local_2f4;
  }
  EVP_MD_CTX_cleanup((EVP_MD_CTX *)auStack_2f0);
LAB_00053854:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

