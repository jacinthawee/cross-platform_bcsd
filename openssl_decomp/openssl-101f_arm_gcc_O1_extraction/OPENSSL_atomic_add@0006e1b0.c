
int OPENSSL_atomic_add(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  do {
    iVar2 = *param_1;
    bVar1 = (bool)hasExclusiveAccess(param_1);
  } while (!bVar1);
  *param_1 = iVar2 + param_2;
  return iVar2 + param_2;
}

