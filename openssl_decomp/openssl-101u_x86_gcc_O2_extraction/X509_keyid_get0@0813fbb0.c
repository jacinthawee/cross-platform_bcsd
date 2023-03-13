
uchar * X509_keyid_get0(X509 *x,int *len)

{
  int *piVar1;
  
  if ((*(int *)(x->sha1_hash + 0xc) != 0) &&
     (piVar1 = *(int **)(*(int *)(x->sha1_hash + 0xc) + 0xc), piVar1 != (int *)0x0)) {
    if (len != (int *)0x0) {
      *len = *piVar1;
    }
    return (uchar *)piVar1[2];
  }
  return (uchar *)0x0;
}

