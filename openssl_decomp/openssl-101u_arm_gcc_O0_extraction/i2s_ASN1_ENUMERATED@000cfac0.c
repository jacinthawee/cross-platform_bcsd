
char * i2s_ASN1_ENUMERATED(X509V3_EXT_METHOD *meth,ASN1_ENUMERATED *aint)

{
  BIGNUM *a;
  char *pcVar1;
  
  if (aint == (ASN1_ENUMERATED *)0x0) {
    return (char *)0x0;
  }
  a = ASN1_ENUMERATED_to_BN(aint,(BIGNUM *)0x0);
  if ((a != (BIGNUM *)0x0) && (pcVar1 = BN_bn2dec(a), pcVar1 != (char *)0x0)) {
    BN_free(a);
    return pcVar1;
  }
  ERR_put_error(0x22,0x79,0x41,"v3_utl.c",0x9d);
  BN_free(a);
  return (char *)0x0;
}

