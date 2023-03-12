
void ASN1_template_free(ASN1_VALUE **pval,ASN1_TEMPLATE *tt)

{
  int iVar1;
  _STACK *p_Var2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  if ((tt->flags & 6) == 0) {
    asn1_item_combine_free();
  }
  else {
    p_Var2 = (_STACK *)*pval;
    iVar4 = 0;
    while( true ) {
      iVar3 = sk_num(p_Var2);
      if (iVar3 <= iVar4) break;
      sk_value(p_Var2,iVar4);
      asn1_item_combine_free();
      iVar4 = iVar4 + 1;
    }
    sk_free(p_Var2);
    *pval = (ASN1_VALUE *)0x0;
  }
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

