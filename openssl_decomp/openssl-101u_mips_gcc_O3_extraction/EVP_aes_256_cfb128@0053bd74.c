
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_aes_256_cfb128(void)

{
  return (EVP_CIPHER *)aes_256_cfb;
}
