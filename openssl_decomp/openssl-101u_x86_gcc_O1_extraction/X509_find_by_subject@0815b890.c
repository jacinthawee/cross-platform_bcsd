
X509 * X509_find_by_subject(stack_st_X509 *sk,X509_NAME *name)

{
  X509_NAME *a;
  X509 *pXVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = sk_num(&sk->stack);
    if (iVar2 <= iVar3) {
      return (X509 *)0x0;
    }
    pXVar1 = (X509 *)sk_value(&sk->stack,iVar3);
    a = pXVar1->cert_info->subject;
    if ((a->canon_enc == (uchar *)0x0) || (a->modified != 0)) {
      iVar2 = i2d_X509_NAME(a,(uchar **)0x0);
      if (-1 < iVar2) goto LAB_0815b8d7;
    }
    else {
LAB_0815b8d7:
      if ((name->canon_enc == (uchar *)0x0) || (name->modified != 0)) {
        iVar2 = i2d_X509_NAME(name,(uchar **)0x0);
        if (iVar2 < 0) goto LAB_0815b915;
      }
      if (a->canon_enclen == name->canon_enclen) {
        iVar2 = memcmp(a->canon_enc,name->canon_enc,a->canon_enclen);
        if (iVar2 == 0) {
          return pXVar1;
        }
      }
    }
LAB_0815b915:
    iVar3 = iVar3 + 1;
  } while( true );
}

