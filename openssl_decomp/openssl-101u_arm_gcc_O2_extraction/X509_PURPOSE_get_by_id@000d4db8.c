
int X509_PURPOSE_get_by_id(int id)

{
  int iVar1;
  int local_24 [9];
  
  if (8 < id - 1U) {
    if ((xptable == (_STACK *)0x0) ||
       (local_24[0] = id, iVar1 = sk_find(xptable,local_24), iVar1 == -1)) {
      iVar1 = -1;
    }
    else {
      iVar1 = iVar1 + 9;
    }
    return iVar1;
  }
  return id - 1U;
}

