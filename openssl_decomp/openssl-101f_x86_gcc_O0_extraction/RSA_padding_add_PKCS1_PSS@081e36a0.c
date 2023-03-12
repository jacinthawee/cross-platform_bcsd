
int RSA_padding_add_PKCS1_PSS(RSA *rsa,uchar *EM,uchar *mHash,EVP_MD *Hash,int sLen)

{
  size_t cnt;
  int iVar1;
  byte *buf;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  int in_GS_OFFSET;
  byte *local_5c;
  int local_58;
  uint local_54;
  EVP_MD_CTX *local_4c;
  byte *local_44;
  int local_40;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_5c = EM;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  cnt = EVP_MD_size(Hash);
  if (-1 < (int)cnt) {
    if (sLen != -1) {
      if (sLen == -2) {
        iVar1 = BN_num_bits(rsa->n);
        local_54 = iVar1 - 1U & 7;
        local_58 = RSA_size(rsa);
        if (local_54 == 0) goto LAB_081e383a;
LAB_081e385b:
        sLen = (local_58 - cnt) - 2;
        local_5c = EM;
        if (sLen < 1) goto LAB_081e386f;
LAB_081e3740:
        buf = (byte *)CRYPTO_malloc(sLen,"rsa_pss.c",0xf2);
        if (buf == (byte *)0x0) {
          ERR_put_error(4,0x94,0x41,"rsa_pss.c",0xf5);
          goto LAB_081e37e8;
        }
        iVar1 = RAND_bytes(buf,sLen);
        if (0 < iVar1) {
          EVP_MD_CTX_init(&local_38);
          iVar1 = 0;
          iVar2 = EVP_DigestInit_ex(&local_38,Hash,(ENGINE *)0x0);
          if ((iVar2 == 0) || (iVar2 = EVP_DigestUpdate(&local_38,&zeroes,8), iVar2 == 0))
          goto LAB_081e37af;
          local_40 = (local_58 - cnt) + -1;
          local_44 = local_5c + local_40;
          iVar2 = EVP_DigestUpdate(&local_38,mHash,cnt);
          if (iVar2 == 0) goto LAB_081e37af;
          goto LAB_081e3a00;
        }
        iVar1 = 0;
      }
      else {
        if (sLen < -2) {
          ERR_put_error(4,0x94,0x88,"rsa_pss.c",0xdc);
          goto LAB_081e37e8;
        }
        iVar1 = BN_num_bits(rsa->n);
        local_54 = iVar1 - 1U & 7;
        local_58 = RSA_size(rsa);
        if (local_54 != 0) goto LAB_081e372a;
LAB_081e383a:
        local_58 = local_58 + -1;
        *EM = '\0';
        EM = EM + 1;
        if (sLen == 0xfffffffe) {
          local_54 = 0;
          goto LAB_081e385b;
        }
        local_54 = 0;
        local_5c = EM;
        if (local_58 <= (int)(cnt + 1 + sLen)) goto LAB_081e3979;
LAB_081e3738:
        if (0 < sLen) goto LAB_081e3740;
LAB_081e386f:
        EVP_MD_CTX_init(&local_38);
        iVar1 = EVP_DigestInit_ex(&local_38,Hash,(ENGINE *)0x0);
        if ((iVar1 == 0) || (iVar1 = EVP_DigestUpdate(&local_38,&zeroes,8), iVar1 == 0))
        goto LAB_081e37e8;
        iVar1 = 0;
        local_40 = (local_58 - cnt) + -1;
        local_44 = local_5c + local_40;
        iVar2 = EVP_DigestUpdate(&local_38,mHash,cnt);
        if (iVar2 == 0) goto LAB_081e37ea;
        buf = (byte *)0x0;
        if (sLen == 0) {
LAB_081e38f1:
          local_4c = &local_38;
          iVar1 = EVP_DigestFinal_ex(local_4c,local_44,(uint *)0x0);
          if (iVar1 == 0) goto LAB_081e3916;
          EVP_MD_CTX_cleanup(local_4c);
          iVar1 = PKCS1_MGF1(local_5c,local_40,local_44,cnt,Hash);
          if (iVar1 != 0) goto LAB_081e3916;
          iVar1 = (local_58 - sLen) - cnt;
          local_5c[iVar1 + -2] = local_5c[iVar1 + -2] ^ 1;
          pbVar5 = local_5c + iVar1 + -1;
          if (0 < sLen) {
            if ((pbVar5 < buf + 4 && buf < local_5c + iVar1 + 3 || (uint)sLen < 7) ||
               ((((uint)buf | (uint)pbVar5) & 3) != 0)) {
              uVar4 = 0;
              do {
                pbVar5[uVar4] = pbVar5[uVar4] ^ buf[uVar4];
                uVar4 = uVar4 + 1;
              } while (sLen != uVar4);
            }
            else {
              uVar3 = 0;
              uVar6 = (sLen - 4U >> 2) + 1;
              uVar4 = uVar6 * 4;
              do {
                *(uint *)(pbVar5 + uVar3 * 4) =
                     *(uint *)(pbVar5 + uVar3 * 4) ^ *(uint *)(buf + uVar3 * 4);
                uVar3 = uVar3 + 1;
              } while (uVar3 < uVar6);
              pbVar5 = pbVar5 + uVar4;
              if (((sLen != uVar4) && (*pbVar5 = *pbVar5 ^ buf[uVar6 * 4], (int)(uVar4 + 1) < sLen))
                 && (pbVar5[1] = pbVar5[1] ^ buf[uVar4 + 1], (int)(uVar4 + 2) < sLen)) {
                pbVar5[2] = pbVar5[2] ^ buf[uVar4 + 2];
              }
            }
          }
          if (local_54 != 0) {
            *local_5c = *local_5c & (byte)(0xff >> (8U - (char)local_54 & 0x1f));
          }
          iVar1 = 1;
          local_5c[local_58 + -1] = 0xbc;
        }
        else {
LAB_081e3a00:
          local_4c = &local_38;
          iVar1 = EVP_DigestUpdate(local_4c,buf,sLen);
          if (iVar1 != 0) goto LAB_081e38f1;
LAB_081e3916:
          iVar1 = 0;
        }
        if (buf == (byte *)0x0) goto LAB_081e37ea;
      }
LAB_081e37af:
      CRYPTO_free(buf);
      goto LAB_081e37ea;
    }
    iVar1 = BN_num_bits(rsa->n);
    local_54 = iVar1 - 1U & 7;
    local_58 = RSA_size(rsa);
    sLen = cnt;
    if (local_54 == 0) goto LAB_081e383a;
LAB_081e372a:
    if ((int)(cnt + 1 + sLen) < local_58) goto LAB_081e3738;
LAB_081e3979:
    ERR_put_error(4,0x94,0x6e,"rsa_pss.c",0xed);
  }
LAB_081e37e8:
  iVar1 = 0;
LAB_081e37ea:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

