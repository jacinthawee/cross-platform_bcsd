
int CMS_unsigned_get_attr_by_NID(CMS_SignerInfo *si,int nid,int lastpos)

{
  int iVar1;
  
  iVar1 = X509at_get_attr_by_NID(*(stack_st_X509_ATTRIBUTE **)(si + 0x18),nid,lastpos);
  return iVar1;
}
