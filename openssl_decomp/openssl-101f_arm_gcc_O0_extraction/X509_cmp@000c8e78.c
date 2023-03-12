
int X509_cmp(X509 *a,X509 *b)

{
  int iVar1;
  undefined4 in_r3;
  
  X509_check_purpose(a,-1,0);
  X509_check_purpose(b,-1,0);
  iVar1 = (*(code *)PTR_memcmp_0018a06c)(&a->rfc3779_addr,&b->rfc3779_addr,0x14,in_r3);
  return iVar1;
}

