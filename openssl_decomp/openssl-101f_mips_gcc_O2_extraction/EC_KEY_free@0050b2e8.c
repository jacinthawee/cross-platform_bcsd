
void EC_KEY_free(EC_KEY *key)

{
  int iVar1;
  
  if ((key != (EC_KEY *)0x0) &&
     (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(key + 0x18,0xffffffff,0x21,"ec_key.c",0x72),
     iVar1 < 1)) {
    if (*(EC_GROUP **)(key + 4) != (EC_GROUP *)0x0) {
      EC_GROUP_free(*(EC_GROUP **)(key + 4));
    }
    if (*(EC_POINT **)(key + 8) != (EC_POINT *)0x0) {
      EC_POINT_free(*(EC_POINT **)(key + 8));
    }
    if (*(BIGNUM **)(key + 0xc) != (BIGNUM *)0x0) {
      BN_clear_free(*(BIGNUM **)(key + 0xc));
    }
    EC_EX_DATA_free_all_data(key + 0x20);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(key,0x24);
                    /* WARNING: Could not recover jumptable at 0x0050b3c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(key);
    return;
  }
  return;
}

