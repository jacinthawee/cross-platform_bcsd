
void TS_RESP_CTX_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (*(code *)PTR_X509_free_006a6e90)(*param_1);
    (*(code *)PTR_EVP_PKEY_free_006a6e78)(param_1[1]);
    (*(code *)PTR_sk_pop_free_006a7058)(param_1[2],PTR_X509_free_006a6e90);
    (*(code *)PTR_sk_pop_free_006a7058)(param_1[3],PTR_ASN1_OBJECT_free_006a7004);
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(param_1[4]);
    (*(code *)PTR_sk_free_006a6e80)(param_1[5]);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(param_1[6]);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(param_1[7]);
    (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(param_1[8]);
                    /* WARNING: Could not recover jumptable at 0x005c0ea8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
    return;
  }
  return;
}

