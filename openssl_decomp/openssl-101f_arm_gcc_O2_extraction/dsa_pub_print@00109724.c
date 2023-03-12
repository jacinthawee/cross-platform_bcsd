
uchar * dsa_pub_print(BIO *param_1,int param_2,int param_3)

{
  BIGNUM *a;
  int iVar1;
  uchar *buf;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  BIGNUM *a_00;
  
  iVar3 = *(int *)(param_2 + 0x14);
  a = *(BIGNUM **)(iVar3 + 0xc);
  a_00 = *(BIGNUM **)(iVar3 + 0x18);
  if (a != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a);
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    a = (BIGNUM *)(iVar2 >> 3);
  }
  if (*(BIGNUM **)(iVar3 + 0x10) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar3 + 0x10));
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (a < (BIGNUM *)(iVar2 >> 3)) {
      a = (BIGNUM *)(iVar2 >> 3);
    }
  }
  if (*(BIGNUM **)(iVar3 + 0x14) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar3 + 0x14));
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (a < (BIGNUM *)(iVar2 >> 3)) {
      a = (BIGNUM *)(iVar2 >> 3);
    }
  }
  if (a_00 != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a_00);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (a < (BIGNUM *)(iVar2 >> 3)) {
      a = (BIGNUM *)(iVar2 >> 3);
    }
  }
  buf = (uchar *)CRYPTO_malloc((int)((int)&a->dmax + 2),"dsa_ameth.c",0x1ce);
  if (buf == (uchar *)0x0) {
    ERR_put_error(10,0x68,0x41,"dsa_ameth.c",0x1d1);
  }
  else {
    iVar2 = ASN1_bn_print(param_1,"priv:",(BIGNUM *)0x0,buf,param_3);
    if ((((iVar2 == 0) || (iVar2 = ASN1_bn_print(param_1,"pub: ",a_00,buf,param_3), iVar2 == 0)) ||
        (iVar2 = ASN1_bn_print(param_1,"P:   ",*(BIGNUM **)(iVar3 + 0xc),buf,param_3), iVar2 == 0))
       || (iVar2 = ASN1_bn_print(param_1,"Q:   ",*(BIGNUM **)(iVar3 + 0x10),buf,param_3), iVar2 == 0
          )) {
      puVar4 = (uchar *)0x0;
    }
    else {
      puVar4 = (uchar *)ASN1_bn_print(param_1,"G:   ",*(BIGNUM **)(iVar3 + 0x14),buf,param_3);
      if (puVar4 != (uchar *)0x0) {
        puVar4 = (uchar *)0x1;
      }
    }
    CRYPTO_free(buf);
    buf = puVar4;
  }
  return buf;
}

