
int CMS_unsigned_add1_attr_by_NID(CMS_SignerInfo *si,int nid,int type,void *bytes,int len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_NID_006a9d88)(si + 0x18);
  return (uint)(iVar1 != 0);
}

