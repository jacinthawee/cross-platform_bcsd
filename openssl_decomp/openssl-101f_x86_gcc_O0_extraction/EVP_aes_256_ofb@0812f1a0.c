
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_aes_256_ofb(void)

{
  return (EVP_CIPHER *)aes_256_ofb;
}
