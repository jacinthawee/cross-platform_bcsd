
int SXNET_add_id_ulong(SXNET **psx,ulong lzone,char *user,int userlen)

{
  ASN1_INTEGER *izone;
  int iVar1;
  
  izone = (ASN1_INTEGER *)(*(code *)PTR_ASN1_STRING_type_new_006a97a4)(2);
  if (izone != (ASN1_INTEGER *)0x0) {
    iVar1 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(izone,lzone);
    if (iVar1 != 0) {
      iVar1 = SXNET_add_id_INTEGER(psx,izone,user,userlen);
      return iVar1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x7f,0x41,"v3_sxnet.c",0xaa);
  (*(code *)PTR_ASN1_STRING_free_006a98bc)(izone);
  return 0;
}

