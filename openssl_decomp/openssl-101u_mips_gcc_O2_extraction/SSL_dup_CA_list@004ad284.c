
stack_st_X509_NAME * SSL_dup_CA_list(stack_st_X509_NAME *sk)

{
  stack_st_X509_NAME *psVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  psVar1 = (stack_st_X509_NAME *)(*(code *)PTR_sk_new_null_006a6fa4)();
  iVar4 = 0;
  do {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(sk);
    if (iVar3 <= iVar4) {
      return psVar1;
    }
    uVar2 = (*(code *)PTR_sk_value_006a6e24)(sk,iVar4);
    iVar3 = (*(code *)PTR_X509_NAME_dup_006a713c)(uVar2);
    if (iVar3 == 0) break;
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar1,iVar3);
    iVar4 = iVar4 + 1;
  } while (iVar3 != 0);
  (*(code *)PTR_sk_pop_free_006a7058)(psVar1,PTR_X509_NAME_free_006a6ff8);
  return (stack_st_X509_NAME *)0x0;
}

