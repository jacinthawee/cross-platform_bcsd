
int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  EVP_CIPHER *pEVar1;
  int iVar2;
  uint uVar3;
  
  pEVar1 = c->cipher;
  if (pEVar1->set_asn1_parameters != (_func_1092 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x08131317. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*pEVar1->set_asn1_parameters)(c,type);
    return iVar2;
  }
  if (((pEVar1->flags & 0x1000) == 0) ||
     ((uVar3 = pEVar1->flags & 0xf0007, 5 < uVar3 && ((uVar3 < 8 || (uVar3 == 0x10001)))))) {
    iVar2 = -1;
  }
  else if (type == (ASN1_TYPE *)0x0) {
    iVar2 = 0;
  }
  else {
    uVar3 = pEVar1->iv_len;
    if (0x10 < uVar3) {
      OpenSSLDie("evp_lib.c",0x87,"j <= sizeof(c->iv)");
    }
    iVar2 = ASN1_TYPE_set_octetstring(type,c->oiv,uVar3);
  }
  return iVar2;
}

