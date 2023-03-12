
void policies_print(int param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  bVar1 = param_1 == 0;
  if (bVar1) {
    param_1 = (*(code *)PTR_BIO_new_fp_006a7248)(*(undefined4 *)PTR_stderr_006a9af8,0);
  }
  uVar2 = (*(code *)PTR_X509_STORE_CTX_get0_policy_tree_006a7c20)(param_2);
  iVar3 = (*(code *)PTR_X509_STORE_CTX_get_explicit_policy_006a7c24)(param_2);
  if (iVar3 == 0) {
    pcVar6 = "False";
  }
  else {
    pcVar6 = "True";
  }
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Require explicit Policy: %s\n",pcVar6);
  iVar3 = (*(code *)PTR_X509_policy_tree_get0_policies_006a7c28)(uVar2);
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%s Policies:","Authority");
  if (iVar3 == 0) {
    (*(code *)PTR_BIO_puts_006a6f58)(param_1," <empty>\n");
  }
  else {
    (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
    iVar7 = 0;
    while( true ) {
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(iVar3);
      if (iVar5 <= iVar7) break;
      uVar4 = (*(code *)PTR_sk_value_006a6e24)(iVar3,iVar7);
      (*(code *)PTR_X509_POLICY_NODE_print_006a7c2c)(param_1,uVar4,2);
      iVar7 = iVar7 + 1;
    }
  }
  iVar3 = (*(code *)PTR_X509_policy_tree_get0_user_policies_006a7c30)(uVar2);
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%s Policies:",&DAT_0064008c);
  if (iVar3 == 0) {
    (*(code *)PTR_BIO_puts_006a6f58)(param_1," <empty>\n");
  }
  else {
    (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
    iVar7 = 0;
    while( true ) {
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(iVar3);
      if (iVar5 <= iVar7) break;
      uVar2 = (*(code *)PTR_sk_value_006a6e24)(iVar3,iVar7);
      (*(code *)PTR_X509_POLICY_NODE_print_006a7c2c)(param_1,uVar2,2);
      iVar7 = iVar7 + 1;
    }
  }
  if (bVar1) {
                    /* WARNING: Could not recover jumptable at 0x0045e8e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_BIO_free_006a6e70)(param_1);
    return;
  }
  return;
}

