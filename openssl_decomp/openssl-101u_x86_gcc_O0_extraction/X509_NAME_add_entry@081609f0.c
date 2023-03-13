
int X509_NAME_add_entry(X509_NAME *name,X509_NAME_ENTRY *ne,int loc,int set)

{
  _STACK *sk;
  int iVar1;
  void *pvVar2;
  X509_NAME_ENTRY *a;
  int iVar3;
  bool bVar4;
  
  if (name == (X509_NAME *)0x0) {
    return 0;
  }
  sk = (_STACK *)name->entries;
  iVar1 = sk_num(sk);
  name->modified = 1;
  if ((loc < 0) || (iVar1 < loc)) {
    loc = iVar1;
    if (set == -1) goto LAB_08160b0a;
  }
  else {
    if (set == -1) {
LAB_08160b0a:
      iVar1 = 0;
      bVar4 = true;
      if (loc != 0) {
        pvVar2 = sk_value(sk,loc + -1);
        iVar1 = *(int *)((int)pvVar2 + 8);
        bVar4 = false;
      }
      goto LAB_08160a7d;
    }
    if (loc < iVar1) {
      pvVar2 = sk_value(sk,loc);
      iVar1 = *(int *)((int)pvVar2 + 8);
      bVar4 = iVar1 == 0;
      goto LAB_08160a7d;
    }
  }
  iVar1 = 0;
  bVar4 = true;
  if (loc != 0) {
    pvVar2 = sk_value(sk,loc + -1);
    iVar1 = *(int *)((int)pvVar2 + 8) + 1;
    bVar4 = iVar1 == 0;
  }
LAB_08160a7d:
  a = X509_NAME_ENTRY_dup(ne);
  if (a == (X509_NAME_ENTRY *)0x0) {
    return 0;
  }
  a->set = iVar1;
  iVar1 = sk_insert(sk,a,loc);
  if (iVar1 != 0) {
    if ((bVar4) && (iVar1 = sk_num(sk), loc + 1 < iVar1)) {
      do {
        iVar3 = loc + 1;
        pvVar2 = sk_value(sk,loc);
        *(int *)((int)pvVar2 + 8) = *(int *)((int)pvVar2 + 8) + 1;
        loc = iVar3;
      } while (iVar1 + -1 != iVar3);
    }
    return 1;
  }
  ERR_put_error(0xb,0x71,0x41,"x509name.c",0x10d);
  X509_NAME_ENTRY_free(a);
  return 0;
}

