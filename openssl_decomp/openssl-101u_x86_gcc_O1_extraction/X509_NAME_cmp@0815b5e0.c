
int X509_NAME_cmp(X509_NAME *a,X509_NAME *b)

{
  int iVar1;
  
  if ((((a->canon_enc == (uchar *)0x0) || (a->modified != 0)) &&
      (iVar1 = i2d_X509_NAME(a,(uchar **)0x0), iVar1 < 0)) ||
     (((b->canon_enc == (uchar *)0x0 || (b->modified != 0)) &&
      (iVar1 = i2d_X509_NAME(b,(uchar **)0x0), iVar1 < 0)))) {
    iVar1 = -2;
  }
  else {
    iVar1 = a->canon_enclen - b->canon_enclen;
    if (iVar1 == 0) {
      iVar1 = memcmp(a->canon_enc,b->canon_enc,a->canon_enclen);
    }
  }
  return iVar1;
}

