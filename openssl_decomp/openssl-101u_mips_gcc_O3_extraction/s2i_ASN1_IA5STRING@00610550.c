
int s2i_ASN1_IA5STRING(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_3 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,100,0x6b,"v3_ia5.c",0x66);
  }
  else {
    iVar1 = (*(code *)PTR_ASN1_STRING_type_new_006a8680)(0x16);
    if (iVar1 != 0) {
      uVar2 = (*(code *)PTR_strlen_006a9a24)(param_3);
      iVar3 = (*(code *)PTR_ASN1_STRING_set_006a7d1c)(iVar1,param_3,uVar2);
      if (iVar3 != 0) {
        return iVar1;
      }
      (*(code *)PTR_ASN1_STRING_free_006a879c)(iVar1);
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,100,0x41,"v3_ia5.c",0x75);
  }
  return 0;
}

