
int v2i_EXTENDED_KEY_USAGE(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = (*(code *)PTR_sk_new_null_006a6fa4)();
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x67,0x41,"v3_extku.c",0x81);
    iVar1 = 0;
  }
  else {
    iVar4 = 0;
    while( true ) {
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(param_3);
      if (iVar2 <= iVar4) break;
      puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(param_3,iVar4);
      if (puVar3[2] == 0) {
        iVar2 = (*(code *)PTR_OBJ_txt2obj_006a7000)(puVar3[1]);
      }
      else {
        iVar2 = (*(code *)PTR_OBJ_txt2obj_006a7000)(puVar3[2],0);
      }
      if (iVar2 == 0) {
        (*(code *)PTR_sk_pop_free_006a7058)(iVar1,PTR_ASN1_OBJECT_free_006a7004);
        (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x67,0x6e,"v3_extku.c",0x8e);
        (*(code *)PTR_ERR_add_error_data_006a813c)
                  (6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
        return 0;
      }
      (*(code *)PTR_sk_push_006a6fa8)(iVar1,iVar2);
      iVar4 = iVar4 + 1;
    }
  }
  return iVar1;
}

