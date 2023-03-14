
X509_CRL * PKCS12_certbag2x509crl(PKCS12_SAFEBAG *bag)

{
  int iVar1;
  X509_CRL *pXVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(bag->type);
  if (iVar1 == 0x99) {
    iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(((bag->value).bag)->type);
    if (iVar1 == 0xa0) {
                    /* WARNING: Could not recover jumptable at 0x005aac80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pXVar2 = (X509_CRL *)
               (*(code *)PTR_ASN1_item_unpack_006a91d8)
                         (((bag->value).keybag)->version,PTR_X509_CRL_it_006a8fa4);
      return pXVar2;
    }
  }
  return (X509_CRL *)0x0;
}
