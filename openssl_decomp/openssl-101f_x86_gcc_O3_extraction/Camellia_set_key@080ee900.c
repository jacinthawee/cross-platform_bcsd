
int Camellia_set_key(uchar *userKey,int bits,CAMELLIA_KEY *key)

{
  int iVar1;
  
  if ((userKey == (uchar *)0x0) || (key == (CAMELLIA_KEY *)0x0)) {
    iVar1 = -1;
  }
  else if (((bits & 0xffffffbfU) == 0x80) || (bits == 0x100)) {
    iVar1 = Camellia_Ekeygen(bits,userKey,key);
    key->grand_rounds = iVar1;
    iVar1 = 0;
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}

