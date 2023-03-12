
int EVP_CIPHER_set_asn1_iv(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  int iVar1;
  uint uVar2;
  
  if (type == (ASN1_TYPE *)0x0) {
    return 0;
  }
  uVar2 = c->cipher->iv_len;
  if (uVar2 < 0x11) {
                    /* WARNING: Could not recover jumptable at 0x00542708. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_ASN1_TYPE_set_octetstring_006a8c3c)(type,c->oiv,uVar2);
    return iVar1;
  }
  (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_lib.c",0x87,"j <= sizeof(c->iv)");
                    /* WARNING: Could not recover jumptable at 0x00542750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_TYPE_set_octetstring_006a8c3c)(type,c->oiv,uVar2);
  return iVar1;
}

