
void SEED_ofb128_encrypt(uchar *in,uchar *out,size_t len,SEED_KEY_SCHEDULE *ks,uchar *ivec,int *num)

{
  CRYPTO_ofb128_encrypt(in,out,len,ks,ivec,num,SEED_encrypt);
  return;
}

