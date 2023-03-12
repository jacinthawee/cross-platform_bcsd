
int CMS_unsigned_add1_attr_by_OBJ(CMS_SignerInfo *si,ASN1_OBJECT *obj,int type,void *bytes,int len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_OBJ_006a9d84)(si + 0x18);
  return (uint)(iVar1 != 0);
}

