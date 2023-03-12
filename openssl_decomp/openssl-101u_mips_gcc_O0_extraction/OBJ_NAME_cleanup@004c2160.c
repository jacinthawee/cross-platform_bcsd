
void OBJ_NAME_cleanup(int type)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = names_lh;
  puVar1 = PTR_lh_doall_006a8490;
  if (names_lh != 0) {
    uVar3 = *(undefined4 *)(names_lh + 0x20);
    *(undefined4 *)(names_lh + 0x20) = 0;
    free_type = type;
    (*(code *)puVar1)(iVar2,names_lh_free_LHASH_DOALL);
    if (type < 0) {
      (*(code *)PTR_lh_free_006a7418)(names_lh);
      (*(code *)PTR_sk_pop_free_006a7058)(name_funcs_stack,name_funcs_free);
      names_lh = 0;
      name_funcs_stack = 0;
    }
    else {
      *(undefined4 *)(names_lh + 0x20) = uVar3;
    }
  }
  return;
}

