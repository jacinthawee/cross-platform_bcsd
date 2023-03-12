
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  EVP_CIPHER *pEVar4;
  
  pEVar4 = c->cipher;
  if (pEVar4->get_asn1_parameters != (_func_1093 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000ad13c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pEVar4->get_asn1_parameters)(c,type);
    return iVar1;
  }
  if (((int)(pEVar4->flags << 0x13) < 0) &&
     ((uVar3 = pEVar4->flags & 0xf0007, uVar3 < 6 || ((7 < uVar3 && (uVar3 != 0x10001)))))) {
    if (type == (ASN1_TYPE *)0x0) {
      return 0;
    }
    uVar3 = pEVar4->iv_len;
    if (0x10 < uVar3) {
      OpenSSLDie("evp_lib.c",0x76,"l <= sizeof(c->iv)");
    }
    uVar2 = ASN1_TYPE_get_octetstring(type,c->oiv,uVar3);
    if (uVar3 == uVar2) {
      if ((int)uVar3 < 1) {
        return uVar3;
      }
      memcpy(c->iv,c->oiv,uVar3);
      return uVar3;
    }
  }
  return -1;
}

