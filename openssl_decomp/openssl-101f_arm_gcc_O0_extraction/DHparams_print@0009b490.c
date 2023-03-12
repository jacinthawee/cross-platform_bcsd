
int DHparams_print(BIO *bp,DH *x)

{
  int iVar1;
  uchar *buf;
  int iVar2;
  uint uVar3;
  
  if (x->p != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(x->p);
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    uVar3 = iVar2 >> 3;
    if (uVar3 != 0) {
      if (x->g != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(x->g);
        iVar2 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar2 = iVar1 + 0xe;
        }
        if (uVar3 < (uint)(iVar2 >> 3)) {
          uVar3 = iVar2 >> 3;
        }
      }
      buf = (uchar *)CRYPTO_malloc(uVar3 + 10,"dh_ameth.c",0x164);
      if (buf == (uchar *)0x0) {
        iVar2 = 0x41;
        goto LAB_0009b566;
      }
      BIO_indent(bp,4,0x80);
      iVar2 = BN_num_bits(x->p);
      iVar2 = BIO_printf(bp,"%s: (%d bit)\n","PKCS#3 DH Parameters",iVar2);
      if ((((iVar2 < 1) ||
           (iVar2 = ASN1_bn_print(bp,"private-key:",(BIGNUM *)0x0,buf,8), iVar2 == 0)) ||
          (iVar2 = ASN1_bn_print(bp,"public-key:",(BIGNUM *)0x0,buf,8), iVar2 == 0)) ||
         ((iVar2 = ASN1_bn_print(bp,"prime:",x->p,buf,8), iVar2 == 0 ||
          (iVar2 = ASN1_bn_print(bp,"generator:",x->g,buf,8), iVar2 == 0)))) {
LAB_0009b53e:
        iVar2 = 0;
        ERR_put_error(5,100,7,"dh_ameth.c",0x181);
      }
      else {
        if (x->length != 0) {
          BIO_indent(bp,8,0x80);
          iVar2 = BIO_printf(bp,"recommended-private-length: %d bits\n",x->length);
          if (iVar2 < 1) goto LAB_0009b53e;
        }
        iVar2 = 1;
      }
      CRYPTO_free(buf);
      return iVar2;
    }
  }
  iVar2 = 0x43;
LAB_0009b566:
  ERR_put_error(5,100,iVar2,"dh_ameth.c",0x181);
  return 0;
}

