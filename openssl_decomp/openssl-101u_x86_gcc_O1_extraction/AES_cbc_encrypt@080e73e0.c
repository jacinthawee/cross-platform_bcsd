
void AES_cbc_encrypt(uchar *in,uchar *out,size_t length,AES_KEY *key,uchar *ivec,int enc)

{
  if (enc == 0) {
    CRYPTO_cbc128_decrypt();
    return;
  }
  CRYPTO_cbc128_encrypt();
  return;
}
