
int X509_check_issued(X509 *issuer,X509 *subject)

{
  X509_NAME *b;
  X509_NAME *a;
  int iVar1;
  int iVar2;
  
  b = X509_get_issuer_name(subject);
  a = X509_get_subject_name(issuer);
  iVar1 = X509_NAME_cmp(a,b);
  iVar2 = 0x1d;
  if (iVar1 == 0) {
    if ((*(byte *)((int)&issuer->ex_flags + 1) & 1) == 0) {
      x509v3_cache_extensions_part_6();
    }
    if ((*(byte *)((int)&subject->ex_flags + 1) & 1) == 0) {
      x509v3_cache_extensions_part_6();
    }
    if ((subject->akid == (AUTHORITY_KEYID *)0x0) ||
       (iVar2 = X509_check_akid(issuer,subject->akid), iVar2 == 0)) {
      iVar2 = iVar1;
      if ((*(byte *)((int)&subject->ex_flags + 1) & 4) == 0) {
        if (((*(byte *)&issuer->ex_flags & 2) != 0) && ((*(byte *)&issuer->ex_kusage & 4) == 0)) {
          iVar2 = 0x20;
        }
      }
      else if (((*(byte *)&issuer->ex_flags & 2) != 0) &&
              ((*(byte *)&issuer->ex_kusage & 0x80) == 0)) {
        iVar2 = 0x27;
      }
    }
  }
  return iVar2;
}

