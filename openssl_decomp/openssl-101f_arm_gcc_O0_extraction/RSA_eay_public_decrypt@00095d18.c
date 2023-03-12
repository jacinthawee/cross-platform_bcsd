
int RSA_eay_public_decrypt(int param_1,uchar *param_2,uchar *param_3,int param_4,int param_5)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *ret;
  BIGNUM *a;
  int iVar2;
  uchar *to;
  BIGNUM *pBVar3;
  BN_MONT_CTX *pBVar4;
  size_t len;
  
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if (0x4000 < iVar1) {
    ERR_put_error(4,0x67,0x69,"rsa_eay.c",0x284);
    return -1;
  }
  iVar1 = BN_ucmp(*(BIGNUM **)(param_4 + 0x10),*(BIGNUM **)(param_4 + 0x14));
  if (iVar1 < 1) {
    iVar1 = 0x28a;
LAB_00095e08:
    ERR_put_error(4,0x67,0x65,"rsa_eay.c",iVar1);
    return -1;
  }
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if ((0xc00 < iVar1) && (iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x14)), 0x40 < iVar1)) {
    iVar1 = 0x293;
    goto LAB_00095e08;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return -1;
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
  to = (uchar *)CRYPTO_malloc(len,"rsa_eay.c",0x29d);
  if ((a == (BIGNUM *)0x0 || ret == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    iVar1 = -1;
    ERR_put_error(4,0x67,0x41,"rsa_eay.c",0x2a0);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return -1;
    }
    goto LAB_00095e4e;
  }
  if ((int)len < param_1) {
    iVar1 = -1;
    ERR_put_error(4,0x67,0x6c,"rsa_eay.c",0x2a8);
  }
  else {
    pBVar3 = BN_bin2bn(param_2,param_1,ret);
    if (pBVar3 == (BIGNUM *)0x0) {
LAB_00095eb4:
      iVar1 = -1;
    }
    else {
      iVar1 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
      if (iVar1 < 0) {
        if (((*(int *)(param_4 + 0x3c) << 0x1e < 0) &&
            (pBVar4 = BN_MONT_CTX_set_locked
                                ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),ctx
                                ), pBVar4 == (BN_MONT_CTX *)0x0)) ||
           (iVar1 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                              (a,ret,*(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x10)
                               ,ctx,*(undefined4 *)(param_4 + 0x40)), iVar1 == 0))
        goto LAB_00095eb4;
        if (param_5 == 5) {
          if (((*a->d & 0xf) != 0xc) &&
             (iVar1 = BN_sub(a,*(BIGNUM **)(param_4 + 0x10),a), iVar1 == 0)) goto LAB_00095eb4;
          iVar1 = BN_bn2bin(a,to);
          iVar1 = RSA_padding_check_X931(param_3,len,to,iVar1,len);
        }
        else {
          iVar1 = BN_bn2bin(a,to);
          if (param_5 == 1) {
            iVar1 = RSA_padding_check_PKCS1_type_1(param_3,len,to,iVar1,len);
          }
          else {
            if (param_5 != 3) {
              iVar1 = -1;
              ERR_put_error(4,0x67,0x76,"rsa_eay.c",0x2cd);
              goto LAB_00095de8;
            }
            iVar1 = RSA_padding_check_none(param_3,len,to,iVar1,len);
          }
        }
        if (iVar1 < 0) {
          ERR_put_error(4,0x67,0x72,"rsa_eay.c",0x2d1);
        }
      }
      else {
        iVar1 = -1;
        ERR_put_error(4,0x67,0x84,"rsa_eay.c",0x2b0);
      }
    }
  }
LAB_00095de8:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_00095e4e:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return iVar1;
}

