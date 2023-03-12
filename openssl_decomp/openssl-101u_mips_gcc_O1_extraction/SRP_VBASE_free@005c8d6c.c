
undefined4 SRP_VBASE_free(undefined4 *param_1)

{
  (*(code *)PTR_sk_pop_free_006a7058)(*param_1,SRP_user_pwd_free);
  (*(code *)PTR_sk_free_006a6e80)(param_1[1]);
  (*(code *)PTR_CRYPTO_free_006a6e88)(param_1[2]);
  (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
  return 0;
}

