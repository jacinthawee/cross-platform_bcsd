
int dsa_priv_print(BIO *param_1,int param_2,int param_3)

{
  BIGNUM *a;
  int iVar1;
  uchar *buf;
  int iVar2;
  int iVar3;
  BIGNUM *a_00;
  BIGNUM *a_01;
  
  iVar3 = *(int *)(param_2 + 0x14);
  a = *(BIGNUM **)(iVar3 + 0xc);
  a_00 = *(BIGNUM **)(iVar3 + 0x1c);
  a_01 = *(BIGNUM **)(iVar3 + 0x18);
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
  if (a_01 != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a_01);
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
    return 0;
  }
  if (a_00 == (BIGNUM *)0x0) {
LAB_0010956c:
    iVar2 = ASN1_bn_print(param_1,"priv:",a_00,buf,param_3);
    if ((((iVar2 != 0) && (iVar2 = ASN1_bn_print(param_1,"pub: ",a_01,buf,param_3), iVar2 != 0)) &&
        (iVar2 = ASN1_bn_print(param_1,"P:   ",*(BIGNUM **)(iVar3 + 0xc),buf,param_3), iVar2 != 0))
       && (iVar2 = ASN1_bn_print(param_1,"Q:   ",*(BIGNUM **)(iVar3 + 0x10),buf,param_3), iVar2 != 0
          )) {
      iVar3 = ASN1_bn_print(param_1,"G:   ",*(BIGNUM **)(iVar3 + 0x14),buf,param_3);
      if (iVar3 != 0) {
        iVar3 = 1;
      }
      goto LAB_0010953c;
    }
  }
  else {
    iVar2 = BIO_indent(param_1,param_3,0x80);
    if (iVar2 != 0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(iVar3 + 0xc));
      iVar2 = BIO_printf(param_1,"%s: (%d bit)\n","Private-Key",iVar2);
      if (0 < iVar2) goto LAB_0010956c;
    }
  }
  iVar3 = 0;
LAB_0010953c:
  CRYPTO_free(buf);
  return iVar3;
}

