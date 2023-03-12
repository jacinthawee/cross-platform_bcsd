
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
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (param_2 != 0) {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_2);
    if (iVar3 != 0) {
      uVar5 = (*(code *)PTR_sk_value_006a6e24)(param_2,0);
      iVar3 = (*(code *)PTR_X509_STORE_CTX_init_006a7270)
                        (auStack_a4,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0xc),uVar5,param_2);
      if (iVar3 == 0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xcf,0xb,"ssl_cert.c",0x1dc);
      }
      else {
        iVar3 = SSL_get_ex_data_X509_STORE_CTX_idx();
        (*(code *)PTR_X509_STORE_CTX_set_ex_data_006a8374)(auStack_a4,iVar3,param_1);
        if (*(int *)(param_1 + 0x24) == 0) {
          pcVar7 = "ssl_server";
        }
        else {
          pcVar7 = "ssl_client";
        }
        (*(code *)PTR_X509_STORE_CTX_set_default_006a8378)(auStack_a4,pcVar7);
        uVar5 = (*(code *)PTR_X509_STORE_CTX_get0_param_006a837c)(auStack_a4);
        (*(code *)PTR_X509_VERIFY_PARAM_set1_006a831c)(uVar5,*(undefined4 *)(param_1 + 0x70));
        if (*(int *)(param_1 + 0xcc) != 0) {
          (*(code *)PTR_X509_STORE_CTX_set_verify_cb_006a8380)(auStack_a4);
        }
        pcVar9 = *(code **)(*(int *)(param_1 + 0xe4) + 100);
        if (pcVar9 == (code *)0x0) {
          iVar3 = (*(code *)PTR_X509_verify_cert_006a728c)(auStack_a4);
        }
        else {
          iVar3 = (*pcVar9)(auStack_a4,*(undefined4 *)(*(int *)(param_1 + 0xe4) + 0x68));
        }
        puVar1 = PTR_X509_STORE_CTX_cleanup_006a7294;
        *(undefined4 *)(param_1 + 0xec) = local_40;
        (*(code *)puVar1)(auStack_a4);
      }
      goto LAB_004ad0f8;
    }
  }
  iVar3 = 0;
LAB_004ad0f8:
  if (local_1c == *(int *)puVar2) {
    return iVar3;
  }
  iVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = (*(code *)PTR_sk_new_null_006a6fa4)();
  iVar8 = 0;
  do {
    iVar6 = (*(code *)PTR_sk_num_006a6e2c)(iVar3);
    if (iVar6 <= iVar8) {
      return iVar4;
    }
    uVar5 = (*(code *)PTR_sk_value_006a6e24)(iVar3,iVar8);
    iVar6 = (*(code *)PTR_X509_NAME_dup_006a713c)(uVar5);
    if (iVar6 == 0) break;
    iVar6 = (*(code *)PTR_sk_push_006a6fa8)(iVar4,iVar6);
    iVar8 = iVar8 + 1;
  } while (iVar6 != 0);
  (*(code *)PTR_sk_pop_free_006a7058)(iVar4,PTR_X509_NAME_free_006a6ff8);
  return 0;
}

