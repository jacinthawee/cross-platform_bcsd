
int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  int iVar1;
  uint uVar2;
  EVP_CIPHER *pEVar3;
  
  pEVar3 = c->cipher;
  if (pEVar3->set_asn1_parameters != (_func_1092 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000ad0d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pEVar3->set_asn1_parameters)(c,type);
    return iVar1;
  }
  if (((int)(pEVar3->flags << 0x13) < 0) &&
     ((uVar2 = pEVar3->flags & 0xf0007, uVar2 < 6 || ((7 < uVar2 && (uVar2 != 0x10001)))))) {
    if (type != (ASN1_TYPE *)0x0) {
      uVar2 = pEVar3->iv_len;
      if (0x10 < uVar2) {
        OpenSSLDie("evp_lib.c",0x87,"j <= sizeof(c->iv)");
      }
      iVar1 = ASN1_TYPE_set_octetstring(type,c->oiv,uVar2);
      return iVar1;
    }
    return 0;
  }
  return -1;
}

