
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
    param_1 = (*(code *)PTR_BIO_new_fp_006a835c)(*(undefined4 *)PTR_stderr_006aac00,0);
  }
  uVar2 = (*(code *)PTR_X509_STORE_CTX_get0_policy_tree_006a8d0c)(param_2);
  iVar3 = (*(code *)PTR_X509_STORE_CTX_get_explicit_policy_006a8d10)(param_2);
  if (iVar3 == 0) {
    pcVar6 = "False";
  }
  else {
    pcVar6 = "True";
  }
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Require explicit Policy: %s\n",pcVar6);
  iVar3 = (*(code *)PTR_X509_policy_tree_get0_policies_006a8d14)(uVar2);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s Policies:","Authority");
  if (iVar3 == 0) {
    (*(code *)PTR_BIO_puts_006a8058)(param_1," <empty>\n");
  }
  else {
    (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
    iVar7 = 0;
    while( true ) {
      iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
      if (iVar5 <= iVar7) break;
      uVar4 = (*(code *)PTR_sk_value_006a7f24)(iVar3,iVar7);
      (*(code *)PTR_X509_POLICY_NODE_print_006a8d18)(param_1,uVar4,2);
      iVar7 = iVar7 + 1;
    }
  }
  iVar3 = (*(code *)PTR_X509_policy_tree_get0_user_policies_006a8d1c)(uVar2);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s Policies:",&DAT_00640604);
  if (iVar3 == 0) {
    (*(code *)PTR_BIO_puts_006a8058)(param_1," <empty>\n");
  }
  else {
    (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
    iVar7 = 0;
    while( true ) {
      iVar5 = (*(code *)PTR_sk_num_006a7f2c)(iVar3);
      if (iVar5 <= iVar7) break;
      uVar2 = (*(code *)PTR_sk_value_006a7f24)(iVar3,iVar7);
      (*(code *)PTR_X509_POLICY_NODE_print_006a8d18)(param_1,uVar2,2);
      iVar7 = iVar7 + 1;
    }
  }
  if (bVar1) {
                    /* WARNING: Could not recover jumptable at 0x0045dde8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_BIO_free_006a7f70)(param_1);
    return;
  }
  return;
}

