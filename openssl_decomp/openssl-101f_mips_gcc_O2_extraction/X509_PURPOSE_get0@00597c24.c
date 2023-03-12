
X509_PURPOSE * X509_PURPOSE_get0(int idx)

{
  X509_PURPOSE *pXVar1;
  
  if (idx < 0) {
    return (X509_PURPOSE *)0x0;
  }
  if (idx < 9) {
    return (X509_PURPOSE *)(xstandard + idx * 0x1c);
  }
                    /* WARNING: Could not recover jumptable at 0x00597c64. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_PURPOSE *)(*(code *)PTR_sk_value_006a7f24)(xptable,idx + -9);
  return pXVar1;
}

