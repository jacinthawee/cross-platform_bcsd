
bool dsa_param_print(BIO *param_1,int param_2,int param_3)

{
  int iVar1;
  uchar *buf;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 0;
  iVar3 = *(int *)(param_2 + 0x14);
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
  buf = (uchar *)CRYPTO_malloc(uVar4 + 10,"dsa_ameth.c",0x1be);
  if (buf != (uchar *)0x0) {
    iVar2 = ASN1_bn_print(param_1,"priv:",(BIGNUM *)0x0,buf,param_3);
    if ((((iVar2 == 0) ||
         (iVar2 = ASN1_bn_print(param_1,"pub: ",(BIGNUM *)0x0,buf,param_3), iVar2 == 0)) ||
        (iVar2 = ASN1_bn_print(param_1,"P:   ",*(BIGNUM **)(iVar3 + 0xc),buf,param_3), iVar2 == 0))
       || (iVar2 = ASN1_bn_print(param_1,"Q:   ",*(BIGNUM **)(iVar3 + 0x10),buf,param_3), iVar2 == 0
          )) {
      bVar5 = false;
    }
    else {
      iVar3 = ASN1_bn_print(param_1,"G:   ",*(BIGNUM **)(iVar3 + 0x14),buf,param_3);
      bVar5 = iVar3 != 0;
    }
    CRYPTO_free(buf);
    return bVar5;
  }
  ERR_put_error(10,0x68,0x41,"dsa_ameth.c",0x1c0);
  return false;
}

