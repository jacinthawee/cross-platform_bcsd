
int X509_ATTRIBUTE_count(X509_ATTRIBUTE *attr)

{
  int iVar1;
  
  if (attr->single != 0) {
    return (uint)((attr->value).ptr != (char *)0x0);
  }
                    /* WARNING: Could not recover jumptable at 0x0057ff40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)((attr->value).ptr);
  return iVar1;
}

