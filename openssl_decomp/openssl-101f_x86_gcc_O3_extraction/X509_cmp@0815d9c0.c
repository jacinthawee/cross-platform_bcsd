
int X509_cmp(X509 *a,X509 *b)

{
  int iVar1;
  
  X509_check_purpose(a,-1,0);
  X509_check_purpose(b,-1,0);
  iVar1 = memcmp(&a->rfc3779_addr,&b->rfc3779_addr,0x14);
  return iVar1;
}

