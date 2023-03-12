
void Camellia_ecb_encrypt(uchar *in,uchar *out,CAMELLIA_KEY *key,int enc)

{
  if (enc != 1) {
    Camellia_decrypt(in,out,key);
    return;
  }
  Camellia_encrypt(in,out,key);
  return;
}

