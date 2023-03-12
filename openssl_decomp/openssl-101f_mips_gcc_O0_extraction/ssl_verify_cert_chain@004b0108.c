
int ssl_verify_cert_chain(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  code *pcVar9;
  undefined auStack_a4 [100];
  undefined4 local_40;
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_2 != 0) {
    iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
    if (iVar3 != 0) {
      uVar5 = (*(code *)PTR_sk_value_006a7f24)(param_2,0);
      iVar3 = (*(code *)PTR_X509_STORE_CTX_init_006a8304)
                        (auStack_a4,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0xc),uVar5,param_2);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xcf,0xb,"ssl_cert.c",0x209);
      }
      else {
        iVar3 = SSL_get_ex_data_X509_STORE_CTX_idx();
        (*(code *)PTR_X509_STORE_CTX_set_ex_data_006a9494)(auStack_a4,iVar3,param_1);
        if (*(int *)(param_1 + 0x24) == 0) {
          pcVar7 = "ssl_server";
        }
        else {
          pcVar7 = "ssl_client";
        }
        (*(code *)PTR_X509_STORE_CTX_set_default_006a9498)(auStack_a4,pcVar7);
        uVar5 = (*(code *)PTR_X509_STORE_CTX_get0_param_006a949c)(auStack_a4);
        (*(code *)PTR_X509_VERIFY_PARAM_set1_006a9438)(uVar5,*(undefined4 *)(param_1 + 0x70));
        if (*(int *)(param_1 + 0xcc) != 0) {
          (*(code *)PTR_X509_STORE_CTX_set_verify_cb_006a94a0)(auStack_a4);
        }
        pcVar9 = *(code **)(*(int *)(param_1 + 0xe4) + 100);
        if (pcVar9 == (code *)0x0) {
          iVar3 = (*(code *)PTR_X509_verify_cert_006a8308)(auStack_a4);
        }
        else {
          iVar3 = (*pcVar9)(auStack_a4,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x68));
        }
        puVar1 = PTR_X509_STORE_CTX_cleanup_006a8310;
        *(undefined4 *)(param_1 + 0xec) = local_40;
        (*(code *)puVar1)(auStack_a4);
      }
      goto LAB_004b015c;
    }
  }
  iVar3 = 0;
LAB_004b015c:
  if (local_1c == *(int *)puVar2) {
    return iVar3;
  }
  iVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = (*(code *)PTR_sk_new_null_006a80a4)();
  iVar8 = 0;
  do {
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
    if (iVar6 <= iVar8) {
      return iVar4;
    }
    uVar5 = (*(code *)PTR_sk_value_006a7f24)(iVar3,iVar8);
    iVar6 = (*(code *)PTR_X509_NAME_dup_006a823c)(uVar5);
    if (iVar6 == 0) break;
    iVar6 = (*(code *)PTR_sk_push_006a80a8)(iVar4,iVar6);
    iVar8 = iVar8 + 1;
  } while (iVar6 != 0);
  (*(code *)PTR_sk_pop_free_006a8158)(iVar4,PTR_X509_NAME_free_006a80f8);
  return 0;
}

