
void Camellia_ofb128_encrypt
               (uchar *in,uchar *out,size_t length,CAMELLIA_KEY *key,uchar *ivec,int *num)

{
  CRYPTO_ofb128_encrypt();
  return;
}

