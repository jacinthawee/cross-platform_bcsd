
X509_NAME_ENTRY * X509_NAME_get_entry(X509_NAME *name,int loc)

{
  int iVar1;
  X509_NAME_ENTRY *pXVar2;
  
  if (name != (X509_NAME *)0x0) {
    iVar1 = sk_num((_STACK *)name->entries);
    if ((-1 < loc) && (loc < iVar1)) {
      pXVar2 = (X509_NAME_ENTRY *)sk_value((_STACK *)name->entries,loc);
      return pXVar2;
    }
  }
  return (X509_NAME_ENTRY *)0x0;
}

