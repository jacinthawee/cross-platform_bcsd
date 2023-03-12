
int X509_TRUST_get_by_id(int id)

{
  int iVar1;
  int local_20 [8];
  
  if (7 < id - 1U) {
    if ((trtable == (_STACK *)0x0) ||
       (local_20[0] = id, iVar1 = sk_find(trtable,local_20), iVar1 == -1)) {
      iVar1 = -1;
    }
    else {
      iVar1 = iVar1 + 8;
    }
    return iVar1;
  }
  return id - 1U;
}

