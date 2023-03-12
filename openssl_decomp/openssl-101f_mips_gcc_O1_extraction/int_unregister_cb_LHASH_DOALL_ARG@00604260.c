
void int_unregister_cb_LHASH_DOALL_ARG(int param_1,int param_2)

{
  int iVar1;
  
  while( true ) {
    iVar1 = (*(code *)PTR_sk_find_006a906c)(*(undefined4 *)(param_1 + 4),param_2);
    if (iVar1 < 0) break;
    (*(code *)PTR_sk_delete_006a8398)(*(undefined4 *)(param_1 + 4),iVar1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (param_2 != *(int *)(param_1 + 8)) {
    return;
  }
  (*(code *)PTR_engine_unlocked_finish_006aa894)(param_2,0);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

