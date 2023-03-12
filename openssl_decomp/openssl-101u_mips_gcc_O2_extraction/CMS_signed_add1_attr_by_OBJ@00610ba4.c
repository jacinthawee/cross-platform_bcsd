
int CMS_signed_add1_attr_by_OBJ(CMS_SignerInfo *si,ASN1_OBJECT *obj,int type,void *bytes,int len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_OBJ_006a8c68)(si + 0xc);
  return (uint)(iVar1 != 0);
}

