
int X509_cmp(X509 *a,X509 *b)

{
  X509_CINF *pXVar1;
  X509_CINF *pXVar2;
  size_t __n;
  int iVar3;
  
  X509_check_purpose(a,-1,0);
  X509_check_purpose(b,-1,0);
  iVar3 = memcmp(&a->rfc3779_addr,&b->rfc3779_addr,0x14);
  if (iVar3 == 0) {
    pXVar1 = a->cert_info;
    iVar3 = (pXVar1->enc).modified;
    if (iVar3 != 0) {
      return 0;
    }
    pXVar2 = b->cert_info;
    if ((pXVar2->enc).modified == 0) {
      __n = (pXVar1->enc).len;
      iVar3 = __n - (pXVar2->enc).len;
      if (iVar3 == 0) {
        iVar3 = memcmp((pXVar1->enc).enc,(pXVar2->enc).enc,__n);
      }
    }
  }
  return iVar3;
}

