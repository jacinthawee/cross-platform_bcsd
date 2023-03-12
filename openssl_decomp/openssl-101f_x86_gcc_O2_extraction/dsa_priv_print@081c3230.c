
bool dsa_priv_print(BIO *param_1,int param_2,int param_3)

{
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar1;
  uchar *buf;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 0;
  iVar3 = *(int *)(param_2 + 0x14);
  a = *(BIGNUM **)(iVar3 + 0x1c);
  a_00 = *(BIGNUM **)(iVar3 + 0x18);
  if (*(BIGNUM **)(iVar3 + 0xc) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar3 + 0xc));
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    uVar4 = iVar2 >> 3;
  }
  if (*(BIGNUM **)(iVar3 + 0x10) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar3 + 0x10));
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar2 >> 3)) {
      uVar4 = iVar2 >> 3;
    }
  }
  if (*(BIGNUM **)(iVar3 + 0x14) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar3 + 0x14));
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar2 >> 3)) {
      uVar4 = iVar2 >> 3;
    }
  }
  if (a != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar2 >> 3)) {
      uVar4 = iVar2 >> 3;
    }
  }
  if (a_00 != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(a_00);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar2 >> 3)) {
      uVar4 = iVar2 >> 3;
    }
  }
  buf = (uchar *)CRYPTO_malloc(uVar4 + 10,"dsa_ameth.c",0x1ce);
  if (buf == (uchar *)0x0) {
    ERR_put_error(10,0x68,0x41,"dsa_ameth.c",0x1d1);
    return false;
  }
  if (a == (BIGNUM *)0x0) {
LAB_081c3376:
    iVar2 = ASN1_bn_print(param_1,"priv:",a,buf,param_3);
    if ((((iVar2 != 0) && (iVar2 = ASN1_bn_print(param_1,"pub: ",a_00,buf,param_3), iVar2 != 0)) &&
        (iVar2 = ASN1_bn_print(param_1,"P:   ",*(BIGNUM **)(iVar3 + 0xc),buf,param_3), iVar2 != 0))
       && (iVar2 = ASN1_bn_print(param_1,"Q:   ",*(BIGNUM **)(iVar3 + 0x10),buf,param_3), iVar2 != 0
          )) {
      iVar3 = ASN1_bn_print(param_1,"G:   ",*(BIGNUM **)(iVar3 + 0x14),buf,param_3);
      bVar5 = iVar3 != 0;
      goto LAB_081c3336;
    }
  }
  else {
    iVar2 = BIO_indent(param_1,param_3,0x80);
    if (iVar2 != 0) {
      iVar2 = BN_num_bits(*(BIGNUM **)(iVar3 + 0xc));
      iVar2 = BIO_printf(param_1,"%s: (%d bit)\n","Private-Key",iVar2);
      if (0 < iVar2) goto LAB_081c3376;
    }
  }
  bVar5 = false;
LAB_081c3336:
  CRYPTO_free(buf);
  return bVar5;
}

