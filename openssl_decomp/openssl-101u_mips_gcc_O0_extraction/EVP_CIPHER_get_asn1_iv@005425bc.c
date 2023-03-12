
int EVP_CIPHER_get_asn1_iv(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  uint uVar1;
  uint uVar2;
  
  if (type == (ASN1_TYPE *)0x0) {
    return 0;
  }
  uVar2 = c->cipher->iv_len;
  if (0x10 < uVar2) {
    (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_lib.c",0x76,"l <= sizeof(c->iv)");
  }
  uVar1 = (*(code *)PTR_ASN1_TYPE_get_octetstring_006a8c40)(type,c->oiv,uVar2);
  if (uVar1 == uVar2) {
    if ((int)uVar2 < 1) {
      return uVar2;
    }
    (*(code *)PTR_memcpy_006a9aec)(c->iv,c->oiv,uVar2);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
