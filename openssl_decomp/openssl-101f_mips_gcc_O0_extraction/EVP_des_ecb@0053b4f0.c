
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_des_ecb(void)

{
  return (EVP_CIPHER *)des_ecb;
}
