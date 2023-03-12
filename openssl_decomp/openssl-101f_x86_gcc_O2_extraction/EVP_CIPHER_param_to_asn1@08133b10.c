
int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  EVP_CIPHER *pEVar1;
  uint len;
  int iVar2;
  
  pEVar1 = c->cipher;
  if (pEVar1->set_asn1_parameters != (_func_1092 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08133b27. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*pEVar1->set_asn1_parameters)(c,type);
    return iVar2;
  }
  if ((*(byte *)((int)&pEVar1->flags + 1) & 0x10) == 0) {
    iVar2 = -1;
  }
  else if (type == (ASN1_TYPE *)0x0) {
    iVar2 = 0;
  }
  else {
    len = pEVar1->iv_len;
    if (0x10 < len) {
      OpenSSLDie("evp_lib.c",0x74,"j <= sizeof(c->iv)");
    }
    iVar2 = ASN1_TYPE_set_octetstring(type,c->oiv,len);
  }
  return iVar2;
}
