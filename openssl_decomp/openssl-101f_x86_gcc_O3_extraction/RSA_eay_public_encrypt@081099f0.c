
size_t RSA_eay_public_encrypt(int param_1,uchar *param_2,void *param_3,int param_4,int param_5)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *a;
  int iVar2;
  uchar *to;
  BIGNUM *pBVar3;
  BN_MONT_CTX *pBVar4;
  size_t sVar5;
  size_t len;
  
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (0x4000 < iVar1) {
    iVar2 = 0xa3;
    iVar1 = 0x69;
    goto LAB_08109bf6;
  }
  iVar1 = BN_ucmp(*(BIGNUM **)(param_4 + 0x10),*(BIGNUM **)(param_4 + 0x14));
  if (iVar1 < 1) {
    iVar2 = 0xa9;
  }
  else {
    iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
    if ((iVar1 < 0xc01) || (iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x14)), iVar1 < 0x41)) {
      ctx = BN_CTX_new();
      if (ctx == (BN_CTX *)0x0) {
        return 0xffffffff;
      }
      BN_CTX_start(ctx);
      ret = BN_CTX_get(ctx);
      a = BN_CTX_get(ctx);
      iVar2 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
      iVar1 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar1 = iVar2 + 7;
      }
      len = iVar1 >> 3;
      to = (uchar *)CRYPTO_malloc(len,"rsa_eay.c",0xbc);
      if ((ret == (BIGNUM *)0x0 || a == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
        ERR_put_error(4,0x68,0x41,"rsa_eay.c",0xbf);
        BN_CTX_end(ctx);
        BN_CTX_free(ctx);
        if (to == (uchar *)0x0) {
          return 0xffffffff;
        }
        sVar5 = 0xffffffff;
        goto LAB_08109bad;
      }
      if (param_5 == 2) {
        iVar1 = RSA_padding_add_SSLv23(to,len,param_2,param_1);
LAB_08109b07:
        if ((iVar1 < 1) || (pBVar3 = BN_bin2bn(to,len,ret), pBVar3 == (BIGNUM *)0x0))
        goto LAB_08109b58;
        iVar1 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
        if (-1 < iVar1) {
          iVar2 = 0xde;
          iVar1 = 0x84;
          goto LAB_08109b4c;
        }
        if ((((*(byte *)(param_4 + 0x3c) & 2) != 0) &&
            (pBVar4 = BN_MONT_CTX_set_locked
                                ((BN_MONT_CTX **)(param_4 + 0x40),
                                 (int)(BN_MONT_CTX **)(param_4 + 0x40),(BIGNUM *)0x9,
                                 *(BN_CTX **)(param_4 + 0x10)), pBVar4 == (BN_MONT_CTX *)0x0)) ||
           (iVar1 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                              (a,ret,*(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x10)
                               ,ctx,*(undefined4 *)(param_4 + 0x40)), iVar1 == 0))
        goto LAB_08109b58;
        iVar2 = BN_num_bits(a);
        iVar1 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar1 = iVar2 + 0xe;
        }
        iVar1 = BN_bn2bin(a,(uchar *)((int)param_3 + (len - (iVar1 >> 3))));
        sVar5 = len;
        if (0 < (int)(len - iVar1)) {
          memset(param_3,0,len - iVar1);
        }
      }
      else {
        if (2 < param_5) {
          if (param_5 == 3) {
            iVar1 = RSA_padding_add_none(to,len,param_2,param_1);
          }
          else {
            if (param_5 != 4) goto LAB_08109c50;
            iVar1 = RSA_padding_add_PKCS1_OAEP(to,len,param_2,param_1,(uchar *)0x0,0);
          }
          goto LAB_08109b07;
        }
        if (param_5 == 1) {
          iVar1 = RSA_padding_add_PKCS1_type_2(to,len,param_2,param_1);
          goto LAB_08109b07;
        }
LAB_08109c50:
        iVar2 = 0xd4;
        iVar1 = 0x76;
LAB_08109b4c:
        ERR_put_error(4,0x68,iVar1,"rsa_eay.c",iVar2);
LAB_08109b58:
        sVar5 = 0xffffffff;
      }
      BN_CTX_end(ctx);
      BN_CTX_free(ctx);
LAB_08109bad:
      OPENSSL_cleanse(to,len);
      CRYPTO_free(to);
      return sVar5;
    }
    iVar2 = 0xb2;
  }
  iVar1 = 0x65;
LAB_08109bf6:
  ERR_put_error(4,0x68,iVar1,"rsa_eay.c",iVar2);
  return 0xffffffff;
}

