
ASN1_OCTET_STRING * s2i_ASN1_OCTET_STRING(X509V3_EXT_METHOD *method,X509V3_CTX *ctx,char *str)

{
  ASN1_STRING *a;
  ASN1_OCTET_STRING *pAVar1;
  int local_14 [2];
  
  a = ASN1_STRING_type_new(4);
  if (a == (ASN1_STRING *)0x0) {
    ERR_put_error(0x22,0x70,0x41,"v3_skey.c",0x57);
  }
  else {
    pAVar1 = (ASN1_OCTET_STRING *)string_to_hex(str,local_14);
    a->data = (uchar *)pAVar1;
    if (pAVar1 == (ASN1_OCTET_STRING *)0x0) {
      ASN1_STRING_free(a);
      a = pAVar1;
    }
    else {
      a->length = local_14[0];
    }
  }
  return a;
}

