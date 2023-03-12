
bool ec_cmp_parameters(int param_1,int param_2)

{
  EC_GROUP *a;
  EC_GROUP *b;
  int iVar1;
  
  a = EC_KEY_get0_group(*(EC_KEY **)(param_1 + 0x14));
  b = EC_KEY_get0_group(*(EC_KEY **)(param_2 + 0x14));
  iVar1 = EC_GROUP_cmp(a,b,(BN_CTX *)0x0);
  return iVar1 == 0;
}

