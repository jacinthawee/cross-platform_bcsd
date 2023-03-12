
void ASN1_primitive_free(ASN1_VALUE **pval,ASN1_ITEM *it)

{
  ASN1_OBJECT *a;
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  int *piVar2;
  ASN1_OBJECT *a_00;
  
  if (it == (ASN1_ITEM *)0x0) {
    piVar2 = (int *)*pval;
    a_00 = (ASN1_OBJECT *)piVar2[1];
    pval = (ASN1_VALUE **)(piVar2 + 1);
    iVar1 = *piVar2;
    if (a_00 == (ASN1_OBJECT *)0x0) {
      return;
    }
LAB_000bbbdc:
    switch(iVar1) {
    case 1:
      if (it == (ASN1_ITEM *)0x0) {
        *pval = (ASN1_VALUE *)0xffffffff;
        return;
      }
LAB_000bbc3e:
      *pval = (ASN1_VALUE *)it->size;
      return;
    case 5:
      break;
    case 6:
      ASN1_OBJECT_free(a_00);
      break;
    case -4:
      a = (ASN1_OBJECT *)a_00->ln;
      if (a != (ASN1_OBJECT *)0x0) {
        switch(a_00->sn) {
        case (char *)0x1:
          a_00->ln = (char **)0xffffffff;
          goto LAB_000bbc36;
        case (char *)0x5:
          break;
        case (char *)0x6:
          ASN1_OBJECT_free(a);
          break;
        case (char *)0xfffffffc:
          ASN1_primitive_free_part_0(&a_00->ln,0);
          CRYPTO_free(a_00->ln);
          break;
        default:
          ASN1_STRING_free((ASN1_STRING *)a);
        }
        a_00->ln = (char **)0x0;
        a_00 = (ASN1_OBJECT *)*pval;
      }
LAB_000bbc36:
      CRYPTO_free(a_00);
      break;
    default:
      goto switchD_000bbbe2_caseD_fffffffd;
    }
  }
  else {
    if ((it->funcs != (void *)0x0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)((int)it->funcs + 0xc),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000bbbca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)();
      return;
    }
    if (it->itype != '\x05') {
      iVar1 = it->utype;
      if (iVar1 == 1) goto LAB_000bbc3e;
      a_00 = (ASN1_OBJECT *)*pval;
      if (a_00 == (ASN1_OBJECT *)0x0) {
        return;
      }
      goto LAB_000bbbdc;
    }
    a_00 = (ASN1_OBJECT *)*pval;
    if (a_00 == (ASN1_OBJECT *)0x0) {
      return;
    }
switchD_000bbbe2_caseD_fffffffd:
    ASN1_STRING_free((ASN1_STRING *)a_00);
    *pval = (ASN1_VALUE *)0x0;
  }
  *pval = (ASN1_VALUE *)0x0;
  return;
}

