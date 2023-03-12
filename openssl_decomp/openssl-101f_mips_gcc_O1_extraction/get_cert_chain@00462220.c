
int get_cert_chain(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uStack_e0;
  int iStack_dc;
  undefined *puStack_d4;
  undefined *puStack_d0;
  int iStack_cc;
  undefined4 *puStack_c8;
  code *pcStack_c4;
  undefined *local_b0;
  undefined auStack_a4 [136];
  int local_1c;
  
  puStack_d0 = PTR___stack_chk_guard_006aabf0;
  puStack_d4 = auStack_a4;
  local_b0 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_X509_STORE_CTX_init_006a8304)(puStack_d4,param_2,param_1,0);
  iVar2 = (**(code **)(local_b0 + -0x7bd8))(puStack_d4);
  if (iVar2 < 1) {
    uVar3 = 0;
    iStack_cc = (**(code **)(local_b0 + -0x7bcc))(puStack_d4);
    if (iStack_cc == 0) {
      iStack_cc = -1;
    }
  }
  else {
    iStack_cc = 0;
    uVar3 = (**(code **)(local_b0 + -0x7bd4))(puStack_d4);
  }
  (**(code **)(local_b0 + -0x7bd0))(puStack_d4);
  *param_3 = uVar3;
  if (local_1c != *(int *)puStack_d0) {
    pcStack_c4 = alg_print;
    (**(code **)(local_b0 + -0x5328))();
    puVar1 = PTR___stack_chk_guard_006aabf0;
    pcVar6 = (char *)&uStack_e0;
    iStack_dc = *(int *)PTR___stack_chk_guard_006aabf0;
    uStack_e0 = (*(undefined4 **)(param_2[1] + 4))[2];
    puStack_c8 = param_3;
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
    if (iStack_dc != *(int *)puVar1) {
      iVar2 = iStack_dc;
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      iVar7 = 0;
      while (iVar5 = (*(code *)PTR_PEM_read_bio_X509_006a80cc)(iVar2,0,0,0), iVar5 != 0) {
        iVar7 = 1;
        (*(code *)PTR_sk_push_006a80a8)(pcVar6,iVar5);
      }
      if (iVar7 != 0) {
        (*(code *)PTR_ERR_clear_error_006a7fe0)();
      }
      return iVar7;
    }
    return 1;
  }
  return iStack_cc;
}

