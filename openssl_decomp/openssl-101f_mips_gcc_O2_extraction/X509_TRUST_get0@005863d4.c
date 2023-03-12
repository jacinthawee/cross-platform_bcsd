
X509_TRUST * X509_TRUST_get0(int idx)

{
  X509_TRUST *pXVar1;
  
  if (idx < 0) {
    return (X509_TRUST *)0x0;
  }
  if (idx < 8) {
    return (X509_TRUST *)(trstandard + idx * 0x18);
  }
                    /* WARNING: Could not recover jumptable at 0x00586414. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pXVar1 = (X509_TRUST *)(*(code *)PTR_sk_value_006a7f24)(trtable,idx + -8);
  return pXVar1;
}

