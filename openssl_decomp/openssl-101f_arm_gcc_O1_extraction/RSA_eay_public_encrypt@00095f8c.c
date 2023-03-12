
size_t RSA_eay_public_encrypt
                 (int param_1,uchar *param_2,void *param_3,int param_4,undefined4 param_5)

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
    ERR_put_error(4,0x68,0x69,"rsa_eay.c",0xa3);
    return 0xffffffff;
  }
  iVar1 = BN_ucmp(*(BIGNUM **)(param_4 + 0x10),*(BIGNUM **)(param_4 + 0x14));
  if (iVar1 < 1) {
    iVar1 = 0xa9;
LAB_0009603a:
    ERR_put_error(4,0x68,0x65,"rsa_eay.c",iVar1);
    return 0xffffffff;
  }
  iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x10));
  if ((0xc00 < iVar1) && (iVar1 = BN_num_bits(*(BIGNUM **)(param_4 + 0x14)), 0x40 < iVar1)) {
    iVar1 = 0xb2;
    goto LAB_0009603a;
  }
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
  if ((a == (BIGNUM *)0x0 || ret == (BIGNUM *)0x0) || (to == (uchar *)0x0)) {
    sVar5 = 0xffffffff;
    ERR_put_error(4,0x68,0x41,"rsa_eay.c",0xbf);
    BN_CTX_end(ctx);
    BN_CTX_free(ctx);
    if (to == (uchar *)0x0) {
      return 0xffffffff;
    }
    goto LAB_0009607e;
  }
  switch(param_5) {
  case 1:
    iVar1 = RSA_padding_add_PKCS1_type_2(to,len,param_2,param_1);
    break;
  case 2:
    iVar1 = RSA_padding_add_SSLv23(to,len,param_2,param_1);
    break;
  case 3:
    iVar1 = RSA_padding_add_none(to,len,param_2,param_1);
    break;
  case 4:
    iVar1 = RSA_padding_add_PKCS1_OAEP(to,len,param_2,param_1,(uchar *)0x0,0);
    break;
  default:
    ERR_put_error(4,0x68,0x76,"rsa_eay.c",0xd4);
    sVar5 = 0xffffffff;
    goto LAB_000960e2;
  }
  if ((iVar1 < 1) || (pBVar3 = BN_bin2bn(to,len,ret), pBVar3 == (BIGNUM *)0x0)) {
LAB_00096144:
    sVar5 = 0xffffffff;
  }
  else {
    iVar1 = BN_ucmp(ret,*(BIGNUM **)(param_4 + 0x10));
    if (iVar1 < 0) {
      if (((*(int *)(param_4 + 0x3c) << 0x1e < 0) &&
          (pBVar4 = BN_MONT_CTX_set_locked
                              ((BN_MONT_CTX **)(param_4 + 0x40),9,*(BIGNUM **)(param_4 + 0x10),ctx),
          pBVar4 == (BN_MONT_CTX *)0x0)) ||
         (iVar1 = (**(code **)(*(int *)(param_4 + 8) + 0x18))
                            (a,ret,*(undefined4 *)(param_4 + 0x14),*(undefined4 *)(param_4 + 0x10),
                             ctx,*(undefined4 *)(param_4 + 0x40)), iVar1 == 0)) goto LAB_00096144;
      iVar2 = BN_num_bits(a);
      iVar1 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar1 = iVar2 + 7;
      }
      iVar1 = BN_bn2bin(a,(uchar *)((len - (iVar1 >> 3)) + (int)param_3));
      sVar5 = len;
      if (0 < (int)(len - iVar1)) {
        memset(param_3,0,len - iVar1);
      }
    }
    else {
      ERR_put_error(4,0x68,0x84,"rsa_eay.c",0xde);
      sVar5 = 0xffffffff;
    }
  }
LAB_000960e2:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_0009607e:
  OPENSSL_cleanse(to,len);
  CRYPTO_free(to);
  return sVar5;
}

