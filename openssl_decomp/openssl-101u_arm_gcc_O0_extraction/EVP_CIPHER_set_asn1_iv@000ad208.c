
int EVP_CIPHER_set_asn1_iv(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  int iVar1;
  uint len;
  
  if (type == (ASN1_TYPE *)0x0) {
    return 0;
  }
  len = c->cipher->iv_len;
  if (len < 0x11) {
    iVar1 = ASN1_TYPE_set_octetstring(type,c->oiv,len);
    return iVar1;
  }
  OpenSSLDie("evp_lib.c",0x87,"j <= sizeof(c->iv)");
  iVar1 = ASN1_TYPE_set_octetstring(type,c->oiv,len);
  return iVar1;
}

