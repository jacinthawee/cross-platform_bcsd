
int eckey_pub_cmp(int param_1,int param_2)

{
  EC_GROUP *group;
  EC_POINT *a;
  EC_POINT *b;
  int iVar1;
  int iVar2;
  
  group = EC_KEY_get0_group(*(EC_KEY **)(param_2 + 0x14));
  a = EC_KEY_get0_public_key(*(EC_KEY **)(param_1 + 0x14));
  b = EC_KEY_get0_public_key(*(EC_KEY **)(param_2 + 0x14));
  iVar1 = EC_POINT_cmp(group,a,b,(BN_CTX *)0x0);
  iVar2 = 1;
  if (iVar1 != 0) {
    iVar2 = (uint)(iVar1 == 1) * 2 + -2;
  }
  return iVar2;
}

