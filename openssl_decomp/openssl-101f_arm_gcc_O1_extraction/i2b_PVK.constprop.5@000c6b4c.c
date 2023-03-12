
void i2b_PVK_constprop_5(undefined4 *param_1,int *param_2,uchar *param_3,code *param_4,void *param_5
                        )

{
  uint uVar1;
  undefined *puVar2;
  size_t sVar3;
  EVP_MD *type;
  EVP_CIPHER *cipher;
  int iVar4;
  BIGNUM *pBVar5;
  uchar *puVar6;
  undefined uVar7;
  int iVar8;
  uchar *puVar9;
  uchar *puVar10;
  uchar uVar11;
  int iVar12;
  uchar *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uchar *puVar18;
  bool bVar19;
  int local_4ec;
  uchar *local_4e8;
  EVP_MD_CTX local_4e4;
  uchar auStack_4cc [5];
  undefined local_4c7;
  undefined local_4c6;
  undefined local_4c5;
  undefined local_4c4;
  undefined local_4c3;
  undefined local_4c2;
  undefined local_4c1;
  undefined local_4c0;
  undefined local_4bf;
  undefined local_4be;
  undefined local_4bd;
  EVP_CIPHER_CTX EStack_4b8;
  char acStack_42c [1024];
  int local_2c;
  
  local_2c = __TMC_END__;
  EVP_CIPHER_CTX_init(&EStack_4b8);
  if (param_3 == (uchar *)0x0) {
    iVar17 = 0x18;
  }
  else {
    iVar17 = 0x28;
  }
  local_4e4.digest = (EVP_MD *)0x0;
  if (*param_2 == 0x74) {
    iVar12 = param_2[5];
    uVar1 = BN_num_bits(*(BIGNUM **)(iVar12 + 0xc));
    if (((((uVar1 & 7) == 0) && (iVar16 = BN_num_bits(*(BIGNUM **)(iVar12 + 0x10)), iVar16 == 0xa0))
        && (iVar16 = BN_num_bits(*(BIGNUM **)(iVar12 + 0x14)), iVar16 <= (int)uVar1)) &&
       (iVar12 = BN_num_bits(*(BIGNUM **)(iVar12 + 0x1c)), iVar12 < 0xa1)) {
      local_4e4.digest = (EVP_MD *)0x32535344;
    }
    else {
      ERR_put_error(9,0x82,0x7e,"pvkfmt.c",0x23c);
      uVar1 = 0;
    }
    iVar12 = 0x2200;
LAB_000c6ba2:
    if (uVar1 != 0) {
      uVar15 = uVar1 + 7;
      if (iVar12 != 0x2200) {
        uVar1 = uVar1 + 0xf;
      }
      uVar15 = uVar15 >> 3;
      if (iVar12 != 0x2200) {
        iVar12 = (uVar1 >> 4) * 5 + (uVar15 + 2) * 2;
      }
      else {
        iVar12 = (uVar15 + 0x20) * 2;
      }
      iVar16 = iVar12 + 0x10;
      if (-1 < iVar16) {
        iVar17 = iVar17 + iVar16;
        if (param_1 == (undefined4 *)0x0) goto LAB_000c6d50;
        puVar2 = (undefined *)*param_1;
        if (puVar2 == (undefined *)0x0) {
          puVar2 = (undefined *)CRYPTO_malloc(iVar17,"pvkfmt.c",0x362);
          if (puVar2 == (undefined *)0x0) {
            ERR_put_error(9,0x89,0x41,"pvkfmt.c",0x365);
            iVar17 = -1;
            goto LAB_000c6d50;
          }
          *param_1 = puVar2;
        }
        *puVar2 = 0x1e;
        puVar2[1] = 0xf1;
        puVar2[2] = 0xb5;
        puVar2[3] = 0xb0;
        puVar2[4] = 0;
        puVar2[5] = 0;
        puVar2[6] = 0;
        puVar2[7] = 0;
        iVar8 = *param_2;
        puVar2[0xb] = 0;
        bVar19 = iVar8 == 0x74;
        if (bVar19) {
          puVar2[9] = 0;
        }
        if (bVar19) {
          puVar2[10] = 0;
        }
        if (!bVar19) {
          puVar2[9] = 0;
        }
        if (bVar19) {
          iVar8 = 2;
        }
        else {
          puVar2[10] = 0;
        }
        uVar7 = (undefined)iVar8;
        if (!bVar19) {
          uVar7 = 1;
        }
        puVar2[8] = uVar7;
        puVar2[0xd] = 0;
        puVar9 = param_3;
        if (param_3 != (uchar *)0x0) {
          puVar9 = (uchar *)0x1;
        }
        puVar2[0xe] = 0;
        puVar18 = puVar2 + 0x18;
        if (puVar9 != (uchar *)0x0) {
          uVar7 = 0x10;
        }
        else {
          uVar7 = 0;
        }
        puVar2[0xf] = 0;
        puVar2[0x10] = uVar7;
        puVar2[0x11] = 0;
        puVar2[0x12] = 0;
        puVar2[0x13] = 0;
        puVar2[0x14] = (char)iVar16;
        puVar2[0xc] = (char)puVar9;
        puVar2[0x15] = (char)((uint)iVar16 >> 8);
        puVar2[0x16] = (char)((uint)iVar16 >> 0x10);
        puVar2[0x17] = (char)((uint)iVar16 >> 0x18);
        if (puVar9 != (uchar *)0x0) {
          iVar16 = RAND_bytes(puVar18,0x10);
          if (0 < iVar16) {
            iVar16 = *param_2;
            puVar9 = puVar18;
            puVar18 = puVar2 + 0x28;
            goto joined_r0x000c6d80;
          }
        }
        else {
          iVar16 = *param_2;
joined_r0x000c6d80:
          if (iVar16 == 0x74) {
            local_4e4.digest = (EVP_MD *)0x0;
            iVar16 = param_2[5];
            uVar1 = BN_num_bits(*(BIGNUM **)(iVar16 + 0xc));
            if ((((uVar1 & 7) == 0) &&
                (iVar8 = BN_num_bits(*(BIGNUM **)(iVar16 + 0x10)), iVar8 == 0xa0)) &&
               ((iVar8 = BN_num_bits(*(BIGNUM **)(iVar16 + 0x14)), iVar8 <= (int)uVar1 &&
                (iVar16 = BN_num_bits(*(BIGNUM **)(iVar16 + 0x1c)), iVar16 < 0xa1)))) {
              local_4e4.digest = (EVP_MD *)0x32535344;
            }
            else {
              ERR_put_error(9,0x82,0x7e,"pvkfmt.c",0x23c);
              uVar1 = 0;
            }
            uVar11 = '\"';
            local_4ec = 0x2200;
LAB_000c6c7e:
            if (uVar1 != 0) {
              *puVar18 = '\a';
              puVar18[1] = '\x02';
              puVar18[2] = '\0';
              puVar18[3] = '\0';
              local_4e8 = puVar18 + 0x10;
              puVar18[4] = '\0';
              puVar18[5] = uVar11;
              puVar18[6] = '\0';
              puVar18[7] = '\0';
              puVar18[0xd] = (uchar)(uVar1 >> 8);
              puVar18[8] = (uchar)local_4e4.digest;
              puVar18[0xb] = (uchar)((uint)local_4e4.digest >> 0x18);
              puVar18[0xc] = (uchar)uVar1;
              puVar18[9] = (uchar)((uint)local_4e4.digest >> 8);
              puVar18[10] = (uchar)((uint)local_4e4.digest >> 0x10);
              puVar18[0xe] = (uchar)(uVar1 >> 0x10);
              puVar18[0xf] = (uchar)(uVar1 >> 0x18);
              if (local_4ec == 0x2200) {
                iVar14 = param_2[5];
                iVar8 = BN_num_bits(*(BIGNUM **)(iVar14 + 0xc));
                puVar18 = local_4e8;
                pBVar5 = *(BIGNUM **)(iVar14 + 0xc);
                iVar16 = iVar8 + 0xe;
                if (-1 < iVar8 + 7) {
                  iVar16 = iVar8 + 7;
                }
                iVar4 = BN_num_bits(pBVar5);
                iVar16 = iVar16 >> 3;
                iVar8 = iVar4 + 0xe;
                if (-1 < iVar4 + 7) {
                  iVar8 = iVar4 + 7;
                }
                iVar8 = iVar8 >> 3;
                BN_bn2bin(pBVar5,puVar18);
                if (0 < iVar8 / 2) {
                  puVar6 = puVar18 + iVar8 + -1;
                  puVar10 = puVar18;
                  do {
                    uVar11 = *puVar10;
                    puVar13 = puVar10 + 1;
                    *puVar10 = *puVar6;
                    *puVar6 = uVar11;
                    puVar6 = puVar6 + -1;
                    puVar10 = puVar13;
                  } while (puVar13 != puVar18 + iVar8 / 2);
                }
                puVar18 = local_4e8 + iVar8;
                if ((0 < iVar16) && (sVar3 = iVar16 - iVar8, 0 < (int)sVar3)) {
                  local_4e8 = puVar18;
                  memset(puVar18,0,sVar3);
                  puVar18 = local_4e8 + sVar3;
                }
                pBVar5 = *(BIGNUM **)(iVar14 + 0x10);
                local_4e8 = puVar18;
                iVar4 = BN_num_bits(pBVar5);
                iVar8 = iVar4 + 0xe;
                if (-1 < iVar4 + 7) {
                  iVar8 = iVar4 + 7;
                }
                iVar8 = iVar8 >> 3;
                BN_bn2bin(pBVar5,puVar18);
                if (0 < iVar8 / 2) {
                  puVar6 = puVar18 + iVar8 + -1;
                  puVar10 = puVar18;
                  do {
                    uVar11 = *puVar10;
                    puVar13 = puVar10 + 1;
                    *puVar10 = *puVar6;
                    *puVar6 = uVar11;
                    puVar6 = puVar6 + -1;
                    puVar10 = puVar13;
                  } while (puVar13 != puVar18 + iVar8 / 2);
                }
                sVar3 = 0x14 - iVar8;
                puVar18 = local_4e8 + iVar8;
                if (0 < (int)sVar3) {
                  local_4e8 = puVar18;
                  memset(puVar18,0,sVar3);
                  puVar18 = local_4e8 + sVar3;
                }
                pBVar5 = *(BIGNUM **)(iVar14 + 0x14);
                local_4e8 = puVar18;
                iVar4 = BN_num_bits(pBVar5);
                iVar8 = iVar4 + 0xe;
                if (-1 < iVar4 + 7) {
                  iVar8 = iVar4 + 7;
                }
                iVar8 = iVar8 >> 3;
                BN_bn2bin(pBVar5,puVar18);
                if (0 < iVar8 / 2) {
                  puVar6 = puVar18 + iVar8 + -1;
                  puVar10 = puVar18;
                  do {
                    uVar11 = *puVar10;
                    puVar13 = puVar10 + 1;
                    *puVar10 = *puVar6;
                    *puVar6 = uVar11;
                    puVar6 = puVar6 + -1;
                    puVar10 = puVar13;
                  } while (puVar13 != puVar18 + iVar8 / 2);
                }
                puVar18 = local_4e8 + iVar8;
                if ((0 < iVar16) && (sVar3 = iVar16 - iVar8, 0 < (int)sVar3)) {
                  local_4e8 = puVar18;
                  memset(puVar18,0,sVar3);
                  puVar18 = local_4e8 + sVar3;
                }
                pBVar5 = *(BIGNUM **)(iVar14 + 0x1c);
                local_4e8 = puVar18;
                iVar8 = BN_num_bits(pBVar5);
                iVar16 = iVar8 + 7;
                if (iVar8 + 7 < 0) {
                  iVar16 = iVar8 + 0xe;
                }
                iVar8 = iVar16 >> 3;
                BN_bn2bin(pBVar5,puVar18);
                iVar16 = iVar8 - (iVar16 >> 0x1f) >> 1;
                if (0 < iVar16) {
                  puVar6 = puVar18 + iVar8 + -1;
                  puVar10 = puVar18;
                  do {
                    uVar11 = *puVar10;
                    puVar13 = puVar10 + 1;
                    *puVar10 = *puVar6;
                    *puVar6 = uVar11;
                    puVar6 = puVar6 + -1;
                    puVar10 = puVar13;
                  } while (puVar13 != puVar18 + iVar16);
                }
                sVar3 = 0x14 - iVar8;
                local_4e8 = local_4e8 + iVar8;
                if (0 < (int)sVar3) {
                  memset(local_4e8,0,sVar3);
                  local_4e8 = local_4e8 + sVar3;
                }
                memset(local_4e8,0xff,0x18);
              }
              else {
                write_rsa(&local_4e8,param_2[5]);
              }
            }
          }
          else {
            local_4e4.digest = (EVP_MD *)0x0;
            if (iVar16 == 6) {
              uVar1 = check_bitlen_rsa(param_2[5],0,&local_4e4);
              uVar11 = 0xa4;
              local_4ec = 0xa400;
              goto LAB_000c6c7e;
            }
          }
          if (param_3 == (uchar *)0x0) goto LAB_000c6d50;
          if (param_4 == (code *)0x0) {
            sVar3 = PEM_def_callback(acStack_42c,0x400,1,param_5);
          }
          else {
            sVar3 = (*param_4)();
          }
          if ((int)sVar3 < 1) {
            ERR_put_error(9,0x89,0x68,"pvkfmt.c",0x389);
          }
          else {
            EVP_MD_CTX_init(&local_4e4);
            type = EVP_sha1();
            iVar16 = EVP_DigestInit_ex(&local_4e4,type,(ENGINE *)0x0);
            if ((((iVar16 == 0) || (iVar16 = EVP_DigestUpdate(&local_4e4,puVar9,0x10), iVar16 == 0))
                || (iVar16 = EVP_DigestUpdate(&local_4e4,acStack_42c,sVar3), iVar16 == 0)) ||
               (iVar16 = EVP_DigestFinal_ex(&local_4e4,auStack_4cc,(uint *)0x0), iVar16 == 0)) {
              EVP_MD_CTX_cleanup(&local_4e4);
            }
            else {
              EVP_MD_CTX_cleanup(&local_4e4);
              if (param_3 == (uchar *)0x1) {
                local_4c7 = 0;
                local_4c6 = 0;
                local_4c5 = 0;
                local_4c4 = 0;
                local_4c3 = 0;
                local_4c2 = 0;
                local_4c1 = 0;
                local_4c0 = 0;
                local_4bf = 0;
                local_4be = 0;
                local_4bd = 0;
              }
              cipher = EVP_rc4();
              puVar9 = puVar9 + 0x18;
              iVar16 = EVP_EncryptInit_ex(&EStack_4b8,cipher,(ENGINE *)0x0,auStack_4cc,(uchar *)0x0)
              ;
              if (iVar16 != 0) {
                OPENSSL_cleanse(auStack_4cc,0x14);
                iVar12 = EVP_DecryptUpdate(&EStack_4b8,puVar9,(int *)&local_4e4,puVar9,iVar12 + 8);
                if ((iVar12 != 0) &&
                   (iVar12 = EVP_DecryptFinal_ex(&EStack_4b8,
                                                 puVar9 + (int)((local_4e4.digest)->
                                                                required_pkey_type + -0xb),
                                                 (int *)&local_4e4), iVar12 != 0)) {
                  EVP_CIPHER_CTX_cleanup(&EStack_4b8);
                  goto LAB_000c6d50;
                }
              }
            }
          }
        }
        EVP_CIPHER_CTX_cleanup(&EStack_4b8);
        iVar17 = -1;
        goto LAB_000c6d50;
      }
    }
  }
  else if (*param_2 == 6) {
    uVar1 = check_bitlen_rsa(param_2[5],0,&local_4e4);
    iVar12 = 0xa400;
    goto LAB_000c6ba2;
  }
  iVar17 = -1;
LAB_000c6d50:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar17);
  }
  return;
}

