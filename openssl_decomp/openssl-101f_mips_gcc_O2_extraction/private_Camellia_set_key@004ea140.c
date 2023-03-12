
int private_Camellia_set_key(uchar *userKey,int bits,CAMELLIA_KEY *key)

{
  int iVar1;
  int iVar2;
  undefined4 in_a3;
  
  if ((userKey == (uchar *)0x0) || (key == (CAMELLIA_KEY *)0x0)) {
    iVar2 = -1;
  }
  else if (((bits & 0xffffffbfU) == 0x80) || (iVar2 = -2, bits == 0x100)) {
    iVar1 = (*(code *)PTR_Camellia_Ekeygen_006a9628)(bits,userKey,key,in_a3,&_gp);
    iVar2 = 0;
    key->grand_rounds = iVar1;
  }
  return iVar2;
}

