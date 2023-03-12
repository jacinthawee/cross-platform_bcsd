
int OTHERNAME_cmp(OTHERNAME *a,OTHERNAME *b)

{
  int iVar1;
  
  if ((a != (OTHERNAME *)0x0) && (b != (OTHERNAME *)0x0)) {
    iVar1 = (*(code *)PTR_OBJ_cmp_006a8cc4)(a->type_id,b->type_id);
    if (iVar1 != 0) {
      return iVar1;
    }
                    /* WARNING: Could not recover jumptable at 0x0058c4f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*(code *)PTR_ASN1_TYPE_cmp_006a8cdc)(a->value,b->value);
    return iVar1;
  }
  return -1;
}

