
char * i2s_ASN1_INTEGER(X509V3_EXT_METHOD *meth,ASN1_INTEGER *aint)

{
  BIGNUM *a;
  char *pcVar1;
  
  if (aint == (ASN1_INTEGER *)0x0) {
    return (char *)0x0;
  }
  a = ASN1_INTEGER_to_BN(aint,(BIGNUM *)0x0);
  if ((a != (BIGNUM *)0x0) && (pcVar1 = BN_bn2dec(a), pcVar1 != (char *)0x0)) {
    BN_free(a);
    return pcVar1;
  }
  ERR_put_error(0x22,0x78,0x41,"v3_utl.c",0x9a);
  BN_free(a);
  return (char *)0x0;
}

