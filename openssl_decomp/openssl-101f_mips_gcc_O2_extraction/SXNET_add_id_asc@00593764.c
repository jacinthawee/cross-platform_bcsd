
int SXNET_add_id_asc(SXNET **psx,char *zone,char *user,int userlen)

{
  ASN1_INTEGER *izone;
  int iVar1;
  
  izone = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,zone);
  if (izone != (ASN1_INTEGER *)0x0) {
    iVar1 = SXNET_add_id_INTEGER(psx,izone,user,userlen);
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x7d,0x83,"v3_sxnet.c",0x9d);
  return 0;
}

