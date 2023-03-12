
void policy_data_free(uint *param_1)

{
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(param_1[1]);
  if ((*param_1 & 4) == 0) {
    (*(code *)PTR_sk_pop_free_006a8158)(param_1[2],PTR_POLICYQUALINFO_free_006aa1c8);
  }
  (*(code *)PTR_sk_pop_free_006a8158)(param_1[3],PTR_ASN1_OBJECT_free_006a8104);
                    /* WARNING: Could not recover jumptable at 0x0059bbc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
  return;
}

