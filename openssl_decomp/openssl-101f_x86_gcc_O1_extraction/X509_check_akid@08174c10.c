
int X509_check_akid(X509 *issuer,AUTHORITY_KEYID *akid)

{
  ASN1_INTEGER *y;
  _STACK *p_Var1;
  X509_NAME *a;
  int iVar2;
  ASN1_INTEGER *x;
  int *piVar3;
  int iVar4;
  X509_NAME *b;
  
  if (akid != (AUTHORITY_KEYID *)0x0) {
    if ((akid->keyid != (ASN1_STRING *)0x0) && (issuer->skid != (ASN1_STRING *)0x0)) {
      iVar2 = ASN1_OCTET_STRING_cmp(akid->keyid,issuer->skid);
      if (iVar2 != 0) {
        return 0x1e;
      }
    }
    y = akid->serial;
    if (y != (ASN1_INTEGER *)0x0) {
      x = X509_get_serialNumber(issuer);
      iVar2 = ASN1_INTEGER_cmp(x,y);
      if (iVar2 != 0) {
        return 0x1f;
      }
    }
    p_Var1 = (_STACK *)akid->issuer;
    if (p_Var1 != (_STACK *)0x0) {
      for (iVar2 = 0; iVar4 = sk_num(p_Var1), iVar2 < iVar4; iVar2 = iVar2 + 1) {
        piVar3 = (int *)sk_value(p_Var1,iVar2);
        if (*piVar3 == 4) {
          a = (X509_NAME *)piVar3[1];
          if (a == (X509_NAME *)0x0) {
            return 0;
          }
          b = X509_get_issuer_name(issuer);
          iVar2 = X509_NAME_cmp(a,b);
          if (iVar2 == 0) {
            return 0;
          }
          return 0x1f;
        }
      }
    }
  }
  return 0;
}

