
X509_NAME_ENTRY * X509_NAME_get_entry(X509_NAME *name,int loc)

{
  int iVar1;
  X509_NAME_ENTRY *pXVar2;
  
  if (name == (X509_NAME *)0x0) {
    return (X509_NAME_ENTRY *)0x0;
  }
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(name->entries);
  if ((loc < iVar1) && (-1 < loc)) {
                    /* WARNING: Could not recover jumptable at 0x0057cc94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar2 = (X509_NAME_ENTRY *)(*(code *)PTR_sk_value_006a6e24)(name->entries,loc);
    return pXVar2;
  }
  return (X509_NAME_ENTRY *)0x0;
}

