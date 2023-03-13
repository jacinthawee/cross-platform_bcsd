
void hmac_key_free(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  if (puVar1 != (undefined4 *)0x0) {
    if (puVar1[2] != 0) {
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(puVar1[2],*puVar1);
    }
                    /* WARNING: Could not recover jumptable at 0x005e0774. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_ASN1_OCTET_STRING_free_006a8cfc)(puVar1);
    return;
  }
  return;
}

