
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_aes_192_ecb(void)

{
  return (EVP_CIPHER *)aes_192_ecb;
}

