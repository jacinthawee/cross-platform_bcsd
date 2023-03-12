
X509 * PKCS12_certbag2x509(PKCS12_SAFEBAG *bag)

{
  int iVar1;
  X509 *pXVar2;
  
  iVar1 = OBJ_obj2nid(bag->type);
  if (iVar1 == 0x98) {
    iVar1 = OBJ_obj2nid(((bag->value).bag)->type);
    if (iVar1 == 0x9e) {
      pXVar2 = (X509 *)ASN1_item_unpack(((bag->value).keybag)->version,(ASN1_ITEM *)X509_it);
      return pXVar2;
    }
  }
  return (X509 *)0x0;
}

