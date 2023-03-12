
int CMS_signed_add1_attr(CMS_SignerInfo *si,X509_ATTRIBUTE *attr)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509at_add1_attr_006a9d80)(si + 0xc);
  return (uint)(iVar1 != 0);
}

