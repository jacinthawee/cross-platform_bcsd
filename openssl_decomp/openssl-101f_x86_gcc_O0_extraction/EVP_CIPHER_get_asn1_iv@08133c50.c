
int EVP_CIPHER_get_asn1_iv(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  uint uVar1;
  uint __n;
  
  if (type != (ASN1_TYPE *)0x0) {
    __n = c->cipher->iv_len;
    if (0x10 < __n) {
      OpenSSLDie("evp_lib.c",0x62,"l <= sizeof(c->iv)");
    }
    uVar1 = ASN1_TYPE_get_octetstring(type,c->oiv,__n);
    if (uVar1 == __n) {
      if (0 < (int)__n) {
        memcpy(c->iv,c->oiv,__n);
      }
    }
    else {
      __n = 0xffffffff;
    }
    return __n;
  }
  return 0;
}

