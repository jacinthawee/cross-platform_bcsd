
void TS_VERIFY_CTX_cleanup(int param_1)

{
  if (param_1 != 0) {
    (*(code *)PTR_X509_STORE_free_006a7274)(*(undefined4 *)(param_1 + 4));
    (*(code *)PTR_sk_pop_free_006a7058)(*(undefined4 *)(param_1 + 8),PTR_X509_free_006a6e90);
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(*(undefined4 *)(param_1 + 0xc));
    (*(code *)PTR_X509_ALGOR_free_006a7ea4)(*(undefined4 *)(param_1 + 0x10));
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x14));
    (*(code *)PTR_BIO_free_all_006a6e74)(*(undefined4 *)(param_1 + 0x1c));
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(*(undefined4 *)(param_1 + 0x20));
    (*(code *)PTR_GENERAL_NAME_free_006a73a4)(*(undefined4 *)(param_1 + 0x24));
                    /* WARNING: Could not recover jumptable at 0x005c49dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_memset_006a99f4)(param_1,0,0x28);
    return;
  }
  return;
}

