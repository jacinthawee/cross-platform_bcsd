
int CMS_signed_add1_attr_by_NID(CMS_SignerInfo *si,int nid,int type,void *bytes,int len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_NID_006a8c6c)(si + 0xc);
  return (uint)(iVar1 != 0);
}

