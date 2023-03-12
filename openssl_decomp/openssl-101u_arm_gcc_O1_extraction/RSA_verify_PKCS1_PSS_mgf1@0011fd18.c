
int RSA_verify_PKCS1_PSS_mgf1
              (RSA *rsa,uchar *mHash,EVP_MD *Hash,EVP_MD *mgf1Hash,uchar *EM,int sLen)

{
  size_t cnt;
  int iVar1;
  int iVar2;
  uint *mask;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  size_t sVar7;
  uint uVar8;
  uint num;
  uint uVar9;
  EVP_MD_CTX EStack_84;
  uchar auStack_6c [64];
  int local_2c;
  
  if (mgf1Hash == (EVP_MD *)0x0) {
    mgf1Hash = Hash;
  }
  local_2c = __stack_chk_guard;
  EVP_MD_CTX_init(&EStack_84);
  cnt = EVP_MD_size(Hash);
  if (-1 < (int)cnt) {
    sVar7 = cnt;
    if (sLen != -1) {
      sVar7 = sLen;
      if ((sLen != -2) && (sLen + 2 < 0 != SCARRY4(sLen,2))) {
        ERR_put_error(4,0x95,0x88,"rsa_pss.c",0x6f);
        goto LAB_0011fdae;
      }
    }
    iVar1 = BN_num_bits(rsa->n);
    iVar2 = RSA_size(rsa);
    uVar8 = iVar1 - 1U & 7;
    if ((0xff << uVar8 & (uint)*EM) == 0) {
      if (uVar8 == 0) {
        EM = EM + 1;
        iVar2 = iVar2 + -1;
      }
      if ((int)(cnt + sVar7 + 1) < iVar2) {
        if (*(byte *)((int)EM + iVar2 + -1) == 0xbc) {
          iVar2 = iVar2 - cnt;
          num = iVar2 - 1;
          mask = (uint *)CRYPTO_malloc(num,"rsa_pss.c",0x87);
          if (mask != (uint *)0x0) {
            iVar1 = PKCS1_MGF1((uchar *)mask,num,(byte *)((int)EM + num),cnt,mgf1Hash);
            if (iVar1 < 0) {
LAB_0011ff8c:
              iVar1 = 0;
            }
            else {
              if (0 < (int)num) {
                uVar5 = (uint)((uint *)((int)EM + 4) <= mask || mask + 1 <= EM);
                if (num < 7) {
                  uVar5 = 0;
                }
                if ((((uint)mask | (uint)EM) & 3) != 0) {
                  uVar5 = 0;
                }
                if (uVar5 == 0) {
                  do {
                    *(byte *)((int)mask + uVar5) =
                         *(byte *)((int)EM + uVar5) ^ *(byte *)((int)mask + uVar5);
                    uVar5 = uVar5 + 1;
                  } while (uVar5 != num);
                }
                else {
                  puVar4 = (uint *)((int)EM + -4);
                  uVar9 = num & 0xfffffffc;
                  uVar5 = 0;
                  puVar3 = mask;
                  do {
                    uVar5 = uVar5 + 1;
                    puVar4 = puVar4 + 1;
                    *puVar3 = *puVar4 ^ *puVar3;
                    puVar3 = puVar3 + 1;
                  } while (uVar5 < num >> 2);
                  if (num != uVar9) {
                    iVar1 = uVar9 + 1;
                    *(byte *)((int)mask + (num & 0xfffffffc)) =
                         *(byte *)((int)mask + (num & 0xfffffffc)) ^
                         *(byte *)((int)EM + (num & 0xfffffffc));
                    if (iVar1 < (int)num) {
                      iVar6 = uVar9 + 2;
                      *(byte *)((int)mask + iVar1) =
                           *(byte *)((int)mask + iVar1) ^ *(byte *)((int)EM + iVar1);
                      if (iVar6 < (int)num) {
                        *(byte *)((int)mask + iVar6) =
                             *(byte *)((int)mask + iVar6) ^ *(byte *)((int)EM + iVar6);
                      }
                    }
                  }
                }
              }
              if (uVar8 == 0) {
                uVar8 = (uint)*(byte *)mask;
              }
              else {
                uVar8 = (uint)*(byte *)mask & 0xff >> (8 - uVar8 & 0xff);
                *(byte *)mask = (byte)uVar8;
              }
              if (uVar8 == 0) {
                if (2 < iVar2) {
                  puVar4 = mask;
                  uVar5 = uVar8;
                  do {
                    puVar4 = (uint *)((int)puVar4 + 1);
                    uVar8 = (uint)*(byte *)puVar4;
                    uVar9 = uVar5 + 1;
                    if (uVar8 != 0) {
                      uVar5 = uVar5 + 2;
                      goto LAB_0011ff42;
                    }
                    uVar5 = uVar9;
                  } while (uVar9 != iVar2 - 2U);
                }
              }
              else {
                uVar5 = 1;
LAB_0011ff42:
                if (uVar8 == 1) {
                  if (((int)sVar7 < 0) || (num - uVar5 == sVar7)) {
                    iVar1 = EVP_DigestInit_ex(&EStack_84,Hash,(ENGINE *)0x0);
                    if ((((iVar1 == 0) ||
                         ((iVar1 = EVP_DigestUpdate(&EStack_84,&zeroes,8), iVar1 == 0 ||
                          (iVar1 = EVP_DigestUpdate(&EStack_84,mHash,cnt), iVar1 == 0)))) ||
                        ((num != uVar5 &&
                         (iVar1 = EVP_DigestUpdate(&EStack_84,(byte *)((int)mask + uVar5),
                                                   num - uVar5), iVar1 == 0)))) ||
                       (iVar1 = EVP_DigestFinal_ex(&EStack_84,auStack_6c,(uint *)0x0), iVar1 == 0))
                    goto LAB_0011ff8c;
                    iVar1 = memcmp(auStack_6c,(byte *)((int)EM + num),cnt);
                    if (iVar1 == 0) {
                      iVar1 = 1;
                    }
                    else {
                      iVar1 = 0;
                      ERR_put_error(4,0x95,0x68,"rsa_pss.c",0xa6);
                    }
                  }
                  else {
                    iVar1 = 0;
                    ERR_put_error(4,0x95,0x88,"rsa_pss.c",0x98);
                  }
                  goto LAB_0011ff6a;
                }
              }
              iVar1 = 0;
              ERR_put_error(4,0x95,0x87,"rsa_pss.c",0x94);
            }
LAB_0011ff6a:
            CRYPTO_free(mask);
            goto LAB_0011fdb0;
          }
          ERR_put_error(4,0x95,0x41,"rsa_pss.c",0x89);
        }
        else {
          ERR_put_error(4,0x95,0x86,"rsa_pss.c",0x82);
        }
      }
      else {
        ERR_put_error(4,0x95,0x6d,"rsa_pss.c",0x7e);
      }
    }
    else {
      ERR_put_error(4,0x95,0x85,"rsa_pss.c",0x76);
    }
  }
LAB_0011fdae:
  iVar1 = 0;
LAB_0011fdb0:
  EVP_MD_CTX_cleanup(&EStack_84);
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

