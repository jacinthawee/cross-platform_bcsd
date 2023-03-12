
int s2i_ASN1_IA5STRING(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_3 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,100,0x6b,"v3_ia5.c",99);
  }
  else {
    iVar1 = (*(code *)PTR_ASN1_STRING_type_new_006a97a4)(0x16);
    if (iVar1 != 0) {
      uVar2 = (*(code *)PTR_strlen_006aab30)(param_3);
      iVar3 = (*(code *)PTR_ASN1_STRING_set_006a8e0c)(iVar1,param_3,uVar2);
      if (iVar3 != 0) {
        return iVar1;
      }
      (*(code *)PTR_ASN1_STRING_free_006a98bc)(iVar1);
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,100,0x41,"v3_ia5.c",0x71);
  }
  return 0;
}

