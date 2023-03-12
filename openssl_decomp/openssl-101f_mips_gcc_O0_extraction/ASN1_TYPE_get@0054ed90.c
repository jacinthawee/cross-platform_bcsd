
int ASN1_TYPE_get(ASN1_TYPE *a)

{
  int iVar1;
  
  if ((a->value).ptr != (char *)0x0) {
    return a->type;
  }
  iVar1 = a->type;
  if (iVar1 != 5) {
    iVar1 = 0;
  }
  return iVar1;
}

