
ASN1_STRING * ASN1_STRING_set_by_NID(ASN1_STRING **out,uchar *in,int inlen,int inform,int nid)

{
  void *pvVar1;
  int iVar2;
  ASN1_STRING *pAVar3;
  uint mask;
  int in_GS_OFFSET;
  ASN1_STRING *local_28;
  int local_24 [5];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = (ASN1_STRING *)0x0;
  if (out == (ASN1_STRING **)0x0) {
    out = &local_28;
  }
  local_24[0] = nid;
  pvVar1 = OBJ_bsearch_(local_24,tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN);
  if (pvVar1 == (void *)0x0) {
    if (stable != (_STACK *)0x0) {
      iVar2 = sk_find(stable,local_24);
      if (-1 < iVar2) {
        pvVar1 = sk_value(stable,iVar2);
        if (pvVar1 != (void *)0x0) goto LAB_08153725;
      }
    }
    iVar2 = ASN1_mbstring_copy(out,in,inlen,inform,global_mask & 0x2806);
  }
  else {
LAB_08153725:
    mask = *(uint *)((int)pvVar1 + 0xc);
    if ((*(byte *)((int)pvVar1 + 0x10) & 2) == 0) {
      mask = global_mask & *(uint *)((int)pvVar1 + 0xc);
    }
    iVar2 = ASN1_mbstring_ncopy(out,in,inlen,inform,mask,*(long *)((int)pvVar1 + 4),
                                *(long *)((int)pvVar1 + 8));
  }
  if (iVar2 < 1) {
    pAVar3 = (ASN1_STRING *)0x0;
  }
  else {
    pAVar3 = *out;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

