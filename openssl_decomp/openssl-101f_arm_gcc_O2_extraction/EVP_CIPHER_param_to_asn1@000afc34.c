
int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  int iVar1;
  EVP_CIPHER *pEVar2;
  uint len;
  
  pEVar2 = c->cipher;
  if (pEVar2->set_asn1_parameters != (_func_1092 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000afc42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pEVar2->set_asn1_parameters)(c,type);
    return iVar1;
  }
  if ((int)(pEVar2->flags << 0x13) < 0) {
    if (type != (ASN1_TYPE *)0x0) {
      len = pEVar2->iv_len;
      if (0x10 < len) {
        OpenSSLDie("evp_lib.c",0x74,"j <= sizeof(c->iv)");
      }
      iVar1 = ASN1_TYPE_set_octetstring(type,c->oiv,len);
      return iVar1;
    }
    return 0;
  }
  return -1;
}

