
X509_TRUST * X509_TRUST_get0(int idx)

{
  X509_TRUST *pXVar1;
  
  if (idx < 0) {
    pXVar1 = (X509_TRUST *)0x0;
  }
  else {
    if (7 < idx) {
      pXVar1 = (X509_TRUST *)sk_value(trtable,idx + -8);
      return pXVar1;
    }
    pXVar1 = (X509_TRUST *)(trstandard + idx * 0x18);
  }
  return pXVar1;
}

