
int EVP_CIPHER_param_to_asn1(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  int iVar1;
  EVP_CIPHER *pEVar2;
  uint uVar3;
  
  pEVar2 = c->cipher;
  if (pEVar2->set_asn1_parameters != (_func_1092 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005423c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pEVar2->set_asn1_parameters)(c,type);
    return iVar1;
  }
  if ((pEVar2->flags & 0x1000) != 0) {
    uVar3 = pEVar2->flags & 0xf0007;
    if ((uVar3 < 6) || ((7 < uVar3 && (uVar3 != 0x10001)))) {
      if (type != (ASN1_TYPE *)0x0) {
        uVar3 = pEVar2->iv_len;
        if (0x10 < uVar3) {
          (*(code *)PTR_OpenSSLDie_006a7c5c)("evp_lib.c",0x87,"j <= sizeof(c->iv)");
        }
                    /* WARNING: Could not recover jumptable at 0x00542464. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)PTR_ASN1_TYPE_set_octetstring_006a8c3c)(type,c->oiv,uVar3);
        return iVar1;
      }
      return 0;
    }
  }
  return -1;
}

