
X509 * PKCS12_certbag2x509(PKCS12_SAFEBAG *bag)

{
  int iVar1;
  X509 *pXVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(bag->type);
  if (iVar1 == 0x98) {
    iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(((bag->value).bag)->type);
    if (iVar1 == 0x9e) {
                    /* WARNING: Could not recover jumptable at 0x005aabfc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pXVar2 = (X509 *)(*(code *)PTR_ASN1_item_unpack_006a91d8)
                                 (((bag->value).keybag)->version,PTR_X509_it_006a8f9c);
      return pXVar2;
    }
  }
  return (X509 *)0x0;
}

