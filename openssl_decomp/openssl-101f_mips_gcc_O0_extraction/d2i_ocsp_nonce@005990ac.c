
int d2i_ocsp_nonce(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
    iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(iVar2,*param_2,param_3);
    if (iVar1 != 0) {
      *param_2 = *param_2 + param_3;
      return iVar2;
    }
    if (iVar2 == 0) goto LAB_00599184;
  }
  else {
    iVar2 = *param_1;
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_ASN1_OCTET_STRING_new_006a978c)();
      iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(iVar2,*param_2,param_3);
      if (iVar1 != 0) goto LAB_00599100;
      if (iVar2 == 0) goto LAB_00599184;
    }
    else {
      iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_set_006a9790)(iVar2,*param_2);
      if (iVar1 != 0) {
LAB_00599100:
        *param_2 = *param_2 + param_3;
        *param_1 = iVar2;
        return iVar2;
      }
    }
    if (*param_1 == iVar2) goto LAB_00599184;
  }
  (*(code *)PTR_ASN1_STRING_free_006a98bc)(iVar2);
LAB_00599184:
  (*(code *)PTR_ERR_put_error_006a9030)(0x27,0x66,0x41,"v3_ocsp.c",0xec);
  return 0;
}

