
int OBJ_cmp(ASN1_OBJECT *a,ASN1_OBJECT *b)

{
  int iVar1;
  
  iVar1 = a->length - b->length;
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x004c458c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_memcmp_006a9ad0)(a->data,b->data);
    return iVar1;
  }
  return iVar1;
}

