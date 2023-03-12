
int AES_set_decrypt_key(uchar *userKey,int bits,AES_KEY *key)

{
  int iVar1;
  
  iVar1 = private_AES_set_decrypt_key(userKey,bits,key);
  return iVar1;
}

