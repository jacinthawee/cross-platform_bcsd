
int X509_NAME_add_entry(X509_NAME *name,X509_NAME_ENTRY *ne,int loc,int set)

{
  bool bVar1;
  int iVar2;
  X509_NAME_ENTRY *a;
  void *pvVar3;
  _STACK *sk;
  uint uVar4;
  
  if (name == (X509_NAME *)0x0) {
    return 0;
  }
  sk = (_STACK *)name->entries;
  iVar2 = sk_num(sk);
  name->modified = 1;
  if ((iVar2 < loc) || (loc < 0)) {
    loc = iVar2;
    if (set == -1) goto LAB_000c9f14;
LAB_000c9ed0:
    loc = iVar2;
    if (iVar2 != 0) {
      pvVar3 = sk_value(sk,iVar2 + -1);
      iVar2 = *(int *)((int)pvVar3 + 8) + 1;
      uVar4 = count_leading_zeroes(*(int *)((int)pvVar3 + 8) + 1);
      uVar4 = uVar4 >> 5;
      goto LAB_000c9eda;
    }
  }
  else {
    if (set != -1) {
      bVar1 = loc < iVar2;
      iVar2 = loc;
      if (bVar1) {
        pvVar3 = sk_value(sk,loc);
        iVar2 = *(int *)((int)pvVar3 + 8);
        uVar4 = count_leading_zeroes(iVar2);
        uVar4 = uVar4 >> 5;
        goto LAB_000c9eda;
      }
      goto LAB_000c9ed0;
    }
LAB_000c9f14:
    if (loc != 0) {
      pvVar3 = sk_value(sk,loc + -1);
      uVar4 = 0;
      iVar2 = *(int *)((int)pvVar3 + 8);
      goto LAB_000c9eda;
    }
  }
  uVar4 = 1;
  iVar2 = loc;
LAB_000c9eda:
  a = X509_NAME_ENTRY_dup(ne);
  if (a == (X509_NAME_ENTRY *)0x0) {
    return 0;
  }
  a->set = iVar2;
  iVar2 = sk_insert(sk,a,loc);
  if (iVar2 != 0) {
    if ((uVar4 != 0) && (iVar2 = sk_num(sk), loc + 1 < iVar2)) {
      do {
        pvVar3 = sk_value(sk,loc);
        loc = loc + 1;
        *(int *)((int)pvVar3 + 8) = *(int *)((int)pvVar3 + 8) + 1;
      } while (loc != iVar2 + -1);
    }
    return 1;
  }
  ERR_put_error(0xb,0x71,0x41,"x509name.c",0x10d);
  X509_NAME_ENTRY_free(a);
  return 0;
}

