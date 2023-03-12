
int RSA_verify_PKCS1_PSS_mgf1
              (RSA *rsa,uchar *mHash,EVP_MD *Hash,EVP_MD *mgf1Hash,uchar *EM,int sLen)

{
  size_t sVar1;
  size_t cnt;
  int iVar2;
  uint num;
  byte *mask;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int in_GS_OFFSET;
  EVP_MD_CTX local_78;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  EVP_MD_CTX_init(&local_78);
  if (mgf1Hash == (EVP_MD *)0x0) {
    mgf1Hash = Hash;
  }
  cnt = EVP_MD_size(Hash);
  if (-1 < (int)cnt) {
    sVar1 = cnt;
    if (((sLen == -1) || (sVar1 = sLen, sLen == -2)) || (-3 < sLen)) {
      sLen = sVar1;
      iVar2 = BN_num_bits(rsa->n);
      uVar7 = iVar2 - 1U & 7;
      iVar2 = RSA_size(rsa);
      if (((uint)*EM & 0xff << (sbyte)uVar7) == 0) {
        if (uVar7 == 0) {
          EM = EM + 1;
          iVar2 = iVar2 + -1;
        }
        if ((int)(cnt + 1 + sLen) < iVar2) {
          if (EM[iVar2 + -1] == 0xbc) {
            iVar2 = iVar2 - cnt;
            num = iVar2 - 1;
            mask = (byte *)CRYPTO_malloc(num,"rsa_pss.c",0x88);
            if (mask != (byte *)0x0) {
              iVar3 = PKCS1_MGF1(mask,num,EM + num,cnt,mgf1Hash);
              if (iVar3 < 0) goto LAB_081e3570;
              if (0 < (int)num) {
                if ((EM < mask + 4 && mask < EM + 4 || num < 7) ||
                   ((((uint)EM | (uint)mask) & 3) != 0)) {
                  uVar5 = 0;
                  do {
                    mask[uVar5] = mask[uVar5] ^ EM[uVar5];
                    uVar5 = uVar5 + 1;
                  } while (uVar5 != num);
                }
                else {
                  uVar4 = 0;
                  uVar9 = (iVar2 - 5U >> 2) + 1;
                  uVar5 = uVar9 * 4;
                  do {
                    *(uint *)(mask + uVar4 * 4) =
                         *(uint *)(mask + uVar4 * 4) ^ *(uint *)(EM + uVar4 * 4);
                    uVar4 = uVar4 + 1;
                  } while (uVar4 < uVar9);
                  if (num != uVar5) {
                    mask[uVar5] = mask[uVar5] ^ EM[uVar9 * 4];
                    if ((int)(uVar5 + 1) < (int)num) {
                      mask[uVar5 + 1] = mask[uVar5 + 1] ^ EM[uVar5 + 1];
                      if ((int)(uVar5 + 2) < (int)num) {
                        mask[uVar5 + 2] = mask[uVar5 + 2] ^ EM[uVar5 + 2];
                      }
                    }
                  }
                }
              }
              if (uVar7 == 0) {
                bVar6 = *mask;
              }
              else {
                bVar6 = (byte)(0xff >> (8U - (sbyte)uVar7 & 0x1f)) & *mask;
                *mask = bVar6;
              }
              if (bVar6 == 0) {
                if (2 < iVar2) {
                  iVar3 = 0;
                  do {
                    bVar6 = mask[iVar3 + 1];
                    iVar8 = iVar3 + 1;
                    if (bVar6 != 0) {
                      uVar7 = iVar3 + 2;
                      goto LAB_081e34f1;
                    }
                    iVar3 = iVar8;
                  } while (iVar8 != iVar2 + -2);
                }
LAB_081e3578:
                iVar3 = 0x97;
                iVar2 = 0x87;
LAB_081e352a:
                iVar8 = 0;
                ERR_put_error(4,0x95,iVar2,"rsa_pss.c",iVar3);
              }
              else {
                uVar7 = 1;
LAB_081e34f1:
                if (bVar6 != 1) goto LAB_081e3578;
                if ((-1 < sLen) && (sLen != num - uVar7)) {
                  iVar3 = 0x9c;
                  iVar2 = 0x88;
                  goto LAB_081e352a;
                }
                iVar2 = EVP_DigestInit_ex(&local_78,Hash,(ENGINE *)0x0);
                if ((((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&local_78,&zeroes,8), iVar2 == 0))
                    || (iVar2 = EVP_DigestUpdate(&local_78,mHash,cnt), iVar2 == 0)) ||
                   ((num != uVar7 &&
                    (iVar2 = EVP_DigestUpdate(&local_78,mask + uVar7,num - uVar7), iVar2 == 0)))) {
LAB_081e3570:
                  iVar8 = 0;
                }
                else {
                  iVar2 = EVP_DigestFinal_ex(&local_78,local_60,(uint *)0x0);
                  if (iVar2 == 0) goto LAB_081e3570;
                  iVar8 = 1;
                  iVar2 = memcmp(local_60,EM + num,cnt);
                  if (iVar2 != 0) {
                    iVar3 = 0xac;
                    iVar2 = 0x68;
                    goto LAB_081e352a;
                  }
                }
              }
              CRYPTO_free(mask);
              goto LAB_081e3312;
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
  iVar8 = 0;
LAB_081e3312:
  EVP_MD_CTX_cleanup(&local_78);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}

