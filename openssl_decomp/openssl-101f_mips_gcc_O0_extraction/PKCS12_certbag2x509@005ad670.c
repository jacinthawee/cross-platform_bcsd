
X509 * PKCS12_certbag2x509(PKCS12_SAFEBAG *bag)

{
  int iVar1;
  X509 *pXVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(bag->type);
  if (iVar1 == 0x98) {
    iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(((bag->value).bag)->type);
    if (iVar1 == 0x9e) {
                    /* WARNING: Could not recover jumptable at 0x005ad6d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pXVar2 = (X509 *)(*(code *)PTR_ASN1_item_unpack_006aa2f0)
                                 (((bag->value).keybag)->version,PTR_X509_it_006aa0b4);
      return pXVar2;
    }
  }
  return (X509 *)0x0;
}

