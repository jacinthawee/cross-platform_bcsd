
int X509_check_issued(X509 *issuer,X509 *subject)

{
  X509_NAME *a;
  X509_NAME *b;
  int iVar1;
  int iVar2;
  
  a = X509_get_subject_name(issuer);
  b = X509_get_issuer_name(subject);
  iVar1 = X509_NAME_cmp(a,b);
  if (iVar1 == 0) {
    if (-1 < (int)(issuer->ex_flags << 0x17)) {
      x509v3_cache_extensions_part_6(issuer);
    }
    if (-1 < (int)(subject->ex_flags << 0x17)) {
      x509v3_cache_extensions_part_6(subject);
    }
    if ((subject->akid == (AUTHORITY_KEYID *)0x0) ||
       (iVar2 = X509_check_akid(issuer,subject->akid), iVar2 == 0)) {
      iVar2 = iVar1;
      if ((int)(subject->ex_flags << 0x15) < 0) {
        if ((int)(issuer->ex_flags << 0x1e) < 0) {
          if ((issuer->ex_kusage & 0x80) == 0) {
            iVar2 = 0x27;
          }
          else {
            iVar2 = 0;
          }
        }
      }
      else if ((int)(issuer->ex_flags << 0x1e) < 0) {
        if ((issuer->ex_kusage & 4) == 0) {
          iVar2 = 0x20;
        }
        else {
          iVar2 = 0;
        }
      }
    }
  }
  else {
    iVar2 = 0x1d;
  }
  return iVar2;
}

