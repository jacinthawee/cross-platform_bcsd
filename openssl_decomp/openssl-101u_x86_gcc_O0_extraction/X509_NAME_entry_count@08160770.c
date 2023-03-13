
int X509_NAME_entry_count(X509_NAME *name)

{
  int iVar1;
  
  if (name != (X509_NAME *)0x0) {
    iVar1 = sk_num((_STACK *)name->entries);
    return iVar1;
  }
  return 0;
}

