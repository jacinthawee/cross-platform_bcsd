
X509 * X509_find_by_issuer_and_serial(stack_st_X509 *sk,X509_NAME *name,ASN1_INTEGER *serial)

{
  X509_CINF *pXVar1;
  X509_NAME *a;
  int iVar2;
  X509 *pXVar3;
  int iVar4;
  
  if (sk != (stack_st_X509 *)0x0) {
    iVar4 = 0;
    while( true ) {
      iVar2 = sk_num(&sk->stack);
      if (iVar2 <= iVar4) break;
      pXVar3 = (X509 *)sk_value(&sk->stack,iVar4);
      pXVar1 = pXVar3->cert_info;
      iVar2 = ASN1_STRING_cmp(pXVar1->serialNumber,serial);
      if (iVar2 == 0) {
        a = pXVar1->issuer;
        if ((a->canon_enc == (uchar *)0x0) || (a->modified != 0)) {
          iVar2 = i2d_X509_NAME(a,(uchar **)0x0);
          if (iVar2 < 0) goto LAB_0815dbd0;
        }
        if ((name->canon_enc == (uchar *)0x0) || (name->modified != 0)) {
          iVar2 = i2d_X509_NAME(name,(uchar **)0x0);
          if (iVar2 < 0) goto LAB_0815dbd0;
        }
        if (a->canon_enclen == name->canon_enclen) {
          iVar2 = memcmp(a->canon_enc,name->canon_enc,a->canon_enclen);
          if (iVar2 == 0) {
            return pXVar3;
          }
        }
      }
LAB_0815dbd0:
      iVar4 = iVar4 + 1;
    }
  }
  return (X509 *)0x0;
}

