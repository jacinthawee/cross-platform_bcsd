
int X509_NAME_entry_count(X509_NAME *name)

{
  int iVar1;
  
  if (name != (X509_NAME *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0057f81c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(name->entries);
    return iVar1;
  }
  return 0;
}

