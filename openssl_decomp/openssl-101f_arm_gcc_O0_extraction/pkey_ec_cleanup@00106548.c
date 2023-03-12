
void pkey_ec_cleanup(int param_1)

{
  EC_GROUP **ptr;
  
  ptr = *(EC_GROUP ***)(param_1 + 0x14);
  if (ptr != (EC_GROUP **)0x0) {
    if (*ptr != (EC_GROUP *)0x0) {
      EC_GROUP_free(*ptr);
    }
    CRYPTO_free(ptr);
    return;
  }
  return;
}

