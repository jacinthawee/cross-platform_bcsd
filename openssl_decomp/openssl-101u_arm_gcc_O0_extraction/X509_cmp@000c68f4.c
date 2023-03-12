
int X509_cmp(X509 *a,X509 *b)

{
  int iVar1;
  X509_CINF *pXVar2;
  undefined4 in_r3;
  int iVar3;
  X509_CINF *pXVar4;
  
  X509_check_purpose(a,-1,0);
  X509_check_purpose(b,-1,0);
  iVar1 = memcmp(&a->rfc3779_addr,&b->rfc3779_addr,0x14);
  if (iVar1 == 0) {
    pXVar2 = a->cert_info;
    iVar3 = (pXVar2->enc).modified;
    if ((iVar3 == 0) && (pXVar4 = b->cert_info, iVar1 = iVar3, (pXVar4->enc).modified == 0)) {
      iVar3 = (pXVar2->enc).len;
      iVar1 = iVar3 - (pXVar4->enc).len;
      if (iVar1 == 0) {
        iVar1 = (*(code *)PTR_memcmp_0018906c)((pXVar2->enc).enc,(pXVar4->enc).enc,iVar3,in_r3);
        return iVar1;
      }
    }
  }
  return iVar1;
}

