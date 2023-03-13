
int CMS_unsigned_add1_attr_by_txt(CMS_SignerInfo *si,char *attrname,int type,void *bytes,int len)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_by_txt_006a8c70)(si + 0x18);
  return (uint)(iVar1 != 0);
}

