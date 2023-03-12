
int EVP_CIPHER_asn1_to_param(EVP_CIPHER_CTX *c,ASN1_TYPE *type)

{
  EVP_CIPHER *pEVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  pEVar1 = c->cipher;
  if (pEVar1->get_asn1_parameters != (_func_1093 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00545790. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*pEVar1->get_asn1_parameters)(c,type);
    return iVar2;
  }
  if ((pEVar1->flags & 0x1000) != 0) {
    if (type == (ASN1_TYPE *)0x0) {
      return 0;
    }
    uVar4 = pEVar1->iv_len;
    if (0x10 < uVar4) {
      (*(code *)PTR_OpenSSLDie_006a8d4c)("evp_lib.c",0x62,"l <= sizeof(c->iv)");
    }
    uVar3 = (*(code *)PTR_ASN1_TYPE_get_octetstring_006a9d5c)(type,c->oiv,uVar4);
    if (uVar4 == uVar3) {
      if ((int)uVar4 < 1) {
        return uVar4;
      }
      (*(code *)PTR_memcpy_006aabf4)(c->iv,c->oiv,uVar4);
      return uVar4;
    }
  }
  return -1;
}

