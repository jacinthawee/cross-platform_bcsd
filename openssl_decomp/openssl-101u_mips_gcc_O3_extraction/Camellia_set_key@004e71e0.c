
int Camellia_set_key(uchar *userKey,int bits,CAMELLIA_KEY *key)

{
  int iVar1;
  
  iVar1 = private_Camellia_set_key(userKey,bits,key);
  return iVar1;
}

