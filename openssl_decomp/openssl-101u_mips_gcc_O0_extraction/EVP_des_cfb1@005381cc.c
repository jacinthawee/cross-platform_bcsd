
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EVP_CIPHER * EVP_des_cfb1(void)

{
  return (EVP_CIPHER *)des_cfb1;
}
