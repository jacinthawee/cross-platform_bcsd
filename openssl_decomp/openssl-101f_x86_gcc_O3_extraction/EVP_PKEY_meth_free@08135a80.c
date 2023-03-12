
void EVP_PKEY_meth_free(EVP_PKEY_METHOD *pmeth)

{
  if ((pmeth != (EVP_PKEY_METHOD *)0x0) && (((byte)pmeth[4] & 1) != 0)) {
    CRYPTO_free(pmeth);
    return;
  }
  return;
}

