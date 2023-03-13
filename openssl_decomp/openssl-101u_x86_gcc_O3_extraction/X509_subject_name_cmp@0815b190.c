
int X509_subject_name_cmp(X509 *a,X509 *b)

{
  X509_NAME *a_00;
  X509_NAME *a_01;
  int iVar1;
  
  a_00 = b->cert_info->subject;
  a_01 = a->cert_info->subject;
  if ((((a_01->canon_enc == (uchar *)0x0) || (a_01->modified != 0)) &&
      (iVar1 = i2d_X509_NAME(a_01,(uchar **)0x0), iVar1 < 0)) ||
     (((a_00->canon_enc == (uchar *)0x0 || (a_00->modified != 0)) &&
      (iVar1 = i2d_X509_NAME(a_00,(uchar **)0x0), iVar1 < 0)))) {
    iVar1 = -2;
  }
  else {
    iVar1 = a_01->canon_enclen - a_00->canon_enclen;
    if (iVar1 == 0) {
      iVar1 = memcmp(a_01->canon_enc,a_00->canon_enc,a_01->canon_enclen);
    }
  }
  return iVar1;
}

