
int alg_print(undefined4 param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pcVar6 = (char *)&local_20;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_20 = (*(undefined4 **)(param_2[1] + 4))[2];
  iVar2 = (*(code *)PTR_d2i_PBEPARAM_006a8318)(0,pcVar6,**(undefined4 **)(param_2[1] + 4));
  if (iVar2 != 0) {
    uVar8 = *(undefined4 *)PTR_bio_err_006a7f3c;
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*param_2);
    uVar3 = (*(code *)PTR_OBJ_nid2ln_006a821c)(uVar3);
    uVar4 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(*(undefined4 *)(iVar2 + 4));
    pcVar6 = "%s, Iteration %ld\n";
    (*(code *)PTR_BIO_printf_006a7f38)(uVar8,"%s, Iteration %ld\n",uVar3,uVar4);
    (*(code *)PTR_PBEPARAM_free_006a8320)(iVar2);
  }
  if (local_1c == *(int *)puVar1) {
    return 1;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar7 = 0;
  while( true ) {
    iVar5 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)(iVar2,0,0,0);
    if (iVar5 == 0) break;
    iVar7 = 1;
    (*(code *)PTR_sk_push_006a80a8)(pcVar6,iVar5);
  }
  if (iVar7 != 0) {
    (*(code *)PTR_ERR_clear_error_006a7fe0)();
  }
  return iVar7;
}

