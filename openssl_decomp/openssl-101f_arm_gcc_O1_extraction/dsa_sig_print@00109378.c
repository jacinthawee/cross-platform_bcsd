
uchar * dsa_sig_print(BIO *param_1,undefined4 param_2,ASN1_STRING *param_3,int param_4)

{
  DSA_SIG *a;
  BIGNUM *a_00;
  int iVar1;
  uchar *puVar2;
  int iVar3;
  uchar *puVar4;
  uchar *local_1c [2];
  
  if (param_3 == (ASN1_STRING *)0x0) {
    iVar3 = BIO_puts(param_1,"\n");
    return (uchar *)(uint)(0 < iVar3);
  }
  local_1c[0] = param_3->data;
  a = d2i_DSA_SIG((DSA_SIG **)0x0,local_1c,param_3->length);
  if (a != (DSA_SIG *)0x0) {
    a_00 = a->r;
    if (a_00 != (BIGNUM *)0x0) {
      iVar1 = BN_num_bits(a_00);
      iVar3 = iVar1 + 0xe;
      if (-1 < iVar1 + 7) {
        iVar3 = iVar1 + 7;
      }
      a_00 = (BIGNUM *)(iVar3 >> 3);
    }
    if (a->s != (BIGNUM *)0x0) {
      iVar1 = BN_num_bits(a->s);
      iVar3 = iVar1 + 7;
      if (iVar1 + 7 < 0) {
        iVar3 = iVar1 + 0xe;
      }
      if (a_00 < (BIGNUM *)(iVar3 >> 3)) {
        a_00 = (BIGNUM *)(iVar3 >> 3);
      }
    }
    puVar2 = (uchar *)CRYPTO_malloc((int)((int)&a_00->dmax + 2),"dsa_ameth.c",0x237);
    if (puVar2 == (uchar *)0x0) {
      ERR_put_error(10,0x7d,0x41,"dsa_ameth.c",0x23a);
    }
    else {
      iVar3 = BIO_write(param_1,"\n",1);
      if ((iVar3 == 1) && (iVar3 = ASN1_bn_print(param_1,"r:   ",a->r,puVar2,param_4), iVar3 != 0))
      {
        puVar4 = (uchar *)ASN1_bn_print(param_1,"s:   ",a->s,puVar2,param_4);
        if (puVar4 != (uchar *)0x0) {
          puVar4 = (uchar *)0x1;
        }
      }
      else {
        puVar4 = (uchar *)0x0;
      }
      CRYPTO_free(puVar2);
      puVar2 = puVar4;
    }
    DSA_SIG_free(a);
    return puVar2;
  }
  puVar2 = (uchar *)X509_signature_dump(param_1,param_3,param_4);
  return puVar2;
}

