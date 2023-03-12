
int X509_NAME_entry_count(X509_NAME *name)

{
  int iVar1;
  
  if (name != (X509_NAME *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0057ca3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)(name->entries);
    return iVar1;
  }
  return 0;
}

