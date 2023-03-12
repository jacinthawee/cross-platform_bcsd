
int ASN1_STRING_cmp(ASN1_STRING *a,ASN1_STRING *b)

{
  int iVar1;
  undefined4 in_a3;
  
  iVar1 = a->length - b->length;
  if ((iVar1 == 0) &&
     (iVar1 = (*(code *)PTR_memcmp_006aabd8)(a->data,b->data,a->length,in_a3,&_gp), iVar1 == 0)) {
    iVar1 = a->type - b->type;
  }
  return iVar1;
}

