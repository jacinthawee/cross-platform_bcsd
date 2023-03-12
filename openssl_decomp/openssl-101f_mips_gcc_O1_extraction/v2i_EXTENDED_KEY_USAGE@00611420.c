
int v2i_EXTENDED_KEY_USAGE(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = (*(code *)PTR_sk_new_null_006a80a4)();
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x67,0x41,"v3_extku.c",0x7f);
    iVar1 = 0;
  }
  else {
    iVar4 = 0;
    while( true ) {
      iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_3);
      if (iVar2 <= iVar4) break;
      puVar3 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(param_3,iVar4);
      if (puVar3[2] == 0) {
        iVar2 = (*(code *)PTR_OBJ_txt2obj_006a8100)(puVar3[1]);
      }
      else {
        iVar2 = (*(code *)PTR_OBJ_txt2obj_006a8100)(puVar3[2],0);
      }
      if (iVar2 == 0) {
        (*(code *)PTR_sk_pop_free_006a8158)(iVar1,PTR_ASN1_OBJECT_free_006a8104);
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x67,0x6e,"v3_extku.c",0x89);
        (*(code *)PTR_ERR_add_error_data_006a9264)
                  (6,"section:",*puVar3,",name:",puVar3[1],",value:",puVar3[2]);
        return 0;
      }
      (*(code *)PTR_sk_push_006a80a8)(iVar1,iVar2);
      iVar4 = iVar4 + 1;
    }
  }
  return iVar1;
}

