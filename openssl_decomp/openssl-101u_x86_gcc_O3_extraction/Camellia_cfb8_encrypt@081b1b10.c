
void Camellia_cfb8_encrypt
               (uchar *in,uchar *out,size_t length,CAMELLIA_KEY *key,uchar *ivec,int *num,int enc)

{
  CRYPTO_cfb128_8_encrypt(in,out,length,key,ivec,num,enc,Camellia_encrypt);
  return;
}

