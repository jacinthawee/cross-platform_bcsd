
int v2i_BASIC_CONSTRAINTS(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  
  iVar1 = (*(code *)PTR_ASN1_item_new_006a8654)(BASIC_CONSTRAINTS_it);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x66,0x41,"v3_bcons.c",0x6f);
    iVar5 = iVar1;
  }
  else {
    iVar5 = 0;
    do {
      while( true ) {
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(param_3);
        if (iVar2 <= iVar5) {
          return iVar1;
        }
        puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(param_3,iVar5);
        pcVar4 = (char *)puVar3[1];
        if (((*pcVar4 != 'C') || (pcVar4[1] != 'A')) || (pcVar4[2] != '\0')) break;
        iVar2 = (*(code *)PTR_X509V3_get_value_bool_006a8dd8)(puVar3,iVar1);
        iVar5 = iVar5 + 1;
        if (iVar2 == 0) goto LAB_0060fde8;
      }
      iVar2 = (*(code *)PTR_strcmp_006a9b18)(pcVar4,"pathlen");
      if (iVar2 != 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x66,0x6a,"v3_bcons.c",0x7b);
        (*(code *)PTR_ERR_add_error_data_006a813c)
                  (6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
        break;
      }
      iVar2 = (*(code *)PTR_X509V3_get_value_int_006a9090)(puVar3,iVar1 + 4);
      iVar5 = iVar5 + 1;
    } while (iVar2 != 0);
LAB_0060fde8:
    iVar5 = 0;
    (*(code *)PTR_ASN1_item_free_006a8658)(iVar1,BASIC_CONSTRAINTS_it);
  }
  return iVar5;
}

