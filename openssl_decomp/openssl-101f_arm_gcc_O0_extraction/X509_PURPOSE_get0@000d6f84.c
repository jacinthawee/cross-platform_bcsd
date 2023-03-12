
X509_PURPOSE * X509_PURPOSE_get0(int idx)

{
  X509_PURPOSE *pXVar1;
  
  if (idx < 0) {
    return (X509_PURPOSE *)0x0;
  }
  if (idx < 9) {
    return (X509_PURPOSE *)(&xstandard + idx * 0x1c);
  }
  pXVar1 = (X509_PURPOSE *)sk_value(xptable,idx + -9);
  return pXVar1;
}
