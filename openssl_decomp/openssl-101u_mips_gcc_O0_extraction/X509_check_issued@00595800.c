
int X509_check_issued(X509 *issuer,X509 *subject)

{
  X509_NAME *a;
  X509_NAME *b;
  int iVar1;
  uint uVar2;
  AUTHORITY_KEYID *akid;
  int iVar3;
  
  a = X509_get_subject_name(issuer);
  b = (X509_NAME *)(*(code *)PTR_X509_get_issuer_name_006a76e4)(subject);
  iVar1 = X509_NAME_cmp(a,b);
  iVar3 = 0x1d;
  if (iVar1 == 0) {
    if ((issuer->ex_flags & 0x100) == 0) {
      x509v3_cache_extensions_part_6(issuer);
      uVar2 = subject->ex_flags;
    }
    else {
      uVar2 = subject->ex_flags;
    }
    if ((uVar2 & 0x100) == 0) {
      x509v3_cache_extensions_part_6(subject);
      akid = subject->akid;
    }
    else {
      akid = subject->akid;
    }
    if ((akid == (AUTHORITY_KEYID *)0x0) || (iVar3 = X509_check_akid(issuer,akid), iVar3 == 0)) {
      iVar3 = iVar1;
      if ((subject->ex_flags & 0x400) == 0) {
        if (((issuer->ex_flags & 2) != 0) && (iVar3 = 0x20, (issuer->ex_kusage & 4) != 0)) {
          iVar3 = 0;
        }
      }
      else if (((issuer->ex_flags & 2) != 0) && (iVar3 = 0x27, (issuer->ex_kusage & 0x80) != 0)) {
        iVar3 = 0;
      }
    }
  }
  return iVar3;
}

