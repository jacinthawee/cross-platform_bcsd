
void TS_VERIFY_CTX_free(int param_1)

{
  if (param_1 != 0) {
    (*(code *)PTR_X509_STORE_free_006a8384)(*(undefined4 *)(param_1 + 4));
    (*(code *)PTR_sk_pop_free_006a8158)(*(undefined4 *)(param_1 + 8),PTR_X509_free_006a7f90);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(*(undefined4 *)(param_1 + 0xc));
    (*(code *)PTR_X509_ALGOR_free_006a8f94)(*(undefined4 *)(param_1 + 0x10));
    (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(param_1 + 0x14));
    (*(code *)PTR_BIO_free_all_006a7f74)(*(undefined4 *)(param_1 + 0x1c));
    (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(*(undefined4 *)(param_1 + 0x20));
    (*(code *)PTR_GENERAL_NAME_free_006a84a4)(*(undefined4 *)(param_1 + 0x24));
    (*(code *)PTR_memset_006aab00)(param_1,0,0x28);
                    /* WARNING: Could not recover jumptable at 0x005c7180. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
    return;
  }
  return;
}

