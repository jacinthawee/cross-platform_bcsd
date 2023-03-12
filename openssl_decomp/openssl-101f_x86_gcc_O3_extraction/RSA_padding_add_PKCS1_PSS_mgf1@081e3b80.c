
int RSA_padding_add_PKCS1_PSS_mgf1
              (RSA *rsa,uchar *EM,uchar *mHash,EVP_MD *Hash,EVP_MD *mgf1Hash,int sLen)

{
  size_t cnt;
  int iVar1;
  byte *buf;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  int in_GS_OFFSET;
  byte *local_58;
  uint local_54;
  EVP_MD_CTX *local_50;
  byte *local_48;
  int local_44;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_58 = EM;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (mgf1Hash == (EVP_MD *)0x0) {
    mgf1Hash = Hash;
  }
  cnt = EVP_MD_size(Hash);
  if (-1 < (int)cnt) {
    if (sLen != -1) {
      if (sLen == -2) {
        iVar1 = BN_num_bits(rsa->n);
        local_54 = iVar1 - 1U & 7;
        iVar1 = RSA_size(rsa);
        if (local_54 == 0) goto LAB_081e3d22;
LAB_081e3d44:
        sLen = (iVar1 - cnt) + -2;
        local_58 = EM;
        if (sLen < 1) goto LAB_081e3d5f;
LAB_081e3c2d:
        buf = (byte *)CRYPTO_malloc(sLen,"rsa_pss.c",0xf2);
        if (buf == (byte *)0x0) {
          ERR_put_error(4,0x94,0x41,"rsa_pss.c",0xf5);
          goto LAB_081e3cd1;
        }
        iVar2 = RAND_bytes(buf,sLen);
        if (0 < iVar2) {
          EVP_MD_CTX_init(&local_38);
          iVar2 = EVP_DigestInit_ex(&local_38,Hash,(ENGINE *)0x0);
          if (iVar2 == 0) goto LAB_081e3ca0;
          iVar5 = 0;
          iVar2 = EVP_DigestUpdate(&local_38,&zeroes,8);
          if (iVar2 == 0) goto LAB_081e3ca2;
          local_44 = (iVar1 - cnt) + -1;
          local_48 = local_58 + local_44;
          iVar2 = EVP_DigestUpdate(&local_38,mHash,cnt);
          if (iVar2 == 0) goto LAB_081e3ca2;
          goto LAB_081e3de5;
        }
LAB_081e3ca0:
        iVar5 = 0;
      }
      else {
        if (sLen < -2) {
          ERR_put_error(4,0x94,0x88,"rsa_pss.c",0xdc);
          goto LAB_081e3cd1;
        }
        iVar1 = BN_num_bits(rsa->n);
        local_54 = iVar1 - 1U & 7;
        iVar1 = RSA_size(rsa);
        if (local_54 != 0) goto LAB_081e3c11;
LAB_081e3d22:
        iVar1 = iVar1 + -1;
        *EM = '\0';
        EM = EM + 1;
        if (sLen == -2) {
          local_54 = 0;
          goto LAB_081e3d44;
        }
        local_54 = 0;
        local_58 = EM;
        if (iVar1 <= (int)(cnt + 1 + sLen)) goto LAB_081e3e9c;
LAB_081e3c21:
        if (0 < sLen) goto LAB_081e3c2d;
LAB_081e3d5f:
        local_44 = (iVar1 - cnt) + -1;
        local_48 = local_58 + local_44;
        EVP_MD_CTX_init(&local_38);
        iVar2 = EVP_DigestInit_ex(&local_38,Hash,(ENGINE *)0x0);
        if ((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&local_38,&zeroes,8), iVar2 == 0))
        goto LAB_081e3cd1;
        iVar5 = 0;
        iVar2 = EVP_DigestUpdate(&local_38,mHash,cnt);
        if (iVar2 == 0) goto LAB_081e3cd3;
        buf = (byte *)0x0;
        if (sLen == 0) {
LAB_081e3e05:
          local_50 = &local_38;
          iVar2 = EVP_DigestFinal_ex(local_50,local_48,(uint *)0x0);
          if (iVar2 == 0) goto LAB_081e3e2a;
          EVP_MD_CTX_cleanup(local_50);
          iVar2 = PKCS1_MGF1(local_58,local_44,local_48,cnt,mgf1Hash);
          if (iVar2 != 0) goto LAB_081e3e2a;
          iVar2 = (iVar1 - sLen) - cnt;
          local_58[iVar2 + -2] = local_58[iVar2 + -2] ^ 1;
          pbVar4 = local_58 + iVar2 + -1;
          if (0 < sLen) {
            if ((pbVar4 < buf + 4 && buf < local_58 + iVar2 + 3 || (uint)sLen < 7) ||
               ((((uint)buf | (uint)pbVar4) & 3) != 0)) {
              iVar2 = 0;
              do {
                pbVar4[iVar2] = pbVar4[iVar2] ^ buf[iVar2];
                iVar2 = iVar2 + 1;
              } while (sLen != iVar2);
            }
            else {
              uVar3 = 0;
              uVar6 = (sLen - 4U >> 2) + 1;
              iVar2 = uVar6 * 4;
              do {
                *(uint *)(pbVar4 + uVar3 * 4) =
                     *(uint *)(pbVar4 + uVar3 * 4) ^ *(uint *)(buf + uVar3 * 4);
                uVar3 = uVar3 + 1;
              } while (uVar3 < uVar6);
              pbVar4 = pbVar4 + iVar2;
              if (((sLen != iVar2) && (*pbVar4 = *pbVar4 ^ buf[uVar6 * 4], iVar2 + 1 < sLen)) &&
                 (pbVar4[1] = pbVar4[1] ^ buf[iVar2 + 1], iVar2 + 2 < sLen)) {
                pbVar4[2] = pbVar4[2] ^ buf[iVar2 + 2];
              }
            }
          }
          if (local_54 != 0) {
            *local_58 = *local_58 & (byte)(0xff >> (8U - (char)local_54 & 0x1f));
          }
          local_58[iVar1 + -1] = 0xbc;
          iVar5 = 1;
        }
        else {
LAB_081e3de5:
          local_50 = &local_38;
          iVar2 = EVP_DigestUpdate(local_50,buf,sLen);
          if (iVar2 != 0) goto LAB_081e3e05;
LAB_081e3e2a:
          iVar5 = 0;
        }
        if (buf == (byte *)0x0) goto LAB_081e3cd3;
      }
LAB_081e3ca2:
      CRYPTO_free(buf);
      goto LAB_081e3cd3;
    }
    iVar1 = BN_num_bits(rsa->n);
    local_54 = iVar1 - 1U & 7;
    iVar1 = RSA_size(rsa);
    sLen = cnt;
    if (local_54 == 0) goto LAB_081e3d22;
LAB_081e3c11:
    if ((int)(cnt + 1 + sLen) < iVar1) goto LAB_081e3c21;
LAB_081e3e9c:
    ERR_put_error(4,0x94,0x6e,"rsa_pss.c",0xed);
  }
LAB_081e3cd1:
  iVar5 = 0;
LAB_081e3cd3:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}

