
void ssl3_cbc_digest_record
               (EVP_MD_CTX *param_1,uchar *param_2,uint *param_3,undefined4 *param_4,void *param_5,
               int param_6,uint param_7,void *param_8,uint param_9,byte param_10)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  EVP_MD *md;
  uint __n;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint extraout_r1;
  uint extraout_r1_00;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int __c;
  size_t __n_00;
  uint uVar23;
  byte bVar24;
  size_t local_384;
  uint local_380;
  uint local_370;
  uint local_364;
  uint local_360;
  SHA512_CTX *local_35c;
  code *local_358;
  code *local_34c;
  uint local_348;
  uint local_334;
  uint local_330;
  size_t local_31c;
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
  
  uVar22 = (uint)param_10;
  local_2c = __stack_chk_guard;
  if (0xfffff < param_7) {
    OpenSSLDie("s3_cbc.c",0x1c7,"data_plus_mac_plus_padding_size < 1024 * 1024");
  }
  md = EVP_MD_CTX_md(param_1);
  __n = EVP_MD_type(md);
  if (__n == 0x2a0) {
    iVar7 = SHA256_Init((SHA256_CTX *)&SStack_108);
    if (0 < iVar7) {
      local_358 = SHA256_Transform + 1;
      local_34c = tls1_sha256_final_raw + 1;
      local_384 = 0x33;
      iVar8 = 0x27;
      iVar7 = 0x200;
      __c = 1;
      __n_00 = 8;
      local_31c = 0x28;
      __n = 0x40;
      local_348 = 0x20;
      goto LAB_00050bf2;
    }
  }
  else if ((int)__n < 0x2a1) {
    if (__n == 4) {
      iVar7 = MD5_Init((MD5_CTX *)&SStack_108);
      if (0 < iVar7) {
        local_358 = MD5_Transform + 1;
        local_34c = tls1_md5_final_raw + 1;
        local_384 = 0x33;
        iVar8 = 0x37;
        iVar7 = 0x200;
        __c = 0;
        __n_00 = 8;
        local_31c = 0x30;
        __n = 0x40;
        local_348 = 0x10;
        goto LAB_00050bf2;
      }
    }
    else if (__n == 0x40) {
      iVar7 = SHA1_Init((SHA_CTX *)&SStack_108);
      if (0 < iVar7) {
        local_34c = tls1_sha1_final_raw + 1;
        local_358 = SHA1_Transform + 1;
        iVar7 = 0x200;
        __c = 1;
        __n_00 = 8;
        iVar8 = 0x33;
        local_384 = 0x33;
        local_31c = 0x28;
        local_348 = 0x14;
        goto LAB_00050bf2;
      }
    }
    else {
LAB_00050f10:
      OpenSSLDie("s3_cbc.c",0x209,"0");
      if (param_3 != (uint *)0x0) {
        uVar9 = 0;
        *param_3 = 0xffffffff;
        goto LAB_00050ca4;
      }
    }
  }
  else if (__n == 0x2a2) {
    iVar7 = SHA512_Init(&SStack_108);
    if (0 < iVar7) {
      local_358 = SHA512_Transform + 1;
      local_34c = tls1_sha512_final_raw + 1;
      local_384 = 0x73;
      iVar8 = 0x4f;
      iVar7 = 0x400;
      __c = 1;
      __n_00 = 0x10;
      local_31c = 0x28;
      __n = 0x80;
      local_348 = 0x40;
LAB_00050bf2:
      if (uVar22 == 0) goto LAB_00050b68;
LAB_00050bf8:
      local_380 = 2;
      uVar23 = local_31c + param_9 + 0xb;
      local_370 = param_7 + uVar23;
      local_364 = __udivsi3(iVar8 + local_370,__n);
      param_6 = param_6 + (uVar23 - local_348);
      __aeabi_uidivmod(param_6,__n);
      local_334 = __udivsi3(param_6,__n);
      local_330 = __udivsi3(param_6 + __n_00,__n);
      uVar16 = 3;
      uVar21 = extraout_r1_00;
      goto LAB_00050c3c;
    }
  }
  else if ((int)__n < 0x2a2) {
    iVar7 = SHA384_Init(&SStack_108);
    if (0 < iVar7) {
      local_358 = SHA512_Transform + 1;
      local_34c = tls1_sha512_final_raw + 1;
      local_384 = 0x73;
      iVar8 = 0x5f;
      iVar7 = 0x400;
      __c = 1;
      __n_00 = 0x10;
      local_31c = 0x28;
      __n = 0x80;
      local_348 = 0x30;
      goto LAB_00050bf2;
    }
  }
  else {
    if (__n != 0x2a3) goto LAB_00050f10;
    iVar7 = SHA224_Init((SHA256_CTX *)&SStack_108);
    if (iVar7 < 1) goto LAB_00050ca2;
    local_358 = SHA256_Transform + 1;
    local_34c = tls1_sha256_final_raw + 1;
    local_384 = 0x33;
    iVar8 = 0x2b;
    iVar7 = 0x200;
    __c = 1;
    __n_00 = 8;
    local_31c = 0x28;
    __n = 0x40;
    local_348 = 0x1c;
    if (uVar22 != 0) goto LAB_00050bf8;
LAB_00050b68:
    local_370 = param_7 + 0xd;
    uVar23 = 0xd;
    local_364 = __udivsi3((param_7 + 0xc + __n + __n_00) - local_348,__n);
    param_6 = (param_6 + 0xd) - local_348;
    __aeabi_uidivmod(param_6,__n);
    local_334 = __udivsi3(param_6,__n);
    local_330 = __udivsi3(param_6 + __n_00,__n);
    uVar16 = 6;
    local_380 = 6;
    uVar21 = extraout_r1;
LAB_00050c3c:
    local_35c = &SStack_108;
    if (uVar16 < local_364) {
      local_364 = local_364 - local_380;
      local_360 = __n * local_364;
    }
    else {
      local_364 = 0;
      local_360 = 0;
    }
    param_6 = param_6 * 8;
    if (uVar22 == 0) {
      param_6 = param_6 + iVar7;
      memset(&local_288,0,__n);
      if (0x80 < param_9) {
        OpenSSLDie("s3_cbc.c",0x271,"mac_secret_length <= sizeof(hmac_pad)");
      }
      __memcpy_chk(&local_288,param_8,param_9,0x80);
      uVar16 = __n;
      if (__n == 0) {
        uVar16 = 1;
      }
      if (uVar16 >> 2 == 0) {
        uVar20 = 1;
        local_288._0_1_ = (byte)local_288 ^ 0x36;
LAB_00050d3a:
        uVar16 = uVar20 + 1;
        *(byte *)((int)&local_288 + uVar20) = *(byte *)((int)&local_288 + uVar20) ^ 0x36;
        if (uVar16 < __n) {
          *(byte *)((int)&local_288 + uVar16) = *(byte *)((int)&local_288 + uVar16) ^ 0x36;
        }
      }
      else {
        puVar11 = &uStack_28c;
        uVar20 = 0;
        do {
          uVar20 = uVar20 + 1;
          puVar13 = puVar11 + 1;
          puVar11 = puVar11 + 1;
          *puVar11 = *puVar13 ^ 0x36363636;
        } while (uVar20 < uVar16 >> 2);
        if ((uVar16 & 0xfffffffc) != uVar16) {
          uVar20 = (uVar16 & 0xfffffffc) + 1;
          *(byte *)((int)&local_288 + (uVar16 & 0xfffffffc)) =
               *(byte *)((int)&local_288 + (uVar16 & 0xfffffffc)) ^ 0x36;
          if (uVar20 < __n) goto LAB_00050d3a;
        }
      }
      (*local_358)(local_35c,&local_288);
      if (__c != 0) goto LAB_00050c62;
LAB_00050d64:
      memset(abStack_2df + 7,__c,__n_00);
      auStack_2f0[__n_00 + 0x10] = (char)param_6;
      abStack_2df[__n_00] = (byte)((uint)param_6 >> 8);
      abStack_2df[__n_00 + 2] = (byte)((uint)param_6 >> 0x18);
      abStack_2df[__n_00 + 1] = (byte)((uint)param_6 >> 0x10);
    }
    else {
      if (__c == 0) goto LAB_00050d64;
LAB_00050c62:
      __memset_chk(abStack_2df + 7,0,__n_00 - 4,0x10);
      (abStack_2df + 7)[__n_00 - 4] = (byte)((uint)param_6 >> 0x18);
      abStack_2df[__n_00 + 6] = (byte)param_6;
      abStack_2df[__n_00 + 4] = (byte)((uint)param_6 >> 0x10);
      abStack_2df[__n_00 + 5] = (byte)((uint)param_6 >> 8);
    }
    if (local_360 != 0) {
      if (uVar22 == 0) {
        local_208 = *param_4;
        uStack_204 = param_4[1];
        uStack_200 = param_4[2];
        local_1fc = *(undefined *)(param_4 + 3);
        memcpy(auStack_1fb,param_5,local_384);
        (*local_358)(local_35c,&local_208);
        uVar16 = __udivsi3(local_360,__n);
        if (1 < uVar16) {
          uVar20 = 1;
          iVar7 = (__n - 0xd) + (int)param_5;
          do {
            uVar20 = uVar20 + 1;
            (*local_358)(local_35c,iVar7);
            iVar7 = iVar7 + __n;
          } while (uVar20 != uVar16);
        }
      }
      else {
        if (uVar23 <= __n) goto LAB_00050ca2;
        iVar8 = uVar23 - __n;
        (*local_358)(local_35c,param_4);
        __memcpy_chk(&local_208,(int)param_4 + __n,iVar8,0x80);
        memcpy((void *)((int)&local_208 + iVar8),param_5,__n - iVar8);
        (*local_358)(local_35c,&local_208);
        iVar7 = __udivsi3(local_360,__n);
        if (1 < iVar7 - 1U) {
          uVar16 = 1;
          iVar8 = (__n - iVar8) + (int)param_5;
          do {
            uVar16 = uVar16 + 1;
            (*local_358)(local_35c,iVar8);
            iVar8 = iVar8 + __n;
          } while (uVar16 != iVar7 - 1U);
        }
      }
    }
    memset(&local_2c8,0,0x40);
    uVar16 = local_364 + local_380;
    if (CARRY4(local_364,local_380) == false) {
      uVar20 = local_348;
      if (local_348 == 0) {
        uVar20 = 1;
      }
      uVar14 = count_leading_zeroes(uVar20 >> 2);
      uVar14 = uVar14 >> 5;
      uVar19 = uVar20 & 0xfffffffc;
      if (uVar14 != 0) {
        uVar19 = 0;
      }
      uVar17 = __n;
      if (__n == 0) {
        uVar17 = 1;
      }
      do {
        bVar3 = (char)((byte)((local_364 ^ local_330) - 1 >> 0x18) &
                      ~(byte)((local_364 ^ local_330) >> 0x18)) >> 7;
        bVar2 = (char)((byte)((local_364 ^ local_334) - 1 >> 0x18) &
                      ~(byte)((local_364 ^ local_334) >> 0x18)) >> 7;
        uVar18 = 0;
        uVar12 = -uVar21;
        uVar15 = local_360;
        do {
          bVar5 = (byte)(uVar18 >> 0x18);
          if (uVar15 < uVar23) {
            bVar24 = (byte)(uVar21 >> 0x18);
            bVar6 = bVar2 & ~((char)(((byte)(uVar12 >> 0x18) ^ bVar24 | bVar5 ^ bVar24) ^ bVar5) >>
                             7);
            bVar24 = *(byte *)((int)param_4 + uVar18 + local_360) & ~bVar6;
          }
          else {
            uVar10 = uVar12 ^ uVar21 | uVar18 ^ uVar21;
            if (uVar15 < local_370) {
              bVar6 = bVar2 & ~((char)((byte)(uVar10 >> 0x18) ^ bVar5) >> 7);
              bVar24 = *(byte *)((int)param_5 + uVar18 + (local_360 - uVar23)) & ~bVar6;
            }
            else {
              bVar24 = 0;
              bVar6 = bVar2;
              if ((int)(uVar10 ^ uVar18) < 0) {
                bVar6 = 0;
              }
            }
          }
          bVar4 = (byte)(uVar21 + 1 >> 0x18);
          uVar15 = uVar15 + 1;
          bVar5 = (bVar2 | ~bVar3) &
                  ~(bVar2 & ~((char)((bVar5 ^ bVar4 | (byte)(~uVar21 + uVar18 >> 0x18) ^ bVar4) ^
                                    bVar5) >> 7)) & (bVar6 & 0x80 | bVar24);
          if (__n - __n_00 <= uVar18) {
            bVar5 = bVar5 & ~bVar3 | abStack_2df[uVar18 + (__n_00 - __n) + 7] & bVar3;
          }
          *(byte *)((int)&local_188 + uVar18) = bVar5;
          uVar18 = uVar18 + 1;
          uVar12 = uVar12 + 1;
        } while (uVar18 < __n);
        (*local_358)(local_35c,&local_188);
        (*local_34c)(local_35c,&local_188);
        if (uVar14 == 0) {
          puVar11 = &uStack_18c;
          puVar13 = &uStack_2cc;
          uVar12 = uVar14;
          do {
            puVar11 = puVar11 + 1;
            uVar12 = uVar12 + 1;
            puVar1 = puVar13 + 1;
            puVar13 = puVar13 + 1;
            *puVar13 = *puVar1 | *puVar11 & CONCAT13(bVar3,CONCAT12(bVar3,CONCAT11(bVar3,bVar3)));
          } while (uVar12 < uVar20 >> 2);
          if ((uVar20 & 0xfffffffc) != uVar20) goto LAB_00050f9c;
        }
        else {
LAB_00050f9c:
          *(byte *)((int)&local_2c8 + uVar19) =
               *(byte *)((int)&local_2c8 + uVar19) | *(byte *)((int)&local_188 + uVar19) & bVar3;
          if ((uVar19 + 1 < local_348) &&
             (*(byte *)((int)&local_2c8 + uVar19 + 1) =
                   *(byte *)((int)&local_2c8 + uVar19 + 1) |
                   *(byte *)((int)&local_188 + uVar19 + 1) & bVar3, uVar19 + 2 < local_348)) {
            *(byte *)((int)&local_2c8 + uVar19 + 2) =
                 *(byte *)((int)&local_2c8 + uVar19 + 2) |
                 *(byte *)((int)&local_188 + uVar19 + 2) & bVar3;
          }
        }
        local_364 = local_364 + 1;
        local_360 = local_360 + uVar17;
      } while (local_364 <= uVar16);
    }
    EVP_MD_CTX_init((EVP_MD_CTX *)auStack_2f0);
    iVar7 = EVP_DigestInit_ex((EVP_MD_CTX *)auStack_2f0,param_1->digest,(ENGINE *)0x0);
    if (0 < iVar7) {
      if (uVar22 == 0) {
        uVar21 = __n;
        if (__n == 0) {
          uVar21 = 1;
        }
        if (uVar21 >> 2 == 0) {
          uVar22 = 1;
          local_288._0_1_ = (byte)local_288 ^ 0x6a;
LAB_00051052:
          *(byte *)((int)&local_288 + uVar22) = *(byte *)((int)&local_288 + uVar22) ^ 0x6a;
          if (uVar22 + 1 < __n) {
            *(byte *)((int)&local_288 + uVar22 + 1) = *(byte *)((int)&local_288 + uVar22 + 1) ^ 0x6a
            ;
          }
        }
        else {
          puVar11 = &uStack_28c;
          do {
            uVar22 = uVar22 + 1;
            puVar13 = puVar11 + 1;
            puVar11 = puVar11 + 1;
            *puVar11 = *puVar13 ^ 0x6a6a6a6a;
          } while (uVar22 < uVar21 >> 2);
          if ((uVar21 & 0xfffffffc) != uVar21) {
            uVar22 = (uVar21 & 0xfffffffc) + 1;
            *(byte *)((int)&local_288 + (uVar21 & 0xfffffffc)) =
                 *(byte *)((int)&local_288 + (uVar21 & 0xfffffffc)) ^ 0x6a;
            if (uVar22 < __n) goto LAB_00051052;
          }
        }
        iVar7 = EVP_DigestUpdate((EVP_MD_CTX *)auStack_2f0,&local_288,__n);
      }
      else {
        memset(&local_288,0x5c,local_31c);
        iVar7 = EVP_DigestUpdate((EVP_MD_CTX *)auStack_2f0,param_8,param_9);
        if (iVar7 < 1) goto LAB_000510c6;
        iVar7 = EVP_DigestUpdate((EVP_MD_CTX *)auStack_2f0,&local_288,local_31c);
      }
      if ((0 < iVar7) &&
         (iVar7 = EVP_DigestUpdate((EVP_MD_CTX *)auStack_2f0,&local_2c8,local_348), 0 < iVar7)) {
        EVP_DigestFinal((EVP_MD_CTX *)auStack_2f0,param_2,&local_2f4);
        if (param_3 != (uint *)0x0) {
          *param_3 = local_2f4;
        }
        EVP_MD_CTX_cleanup((EVP_MD_CTX *)auStack_2f0);
        uVar9 = 1;
        goto LAB_00050ca4;
      }
    }
LAB_000510c6:
    EVP_MD_CTX_cleanup((EVP_MD_CTX *)auStack_2f0);
  }
LAB_00050ca2:
  uVar9 = 0;
LAB_00050ca4:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}

