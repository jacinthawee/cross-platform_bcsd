
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  int iVar1;
  uint uVar2;
  EVP_CIPHER *pEVar3;
  uint __n;
  
  pEVar3 = c->cipher;
  if (pEVar3->get_asn1_parameters != (_func_1093 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000afc98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pEVar3->get_asn1_parameters)(c,type);
    return iVar1;
  }
  if ((int)(pEVar3->flags << 0x13) < 0) {
    if (type == (ASN1_TYPE *)0x0) {
      return 0;
    }
    __n = pEVar3->iv_len;
    if (0x10 < __n) {
      OpenSSLDie("evp_lib.c",0x62,"l <= sizeof(c->iv)");
    }
    uVar2 = ASN1_TYPE_get_octetstring(type,c->oiv,__n);
    if (__n == uVar2) {
      if ((int)__n < 1) {
        return __n;
      }
      memcpy(c->iv,c->oiv,__n);
      return __n;
    }
  }
  return -1;
}

