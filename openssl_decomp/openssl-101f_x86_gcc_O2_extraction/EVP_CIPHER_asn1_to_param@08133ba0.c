
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  EVP_CIPHER *pEVar1;
  uint __n;
  int iVar2;
  uint uVar3;
  
  pEVar1 = c->cipher;
  if (pEVar1->get_asn1_parameters != (_func_1093 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08133bbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*pEVar1->get_asn1_parameters)(c,type);
    return iVar2;
  }
  if ((*(byte *)((int)&pEVar1->flags + 1) & 0x10) != 0) {
    if (type == (ASN1_TYPE *)0x0) {
      return 0;
    }
    __n = pEVar1->iv_len;
    if (0x10 < __n) {
      OpenSSLDie("evp_lib.c",0x62,"l <= sizeof(c->iv)");
    }
    uVar3 = ASN1_TYPE_get_octetstring(type,c->oiv,__n);
    if (__n == uVar3) {
      if ((int)__n < 1) {
        return __n;
      }
      memcpy(c->iv,c->oiv,__n);
      return __n;
    }
  }
  return -1;
}

