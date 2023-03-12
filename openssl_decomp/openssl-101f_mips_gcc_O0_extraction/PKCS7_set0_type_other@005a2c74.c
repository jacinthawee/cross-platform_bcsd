
int PKCS7_set0_type_other(PKCS7 *p7,int type,ASN1_TYPE *other)

{
  ASN1_OBJECT *pAVar1;
  
  pAVar1 = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(type);
  (p7->d).other = other;
  p7->type = pAVar1;
  return 1;
}

