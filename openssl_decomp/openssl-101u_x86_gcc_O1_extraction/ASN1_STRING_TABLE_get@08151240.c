
ASN1_STRING_TABLE * ASN1_STRING_TABLE_get(int nid)

{
  ASN1_STRING_TABLE *pAVar1;
  int iVar2;
  int in_GS_OFFSET;
  int local_24 [5];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_24[0] = nid;
  pAVar1 = (ASN1_STRING_TABLE *)
           OBJ_bsearch_(local_24,tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN);
  if ((pAVar1 == (ASN1_STRING_TABLE *)0x0) && (stable != (_STACK *)0x0)) {
    iVar2 = sk_find(stable,local_24);
    if (-1 < iVar2) {
      pAVar1 = (ASN1_STRING_TABLE *)sk_value(stable,iVar2);
    }
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

