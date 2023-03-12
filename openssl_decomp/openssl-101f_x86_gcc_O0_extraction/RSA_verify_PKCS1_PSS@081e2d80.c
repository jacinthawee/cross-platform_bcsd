
int RSA_verify_PKCS1_PSS(RSA *rsa,uchar *mHash,EVP_MD *Hash,uchar *EM,int sLen)

{
  uint uVar1;
  size_t sVar2;
  size_t cnt;
  int iVar3;
  uint num;
  byte *mask;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  int iVar9;
  int in_GS_OFFSET;
  sbyte local_98;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_78);
  cnt = EVP_MD_size(Hash);
  if (-1 < (int)cnt) {
    sVar2 = cnt;
    if (((sLen == -1) || (sVar2 = sLen, sLen == -2)) || (-3 < sLen)) {
      sLen = sVar2;
      iVar3 = BN_num_bits(rsa->n);
      uVar7 = iVar3 - 1U & 7;
      iVar3 = RSA_size(rsa);
      local_98 = (sbyte)uVar7;
      if (((uint)*EM & 0xff << local_98) == 0) {
        if (uVar7 == 0) {
          EM = EM + 1;
          iVar3 = iVar3 + -1;
        }
        if ((int)(cnt + 1 + sLen) < iVar3) {
          if (EM[iVar3 + -1] == 0xbc) {
            iVar3 = iVar3 - cnt;
            num = iVar3 - 1;
            mask = (byte *)CRYPTO_malloc(num,"rsa_pss.c",0x88);
            if (mask != (byte *)0x0) {
              iVar4 = PKCS1_MGF1(mask,num,EM + num,cnt,Hash);
              if (iVar4 < 0) goto LAB_081e30d0;
              if (0 < (int)num) {
                if ((EM < mask + 4 && mask < EM + 4 || num < 7) ||
                   ((((uint)EM | (uint)mask) & 3) != 0)) {
                  uVar6 = 0;
                  do {
                    mask[uVar6] = mask[uVar6] ^ EM[uVar6];
                    uVar6 = uVar6 + 1;
                  } while (uVar6 != num);
                }
                else {
                  uVar6 = (iVar3 - 5U >> 2) + 1;
                  uVar5 = 0;
                  uVar1 = uVar6 * 4;
                  do {
                    *(uint *)(mask + uVar5 * 4) =
                         *(uint *)(mask + uVar5 * 4) ^ *(uint *)(EM + uVar5 * 4);
                    uVar5 = uVar5 + 1;
                  } while (uVar5 < uVar6);
                  if (num != uVar1) {
                    mask[uVar1] = mask[uVar1] ^ EM[uVar6 * 4];
                    if ((int)(uVar1 + 1) < (int)num) {
                      mask[uVar1 + 1] = mask[uVar1 + 1] ^ EM[uVar1 + 1];
                      if ((int)(uVar1 + 2) < (int)num) {
                        mask[uVar1 + 2] = mask[uVar1 + 2] ^ EM[uVar1 + 2];
                      }
                    }
                  }
                }
              }
              if (uVar7 == 0) {
                bVar8 = *mask;
              }
              else {
                bVar8 = (byte)(0xff >> (8U - local_98 & 0x1f)) & *mask;
                *mask = bVar8;
              }
              if (bVar8 == 0) {
                if (2 < iVar3) {
                  iVar4 = 0;
                  do {
                    bVar8 = mask[iVar4 + 1];
                    iVar9 = iVar4 + 1;
                    if (bVar8 != 0) {
                      uVar7 = iVar4 + 2;
                      goto LAB_081e3059;
                    }
                    iVar4 = iVar9;
                  } while (iVar9 != iVar3 + -2);
                }
LAB_081e30d8:
                iVar4 = 0x97;
                iVar3 = 0x87;
LAB_081e308e:
                iVar9 = 0;
                ERR_put_error(4,0x95,iVar3,"rsa_pss.c",iVar4);
              }
              else {
                uVar7 = 1;
LAB_081e3059:
                if (bVar8 != 1) goto LAB_081e30d8;
                if ((-1 < sLen) && (sLen != num - uVar7)) {
                  iVar4 = 0x9c;
                  iVar3 = 0x88;
                  goto LAB_081e308e;
                }
                iVar3 = EVP_DigestInit_ex(&local_78,Hash,(ENGINE *)0x0);
                if ((((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&local_78,&zeroes,8), iVar3 == 0))
                    || (iVar3 = EVP_DigestUpdate(&local_78,mHash,cnt), iVar3 == 0)) ||
                   ((num != uVar7 &&
                    (iVar3 = EVP_DigestUpdate(&local_78,mask + uVar7,num - uVar7), iVar3 == 0)))) {
LAB_081e30d0:
                  iVar9 = 0;
                }
                else {
                  iVar3 = EVP_DigestFinal_ex(&local_78,local_60,(uint *)0x0);
                  if (iVar3 == 0) goto LAB_081e30d0;
                  iVar9 = 1;
                  iVar3 = memcmp(local_60,EM + num,cnt);
                  if (iVar3 != 0) {
                    iVar4 = 0xac;
                    iVar3 = 0x68;
                    goto LAB_081e308e;
                  }
                }
              }
              CRYPTO_free(mask);
              goto LAB_081e2e82;
            }
            ERR_put_error(4,0x95,0x41,"rsa_pss.c",0x8b);
          }
          else {
            ERR_put_error(4,0x95,0x86,"rsa_pss.c",0x83);
          }
        }
        else {
          ERR_put_error(4,0x95,0x6d,"rsa_pss.c",0x7e);
        }
      }
      else {
        ERR_put_error(4,0x95,0x85,"rsa_pss.c",0x74);
      }
    }
    else {
      ERR_put_error(4,0x95,0x88,"rsa_pss.c",0x6c);
    }
  }
  iVar9 = 0;
LAB_081e2e82:
  EVP_MD_CTX_cleanup(&local_78);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
}

