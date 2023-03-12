
int X509_check_trust(X509 *x,int id,int flags)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int local_28 [6];
  
  if (id == -1) {
    return 1;
  }
  uVar3 = id - 1;
  if (7 < uVar3) {
    local_28[0] = id;
    if (((trtable == (_STACK *)0x0) || (iVar2 = sk_find(trtable,local_28), iVar2 == -1)) ||
       (uVar3 = iVar2 + 8, iVar2 == -9)) {
      iVar2 = (*default_trust)(id,x,flags);
      return iVar2;
    }
    if ((int)uVar3 < 0) {
      puVar1 = (undefined *)0x0;
      goto LAB_000ced0e;
    }
  }
  if ((int)uVar3 < 8) {
    puVar1 = PTR_trstandard_000ced6c + uVar3 * 0x18;
  }
  else {
    puVar1 = (undefined *)sk_value(trtable,uVar3 - 8);
  }
LAB_000ced0e:
  iVar2 = (**(code **)(puVar1 + 8))(puVar1,x,flags);
  return iVar2;
}

