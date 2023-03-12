
void EVP_PKEY_asn1_free(EVP_PKEY_ASN1_METHOD *ameth)

{
  if ((ameth != (EVP_PKEY_ASN1_METHOD *)0x0) && ((*(uint *)(ameth + 8) & 2) != 0)) {
    if (*(int *)(ameth + 0xc) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
    if (*(int *)(ameth + 0x10) != 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)();
    }
                    /* WARNING: Could not recover jumptable at 0x0056700c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(ameth);
    return;
  }
  return;
}

